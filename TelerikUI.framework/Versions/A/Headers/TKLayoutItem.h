//
//  TKLayoutItem.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKLayout.h"

/**
 @enum TKLayoutSizingMode
 @discussion Defines the different sizing modes that can be used when arranging sub views in TKStackLayout.
 */
typedef NS_ENUM(NSInteger, TKLayoutSizingMode) {
    /**
     The stack layout will not change the size for the subview. It will change only the frame origin.
     */
    TKLayoutSizingModeFixed,
    /**
     The stack layout will use the sizeThatFits method to determine the desired size for the subview.
     */
    TKLayoutSizingModeFit,
};

@class TKStackLayout;

/**
 Represents a base layout item that is used in TKStakLayout class.
 */
@interface TKLayoutItem: NSObject<TKLayout>

/**
 Initializes the class and associates it with a view.
 @param aView The view to be associated with this layout item.
 @return An instance of the class, if successfull.
 */
-(id)initWithView:(UIView*)aView;

/**
 Initializes the class and associates it with a view.
 @param aLayer The layer to be associated with this layout item.
 @return An instance of the class, if successfull.
 */
-(id)initWithLayer:(CALayer*)aLayer;

/**
 Initializes the class and associates it with a view.
 @param aLayout The layout to be associated with this layout item.
 @return An instance of the class, if successfull.
 */
-(id)initWithLayout:(id<TKLayout>)aLayout;

/**
 Returns the item persisted in this class. It can be a view, a layer or any object implementing the TKLayout interface.
 */
-(id)content;

/**
 This method is being called when the item is removed from its owner layout.
 */
-(void)itemWasRemoved;

/**
 The sizing mode that will be used when arranging the view.

 @discussion The layout sizing modes are defined as follows:
 
    typedef enum {
        TKLayoutSizingModeFixed,    // The stack layout will not change the size for the subview. It will change only the frame origin.
        TKLayoutSizingModeFit,      // The stack layout will use the sizeThatFits method to determine the desired size for the subview.
    } TKLayoutSizingMode;

 */
@property TKLayoutSizingMode sizingMode;

/**
 The streching mode that will be used when arranging the view.
 */
@property TKLayoutStretchMode stretchMode;

/**
 The alignment mode that will be used when arranging the view.
 */
@property TKLayoutAlignmentMode alignmentMode;

/**
 The margin that will be used when arranging the view.
 */
@property UIEdgeInsets margin;

@end
