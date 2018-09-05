/****************************************************************************
 Copyright (c) 2012+2013 cocos2d+x.org
 
 http://www.cocos2d+x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "ProtocolAnalytics.h"
//#import  "InterfaceAnalytics.h"
#include "PluginUtilsIOS.h"

namespace cocos2d { namespace plugin {

ProtocolAnalytics::ProtocolAnalytics()
{
}

ProtocolAnalytics::~ProtocolAnalytics()
{
    PluginUtilsIOS::erasePluginOCData(this);
}

    
void ProtocolAnalytics::setAppleAdvertisingIdentifier(const char* appleAdvertisingIdentifier){
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setAppleAdvertisingIdentifier");
}

void ProtocolAnalytics::setEventUploadCountInterval(int countInterval) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setEventUploadCountInterval");
}
void ProtocolAnalytics::setEventUploadTimeInterval(int timeInterval){
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setEventUploadTimeInterval");
    
}

void ProtocolAnalytics::deepLinkOpenWithUrl(const char* urlStr){
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:deepLinkOpenWithUrl");
    
}

void ProtocolAnalytics::initAdBrix(const char* appKey, const char* secretKey){
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:initAdBrix");
    
}

void ProtocolAnalytics::setLogLevel(int logLevel) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM :setLogLevel");
    
}
void ProtocolAnalytics::setAge(int age) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setAge");
    
}
void ProtocolAnalytics::setGender(int gender) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setGender");
    
}

void ProtocolAnalytics::setUserProperties(paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:setUserProperties");
    
}

void ProtocolAnalytics::gdprForgetMe() {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:gdprForgetMe");
    
}

void ProtocolAnalytics::events(const char* eventName) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:events");
    
}
void ProtocolAnalytics::events(const char* eventName, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:events");
    
}

void ProtocolAnalytics::login(const char* userId) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:login");
    
}


void ProtocolAnalytics::gameLevelAchieved(int level, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:gameLevelAchieved");
    
}

void ProtocolAnalytics::gameTutorialCompleted(bool isSkip, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:gameTutorialCompleted");
    
}
void ProtocolAnalytics::gameCharacterCreated(paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:gameCharacterCreated");
}
void ProtocolAnalytics::gameStageCleared(const char* stageName, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:gameStageCleared");
    
}

void ProtocolAnalytics::commonPurchaseSingle(paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:commonPurchase");
    
}
    
void ProtocolAnalytics::commonPurchaseBulk(paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:commonPurchase");
    
}
    
void ProtocolAnalytics::commonSignUp(int channel, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:commonSignUp");
    
}
void ProtocolAnalytics::commonUseCredit(paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:commonUseCredit");
}
void ProtocolAnalytics::commonAppUpdate(const char* prev_ver, const char*  curr_ver, paramMap* params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics:commonAppUpdate");
}
void ProtocolAnalytics::commonInvite(int channel,  paramMap params) {
    PluginOCData* pData = PluginUtilsIOS::getPluginOCData(this);
    assert(pData != NULL);
    NSLog(@"AdBrixRM ProtocolAnalytics: commonInvite");
}


}} //namespace cocos2d { namespace plugin {
