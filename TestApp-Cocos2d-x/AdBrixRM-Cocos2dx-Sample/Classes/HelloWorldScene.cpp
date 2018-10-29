#include "HelloWorldScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    using namespace cocos2d;


#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    using namespace cocos2d::plugin;
#endif


USING_NS_CC;

enum AdBrixRMSdkTags {
    kTagEvents,
    kTagLevelAchieved,
    kTagTutorialCompleted,
    kTagCharacterCreated,
    kTagStageCleared,
    kTagSignUp,
    kTagUseCredit,
    kTagAppUpdate,
    kTagInvite,
    kTagPurchaseB,
    kTagPurchaseS,
    kTagLogin,
    kTagProps,
    kTagGdprForgetMe
};

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    auto label = Label::createWithTTF("AdBrixRM Cocos2d Sample AOS", "fonts/Marker Felt.ttf", 24);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    auto label = Label::createWithTTF("AdBrixRM Cocos2d Sample iOS", "fonts/Marker Felt.ttf", 24);
#endif

    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 0);

    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    
    //AdBrix Remaster Integrate sample menus - start
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 0);
    initSdkMenu(menu);
    //AdBrix Remaster Integrate sample menus - end

    
    //AdBrix Remaster Integrate - start
    loadAdBrixRmPlugin();
    //AdBrix Remaster Integrate - end
    
    
    

   
    
    
    return true;
}

void HelloWorld::initSdkMenu(Menu* menu) {
    
    std::vector < std::pair<int, const char*> > items;
    items.push_back(std::make_pair(kTagEvents, "Events"));
    items.push_back(std::make_pair(kTagLevelAchieved, "LevelAchieved"));
    items.push_back(std::make_pair(kTagTutorialCompleted, "TutorialCompleted"));
    items.push_back(std::make_pair(kTagCharacterCreated, "CharacterCreated"));
    items.push_back(std::make_pair(kTagStageCleared, "StageCleared"));
    items.push_back(std::make_pair(kTagSignUp, "SignUp"));
    items.push_back(std::make_pair(kTagUseCredit, "UseCredit"));
    items.push_back(std::make_pair(kTagAppUpdate, "AppUpdate"));
    items.push_back(std::make_pair(kTagLogin, "Login"));
    items.push_back(std::make_pair(kTagInvite, "Invite"));
    items.push_back(std::make_pair(kTagPurchaseB, "Purchase-Bulk"));
    items.push_back(std::make_pair(kTagPurchaseS, "Purchase-Single"));
    items.push_back(std::make_pair(kTagProps, "Props(age,gender,prop)"));
    items.push_back(std::make_pair(kTagGdprForgetMe, "GdprForgetMe"));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    float columsPosX[] = { origin.x + visibleSize.width / 6, origin.x
        + (visibleSize.width * 3) / 6, origin.x
        + (visibleSize.width * 5) / 6 };
    
    float step = 45.0f;
    float beginY = origin.y + visibleSize.height - step;
    beginY -= 100.0f;
    for (auto it = items.begin(); it != items.end(); ++it) {
        auto item = MenuItemFont::create(it->second,
                                         CC_CALLBACK_1(HelloWorld::menuCallback, this));
        item->setTag(it->first);
        
        auto i = std::distance(items.begin(), it);
      
        item->setPosition(Point(columsPosX[i % 3], beginY - (i / 3) * step));
        
        menu->addChild(item, 1);
    }

}


void HelloWorld::menuCallback(Ref* pSender) {
    auto item = (MenuItemFont*) pSender;
    
    switch (item->getTag()) {
        case kTagEvents:
            menuEventsCallback();
            break;
            
        case kTagLevelAchieved:
            menuGameLevelAchievedCallback();
            break;
        case kTagTutorialCompleted:
            menuGameTutorialCompletedCallback();
            break;
        case kTagCharacterCreated:
            menuGameCharacterCreatedCallback();
            break;
        case kTagStageCleared:
            menuGameStageClearedCallback();
            break;
        case kTagSignUp:
            menuCommonSignUpCallback();
            break;
        case kTagUseCredit:
            menuCommonUseCreditCallback();
            break;
        case kTagAppUpdate:
            menuCommonAppUpdateCallback();
            break;
        case kTagInvite:
            menuCommonInviteCallback();
            break;
            
        case kTagPurchaseB:
            menuCommonPurchaseBulkCallback();
            break;
            
        case kTagPurchaseS:
            menuCommonPurchaseSingleCallback();
            break;
            
        case kTagLogin:
            menuLoginCallback();
            break;
        case kTagProps:
            menuPropsCallback();
            break;
        case kTagGdprForgetMe:
            menuGdprForgetMeCallback();
            break;
            
        default:
            break;
    }
}

