//
//  PluginAdBrix.h
//  PluginAdBrix
//
//  Created by wonje,song on 2015. 7. 14..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "InterfaceAnalytics.h"

@interface PluginAdBrix : NSObject <InterfaceAnalytics>


/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
- (void)firstTimeExperience:(NSString *)activityName;


/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
- (void)firstTimeExperienceWithParam:(NSMutableDictionary *)params;


/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
- (void)retention:(NSString *)activityName;


/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
- (void)retentionWithParam:(NSMutableDictionary *)params;

/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
- (void)buy:(NSString *)activityName;


/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
- (void)buyWithParam:(NSMutableDictionary *)params;


/*!
 @abstract
 친구 초대 이벤트를 노출한다.
 */
- (void)showViralCPINotice;

/*!
 @abstract
 cohort 분석시 호출한다.
 
 @param customCohortType          cohort type : AdBrixCustomCohortType
 @param filterName                filter Name
 */
- (void)setCustomCohort:(NSMutableDictionary *)params;

/*!
 @abstract
 cross promotion 이벤트를 노출한다.
 
 @param activityName              activity name.
 */
- (void)crossPromotionShowAD:(NSString *)activityName;

- (NSString *)currencyName:(NSString *)currency;
- (void)commercePurchaseI:(NSMutableDictionary *)params;
- (void)commercePurchaseII:(NSMutableDictionary *)params;
- (void)commercePurchaseIII:(NSMutableDictionary *)params;

@end
