//
//  PluginIgaworksCoupon.m
//  PluginIgaworksCoupon
//
//  Created by wonje,song on 2015. 7. 15..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginIgaworksCoupon.h"

#import <IgaworksCoupon/IgaworksCoupon.h>

#import "AdsWrapper.h"

@interface PluginIgaworksCoupon () <IgaworksCouponDelegate>

@end

@implementation PluginIgaworksCoupon



- (void)showCoupon
{
    [IgaworksCoupon shared].delegate = self;
    
    [IgaworksCoupon showCoupon];
}

- (void)checkCoupon:(NSString *)code
{
    [IgaworksCoupon shared].delegate = self;
    
    [IgaworksCoupon checkCoupon:[self checkNilToBlankString:code]];
}

#pragma mark - IgaworksCouponDelegate
- (void)igaworksCouponValidationDidComplete:(BOOL)result message:(NSString *)message
{
    if (result)
    {
        [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"igaworksCouponValidationDidComplete`%@", message]];
    }
    else
    {
        [AdsWrapper onAdsResult:self withRet:kUnknownError withMsg:[NSString stringWithFormat:@"igaworksCouponValidationDidComplete`%@", message]];
    }
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

@end
