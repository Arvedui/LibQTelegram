#include "mtprotoupdatehandler.h"
#include "../autogenerated/mtproto/decompiler/decompilertable.h"
#include "../autogenerated/telegramapi.h"
#include "../autogenerated/clientsyncmanager.h"
#include "../config/telegramconfig.h"
#include "../types/telegramhelper.h"
#include "dc/dcsessionmanager.h"
#include <QDateTime>

#define Nop

MTProtoUpdateHandler* MTProtoUpdateHandler::_instance = NULL;

MTProtoUpdateHandler::MTProtoUpdateHandler(QObject *parent) : QObject(parent), _syncing(false)
{
}

MTProtoUpdateHandler *MTProtoUpdateHandler::instance()
{
    if(!MTProtoUpdateHandler::_instance)
        MTProtoUpdateHandler::_instance = new MTProtoUpdateHandler();

    return MTProtoUpdateHandler::_instance;
}

bool MTProtoUpdateHandler::handle(MTProtoReply *mtreply)
{
    switch(mtreply->constructorId())
    {
        case TLTypes::Updates:
        case TLTypes::UpdatesCombined:
        case TLTypes::UpdateShort:
        case TLTypes::UpdateShortMessage:
        case TLTypes::UpdateShortChatMessage:
            this->handleUpdates(mtreply);
            return true;

        case TLTypes::UpdatesDifference:
        case TLTypes::UpdatesDifferenceSlice:
        case TLTypes::UpdatesDifferenceEmpty:
            this->handleUpdatesDifference(mtreply);
            return true;

        case TLTypes::UpdatesChannelDifference:
        case TLTypes::UpdatesChannelDifferenceTooLong:
        case TLTypes::UpdatesChannelDifferenceEmpty:
            this->handleUpdatesChannelDifference(mtreply);
            return true;

        default:
            break;
    }

    return false;
}

bool MTProtoUpdateHandler::syncing() const
{
    return this->_syncing;
}

void MTProtoUpdateHandler::sync()
{
    UpdatesState* clientstate = TelegramConfig_clientState;
    TelegramAPI::updatesGetDifference(DC_MainSession, clientstate->pts(), clientstate->date(), clientstate->qts());
}

void MTProtoUpdateHandler::setSyncing(bool b)
{
    if(this->_syncing == b)
        return;

    this->_syncing = b;
    emit syncingChanged();
}

void MTProtoUpdateHandler::handleUpdates(MTProtoReply *mtreply)
{
    Updates updates;
    updates.read(mtreply);

    UpdatesState* clientstate = TelegramConfig_clientState;
    ClientSyncManager::syncUpdates(&updates, clientstate);

    switch(updates.constructorId())
    {
        case TLTypes::UpdateShortMessage:
        case TLTypes::UpdateShortChatMessage:
        {
            Message* message = TelegramHelper::createMessage(&updates, TelegramConfig_me);
            emit newMessage(message);
            emit newSingleMessage(message);
            break;
        }

        case TLTypes::UpdateShort:
            this->handleUpdate(updates.update());
            break;

        case TLTypes::Updates:
        case TLTypes::UpdatesCombined:
            emit newUsers(updates.users());
            emit newChats(updates.chats());
            this->handleUpdates(updates.updates());
            break;

        default:
            qWarning("Unhandled updates: %s#%08x", qUtf8Printable(DecompilerTable::constructorName(updates.constructorId())), updates.constructorId());
            break;
    }
}

