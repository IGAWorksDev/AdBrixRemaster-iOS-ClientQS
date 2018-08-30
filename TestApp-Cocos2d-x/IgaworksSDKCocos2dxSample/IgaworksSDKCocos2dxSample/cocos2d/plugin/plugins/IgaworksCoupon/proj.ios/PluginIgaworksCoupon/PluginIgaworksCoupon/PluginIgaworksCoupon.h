//
//  PluginIgaworksCoupon.h
//  PluginIgaworksCoupon
//
//  Created by wonje,song on 2015. 7. 15..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "InterfaceAds.h"

@interface PluginIgaworksCoupon : NSObject <InterfaceAds>


- (void)showCoupon;
- (void)checkCoupon:(NSString *)code;

@end
