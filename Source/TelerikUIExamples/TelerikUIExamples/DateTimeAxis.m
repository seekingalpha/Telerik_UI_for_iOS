//
//  DateTimeAxis.m
//  TelerikUIExamples
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "DateTimeAxis.h"
#import <TelerikUI/TelerikUI.h>

@implementation DateTimeAxis
{
    TKChart *_chart;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _chart = [[TKChart alloc] initWithFrame:self.exampleBoundsWithInset];
    _chart.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:_chart];
    
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *dateTimeComponents = [[NSDateComponents alloc] init];
    dateTimeComponents.year = 2013;
    dateTimeComponents.day = 1;
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    for (int i = 1; i <= 6; i++) {
        dateTimeComponents.month = i;
        [array addObject:[[TKChartDataPoint alloc] initWithX:[calendar dateFromComponents:dateTimeComponents] Y:@(arc4random() % 100)]];
    }
    TKChartSplineAreaSeries *series = [[TKChartSplineAreaSeries alloc] initWithItems:array];
    series.selectionMode = TKChartSeriesSelectionModeSeries;
    
    dateTimeComponents.month = 1;
    NSDate *minDate = [calendar dateFromComponents:dateTimeComponents];
    dateTimeComponents.month = 6;
    NSDate *maxDate = [calendar dateFromComponents:dateTimeComponents];
    
    TKChartDateTimeAxis *xAxis = [[TKChartDateTimeAxis alloc] initWithMinimumDate:minDate andMaximumDate:maxDate];
    xAxis.majorTickIntervalUnit = TKChartDateTimeAxisIntervalUnitMonths;
    xAxis.majorTickInterval = 1;
    _chart.xAxis = xAxis;
    
    [_chart addSeries:series];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
