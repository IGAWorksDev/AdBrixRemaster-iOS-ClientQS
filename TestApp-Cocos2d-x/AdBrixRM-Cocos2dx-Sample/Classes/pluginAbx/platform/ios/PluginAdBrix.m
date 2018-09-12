//
//  PluginAdBrix.m
//  PluginAdBrix
//
//  Created by wonje,song on 2015. 7. 14..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import "PluginAdBrix.h"

//#import "AdsWrapper.h"

@implementation PluginAdBrix


- (void)setAdBrixDeeplinkDelegate
{
    [[AdBrixRM sharedInstance] setDeeplinkDelegateWithDelegate:self];
}

- (void)setAppleAdvertisingIdentifier:(NSString *)appleAdvertisingIdentifier {
    NSLog(@"AdBrixRM :setAppleAdvertisingIdentifier");
    [[AdBrixRM sharedInstance] setAppleAdvertisingIdentifier:appleAdvertisingIdentifier];
}

- (void)setEventUploadCountInterval:(NSNumber *)countInterval {
    NSLog(@"AdBrixRM :setEventUploadCountInterval");
    [[AdBrixRM sharedInstance] setEventUploadCountInterval:[[AdBrixRM sharedInstance] convertCountInterval:[countInterval integerValue]]];
}
- (void)setEventUploadTimeInterval:(NSNumber *)timeInterval {
    NSLog(@"AdBrixRM :setEventUploadTimeInterval");
    [[AdBrixRM sharedInstance] setEventUploadTimeInterval:[[AdBrixRM sharedInstance] convertTimeInterval:[timeInterval integerValue]]];
}

- (void)deepLinkOpenWithUrl:(NSString *)urlStr {
    NSLog(@"AdBrixRM :deepLinkOpenWithUrl");
    [[AdBrixRM sharedInstance] deepLinkOpenWithUrl:[NSURL URLWithString: urlStr]];
}

- (void)initAdBrix:(NSString *)appKey secretKey:(NSString *)secretKey {
    NSLog(@"AdBrixRM :initAdBrix1");
    [[AdBrixRM sharedInstance] initAdBrixWithAppKey:appKey secretKey:secretKey];
}

- (void)initAdBrix:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :initAdBrix2");
//     [IgaworksCore igaworksCoreWithAppKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] andHashKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]andIsUseIgaworksRewardServer:[self checkNilToNo:[params objectForKey:@"Param3"]]];

    NSLog(@"AdBrixRM :initAdBrix2 %@, %@", [self checkNilToBlankString:[params objectForKey:@"Param1"]], [self checkNilToBlankString:[params objectForKey:@"Param2"]]);
    [[AdBrixRM sharedInstance] initAdBrixWithAppKey:[self checkNilToBlankString:[params objectForKey:@"Param1"]] secretKey:[self checkNilToBlankString:[params objectForKey:@"Param2"]]];
}

- (void)setLogLevel:(NSNumber *)logLevel {
    NSLog(@"AdBrixRM :setLogLevel");
    [[AdBrixRM sharedInstance] setLogLevel:[[AdBrixRM sharedInstance] convertLogLevel:[logLevel integerValue]]];
}

- (void)setAge:(NSNumber *)age {
    NSLog(@"AdBrixRM :setAge %@", age);
    [[AdBrixRM sharedInstance] setAgeWithInt:[age integerValue]];
}

- (void)setGender:(NSNumber *)gender {
    NSLog(@"AdBrixRM :setGender");
    [[AdBrixRM sharedInstance] setGenderWithAdBrixGenderType:  [[AdBrixRM sharedInstance] convertGender:[gender integerValue]] ];
}

- (void)setUserProperties:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :setUserProperties");
    [[AdBrixRM sharedInstance] setUserPropertiesWithDictionary:params];
}

- (void)gdprForgetMe {
    NSLog(@"AdBrixRM :gdprForgetMe");
    [[AdBrixRM sharedInstance] gdprForgetMe];
}

- (void)events:(NSString *)eventName {
    NSLog(@"AdBrixRM :events");
    [[AdBrixRM sharedInstance] eventWithEventName:eventName];
}
- (void)eventsWithParam:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :events");
   [[AdBrixRM sharedInstance] eventWithEventName:[self checkNilToBlankString:[params objectForKey:@"Param1"]] value:[params objectForKey:@"Param2"]];
}

