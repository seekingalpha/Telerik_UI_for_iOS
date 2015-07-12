//
//  TKListViewLinearLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 @enum TKListViewScrollDirection
 @discussion Defines the scroll direction.
 */
typedef NS_ENUM(NSInteger, TKListViewScrollDirection)
{
    /**
     Vertical scroll direction.
     */
    TKListViewScrollDirectionVertical,
    /**
     Horizontal scroll direction.
     */
    TKListViewScrollDirectionHorizontal
};

/**
 @enum TKListViewItemAlignment
 @discussion Defines the cell alignment when using columns layout.
 */
typedef NS_ENUM(NSInteger, TKListViewItemAlignment)
{
    /**
     Visually stretch items.
     */
    TKListViewItemAlignmentStretch   = 0,
    /**
     Visually left align items.
     */
    TKListViewItemAlignmentLeft      = 1,
    /**
     Visually center items.
     */
    TKListViewItemAlignmentCenter    = 2,
    /**
     Visually right align items.
     */
    TKListViewItemAlignmentRight     = 3,
};

typedef NS_ENUM(NSInteger, TKListViewItemAnimation)
{
    TKListViewItemAnimationDefault,
  
    TKListViewItemAnimationFade,
    
    TKListViewItemAnimationScale,
    
    TKListViewItemAnimationSlide
};

/**
 A base layout used to render cells in TKListView.
 */
@interface TKListViewLinearLayout : UICollectionViewLayout

/**
 The scroll direction.
 */
@property (nonatomic) TKListViewScrollDirection scrollDirection;

@property (nonatomic) TKListViewItemAnimation itemInsertAnimation;

@property (nonatomic) TKListViewItemAnimation itemDeleteAnimation;

@property (nonatomic) TKListViewItemAnimation itemAppearAnimation;

@property (nonatomic) CGFloat animationDuration;

/**
 The desired cell alignment within a column.
 */
@property (nonatomic) TKListViewItemAlignment itemAlignment;

/**
 The spacing between items.
 */
@property (nonatomic) CGFloat itemSpacing;

/**
 The item size. 
 */
@property (nonatomic) CGSize itemSize;

/**
 The header reference size.
 */
@property (nonatomic) CGSize headerReferenceSize;

/**
 The footer reference size.
 */
@property (nonatomic) CGSize footerReferenceSize;

@end
