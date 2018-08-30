#include "HelloWorldScene.h"
#include "TestCommerceV2.h"

using namespace cocos2d::plugin;

USING_NS_CC;

std::vector<std::string> split(const std::string &s, char delim);

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // load IgaworksCorePlugin
    loadIgaworksCorePlugin();
    
    // set listner or set callback
    _igaworksCoreListener = new IgaworksCoreListener();
    _pluginIgaworksCore->setAdsListener(_igaworksCoreListener);
    
    PluginParam pAppKey("558024754"); // your app key
    PluginParam pHashKey("d0ead817ff8247e0"); // your hash key

    
    // Cross Promotion
//    PluginParam pAppKey("776597575"); // your app key
//    PluginParam pHashKey("9ab52430f0d444f4"); // your hash key
    
    // Nanoo
    //    PluginParam pAppKey("609026288"); // your app key
    //    PluginParam pHashKey("e27514c22ffa4666"); // your hash key
    
    PluginParam pIsUseIgaworksRewardServer(false); // isUseIgaworksRewardServer    igaworks에서 제공하는 reward server를 사용할것인지 여부. true : 사용, false : 사용하지 않음
    _pluginIgaworksCore->callFuncWithParam("igaworksCoreWithAppKey", &pAppKey, &pHashKey, &pIsUseIgaworksRewardServer, NULL);
    
    // set IgaworksCoreDelegate
    _pluginIgaworksCore->callFuncWithParam("setIgaworksCoreDelegate", NULL);
    
    // set IgaworksADClientRewardDelegate
    _pluginIgaworksCore->callFuncWithParam("setIgaworksADClientRewardDelegate", NULL);
    
    // set log level
    // 0 : IgaworksADLogInfo, 1 : IgaworksADLogDebug, 2 : IgaworksADLogTrace
    PluginParam pLogLevel(2);
    _pluginIgaworksCore->callFuncWithParam("setLogLevel", &pLogLevel, NULL);
    
    // set age
    PluginParam pAge(30);
    _pluginIgaworksCore->callFuncWithParam("setAge", &pAge, NULL);
    
    // set gender
    // 2 : IgaworksADGenderMale, 1 : IgaworksADGenderFemale
    PluginParam pGender(1);
    _pluginIgaworksCore->callFuncWithParam("setGender", &pGender, NULL);
    
    // igaworksad set userid
    PluginParam pUserId("igaworks");
    _pluginIgaworksCore->callFuncWithParam("setUserId", &pUserId, NULL);
    
    PluginParam pUrl("http://www.google.com");
    _pluginIgaworksCore->callFuncWithParam("setReferralUrl", &pUrl, NULL);

    // AdPopcornOfferwall
    loadAdPopcornOfferwallPlugin();
    
    _adPopcornOfferwallListener = new AdPopcornOfferwallListener();
    _pluginAdPopcornOfferwall->setAdsListener(_adPopcornOfferwallListener);
    
    
    // LivePos
    loadLiveOpsPlugin();
    _liveOpsListener = new LiveOpsListener();
    _liveOpsListener->_pluginLiveOps = _pluginLiveOps;
    _pluginLiveOps->setAdsListener(_liveOpsListener);
    
    _pluginLiveOps->callFuncWithParam("initPush", NULL);
    
    auto showLiveOpsAdItem = MenuItemFont::create("LiveOps Popup", CC_CALLBACK_1(HelloWorld::menuLiveOpsPopup, this));
    // create menu, it's an autorelease object
    auto menu = Menu::create(showLiveOpsAdItem, NULL);
    menu->setPosition(600.0f, 220.0f);
    this->addChild(menu, 1);
 
    loadAdBrixRmPlugin();
    auto events = MenuItemFont::create("AdBrixRM_Events", CC_CALLBACK_1(HelloWorld::menuEventsCallback, this));
    //    // create menu, it's an autorelease object
    menu = Menu::create(events, NULL);
    menu->setPosition(600.0f, 430.0f);
    this->addChild(menu, 1);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    return true;
}

