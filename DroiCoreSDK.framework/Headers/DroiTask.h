/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */
#import <Foundation/Foundation.h>

@interface DroiTask : NSObject
- (DroiTask*) then : (void (^)(void)) block;
- (DroiTask*) delay : (int) millisecond;
- (DroiTask*) callback : (void (^)(void)) callback inDispatcher : (NSString*) dispatcherName;
- (DroiTask*) callback : (void (^)(void)) callback;
- (BOOL) runInBackground : (NSString*) dispatcherName;
- (BOOL) runAndWait : (NSString*) dispatcherName;
- (BOOL) waitTask;
- (BOOL) cancel;
- (void) resetState;

+ (DroiTask*) create : (void (^)(void)) block;

@property (readonly) BOOL isCancelled;
@property (readonly) BOOL isCompleted;
@property (readonly) BOOL isRunning;

-(instancetype) init __attribute__((unavailable("init not available")));
@end