- (void)login:(NSString *)userId {
    NSLog(@"AdBrixRM :login");
    [[AdBrixRM sharedInstance] loginWithUserId:[self checkNilToBlankString:userId]];
}


- (void)gameLevelAchieved:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :gameLevelAchieved");
    [[AdBrixRM sharedInstance] gameLevelAchievedWithLevel:[[params objectForKey:@"Param1"] integerValue] gameInfoAttr:[params objectForKey:@"Param2"]];
}

- (void)gameTutorialCompleted:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :gameTutorialCompleted");
    [[AdBrixRM sharedInstance] gameTutorialCompletedWithIsSkip:[[params objectForKey:@"Param1"] boolValue] gameInfoAttr:[params objectForKey:@"Param2"]];
}

- (void)gameCharacterCreated:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :gameCharacterCreated");
    [[AdBrixRM sharedInstance] gameCharacterCreatedWithGameInfoAttr:params];
}

- (void)gameStageCleared:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :gameStageCleared");
    [[AdBrixRM sharedInstance] gameStageClearedWithStageName:[self checkNilToBlankString:[params objectForKey:@"Param1"]] gameInfoAttr:[params objectForKey:@"Param2"]];
}

- (void)commonPurchaseSingle:(NSMutableDictionary *)params;
{
    @try
    {
        if(params == nil)
        {
            NSLog(@"- (void)commonPurchaseSingle:(NSMutableDictionary *)params : missing params, params is : %@", params);
            return;
        }
        else {
            NSLog(@"commonPurchase params ORIGIN :: %@", params);
        }
        
        NSMutableArray<AdBrixRmCommerceProductModel *> *pArr = [NSMutableArray array];
        NSData *data = [[params objectForKey:@"Param2"] dataUsingEncoding:NSUTF8StringEncoding];
        NSError* e = nil;
        id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:&e];
        
        if (e || json==nil) {
            NSLog(@"commonPurchase productJSON error :: json string parsing err! %@", e);
        }
        else {
            NSLog(@"commonPurchase JSON :: %@", json);
            
            AdBrixRmCommerceProductCategoryModel *cat = nil;
            
            if ([json objectForKey:@"category"])
            {
                NSArray* categoryList = [[json objectForKey:@"category"] componentsSeparatedByString:@"."];
                if(categoryList.count == 1)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0]];
                if(categoryList.count == 2)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1]];
                if(categoryList.count == 3)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2]];
                if(categoryList.count == 4)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3]];
                if(categoryList.count == 5)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3] category5:categoryList[4]];
            }
            
            AdBrixRmCommerceProductAttrModel *attrs;
            if ([json objectForKey:@"extra_attrs"])
            {
                NSDictionary* attrsDic = [json objectForKey:@"extra_attrs"];
                attrs = [[AdBrixRM sharedInstance] createCommerceProductAttrDataWithDictionary:attrsDic];
            }
            
            [pArr addObject:[[AdBrixRM sharedInstance] createCommerceProductDataWithProductId:[json objectForKey:@"product_id"]
                                                                                  productName:[json objectForKey:@"product_name"]
                                                                                        price:[self checkNilToDoubleZero :[json objectForKey:@"price"]]
                                                                                     quantity:[self checkNilToZero:[json objectForKey:@"quantity"]]
                                                                                     discount:[self checkNilToDoubleZero:[json objectForKey:@"discount"]]
                                                                               currencyString:[self currencyName:[json objectForKey:@"currency"]]
                                                                                     category:cat
                                                                              productAttrsMap:attrs]];
            
            
            [[AdBrixRM sharedInstance]   commonPurchaseWithOrderId:[params objectForKey:@"Param1"]
                                                       productInfo:pArr
                                                          discount:[[params objectForKey:@"Param3"] doubleValue]
                                                    deliveryCharge:[[params objectForKey:@"Param4"] doubleValue]
                                                     paymentMethod:[[AdBrixRM sharedInstance] convertPayment:[[params objectForKey:@"Param5"] integerValue]]
                                                         orderAttr:[params objectForKey:@"Param6"]];
        }
        
    }
    @catch (NSException *exception)
    {
        NSLog(@"- (void)commonPurchaseSingle:(NSMutableDictionary *)params : error, : %@", exception);
    }
    
}