void HelloWorld::loadAdBrixRmPlugin()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    _pluginAdBrixRm = dynamic_cast<ProtocolAnalytics*>(PluginManager::getInstance()->loadPlugin("PluginAdBrix"));
    
    printf("AdBrixRm plugin = %s", _pluginAdBrixRm->getPluginName());
#endif
}

void HelloWorld::unloadAdBrixRmPlugin()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (NULL != _pluginAdBrixRm) {
        std::string pluginName = _pluginAdBrixRm->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginAdBrixRm = NULL;
    }
#endif
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




void HelloWorld::menuEventsCallback()
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    Json::Value param;

    param["test_key"] = "test_key01";
    param["test_value"] = "test_value01";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::event("testCocosEvt", jsonStr);

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //just custom event with name
    PluginParam pEventName1("customEvents01");
    _pluginAdBrixRm->callFuncWithParam("events", &pEventName1, NULL);


    //custom event with name and parameter map
    PluginParam pEventName2("customEvents02");

    std::map<std::string,std::string> pEventParam;
    pEventParam["test_key0"] = "test_value0";
    pEventParam["test_key1"] = "test_value1";
    pEventParam["test_key2"] = "test_value2";
    PluginParam pEventParams(pEventParam);

    _pluginAdBrixRm->callFuncWithParam("eventsWithParam", &pEventName2, &pEventParams, NULL);
#endif


    
}

void  HelloWorld::menuGdprForgetMeCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    PluginAdBrixAOS::gdprForgetMe();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    _pluginAdBrixRm->callFuncWithParam("gdprForgetMe", NULL);
#endif
}

void  HelloWorld::menuLoginCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    PluginAdBrixAOS::login("AdBrixRemasterAOSTest");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pEventName1("adbrixremasteruser");
    _pluginAdBrixRm->callFuncWithParam("login", &pEventName1, NULL);
    
    bool isLoginSucc = false;
    if(isLoginSucc) {
        PluginParam pEventName1("adbrixremasteruser");
        _pluginAdBrixRm->callFuncWithParam("login", &pEventName1, NULL);
    }
    else {
        PluginParam pEventName1("");
        _pluginAdBrixRm->callFuncWithParam("login", &pEventName1, NULL);
    }
#endif
}

void  HelloWorld::menuPropsCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    PluginAdBrixAOS::setUserProperties("nickname","cocos_adbrixer");
    PluginAdBrixAOS::setAge(20);
    PluginAdBrixAOS::setGender(1);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::map<std::string,std::string> pEventParam;
    pEventParam["nickname"] = "adbrixrm";
    pEventParam["birthday"] = "2018";
    PluginParam pEventParams(pEventParam);
    
    _pluginAdBrixRm->callFuncWithParam("setUserProperties", &pEventParams, NULL);
    
    PluginParam pAge(20);
    _pluginAdBrixRm->callFuncWithParam("setAge", &pAge, NULL);
    
    PluginParam pGender(1);
    _pluginAdBrixRm->callFuncWithParam("setGender", &pGender, NULL);
#endif
}

