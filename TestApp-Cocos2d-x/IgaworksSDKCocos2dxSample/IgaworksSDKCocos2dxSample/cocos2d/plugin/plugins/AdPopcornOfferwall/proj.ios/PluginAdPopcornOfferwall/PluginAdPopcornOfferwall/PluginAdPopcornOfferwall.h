//
//  PluginAdPopcornOfferwall.h
//  PluginAdPopcornOfferwall
//
//  Created by wonje,song on 2015. 7. 13..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "InterfaceAds.h"

@interface PluginAdPopcornOfferwall : NSObject <InterfaceAds>


/*!
 @abstract
 Open offerwall.
 
 @discussion
 리스트 형태의 광고를 노출한다.
 
 @param vController          광고 리스트를 노출시킬 view controller
 @param delegate             AdPopcornDelegate
 @param userDataDictionaryForFilter    filtering(targeting)을 위한 user data
 */
- (void)openOfferWallWithViewController:(NSMutableDictionary *)params;

- (void)openPromotionEvent:(NSNumber *)isSetDelegate;

- (void)loadVideoAd:(NSNumber *)isSetDelegate;

- (void)showVideoAdWithViewController:(NSNumber *)isSetDelegate;

/*!
 @abstract
 IGAWorks에 리워드 지급 확정 처리를 요청한다.
 
 @discussion
 이곳에서 사용자에게 리워드 지급 처리를 한다. 지급 처리가 완료 되었다면, 해당 메소드를 호출하여 IGAWorks에 리워드 지급 확정 처리를 요청한다.
 
 @param rewardKey            리워드 식별키
 */
- (void)didGiveRewardItemWithRewardKey:(NSString *)rewardKey;

/*!
 @abstract
 IGAWorks에 리워드 지급이 필요한 정보가 있는지 확인 요청을 한다.
 
 @discussion
 일반적으로 자동으로 pending된 리워드 정보가 업데이트 되지만, 사용자가 직접 pending된 리워드가 있는지 수동으로 확인하기 위한 요청 API.
 
 */
- (void)getClientPendingRewardItems;

@end
