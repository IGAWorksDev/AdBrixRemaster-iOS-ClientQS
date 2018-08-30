//
//  PluginAdBrix.m
//  PluginAdBrix
//
//  Created by wonje,song on 2015. 7. 14..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginAdBrixRM.h"

#import <AdBrixRM/AdBrixRM.h>
#import <AdBrixRM/AdBrixRM-Swift.h>

#import "AdsWrapper.h"

@implementation PluginAdBrixRM

- (void)setAppleAdvertisingIdentifier:(NSString *)appleAdvertisingIdentifier {
    [[AdBrixRM sharedInstance] setAppleAdvertisingIdentifier:appleAdvertisingIdentifier];
}

- (void)setEventUploadCountInterval:(NSNumber *)countInterval {
    [[AdBrixRM sharedInstance] setEventUploadCountInterval:[[AdBrixRM sharedInstance] convertCountInterval:[countInterval integerValue]]];
}
- (void)setEventUploadTimeInterval:(NSNumber *)timeInterval {
    [[AdBrixRM sharedInstance] setEventUploadTimeInterval:[[AdBrixRM sharedInstance] convertTimeInterval:[timeInterval integerValue]]];
}

- (void)deepLinkOpenWithUrl:(NSString *)urlStr {
    [[AdBrixRM sharedInstance] deepLinkOpenWithUrl:[NSURL URLWithString: urlStr]];
}


- (void)initAdBrix:(NSString *)appKey secretKey:(NSString *)secretKey {
    [[AdBrixRM sharedInstance] initAdBrixWithAppKey:appKey secretKey:secretKey];
}

- (void)setLogLevel:(NSNumber *)logLevel {
    [[AdBrixRM sharedInstance] setLogLevel:[[AdBrixRM sharedInstance] convertLogLevel:(NSInteger)logLevel]];
}

- (void)setAge:(NSNumber *)age {
    [[AdBrixRM sharedInstance] setAgeWithInt:(NSInteger)age];
}

- (void)setGender:(NSNumber *)gender {
    [[AdBrixRM sharedInstance] setGenderWithAdBrixGenderType:  [[AdBrixRM sharedInstance] convertGender:[gender integerValue]] ];
}

- (void)setUserProperties:(NSMutableDictionary *)params {
    [[AdBrixRM sharedInstance] setUserPropertiesWithDictionary:params];
}

- (void)gdprForgetMe {
    [[AdBrixRM sharedInstance] gdprForgetMe];
}

- (void)events:(NSString *)eventName {
    [[AdBrixRM sharedInstance] eventWithEventName:eventName];
}
- (void)events:(NSString *)eventName params:(NSMutableDictionary *)params {
    [[AdBrixRM sharedInstance] eventWithEventName:eventName value:params];
}

- (void)login:(NSString *)userId {
    [[AdBrixRM sharedInstance] loginWithUserId:userId];
}


- (void)gameLevelAchieved:(NSNumber *)level attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] gameLevelAchievedWithLevel:[level integerValue] gameInfoAttr:attr];
}

- (void)gameTutorialCompleted:(BOOL)isSkip attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] gameTutorialCompletedWithIsSkip:isSkip gameInfoAttr:attr];
}

- (void)gameCharacterCreated:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] gameCharacterCreatedWithGameInfoAttr:attr];
}

- (void)gameStageCleared:(NSString *)stageName attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] gameStageClearedWithStageName:stageName gameInfoAttr:attr];
}


