//
//  PluginAdPopcornDA.m
//  PluginAdPopcornDA
//
//  Created by wonje,song on 2015. 7. 15..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginAdPopcornDA.h"

#import <AdPopcornDA/DABannerView.h>
#import <AdPopcornDA/DAInterstitialAd.h>
#import <AdPopcornDA/DAPopupAd.h>
#import <AdPopcornDA/DANativeAd.h>
#import <AdPopcornDA/DAOneSpotAd.h>

#import "AdsWrapper.h"

@interface PluginAdPopcornDA () <DABannerViewDelegate, DAInterstitialAdDelegate, DAPopupAdDelegate, DANativeAdDelegate, DAOneSpotAdDelegate>
{
    DABannerView *_bannerView;
    DAInterstitialAd *_interstitialAd;
    DAPopupAd *_popupAd;
    DANativeAd *_nativeAd;
    DAOneSpotAd *_oneSpotAd;
}

@end

@implementation PluginAdPopcornDA

- (void)initWithBannerViewSize:(NSMutableDictionary *)params
{
    
   _bannerView = [[DABannerView alloc] initWithBannerViewSize:[self checkNilToZero:[params objectForKey:@"Param1"]] origin:CGPointMake(0.0f, 0.0f) appKey:[self checkNilToBlankString:[params objectForKey:@"Param3"]] spotKey:[self checkNilToBlankString:[params objectForKey:@"Param4"]] viewController:[AdsWrapper getCurrentRootViewController]];
    
    [AdsWrapper addAdView:_bannerView atPos:[self checkNilToZero:[params objectForKey:@"Param2"]]];
}

- (void)bannerViewSetAdRefreshRate:(NSNumber *)adRefreshRate
{
    _bannerView.adRefreshRate = [self checkNilToZero:adRefreshRate];
}

- (void)bannerViewSetDelegate
{
    _bannerView.delegate = self;
}

- (void)closeBannerView
{
    [_bannerView removeFromSuperview];
    [_bannerView stopAd];
}

- (void)interstitialAdInitWithKey:(NSMutableDictionary *)params
{
    _interstitialAd = [[DAInterstitialAd alloc] initWithKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] spotKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]] viewController:[AdsWrapper getCurrentRootViewController]];
}

- (void)interstitialAdPresentFromViewController
{
    [_interstitialAd presentFromViewController:[AdsWrapper getCurrentRootViewController]];
}

- (void)interstitialAdSetDelegate
{
    _interstitialAd.delegate = self;
}

- (void)popupAdInitWithKey:(NSMutableDictionary *)params
{
    _popupAd = [[DAPopupAd alloc] initWithKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] spotKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)popupAdPresentFromViewController
{
    [_popupAd presentFromViewController:[AdsWrapper getCurrentRootViewController]];
}

- (void)popupAdSetDelegate
{
    _popupAd.delegate = self;
}

- (void)nativeAdInitWithKey:(NSMutableDictionary *)params
{
    _nativeAd = [[DANativeAd alloc] initWithKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] spotKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
    
}

- (void)nativeAdSetDelegate
{
    _nativeAd.delegate = self;
}

- (void)loadNativeAd
{
    [_nativeAd loadAd];
}

- (void)nativeAdCallImpression:(NSString *)impressionUrl
{
    [_nativeAd callImpression:[self checkNilToBlankString:impressionUrl]];
}

- (void)nativeADClick:(NSString *)clickUrl
{
    [_nativeAd click:[self checkNilToBlankString:clickUrl]];
}

- (void)oneSpotAdInitWithKey:(NSMutableDictionary *)params
{
    _oneSpotAd = [[DAOneSpotAd alloc] initWithKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] spotKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)oneSpotAdPresentFromViewController
{
    [_oneSpotAd presentFromViewController:[AdsWrapper getCurrentRootViewController]];
}

- (void)oneSpotAdSetDelegate
{
    _oneSpotAd.delegate = self;
}

#pragma mark - DABannerViewDelegate
- (void)DABannerViewDidLoadAd:(DABannerView *)bannerView
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DABannerViewDidLoadAd"];
}

- (void)DABannerView:(DABannerView *)bannerView didFailToReceiveAdWithError:(DAError *)error
{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case DAServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"DABannerViewDidFailToReceiveAdWithError`%@", [error localizedDescription]]];
}

