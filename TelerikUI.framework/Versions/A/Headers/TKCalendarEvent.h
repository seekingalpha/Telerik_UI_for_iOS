//
//  TKCalendarEvent.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"

/**
 @discussion Represents an event used in TKCalendar class.
 */
@interface TKCalendarEvent : NSObject <TKCalendarEventProtocol>

/**
 The event location.
 */
@property (nonatomic, strong) NSString *location;

/**
 The event description.
 */
@property (nonatomic, strong) NSString *content;

@end
