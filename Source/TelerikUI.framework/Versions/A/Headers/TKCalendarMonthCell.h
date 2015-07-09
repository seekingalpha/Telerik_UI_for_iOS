//
//  TKCalendarMonthCell.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendar;
@class TKCalendarMonthView;
@class TKCalendarYearPresenter;

/**
 @discussion A month within a year view in TKCalendar.
 */
@interface TKCalendarMonthCell : UICollectionViewCell

/**
 Attaches an owner and date to this cell.
 
 @param owner        The owner, an instance of TKCalendar.
 @param presenter    The year presenter for the cell.
 @param year         The presented year.
 @param month        The presented month.
 */
- (void)attachWithCalendar:(TKCalendar*)owner presenter:(TKCalendarYearPresenter*)presenter withYear:(NSInteger)year andMonth:(NSInteger)month;

/**
 Returns the contained calendar cell instance.
 */
- (TKCalendarMonthView*)monthView;

@end
