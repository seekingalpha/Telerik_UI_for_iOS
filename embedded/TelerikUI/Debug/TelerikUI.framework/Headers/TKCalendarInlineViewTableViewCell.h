//
//  TKCalendarInlineViewTableViewCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKCalendarInlineViewTableViewCellStyle;
@class TKCalendarDayCell;
@protocol TKCalendarEventProtocol;

/**
 *  @discussion A table view cell used to present events in TKCalendarMonthPresenter inline view.
 */
@interface TKCalendarInlineViewTableViewCell : UITableViewCell

/**
 *  Returns the cell style. Use the style property to customize the visual appearance of TKCalendarInlineViewTableViewCell.
 */
@property (nonatomic, strong, readonly) TKCalendarInlineViewTableViewCellStyle *style;

/**
 *  Attaches a day cell and event index.
 *
 *  @param cell The day cell to which the displayed event belongs.
 *  @param index The index of the evnet inside the day cell events list.
 */
- (void)attachWithCell:(TKCalendarDayCell*)cell eventIndex:(NSInteger)index;

/**
 * Called when the event text should be updated.
 *
 * @param event The event associated with this cell.
 * @param cell The cell whose events should be displayed.
 */
- (void)updateTextForEvent:(id<TKCalendarEventProtocol>)event withCell:(TKCalendarDayCell*)cell;

@end
