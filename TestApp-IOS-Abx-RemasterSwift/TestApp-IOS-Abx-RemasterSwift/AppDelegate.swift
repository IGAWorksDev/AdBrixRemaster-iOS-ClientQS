//
//  AppDelegate.swift
//  TestApp-IOS-Abx-RemasterSwift
//
//  Created by igaworks on 2018. 2. 6..
//  Copyright © 2018년 igaworks. All rights reserved.
//

import UIKit
import AdBrixRM
import AdSupport
import CoreLocation

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, CLLocationManagerDelegate, AdBrixRMDeeplinkDelegate {

    var window: UIWindow?
    var locationManager:CLLocationManager!

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        let adBrix = AdBrixRM.getInstance
        
        //광고id
        if ((NSClassFromString("ASIdentifierManager")) != nil) {
            let ifa :UUID = ASIdentifierManager.shared().advertisingIdentifier
            adBrix.setAppleAdvertisingIdentifier(ifa.uuidString)
        }
        
        
        adBrix.initAdBrix(appKey: "03M110kRQ0K7UAF16jxmYg", secretKey:"Br9TLszIZUGsmSbnToNBXg")
        
        adBrix.setPushEnable(toPushEnable: true)
        adBrix.setLogLevel(AdBrixRM.AdBrixLogLevel.ERROR)
        adBrix.setEventUploadCountInterval(AdBrixRM.AdBrixEventUploadCountInterval.MIN)
        adBrix.setEventUploadTimeInterval(AdBrixRM.AdBrixEventUploadTimeInterval.MIN)
        adBrix.setLocation(latitude: 32.514, longitude: 126.986)
                
        
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
        print("Remain BgTime :: App is applicationDidEnterBackground.")
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
        print("Remain BgTime :: App is applicationWillTerminate.")
    }
    
    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any?) -> Bool {
        let adBrix = AdBrixRM.getInstance
        adBrix.deepLinkOpen(url: url)
        return true
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        let adBrix = AdBrixRM.getInstance
        adBrix.deepLinkOpen(url: url)
        return true
    }
    
    func application(_ application: UIApplication,
                     continue userActivity: NSUserActivity,
                     restorationHandler: @escaping ([Any]?) -> Void) -> Bool {
        guard userActivity.activityType == NSUserActivityTypeBrowsingWeb,
            let incomingURL = userActivity.webpageURL,
            let components = NSURLComponents(url: incomingURL, resolvingAgainstBaseURL: true),
            let path = components.path,
            let params = components.queryItems else {
                return false
        }
        
        print("path = \(path) :: incomingURL \(incomingURL) \(params)")
        let adBrix = AdBrixRM.getInstance
        adBrix.deepLinkOpen(url: incomingURL)
        
        return true
    }
    
    func didReceiveDeeplink(deeplink: String) {
        print("deeplink received :: \(deeplink)")
    }
    
//    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
//
//        print("location error is = \(error.localizedDescription)")
//
//    }
//
//
//    func locationManager(_ manager: CLLocationManager,
//                         didUpdateLocations locations: [CLLocation]) {
//
//        if let loc = manager.location {
//            let locValue:CLLocationCoordinate2D = (manager.location?.coordinate)!
//            print("Current Locations = \(locValue.latitude) \(locValue.longitude)")
//        }
//
//    }


    func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
//        if let newData = fetchUpdates() {
//            addDataToFeed(newData: newData)
//            completionHandler(.newData)
//        }
        
        self.checkData(completion: { (_ result) in
            
            print("Time Fetch :: checkData :: \(result)")
            if result {
                completionHandler(.newData)
            }
            else {
                print("Time Fetch :: checkData")
                completionHandler(.noData)
            }
        })
    }
    
    func checkData(completion: @escaping (_ result: Bool)->()) {
        completion(true)
        
    }
    
}

