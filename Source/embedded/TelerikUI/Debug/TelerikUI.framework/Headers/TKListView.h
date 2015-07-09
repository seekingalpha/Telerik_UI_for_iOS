//
//  TKListView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKListView;
@class TKListViewCell;
@class TKListViewReusableCell;
@class TKListViewPullToRefreshView;
@class TKListViewLoadOnDemandView;

#import "TKListViewLinearLayout.h"

/**
 This constant takes place in dequeing supplementary views for group headers.
 */
extern NSString *const TKListViewElementKindSectionHeader;

/**
 This constant takes place in dequeing supplementary views for group footers.
 */
extern NSString *const TKListViewElementKindSectionFooter;

/**
 @enum TKListViewSelectionBehavior
 @discussion Defines the selection behavior of TKListView.
 */
typedef NS_ENUM(NSInteger, TKListViewSelectionBehavior)
{
    /**
     No selection is allowed.
     */
    TKListViewSelectionBehaviorNone,
    /**
     Selection on press.
     */
    TKListViewSelectionBehaviorPress,
    /**
     Selection on long press.
     */
    TKListViewSelectionBehaviorLongPress,
};

/**
 The TKListViewDelegate protocol defines methods that allow you to manage the selection of items in TKListView, to perform actions on those items, and respond to interaction with those items.
 */
@protocol TKListViewDelegate <UIScrollViewDelegate>
@optional

/**
 * Returns a boolean value indicating whether the specified item should be highlighted.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be highlighted.
 
 @return YES if the item should be highlighted.
 */
- (BOOL)listView:(TKListView*)listView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 This method is called after highliting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the highlighted item.
 */
- (void)listView:(TKListView *)listView didHighlightItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 This method is called after unhighliting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the unhighlighted item.
 */
- (void)listView:(TKListView *)listView didUnhighlightItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Returns a boolean value indicating whether the specified item should be selected.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be selected.
 
 @return YES if the item should be selected.
 */
- (BOOL)listView:(TKListView *)listView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Returns a boolean value indicating whether the specified item should be deselected.
 @param listView The TKListView instance requesting this information.
 @param indexPath The index path of the item about to be deselected.
 
 @return YES if the item should be selected.
 */
- (BOOL)listView:(TKListView *)listView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 This method is called after selecting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the selected item.
 */
- (void)listView:(TKListView *)listView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 This method is called after deselecting an item.
 @param listView The TKListView instance.
 @param indexPath The index path of the deselected item.
 */
- (void)listView:(TKListView *)listView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 This method is called after reordering an item an item.
 @param listView The TKListView instance.
 @param originalIndexPath The index path we move the item from.
 @param targetIndexPath The index path we move the item to.
 */
- (void)listView:(TKListView *)listView didReorderItemFromIndexPath:(NSIndexPath *)originalIndexPath toIndexPath:(NSIndexPath *)targetIndexPath;

/**
 This method is called when the user starts swiping a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 */
- (BOOL)listView:(TKListView *)listView shouldSwipeCell:(TKListViewCell*)cell atIndexPath:(NSIndexPath*)indexPath;

/**
 This method is called when the user swipes a cell. This method is called after shouldSwipeCell and before didFinishSwipingCell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 @param offset The swipe offset.
 */
- (void)listView:(TKListView *)listView didSwipeCell:(TKListViewCell *)cell atIndexPath:(NSIndexPath*)indexPath withOffset:(CGPoint)offset;

/**
 This method is called after the user has finished swiping a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being swiped.
 @param indexPath The index path of the cell being swiped.
 @param offset The swipe offset.
 */
- (void)listView:(TKListView *)listView didFinishSwipeCell:(TKListViewCell *)cell atIndexPath:(NSIndexPath *)indexPath withOffset:(CGPoint)offset;

/**
 This method is called when the user pulls the list view to refresh its data.
 @param listView The TKListView instance.
 @param offset The pull offset.
 */
- (void)listView:(TKListView *)listView didPullWithOffset:(CGFloat)offset;

/**
 This method is called after the user long pressed a cell.
 @param listView The TKListView instance.
 @param cell The TKListViewCell instance being long pressed.
 @param indexPath The index path of the cell being long pressed.
 */
- (void)listView:(TKListView *)listView didLongPressCell:(TKListViewCell*) cell atIndexPath:(NSIndexPath*) indexPath;

/**
 Returns a boolean value indicating whether more data will be loaded.
 Called after the user requested loading more data on demand by scrolling over the cellBuffer limit size.
 @param listView The TKListView instance.
 @param indexPath The index path where the buffer limit size was reached.
 */
