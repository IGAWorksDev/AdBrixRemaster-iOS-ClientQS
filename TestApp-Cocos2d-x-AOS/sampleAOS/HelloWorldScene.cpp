#include "HelloWorldScene.h"
#include "IgaworksPlugin.h"
#include "TestCommerceV2.h"
#define COCOS2D_DEBUG 1

USING_NS_CC;

bool enable = true;

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
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("IgaWorks cocos2d-x android sample", "Arial", 24);
    
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

	/*
    auto btnLabel_1 = Label::createWithSystemFont("Init GCM", "Airal", 50);
    auto btnLabel_2 = Label::createWithSystemFont("GET POPUP", "Airal", 50);
    auto btnLabel_3 = Label::createWithSystemFont("ShowCouponDialog", "Airal", 50);
    auto btnLabel_4 = Label::createWithSystemFont("Usecoupon", "Airal", 50);
    auto btnLabel_5 = Label::createWithSystemFont("Flush", "Airal", 50);
    auto btnLabel_6 = Label::createWithSystemFont("purchase", "Airal", 50);

    auto mItem_1 = MenuItemLabel::create(btnLabel_1, CC_CALLBACK_1(HelloWorld::menuCallback1, this));
    auto mItem_2 = MenuItemLabel::create(btnLabel_2, CC_CALLBACK_1(HelloWorld::menuCallback2, this));
    auto mItem_3 = MenuItemLabel::create(btnLabel_3, CC_CALLBACK_1(HelloWorld::menuCallback3, this));
    auto mItem_4 = MenuItemLabel::create(btnLabel_4, CC_CALLBACK_1(HelloWorld::menuCallback4, this));
    auto mItem_5 = MenuItemLabel::create(btnLabel_5, CC_CALLBACK_1(HelloWorld::menuCallback5, this));
    auto mItem_6 = MenuItemLabel::create(btnLabel_5, CC_CALLBACK_1(HelloWorld::menuCallback5, this));

    auto menu = Menu::create(mItem_1, mItem_2, mItem_3, mItem_4, mItem_5, mItem_6, NULL);

    menu->alignItemsVertically();
    this->addChild(menu);
	*/
	// AdBrix

	auto firstTimeExperienceItem = MenuItemFont::create("firstTimeExperience", CC_CALLBACK_1(HelloWorld::menuFirstTimeExperienceCallback, this));
	menu = Menu::create(firstTimeExperienceItem, NULL);
	menu->setPosition(200.0f, 340.0f);
	this->addChild(menu, 1);

	auto retentionItem = MenuItemFont::create("retention", CC_CALLBACK_1(HelloWorld::menuRetentionCallback, this));
	menu = Menu::create(retentionItem, NULL);
	menu->setPosition(200.0f, 310.0f);
	this->addChild(menu, 1);

	auto buyItem = MenuItemFont::create("buy", CC_CALLBACK_1(HelloWorld::menuBuyCallback, this));
	menu = Menu::create(buyItem, NULL);
	menu->setPosition(200.0f, 280.0f);
	this->addChild(menu, 1);

	auto customCohortItem = MenuItemFont::create("Set Custom Cohort", CC_CALLBACK_1(HelloWorld::menuSetCustomCohortCallback, this));
	menu = Menu::create(customCohortItem, NULL);
	menu->setPosition(200.0f, 250.0f);
	this->addChild(menu, 1);

	/*
	auto showADItem = MenuItemFont::create("CrossPromotion Show AD", CC_CALLBACK_1(HelloWorld::menuCrossPromotionShowADCallback, this));
	menu = Menu::create(showADItem, NULL);
	menu->setPosition(200.0f, 220.0f);
	this->addChild(menu, 1);
	*/

	auto showCouponItem = MenuItemFont::create("Show Coupon", CC_CALLBACK_1(HelloWorld::menuShowCouponCallback, this));
	menu = Menu::create(showCouponItem, NULL);
	menu->setPosition(200.0f, 190.0f);
	this->addChild(menu, 1);

	auto checkCouponItem = MenuItemFont::create("Check Coupon", CC_CALLBACK_1(HelloWorld::menuCheckCouponCallback, this));
	menu = Menu::create(checkCouponItem, NULL);
	menu->setPosition(200.0f, 160.0f);
	this->addChild(menu, 1);

	// IgaworksNanoo

	auto getNanooFanPageItem = MenuItemFont::create("GetNanooFanPage", CC_CALLBACK_1(HelloWorld::menuGetNanooFanPageCallback, this));
	menu = Menu::create(getNanooFanPageItem, NULL);
	menu->setPosition(600.0f, 400.0f);
	this->addChild(menu, 1);

	// LivePos

	auto setFCMiidToLiveOps = MenuItemFont::create("LiveOps registerFCMToken", CC_CALLBACK_1(HelloWorld::menuSetFCMiidToLiveOps, this));
	menu = Menu::create(setFCMiidToLiveOps, NULL);
	menu->setPosition(600.0f, 250.0f);
	this->addChild(menu, 1);

	auto showLiveOpsAdItem = MenuItemFont::create("LiveOps Popup", CC_CALLBACK_1(HelloWorld::menuLiveOpsPopup, this));
	menu = Menu::create(showLiveOpsAdItem, NULL);
	menu->setPosition(600.0f, 220.0f);
	this->addChild(menu, 1);

	// IgaworksCommerce

	auto purchaseCommerceItem = MenuItemFont::create("Commerce Purchase", CC_CALLBACK_1(HelloWorld::menuPurchaseCommerce, this));
	menu = Menu::create(purchaseCommerceItem, NULL);
	menu->setPosition(600.0f, 190.0f);
	this->addChild(menu, 1);


	auto goToCommerceV2Test = MenuItemFont::create("Goto CommerceV2 test", CC_CALLBACK_1(HelloWorld::menuGoToCommerceV2Test, this));
	goToCommerceV2Test->setColor(Color3B(0, 255, 0));
	menu = Menu::create(goToCommerceV2Test, NULL);
	menu->setPosition(goToCommerceV2Test->getContentSize().width / 2.0, goToCommerceV2Test->getContentSize().height / 2.0);
	this->addChild(menu, 1);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::startApplication();
    IgaworksPlugin::startSession();
