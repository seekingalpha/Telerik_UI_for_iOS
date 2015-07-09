//
//  TKChartBubbleDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartDataPoint.h"

/**
 @discussion Represents a data point for bubble series.
 */
@interface TKChartBubbleDataPoint : TKChartDataPoint

/**
 Bubble area value.
 */
@property (nonatomic, strong) NSNumber *area;

/**
 Creates a data point for bubble series.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param area Bubble area value.
 */
+ (instancetype)dataPointWithX:(id)xValue Y:(id)yValue area:(NSNumber *)area;

/**
 Creates a data point for bubble series.
 @param xValue X axis value.
 @param yValue Y axis value.
 @param area Bubble area value.
 */
- (id)initWithX:(id)xValue Y:(id)yValue area:(NSNumber *)area;

@end
