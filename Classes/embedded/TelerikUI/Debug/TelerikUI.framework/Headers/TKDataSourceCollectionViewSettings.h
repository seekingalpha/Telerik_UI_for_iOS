//
//  TKDataSourceCollectionViewSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Defines a block function that is used when creating a new cell in UICollectionView when using it with TKDataSource.
 
 @param collectionView The collectionView.
 @param indexPath The index path for the cell.
 @param item The item associated with this cell.
 */
typedef UICollectionViewCell* (^TKDataSourceCollectionViewSettings_CreatrCellBlock)(UICollectionView *collectionView,
                                                                                    NSIndexPath *indexPath,
                                                                                    id item);

/**
 Defines a block function that is used when initializing cell properties in UICollectionView when using it with TKDataSource.
 
 @param collectionView The collectionView.
 @param indexPath The index path for the cell.
 @param cell The cell.
 @param item The item associated with this cell.
 */
typedef void (^TKDataSourceCollectionViewSettings_InitCellWithItemBlock)(UICollectionView *collectionView,
                                                                         NSIndexPath* indexPath,
                                                                         UICollectionViewCell *cell,
                                                                         id item);

/**
 The settings that can be customized when using TKDataSource with UICollectionView.
 */
@interface TKDataSourceCollectionViewSettings : NSObject

/**
 Defines a block function that is called when creating a new cell in UICollectionView. TKCollectionViewCell is used by default.
 
 @param cellIdForItem The block function that will be called when creating a new cell.
 */
- (void)createCell:(TKDataSourceCollectionViewSettings_CreatrCellBlock)cellIdForItem;

/**
 Defines a block function that is called when initializing the cell properties.
 
 @param initCellWithItem The block function that will be called when initializing a new cell.
 */
- (void)initCell:(TKDataSourceCollectionViewSettings_InitCellWithItemBlock)initCellWithItem;

@end
