
//
//  PluginLiveOps.h
//  PluginLiveOps
//
//  Created by 강기태 on 2015. 8. 10..
//  Copyright (c) 2015년 igaworks. All rights reserved.
//
#import "PluginLiveOps.h"
#import <LiveOps/LiveOps.h>

@implementation PluginLiveOps

- (void)initPush
{
    [LiveOpsPush initPush];
    
    [LiveOpsPopup setPopupLinkListener:^(NSString *popupSpaceKey, NSDictionary *customData) {
        
        NSString* customDataStr = @"{}";
        
        if (customData) {
            NSError* error;
            NSData* jsonData = [NSJSONSerialization dataWithJSONObject:customData options:0 error:&error];
            if (jsonData) {
                customDataStr = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            }
        }
        
        NSString* msg = [NSString stringWithFormat:@"setPopupLinkListener'%@,%@", popupSpaceKey, customDataStr];
        [AdsWrapper onAdsResult:self withRet:kAdsShown withMsg:msg];
    }];

    [LiveOpsPopup setPopupCloseListener:^(NSString *popupSpaceKey, NSString *popupCampaignName, NSDictionary *customData, NSUInteger remainPopupNum) {
        
        NSString* customDataStr = @"{}";
        
        if (customData) {
            NSError* error;
            NSData* jsonData = [NSJSONSerialization dataWithJSONObject:customData options:0 error:&error];
            if (jsonData) {
                customDataStr = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            }
        }
        
        NSString* msg = [NSString stringWithFormat:@"setPopupCloseListener'%@,%@,%@,%lu", popupSpaceKey, popupCampaignName, customDataStr, remainPopupNum];
        [AdsWrapper onAdsResult:self withRet:kAdsShown withMsg:msg];
    }];
}

- (void)setRemotePushEnable:(BOOL)isEnabled
{
    [LiveOpsPush setRemotePushEnable:isEnabled];
}

- (void)registerLocalPushNotification:(NSInteger)Id date:(NSDate*)date body:(NSString*)bodyText button:(NSString*)buttonText soundName:(NSString*)sound badgeNumber:(NSInteger)badgeNum customPayload:(NSDictionary*)payloadDict
{
    [LiveOpsPush registerLocalPushNotification:Id date:date body:bodyText button:buttonText soundName:sound badgeNumber:badgeNum customPayload:payloadDict];
}

- (void)cancelLocalPush:(NSInteger)Id
{
    [LiveOpsPush cancelLocalPush:Id];
}

- (void)setTargetingData:(id)obj withKey:(NSString*)key
{
    [LiveOpsUser setTargetingData:obj withKey:key];
}

- (void)flush
{
    [LiveOpsUser flush];
}

- (void)getPopups
{
    [LiveOpsPopup getPopups:^{
        [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"getPopups"];
    }];
}

- (void)showPopups:(NSString*)popupSpaceKey
{
    [LiveOpsPopup showPopups:popupSpaceKey];
}

- (void)showPopups:(NSString*)popupSpaceKey withViewController:(UIViewController*)viewCtrler
{
    [LiveOpsPopup showPopups:popupSpaceKey withViewController:viewCtrler];
}

- (void)destroyPopup
{
    [LiveOpsPopup destroyPopup];
}

- (void)destroyAllPopups
{
    [LiveOpsPopup destroyAllPopups];
}

//- (void)setPopupLinkListener:(LiveOpsPopupLinkCallback)block
//{
//    [LiveOpsPopup setPopupLinkListener:block];
//}
//
//- (void)setPopupCloseListener:(LiveOpsPopupCloseCallback)block
//{
//    [LiveOpsPopup setPopupCloseListener:block];
//}



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
    return @"1.0.1in";
}

- (NSString *)getPluginVersion
{
    return @"1.0";
}



@end