void HelloWorld::loadIgaworksCorePlugin()
{
    // load plugin PluginIgaworksCore
    _pluginIgaworksCore = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginIgaworksCore"));
    printf("IgaworksCore plugin = %s", _pluginIgaworksCore->getPluginName());
}

void HelloWorld::unloadIgaworksCorePlugin()
{
    if (NULL != _pluginIgaworksCore) {
        std::string pluginName = _pluginIgaworksCore->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginIgaworksCore = NULL;
    }
}

void HelloWorld::loadAdPopcornOfferwallPlugin()
{
    _pluginAdPopcornOfferwall = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginAdPopcornOfferwall"));
    
    printf("AdPopcornOfferwall plugin = %s", _pluginAdPopcornOfferwall->getPluginName());
}

void HelloWorld::unloadAdPopcornOfferwallPlugin()
{
    if (NULL != _pluginAdPopcornOfferwall) {
        std::string pluginName = _pluginAdPopcornOfferwall->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginAdPopcornOfferwall = NULL;
    }
}

void HelloWorld::loadAdBrixPlugin()
{
   
}

void HelloWorld::unloadAdBrixPlugin()
{
    
}

void HelloWorld::loadAdBrixRmPlugin()
{
    _pluginAdBrixRm = dynamic_cast<ProtocolAnalytics*>(PluginManager::getInstance()->loadPlugin("PluginAdBrixRM"));
    
    printf("AdBrixRm plugin = %s", _pluginAdBrixRm->getPluginName());
}

void HelloWorld::unloadAdBrixRmPlugin()
{
    if (NULL != _pluginAdBrixRm) {
        std::string pluginName = _pluginAdBrixRm->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginAdBrixRm = NULL;
    }
}

void HelloWorld::loadIgaworksCouponPlugin()
{
    _pluginIgaworksCoupon = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginIgaworksCoupon"));
    
    printf("IgaworksCoupon plugin = %s", _pluginIgaworksCoupon->getPluginName());
}

void HelloWorld::unloadIgaworksCouponPlugin()
{
    if (NULL != _pluginIgaworksCoupon) {
        std::string pluginName = _pluginIgaworksCoupon->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginIgaworksCoupon = NULL;
    }
}

void HelloWorld::loadIgaworksNanooPlugin()
{
    _pluginIgaworksNanoo = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginIgaworksNanoo"));

    printf("IgaworksNanoo plugin = %s", _pluginIgaworksNanoo->getPluginName());
}

void HelloWorld::unloadIgaworksNanooPlugin()
{
    if (NULL != _pluginIgaworksNanoo) {
        std::string pluginName = _pluginIgaworksNanoo->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginIgaworksNanoo = NULL;
    }
}

void HelloWorld::loadAdPopcornDAPlugin()
{
    _pluginAdPopcornDA = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginAdPopcornDA"));
    
    printf("AdPopcornDA plugin = %s", _pluginAdPopcornDA->getPluginName());
}

void HelloWorld::unloadAdPopcornDAPlugin()
{
    if (NULL != _pluginAdPopcornDA) {
        std::string pluginName = _pluginAdPopcornDA->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginAdPopcornDA = NULL;
    }
}

void HelloWorld::loadLiveOpsPlugin()
{
    PluginProtocol* col = PluginManager::getInstance()->loadPlugin("PluginLiveOps");
    _pluginLiveOps = dynamic_cast<ProtocolAds*>(col);
    
    printf("LiveOps plugin = %s", _pluginLiveOps->getPluginName());
}

void HelloWorld::unloadLiveOpsPlugin()
{
    if (NULL != _pluginLiveOps) {
        std::string pluginName = _pluginLiveOps->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginLiveOps = NULL;
    }
}

void HelloWorld::loadIgaworksCommercePlugin()
{
    PluginProtocol* col = PluginManager::getInstance()->loadPlugin("PluginIgaworksCommerce");
    _pluginIgaworksCommerce = dynamic_cast<ProtocolIAP*>(col);
    
    printf("IgaworksCommerce plugin = %s", _pluginIgaworksCommerce->getPluginName());
}

