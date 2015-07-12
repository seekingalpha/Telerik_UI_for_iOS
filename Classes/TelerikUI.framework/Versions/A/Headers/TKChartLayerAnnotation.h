//
//  TKChartLayerAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartPointAnnotation.h"

@class TKChartAxis;

/**
 Represents an annotation that contains a layer.
 */
@interface TKChartLayerAnnotation : TKChartPointAnnotation

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param xValue The X coordinate of the annotation.
 @param yValue The Y coordinate of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithLayer:(CALayer*)layer X:(id)xValue Y:(id)yValue forSeries:(TKChartSeries*)series;

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 @param point The location of the annotation.
 @param series The TKChartSeries instance to use with these coordinates.
 */
- (id)initWithLayer:(CALayer *)layer point:(id<TKChartData>)point forSeries:(TKChartSeries *)series;

/**
 Initializes the annotation with a layer.
 @param layer The layer to display with this annotation.
 */
- (id)initWithLayer:(CALayer *)layer;

/**
 The annotation layer.
 */
@property (nonatomic, strong) CALayer *layer;

@end
