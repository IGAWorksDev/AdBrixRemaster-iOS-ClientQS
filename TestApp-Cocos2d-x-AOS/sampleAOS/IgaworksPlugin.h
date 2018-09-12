#ifndef __IGAWORKS_PLUGIN_H__
#define __IGAWORKS_PLUGIN_H__

#include "cocos2d.h"

#define ADBRIX_SDK		0
#define ADPOPCORN_SDK	1
#define COMMON_SDK		2
#define COUPON_SDK		3
#define DISPLAY_SDK		4
#define LIVEOPS_SDK		5
#define PROMOTION_SDK	6
#define NANOO_SDK		7
enum
{
	AdBrixCurrencyKRW = 1,
	AdBrixCurrencyUSD = 2,
	AdBrixCurrencyJPY = 3,
	AdBrixCurrencyEUR = 4,
	AdBrixCurrencyGBP = 5,
	AdBrixCurrencyCNY = 6,
	AdBrixCurrencyTWD = 7,
	AdBrixCurrencyHKD = 8
};

enum
{
	AdBrixPaymentCreditCard		= 1,
	AdBrixPaymentBankTransfer	= 2,
	AdBrixPaymentMobilePayment	= 3,
	AdBrixPaymentETC			= 4
};

enum
{
	AdBrixSharingFacebook = 1,
	AdBrixSharingKakaoTalk = 2,
	AdBrixSharingKakaoStory = 3,
	AdBrixSharingLine = 4,
	AdBrixSharingWhatsApp = 5,
	AdBrixSharingQQ = 6,
	AdBrixSharingWeChat = 7,
	AdBrixSharingSMS = 8,
	AdBrixSharingEmail = 9,
	AdBrixSharingCopyUrl = 10,
	AdBrixSharingETC = 11
};

class IgaworksCocos2dxCallbackListener {
public:
	virtual void OnClosedOfferWallPage() {}

	virtual void OnDidGiveRewardItemResult(const char* resultMessage) {}
	virtual void OnGetRewardInfo(const char* campaignKey, const char* campaignName, const char* quantity, const char* cv, const char* rewardKey) {}

	virtual void OnSendCouponSucceed(const char* msg) {}
	virtual void OnSendCouponFailed(const char* msg) {}

	virtual void OnInterstitialReceiveSuccess() {}
	virtual void OnInterstitialReceiveFailed(int errorCode, const char* errorMessage) {}
	virtual void OnInterstitialClosed() {}
	virtual void OnPopupAdReceiveSuccess() {}
	virtual void OnPopupAdReceiveFailed(int errorCode, const char* errorMessage) {}
	virtual void OnPopupAdClosed() {}
	virtual void OnNativeAdRequestSucceeded (const char* nativeAdContents){}
	virtual void OnNativeAdRequestFailed(int errorCode, const char* errorMessage){}

	//LiveOps
	virtual void OnSuccessLiveOpsPopupResourceEventListener(){}
	virtual void OnFailLiveOpsPopupResourceEventListener(){}
	virtual void OnLiveOpsDeepLinkEventListener(const char* deeplink_json){}
	virtual void OnRegistrationIdEventListener(const char* regID){}
	virtual void OnSuccessLiveOpsGCMPushEnableEventListener(){}
	virtual void OnFailLiveOpsGCMPushEnableEventListener(){}
	virtual void OnLiveOpsPopupClick(){}
	virtual void OnLiveOpsCancelPopupBtnClick(){}


	virtual void OnPlayBtnClickListener() {}

	virtual void OnBtnClickListener(bool finish){}
	
	virtual void OnOpenFanPageListener(const char* url){}

	virtual ~IgaworksCocos2dxCallbackListener() {}
};

class IgaworksPlugin {
private:
	static IgaworksCocos2dxCallbackListener* callbackListener;

public:
	static void setCallbackListener(IgaworksCocos2dxCallbackListener *callbackListener);
	static IgaworksCocos2dxCallbackListener *getCallbackListener();

	// ADPOPCORN API
	static void openOfferwall();
	static void setSensorLandscapeEnable(bool flag);
	static void openBanner(const char* campaignKey);
	static void openPromotionEvent();
	static void getClientPendingRewardItems();
	static void didGiveRewardItem(const char* cv, const char* rewardKey);

	// COMMON API
	static void startApplication();
	static void startSession();
	static void endSession();
	static void setUserId(const char* userId);
	static void setClientRewardEventListener();

