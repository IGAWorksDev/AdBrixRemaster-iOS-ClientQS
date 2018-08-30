//
//  PluginAdPopcornOfferwall.m
//  PluginAdPopcornOfferwall
//
//  Created by wonje,song on 2015. 7. 13..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginAdPopcornOfferwall.h"

#import <AdPopcornOfferwall/AdPopcornOfferwall.h>

#import "AdsWrapper.h"

@interface PluginAdPopcornOfferwall () <AdPopcornOfferwallDelegate>

@end

@implementation PluginAdPopcornOfferwall


- (void)openOfferWallWithViewController:(NSMutableDictionary *)params
{
    NSMutableDictionary *userDataDictionaryForFilter = [self checkNilToNil:[params objectForKey:@"Param2"]];
    
    NSLog(@"userDataDictionaryForFilter : %@, Param1 : %@", userDataDictionaryForFilter, [params objectForKey:@"Param1"]);
    
    
    if ([self checkNilToZero:[params objectForKey:@"Param1"]])
    {
        [AdPopcornOfferwall openOfferWallWithViewController:[AdsWrapper getCurrentRootViewController] delegate:self userDataDictionaryForFilter:userDataDictionaryForFilter];
    }
    else
    {
        [AdPopcornOfferwall openOfferWallWithViewController:[AdsWrapper getCurrentRootViewController] delegate:nil userDataDictionaryForFilter:userDataDictionaryForFilter];
    }
}

- (void)openPromotionEvent:(NSNumber *)isSetDelegate
{
    if ([self checkNilToNo:isSetDelegate])
    {
        [AdPopcornOfferwall openPromotionEvent:[AdsWrapper getCurrentRootViewController] delegate:self];
    }
    else
    {
        [AdPopcornOfferwall openPromotionEvent:[AdsWrapper getCurrentRootViewController] delegate:nil];
    }
}

- (void)loadVideoAd:(NSNumber *)isSetDelegate
{
    if ([self checkNilToNo:isSetDelegate])
    {
        [AdPopcornOfferwall loadVideoAd:self];
    }
    else
    {
        [AdPopcornOfferwall loadVideoAd:nil];
    }
}

- (void)showVideoAdWithViewController:(NSNumber *)isSetDelegate
{
    if ([self checkNilToNo:isSetDelegate])
    {
        [AdPopcornOfferwall showVideoAdWithViewController:[AdsWrapper getCurrentRootViewController] delegate:self];
    }
    else
    {
        [AdPopcornOfferwall showVideoAdWithViewController:[AdsWrapper getCurrentRootViewController] delegate:nil];
    }
    
}

- (void)didGiveRewardItemWithRewardKey:(NSString *)rewardKey
{
 
    [AdPopcornOfferwall didGiveRewardItemWithRewardKey:rewardKey];
}

- (void)getClientPendingRewardItems
{
    [AdPopcornOfferwall getClientPendingRewardItems];
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
#pragma mark - AdPopcornOfferwallDelegate
- (void)willOpenOfferWall
{
    NSLog(@"- (void)willOpenOfferWall");
    
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenOfferWall"];
}

- (void)didOpenOfferWall
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenOfferWall"];
}

- (void)willCloseOfferWall
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseOfferWall"];
}

- (void)didCloseOfferWall
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseOfferWall"];
}

- (void)willOpenPromotionEvent
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenPromotionEvent"];
}

- (void)didOpenPromotionEvent
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenPromotionEvent"];
}

- (void)willClosePromotionEvent
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willClosePromotionEvent"];
}

- (void)didClosePromotionEvent
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didClosePromotionEvent"];
}

- (void)loadVideoAdSuccess{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"loadVideoAdSuccess"];
}

- (void)loadVideoAdFailedWithError:(APError *)error
{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case APServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"loadVideoAdFailedWithError`%@", [error localizedDescription]]];
}

- (void)showVideoAdFailedWithError:(APError *)error{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case APServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"showVideoAdFailedWithError`%@", [error localizedDescription]]];
}

- (void)willOpenVideoAd{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenVideoAd"];
}

- (void)didOpenVideoAd{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenVideoAd"];
}

- (void)willCloseVideoAd{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseVideoAd"];
}

- (void)didCloseVideoAd{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseVideoAd"];
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
