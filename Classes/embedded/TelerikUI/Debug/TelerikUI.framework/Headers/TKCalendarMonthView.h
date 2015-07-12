//
//  TKCalendarMonthView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

@class TKCalendar;
@class TKCalendarYearPresenter;
@class TKCalYearViewStyle;

/**
 @discussion A month view rendered by using a core graphics.
 */
@interface TKCalendarMonthView : UIView

/**
 Attaches an owner and date to the view.
 
 @param owner     The view owner, an instance of TKCalendar.
 @param presenter The view presenter, an instance of TKCalendarYearPresenter.
 @param year      The year.
 @param month     The month.
 */
- (void)attachWithCalendar:(TKCalendar*)owner presenter:(TKCalendarYearPresenter*)presenter withYear:(NSInteger)year andMonth:(NSInteger)month;

/**
 Returns the date for this cell.
 */
- (NSDate*)date;

@end