- (void)commonPurchase:(NSString *)orderId productParam:(NSMutableDictionary *)productParam discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSNumber *)paymentMethod orderAttr:(NSMutableDictionary *)orderAttr {
    
    if(productParam == nil) {
        NSLog(@"- (void)commercePurchaseIII:(NSMutableDictionary *)params : missing params, params is : %@", productParam);
        return;
    }
    
    NSMutableArray<AdBrixRmCommerceProductModel *> *pArr = [NSMutableArray array];
    
    NSMutableDictionary *pMap = [productParam objectForKey:@"products"];
    
    for (NSString *pKey in pMap)
    {
        NSData *data = [[pMap valueForKey:pKey] dataUsingEncoding:NSUTF8StringEncoding];
        id jsonOb = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        AdBrixRmCommerceProductCategoryModel *cat = nil;
        
        if ([jsonOb objectForKey:@"category"])
        {
            NSArray* categoryList = [[jsonOb objectForKey:@"category"] componentsSeparatedByString:@"."];
            if(categoryList.count == 1)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0]];
            if(categoryList.count == 2)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1]];
            if(categoryList.count == 3)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2]];
            if(categoryList.count == 4)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3]];
            if(categoryList.count == 5)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3] category5:categoryList[4]];
        }
        
        AdBrixRmCommerceProductAttrModel *attrs;
        if ([jsonOb objectForKey:@"extra_attrs"])
        {
            NSDictionary* attrsDic = [jsonOb objectForKey:@"extra_attrs"];
            attrs = [[AdBrixRM sharedInstance] createCommerceProductAttrDataWithDictionary:attrsDic];
        }
        
        [pArr addObject:[[AdBrixRM sharedInstance] createCommerceProductDataWithProductId:[jsonOb objectForKey:@"productId"]
                                                                              productName:[jsonOb objectForKey:@"productName"]
                                                                                    price:[self checkNilToDoubleZero :[jsonOb objectForKey:@"price"]]
                                                                                 quantity:[self checkNilToZero:[jsonOb objectForKey:@"quantity"]]
                                                                                 discount:[self checkNilToDoubleZero:[jsonOb objectForKey:@"discount"]]
                                                                           currencyString:[self currencyName:[jsonOb objectForKey:@"currency"]]
                                                                                 category:cat
                                                                          productAttrsMap:attrs]];
    }
        
    [[AdBrixRM sharedInstance]   commonPurchaseWithOrderId:orderId
                                 productInfo:pArr
                                 discount:discount
                                 deliveryCharge:deliveryCharge
                                 paymentMethod:[[AdBrixRM sharedInstance] convertPayment:[paymentMethod integerValue]]
                                 orderAttr:orderAttr];
}

- (void)commonSignUp:(NSNumber *)channel attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] commonSignUpWithChannel:[[AdBrixRM sharedInstance] convertSignUpChannel:[channel integerValue]] commonAttr:attr];
}

- (void)commonUseCredit:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] commonUseCreditWithCommonAttr:attr];
}

- (void)commonAppUpdate:(NSString *)prev_ver curr_ver:(NSString *)curr_ver attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] commonAppUpdateWithPrev_ver:prev_ver curr_ver:curr_ver commonAttr:attr];
}

- (void)commonInvite:(NSNumber *)channel attr:(NSMutableDictionary *)attr {
    [[AdBrixRM sharedInstance] commonInviteWithChannel:[[AdBrixRM sharedInstance] convertInviteChannel:[channel integerValue]] commonAttr:attr];
}


- (NSString *)currencyName:(NSNumber *)currency
{
    return [[AdBrixRM sharedInstance] getCurrencyString:[currency integerValue]];
}

- (NSString *)paymentMethod:(NSNumber *)method
{
    return [[AdBrixRM sharedInstance] getPaymentMethod:[method integerValue]];
}

- (NSString *)sharingChannel:(NSNumber *)channel
{
    return [[AdBrixRM sharedInstance] getSharingChannel:[channel integerValue]];
}

- (NSString *)signUpChannel:(NSNumber *)channel
{
    return [[AdBrixRM sharedInstance] getSignUpChannel:[channel integerValue]];
}

- (NSString *)inviteChannel:(NSNumber *)channel
{
    return [[AdBrixRM sharedInstance] getInviteChannel:[channel integerValue]];
}




#pragma mark - private method

+(AdBrixRmCommerceProductCategoryModel *)makeCategoryFromStringForCommerce: (NSString *)categoryString
{
    NSString *categories[5];
    if (categoryString) {
        NSArray* categoryList = [categoryString componentsSeparatedByString:@"."];
        for (int i=0; i<categoryList.count; ++i)
        {
            categories[i] = categoryList[i];
        }
    }
    
    return [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categories[0] category2:categories[1] category3:categories[2] category4:categories[3] category5:categories[4]];
}

+ (NSMutableDictionary* )makeExtraAttrDictionaryFromJson:(NSString *)jsonString
{
    NSMutableDictionary *_extraAttrs = [NSMutableDictionary dictionary];
    
    id dict = [NSJSONSerialization JSONObjectWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding] options:kNilOptions error:nil];
    
    for(NSString* key in dict)
    {
        if(![key isKindOfClass:[NSNull class]])
        {
            [_extraAttrs setValue:[dict objectForKey:key] forKey:key];
        }
    }
    
    return _extraAttrs;
}

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
