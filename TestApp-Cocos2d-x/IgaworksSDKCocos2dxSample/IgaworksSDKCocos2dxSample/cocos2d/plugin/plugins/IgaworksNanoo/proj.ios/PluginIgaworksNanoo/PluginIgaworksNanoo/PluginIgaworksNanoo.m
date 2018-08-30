//
//  PluginIgaworksNanoo.m
//  PluginIgaworksNanoo
//
//  Created by wonje,song on 2015. 7. 15..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginIgaworksNanoo.h"

#import <IgaworksNanoo/IgaworksNanoo.h>

#import "AdsWrapper.h"

@interface PluginIgaworksNanoo() <IgaworksNanooDelegate>

@end

@implementation PluginIgaworksNanoo

- (void)getNanooFanPage
{
    [IgaworksNanoo shared].delegate = self;
    [IgaworksNanoo getNanooFanPage:[AdsWrapper getCurrentRootViewController]];
}


#pragma mark - IgaworksNanooDelegate
- (void)getNanooFanPageDidComplete:(NSString *)nanooFanPageurl
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"getNanooFanPageDidComplete`%@", nanooFanPageurl]];
}

- (void)getNanooFanPageFailedWithError:(NSError *)error
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"getNanooFanPageFailedWithError`%@", error.localizedDescription]];
}

- (void)willOpenNanooFanPage
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenNanooFanPage"];
}

- (void)didOpenNanooFanPage
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenNanooFanPage"];
}

- (void)willCloseNanooFanPage
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseNanooFanPage"];
}

- (void)didCloseNanooFanPage
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseNanooFanPage"];
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
