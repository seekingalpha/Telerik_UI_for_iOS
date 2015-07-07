//
//  TKSolidFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKFill.h"

/**
 @discussion A solid color fill.
 */

@interface TKSolidFill : TKFill

/**
 * Initializes with a fill color.
 * @param color The fill color.
 */
+ (instancetype)solidFillWithColor:(UIColor*)color;

/**
 Initializes with a fill color.
 @param color The fill color.
 @param cornerRadius The corner radius in points.
 */
+ (instancetype)solidFillWithColor:(UIColor*)color cornerRadius:(CGFloat)cornerRadius;

/**
 Initializes with a fill color.
 @param color The fill color.
 */
- (id)initWithColor:(UIColor*)color;

/**
 Initializes with a fill color.
 @param color The fill color.
 @param cornerRadius The corner radius in points.
 */
- (id)initWithColor:(UIColor *)color cornerRadius:(CGFloat)cornerRadius;

/**
 The Fill color to use while drawing.
 */
@property (nonatomic, strong) UIColor* color;

@end
