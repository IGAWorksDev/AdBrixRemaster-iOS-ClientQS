//
//  PluginAdPopcornDA.h
//  PluginAdPopcornDA
//
//  Created by wonje,song on 2015. 7. 15..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "InterfaceAds.h"

@interface PluginAdPopcornDA : NSObject <InterfaceAds>

- (void)initWithBannerViewSize:(NSMutableDictionary *)params;

- (void)bannerViewSetAdRefreshRate:(NSNumber *)adRefreshRate;

- (void)bannerViewSetDelegate;

- (void)closeBannerView;

- (void)interstitialAdInitWithKey:(NSMutableDictionary *)params;

- (void)interstitialAdPresentFromViewController;

- (void)interstitialAdSetDelegate;

- (void)popupAdInitWithKey:(NSMutableDictionary *)params;

- (void)popupAdPresentFromViewController;

- (void)popupAdSetDelegate;

- (void)nativeAdInitWithKey:(NSMutableDictionary *)params;

- (void)nativeAdSetDelegate;

- (void)loadNativeAd;

- (void)nativeAdCallImpression:(NSString *)impressionUrl;

- (void)nativeADClick:(NSString *)clickUrl;

- (void)oneSpotAdInitWithKey:(NSMutableDictionary *)params;

- (void)oneSpotAdPresentFromViewController;

- (void)oneSpotAdSetDelegate;
@end
