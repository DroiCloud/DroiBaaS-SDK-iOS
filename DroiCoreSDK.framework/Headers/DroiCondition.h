/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString* const DroiCondition_LT;
FOUNDATION_EXPORT NSString* const DroiCondition_LT_OR_EQ;
FOUNDATION_EXPORT NSString* const DroiCondition_EQ;
FOUNDATION_EXPORT NSString* const DroiCondition_NEQ;
FOUNDATION_EXPORT NSString* const DroiCondition_GT_OR_EQ;
FOUNDATION_EXPORT NSString* const DroiCondition_GT;
FOUNDATION_EXPORT NSString* const DroiCondition_ISNULL;
FOUNDATION_EXPORT NSString* const DroiCondition_ISNOTNULL;
FOUNDATION_EXPORT NSString* const DroiCondition_CONTAINS;
FOUNDATION_EXPORT NSString* const DroiCondition_NOTCONTAINS;
FOUNDATION_EXPORT NSString* const DroiCondition_STARTSWITH;
FOUNDATION_EXPORT NSString* const DroiCondition_NOTSTARTSWITH;
FOUNDATION_EXPORT NSString* const DroiCondition_ENDSWITH;
FOUNDATION_EXPORT NSString* const DroiCondition_NOTENDSWITH;
FOUNDATION_EXPORT NSString* const DroiCondition_IN;
FOUNDATION_EXPORT NSString* const DroiCondition_NOTIN;

@interface DroiCondition : NSObject
#pragma mark - Chain methods
- (DroiCondition*) or : (DroiCondition*) arg;
- (DroiCondition*) and : (DroiCondition*) arg;

#pragma mark - Instance methods
+ (instancetype) cond : (NSString*) arg1 andType : (NSString*) type andArg2 : (id) arg2;
+ (instancetype) selectIn : (NSString*) arg1 withItems : (NSArray*) items;
+ (instancetype) notSelectIn : (NSString*) arg1 withItems : (NSArray*) items;
@end
