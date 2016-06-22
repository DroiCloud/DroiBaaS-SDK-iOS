/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import <Foundation/Foundation.h>

extern NSString* const MainThreadDispatcher;
extern NSString* const BackgroundThreadDispatcher;

@interface TaskDispatcher : NSObject
-(instancetype) init __attribute__((unavailable("init not available")));

#pragma mark - Normal Task
- (BOOL) enqueueTask : (void (^)(void)) block;
- (BOOL) enqueueTask : (void (^)(void)) block withName : (NSString*) taskName;
- (BOOL) enqueueTask : (void (^)(void)) block withDelay : (int) delayInMillisecond;
- (BOOL) enqueueTask : (void (^)(void)) block withName : (NSString*) taskName andDelay : (int) delayInMillisecond;

#pragma mark - Timer Task
- (BOOL) enqueueTimerTask : (void (^)(void)) block withInterval : (int) intervalInMillisecond andName : (NSString*) taskName;
- (BOOL) killTask : (NSString*) taskName;
- (BOOL) killAllTasks;

#pragma mark - State
- (BOOL) isRunning;
- (BOOL) hasTask : (NSString*) taskName;
- (dispatch_queue_t) threadQueue;
- (NSString*) getName;

#pragma mark - Global methods
+ (TaskDispatcher*) currentTaskDispatcher;
+ (TaskDispatcher*) getTaskDispatcher:(NSString*) dispatcherName;
@end
