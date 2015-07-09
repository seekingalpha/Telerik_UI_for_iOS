//
//  TKGradientFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKFill.h"

/**
 @discussion Represents an abstract gradient fill class.
 */
@interface TKGradientFill : TKFill

/**
 Initializes a linear gradient brush with colors.
 @param colors The array of UIColor containing gradient colors.
 */
- (id)initWithColors:(NSArray *)colors;

/**
 Initializes a linear gradient brush with colors and corner radius.
 @param colors The array of UIColor containing gradient colors.
 @param cornerRadius The corner radius in points.
 */
- (id)initWithColors:(NSArray *)colors cornerRadius:(CGFloat)cornerRadius;

/**
 Initializes a linear gradient brush with colors and locations.
 @param colors The array of UIColor containing gradient colors.
 @param locations The array of NSNumber objects defining the location of each gradient stop in the interval of 0 to 1.
 */
- (id)initWithColors:(NSArray *)colors locations:(NSArray *)locations;

/**
 Initializes a linear gradient brush with colors, locations, and corder radius.
 @param colors The array of UIColor containing gradient colors.
 @param locations The array of NSNumber objects defining the location of each gradient stop in the interval of 0 to 1.
 @param cornerRadius The corner radius in points.
 */
- (id)initWithColors:(NSArray *)colors locations:(NSArray *)locations cornerRadius:(CGFloat)cornerRadius;

/**
 The array of UIColor containing gradient colors.
 */
@property (nonatomic, strong) NSArray *colors;

/**
 The array of NSNumber objects defining the location of each gradient stop in the interval of 0 to 1. If nil, the stops are spread uniformly across the range. The defaults is nil.
 */
@property (nonatomic, strong) NSArray *locations;

@end
