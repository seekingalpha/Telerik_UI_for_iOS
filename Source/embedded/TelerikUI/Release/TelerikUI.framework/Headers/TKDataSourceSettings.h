//
//  TKDataSourceSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKDataSourceChartSettings;
@class TKDataSourceCollectionViewSettings;
@class TKDataSourceTableViewSettings;
@class TKDataSourceCalendarSettings;
@class TKDataSourceListViewSettings;


/**
 Contains various settings allowing appearance customizations of TKDataSource consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@interface TKDataSourceSettings : NSObject

/**
 Settings specific to TKChart.
 */
@property (nonatomic, strong) TKDataSourceChartSettings *chart;

/**
 Settings specific to UICollectionView.
 */
@property (nonatomic, strong) TKDataSourceCollectionViewSettings *collectionView;

/**
 Settings specific to UITableView.
 */
@property (nonatomic, strong) TKDataSourceTableViewSettings *tableView;

/**
 Settings specific to TKCalendar.
 */
@property (nonatomic, strong) TKDataSourceCalendarSettings *calendar;

/**
 Settings specific to TKListView.
 */
@property (nonatomic, strong) TKDataSourceListViewSettings *listView;

@end
