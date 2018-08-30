//
//  PluginIgaworksCore.m
//  PluginIgaworksCore
//
//  Created by wonje,song on 2015. 7. 10..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginIgaworksCore.h"

#import <IgaworksCore/IgaworksCore.h>

#import "AdsWrapper.h"

@interface PluginIgaworksCore () <IgaworksCoreDelegate, IgaworksADClientRewardDelegate>
{
    NSString *_rewardKey;
}

@end

@implementation PluginIgaworksCore

- (void)igaworksCoreWithAppKey:(NSMutableDictionary *)params
{
    [IgaworksCore igaworksCoreWithAppKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] andHashKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]andIsUseIgaworksRewardServer:[self checkNilToNo:[params objectForKey:@"Param3"]]];
}

- (void)setLogLevel:(NSNumber *)logLevel
{
    [IgaworksCore setLogLevel:[self checkNilToZero:logLevel]];
}

- (void)setAge:(NSNumber *)age
{
    [IgaworksCore setAge:[self checkNilToZero:age]];
}

- (void)setGender:(NSNumber *)gender
{
    [IgaworksCore setGender:[self checkNilToZero:gender]];
}

- (void)setUserId:(NSString *)userId
{
    [IgaworksCore setUserId:[self checkNilToBlankString:userId]];
}

- (void)setIgaworksCoreDelegate
{
    [IgaworksCore shared].delegate = self;
}

- (void)setIgaworksADClientRewardDelegate
{
    [IgaworksCore shared].clientRewardDelegate = self;
}

- (NSString *)getRewardKey
{
    return _rewardKey;
}

- (void) setReferralUrl:(NSURL *)URL
{
    [IgaworksCore setReferralUrl:URL];
}

#pragma mark - InterfaceAds
- (void)configDeveloperInfo:(NSMutableDictionary *)devInfo
{
    // no-op
}

- (void)showAds:(NSMutableDictionary *)info position:(int)pos
{
    // no-op
}

- (void)hideAds:(NSMutableDictionary *)info
{
    // no-op
}

- (void)queryPoints
{
    // no-op
}

- (void)spendPoints:(int)points
{
    // no-op
}

- (void)setDebugMode:(BOOL)debug
{
    // no-op
}


- (NSString *)getSDKVersion
{
    return @"1.0.0in";
}

- (NSString *)getPluginVersion
{
    return @"1.0";
}

#pragma mark - IgaworksCoreDelegate
- (void)didSaveConversionKey:(NSInteger)conversionKey subReferralKey:(NSString *)subReferralKey
{
    NSLog(@"didSaveConversionKey");
    
    
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"didSaveConversionKey`%lu,%@", (unsigned long)conversionKey, subReferralKey]];
}


#pragma mark - IgaworksADClientRewardDelegate
- (void)onRewardRequestResult:(BOOL)isSuccess withMessage:(NSString *)message itemName:(NSString *)itemName itemKey:(NSString *)itemKey campaignName:(NSString *)campaignName campaignKey:(NSString *)campaignKey rewardKey:(NSString *)rewardKey quantity:(NSInteger)quantity
{
    _rewardKey = rewardKey;
    
    [AdsWrapper onPlayerGetPoints:self withPoints:(int)quantity];
}

- (void)onRewardCompleteResult:(BOOL)isSuccess withMessage:(NSString *)message resultCode:(NSInteger)resultCode withCompletedRewardKey:(NSString *)completedRewardKey
{
    NSLog(@"1. onRewardCompleteResult : isSuccess : %d, message : %@, resultCode : %lu, completedRewardKey : %@", isSuccess, message, (unsigned long)resultCode, completedRewardKey);
    
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"onRewardCompleteResult`%@,%@,%ld,%@", isSuccess ? @"true" : @"false", message, (long)resultCode, completedRewardKey]];
    
    
//    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:message message:completedRewardKey delegate:self cancelButtonTitle:@"Confirm" otherButtonTitles:nil, nil];
//    [alertView show];
}


#pragma mark - private method
- (NSString *)checkNilToBlankString:(id)target
{
    NSString *returnString = @"";
    if ([NSNumber numberWithInt:0] != target)
    {
        returnString = target;
    }
    
    return returnString;
}

- (BOOL)checkNilToNo:(id)target
{
    BOOL returnBool = NO;
    if ([NSNumber numberWithInt:0] != target)
    {
        returnBool = (BOOL)[target boolValue];
    }
    
    return returnBool;
}

- (int)checkNilToZero:(id)target
{
    int returnInt = 0;
    if ([NSNumber numberWithInt:0] != target)
    {
        returnInt = [target intValue];
    }
    
    return returnInt;
}

- (id)checkNilToNil:(id)target
{
    id returnObject = nil;
    if ([NSNumber numberWithInt:0] != target)
    {
        returnObject = target;
    }
    
    return returnObject;
    
}

- (double)checkNilToDoubleZero:(id)target
{
    double returnDouble = 0.0;
    if ([NSNumber numberWithDouble:0.0] != target)
    {
        returnDouble = [target doubleValue];
    }
    
    return returnDouble;
}



@end