void HelloWorld::unloadIgaworksCommercePlungin()
{
    if (NULL != _pluginIgaworksCommerce) {
        std::string pluginName = _pluginIgaworksCommerce->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginIgaworksCommerce = NULL;
    }
}


#pragma mark - private
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

#pragma mark - menu callback
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuOpenOfferwallCallback(Ref* pSender)
{
    
        StringMap userDataDictionaryForFilter;
        userDataDictionaryForFilter["age"] = "10";
        userDataDictionaryForFilter["gender"] = "1";
        PluginParam pUserDataDictionaryForFilter(userDataDictionaryForFilter);
    
    // set demo info for targeting
//    PluginParam pUserDataDictionaryForFilter(NULL);

    // set delegate
    PluginParam pDelegate(true);
    // adpopcorn open offerwall
    _pluginAdPopcornOfferwall->callFuncWithParam("openOfferWallWithViewController", &pDelegate, &pUserDataDictionaryForFilter, NULL);
}

void HelloWorld::menuOpenPromotionEventCallback(Ref* pSender)
{
    // set delegate
    PluginParam pDelegate(true);
    // adpopcorn open promotion event
    _pluginAdPopcornOfferwall->callFuncWithParam("openPromotionEvent", &pDelegate, NULL);
}

void HelloWorld::menuEventsCallback(Ref* pSender)
{
    PluginParam pEventName("customEvents01");
    
    _pluginAdBrixRm->callFuncWithParam("events", &pEventName, NULL);
}

void HelloWorld::menuFirstTimeExperienceCallback(Ref* pSender)
{
    PluginParam pActivityName("activity1");
    
    _pluginAdBrix->callFuncWithParam("firstTimeExperience", &pActivityName, NULL);
}


void HelloWorld::menuRetentionCallback(Ref* pSender)
{
    PluginParam pActivityName("activity2");
    
    _pluginAdBrix->callFuncWithParam("retention", &pActivityName, NULL);
}

void HelloWorld::menuBuyCallback(Ref* pSender)
{
    PluginParam pActivityName("activity3");
    
    _pluginAdBrix->callFuncWithParam("buy", &pActivityName, NULL);
}

void HelloWorld::menuShowViralCPINoticeCallback(Ref* pSender)
{
    _pluginAdBrix->callFuncWithParam("showViralCPINotice", NULL);
}

void HelloWorld::menuSetCustomCohortCallback(Ref* pSender)
{
    PluginParam pCustomCohortType(1);
    PluginParam pFilterName("level_1");
    
    _pluginAdBrix->callFuncWithParam("setCustomCohort", &pCustomCohortType, &pFilterName, NULL);
}

void HelloWorld::menuCrossPromotionShowADCallback(Ref* pSender)
{
    PluginParam pActivityName("game_end");
    
    _pluginAdBrix->callFuncWithParam("crossPromotionShowAD", &pActivityName, NULL);

}

void HelloWorld::menuShowCouponCallback(Ref* pSender)
{
    _pluginIgaworksCoupon->callFuncWithParam("showCoupon", NULL);
}

void HelloWorld::menuCheckCouponCallback(Ref* pSender)
{
    PluginParam pCode("abcd");
    
    _pluginIgaworksCoupon->callFuncWithParam("checkCoupon", &pCode, NULL);
}

void HelloWorld::menuGetNanooFanPageCallback(Ref* pSender)
{
    _pluginIgaworksNanoo->callFuncWithParam("getNanooFanPage", NULL);
}

