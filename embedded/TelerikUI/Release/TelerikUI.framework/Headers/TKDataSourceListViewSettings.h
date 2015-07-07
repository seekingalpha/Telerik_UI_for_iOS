//
//  TKDataSourceListViewSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKListView;
@class TKListViewCell;
@class TKDataSource;
@class TKDataSourceGroup;
@class TKListViewReusableCell;
@class TKListViewHeaderCell;
@class TKListViewFooterCell;

/**
 Defines a block function that is used when creating a new cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param item The item associated with this cell.
 */
typedef TKListViewCell* (^TKDataSourceListViewSettings_CreateCellItemBlock)(TKListView *listView, NSIndexPath *indexPath, id item);

/**
 Defines a block function that is used when initializing cell properties in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param cell The cell.
 @param item The item associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitCellWithItemBlock)(TKListView *listView, NSIndexPath *indexPath, TKListViewCell *cell, id item);

/**
 Defines a block function that is used when creating a supplementaty view cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param kind The cell kind.
 @param group The group associated with this cell.
 */
typedef TKListViewReusableCell* (^TKDataSourceListViewSettings_CreateViewBlock)(TKListView *listView, NSIndexPath *indexPath, NSString *kind, TKDataSourceGroup* group);

/**
 Defines a block function that is used when initializing a header cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param headerCell The cell.
 @param group The group associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitHeaderCellWithItemBlock)(TKListView *listView,
                                                                         NSIndexPath *indexPath,
                                                                         TKListViewHeaderCell *headerCell,
                                                                         TKDataSourceGroup *group);

/**
 Defines a block function that is used when initializing a footer cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param footerCell The cell.
 @param group The group associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitFooterCellWithItemBlock)(TKListView *listView,
                                                                         NSIndexPath *indexPath,
                                                                         TKListViewFooterCell *footerCell,
                                                                         TKDataSourceGroup *group);

/**
 The settings that can be customized when using TKDataSource with TKListView.
 */
@interface TKDataSourceListViewSettings : NSObject

/**
 A block function that is called when creating a new cell in TKListView.
 
 @param createCellBlock The block method that will be called.
 */
- (void)createCell:(TKDataSourceListViewSettings_CreateCellItemBlock)createCellBlock;

/**
 A block function that is called when initializing the cell properties.

 @param initCellBlock The block method that will be called.
 */
- (void)initCell:(TKDataSourceListViewSettings_InitCellWithItemBlock)initCellBlock;

/**
 A block function that is called when creating a supplementary view in TKListView.

 @param createViewBlock The block method that will be called.
 */
- (void)createSupplementaryView:(TKDataSourceListViewSettings_CreateViewBlock)createViewBlock;

/**
 A block function that is called when initializing a header cell in TKListView.
 
 @param initHeaderBlock The block method that will be called.
 */
- (void)initHeader:(TKDataSourceListViewSettings_InitHeaderCellWithItemBlock)initHeaderBlock;

/**
 A block function that is called when initializing a footer cell in TKListView.
 
 @param initFooterBlock The block method that will be called.
 */
- (void)initFooter:(TKDataSourceListViewSettings_InitFooterCellWithItemBlock)initFooterBlock;

@end
