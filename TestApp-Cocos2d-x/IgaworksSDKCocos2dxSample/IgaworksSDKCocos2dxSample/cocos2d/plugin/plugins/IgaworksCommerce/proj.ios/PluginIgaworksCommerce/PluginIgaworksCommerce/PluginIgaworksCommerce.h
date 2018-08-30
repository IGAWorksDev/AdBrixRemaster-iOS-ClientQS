//
//  PluginIgaworksCommerce.h
//  PluginIgaworksCommerce
//
//  Created by 강기태 on 2015. 9. 10..
//  Copyright (c) 2015년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "InterfaceIAP.h"

#import <IgaworksCommerce/IgaworksCommerce.h>

@interface PluginIgaworksCommerce : NSObject <InterfaceIAP>

- (void)purchase:(NSMutableDictionary *)params;
- (void)purchaseWithJson:(NSString*)purchaseDataJsonString;

- (NSString *)currencyName:(NSUInteger)currency;
+ (IgaworksCommerceItem*)createItemModel :(NSString*)orderId productId:(NSString*)productId productName:(NSString*)productName price:(double)price quantity:(NSUInteger)quantity currencyString:(NSString *)currencyString category:(NSString*)categories;
@end
