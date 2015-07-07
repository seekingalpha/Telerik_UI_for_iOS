//
//  TKChartSelectionInfo.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartData.h"

@class TKChartSeries;
@class TKChartDataPoint;

/**
 Represents a class that contains selection and hit test information.
 */
@interface TKChartSelectionInfo : NSObject<NSCopying>

/**
 Creates a TKChartSelectionInfo instance.
 @param series The series for this hit test.
 @param dataPointIndex The index of the point for this hit test.
 */
+ (instancetype)hitTestInfoWithSeries:(TKChartSeries *)series
                       dataPointIndex:(NSInteger)dataPointIndex;

/**
 Creates a TKChartSelectionInfo instance.
 @param series The series for this hit test.
 @param dataPointIndex The index of the point for this hit test.
 @param distance The distance.
 */
+ (instancetype)hitTestInfoWithSeries:(TKChartSeries *)series
                       dataPointIndex:(NSInteger)dataPointIndex
                             distance:(CGFloat)distance;

/**
 Initializes a TKChartSelectionInfo instance.
 @param series The series for this hit test.
 @param dataPointIndex The index of the point for this hit test.
 */
- (id)initWithSeries:(TKChartSeries *)series
      dataPointIndex:(NSInteger)dataPointIndex;

/**
 Initializes a TKChartSelectionInfo.
 @param series The series for this hit test.
 @param dataPointIndex The index of the point for this hit test.
 @param distance The distance between the touch origin and data point origin.
 */
- (id)initWithSeries:(TKChartSeries *)series
      dataPointIndex:(NSInteger)dataPointIndex
            distance:(CGFloat)distance;

/**
 Returns the underlying series.
 */
@property (nonatomic, weak, readonly) TKChartSeries *series;

/**
 Returns the index of the underlying data point.
 */
@property (nonatomic, assign, readonly) NSInteger dataPointIndex;

/**
 Returns the underlying data point.
 */
- (id<TKChartData>)dataPoint;

/**
 Returns the distance between the touch origin and data point origin.
 */
@property (nonatomic, assign, readonly) CGFloat distance;

/**
 Returns the location in view coordinates
 */
- (CGPoint)location;

@end