void HelloWorld::menuShowBannerViewCallback(Ref* pSender)
{
    // DABannerViewSize320x50 : 0
    PluginParam pSize(0);
    // kPosTopLeft : 상단 가운데, kPosBottomLeft : 하단 가운데
    PluginParam pAtPos(cocos2d::plugin::ProtocolAds::kPosBottomLeft);
    PluginParam pAppKey("62198111"); // app key
    PluginParam pSpotKey("83703ad2cd"); // spot key
    
    
//    bannerViewSetAdRefreshRate
    PluginParam pAdRefreshRate(35);
    _pluginAdPopcornDA->callFuncWithParam("bannerViewSetAdRefreshRate", &pAdRefreshRate, NULL);
    
    
    _pluginAdPopcornDA->callFuncWithParam("initWithBannerViewSize", &pSize, &pAtPos, &pAppKey, &pSpotKey, NULL);
    
    // set delegate
    _pluginAdPopcornDA->callFuncWithParam("bannerViewSetDelegate", NULL);
}

void HelloWorld::menuCloseBannerViewCallback(Ref* pSender)
{
    _pluginAdPopcornDA->callFuncWithParam("closeBannerView", NULL);
}

void HelloWorld::menuShowInterstitialAdCallback(Ref* pSender)
{
    PluginParam pAppKey("62198111"); // app key
    PluginParam pSpotKey("007f70eec2"); // spot key
    
    _pluginAdPopcornDA->callFuncWithParam("interstitialAdInitWithKey", &pAppKey, &pSpotKey, NULL);
    
    // set delegate
    _pluginAdPopcornDA->callFuncWithParam("interstitialAdSetDelegate", NULL);
}

void HelloWorld::menuShowPopupAdCallback(Ref* pSender)
{
    PluginParam pAppKey("62198111"); // app key
    PluginParam pSpotKey("aa7df3078d"); // spot key
    
    _pluginAdPopcornDA->callFuncWithParam("popupAdInitWithKey", &pAppKey, &pSpotKey, NULL);
    
    // set delegate
    _pluginAdPopcornDA->callFuncWithParam("popupAdSetDelegate", NULL);
}

void HelloWorld::menuRequestNativeAd(Ref* pSender)
{
    PluginParam pAppKey("62198111"); // app key
    PluginParam pSpotKey("dbe8e4307f"); // spot key
    
    _pluginAdPopcornDA->callFuncWithParam("nativeAdInitWithKey", &pAppKey, &pSpotKey, NULL);
    
    // set delegate
    _pluginAdPopcornDA->callFuncWithParam("nativeAdSetDelegate", NULL);
    
    _pluginAdPopcornDA->callFuncWithParam("loadNativeAd", NULL);
}

void HelloWorld::menuLiveOpsPopup(cocos2d::Ref* pSender)
{
    _pluginLiveOps->callFuncWithParam("getPopups", NULL);
}

void HelloWorld::menuPurchaseCommerce(cocos2d::Ref* pSender)
{
    //orderId productId:(NSString*)productId price:(double)price currencyString:(NSString *)currencyString category:(NSArray*)categories quantity:(NSUInteger)quantity productName:(NSString*)productName
    
    PluginParam pOrderId("testOrderId");
    PluginParam pProductId("testProductId");
    PluginParam pPrice(3.0f);
    
    //IgaworksCommerceCurrencyUSD == 2
    PluginParam pCurrency(2);
    std::string currencyUSD = _pluginIgaworksCommerce->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    PluginParam pCurrencyString(currencyUSD.c_str());
    
    StringMap categories;
    categories["0"] = "testCategory1";
    categories["1"] = "testCategory2";
    categories["2"] = "testCategory3";
    PluginParam pCategory(categories);
    
    PluginParam pQuantity(2);
    PluginParam pProductName("testProductName");
    _pluginIgaworksCommerce->callFuncWithParam("purchase", &pOrderId, &pProductId, &pPrice, &pCurrencyString, &pCategory, &pQuantity, &pProductName, NULL);
}

void HelloWorld::menuGoToCommerceV2Test(Ref* pSender)
{
    Scene *pScene =  TestCommerceV2::createScene();
    Director:: getInstance()->replaceScene(pScene);
    return;
}

