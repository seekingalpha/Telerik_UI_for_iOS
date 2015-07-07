//
//  TKChartFinancialDataPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartDataPoint.h"

/**
 @discussion Represents a data point for financial series.
 */
@interface TKChartFinancialDataPoint : TKChartDataPoint

/**
 Open price value.
 */
@property (nonatomic, strong) NSNumber *open;

/**
 High price value.
 */
@property (nonatomic, strong) NSNumber *high;

/**
 Low price value.
 */
@property (nonatomic, strong) NSNumber *low;

/**
 Close price value.
 */
@property (nonatomic, strong) NSNumber *close;

/**
 Volume value.
 */
@property (nonatomic, strong) NSNumber *volume;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 @param volume Volume value.
 */
+ (instancetype)dataPointWithX:(id)xValue open:(NSNumber *)open high:(NSNumber *)high low:(NSNumber *)low close:(NSNumber *)close volume:(NSNumber *)volume;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 */
+ (instancetype)dataPointWithX:(id)xValue open:(NSNumber *)open high:(NSNumber *)high low:(NSNumber *)low close:(NSNumber *)close;

/**
 Creates a financial data point.
 @param xValue X axis value.
 @param open Open price value.
 @param high High price value.
 @param low Low price value.
 @param close Close price value.
 @param volume Volume value.
 */
- (id)initWithX:(id)xValue open:(NSNumber *)open high:(NSNumber *)high low:(NSNumber *)low close:(NSNumber *)close volume:(NSNumber *)volume;

@end
