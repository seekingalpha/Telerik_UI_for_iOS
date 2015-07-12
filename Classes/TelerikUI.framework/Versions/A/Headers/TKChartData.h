//
//  TKChartData.h
//
//  Copyright (c) 2013 Telerik. All rights reserved.

/**
 * @discussion Represents a data provider protocol for chart's series
 */
@protocol TKChartData <NSObject>

@required

/**
 Returns an x-value in cartesian series. It is used as a value for pie series.
 */
- (id)dataXValue;

/**
 Returns a y-value in cartesian series.
 */
- (id)dataYValue;

@optional

/**
 The name for a pie.
 */
- (NSString *)dataName;

/**
 The value of the bubble area for bubble series.
 */
- (NSNumber *)area;

/**
 Open price value for financial series.
 */
- (NSNumber *)open;

/**
 High price value for financial series.
 */
- (NSNumber *)high;

/**
 Low price value for financial series.
 */
- (NSNumber *)low;

/**
 Close price value for financial series.
 */
- (NSNumber *)close;

/**
 Volume value for financial series.
 */
- (NSNumber *)volume;

/**
 The y axis value for indicator signal line
 */
- (id)signalYValue;

@end
