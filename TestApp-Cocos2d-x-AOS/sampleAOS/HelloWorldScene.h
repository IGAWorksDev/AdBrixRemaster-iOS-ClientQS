#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "IgaworksPlugin.h"

class HelloWorld : public cocos2d::Layer, public IgaworksCocos2dxCallbackListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
	//added by John
	void menuFirstTimeExperienceCallback(Ref* pSender);
	void menuRetentionCallback(Ref* pSender);
	void menuBuyCallback(Ref* pSender);
	void menuSetCustomCohortCallback(Ref* pSender);
	void menuShowViralCPINoticeCallback(Ref* pSender);
	void menuCrossPromotionShowADCallback(Ref* pSender);
	void menuShowCouponCallback(Ref* pSender);
	void menuCheckCouponCallback(Ref* pSender);
	void menuGetNanooFanPageCallback(Ref* pSender);
	void menuShowBannerViewCallback(Ref* pSender);
	void menuCloseBannerViewCallback(Ref* pSender);
	void menuShowInterstitialAdCallback(Ref* pSender);
	void menuShowPopupAdCallback(Ref* pSender);
	void menuRequestNativeAd(Ref* pSender);
	void menuSetFCMiidToLiveOps(cocos2d::Ref* pSender);
	void menuLiveOpsPopup(cocos2d::Ref* pSender);
	void menuPurchaseCommerce(cocos2d::Ref* pSender);
	void menuGoToCommerceV2Test(Ref* pSender);

    // a selector callback
    //void menuCallback1(cocos2d::Ref* pSender);
    //void menuCallback2(cocos2d::Ref* pSender);
    //void menuCallback3(cocos2d::Ref* pSender);
    //void menuCallback4(cocos2d::Ref* pSender);
    //void menuCallback5(cocos2d::Ref* pSender);
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    virtual void OnSuccessLiveOpsPopupResourceEventListener();
    virtual void OnSuccessLiveOpsGCMPushEnableEventListener();
	virtual void OnFailLiveOpsGCMPushEnableEventListener();
	virtual void OnLiveOpsPopupClick();
	virtual void OnLiveOpsCancelPopupBtnClick();

	virtual void OnLiveOpsDeepLinkEventListener(const char* deeplink_json);

	virtual void OnSendCouponSucceed(const char* msg);
	virtual void OnSendCouponFailed(const char* msg);
};

#endif // __HELLOWORLD_SCENE_H__
