//
//  TKChartViewAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartPointAnnotation.h"

/**
 Represents an annotation that contains a view.
 */
@interface TKChartViewAnnotation : TKChartPointAnnotation

/**
 Initializes the annotation with a view.
 @param aView The view to display with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithView:(UIView*)aView X:(id)xValue Y:(id)yValue forSeries:(TKChartSeries*)series;

/**
 Initializes the annotation with a view.
 @param aView The view to display with this annotation.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithView:(UIView*)aView point:(id<TKChartData>)point forSeries:(TKChartSeries*)series;

/**
 Initializes the annotation with a view.
 @param aView The view to display with this annotation.
 */
- (id)initWithView:(UIView *)aView;

/**
 The annotation view.
 */
@property (nonatomic, strong) UIView *view;

@end
