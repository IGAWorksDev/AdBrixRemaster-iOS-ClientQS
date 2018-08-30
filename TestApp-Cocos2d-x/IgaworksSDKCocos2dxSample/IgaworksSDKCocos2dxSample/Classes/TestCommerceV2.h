//
//  TestCommerceV2.hpp
//  IgaworksSDKCocos2dxSample
//
//  Created by igaworks on 2017. 2. 15..
//
//

#ifndef TestCommerceV2_h
#define TestCommerceV2_h

#include "cocos2d.h"

#include "PluginManager.h"
#include "ProtocolAds.h"
#include "ProtocolAnalytics.h"
#include "ProtocolIAP.h"

class TestCommerceV2 : public cocos2d::Layer
{
public:
    
    cocos2d::plugin::ProtocolAnalytics* _pluginAdBrix;
    cocos2d::plugin::ProtocolIAP* _pluginIgaworksCommerce;
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void menuGoToMain(Ref* pSender);
    
    void apiPurchaseI(cocos2d::Ref* pSender);
    void apiPurchaseII(Ref* pSender);
    void apiPurchaseIII(Ref* pSender);
    
    void loadAdBrixPlugin();
    
    void loadIgaworksCommercePlugin();
    void unloadIgaworksCommercePlungin();
    
    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TestCommerceV2);
};

#endif /* TestCommerceV2_h */
