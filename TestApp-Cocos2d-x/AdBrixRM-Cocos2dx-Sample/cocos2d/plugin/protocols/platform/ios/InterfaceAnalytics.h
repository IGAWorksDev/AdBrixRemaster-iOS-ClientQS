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

#import <Foundation/Foundation.h>

@protocol InterfaceAnalytics <NSObject>

- (void)setAppleAdvertisingIdentifier:(NSString *)appleAdvertisingIdentifier;

- (void)setEventUploadCountInterval:(NSNumber *)countInterval;
- (void)setEventUploadTimeInterval:(NSNumber *)timeInterval;

- (void)deepLinkOpenWithUrl:(NSString *)urlStr;

- (void)initAdBrix:(NSString *)appKey secretKey:(NSString *)secretKey;

- (void)setLogLevel:(NSNumber *)logLevel;
- (void)setAge:(NSNumber *)age;
- (void)setGender:(NSNumber *)gender;
- (void)setUserProperties:(NSMutableDictionary *)params;

- (void)gdprForgetMe;

- (void)events:(NSString *)eventName;
- (void)eventsWithParam:(NSMutableDictionary *)params;

- (void)login:(NSString *)userId;

- (void)commonPurchaseSingle:(NSMutableDictionary *)params;
- (void)commonPurchaseBulk:(NSMutableDictionary *)params;

- (void)gameLevelAchieved:(NSMutableDictionary *)params;
- (void)gameTutorialCompleted:(NSMutableDictionary *)params;
- (void)gameCharacterCreated:(NSMutableDictionary *)params;
- (void)gameStageCleared:(NSMutableDictionary *)params;


- (void)commonSignUp:(NSMutableDictionary *)params;
- (void)commonUseCredit:(NSMutableDictionary *)attr;
- (void)commonAppUpdate:(NSMutableDictionary *)params;
- (void)commonInvite:(NSMutableDictionary *)params;

@end
