//
//  DataController.h
//  PrometAR
//
// Created by Geoffroy Lesage on 4/24/13.
// Copyright (c) 2013 Promet Solutions Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

#import "SCNetworkReachability.h"
#import "DBController.h"


@class DataController;

@protocol DataControllerDelegate
- (void)gotNearData:(NSArray*)arObjects;
- (void)gotAllData:(NSArray*)arObjects;

- (void)gotUpdatedData;

@end

@interface DataController : NSObject <SCNetworkReachabilityDelegate> {
    DBController *dbController;
    
    // -- Reachability -- //
    BOOL siteIsReachable;
    int tries;
    
    BOOL fetching;
}

@property (assign, nonatomic) id <DataControllerDelegate> delegate;

-(void)getNearARObjects:(CLLocationCoordinate2D)coordinates;
-(void)getAllARObjects:(CLLocationCoordinate2D)coordinates;

-(void)fetchUpdatedARObjects;


@end