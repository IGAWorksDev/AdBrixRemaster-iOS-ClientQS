//
//  AppDelegate.m
//  TestApp-IOS-Abx-RemasterObjC
//
//  Created by igaworks on 2018. 2. 6..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#import "AppDelegate.h"
#import <AdBrixRm/AdBrixRM-Swift.h>
#import <AdSupport/AdSupport.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    AdBrixRM *adBrix = [AdBrixRM sharedInstance]; //또는 AdBrixRM *adBrixs = AdBrixRM.sharedInstance;

    //광고id
    if (NSClassFromString(@"ASIdentifierManager")) {
        NSUUID *ifa =[[ASIdentifierManager sharedManager]advertisingIdentifier];
        BOOL isAppleAdvertisingTrackingEnalbed = [[ASIdentifierManager sharedManager]isAdvertisingTrackingEnabled];
        [adBrix setAppleAdvertisingIdentifier:[ifa UUIDString] :isAppleAdvertisingTrackingEnalbed];
        NSLog(@"[ifa UUIDString] %@", [ifa UUIDString]);
    }
    
    [adBrix setLogLevel:AdBrixLogLevelNONE];
    [adBrix setEventUploadCountInterval:AdBrixEventUploadCountIntervalMIN];
    [adBrix setEventUploadTimeInterval:AdBrixEventUploadTimeIntervalMIN];
    
    double lat = 37.541;
    double lon = 126.986;
    [adBrix setLocationWithLatitude:lat longitude:lon];
    [adBrix initAdBrixWithAppKey:@"inputYourAppKeyFromServer" secretKey:@"inputYourSecretKeyFromServer"];
  
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}




//-(BOOL)application:(UIApplication *)app
//           openURL:(NSURL *)url
//           options:(NSDictionary *)options {
//    return NO;
//
//}

#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_9_0

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    
    
    
    
    // pass open url for commerce conversion
    AdBrixRM *adBrix = [AdBrixRM sharedInstance]; //또는 AdBrix *adBrixs = AdBrixRM.sharedInstance;
    [adBrix deepLinkOpenWithUrl:url];
    
    return YES;
}

#else

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options
{
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"deep link test"
                                                    message:@"deep link push open over ios9"
                                                   delegate:nil
                                          cancelButtonTitle:nil
                                          otherButtonTitles:@"Confirm",nil];
    [alert show];
    
    AdBrixRM *adBrix = [AdBrixRM sharedInstance];
    [adBrix deepLinkOpenWithUrl:url];
    return YES;
    
}
#endif

- (NSString *)getDateStr
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
    
    [dateFormatter setTimeZone:timeZone];
    [dateFormatter setDateFormat:[[AdBrixRM sharedInstance] AdBrixDateFormat]];
    dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US"];
    NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
    
    return dateString;
}


@end
