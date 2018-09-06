#include "HelloWorldScene.h"

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
    
    
    
    //AdBrix Remaster Integrate - start
    loadAdBrixRmPlugin();
    
    
    float menuX1pos = 150.0f;
    float menuX2pos = 380.0f;
    float menuX3pos = 610.0f;
    float menuY1pos = 100.0f;
    float menuY2pos = 100.f;
    float menuY3pos = 100.f;
    float menuYInterval = 50.0f;
    
    
    
    auto events = MenuItemFont::create("Events", CC_CALLBACK_1(HelloWorld::menuEventsCallback, this));
    auto menu = Menu::create(events, NULL);
    menu->setPosition(menuX1pos, menuY1pos);
    this->addChild(menu, 1);
    
    menuY1pos += menuYInterval;
    events = MenuItemFont::create("LevelAchieved", CC_CALLBACK_1(HelloWorld::menuGameLevelAchievedCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX1pos, menuY1pos);
    this->addChild(menu, 1);
    
    menuY1pos += menuYInterval;
    events = MenuItemFont::create("TutorialCompleted", CC_CALLBACK_1(HelloWorld::menuGameTutorialCompletedCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX1pos, menuY1pos);
    this->addChild(menu, 1);
    
    menuY1pos += menuYInterval;
    events = MenuItemFont::create("CharacterCreated", CC_CALLBACK_1(HelloWorld::menuGameCharacterCreatedCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX1pos, menuY1pos);
    this->addChild(menu, 1);
    
    menuY1pos += menuYInterval;
    events = MenuItemFont::create("StageCleared", CC_CALLBACK_1(HelloWorld::menuGameStageClearedCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX1pos, menuY1pos);
    this->addChild(menu, 1);
    
    
    
    
    events = MenuItemFont::create("SignUp", CC_CALLBACK_1(HelloWorld::menuCommonSignUpCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    menuY2pos += menuYInterval;
    events = MenuItemFont::create("UseCredit", CC_CALLBACK_1(HelloWorld::menuCommonUseCreditCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    menuY2pos += menuYInterval;
    events = MenuItemFont::create("AppUpdate", CC_CALLBACK_1(HelloWorld::menuCommonAppUpdateCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    menuY2pos += menuYInterval;
    events = MenuItemFont::create("Invite", CC_CALLBACK_1(HelloWorld::menuCommonInviteCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    menuY2pos += menuYInterval;
    events = MenuItemFont::create("Purchase-Bulk", CC_CALLBACK_1(HelloWorld::menuCommonPurchaseBulkCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    menuY2pos += menuYInterval;
    events = MenuItemFont::create("Purchase-Single", CC_CALLBACK_1(HelloWorld::menuCommonPurchaseSingleCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX2pos, menuY2pos);
    this->addChild(menu, 1);
    
    events = MenuItemFont::create("Login", CC_CALLBACK_1(HelloWorld::menuLoginCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX3pos, menuY3pos);
    this->addChild(menu, 1);
    
    menuY3pos += menuYInterval;
    events = MenuItemFont::create("Props(age,gender,prop)", CC_CALLBACK_1(HelloWorld::menuPropsCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX3pos, menuY3pos);
    this->addChild(menu, 1);
    
    menuY3pos += menuYInterval;
    events = MenuItemFont::create("GdprForgetMe", CC_CALLBACK_1(HelloWorld::menuGdprForgetMeCallback, this));
    menu = Menu::create(events, NULL);
    menu->setPosition(menuX3pos, menuY3pos);
    this->addChild(menu, 1);
    
    
    //AdBrix Remaster Integrate - end
    
    
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
    
    auto label = Label::createWithTTF("AdBrixRM Cocos2d Sample", "fonts/Marker Felt.ttf", 24);
    
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



void HelloWorld::loadAdBrixRmPlugin()
{
    _pluginAdBrixRm = dynamic_cast<ProtocolAnalytics*>(PluginManager::getInstance()->loadPlugin("PluginAdBrix"));
    
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




void HelloWorld::menuEventsCallback(Ref* pSender)
{
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
    
}

void  HelloWorld::menuGdprForgetMeCallback(cocos2d::Ref* pSender) {
    _pluginAdBrixRm->callFuncWithParam("gdprForgetMe", NULL);
}

void  HelloWorld::menuLoginCallback(cocos2d::Ref* pSender) {
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
}

void  HelloWorld::menuPropsCallback(cocos2d::Ref* pSender) {
    
    std::map<std::string,std::string> pEventParam;
    pEventParam["nickname"] = "adbrixrm";
    pEventParam["birthday"] = "2018";
    PluginParam pEventParams(pEventParam);
    
    _pluginAdBrixRm->callFuncWithParam("setUserProperties", &pEventParams, NULL);
    
    PluginParam pAge(20);
    _pluginAdBrixRm->callFuncWithParam("setAge", &pAge, NULL);
    
    PluginParam pGender(1);
    _pluginAdBrixRm->callFuncWithParam("setGender", &pGender, NULL);
}

void  HelloWorld::menuGameLevelAchievedCallback(cocos2d::Ref* pSender) {
    
    PluginParam pLevel(10);
    
    std::map<std::string,std::string> pAttrParam;
    
    pAttrParam["gold"] = "10";
    pAttrParam["prev_all_cleared"] = "n";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameLevelAchieved", &pLevel, &pAttrParams, NULL);
}

void  HelloWorld::menuGameTutorialCompletedCallback(cocos2d::Ref* pSender) {
    PluginParam pIsSkip(false);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameTutorialCompleted", &pIsSkip, &pAttrParams, NULL);
}

void  HelloWorld::menuGameCharacterCreatedCallback(cocos2d::Ref* pSender) {
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameCharacterCreated", &pAttrParams, NULL);
}

void  HelloWorld::menuGameStageClearedCallback(cocos2d::Ref* pSender) {
    PluginParam pStageName("1-1");
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["gold"] = "10";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("gameStageCleared", &pStageName, &pAttrParams, NULL);
}

void  HelloWorld::menuCommonSignUpCallback(cocos2d::Ref* pSender) {
    PluginParam pSignChannel(AdBrixSignUpNaverChannel);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["test_key"] = "test_value";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonSignUp", &pSignChannel, &pAttrParams, NULL);
    
}

void  HelloWorld::menuCommonUseCreditCallback(cocos2d::Ref* pSender) {
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["type"] = "gold";
    PluginParam pAttrParams(pAttrParam);
    _pluginAdBrixRm->callFuncWithParam("commonUseCredit", &pAttrParams, NULL);
}

void  HelloWorld::menuCommonAppUpdateCallback(cocos2d::Ref* pSender) {
    PluginParam pPrevVer("1.0");
    PluginParam pCurrVer("1.1");
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["market"] = "app_store";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonAppUpdate", &pPrevVer, &pCurrVer, &pAttrParams, NULL);
}

void  HelloWorld::menuCommonInviteCallback(cocos2d::Ref* pSender) {
    PluginParam pinviteChannel(AdBrixInviteKakaoChannel);
    
    std::map<std::string,std::string> pAttrParam;
    pAttrParam["test_key"] = "test_value";
    PluginParam pAttrParams(pAttrParam);
    
    _pluginAdBrixRm->callFuncWithParam("commonInvite", &pinviteChannel, &pAttrParams, NULL);
    
}

void HelloWorld::menuCommonPurchaseSingleCallback(cocos2d::Ref* pSender) {
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
}

void  HelloWorld::menuCommonPurchaseBulkCallback(cocos2d::Ref* pSender) {
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
}