#pragma mark - IgaworksCoreListener
void IgaworksCoreListener::onAdsResult(AdsResultCode code, const char* msg)
{
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    // event string
    __String* didSaveConversionKeyEvent =  __String::create("didSaveConversionKey");
    
    __String* onRewardCompleteResultEvent =  __String::create("onRewardCompleteResult");
    
    if(strEventMsg->compare(didSaveConversionKeyEvent->getCString()) == 0)
    {
        log("1. didSaveConversionKeyEvent");
        
        std::vector<std::string> strMsgVector = split(strOtherMsg->getCString(), ',');
        __String* strConversionKey = __String::create(strMsgVector[0].c_str());
        __String* strSubReferralKey = __String::create(strMsgVector[1].c_str());
        
        log("2. didSaveConversionKey : ConversionKey : %s, SubReferralKey : %s", strConversionKey->getCString(), strSubReferralKey->getCString());
    }
    else if (strEventMsg->compare(onRewardCompleteResultEvent->getCString()) == 0)
    {
        log("1. onRewardCompleteResult");
        
        std::vector<std::string> strMsgVector = split(strOtherMsg->getCString(), ',');
        __String* strIsSuccess = __String::create(strMsgVector[0].c_str());
        __String* strMessage = __String::create(strMsgVector[1].c_str());
        
        __String* strResultCode = __String::create(strMsgVector[2].c_str());
        
        __String* strCompletedRewardKey = __String::create(strMsgVector[3].c_str());
        
        log("2. onRewardCompleteResultEvent : strIsSuccess : %s, strMessage : %s, strResultCode : %s, strCompletedRewardKey : %s", strIsSuccess->getCString(), strMessage->getCString(), strResultCode->getCString(), strCompletedRewardKey->getCString());
    }
    
    
    
}

// igaworks에서 제공하는 reward 서버를 사용하는 경우, 해당 이벤트로 수신하여 reward를 지급하고 igaworks 서버로 reward 지급에 대하여 노티한다.
void IgaworksCoreListener::onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, int points)
{
    log("IgaworksCoreListener::onPlayerGetPoints : pAdsPlugin : %s", pAdsPlugin->getPluginName());
    log("IgaworksCoreListener::onPlayerGetPoints : Player get points : %d", points);
    
    
    // @warning should add code to give game-money to player here
    
    // spend the points of player
    if (pAdsPlugin != NULL) {
        //        pAdsPlugin->spendPoints(points);
        std::string rewardKey = pAdsPlugin->callStringFuncWithParam("getRewardKey", NULL);
        log("MyAdsListener::onPlayerGetPoints : rewardKey : %s", rewardKey.c_str());
        
        
        _pluginAdPopcornOfferwall = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginAdPopcornOfferwall"));
        
        PluginParam pRewardKey(rewardKey.c_str());
        _pluginAdPopcornOfferwall->callFuncWithParam("didGiveRewardItemWithRewardKey", &pRewardKey, NULL);
        
    }
}


