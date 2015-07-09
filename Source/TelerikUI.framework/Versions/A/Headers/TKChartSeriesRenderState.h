//
//  TKChartSeriesRenderState.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKMutableArray;

/**
 Represents the visual state for chart series.
 */
@interface TKChartSeriesRenderState : NSObject

/**
 Returns the points that will be rendered.
 */
@property (nonatomic, strong, readwrite) TKMutableArray *points;

/**
 Returns the points that have been rendered.
 */
@property (nonatomic, strong, readonly) TKMutableArray *oldPoints;

/**
 Returns the index according to series order
 */
@property (nonatomic, readonly) NSUInteger index;

/**
 Initializes the TKChartSeriesRenderState for series.
 @param index The index according to the series order.
 */
- (id)initWithIndex:(NSUInteger)index;

/**
 Creates an animation key path for a particular point at a specified index.
 @param pointIndex The point's index in the series.
 */
- (NSString *)animationKeyPathForPointAtIndex:(NSUInteger)pointIndex;

@end
