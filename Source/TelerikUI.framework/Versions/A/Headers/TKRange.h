//
//  TKRange.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

/**
 @discussion A class that represents a range of minimum and maximum values.
 */
@interface TKRange : NSObject

/**
 Initializes the range with its minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range
 */
+ (id)rangeWithMinimum:(id)minimum andMaximum:(id)maximum;

/**
 Initializes the range with its minimum and maximum index path.
 @param minimumIndex The minimum index of the range.
 @param maximumIndex The maximum index of the range
 */
+ (id)rangeWithMinimumIndex:(NSInteger)minimumIndex andMaximumIndex:(NSInteger)maximumIndex;

/** 
 The range's minimum.
 */
@property (nonatomic, strong) id minimum;

/** 
 The range's maximum.
 */
@property (nonatomic, strong) id maximum;

/** 
 Initializes the range with its minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range 
 */
- (id)initWithMinimum:(id)minimum andMaximum:(id)maximum;

/** 
 Defines the range's minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range.
 */
- (void)setMinimum:(id)minimum andMaximum:(id)maximum;

/** 
 Defines the range's minimum and maximum.
 @param minimum The minimum value of the range.
 @param maximum The maximum value of the range.
 @param includeCurrentRange Includes the current values in calculation.
*/
- (void)setMinimum:(id)minimum andMaximum:(id)maximum calcWithCurrent:(BOOL)includeCurrentRange;

@end
