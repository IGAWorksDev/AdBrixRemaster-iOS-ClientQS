#ifndef __IGAWORKS_PLUGIN_H__
#define __IGAWORKS_PLUGIN_H__

#include "cocos2d.h"
#include "json.h"

#define ADBRIX_SDK		0
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
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
	AdBrixPaymentCreditCard         = 1,
	AdBrixPaymentBankTransfer       = 2,
	AdBrixPaymentMobilePayment      = 3,
	AdBrixPaymentETC                = 4
};

enum
{
	AdBrixSharingFacebook       = 1,
	AdBrixSharingKakaoTalk      = 2,
	AdBrixSharingKakaoStory     = 3,
	AdBrixSharingLine           = 4,
	AdBrixSharingWhatsApp       = 5,
	AdBrixSharingQQ             = 6,
	AdBrixSharingWeChat         = 7,
	AdBrixSharingSMS            = 8,
	AdBrixSharingEmail          = 9,
	AdBrixSharingCopyUrl        = 10,
	AdBrixSharingETC            = 11
};

enum
{
	AdBrixSignUpKakaoChannel           = 1
	,AdBrixSignUpNaverChannel           = 2
	,AdBrixSignUpLineChannel            = 3
	,AdBrixSignUpGoogleChannel          = 4
	,AdBrixSignUpFacebookChannel        = 5
	,AdBrixSignUpTwitterChannel         = 6
	,AdBrixSignUpWhatsAppChannel        = 7
	,AdBrixSignUpQQChannel              = 8
	,AdBrixSignUpWeChatChannel          = 9
	,AdBrixSignUpUserIdChannel          = 10
	,AdBrixSignUpETCChannel             = 11
};

enum
{
	AdBrixInviteKakaoChannel            = 1
	,AdBrixInviteNaverChannel           = 2
	,AdBrixInviteLineChannel            = 3
	,AdBrixInviteGoogleChannel          = 4
	,AdBrixInviteFacebookChannel        = 5
	,AdBrixInviteTwitterChannel         = 6
	,AdBrixInviteWhatsAppChannel        = 7
	,AdBrixInviteQQChannel              = 8
	,AdBrixInviteWeChatChannel          = 9
	,AdBrixInviteETCChannel             = 10
};

//class IgaworksCocos2dxCallbackListener {
//public:


//	virtual ~IgaworksCocos2dxCallbackListener() {}
//};

class PluginAdBrixAOS {
private:
//	static IgaworksCocos2dxCallbackListener* callbackListener;

public:
	//static void setCallbackListener(IgaworksCocos2dxCallbackListener *callbackListener);
	//static IgaworksCocos2dxCallbackListener *getCallbackListener();


	// COMMON API
	static void gdprForgetMe();
    static void event(const char* name, std::string jsonParam);
	static void login(const char* user_id);
	static void setAge(int age);
	static void setGender(int gender);
	static void setUserProperties(const char* key, const char* value);
    static void commonPurchase(const char * orderID, const char * purchaseDetail, double discount, double deliveryCharge, int paymentMethod, std::string jsonParam);
	static void commonPurchaseBulk(const char * orderID, const char * purchaseDetail, double discount, double deliveryCharge, int paymentMethod, std::string jsonParam);
	static void commonSignUp(int signChannelIdx,  std::string jsonParam);
    static void commonUseCredit(std::string jsonParam);
    static void commonAppUpdate(const char * prev_ver, const char * curr_ver, std::string jsonParam);
    static void commonInvite(int inviteChannelIdx, std::string jsonParam);
    static void gameTutorialCompleted(bool is_skip,  std::string jsonParam);
    static void gameLevelAchieved(int level, std::string jsonParam);
    static void gameCharacterCreated(std::string jsonParam);
    static void gameStageCleared(const char* stageName, std::string jsonParam);
	static void deepLinkOpen();
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
	static Json::Value create(const char* productId, const char* productName, double price, double discount, int quantity, int currencyString, AdBrixCommerceProductCategoryModel* category, AdBrixCommerceProductAttrModel *extraAttrs);

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
#endif
#endif // __IGAWORKS_PLUGIN_H__
