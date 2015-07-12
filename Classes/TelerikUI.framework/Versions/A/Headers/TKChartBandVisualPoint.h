//
//  TKChartBandVisualPoint.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartVisualPoint.h"
#import "TKChartData.h"

@class TKChartSeriesRender;
@class TKChartSeries;

@interface TKChartBandVisualPoint : TKChartVisualPoint

@property (nonatomic) CGFloat signalY;

- (id)initWithPoint:(CGPoint)point signalY:(CGFloat)signalY;

@end
