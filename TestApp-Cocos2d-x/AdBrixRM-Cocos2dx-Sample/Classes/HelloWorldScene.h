#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "pluginAbx/platform/android/PluginAdBrixAOS.h"
    #include "pluginAbx/platform/android/json.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "PluginManager.h"
    #include "ProtocolAnalytics.h"
#endif



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
    
  
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    cocos2d::plugin::ProtocolAnalytics* _pluginAdBrixRm;
#endif

private:
    void menuCallback(Ref* pSender);
    void initSdkMenu(cocos2d::Menu* menu);

    
    
    void menuEventsCallback();
    void menuLoginCallback();
    void menuPropsCallback();
    
    void menuGameLevelAchievedCallback();
    void menuGameTutorialCompletedCallback();
    void menuGameCharacterCreatedCallback();
    void menuGameStageClearedCallback();
    
    void menuCommonSignUpCallback();
    void menuCommonUseCreditCallback();
    void menuCommonAppUpdateCallback();
    void menuCommonInviteCallback();
    void menuCommonPurchaseSingleCallback();
    void menuCommonPurchaseBulkCallback();
    
    void menuGdprForgetMeCallback();
};

#endif // __HELLOWORLD_SCENE_H__
