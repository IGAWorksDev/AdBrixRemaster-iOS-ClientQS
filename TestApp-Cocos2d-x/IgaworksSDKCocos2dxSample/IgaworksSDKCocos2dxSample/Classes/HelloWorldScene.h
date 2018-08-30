#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "PluginManager.h"
#include "ProtocolAds.h"
#include "ProtocolAnalytics.h"
#include "ProtocolIAP.h"


class IgaworksCoreListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
    
    virtual void onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, int points);
    
private:
    cocos2d::plugin::ProtocolAds* _pluginIgaworksCore;
    cocos2d::plugin::ProtocolAds* _pluginAdPopcornOfferwall;
};


class AdPopcornOfferwallListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);

private:
    cocos2d::plugin::ProtocolAds* _pluginAdPopcornOfferwall;
    
};

class IgaworksCouponListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
    
private:
    cocos2d::plugin::ProtocolAds* _pluginIgaworksCoupon;
};

class IgaworksNanooListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
    
private:
    cocos2d::plugin::ProtocolAds* _pluginIgaworksNanoo;
};

class AdPopcornDAListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
    
private:
    cocos2d::plugin::ProtocolAds* _pluginAdPopcornDA;
    
};

class LiveOpsListener : public cocos2d::plugin::AdsListener
{
public:
    virtual void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg);
    cocos2d::plugin::ProtocolAds* _pluginLiveOps;
    
};



class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // load plugin
    void loadIgaworksCorePlugin();
    void unloadIgaworksCorePlugin();
    
    void loadAdPopcornOfferwallPlugin();
    void unloadAdPopcornOfferwallPlugin();
    
    void loadAdBrixPlugin();
    void unloadAdBrixPlugin();
    
    void loadIgaworksCouponPlugin();
    void unloadIgaworksCouponPlugin();
    
    void loadIgaworksNanooPlugin();
    void unloadIgaworksNanooPlugin();
    
    void loadAdPopcornDAPlugin();
    void unloadAdPopcornDAPlugin();
    
    void loadLiveOpsPlugin();
    void unloadLiveOpsPlugin();
    
    void loadIgaworksCommercePlugin();
    void unloadIgaworksCommercePlungin();
    
    void loadAdBrixRmPlugin();
    void unloadAdBrixRmPlugin();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void menuOpenOfferwallCallback(cocos2d::Ref* pSender);
    void menuOpenPromotionEventCallback(cocos2d::Ref* pSender);
    
    void menuFirstTimeExperienceCallback(cocos2d::Ref* pSender);
    
    
    void menuRetentionCallback(cocos2d::Ref* pSender);
    
    void menuBuyCallback(cocos2d::Ref* pSender);
    
    void menuShowViralCPINoticeCallback(cocos2d::Ref* pSender);
    
    void menuSetCustomCohortCallback(cocos2d::Ref* pSender);
    
    void menuCrossPromotionShowADCallback(cocos2d::Ref* pSender);
    
    void menuShowCouponCallback(cocos2d::Ref* pSender);
    
    void menuCheckCouponCallback(cocos2d::Ref* pSender);
    
    void menuGetNanooFanPageCallback(cocos2d::Ref* pSender);
    
    void menuShowBannerViewCallback(cocos2d::Ref* pSender);
    
    void menuCloseBannerViewCallback(cocos2d::Ref* pSender);
    
    void menuShowInterstitialAdCallback(cocos2d::Ref* pSender);
    
    void menuShowPopupAdCallback(cocos2d::Ref* pSender);
    
    void menuRequestNativeAd(cocos2d::Ref* pSender);
    
    void menuLiveOpsPopup(cocos2d::Ref* pSender);
    
    void menuPurchaseCommerce(cocos2d::Ref* pSender);
    
    void menuGoToCommerceV2Test(Ref* pSender);
    
    void menuEventsCallback(cocos2d::Ref* pSender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    cocos2d::plugin::ProtocolAds* _pluginIgaworksCore;
    cocos2d::plugin::ProtocolAds* _pluginAdPopcornOfferwall;
    
    cocos2d::plugin::ProtocolAnalytics* _pluginAdBrix;
    cocos2d::plugin::ProtocolAds* _pluginIgaworksCoupon;
    cocos2d::plugin::ProtocolAds* _pluginIgaworksNanoo;
    
    cocos2d::plugin::ProtocolAds* _pluginAdPopcornDA;
    
    cocos2d::plugin::ProtocolAds* _pluginLiveOps;
    
    cocos2d::plugin::ProtocolIAP* _pluginIgaworksCommerce;
    
    cocos2d::plugin::ProtocolAnalytics* _pluginAdBrixRm;
    
private:
    IgaworksCoreListener* _igaworksCoreListener;
    AdPopcornOfferwallListener* _adPopcornOfferwallListener;
    IgaworksCouponListener* _igaworksCouponListener;
    IgaworksNanooListener* _igaworksNanooListener;
    AdPopcornDAListener *_adPopcornDAListener;
    LiveOpsListener *_liveOpsListener;
    
};

#endif // __HELLOWORLD_SCENE_H__
