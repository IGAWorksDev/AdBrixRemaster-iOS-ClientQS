//
//  PluginAdBrix.m
//  PluginAdBrix
//
//  Created by wonje,song on 2015. 7. 14..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginAdBrix.h"

#import <AdBrix/AdBrix.h>
#import <AdBrix/CrossPromotion.h>

#import "AdsWrapper.h"

@implementation PluginAdBrix


- (void)firstTimeExperience:(NSString *)activityName
{
    NSLog(@"- (void)firstTimeExperience:(NSString *)activityName : %@", activityName);
    
    [AdBrix firstTimeExperience:activityName];
}

- (void)firstTimeExperienceWithParam:(NSMutableDictionary *)params
{
    [AdBrix firstTimeExperience:[self checkNilToBlankString:[params objectForKey:@"Param1"]] param:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
    
}

- (void)retention:(NSString *)activityName
{
    [AdBrix retention:activityName];
}

- (void)retentionWithParam:(NSMutableDictionary *)params
{
    [AdBrix retention:[self checkNilToBlankString:[params objectForKey:@"Param1"]] param:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)buy:(NSString *)activityName
{
    [AdBrix buy:activityName];
}

- (void)buyWithParam:(NSMutableDictionary *)params
{
    [AdBrix buy:[self checkNilToBlankString:[params objectForKey:@"Param1"]] param:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)showViralCPINotice
{
    [AdBrix showViralCPINotice:[AdsWrapper getCurrentRootViewController]];
}

- (void)setCustomCohort:(NSMutableDictionary *)params
{
    [AdBrix setCustomCohort:[self checkNilToZero:[params objectForKey:@"Param1"]] filterName:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)crossPromotionShowAD:(NSString *)activityName
{
    [CrossPromotion showAD:[self checkNilToBlankString:activityName] parentViewController:[AdsWrapper getCurrentRootViewController]];
}

#pragma mark - CommerceV2

- (NSString *)currencyName:(NSNumber *)currency
{
    return [AdBrix currencyName:[currency integerValue]];
}

- (NSString *)paymentMethod:(NSNumber *)method
{
    return [AdBrix paymentMethod:[method integerValue]];
}

- (NSString *)sharingChannel:(NSNumber *)channel
{
    return [AdBrix sharingChannel:[channel integerValue]];
}

- (void)commercePurchaseI:(NSMutableDictionary *)params;
{
    @try
    {
        [AdBrix commercePurchase: [self checkNilToBlankString : [params objectForKey:@"Param1"]]
                           price: [self checkNilToDoubleZero : [params objectForKey:@"Param2"]]
                        currency: [self checkNilToBlankString : [params objectForKey:@"Param3"]]
                   paymentMethod: [self checkNilToBlankString : [params objectForKey:@"Param4"]]];
    }
    @catch (NSException *exception)
    {
        NSLog(@"- (void)commercePurchaseI:(NSMutableDictionary *)params : error, : %@", exception);
    }
}

- (void)commercePurchaseII:(NSMutableDictionary *)params;
{
    @try
    {
        if(params == nil)
        {
            NSLog(@"- (void)commercePurchaseII:(NSMutableDictionary *)params : missing params, params is : %@", params);
            return;
        }
        
        NSData *data = [[params objectForKey:@"Param2"] dataUsingEncoding:NSUTF8StringEncoding];
        
        id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        
        AdBrixCommerceProductCategoryModel *cat = nil;
        
        if ([json objectForKey:@"category"])
        {
            NSArray* categoryList = [[json objectForKey:@"category"] componentsSeparatedByString:@"."];
            if(categoryList.count == 1)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0]];
            if(categoryList.count == 2)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1]];
            if(categoryList.count == 3)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2]];
            if(categoryList.count == 4)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3]];
            if(categoryList.count == 5)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3] category5:categoryList[4]];
        }
        
        ;
        
        AdBrixCommerceProductAttrModel *attrs;
        if ([json objectForKey:@"extra_attrs"])
        {
            NSDictionary* attrsDic = [json objectForKey:@"extra_attrs"];
            attrs = [AdBrixCommerceProductAttrModel create:attrsDic];
        }
        
        [AdBrix commercePurchase:[params objectForKey:@"Param1"]
                         product:[AdBrix createCommerceProductModel:[json objectForKey:@"productId"]
                                                        productName:[json objectForKey:@"productName"]
                                                              price:[self checkNilToDoubleZero :[json objectForKey:@"price"]]
                                                           discount:[self checkNilToDoubleZero:[json objectForKey:@"discount"]]
                                                           quantity:[self checkNilToZero:[json objectForKey:@"quantity"]]
                                                     currencyString:[json objectForKey:@"productId"]
                                                           category:cat extraAttrsMap:attrs]
                        discount:[[params objectForKey:@"Param3"] doubleValue]
                  deliveryCharge:[[params objectForKey:@"Param4"] doubleValue]
                   paymentMethod:[AdBrix paymentMethod:[[params objectForKey:@"Param5"] integerValue]]];
    }
    @catch (NSException *exception)
    {
        NSLog(@"- (void)commercePurchase:(NSMutableDictionary *)params : error, : %@", exception);
    }

}

