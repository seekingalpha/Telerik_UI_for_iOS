//
//  TKDataSource.h
//  TestDataSource
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChart.h"
#import "TKCalendar.h"
#import "TKListView.h"

@class TKDataSourceSettings;
@class TKDataSourceGroup;
@class TKDataSourceSortDescriptor;
@class TKDataSourceFilterDescriptor;
@class TKDataSourceGroupDescriptor;



/**
 * @enum TKDataSourceDataFormat
 * @discussion Represents an enum that defines the format of the data that can be parsed by TKDataSource.
 */
typedef NS_ENUM(NSInteger, TKDataSourceDataFormat) {
    /**
     The data is in JSON format.
     */
    TKDataSourceDataFormatJSON,
};



/**
 Defines a block that is used when evaluating the text for an item in TKDataSource.
 
 @param item The item that is evaluated.
 @param group The group which owns this item. Can be nil if no grouping is applied.
 */
typedef NSString* (^TKDataSourceFormatTextBlock)(id item, TKDataSourceGroup *group);

/**
 Defines a block that is used when enumerating items in TKDataSource.
 
 @param item The current item.
 */
typedef void (^TKDataSourceEnumerator)(id item);

/**
 Defines a block that is used when mapping the items in TKDataSource.
 
 @param item The current item that is mapped.
 */
typedef id (^TKDataSourceMapFunctionBlock)(id item);

/**
 Defines a block that is used when reducing the items in TKDataSource to a single value.
 
 @param item The item that is reduced.
 @param value The current value.
 */
typedef id (^TKDataSourceReduceFunctionBlock)(id item, id value);

/**
 Defines a block that is used when filtering items in TKDataSource.
 
 @param item The item that is tested.
 */
typedef BOOL (^TKDataSourceFilterBlock)(id item);



/**
 @discussion TKDataSource is an adapter that consumes data from various sources and has functionality for data manipulations. It implements various data source protocols and can be used as a data source for TKChart, TKCalendar, TKListView, UITableView and UICollectionView.
 */
@interface TKDataSource : NSObject <UITableViewDataSource,
                                    UITableViewDelegate,
                                    UICollectionViewDataSource,
                                    UICollectionViewDelegate,
                                    TKChartDataSource,
                                    TKChartDelegate,
                                    TKCalendarDataSource,
                                    TKCalendarDelegate,
                                    TKListViewDataSource,
                                    TKListViewDelegate>



#pragma mark - Properties

/**
 The item source for this class. It can be a simple array with value types, complex objects or a dictionary.
 */
@property (nonatomic, strong) id itemSource;

/**
 An array view of the items contained in the itemSource after applying sorting, grouping and filtering operations.
 */
@property (nonatomic, readonly) NSArray *items;

/**
 The current item. It is syncronized among all consumers of this class.
 */
@property (nonatomic, weak) id currentItem;

/**
 The display key used when extracting text from a single item.
 */
@property (nonatomic, copy) NSString *displayKey;

/**
 The value key used when extracting a value from a single item.
 */
@property (nonatomic, copy) NSString *valueKey;

/**
 The key used to extract items for specific group when grouping is applied. The key path is relative to the group object.
 */
@property (nonatomic, copy) NSString *groupItemSourceKey;

/**
 Provides the ability to customize the appearance of TKDataSource consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@property (nonatomic, strong) TKDataSourceSettings *settings;

/**
 A formatted that is applied when extracting text from an item by using the displayKey property.
 */
@property (nonatomic, strong) NSFormatter *formatter;

/**
 Determines whether items reordering is allowed or not.
 */
@property (nonatomic, assign) BOOL allowItemsReorder;

#pragma mark - Initialization

/**
 Initializes the data source with a value for the itemSource property.

 @param itemSource The value for the itemSource property.
 */
- (id)initWithItemSource:(id)itemSource;

/**
 Initializes the data source with an array of items.
 
 @param items The array that is assigned to the itemSource property.
 */
- (id)initWithArray:(NSArray*)items;

/**
 Initializes the data source with an array of items and parameters.
 
 @param items The array that is assigned to the itemSource property.
 @param displayKey The display key to use.
 */
- (id)initWithArray:(NSArray*)items displayKey:(NSString*)displayKey;

/**
 Initializes the data source with an array of items and parameters.
 
 @param items The array that is assigned to the itemSource property.
 @param displayKey The display key to use.
 @param valueKey The value key to use.
 */
- (id)initWithArray:(NSArray*)items displayKey:(NSString*)displayKey valueKey:(NSString*)valueKey;

/**
 Initializes the data source with a JSON formatted string.

 @param str The string containing JSON formatted data.
 */
- (id)initWithJSONString:(NSString *)str;

/**
 Initializes the data source with data coming from a web service.

 @param url The url where the data is located.
 @param dataFormat The format of the data coming from the web service.
 @param rootItemKeyPath The key path to the item containing the items collection that will be used in this data source.
 @param completion The block that is called after the data is loaded.
 */
- (id)initWithDataFromURL:(NSString*)url
               dataFormat:(TKDataSourceDataFormat)dataFormat
          rootItemKeyPath:(NSString*)rootItemKeyPath
               completion:(void (^)(NSError *error))completion;

/**
 Initializes the data source with data coming from a JSON formatted resource.
 
 @param name The file name.
 @param type The file type.
 @param rootItemKeyPath The key path to the item containing the items collection that will be used in this data source.
 */
- (id)initWithDataFromJSONResource:(NSString *)name
                            ofType:(NSString*)type
                   rootItemKeyPath:(NSString*)rootItemKeyPath;

/**
 Reads a JSON formatted string and loads the parsed data in the data source.

 @param string The string containing JSON formatted data.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 */
