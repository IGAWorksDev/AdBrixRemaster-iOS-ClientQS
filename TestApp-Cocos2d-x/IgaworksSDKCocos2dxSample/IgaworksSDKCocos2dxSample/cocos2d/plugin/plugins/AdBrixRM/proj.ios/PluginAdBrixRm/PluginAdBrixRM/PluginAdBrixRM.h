//
//  PluginAdBrixRemaster.h
//  PluginAdBrixRemaster
//
//  Created by igaworks on 2018. 8. 28..
//  Copyright © 2018년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PluginAdBrixRemaster : NSObject
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
- (void)events:(NSString *)eventName params:(NSMutableDictionary *)params;

- (void)login:(NSString *)userId;


- (void)gameLevelAchieved:(NSNumber *)level attr:(NSMutableDictionary *)attr;

- (void)gameTutorialCompleted:(BOOL)isSkip attr:(NSMutableDictionary *)attr;

- (void)gameCharacterCreated:(NSMutableDictionary *)attr;

- (void)gameStageCleared:(NSString *)stageName attr:(NSMutableDictionary *)attr;


- (void)commonPurchase:(NSString *)orderId productParam:(NSMutableDictionary *)productParam discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSNumber *)paymentMethod orderAttr:(NSMutableDictionary *)orderAttr;

- (void)commonSignUp:(NSNumber *)channel attr:(NSMutableDictionary *)attr;

- (void)commonUseCredit:(NSMutableDictionary *)attr;

- (void)commonAppUpdate:(NSString *)prev_ver curr_ver:(NSString *)curr_ver attr:(NSMutableDictionary *)attr;

- (void)commonInvite:(NSNumber *)channel attr:(NSMutableDictionary *)attr;


- (NSString *)currencyName:(NSNumber *)currency;

- (NSString *)paymentMethod:(NSNumber *)method;

- (NSString *)sharingChannel:(NSNumber *)channel;

- (NSString *)signUpChannel:(NSNumber *)channel;

- (NSString *)inviteChannel:(NSNumber *)channel;

@end