#endif
    //IgaworksPlugin::setUserId("LIVEOPS");
    //IgaworksPlugin::setCallbackListener(this);
    //IgaworksPlugin::initializeLiveOps();
    //IgaworksPlugin::resumeLiveOps();
    //IgaworksPlugin::enableService(true);
    long size = 20000000;
    char * str = new char[20000000];
    for (int i = 0; i < size; i++) {
    	*(str++) = 'a';
    }
    //IgaworksPlugin::retention(str);
    //IgaworksPlugin::setLiveOpsPopupEventListener();
    //IgaworksPlugin::requestPopupResource();
   /* IgaworksPlugin::setBigTextClientPushEvent(1,"Show big Text","BigText Title","BigText Content", "BigText Summmary",1, true);
    IgaworksPlugin::setNormalClientPushEvent(2,"ClientPush",2, true);*/

    //IgaworksPlugin::setTargetingData("String","CocosDEMO");

    return true;
}

void HelloWorld::menuFirstTimeExperienceCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::firstTimeExperience("activity1");
#endif
}

void HelloWorld::menuRetentionCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::retention("activity2");
#endif
}

void HelloWorld::menuBuyCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::buy("purchase_1000_krw");
#endif
}

void HelloWorld::menuSetCustomCohortCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::setCustomCohort(1, "Level_1");
#endif
}

void HelloWorld::menuShowViralCPINoticeCallback(Ref* pSender)

{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}

void HelloWorld::menuCrossPromotionShowADCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}

void HelloWorld::menuShowCouponCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::showCouponDialog(true);
#endif
}

void HelloWorld::menuCheckCouponCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::checkCoupon("couponText");
#endif
}

void HelloWorld::menuGetNanooFanPageCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::openFanPage(true);
#endif
}

void HelloWorld::menuShowBannerViewCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}



void HelloWorld::menuCloseBannerViewCallback(Ref* pSender)

{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}



void HelloWorld::menuShowInterstitialAdCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}



void HelloWorld::menuShowPopupAdCallback(Ref* pSender)

{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}

void HelloWorld::menuRequestNativeAd(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}