- (BOOL)listView:(TKListView *)listView shouldLoadMoreDataAtIndexPath:(NSIndexPath*) indexPath;

/**
 Returns a boolean value indicating whether listView should display activity indicator and wait for fresh data.
 Called after user performs pull-to-refresh gesture.
 @param listView The listview component instance requesting the fresh data.
 */
- (BOOL)listViewShouldRefreshOnPull:(TKListView *)listView;


@end

/**
 A delegate class exposing mothods to provide cells and supplementary views matching the source data.
 */
@protocol TKListViewDataSource <NSObject>
@required

/**
 Returns the number of items conatined in specific section.
 @param listView The TKListView instance requesting the information.
 @param section The index for the section.
 */
- (NSInteger)listView:(TKListView *)listView numberOfItemsInSection:(NSInteger)section;


/**
 Returns a TKListViewCell instance for a given index path.
 The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
 @param listView The TKListView instance requesting the cell.
 @param indexPath The index path we need a cell for.
 */
- (TKListViewCell *)listView:(TKListView *)listView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional

/**
 Returns the number of sections.
 @param listView The TKListView instance requesting the cell.
 */
- (NSInteger)numberOfSectionsInListView:(TKListView *)listView;

/**
 Returns a view to be used as a section header or footer in TKListView.
 The cell that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
 @param listView The TKListView instance requesting the cell.
 @param kind The kind of the supplementary view e.g. TKListViewElementKindSectionHeader or TKListViewElementKindSectionFooter
 @param indexPath The index path we need a cell for.
 */
- (TKListViewReusableCell *)listView:(TKListView *)listView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

@end

/**
 @discussion TKListView provides means for displaying lists of data. The items of the list can be arranged in a columns layout or wrap layout. It provides UI virtualization, pull-to-refresh, load-on-demand, cells swipe, cell reorder, single/multiple selection, grouping.
 */
@interface TKListView : UIView <UICollectionViewDataSource, UICollectionViewDelegate>

/**
 A delegate used to manage the selection of items in TKListView, perform actions on those items and respond to interaction with those items.
 */
@property (nonatomic, weak) id<TKListViewDelegate> delegate;

/**
 A datasource delegate used to provide data for the cells, headers and footers.
 */
@property (nonatomic, weak) id<TKListViewDataSource> dataSource;

/**
 The layout object used to arrange cells.
 */
@property (nonatomic, strong) UICollectionViewLayout *layout;

/**
 Indicates whether user is able to select multiple items.
 */
@property (nonatomic) BOOL allowsMultipleSelection;

/**
 Indicates whether user is able to reorder cells.
 */
@property (nonatomic) BOOL allowsCellReorder;

/**
 Indicates whether the end-user is able to swipe cells.
 */
@property (nonatomic) BOOL allowsCellSwipe;

/**
 Indicates whether user is able to perform the pull-to-refresh gesture.
 */
@property (nonatomic) BOOL allowsPullToRefresh;

/**
 The maximum distance a cell can be swiped by the end-user.
 */
@property (nonatomic) UIEdgeInsets cellSwipeLimits;

/**
 The cell swipe treshold - the distance defining whether the cell will revert to original position or animate to the swipe limits if the end-user does not finish the swipe gesture.
 */
@property (nonatomic) CGFloat cellSwipeTreshold;

/**
 The cell swipe animation duration.
 */
@property (nonatomic) CGFloat cellSwipeAnimationDuration;

/**
 The distance from the edge where autoscroll commences while dragging/reordering a cell.
 */
@property (nonatomic) CGFloat autoScrollTreshold;

/**
 The pull distance at which pull-to-refresh activates.
 */
@property (nonatomic) CGFloat pullToRefreshTreshold;

/**
 Defines the number of cells from the bottom of TKListView up at which to start requesting load-on-demand data.
 Default is zero which means that no data will be loaded on demand.
 */
@property (nonatomic) NSInteger cellBufferSize;

/**
 The content insets relative to its view size.
 */
@property (nonatomic) UIEdgeInsets contentInset;

/**
 The content offset.
 */
@property (nonatomic) CGPoint contentOffset;

/**
 Defines the scroll direction. Applicable if the current layout supports it.
 */
@property (nonatomic) TKListViewScrollDirection scrollDirection;

/**
 Defines whether cells are selected on press, long press, or can't be selected at all.
 */
@property (nonatomic) TKListViewSelectionBehavior selectionBehavior;

/**
 The UIView containing the activity indicator while TKListView is refreshing data after the pull-to-refresh gesture.
 */
@property (nonatomic, strong) TKListViewPullToRefreshView *pullToRefreshView;

/**
 The UIView containing the activity indicator while TKListView is loading data on demand and has scrolled to the end of the content size.
 */
