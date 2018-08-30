//
//  TestCommerceV2.cpp
//  IgaworksSDKCocos2dxSample
//
//  Created by igaworks on 2017. 2. 15..
//
//

#include "TestCommerceV2.h"
#include "HelloWorldScene.h"

using namespace cocos2d::plugin;

USING_NS_CC;

Scene* TestCommerceV2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestCommerceV2::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestCommerceV2::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    loadAdBrixPlugin();
    loadIgaworksCommercePlugin();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto goToMain = MenuItemFont::create("Goto Main", CC_CALLBACK_1(TestCommerceV2::menuGoToMain, this));
    goToMain->setColor(Color3B(0, 255, 0));
    // create menu, it's an autorelease object
    auto menu = Menu::create(goToMain, NULL);
    menu->setPosition(goToMain->getContentSize().width/2.0, goToMain->getContentSize().height/2.0);
    this->addChild(menu, 1);
    
    auto apiPurchaseI = MenuItemFont::create("CV2 purchase I", CC_CALLBACK_1(TestCommerceV2::apiPurchaseI, this));
    // create menu, it's an autorelease object
    menu = Menu::create(apiPurchaseI, NULL);
    menu->setPosition(200.0f,400.0f);
    this->addChild(menu, 1);
    
    auto apiPurchaseII = MenuItemFont::create("CV2 Purchase II", CC_CALLBACK_1(TestCommerceV2::apiPurchaseII, this));
    // create menu, it's an autorelease object
    menu = Menu::create(apiPurchaseII, NULL);
    menu->setPosition(200.0f, 370.0f);
    this->addChild(menu, 1);
    
    auto apiPurchaseIII = MenuItemFont::create("CV2 Purchase III", CC_CALLBACK_1(TestCommerceV2::apiPurchaseIII, this));
    // create menu, it's an autorelease object
    menu = Menu::create(apiPurchaseIII, NULL);
    menu->setPosition(200.0f, 340.0f);
    this->addChild(menu, 1);
    
    return true;
}

void TestCommerceV2::menuGoToMain(Ref* pSender)
{
    Scene *pScene =  HelloWorld::createScene();
    Director:: getInstance()->replaceScene(pScene);
    return;
}
void TestCommerceV2::apiPurchaseI(Ref* pSender)
{
    PluginParam pProductId("cocos2d_x_PRODUCT_ID");
    PluginParam pPrice(5000);
    PluginParam pCurrency(AdBrixCurrencyKRW);
    std::string currencyUSD = _pluginAdBrix->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    PluginParam pPaymentMethod(AdBrixPaymentCreditCard);
    std::string paymentCreditCard = _pluginAdBrix->callStringFuncWithParam("paymentMethod", &pPaymentMethod, NULL);
    
    PluginParam pCurrencyString(currencyUSD.c_str());
    
    _pluginAdBrix->callFuncWithParam("commercePurchaseI", &pProductId, &pPrice, &currencyUSD, &paymentCreditCard, NULL);
}