void MTProtoUpdateHandler::handleUpdatesDifference(MTProtoReply *mtreply)
{
    UpdatesDifference updatedifference;
    updatedifference.read(mtreply);

    if(updatedifference.constructorId() == TLTypes::UpdatesDifferenceEmpty)
    {
        qDebug("DC %d No Differences", mtreply->config()->dcid());
        return;
    }

    if(updatedifference.constructorId() == TLTypes::UpdatesDifferenceSlice)
    {
        this->setSyncing(true);

        qDebug("DC %d differences %s: %d users, %d chats, %d messages",
               mtreply->config()->dcid(),
               qUtf8Printable(QDateTime::fromTime_t(updatedifference.intermediateState()->date()).toString()),
               updatedifference.users().length(),
               updatedifference.chats().length(),
               updatedifference.newMessages().length());
    }

    emit newUsers(updatedifference.users());
    emit newChats(updatedifference.chats());
    emit newMessages(updatedifference.newMessages());

    this->handleUpdates(updatedifference.otherUpdates());

    if(updatedifference.constructorId() == TLTypes::UpdatesDifferenceSlice)
    {
        ClientSyncManager::syncState(updatedifference.intermediateState());
        this->sync();
        return;
    }

    this->setSyncing(false);
    TelegramConfig_save; // Update state
}

void MTProtoUpdateHandler::handleUpdatesChannelDifference(MTProtoReply *mtreply)
{
    UpdatesChannelDifference updatechanneldifference;
    updatechanneldifference.read(mtreply);

    if(updatechanneldifference.constructorId() == TLTypes::UpdatesChannelDifferenceEmpty)
    {
        qDebug("DC %d No Channel Differences", mtreply->config()->dcid());
        return;
    }

    emit newUsers(updatechanneldifference.users());
    emit newChats(updatechanneldifference.chats());

    if(updatechanneldifference.constructorId() == TLTypes::UpdatesChannelDifference)
    {
        emit newMessages(updatechanneldifference.newMessages());
        this->handleUpdates(updatechanneldifference.otherUpdates());
    }
    else
        emit newMessages(updatechanneldifference.messages());
}

void MTProtoUpdateHandler::handleUpdates(TLVector<Update *> updatelist)
{
    UpdatesState* clientstate = TelegramConfig_clientState;

    for(int i = 0; i < updatelist.length(); i++)
    {
        Update* update = updatelist[i];
        ClientSyncManager::syncUpdate(update, clientstate);
        this->handleUpdate(update);
    }
}

void MTProtoUpdateHandler::handleUpdate(Update *update)
{
    switch(update->constructorId())
    {
        case TLTypes::UpdateNewMessage:
            emit newMessage(update->messageUpdatenewmessage());
            break;

        case TLTypes::UpdateNewChannelMessage:
            emit newMessage(update->messageUpdatenewchannelmessage());
            break;

        case TLTypes::UpdateEditMessage:
        case TLTypes::UpdateEditChannelMessage:
            emit editMessage(update->message());
            break;

        case TLTypes::UpdateUserStatus:
            emit newUserStatus(update);
            break;

        case TLTypes::UpdateDraftMessage:
            emit newDraftMessage(update);
            break;

        case TLTypes::UpdateDeleteMessages:
            emit deleteMessages(update->messages());
            break;

        case TLTypes::UpdateDeleteChannelMessages:
            emit deleteChannelMessages(update->channelId(), update->messages());
            break;

        case TLTypes::UpdateReadHistoryInbox:
        case TLTypes::UpdateReadHistoryOutbox:
        case TLTypes::UpdateReadChannelInbox:
        case TLTypes::UpdateReadChannelOutbox:
            emit readHistory(update);
            break;

        case TLTypes::UpdateUserTyping:
        case TLTypes::UpdateChatUserTyping:
            emit typing(update);
            break;

        case TLTypes::UpdateWebPage:
            emit webPage(update->webpage());
            break;

        case TLTypes::UpdateNotifySettings:
            emit notifySettings(update->peerUpdatenotifysettings(), update->notifySettings());
            break;

        case TLTypes::UpdateChannelTooLong:
            emit channelTooLong(update);
            break;

        case TLTypes::UpdateNewAuthorization:
        case TLTypes::UpdateChannel:
        case TLTypes::UpdateMessageID:
            Nop;
            break;

        default:
            qWarning("Unhandled update: %s#%08x", qUtf8Printable(DecompilerTable::constructorName(update->constructorId())), update->constructorId());
            break;
    }
}