- (void)commonPurchaseBulk:(NSMutableDictionary *)params;
{
    @try
    {
        if(params == nil)
        {
            NSLog(@"- (void)commonPurchaseBulk:(NSMutableDictionary *)params : missing params, params is : %@", params);
            return;
        }
        else {
            NSLog(@"commonPurchase params ORIGIN :: %@", params);
        }
        
        NSMutableArray *pArr = [NSMutableArray array];
        NSMutableDictionary *pMap = [params objectForKey:@"Param2"];;
        
        //NSLog(@"commonPurchase :: %@", params);
        
        for (NSString *pKey in pMap)
        {
            NSData *data = [[pMap valueForKey:pKey] dataUsingEncoding:NSUTF8StringEncoding];
            NSError* e = nil;
            
            
            id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:&e];
           
            if (e || json==nil) {
                NSLog(@"commonPurchase productJSON error :: json string parsing err! %@", e);
            }
            else {
                AdBrixRmCommerceProductCategoryModel *cat = nil;
                
                NSLog(@"commonPurchase productJSON :: %@", json);
                
                if ([json objectForKey:@"category"])
                {
                    NSArray* categoryList = [[json objectForKey:@"category"] componentsSeparatedByString:@"."];
                    if(categoryList.count == 1)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0]];
                    if(categoryList.count == 2)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1]];
                    if(categoryList.count == 3)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2]];
                    if(categoryList.count == 4)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3]];
                    if(categoryList.count == 5)cat = [[AdBrixRM sharedInstance] createCommerceProductCategoryDataWithCategory:categoryList[0] category2:categoryList[1] category3:categoryList[2] category4:categoryList[3] category5:categoryList[4]];
                }
                
                AdBrixRmCommerceProductAttrModel *attrs;
                if ([json objectForKey:@"extra_attrs"])
                {
                    NSDictionary* attrsDic = [json objectForKey:@"extra_attrs"];
                    attrs = [[AdBrixRM sharedInstance] createCommerceProductAttrDataWithDictionary:attrsDic];
                }
                
                [pArr addObject:[[AdBrixRM sharedInstance] createCommerceProductDataWithProductId:[json objectForKey:@"product_id"]
                                                                                      productName:[json objectForKey:@"product_name"]
                                                                                            price:[self checkNilToDoubleZero :[json objectForKey:@"price"]]
                                                                                         quantity:[self checkNilToZero:[json objectForKey:@"quantity"]]
                                                                                         discount:[self checkNilToDoubleZero:[json objectForKey:@"discount"]]
                                                                                   currencyString:[self currencyName:[json objectForKey:@"currency"]]
                                                                                         category:cat
                                                                                  productAttrsMap:attrs]];
            }
            
            
            
            
            
        }
        
        [[AdBrixRM sharedInstance]   commonPurchaseWithOrderId:[params objectForKey:@"Param1"]
                                                   productInfo:pArr
                                                      discount:[[params objectForKey:@"Param3"] doubleValue]
                                                deliveryCharge:[[params objectForKey:@"Param4"] doubleValue]
                                                 paymentMethod:[[AdBrixRM sharedInstance] convertPayment:[[params objectForKey:@"Param5"] integerValue]]
                                                     orderAttr:[params objectForKey:@"Param6"]];
    }
    @catch (NSException *exception)
    {
        NSLog(@"- (void)commonPurchaseBulk:(NSMutableDictionary *)params : error, : %@", exception);
    }
}

- (void)commonSignUp:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :commonSignUp");
    [[AdBrixRM sharedInstance] commonSignUpWithChannel:[[AdBrixRM sharedInstance] convertSignUpChannel:[[params objectForKey:@"Param1"] integerValue]] commonAttr:[params objectForKey:@"Param2"]];
}

- (void)commonUseCredit:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :commonUseCredit");
    [[AdBrixRM sharedInstance] commonUseCreditWithCommonAttr:params];
}

- (void)commonAppUpdate:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :commonAppUpdate");
    [[AdBrixRM sharedInstance] commonAppUpdateWithPrev_ver:[params objectForKey:@"Param1"] curr_ver:[params objectForKey:@"Param1"] commonAttr:[params objectForKey:@"Param4"]];
}

- (void)commonInvite:(NSMutableDictionary *)params {
    NSLog(@"AdBrixRM :commonInvite");
    [[AdBrixRM sharedInstance] commonInviteWithChannel:[[AdBrixRM sharedInstance] convertInviteChannel:[[params objectForKey:@"Param1"]  integerValue]] commonAttr:[params objectForKey:@"Param2"] ];
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
