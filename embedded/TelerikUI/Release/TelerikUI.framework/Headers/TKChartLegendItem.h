//
//  TKChartLegendItem.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKStackLayout.h"

@class TKChart;
@class TKChartShapeView;
@class TKChartSelectionInfo;
@class TKChartLegendItemStyle;

/**
 @discussion The legend item contained in TKChartLegendContainer class.
 */
@interface TKChartLegendItem : UIView

/**
 The view containing the icon of the legend item.
 @return The UIView representing the icon of the legend item.
 */
@property (nonatomic, strong) UIView *icon;

/**
 The label of the legend item.
 @return The UILabel representing the text of the legend item.
 */
@property (nonatomic, strong) UILabel *label;

/**
 The selection information object.
 @discussion When this parameter is provided and the user touches the legend item related series (and data points if specified) are selected.
 */
@property (nonatomic, strong) TKChartSelectionInfo *selectionInfo;

/**
 The legend item's style.
 */
@property (nonatomic, strong) TKChartLegendItemStyle *style;

/**
 The stack layout responsible for arranging the legend items
 */
@property (nonatomic, strong, readonly) TKStackLayout *stack;

/**
 Called when the item was touched.
 @param tapRecognizer The tap gesture recognizer.
 */
- (void)tap:(UITapGestureRecognizer*)tapRecognizer;

/**
 Updates legend item state when selection has changed.
 */
- (void)update;

@end