- (void)DABannerViewWillLeaveApplication:(DABannerView *)bannerView
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DABannerViewWillLeaveApplication"];
}

#pragma mark - DAInterstitialAdDelegate
- (void)DAInterstitialAdDidLoad:(DAInterstitialAd *)interstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAInterstitialAdDidLoad"];
}

- (void)DAInterstitialAd:(DAInterstitialAd *)interstitialAd didFailToReceiveAdWithError:(DAError *)error
{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case DAServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"DAInterstitialAdDidFailToReceiveAdWithError`%@", [error localizedDescription]]];
}

- (void)DAInterstitialAdWillLeaveApplication:(DAInterstitialAd *)interstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAInterstitialAdWillLeaveApplication"];
}

- (void)willOpenDAInterstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenDAInterstitialAd"];
}

- (void)didOpenDAInterstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenDAInterstitialAd"];
}


- (void)willCloseDAInterstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseDAInterstitialAd"];
}


- (void)didCloseDAInterstitialAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseDAInterstitialAd"];
}

#pragma mark - DAPopupAdDelegate
- (void)DAPopupAdDidLoad:(DAPopupAd *)popupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAPopupAdDidLoad"];
}

- (void)DAPopupAd:(DAPopupAd *)popupAd didFailToReceiveAdWithError:(DAError *)error
{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case DAServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"DAPopupAdDidFailToReceiveAdWithError`%@", [error localizedDescription]]];
}

- (void)DAPopupAdWillLeaveApplication:(DAPopupAd *)popupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAPopupAdWillLeaveApplication"];
}

- (void)willOpenDAPopupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenDAPopupAd"];
}

- (void)didOpenDAPopupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenDAPopupAd"];
}

- (void)willCloseDAPopupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseDAPopupAd"];
}

- (void)didCloseDAPopupAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseDAPopupAd"];
}


#pragma mark - DANativeAdDelegate
- (void)DANativeAdDidFinishLoading:(DANativeAd *)nativeAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"DANativeAdDidFinishLoading`%@", [nativeAd.nativeAdvertisingResultJson description]]];
}

- (void)DANativeAd:(DANativeAd *)nativeAd didFailWithError:(DAError *)error
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:[NSString stringWithFormat:@"DANativeAdDidFailWithError`%@", [error localizedDescription]]];
}

#pragma mark - DAOneSpotAdDelegate
- (void)DAOneSpotAdDidLoad:(DAOneSpotAd *)onespotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAOneSpotAdDidLoad"];
}

- (void)DAOneSpotAd:(DAOneSpotAd *)onespotAd didFailToReceiveAdWithError:(DAError *)error
{
    int errorNo = kUnknownError;
    switch ([error code]) {
        case DAServerTimeout:
            errorNo = kNetworkError;
            break;
        default:
            break;
    }
    
    [AdsWrapper onAdsResult:self withRet:errorNo withMsg:[NSString stringWithFormat:@"DAOneSpotAdDidFailToReceiveAdWithError`%@", [error localizedDescription]]];
}

- (void)DAOneSpotAdWillLeaveApplication:(DAOneSpotAd *)onespotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"DAOneSpotAdWillLeaveApplication"];
}

- (void)willOpenDAOneSpotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willOpenDAOneSpotAd"];
}

- (void)didOpenDAOneSpotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didOpenDAOneSpotAd"];
}

- (void)willCloseDAOneSpotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"willCloseDAOneSpotAd"];
}

- (void)didCloseDAOneSpotAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCloseDAOneSpotAd"];
}

- (void)didCompleteDAOneSpotVideoAd
{
    [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"didCompleteDAOneSpotVideoAd"];
}

#pragma mark - InterfaceAds
- (void)configDeveloperInfo:(NSMutableDictionary *)devInfo
{

}

- (void)showAds:(NSMutableDictionary *)info position:(int)pos
{

}

- (void)hideAds:(NSMutableDictionary *)info
{
    
}

 -(void)queryPoints
{

}

- (void)spendPoints:(int)points
{

}

- (void)setDebugMode:(BOOL)debug
{

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

- (int)checkNilToZero:(id)target
{
    int returnInt = 0;
    if ([NSNumber numberWithInt:0] != target)
    {
        returnInt = [target intValue];
    }
    
    return returnInt;
}

@end
