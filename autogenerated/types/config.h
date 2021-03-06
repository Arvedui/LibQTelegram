#ifndef CONFIG_H
#define CONFIG_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "disabledfeature.h"
#include "../../types/telegramobject.h"
#include "dcoption.h"

class Config: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLInt flags READ flags WRITE setFlags NOTIFY flagsChanged)
	Q_PROPERTY(TLInt date READ date WRITE setDate NOTIFY dateChanged)
	Q_PROPERTY(TLInt expires READ expires WRITE setExpires NOTIFY expiresChanged)
	Q_PROPERTY(TLBool isTestMode READ isTestMode WRITE setIsTestMode NOTIFY isTestModeChanged)
	Q_PROPERTY(TLInt thisDc READ thisDc WRITE setThisDc NOTIFY thisDcChanged)
	Q_PROPERTY(TLVector<DcOption*> dcOptions READ dcOptions WRITE setDcOptions NOTIFY dcOptionsChanged)
	Q_PROPERTY(TLInt chatSizeMax READ chatSizeMax WRITE setChatSizeMax NOTIFY chatSizeMaxChanged)
	Q_PROPERTY(TLInt megagroupSizeMax READ megagroupSizeMax WRITE setMegagroupSizeMax NOTIFY megagroupSizeMaxChanged)
	Q_PROPERTY(TLInt forwardedCountMax READ forwardedCountMax WRITE setForwardedCountMax NOTIFY forwardedCountMaxChanged)
	Q_PROPERTY(TLInt onlineUpdatePeriodMs READ onlineUpdatePeriodMs WRITE setOnlineUpdatePeriodMs NOTIFY onlineUpdatePeriodMsChanged)
	Q_PROPERTY(TLInt offlineBlurTimeoutMs READ offlineBlurTimeoutMs WRITE setOfflineBlurTimeoutMs NOTIFY offlineBlurTimeoutMsChanged)
	Q_PROPERTY(TLInt offlineIdleTimeoutMs READ offlineIdleTimeoutMs WRITE setOfflineIdleTimeoutMs NOTIFY offlineIdleTimeoutMsChanged)
	Q_PROPERTY(TLInt onlineCloudTimeoutMs READ onlineCloudTimeoutMs WRITE setOnlineCloudTimeoutMs NOTIFY onlineCloudTimeoutMsChanged)
	Q_PROPERTY(TLInt notifyCloudDelayMs READ notifyCloudDelayMs WRITE setNotifyCloudDelayMs NOTIFY notifyCloudDelayMsChanged)
	Q_PROPERTY(TLInt notifyDefaultDelayMs READ notifyDefaultDelayMs WRITE setNotifyDefaultDelayMs NOTIFY notifyDefaultDelayMsChanged)
	Q_PROPERTY(TLInt chatBigSize READ chatBigSize WRITE setChatBigSize NOTIFY chatBigSizeChanged)
	Q_PROPERTY(TLInt pushChatPeriodMs READ pushChatPeriodMs WRITE setPushChatPeriodMs NOTIFY pushChatPeriodMsChanged)
	Q_PROPERTY(TLInt pushChatLimit READ pushChatLimit WRITE setPushChatLimit NOTIFY pushChatLimitChanged)
	Q_PROPERTY(TLInt savedGifsLimit READ savedGifsLimit WRITE setSavedGifsLimit NOTIFY savedGifsLimitChanged)
	Q_PROPERTY(TLInt editTimeLimit READ editTimeLimit WRITE setEditTimeLimit NOTIFY editTimeLimitChanged)
	Q_PROPERTY(TLInt ratingEDecay READ ratingEDecay WRITE setRatingEDecay NOTIFY ratingEDecayChanged)
	Q_PROPERTY(TLInt stickersRecentLimit READ stickersRecentLimit WRITE setStickersRecentLimit NOTIFY stickersRecentLimitChanged)
	Q_PROPERTY(TLInt tmpSessions READ tmpSessions WRITE setTmpSessions NOTIFY tmpSessionsChanged)
	Q_PROPERTY(TLVector<DisabledFeature*> disabledFeatures READ disabledFeatures WRITE setDisabledFeatures NOTIFY disabledFeaturesChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorConfig = 0x9a6b2e2a,
		};

	public:
		explicit Config(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		TLInt flags() const;
		void setFlags(TLInt flags);
		TLInt date() const;
		void setDate(TLInt date);
		TLInt expires() const;
		void setExpires(TLInt expires);
		TLBool isTestMode() const;
		void setIsTestMode(TLBool is_test_mode);
		TLInt thisDc() const;
		void setThisDc(TLInt this_dc);
		const TLVector<DcOption*>& dcOptions() const;
		void setDcOptions(const TLVector<DcOption*>& dc_options);
		TLInt chatSizeMax() const;
		void setChatSizeMax(TLInt chat_size_max);
		TLInt megagroupSizeMax() const;
		void setMegagroupSizeMax(TLInt megagroup_size_max);
		TLInt forwardedCountMax() const;
		void setForwardedCountMax(TLInt forwarded_count_max);
		TLInt onlineUpdatePeriodMs() const;
		void setOnlineUpdatePeriodMs(TLInt online_update_period_ms);
		TLInt offlineBlurTimeoutMs() const;
		void setOfflineBlurTimeoutMs(TLInt offline_blur_timeout_ms);
		TLInt offlineIdleTimeoutMs() const;
		void setOfflineIdleTimeoutMs(TLInt offline_idle_timeout_ms);
		TLInt onlineCloudTimeoutMs() const;
		void setOnlineCloudTimeoutMs(TLInt online_cloud_timeout_ms);
		TLInt notifyCloudDelayMs() const;
		void setNotifyCloudDelayMs(TLInt notify_cloud_delay_ms);
		TLInt notifyDefaultDelayMs() const;
		void setNotifyDefaultDelayMs(TLInt notify_default_delay_ms);
		TLInt chatBigSize() const;
		void setChatBigSize(TLInt chat_big_size);
		TLInt pushChatPeriodMs() const;
		void setPushChatPeriodMs(TLInt push_chat_period_ms);
		TLInt pushChatLimit() const;
		void setPushChatLimit(TLInt push_chat_limit);
		TLInt savedGifsLimit() const;
		void setSavedGifsLimit(TLInt saved_gifs_limit);
		TLInt editTimeLimit() const;
		void setEditTimeLimit(TLInt edit_time_limit);
		TLInt ratingEDecay() const;
		void setRatingEDecay(TLInt rating_e_decay);
		TLInt stickersRecentLimit() const;
		void setStickersRecentLimit(TLInt stickers_recent_limit);
		TLInt tmpSessions() const;
		void setTmpSessions(TLInt tmp_sessions);
		const TLVector<DisabledFeature*>& disabledFeatures() const;
		void setDisabledFeatures(const TLVector<DisabledFeature*>& disabled_features);

	signals:
		void flagsChanged();
		void dateChanged();
		void expiresChanged();
		void isTestModeChanged();
		void thisDcChanged();
		void dcOptionsChanged();
		void chatSizeMaxChanged();
		void megagroupSizeMaxChanged();
		void forwardedCountMaxChanged();
		void onlineUpdatePeriodMsChanged();
		void offlineBlurTimeoutMsChanged();
		void offlineIdleTimeoutMsChanged();
		void onlineCloudTimeoutMsChanged();
		void notifyCloudDelayMsChanged();
		void notifyDefaultDelayMsChanged();
		void chatBigSizeChanged();
		void pushChatPeriodMsChanged();
		void pushChatLimitChanged();
		void savedGifsLimitChanged();
		void editTimeLimitChanged();
		void ratingEDecayChanged();
		void stickersRecentLimitChanged();
		void tmpSessionsChanged();
		void disabledFeaturesChanged();

	private:
		TLInt _flags;
		TLInt _date;
		TLInt _expires;
		TLBool _is_test_mode;
		TLInt _this_dc;
		TLVector<DcOption*> _dc_options;
		TLInt _chat_size_max;
		TLInt _megagroup_size_max;
		TLInt _forwarded_count_max;
		TLInt _online_update_period_ms;
		TLInt _offline_blur_timeout_ms;
		TLInt _offline_idle_timeout_ms;
		TLInt _online_cloud_timeout_ms;
		TLInt _notify_cloud_delay_ms;
		TLInt _notify_default_delay_ms;
		TLInt _chat_big_size;
		TLInt _push_chat_period_ms;
		TLInt _push_chat_limit;
		TLInt _saved_gifs_limit;
		TLInt _edit_time_limit;
		TLInt _rating_e_decay;
		TLInt _stickers_recent_limit;
		TLInt _tmp_sessions;
		TLVector<DisabledFeature*> _disabled_features;

};

#endif // CONFIG_H
