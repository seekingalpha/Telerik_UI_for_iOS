//
//  TKChartPointAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"
#import "TKChartData.h"

@class TKChartAxis;
@class TKChartSeries;

/**
  Represents a base class for coordinate based annotations
 */
@interface TKChartPointAnnotation : TKChartAnnotation

/**
 Initializes the annotation by using coordinates.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithX:(id)xValue Y:(id)yValue forSeries:(TKChartSeries*)series;

/**
 Initializes the annotation by using coordinates.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithPoint:(id<TKChartData>)point forSeries:(TKChartSeries*)series;

/**
 Returns the plot coordinates of this annotation whithin the specified bounds.
 @param bounds the bounds which define the final coordinates.
 */
- (CGPoint)locationInRect:(CGRect)bounds;

/**
 The TKChartSeries associated with the annotation.
 */
@property (nonatomic, strong) TKChartSeries *series;

/**
 The annotation position.
 */
@property (nonatomic, strong) id<TKChartData> position;

/**
 An offset which is applied to annotation coordinates when calling the locationInRect: method.
 */
@property (nonatomic, assign) UIOffset offset;

@end