void HelloWorld::menuSetFCMiidToLiveOps(cocos2d::Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::registerFCMToken("fcmiid");
#endif
}

void HelloWorld::menuLiveOpsPopup(cocos2d::Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	IgaworksPlugin::showPopUp("testspcae");
#endif
}

void HelloWorld::menuPurchaseCommerce(cocos2d::Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	log("not impl");
#endif
}

void HelloWorld::menuGoToCommerceV2Test(Ref* pSender)

{
	Scene *pScene = TestCommerceV2::createScene();
	Director::getInstance()->replaceScene(pScene);
	return;
}

/*
void helloworld::menucallback1(cocos2d::ref* psender){
	//igaworksplugin::initializeliveops();
}

void helloworld::menucallback2(cocos2d::ref* psender){
	//igaworksplugin::requestpopupresource();
}

void helloworld::menucallback3(cocos2d::ref* psender){
	//enable = !enable;
	//igaworksplugin::enableservicewithcallback(enable);
	//igaworksplugin::showcoupondialog(true);
}

void helloworld::menucallback4(cocos2d::ref* psender){
	//igaworksplugin::checkcoupon("igawx3ly7bymv7mv");
	//igaworksplugin::opencouponbox();

	igaworksplugin::settargetingdata("boolean", true);
		igaworksplugin::settargetingdata("long", 100l);
		igaworksplugin::settargetingdata("integer", 100);
		igaworksplugin::settargetingdata("string", "testgroup");
}


void helloworld::menucallback5(cocos2d::ref* psender){
		//igaworksplugin::initializeliveops();
		//igaworksplugin::flush();
}
*/

void HelloWorld::OnSuccessLiveOpsPopupResourceEventListener (){
	CCLOG("%s","OnSuccessLiveOpsPopupResourceEventListener");
	//IgaworksPlugin::showPopUp("garo");
}
void HelloWorld::OnSuccessLiveOpsGCMPushEnableEventListener(){
	CCLOG("%s","OnSuccessLiveOpsGCMPushEnableEventListener");
	//IgaworksPlugin::setNormalClientPushEvent(1,"OnSuccessLiveOpsGCMPushEnableEventListener",14, true);
}
void HelloWorld::OnFailLiveOpsGCMPushEnableEventListener(){
	CCLOG("%s","OnFailLiveOpsGCMPushEnableEventListener");
	//IgaworksPlugin::setNormalClientPushEvent(1,"OnFailLiveOpsGCMPushEnableEventListener",13, true);
}
void HelloWorld::OnLiveOpsCancelPopupBtnClick(){
	CCLOG("%s","OnLiveOpsCancelPopupBtnClick");
	//IgaworksPlugin::setNormalClientPushEvent(1,"OnLiveOpsCancelPopupBtnClick",12, true);
	//MessageBox("OnLiveOpsCancelPopupBtnClick","Alert");
}
void HelloWorld::OnLiveOpsPopupClick(){
	CCLOG("%s","OnLiveOpsPopupClick");
	//MessageBox("OnLiveOpsPopupClick","Alert");
	//IgaworksPlugin::destroyPopup();
	//IgaworksPlugin::destroyAllPopups();
	//IgaworksPlugin::setNormalClientPushEvent(1,"OnLiveOpsPopupClick",11, true);
}
void HelloWorld::OnSendCouponSucceed(const char* msg) {
	if(*msg){
		//IgaworksPlugin::setNormalClientPushEvent(1,deeplink_json,11, true);
		MessageBox(msg,"Alert");
	}else{
		MessageBox("Coupon: Empty msg", "Alert");
	}
}
void HelloWorld::OnSendCouponFailed(const char* msg) {
	if(*msg){
		//IgaworksPlugin::setNormalClientPushEvent(1,deeplink_json,11, true);
		MessageBox(msg,"Alert");
	}else{
		MessageBox("Coupon: Empty msg", "Alert");
	}
}

void HelloWorld::OnLiveOpsDeepLinkEventListener(const char* deeplink_json){
	if(*deeplink_json){
		//IgaworksPlugin::setNormalClientPushEvent(1,deeplink_json,11, true);
		MessageBox(deeplink_json,"Alert");
	}else{
MessageBox("Empty JSON", "Alert");
	}
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
