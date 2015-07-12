
//
//  TKChartSeriesRender.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartRender.h"

@class TKChartAxis;
@class TKChartSeries;
@class TKChartVisualPoint;
@class TKMutableArray;
@class TKChartSelectionInfo;

@protocol TKChartData;

/**
 @discussion Represents a class that renders stacked series.
 */
@interface TKChartSeriesRender : TKChartRender

/**
 Returns The location of numeric value representation
 @param numericValue The numeric value
 @param axis The axis
 @param bounds The bounds
 @return The location of numeric value representation
 */
+ (CGFloat)locationOfValue:(double)numericValue forAxis:(TKChartAxis*)axis inRect:(CGRect)bounds;

/**
 Initializes the TKChartSeriesRender object.
 @param chart The chart associated with this render.
 @param series The stacked series.
 */
- (id)initWithChart:(TKChart *)chart forSeries:(NSArray*)series;

/**
 The series associated with this render.
 */
- (NSArray*)series;

/**
 Adds a series to render.
  @param series The series that should be added.
 */
- (BOOL)addSeries:(TKChartSeries*)series;

/**
 Determines whether a series is compatible with TKChartSeriesRender.
 @param series The series to test with.
 */
- (BOOL)isCompatibleWithSeries:(TKChartSeries*)series;

/**
 Returns an x-coordinate of the x-numeric value for specific series.
 @param numericValue The numeric value.
 @param series The series.
 */
- (double)locationOfXNumericValue:(double)numericValue inSeries:(TKChartSeries*)series;

/**
 Returns a y-coordinate of the y-numeric value for specific series.
 @param numericValue The numeric value.
 @param series The series.
 */
- (double)locationOfYNumericValue:(double)numericValue inSeries:(TKChartSeries*)series;

/**
 Returns the location of a data point
 @param data The data point to locate
 @param series The series to which the specified data point is associated
 */
- (CGPoint)locationOfPoint:(id<TKChartData>)data inSeries:(TKChartSeries*)series;

/**
 Returns a visual point based on the provided information.
 @param point The data point that should be converted.
 @param index The data point index.
 @param series The series which contains this point.
 @return An instance of TKChartVisualPoint if successfull.
 */
- (TKChartVisualPoint*)pointFromData:(id<TKChartData>)point pointIndex:(NSUInteger)index inSeries:(TKChartSeries *)series;

/**
 Creates a visual point based on the provided information.
 @param data The data point that should be converted.
 @param index The data point index.
 @param series The series which contains this point.
 @return The instance of the newly created TKChartVisualPoint.
 */
- (TKChartVisualPoint*)createVisualPoint:(id<TKChartData>)data pointIndex:(NSInteger)index inSeries:(TKChartSeries *)series;

/**
 Returns the render states for all associated series
 */
@property (nonatomic, strong, readonly) TKMutableArray *seriesRenderStates;

/**
 Does a hit point test.
 @param point The point to test with.
 @return A TKChartSelectionInfo object containing information about the hit point found. Returns nil when no hit test found.
 */
- (TKChartSelectionInfo *)hitTestForPoint:(CGPoint)point;

/**
 This method is being called by TKChart when the selection is about to change.
 @param series The series that is currently selected.
 @param pointIndex The point index of the currently selected point.
 */
- (void)selectionWillChangeForSeries:(TKChartSeries*)series andPoint:(NSInteger)pointIndex;

@end
