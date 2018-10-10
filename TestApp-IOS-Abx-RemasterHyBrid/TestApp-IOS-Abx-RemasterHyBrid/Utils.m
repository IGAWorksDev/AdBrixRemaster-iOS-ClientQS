//
//  Utils.m
//  TestApp-IOS-Abx-RemasterHyBrid
//
//  Created by igaworks on 2018. 9. 18..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Utils.h"

@implementation Utils

+  (NSMutableDictionary *)getURLParmaters:(NSURL *)URL
{
    NSMutableDictionary *parameters = nil;
    
    NSString *query = [URL query];
    if (query.length > 0) {
        
        NSArray *components = [query componentsSeparatedByString:@"&"];
        parameters = [[NSMutableDictionary alloc] init];
        for (NSString *component in components)
        {
            NSArray *subcomponents = [component componentsSeparatedByString:@"="];
            if(subcomponents.count == 2)
            {
                
                [parameters setObject:[[subcomponents objectAtIndex:1] stringByRemovingPercentEncoding]
                               forKey:[[subcomponents objectAtIndex:0] stringByRemovingPercentEncoding]];
            }
            else
            {
                [parameters setObject:@"" forKey:[component stringByRemovingPercentEncoding]];
            }
        }
    }
    
    return parameters;
}

@end
