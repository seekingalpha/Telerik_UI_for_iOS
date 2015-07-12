//
//  TKDataSourceFilterDescriptor.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKDataSource.h"

/**
 A filter descriptor used in TKDataSource to filter items.
 */
@interface TKDataSourceFilterDescriptor : NSObject

/**
 An SQL-like string query used when filtering items. Check the documentation of NSPredicate for detailed explanation for the syntax of this property value. The value of this property is ignored when the filterBlock property is set.
 */
@property (nonatomic, readonly) NSString *query;

/**
 The block function that is used to filter items. This property has higher priority than the query.
 */
@property (readonly) TKDataSourceFilterBlock filterBlock;

/**
 Initializes the filter descriptor with a query.

 @param query The query to use when filtering items.
 */
- (id)initWithQuery:(NSString*)query;

/**
 Initializes the filter descriptor with a block function.

 @param filterBlock The block function that is used to filter items.
 */
- (id)initWithBlock:(TKDataSourceFilterBlock)filterBlock;

/**
 Returns true if the specified item should remain in the filtered list.
 
 @param item The item to filter.
 */
- (BOOL)evaluate:(id)item;

@end