@property (nonatomic, strong) TKListViewLoadOnDemandView *loadOnDemandView;

/**
 A view that will be automatically resized to track the size of the collection view and placed behind all cells and supplementary views.
 */
@property (nonatomic, retain) UIView *backgroundView;

/**
 Reloads all data.
 */
- (void)reloadData;

/**
 Returns an array with the index paths of the selected items.
 */
- (NSArray *)indexPathsForSelectedItems;

/**
 Deselects all selected items.
 */
- (void)clearSelectedItems;

/**
 Selects an item at the given index path.
 @param indexPath The index path of the item to select.
 @param animated Determines whether to animate the selection.
 @param scrollPosition The scroll position.
 */
- (void)selectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;

/**
 Deselects an item at the given index path.
 @param indexPath The index path of the item to deselect.
 @param animated Determines whether to animate the selection.
 */
- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

/**
 Returns a TKListVIewCell to be provided in the listView:cellForItemAtIndexPath:ndexPath delegate method.
 
 @param identifier A string identifier of the cell type.
 @param indexPath The index path of the item we need a cell for.
 */
- (id)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;

/**
 Returns a header or footer view to be provided in the listView:viewForSupplementaryElementOfKind:atIndexPath:
 
 @param elementKind The element kind - header or footer.
 @param identifier A string identifier of the view type.
 @param indexPath The index path of the supplementary view.
 */
- (id)dequeueReusableSupplementaryViewOfKind:(NSString*)elementKind withReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath*)indexPath;

/**
 Registers a class to be used to represent cells in listview.
 @param cellClass The class of the UIView to represent a cell.
 @param identifier A string identifier of the cell type.
 */
- (void)registerClass:(Class)cellClass forCellWithReuseIdentifier:(NSString *)identifier;

/**
 Registers a class to be used to represent headers and footers.
 @param viewClass The class of the UIView to represent a header or footer
 @param elementKind The element kind - header or footer.
 @param identifier A string identifier of the supplementary view type.
 */
- (void)registerClass:(Class)viewClass forSupplementaryViewOfKind:(NSString *)elementKind withReuseIdentifier:(NSString *)identifier;

/**
 Returns the visible cell object at the specified index path.
 @param indexPath The index path for the cell.
 */
- (TKListViewCell*)cellForItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 Inserts new items at the specified index paths.
 @param indexPaths The index paths of the newly inserted items.
 */
- (void)insertItemsAtIndexPaths:(NSArray *)indexPaths;

/**
 Moves an item from one location to another in the list view.
 @param indexPath The old index path.
 @param newIndexPath The new index path.
 */
- (void)moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;

/**
 Deletes the items at the specified index paths.
 @param indexPaths The index paths of the deleted items.
 */
- (void)deleteItemsAtIndexPaths:(NSArray *)indexPaths;

/**
 Reloads the items at the specified index paths.
 @param indexPaths The index paths of items to reload.
 */
- (void)reloadItemsAtIndexPaths:(NSArray *)indexPaths;

/**
 Allows multiple insert/delete/reload/move calls to be animated.
 @param updates The updates to apply.
 @param completion Will be executed upon completion.
 */
- (void)performBatchUpdates:(void (^)(void))updates completion:(void (^)(BOOL finished))completion;

/**
 Returns the number of sections.
 */
- (NSInteger)numberOfSections;

/**
 Returns the number of items conatined in specific section.
 @param section The index of the section.
 */
- (NSInteger)numberOfItemsInSection:(NSInteger)section;

/**
 Returns the number for currently visible cells.
 */
- (NSArray *)visibleCells;

/**
 Returns the index paths for the currently visible cells.
 */
- (NSArray *)indexPathsForVisibleItems;

/**
 Returns the index path for the item at the specified location.
 @param point The point where the item is located.
 */
- (NSIndexPath *)indexPathForItemAtPoint:(CGPoint)point;

/**
 Returns the index path for specific cell.
 @param cell The cell.
 */
- (NSIndexPath *)indexPathForCell:(UICollectionViewCell *)cell;

/**
 Scrolls to specific item.
 @param indexPath The index path for the item.
 @param scrollPosition The scroll position.
 @param animated Determines whether to animate the scrolling.
 */
- (void)scrollToItemAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UICollectionViewScrollPosition)scrollPosition animated:(BOOL)animated;

/**
 Notifies the list view that a new data requested on demand is ready to be shown.
 */
- (void)didLoadDataOnDemand;

/*
 Notifies the list view that a fresh data is available after a pull-to-refresh gesture takes place.
 */
- (void)didRefreshOnPull;

@end
