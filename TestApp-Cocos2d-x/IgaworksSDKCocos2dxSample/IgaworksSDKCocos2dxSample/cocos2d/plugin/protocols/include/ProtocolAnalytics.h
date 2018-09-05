/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org

http://www.cocos2d-x.org

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
#ifndef __CCX_PROTOCOL_ANALYTICS_H__
#define __CCX_PROTOCOL_ANALYTICS_H__

#include "PluginProtocol.h"
#include <map>
#include <string>

namespace cocos2d { namespace plugin {

typedef std::pair< std::string, std::string >   paramPair;
typedef std::map< std::string, std::string >    paramMap;

class ProtocolAnalytics : public PluginProtocol
{
public:
	ProtocolAnalytics();
	virtual ~ProtocolAnalytics();

    void setAppleAdvertisingIdentifier(const char* appleAdvertisingIdentifier);
    
    void setEventUploadCountInterval(int countInterval);
    void setEventUploadTimeInterval(int timeInterval);
    
    void deepLinkOpenWithUrl(const char* urlStr);
    
    void initAdBrix(const char* appKey, const char* secretKey);
    
    void setLogLevel(int logLevel);
    void setAge(int age);
    void setGender(int gender);
    
    void setUserProperties(paramMap* params);
    
    void gdprForgetMe();
    
    void events(const char* eventName);
    void events(const char* eventName, paramMap* params);
    
    void login(const char* userId);
    
    
    void gameLevelAchieved(int level, paramMap* params);
    
    void gameTutorialCompleted(bool isSkip, paramMap* params);
    void gameCharacterCreated(paramMap* params);
    void gameStageCleared(const char* stageName, paramMap* params);
    
    
    void commonPurchaseSingle(paramMap* params);
    void commonPurchaseBulk(paramMap* params);
    
    void commonSignUp(int channel, paramMap* params);
    void commonUseCredit(paramMap* params);
    void commonAppUpdate(const char* prev_ver, const char*  curr_ver, paramMap* params);
    void commonInvite(int channel,  paramMap params);
    
};

}} // namespace cocos2d { namespace plugin {


#endif /* __CCX_PROTOCOL_ANALYTICS_H__ */
