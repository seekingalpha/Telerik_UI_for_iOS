//
//  StackLayout.h
//  TestLayout
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKLayout.h"

/**
 @enum TKStackLayoutOrientation
 @discussion Defines whether the stack layout should arrange its subviews horiontally or vertically.
 */
typedef NS_ENUM(NSInteger, TKStackLayoutOrientation) {
    /**
     Items should be arranged horizontally.
    */
    TKStackLayoutOrientationHorizontal,
    /**
     Items should be arranged vertically.
    */
    TKStackLayoutOrientationVertical
};

/**
 @enum TKStackLayoutItemOrder
 @discussion Defines whether to reverse the order in which subviews are arranged.
 */
typedef NS_ENUM(NSInteger, TKStackLayoutItemOrder) {
    /**
     Items should be arranged in the same order they are added in the stack.
    */
    TKStackLayoutItemOrderNormal,
    /**
     Items should be arranged in reverse order.
    */
    TKStackLayoutItemOrderReverse
};

/**
 @discussion A class that is able to arrange subviews in a stack layout.
 */
@interface TKStackLayout : NSObject<TKLayout, NSFastEnumeration>

/**
 The layout orientation. It can be horizontal or vertical.

 @discussion The stack layout orientations are defined as follows:

    typedef enum {
        TKStackLayoutOrientationHorizontal,     // Items should be arranged horizontally.
        TKStackLayoutOrientationVertical        // Items should be arranged vertically.
    } TKStackLayoutOrientation;

 */
@property (nonatomic, assign) TKStackLayoutOrientation orientation;

/**
 The layout order. It can be normal or reversed.
 
 @discussion The stack layout item orders are defined as follows:

    typedef enum {
        TKStackLayoutItemOrderNormal,       // Items should be arranged in the same order they are added in the stack.
        TKStackLayoutItemOrderReverse       // Items should be arranged in reverse order.
    } TKStackLayoutItemOrder;

 */
@property (nonatomic, assign) TKStackLayoutItemOrder itemOrder;

/**
 A value that defines the spacing between the subviews.
 */
@property (nonatomic, assign) CGFloat itemSpacing;

/**
 The alignment mode that will be used when arranging the view.
 */
@property TKLayoutAlignmentMode alignmentMode;

/**
 The streching mode that will be used when arranging the view.
 */
@property TKLayoutStretchMode stretchMode;

/**
 Adds a new stack layout item to the stack. This method does not add a subview to a superview. The developer should do this explicitly.
 @param item The item to be added.
 @return YES if successfull.
 */
- (BOOL)addItem:(id<TKLayout>)item;

/**
 Inserts a new item at a specified position in the stack. This method does not add a subview to a superview. The developer should do this explicitly.
 @param item The item to be inserted.
 @param index The index at which the item will be inserted.
 @return YES if successfull.
 */
- (BOOL)insertItem:(id<TKLayout>)item atIndex:(NSUInteger)index;

/**
 Removes an item from the stack.
 @param item The item to be removed.
 @return YES if successfull.
 */
- (BOOL)removeItem:(id<TKLayout>)item;

/**
 Removes an item from the stack.
 @param index The index of the item to be removed.
 @return YES if successfull.
 */
-(BOOL)removeItemAtIndex:(NSUInteger)index;

/** 
 Removes all items from the stack. This method does not remove subviews from their superview.
 */
- (void)removeAllItems;

/**
 Gets an item at a specific index.
 @param index The index of the item.
 @return An instance of TKStackLayoutItem if successfull.
 */
- (id<TKLayout>)itemAtIndex:(NSUInteger)index;

/**
 Gets the index of specific item.
 @param layoutItem The item.
 @return The item index if successfull.
 */
- (NSInteger)indexOfItem:(id<TKLayout>)layoutItem;

/**
 The last item in the layout
 @returns The last item in the layout
 */
- (id<TKLayout>)lastItem;

/**
 The items count.
 @returns The items count.
 */
- (NSInteger)count;

@end