#pragma mark - AdPopcornOfferwallListener
void AdPopcornOfferwallListener::onAdsResult(AdsResultCode code, const char* msg)
{
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    __String* willOpenOfferWallEvent =  __String::create("willOpenOfferWall");
    __String* didOpenOfferWallEvent =  __String::create("didOpenOfferWall");
    __String* willCloseOfferWallEvent =  __String::create("willCloseOfferWall");
    __String* didCloseOfferWallEvent =  __String::create("didCloseOfferWall");
    
    __String* willOpenPromotionEventEvent =  __String::create("willOpenPromotionEvent");
    __String* didOpenPromotionEventEvent =  __String::create("didOpenPromotionEvent");
    __String* willClosePromotionEventEvent =  __String::create("willClosePromotionEvent");
    __String* didClosePromotionEventEvent =  __String::create("didClosePromotionEvent");
    
    // willOpenOfferWall
    if(strEventMsg->compare(willOpenOfferWallEvent->getCString()) == 0)
    {
        log("1. willOpenOfferWallEvent");
    }
    // didOpenOfferWall
    else if (strEventMsg->compare(didOpenOfferWallEvent->getCString()) == 0)
    {
        log("1. didOpenOfferWallEvent");
    }
    // willCloseOfferWall
    else if (strEventMsg->compare(willCloseOfferWallEvent->getCString()) == 0)
    {
        log("1. willCloseOfferWallEvent");
    }
    // didCloseOfferWall
    else if (strEventMsg->compare(didCloseOfferWallEvent->getCString()) == 0)
    {
        log("1. didCloseOfferWallEvent");
    }
    // willOpenPromotionEvent
    else if (strEventMsg->compare(willOpenPromotionEventEvent->getCString()) == 0)
    {
        log("1. willOpenPromotionEvent");
    }
    // didOpenPromotionEvent"
    else if (strEventMsg->compare(didOpenPromotionEventEvent->getCString()) == 0)
    {
        log("1. didOpenPromotionEvent");
    }
    // willClosePromotionEvent"
    else if (strEventMsg->compare(willClosePromotionEventEvent->getCString()) == 0)
    {
        log("1. willClosePromotionEvent");
    }
    // didClosePromotionEvent"
    else if (strEventMsg->compare(didClosePromotionEventEvent->getCString()) == 0)
    {
        log("1. didClosePromotionEvent");
    }
}

#pragma mark - IgaworksCouponListener
void IgaworksCouponListener::onAdsResult(AdsResultCode code, const char* msg)
{
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. IgaworksCouponListener : strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    __String* igaworksCouponValidationDidCompleteEvent =  __String::create("igaworksCouponValidationDidComplete");
    
    if (strEventMsg->compare(igaworksCouponValidationDidCompleteEvent->getCString()) == 0)
    {
        log("1. igaworksCouponValidationDidComplete : %s", strOtherMsg->getCString());
    }
}

#pragma mark - IgaworksNanooListener
void IgaworksNanooListener::onAdsResult(AdsResultCode code, const char* msg)
{
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. IgaworksNanooListener : strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    __String* getNanooFanPageDidCompleteEvent = __String::create("getNanooFanPageDidComplete");
    __String* getNanooFanPageFailedWithErrorEvent = __String::create("getNanooFanPageFailedWithError");
    __String* willOpenNanooFanPageEvent = __String::create("willOpenNanooFanPage");
    __String* didOpenNanooFanPageEvent = __String::create("didOpenNanooFanPage");
    __String* willCloseNanooFanPageEvent = __String::create("willCloseNanooFanPage");
    __String* didCloseNanooFanPageEvent = __String::create("didCloseNanooFanPage");
    
    if (strEventMsg->compare(getNanooFanPageDidCompleteEvent->getCString()) == 0)
    {
        log("1. getNanooFanPageDidComplete : %s", strOtherMsg->getCString());
    }
    // getNanooFanPageFailedWithError
    else if (strEventMsg->compare(getNanooFanPageFailedWithErrorEvent->getCString()) == 0)
    {
        log("1. getNanooFanPageFailedWithError : %s", strOtherMsg->getCString());
    }
    // willOpenNanooFanPage
    else if (strEventMsg->compare(willOpenNanooFanPageEvent->getCString()) == 0)
    {
        log("1. willOpenNanooFanPage");
    }
    // didOpenNanooFanPage
    else if (strEventMsg->compare(didOpenNanooFanPageEvent->getCString()) == 0)
    {
        log("1. didOpenNanooFanPage");
    }
    // willClsoeNanooFanPageEvent
    else if (strEventMsg->compare(willCloseNanooFanPageEvent->getCString()) == 0)
    {
        log("1. willClsoeNanooFanPage");
    }
    else if (strEventMsg->compare(didCloseNanooFanPageEvent->getCString()) == 0)
    {
        log("1. didCloseNanooFanPage");
    }
}

