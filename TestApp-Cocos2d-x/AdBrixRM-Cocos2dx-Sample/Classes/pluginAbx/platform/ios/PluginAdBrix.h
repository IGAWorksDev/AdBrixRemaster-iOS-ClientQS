//
//  PluginAdBrix.h
//  PluginAdBrix
//
//  Created by wonje,song on 2015. 7. 14..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "InterfaceAnalytics.h"

//#import <AdBrixRM/AdBrixRM.h>
#import <AdBrixRM/AdBrixRM-Swift.h>

@interface PluginAdBrix : NSObject <InterfaceAnalytics>
//<InterfaceAnalytics>


- (void)setAppleAdvertisingIdentifier:(NSString *)appleAdvertisingIdentifier;

- (void)setEventUploadCountInterval:(NSNumber *)countInterval;
- (void)setEventUploadTimeInterval:(NSNumber *)timeInterval;

- (void)deepLinkOpenWithUrl:(NSString *)urlStr;

- (void)initAdBrix:(NSMutableDictionary *)params;
- (void)initAdBrix:(NSString *)appKey secretKey:(NSString *)secretKey;

- (void)setLogLevel:(NSNumber *)logLevel;

- (void)setAge:(NSNumber *)age;

- (void)setGender:(NSNumber *)gender;

- (void)setUserProperties:(NSMutableDictionary *)params;

- (void)gdprForgetMe;

- (void)events:(NSString *)eventName;
- (void)eventsWithParam:(NSMutableDictionary *)params;

- (void)login:(NSString *)userId;



- (void)gameLevelAchieved:(NSMutableDictionary *)params;

- (void)gameTutorialCompleted:(NSMutableDictionary *)params;

- (void)gameCharacterCreated:(NSMutableDictionary *)params;

- (void)gameStageCleared:(NSMutableDictionary *)params;


- (void)commonPurchaseSingle:(NSMutableDictionary *)params;
- (void)commonPurchaseBulk:(NSMutableDictionary *)params;

- (void)commonSignUp:(NSMutableDictionary *)params;

- (void)commonUseCredit:(NSMutableDictionary *)attr;

- (void)commonAppUpdate:(NSMutableDictionary *)params;

- (void)commonInvite:(NSMutableDictionary *)params;


- (NSString *)currencyName:(NSNumber *)currency;

- (NSString *)paymentMethod:(NSNumber *)method;

- (NSString *)sharingChannel:(NSNumber *)channel;

- (NSString *)signUpChannel:(NSNumber *)channel;

- (NSString *)inviteChannel:(NSNumber *)channel;




@end
