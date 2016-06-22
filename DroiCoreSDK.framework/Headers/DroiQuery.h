/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "DroiObject.h"
#import "DroiCondition.h"
#import "DroiError.h"

typedef void(^DroiQueryCallback)(NSArray* result, DroiError* err);

#ifndef DroiQueryAnnotation
#define DroiQueryAnnotation
#endif

#pragma mark - Query Constants
FOUNDATION_EXPORT NSString* const DroiQuery_LOCALSTORAGE;
FOUNDATION_EXPORT NSString* const DroiQuery_CLOUDSTORAGE;

FOUNDATION_EXPORT NSString* const DroiQuery_SELECT;
FOUNDATION_EXPORT NSString* const DroiQuery_INSERT;
FOUNDATION_EXPORT NSString* const DroiQuery_DELETE;
FOUNDATION_EXPORT NSString* const DroiQuery_UPDATE;

FOUNDATION_EXPORT NSString* const DroiQuery_WHERE;
FOUNDATION_EXPORT NSString* const DroiQuery_COND;
FOUNDATION_EXPORT NSString* const DroiQuery_VALUES;
FOUNDATION_EXPORT NSString* const DroiQuery_OR;
FOUNDATION_EXPORT NSString* const DroiQuery_AND;

FOUNDATION_EXPORT NSString* const DroiQuery_GROUPBY;
FOUNDATION_EXPORT NSString* const DroiQuery_ORDERBY;

FOUNDATION_EXPORT NSString* const DroiQuery_LIMIT;
FOUNDATION_EXPORT NSString* const DroiQuery_OFFSET;

@interface DroiQuery : NSObject
#pragma mark - Run Query Task
- (BOOL) run;
- (NSArray*) runQuery;
- (NSUInteger) runQueryInBackground : (DroiQueryCallback) callback;
- (void) cancelTask : (NSUInteger) taskId;

#pragma mark - Condition builder
- (DroiQuery*) localStorage;
- (DroiQuery*) cloudStorage;
- (DroiQuery*) queryByName : (NSString*) fromName;
- (DroiQuery*) queryByClass : (Class) clazz;
- (DroiQuery*) insertObject : (DroiObject*) object withClass : (Class) clazz;
- (DroiQuery*) insertObject : (DroiObject*) object withClassName : (NSString*) className;

- (DroiQuery*) deleteObject : (DroiObject*) object withClass : (Class) clazz;
- (DroiQuery*) deleteObject : (DroiObject*) object withClassName : (NSString*) className;
- (DroiQuery*) deleteByClass : (Class) clazz;

- (DroiQuery*) updateObject : (DroiObject*) object withClass : (Class) clazz;
- (DroiQuery*) updateObject : (DroiObject*) object withClassName : (NSString*) className;
- (DroiQuery*) updateByClass : (Class) clazz;

- (DroiQuery*) whereStatement : (NSString*) arg1 opType : (NSString*) opType arg2 : (NSString*) arg2;
- (DroiQuery*) whereStatement : (DroiCondition*) cond;
- (DroiQuery*) orderBy : (NSString*) arg ascending : (BOOL) ascendingSort;
- (DroiQuery*) limit : (int) limitSize;
- (DroiQuery*) offset : (int) position;
#pragma mark -

#pragma mark - Creation
+ (instancetype) create;
@end