void TestCommerceV2::apiPurchaseII(Ref* pSender)
{
    std::map<std::string,std::string> pMap;
    
    pMap["key01"]="value01";
    pMap["key02"]="value02";
    pMap["key03"]="value03";
    pMap["key04"]="value04";
    
    AdBrixRmCommerceProductAttrModel *attr = AdBrixRmCommerceProductAttrModel::create(pMap);
    AdBrixRmCommerceProductCategoryModel *cat = AdBrixRmCommerceProductCategoryModel::create("cat1", "cat2");
    AdBrixRmCommerceProductModel *pProductModel = NULL;
    
    PluginParam pOrderId("cocos2d_x_ORDER_ID");
    PluginParam pProductId("cocos2d_x_PRODUCT_ID");
    PluginParam pDiscount(4000);
    PluginParam pDeliveryCharge(4000);
    PluginParam pPrice(5000);
    PluginParam pCurrency(AdBrixCurrencyKRW);
    std::string currencyUSD = _pluginAdBrix->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    PluginParam pPaymentMethod(AdBrixPaymentCreditCard);
    std::string paymentCreditCard = _pluginAdBrix->callStringFuncWithParam("paymentMethod", &pPaymentMethod, NULL);
    
    PluginParam pActivityName(pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID", "cocos2d_x_PRODUCT_NAME", 1000.0, 500.0, 1, currencyUSD.c_str(), cat, attr).c_str());

    _pluginAdBrix->callFuncWithParam("commercePurchaseII", &pOrderId, &pActivityName, &pDiscount, &pDeliveryCharge, &pCurrency, NULL);
}

void TestCommerceV2::apiPurchaseIII(Ref* pSender)
{
    std::map<std::string,std::string> pMap;

    pMap["key01"]="value01";
    pMap["key02"]="value02";
    pMap["key03"]="value03";
    pMap["key04"]="value04";

    AdBrixRmCommerceProductAttrModel *attr = AdBrixRmCommerceProductAttrModel::create(pMap);
    AdBrixRmCommerceProductCategoryModel *cat = AdBrixRmCommerceProductCategoryModel::create("cat1", "cat2");
    AdBrixRmCommerceProductModel *pProductModel = NULL;

    PluginParam pOrderId("cocos2d_x_ORDER_ID");
    PluginParam pProductId("cocos2d_x_PRODUCT_ID");
    PluginParam pDiscount(4000);
    PluginParam pDeliveryCharge(4000);
    PluginParam pPrice(5000);
    PluginParam pCurrency(AdBrixCurrencyKRW);
    std::string currencyUSD = _pluginAdBrix->callStringFuncWithParam("currencyName", &pCurrency, NULL);
    PluginParam pPaymentMethod(AdBrixPaymentCreditCard);
    std::string paymentCreditCard = _pluginAdBrix->callStringFuncWithParam("paymentMethod", &pPaymentMethod, NULL);


    std::map<std::string,std::string> pProductMap;
    
    pProductMap["key01"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID01", "cocos2d_x_PRODUCT_NAME01", 500.0, 100.0, 1, currencyUSD.c_str(), cat, attr).c_str();
    pProductMap["key02"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID02", "cocos2d_x_PRODUCT_NAME02", 600.0, 200.0, 1, currencyUSD.c_str(), cat, attr).c_str();
    pProductMap["key03"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID03", "cocos2d_x_PRODUCT_NAME03", 700.0, 300.0, 1, currencyUSD.c_str(), cat, attr).c_str();
    pProductMap["key04"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID04", "cocos2d_x_PRODUCT_NAME04", 800.0, 400.0, 1, currencyUSD.c_str(), cat, attr).c_str();
    pProductMap["key05"]=pProductModel->AdBrixRmCommerceProductModel::create("cocos2d_x_PRODUCT_ID05", "cocos2d_x_PRODUCT_NAME05", 900.0, 500.0, 1, currencyUSD.c_str(), cat, attr).c_str();

    PluginParam pProductList(pProductMap);
    
    _pluginAdBrix->callFuncWithParam("commercePurchaseIII", &pOrderId, &pProductList, &pDiscount, &pDeliveryCharge, &pCurrency, NULL);
}

void TestCommerceV2::loadAdBrixPlugin()
{
    _pluginAdBrix = dynamic_cast<ProtocolAnalytics*>(PluginManager::getInstance()->loadPlugin("PluginAdBrix"));
    
    printf("AdBrix plugin = %s", _pluginAdBrix->getPluginName());
}

void TestCommerceV2::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    auto touch = touches[0];
    auto touchPoint = touch->getLocation();
    touchPoint = this->convertToWorldSpace(touchPoint);
    
    log("onTouchesBegan id = %d, x = %f, y = %f",
        touch->getID(),
        touchPoint.x,
        touchPoint.y);
}


void TestCommerceV2::loadIgaworksCommercePlugin()
{
    PluginProtocol* col = PluginManager::getInstance()->loadPlugin("PluginIgaworksCommerce");
    _pluginIgaworksCommerce = dynamic_cast<ProtocolIAP*>(col);
    
    printf("IgaworksCommerce plugin = %s", _pluginIgaworksCommerce->getPluginName());
}

void TestCommerceV2::unloadIgaworksCommercePlungin()
{
    if (NULL != _pluginIgaworksCommerce) {
        std::string pluginName = _pluginIgaworksCommerce->getPluginName();
        PluginManager::getInstance()->unloadPlugin(pluginName.c_str());
        _pluginIgaworksCommerce = NULL;
    }
}


