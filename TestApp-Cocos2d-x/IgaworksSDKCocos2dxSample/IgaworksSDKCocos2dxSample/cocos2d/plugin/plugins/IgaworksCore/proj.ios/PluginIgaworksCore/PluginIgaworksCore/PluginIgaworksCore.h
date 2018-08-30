//
//  PluginIgaworksCore.h
//  PluginIgaworksCore
//
//  Created by wonje,song on 2015. 7. 10..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "InterfaceAds.h"

@interface PluginIgaworksCore : NSObject <InterfaceAds>


- (void)igaworksCoreWithAppKey:(NSMutableDictionary *)params;

- (void)setLogLevel:(NSNumber *)logLevel;

- (void)setAge:(NSNumber *)age;
- (void)setGender:(NSNumber *)gender;
- (void)setUserId:(NSString *)userId;


- (void)setIgaworksCoreDelegate;

- (void)setIgaworksADClientRewardDelegate;

- (NSString *)getRewardKey;
- (void)setReferralUrl:(NSURL *)URL;


@end
