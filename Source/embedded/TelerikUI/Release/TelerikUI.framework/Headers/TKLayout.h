//
//  TKLayout.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @enum TKLayoutStretchMode
 @discussion Defines the different stretching modes that can be used when arranging subviews in TKStackLayout.
 */
typedef NS_ENUM(NSInteger, TKLayoutStretchMode) {
    /**
     The subview should not stretch.
     */
    TKLayoutStretchModeNone = 0,
    /**
     The subview should stretch horizontally and occupy the available area.
     */
    TKLayoutStretchModeHorizontal = 1,
    /**
     The subview should stretch vertically and occupy the avaialable area.
     */
    TKLayoutStretchModeVertical = 2
};

/**
 @enum TKLayoutAlignmentMode
 @discussion Defines the different alignment modes that can be used when arranging subviews in TKStackLayout.
 */
typedef NS_OPTIONS(NSInteger, TKLayoutAlignmentMode) {
    /**
     The subview should be aligned to the left.
     */
    TKLayoutAlignmentModeLeft = 1,
    /**
     The subview should be aligned to the right.
     */
    TKLayoutAlignmentModeTop  = 2,
    /**
     The subview should be aligned to the top.
     */
    TKLayoutAlignmentModeRight = 4,
    /**
     The subview should be aligned to the bottom.
     */
    TKLayoutAlignmentModeBottom = 8,
    /**
     The subview should be centered horizontally.
     */
    TKLayoutAlignmentModeHorizontalCenter = 16,
    /**
     The subview should be centered vertically.
     */
    TKLayoutAlignmentModeVerticalCenter = 32
};

/**
 Represents layouting information used by layout managers
 */
@protocol TKLayout <NSObject>

/**
 Measures the size required by the layout item by using the provided size as a constraint.
 @param size The available size that could be used when arranging this item.
 @return The desired size that is required by this item.
 */
-(CGSize)measure:(CGSize)size;

/**
 Lays out the item within the provided rectangle.
 @param rect The rectangle that is provided to this item for arrange.
 */
-(void)arrange:(CGRect)rect;

@property (nonatomic,readonly) CGSize desiredSize;

@optional

/**
 The alignment mode that will be used when arranging the view.

 @discussion The alignment modes are defined as follows:
 
    typedef enum {
        TKLayoutAlignmentModeLeft = 1,              // The subview should be aligned to the left.
        TKLayoutAlignmentModeTop  = 2,              // The subview should be aligned to the right.
        TKLayoutAlignmentModeRight = 4,             // The subview should be aligned to the top.
        TKLayoutAlignmentModeBottom = 8,            // The subview should be aligned to the bottom.
        TKLayoutAlignmentModeHorizontalCenter = 16, // The subview should be centered horizontally.
        TKLayoutAlignmentModeVerticalCenter = 32    // The subview should be centered vertically.
    } TKLayoutAlignmentMode;

 */
@property TKLayoutAlignmentMode alignmentMode;

/**
 The streching mode that will be used when arranging the view.
 
 @discussion The stretch modes are defined as follows:
 
    typedef enum {
        TKLayoutStretchModeNone = 0,        // The subview should not stretch.
        TKLayoutStretchModeHorizontal = 1,  // The subview should stretch horizontally and occupy the available area.
        TKLayoutStretchModeVertical = 2     // The subview should stretch vertically and occupy the avaialable area.
    } TKLayoutStretchMode;

 */
@property TKLayoutStretchMode stretchMode;

/**
 This method is being called when the item is removed from its owner layout.
 */
-(void)itemWasRemoved;

/**
 This method is being called when the item is added to a layout.
 @param layout The layout to which this item is being added.
 */
-(void)itemWasAddedInLayout:(id<TKLayout>)layout;

@end

