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
    
    
    void loadAdBrixRmPlugin();
    void unloadAdBrixRmPlugin();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    
    
    void menuEventsCallback(cocos2d::Ref* pSender);
    void menuLoginCallback(cocos2d::Ref* pSender);
    void menuPropsCallback(cocos2d::Ref* pSender);
    
    void menuGameLevelAchievedCallback(cocos2d::Ref* pSender);
    void menuGameTutorialCompletedCallback(cocos2d::Ref* pSender);
    void menuGameCharacterCreatedCallback(cocos2d::Ref* pSender);
    void menuGameStageClearedCallback(cocos2d::Ref* pSender);
    
    void menuCommonSignUpCallback(cocos2d::Ref* pSender);
    void menuCommonUseCreditCallback(cocos2d::Ref* pSender);
    void menuCommonAppUpdateCallback(cocos2d::Ref* pSender);
    void menuCommonInviteCallback(cocos2d::Ref* pSender);
    void menuCommonPurchaseSingleCallback(cocos2d::Ref* pSender);
    void menuCommonPurchaseBulkCallback(cocos2d::Ref* pSender);
    
    void menuGdprForgetMeCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    cocos2d::plugin::ProtocolAnalytics* _pluginAdBrixRm;
    
private:
    
};

#endif // __HELLOWORLD_SCENE_H__
