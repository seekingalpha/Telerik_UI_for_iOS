//
//  TKCalendarYearTitleView.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendarTitleCell.h"

/**
 @discussion A title view within a year view in TKCalendar.
 */
@interface TKCalendarYearTitleView : UICollectionReusableView

/**
 Attaches an owner and text to the view.

 @param owner The view owner, an instance of TKCalendar.
 @param text  The view text.
 */
- (void)attachWithCalendar:(TKCalendar*)owner withText:(NSString*)text;

/**
 Returns the contained title cell.
 */
- (TKCalendarTitleCell*)view;

@end
