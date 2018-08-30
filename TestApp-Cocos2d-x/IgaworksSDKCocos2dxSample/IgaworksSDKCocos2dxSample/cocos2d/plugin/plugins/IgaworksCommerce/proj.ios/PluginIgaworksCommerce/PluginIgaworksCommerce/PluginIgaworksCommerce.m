//
//  PluginIgaworksCommerce.m
//  PluginIgaworksCommerce
//
//  Created by 강기태 on 2015. 9. 10..
//  Copyright (c) 2015년 igaworks. All rights reserved.
//

#import "PluginIgaworksCommerce.h"

@implementation PluginIgaworksCommerce

- (void)purchase:(NSMutableDictionary *)params {
    
    NSString* orderId = [params objectForKey:@"Param1"];
    NSString* productId = [params objectForKey:@"Param2"];
    NSNumber* price = [params objectForKey:@"Param3"];
    NSString* currencyStr = [params objectForKey:@"Param4"];
    
    NSDictionary* categories = [params objectForKey:@"Param5"];
    NSMutableArray* categoriesArr = [NSMutableArray arrayWithCapacity:5];
    
    for (int i=0; i<5; ++i) {
        id categoryVal = categories[[NSString stringWithFormat:@"%d", i]];
        if (!categoryVal) {
            break;
        }
        
        [categoriesArr addObject:categoryVal];
    }
    
    NSNumber* quantity = [params objectForKey:@"Param6"];
    NSString* productName = [params objectForKey:@"Param7"];
    
    [IgaworksCommerce purchase:orderId productId:productId price:[price doubleValue] currencyString:currencyStr category:categoriesArr quantity:[quantity unsignedIntegerValue] productName:productName];
}

- (void)purchaseWithJson:(NSString*)purchaseDataJsonString {
    [IgaworksCommerce purchase:purchaseDataJsonString];
}

- (NSString *)currencyName:(NSUInteger)currency {
    return [IgaworksCommerce currencyName:currency];
}

#pragma mark - InterfaceAds
- (void) configDeveloperInfo: (NSMutableDictionary*) cpInfo {
    // no-op
}

- (void) payForProduct: (NSMutableDictionary*) profuctInfo {
    
}

- (void) setDebugMode: (BOOL) debug {
    // no-op
}

- (NSString*) getSDKVersion {
    return @"1.0.1in";
}

- (NSString*) getPluginVersion {
    return @"1.0";
}

@end