	// DISPLAY AD API
	static void initDisplayAd();
	static void initDisplayAd(bool isTestMode, bool enableDetailLog);
	static void destroy();
	static void showInterstitialAd(const char* spotKey);
	static void loadEndingAd(const char* spotKey);
	static void showEndingAd(const char* spotKey);
	static void showPopupAd(const char* spotKey);
	static void setRefreshTime(int seconds);
	static void setLocation(double latitude, double longitude);
	static void loadNativeAd(const char* spotKey);
	static void destroyNativeAd();
	static void impressionAction();
	static void clickAction();
	static void setEndingAdEventCallbackListener(const char* spotKey);

	// ADBRIX API
	static void setAge(int age);
	static void setGender(int gender);
	static void firstTimeExperience(const char* name);
	static void retention(const char* name);
	static void retention(const char* name, const char* param);
	static void buy(const char* name);
	static void setCustomCohort(int cohortVar, const char* value);
	static void purchase(const char * productID, double price, int currency, int paymentMethod);
	static void purchase(const char * orderID, const char * purchaseDetail, double discount, double deliveryCharge, int paymentMethod);
	
	// COUPON API
	static void showCouponDialog(bool showResultMsgToast);
	static void checkCoupon(const char* couponText);

	// LIVEOPS API
	static void initializeLiveOps();
	static void initializeLiveOps(const char* senderIDs);
	static void registerFCMToken(const char* refreshedToken);
	static void resumeLiveOps();
	//static void setLiveOpsNotificationCallback();
	static void setTargetingData(const char* userGroup, const char* userData);
	static void setTargetingData(const char* userGroup, int userData);
	static void setTargetingData(const char* userGroup, long userData);
	static void setTargetingData(const char* userGroup, float userData);
	static void setTargetingData(const char* userGroup, bool userData);
	static void setNormalClientPushEvent(long second, const char* contentText, int eventId, bool alwaysIsShown);
	static void setBigTextClientPushEvent(long second, const char* contentText, const char* bigContentTitle, const char* bigText, const char* summaryText, int eventId, bool alwaysIsShown);
	static void enableService(bool enable);
	static void enableServiceWithCallback(bool enable);
	static void cancelClientPushEvent(int eventId);
	static void setNotificationIconName(const char* notificationIconName);
	static void showPopUp(const char* spaceKey);
	static void requestPopupResource();
	static void destroyPopup();
	static void destroyAllPopups();
	static void flush();
	static void setLiveOpsPopupEventListener();


	// PROMOTION API
	static void showAD(const char* name);
	static void hideAD();
	
	// NANOO API
	static void openFanPage(bool openAutomatically);
};


class AdBrixCommerceProductAttrModel
{
	public:
		AdBrixCommerceProductAttrModel(std::map<std::string, std::string> attrData);
		//adBrixCommerceProductAttrModel();
		
		static AdBrixCommerceProductAttrModel* create(std::map<std::string, std::string> attrData);
		const char* getValue(int pIndex);
		const char* getKey(int pIndex);
	
	private:
		const char * Key[5];
		const char * Value[5];

};



class AdBrixCommerceProductCategoryModel

{

public:

	static AdBrixCommerceProductCategoryModel* create(std::string category1);
	static AdBrixCommerceProductCategoryModel* create(std::string category1, std::string category2);
	static AdBrixCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3);
	static AdBrixCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3, std::string category4);
	static AdBrixCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3, std::string category4, std::string category5);

	std::string categoryFullString;

private:
	std::string category1;
	std::string category2;
	std::string category3;
	std::string category4;
	std::string category5;
};

class AdBrixCommerceProductModel : public AdBrixCommerceProductAttrModel, AdBrixCommerceProductCategoryModel
{

public:
	//AdBrixCommerceProductModel(std::string productId, std::string productName, double price, double discount, int quantity, int currencyString, AdBrixCommerceProductCategoryModel *category, AdBrixCommerceProductAttrModel *extraAttrs);
	//std::string create(const char *productId, const char *productName, double price, double discount, int quantity, const char *currencyString, AdBrixCommerceProductCategoryModel category, AdBrixCommerceProductAttrModel *extraAttrs);
	static std::string create(const char* productId, const char* productName, double price, double discount, int quantity, int currencyString, AdBrixCommerceProductCategoryModel* category, AdBrixCommerceProductAttrModel *extraAttrs);
private:
	const char* _productID;
	double _price;
	double _discount;
	const char* _currencyString;
	const char* _category;
	int _quantity;
	const char* _productName;
	//std::map<const char*, const char*> _extraAttrs;
};
#endif // __IGAWORKS_PLUGIN_H__
