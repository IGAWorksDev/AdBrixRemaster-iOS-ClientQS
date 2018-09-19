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
                [parameters setObject:[[subcomponents objectAtIndex:1] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]
                               forKey:[[subcomponents objectAtIndex:0] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
            }
            else
            {
                [parameters setObject:@"" forKey:[component stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
            }
        }
    }
    
    return parameters;
}

@end