#pragma mark - AdPopcornDAListener
void AdPopcornDAListener::onAdsResult(AdsResultCode code, const char* msg)
{
    _pluginAdPopcornDA = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("PluginAdPopcornDA"));
    
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. AdPopcornDAListener : strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    
    __String* daBannerViewDidLoadAdEvent =  __String::create("DABannerViewDidLoadAd");
    __String* daBannerViewDidFailToReceiveAdWithErrorEvent =  __String::create("DABannerViewDidFailToReceiveAdWithError");
    __String* daBannerViewWillLeaveApplicationEvent = __String::create("DABannerViewWillLeaveApplication");
    

    __String* daInterstitialAdDidFailToReceiveAdWithErrorEvent = __String::create("DAInterstitialAdDidFailToReceiveAdWithError");
    __String* daInterstitialAdWillLeaveApplicationEvent = __String::create("DAInterstitialAdWillLeaveApplication");
    
    __String* willOpenDAInterstitialAdEvent = __String::create("willOpenDAInterstitialAd");
    __String* didOpenDAInterstitialAdEvent = __String::create("didOpenDAInterstitialAd");
    __String* willCloseDAInterstitialAdEvent = __String::create("willCloseDAInterstitialAd");
    __String* didCloseDAInterstitialAdEvent = __String::create("didCloseDAInterstitialAd");
    
    __String* daPopupAdDidFailToReceiveAdWithErrorEvent =  __String::create("DAPopupAdDidFailToReceiveAdWithError");
    __String* daPopupAdWillLeaveApplicationEvent = __String::create("DAPopupAdWillLeaveApplication");
    
    
    __String* willOpenDAPopupAdEvent = __String::create("willOpenDAPopupAd");
    __String* didOpenDAPopupAdEvent = __String::create("didOpenDAPopupAd");
    __String* willCloseDAPopupAdEvent = __String::create("willCloseDAPopupAd");
    __String* didCloseDAPopupAdEvent = __String::create("didCloseDAPopupAd");
    
    __String* daNativeAdDidFinishLoadingEvent =  __String::create("DANativeAdDidFinishLoading");
    __String* daNativeAddidFailWithErrorEvent =  __String::create("DANativeAddidFailWithError");
    
    
    __String* daInterstitialAdDidLoadEvent =  __String::create("DAInterstitialAdDidLoad");
    
    __String* daPopupAdDidLoadEvent =  __String::create("DAPopupAdDidLoad");
    
    
    if(strEventMsg->compare(daBannerViewDidLoadAdEvent->getCString()) == 0)
    {
        log("1. DABannerViewDidLoadAd");
    }
    else if (strEventMsg->compare(daBannerViewDidFailToReceiveAdWithErrorEvent->getCString()) == 0)
    {
        log("1. DABannerViewDidFailToReceiveAdWithError");
    }
    else if (strEventMsg->compare(daBannerViewWillLeaveApplicationEvent->getCString()) == 0)
    {
        log("1. DABannerViewWillLeaveApplication");
    }
    else if (strEventMsg->compare(daInterstitialAdDidFailToReceiveAdWithErrorEvent->getCString()) == 0)
    {
        log("1. DAInterstitialAdDidFailToReceiveAdWithError");
    }
    else if (strEventMsg->compare(daInterstitialAdWillLeaveApplicationEvent->getCString()) == 0)
    {
        log("1. DAInterstitialAdWillLeaveApplication");
    }
    else if (strEventMsg->compare(willOpenDAInterstitialAdEvent->getCString()) == 0)
    {
        log("1. willOpenDAInterstitialAd");
    }
    else if (strEventMsg->compare(didOpenDAInterstitialAdEvent->getCString()) == 0)
    {
        log("1. didOpenDAInterstitialAd");
    }
    else if (strEventMsg->compare(willCloseDAInterstitialAdEvent->getCString()) == 0)
    {
        log("1. willCloseDAInterstitialAd");
    }
    else if (strEventMsg->compare(didCloseDAInterstitialAdEvent->getCString()) == 0)
    {
        log("1. didCloseDAInterstitialAd");
    }
    else if (strEventMsg->compare(daPopupAdDidFailToReceiveAdWithErrorEvent->getCString()) == 0)
    {
        log("1. DAPopupAdDidFailToReceiveAdWithError");
    }
    else if (strEventMsg->compare(daPopupAdWillLeaveApplicationEvent->getCString()) == 0)
    {
        log("1. DAPopupAdWillLeaveApplication");
    }
    else if (strEventMsg->compare(willOpenDAPopupAdEvent->getCString()) == 0)
    {
        log("1. willOpenDAPopupAd");
    }
    else if (strEventMsg->compare(didOpenDAPopupAdEvent->getCString()) == 0)
    {
        log("1. didOpenDAPopupAd");
    }
    else if (strEventMsg->compare(willCloseDAPopupAdEvent->getCString()) == 0)
    {
        log("1. willCloseDAPopupAd");
    }
    else if (strEventMsg->compare(didCloseDAPopupAdEvent->getCString()) == 0)
    {
        log("1. didCloseDAPopupAd");
    }
    else if (strEventMsg->compare(daNativeAdDidFinishLoadingEvent->getCString()) == 0)
    {
        log("1. DANativeAdDidFinishLoading : nativeAdvertisingResultJson : %s", strOtherMsg->getCString());
    }
    else if (strEventMsg->compare(daNativeAddidFailWithErrorEvent->getCString()) == 0)
    {
        log("1. DANativeAddidFailWithError");
    }
    else if(strEventMsg->compare(daInterstitialAdDidLoadEvent->getCString()) == 0)
    {
        _pluginAdPopcornDA->callFuncWithParam("interstitialAdPresentFromViewController", NULL);
    }
    else if (strEventMsg->compare(daPopupAdDidLoadEvent->getCString()) == 0)
    {
        _pluginAdPopcornDA->callFuncWithParam("popupAdPresentFromViewController", NULL);
    }
    
    
}