- (void)commercePurchaseIII:(NSMutableDictionary *)params;
{
    @try
    {
        NSLog(@"- (void)commercePurchaseIII:(NSMutableDictionary *)params : missing params, params is : %@", params);
        if(params == nil)
        {
            NSLog(@"- (void)commercePurchaseIII:(NSMutableDictionary *)params : missing params, params is : %@", params);
            return;
        }
        NSMutableArray *pArr = [NSMutableArray array];
        
        NSMutableDictionary *pMap = [params objectForKey:@"Param2"];;
        
        
        for (NSString *pKey in pMap)
        {
            NSData *data = [[pMap valueForKey:pKey] dataUsingEncoding:NSUTF8StringEncoding];
            id jsonOb = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
            AdBrixCommerceProductCategoryModel *cat = nil;
            
            if ([jsonOb objectForKey:@"category"])
            {
                NSArray* categoryList = [[jsonOb objectForKey:@"category"] componentsSeparatedByString:@"."];
                if(categoryList.count == 1)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0]];
                if(categoryList.count == 2)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1]];
                if(categoryList.count == 3)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2]];
                if(categoryList.count == 4)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3]];
                if(categoryList.count == 5)cat = [AdBrixCommerceProductCategoryModel create:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3] category5:categoryList[4]];
            }
            
            AdBrixCommerceProductAttrModel *attrs;
            if ([jsonOb objectForKey:@"extra_attrs"])
            {
                NSDictionary* attrsDic = [jsonOb objectForKey:@"extra_attrs"];
                attrs = [AdBrixCommerceProductAttrModel create:attrsDic];
            }
            
            
            [pArr addObject:[AdBrix createCommerceProductModel:[jsonOb objectForKey:@"productId"]
                                                   productName:[jsonOb objectForKey:@"productName"]
                                                         price:[self checkNilToDoubleZero :[jsonOb objectForKey:@"price"]]
                                                      discount:[self checkNilToDoubleZero:[jsonOb objectForKey:@"discount"]]
                                                      quantity:[self checkNilToZero:[jsonOb objectForKey:@"quantity"]]
                                                currencyString:[jsonOb objectForKey:@"productId"]
                                                      category:cat extraAttrsMap:attrs]];
        
        
        }

        [AdBrix commercePurchase:[params objectForKey:@"Param1"] productsInfos:pArr discount:[[params objectForKey:@"Param3"] doubleValue] deliveryCharge:[[params objectForKey:@"Param4"] doubleValue] paymentMethod:[AdBrix paymentMethod:[[params objectForKey:@"Param5"] integerValue]]];
    }
    @catch (NSException *exception)
    {
        NSLog(@"- (void)commercePurchase:(NSMutableDictionary *)params : error, : %@", exception);
    }
}

- (void)commercePurchase:(NSString *)orderId productsJsonDict:(NSArray *)productsJsonDict discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSString *)paymentMethod
{
    
}

- (void)commerceDeeplinkOpen : (NSString *)deeplinkUrl
{
    
}

- (void)commerceLogin : (NSString *)userId
{
    
}

- (void)commerceRefund:(NSString *)orderId productsJsonDict:(NSArray *)productsJsonDict penaltyCharge:(double)penaltyCharge
{
    
}

- (void)commerceAddtoCart:(NSArray *)productsJsonDict
{
    
}

- (void)commerceAddToWishList:(NSArray *)productsJsonDict
{
    
}

- (void)commerceProductView:(NSArray *)productsJsonDict
{
    
}

- (void)commerceCategoryView:(AdBrixCommerceProductCategoryModel*)category
{
    
}

- (void)commerceReviewOrder:(NSString *)orderId productsJsonDict:(NSArray *)productsJsonDict discount:(double)discount deliveryCharge:(double)deliveryCharge
{
    
}

- (void)commercePaymentView:(NSString *)orderId productsJsonDict:(NSArray *)productsJsonDict discount:(double)discount deliveryCharge:(double)deliveryCharge
{
    
}

- (void)commerceSearch:(NSArray *)productsJsonDict keyword:(NSString *) keyword
{
    
}

- (void)commerceShare:(NSString*)channel productsJsonDict:(NSArray *)productsJsonDict
{
    
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


#pragma mark - InterfaceAnalytics
- (void)startSession:(NSString *)appKey
{
    // no-op
}

- (void)stopSession
{
    // no-op
}

- (void)setSessionContinueMillis:(long)millis
{
    // no-op
}

- (void)setCaptureUncaughtException:(BOOL)isEnabled
{
    // no-op
}

- (void)setDebugMode:(BOOL)debug
{
    // no-op
}

- (void)logError:(NSString *)errorId withMsg:(NSString *)message
{
    // no-op
}

- (void)logEvent:(NSString *)eventId
{
    // no-op
}

- (void)logEvent:(NSString *)eventId withParam:(NSMutableDictionary *)paramMap
{
    // no-op
}

- (void)logTimedEventBegin:(NSString *)eventId
{
    // no-op
}

- (void)logTimedEventEnd:(NSString *)eventId
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



@end