- (void)loadDataFromJSONString:(NSString*)string rootItemKeyPath:(NSString*)rootItemKeyPath;

/**
 Reads a JSON formatted resource and loads the parsed data in the data source.
 
 @param name The file name.
 @param type The file type.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 */
- (void)loadDataFromJSONResource:(NSString *)name ofType:(NSString*)type rootItemKeyPath:(NSString*)rootItemKeyPath;

/**
 Downloads data from a web service and initializes the data source with it.

 @param url The url where the data is located.
 @param dataFormat The format of the data coming from the web service.
 @param rootItemKeyPath The key path to the item containing the items collection that is used in this data source.
 @param completion A block that is called after the data is loaded.
 */
- (void)loadDataFromURL:(NSString*)url
             dataFormat:(TKDataSourceDataFormat)dataFormat
        rootItemKeyPath:(NSString*)rootItemKeyPath
             completion:(void (^)(NSError *error))completion;



#pragma mark - Descriptors

/**
 Returns a list with filter descriptors that is applied after the itemSource propety is set.
 */
- (NSArray*)filterDescriptors;

/**
 Adds a new filter descriptor.

 @param filterDescriptor The filter descriptor to add.
 */
- (void)addFilterDescriptor:(TKDataSourceFilterDescriptor*)filterDescriptor;

/**
 Removes a filter descriptor.

 @param filterDescriptor The filter descriptor to remove.
 */
- (void)removeFilterDescriptor:(TKDataSourceFilterDescriptor*)filterDescriptor;

/**
 Removes all filter descriptors.
 */
- (void)removeAllFilterDescriptors;

/**
 Returns a list with sort descriptors that is applied after the itemSource propety is set.
 */
- (NSArray*)sortDescriptors;

/**
 Adds a new sort descriptor.
 
 @param sortDescriptor The sort descriptor to add.
 */
- (void)addSortDescriptor:(TKDataSourceSortDescriptor*)sortDescriptor;

/** 
 Removes a sort descriptor.
 
 @param sortDescriptor The sort descriptor to remove.
 */
- (void)removeSortDescriptor:(TKDataSourceSortDescriptor*)sortDescriptor;

/**
 Removes all sort descriptors.
 */
- (void)removeAllSortDescriptors;

/**
 Returns a list with group descriptors that will be applied when the itemSource propety is set.
 */
- (NSArray*)groupDescriptors;

/**
 Adds a new group descriptor.
 
 @param groupDescriptor The group descriptor to be added.
 */
- (void)addGroupDescriptor:(TKDataSourceGroupDescriptor*)groupDescriptor;

/**
 Removes a group descriptor.
 
 @param groupDescriptor The group descriptor to remove.
 */
- (void)removeGroupDescriptor:(TKDataSourceGroupDescriptor*)groupDescriptor;

/**
 Removes all group descriptors.
 */
- (void)removeAllGroupDescriptors;

/**
 Reloads the data and applies again all descriptors. Call this method when the data has changed.
 */
- (void)reloadData;



#pragma mark - Data operations

/**
 Apples the specified block to all items in the data source and allows changing their values.

 @param mapBlock The block function that is applied to all items.
 */
- (void)map:(TKDataSourceMapFunctionBlock)mapBlock;

/**
 Enumerates all items in the data source.
 
 @param enumeratorBlock The block function that is called when enumerating data source items.
 */
- (void)enumerate:(TKDataSourceEnumerator)enumeratorBlock;

/**
 Reduces the items collection to a single value and returns it.
 
 @param initialValue The value to start with.
 @param reduceBlock The block function that is called when reducing the items collection.
 */
- (id)reduce:(id)initialValue with:(TKDataSourceReduceFunctionBlock)reduceBlock;

/**
 Filters the items in the data source.
 
 @param filterBlock The block function that is used when filtering.
 */
- (void)filter:(TKDataSourceFilterBlock)filterBlock;

/**
 Filters the items in the data source by using a query.
 
 @param filterQuery The filter query that is used to filter the items.
 */
- (void)filterWithQuery:(NSString*)filterQuery;

/**
 Sorts the items in the data source.
 
 @param comparatorBlock The comparator block function that is used when sorting.
 */
- (void)sort:(NSComparator)comparatorBlock;

/**
 Sorts the items in the data source by using a property name.
 
 @param propertyName The property that is used to sort the items.
 @param ascending The sort direction.
 */
- (void)sortWithKey:(NSString*)propertyName ascending:(BOOL)ascending;

/**
 Groups the items in the data source.
 
 @param keyForItem The group block function that is used to get a group key.
 */
- (void)group:(TKDataSourceMapFunctionBlock)keyForItem;

/**
 Groups the items in the data source by using a property name.
 
 @param propertyName The property that is used to group the items.
 */
- (void)groupWithKey:(NSString*)propertyName;


#pragma mark - Methods

/**
 Moves an item. This method is applicable only when grouping is not applied.
 
 @param fromIndex The old item index.
 @param toIndex The new item index.
 */
- (void)moveItemAtIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/**
 Returns the value of an item. Uses the valueKey property.
 
 @param item The item.
 @param group The group which owns this item. Can be nil if there is no grouping applied.
 */
- (id)valueForItem:(id)item inGroup:(TKDataSourceGroup*)group;

/**
 Returns the text for the item. Uses the displayKey property.
 
 @param item The item.
 @param group The group which owns this item. Can be nil if there is no grouping applied.
 */
- (NSString*)textFromItem:(id)item inGroup:(TKDataSourceGroup*)group;

/**
 Defines a textblock that is applied to get the text from an item when calling the textForItem method if specified.
 
 @param  formatTextBlock The block function that gets text from an item.
 */
- (void)formatText:(TKDataSourceFormatTextBlock)formatTextBlock;

@end