void  HelloWorld::menuGameLevelAchievedCallback() {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;

    param["rewards"] = "n";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::gameLevelAchieved (10, jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pLevel(10);
    
    std::map<std::string,std::string> pAttrParam;
    
    pAttrParam["gold"] = "10";
    pAttrParam["prev_all_cleared"] = "n";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameLevelAchieved", &pLevel, &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuGameTutorialCompletedCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;
    param["rewards"] = "y";
    param["rewards_gold"] = "100";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::gameTutorialCompleted (false, jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pIsSkip(false);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameTutorialCompleted", &pIsSkip, &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuGameCharacterCreatedCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;

    param["c_name"] = "freddy";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::gameCharacterCreated (jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameCharacterCreated", &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuGameStageClearedCallback() {
 #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;

    param["rewards"] = "y";
    param["rewards_gold"] = "500";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::gameStageCleared ("1-2", jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pStageName("1-1");
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameStageCleared", &pStageName, &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuCommonSignUpCallback() {
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;
    param["with_userid"] = "n";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::commonSignUp (AdBrixSignUpKakaoChannel, jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pSignChannel(AdBrixSignUpNaverChannel);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["test_key"] = "test_value";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonSignUp", &pSignChannel, &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuCommonUseCreditCallback() {
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;
    param["card"] = "samsung";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::commonUseCredit (jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["type"] = "gold";
    PluginParam pAttrParams(pAttrParam);
    _pluginAdBrixRm->callFuncWithParam("commonUseCredit", &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuCommonAppUpdateCallback() {
 #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;
    param["market"] = "google_play";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::commonAppUpdate ("1.0", "1.1", jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pPrevVer("1.0");
    PluginParam pCurrVer("1.1");
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["market"] = "app_store";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonAppUpdate", &pPrevVer, &pCurrVer, &pAttrParams, NULL);
#endif
}

void  HelloWorld::menuCommonInviteCallback() {
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Json::Value param;
    param["email_auth"] = "y";

    Json::StreamWriterBuilder builder;
    std::string jsonStr = Json::writeString(builder, param);

    PluginAdBrixAOS::commonInvite (AdBrixInviteGoogleChannel, jsonStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PluginParam pinviteChannel(AdBrixInviteKakaoChannel);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["test_key"] = "test_value";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonInvite", &pinviteChannel, &pAttrParams, NULL);
#endif
}

void HelloWorld::menuCommonPurchaseSingleCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    std::map<std::string, std::string> pMap;
    pMap["productattr_key01"] = "productattr_value01";
    pMap["productattr_key02"] = "productattr_value02";

    //set the extra value to the AdBrixCommerceProductAttrModel
    AdBrixCommerceProductAttrModel *attr = AdBrixCommerceProductAttrModel::create(pMap);
    AdBrixCommerceProductCategoryModel *cat = AdBrixCommerceProductCategoryModel::create("cat1", "cat2");
    Json::Value pProductModel = AdBrixCommerceProductModel::create("cocos2d_x_PRODUCT_ID", "cocos2d_x_PRODUCT_NAME", 1000.0, 500.0, 1, AdBrixCurrencyKRW, cat, attr);

    Json::StreamWriterBuilder builder;
    std::string pProductModelJson = Json::writeString(builder, pProductModel);

    Json::Value pOrderAttrMap;

    pOrderAttrMap["orderattr_key01"] = "orderattr_value01";

    Json::StreamWriterBuilder builder2;
    std::string orderAttrStr = Json::writeString(builder2, pOrderAttrMap);


    PluginAdBrixAOS::commonPurchase("cocos2d_x_PRODUCT_ID", pProductModelJson.c_str(), 1000.00, 3500.00, AdBrixPaymentCreditCard, orderAttrStr);

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::map<std::string,std::string> pMap;
    
    pMap["productattr_key01"]="productattr_value01";
    pMap["productattr_key02"]="productattr_value02";
    
    AdBrixRmCommerceProductAttrModel *attr = AdBrixRmCommerceProductAttrModel::create(pMap);
    AdBrixRmCommerceProductCategoryModel *cat = AdBrixRmCommerceProductCategoryModel::create("cat1", "cat2");
    AdBrixRmCommerceProductModel *pProductModel = NULL;
    
    
    PluginParam pCurrency(AdBrixCurrencyKRW);
    std::string currencyStr = _pluginAdBrixRm->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    PluginParam pProduct(pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID", "cocos2d_x_PRODUCT_NAME", 1000.0, 500.0, 1, currencyStr.c_str(), cat, attr).c_str());
    
    
    PluginParam pOrderId("290192012");
    PluginParam pDiscount(4000);
    PluginParam pDeliveryCharge(4000);
    PluginParam pPaymentMethod(AdBrixPaymentCreditCard);
    
    std::map<std::string,std::string> pOrderAttrParam;
    pOrderAttrParam["orderattr_key01"] = "orderattr_value01";
    PluginParam pOrderAttrParams(pOrderAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonPurchaseSingle", &pOrderId, &pProduct, &pDiscount, &pDeliveryCharge, &pPaymentMethod, &pOrderAttrParams, NULL);
#endif
}

void  HelloWorld::menuCommonPurchaseBulkCallback() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

    std::map<std::string, std::string> pMap;
    pMap["productattr_key01"] = "productattr_value01";
    pMap["productattr_key02"] = "productattr_value02";

    //set the extra value to the AdBrixCommerceProductAttrModel
    AdBrixCommerceProductAttrModel *attr = AdBrixCommerceProductAttrModel::create(pMap);
    AdBrixCommerceProductCategoryModel *cat = AdBrixCommerceProductCategoryModel::create("cat1", "cat2");

    //make product
    Json::Value pProductModel1 = AdBrixCommerceProductModel::create("cocos2d_x_PRODUCT_ID1", "cocos2d_x_PRODUCT_NAME1", 1000.0, 500.0, 1, AdBrixCurrencyKRW, cat, attr);
    Json::Value pProductModel2 = AdBrixCommerceProductModel::create("cocos2d_x_PRODUCT_ID2", "cocos2d_x_PRODUCT_NAME2", 2000.0, 500.0, 1, AdBrixCurrencyKRW, cat, attr);
    Json::Value pProductModel3 = AdBrixCommerceProductModel::create("cocos2d_x_PRODUCT_ID3", "cocos2d_x_PRODUCT_NAME3", 3000.0, 500.0, 1, AdBrixCurrencyKRW, cat, attr);

    //generate product array
    Json::Value pProductArray;
    pProductArray.append(pProductModel1);
    pProductArray.append(pProductModel2);
    pProductArray.append(pProductModel3);
    Json::StreamWriterBuilder builder;
    std::string pProductArrayStr = Json::writeString(builder, pProductArray);

    Json::Value pOrderAttrMap;

    pOrderAttrMap["orderattr_key01"] = "orderattr_value01";

    Json::StreamWriterBuilder attrBuilder;
    std::string orderAttrStr = Json::writeString(attrBuilder, pOrderAttrMap);

    PluginAdBrixAOS::commonPurchaseBulk("cocos2d_x_PRODUCT_ID", pProductArrayStr.c_str(), 1000.00, 3500.00, AdBrixPaymentCreditCard, orderAttrStr);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    std::map<std::string,std::string> pMap;
    
    pMap["productattr_key01"]="productattr_value01";
    pMap["productattr_key02"]="productattr_value02";
    
    AdBrixRmCommerceProductAttrModel *attr = AdBrixRmCommerceProductAttrModel::create(pMap);
    AdBrixRmCommerceProductCategoryModel *cat = AdBrixRmCommerceProductCategoryModel::create("cat1", "cat2");
    AdBrixRmCommerceProductModel *pProductModel = NULL;
    
    PluginParam pCurrency(AdBrixCurrencyKRW);
    std::string currencyStr = _pluginAdBrixRm->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    
    
    
    std::map<std::string,std::string> pProductMap;
    
    pProductMap["key01"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID01", "cocos2d_x_PRODUCT_NAME01", 500.0, 100.0, 1, currencyStr.c_str(), cat, attr).c_str();
    pProductModel = NULL;
    pProductMap["key02"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID02", "cocos2d_x_PRODUCT_NAME02", 600.0, 200.0, 1, currencyStr.c_str(), cat, attr).c_str();
    pProductModel = NULL;
    pProductMap["key03"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID03", "cocos2d_x_PRODUCT_NAME03", 700.0, 300.0, 1, currencyStr.c_str(), cat, attr).c_str();
    pProductModel = NULL;
    pProductMap["key04"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID04", "cocos2d_x_PRODUCT_NAME04", 800.0, 400.0, 1, currencyStr.c_str(), cat, attr).c_str();
    pProductModel = NULL;
    pProductMap["key05"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID05", "cocos2d_x_PRODUCT_NAME05", 900.0, 500.0, 1, currencyStr.c_str(), cat, attr).c_str();
    
//    printf("MAPAMAP :: %@", pProductMap.size());
    PluginParam pProductList(pProductMap);
    
    PluginParam pOrderId("290192012");
    PluginParam pDiscount(4000);
    PluginParam pDeliveryCharge(4000);
    PluginParam pPaymentMethod(AdBrixPaymentCreditCard);
    
    std::map<std::string,std::string> pOrderAttrParam;
    pOrderAttrParam["orderattr_key01"] = "orderattr_value01";
    PluginParam pOrderAttrParams(pOrderAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonPurchaseBulk", &pOrderId, &pProductList, &pDiscount, &pDeliveryCharge, &pPaymentMethod, &pOrderAttrParams, NULL);
#endif
}