#pragma mark - LiveOps
void LiveOpsListener::onAdsResult(AdsResultCode code, const char* msg)
{
    std::vector<std::string> strMsgVector = split(msg, '`');
    __String* strEventMsg = __String::create(strMsgVector[0].c_str());
    __String* strOtherMsg = __String::create("");
    if(strMsgVector.size() > 1)
    {
        strOtherMsg = __String::create(strMsgVector[1].c_str());
    }
    
    log("0. LiveOpsListener : strEventMsg : %s, strOtherMsg : %s", strEventMsg->getCString(), strOtherMsg->getCString());
    
    __String* setPopupLinkListener = __String::create("setPopupLinkListener");
    __String* setPopupCloseListener = __String::create("setPopupCloseListener");
    __String* getPopups = __String::create("getPopups");
    
    if (strEventMsg->compare(setPopupLinkListener->getCString()) == 0)
    {
        std::vector<std::string> strMsgVector = split(strOtherMsg->getCString(), ',');
        __String* strPopupSpaceKey = __String::create(strMsgVector[0].c_str());
        __String* strCustomData = __String::create(strMsgVector[1].c_str());
        
        log("1. setPopupLinkListener : %s, %s", strPopupSpaceKey->getCString(), strCustomData->getCString());
    }
    else if (strEventMsg->compare(setPopupCloseListener->getCString()) == 0)
    {
        std::vector<std::string> strMsgVector = split(strOtherMsg->getCString(), ',');
        __String* strPopupSpaceKey = __String::create(strMsgVector[0].c_str());
        __String* strPopupCampaignName = __String::create(strMsgVector[1].c_str());
        __String* strCustomData = __String::create(strMsgVector[2].c_str());
        __String* strRemainPopupNum = __String::create(strMsgVector[3].c_str());
        
        log("1. setPopupCloseListener : %s, %s, %s, %s", strPopupSpaceKey->getCString(), strPopupCampaignName->getCString(), strCustomData->getCString(), strRemainPopupNum->getCString());
    }
    else if (strEventMsg->compare(getPopups->getCString()) == 0)
    {
        log("1. getPopups");
        
        PluginParam pPopupSpaceKey("haha");
        _pluginLiveOps->callFuncWithParam("showPopups", &pPopupSpaceKey, NULL);
    }
}
