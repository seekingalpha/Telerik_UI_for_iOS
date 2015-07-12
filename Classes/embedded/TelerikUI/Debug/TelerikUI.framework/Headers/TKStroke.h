//
//  TKStroke.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKDrawing.h"

/**
 @enum TKRectSide
 @discussion Defines sides where to draw stroke.
 */
typedef NS_OPTIONS(NSInteger, TKRectSide) {
    /**
     Draw stroke on top side.
     */
    TKRectSideTop = 1 << 0,
    /**
     Draw stroke on bottom side.
     */
    TKRectSideBottom = 1 << 1,
    /**
     Draw stroke on left side.
     */
    TKRectSideLeft = 1 << 2,
    /**
     Draw stroke on right side.
     */
    TKRectSideRight = 1 << 3,
    /**
     Draw stroke on all sides (default)
     */
    TKRectSideAll = ~0L
};

@class TKFill;

/**
 @discussion Represents a stroke that renders a line.
 */
@interface TKStroke : NSObject<TKDrawing, NSCopying>

/**
 * Defines the stroke with a solid color.
 * @param color The solid color.
 */
+ (instancetype)strokeWithColor:(UIColor*)color;

/**
 * Defines the stroke with a solid color and thickness.
 * @param color The solid color.
 * @param width The stroke's thickness.
 */
+ (instancetype)strokeWithColor:(UIColor*)color width:(CGFloat)width;

/**
 * Defines the stroke with a solid color, thickness and corner radius.
 * @param color The solid color.
 * @param width The stroke's tickness.
 * @param cornerRadius The corner radius in points.
 */
+ (instancetype)strokeWithColor:(UIColor*)color width:(CGFloat)width cornerRadius:(CGFloat)cornerRadius;

/**
 * Defines the stroke with a fill.
 * @param fill The fill used for the stroke.
 */
+ (instancetype)strokeWithFill:(TKFill*)fill;

/**
 * Defines the stroke with a fill and thickness.
 * @param fill The fill used for the stroke.
 * @param width The stroke's thickness.
 */
+ (instancetype)strokeWithFill:(TKFill*)fill width:(CGFloat)width;

/**
 * Defines the stroke with a fill, thickness and corder radius.
 * @param fill The fill used for the stroke.
 * @param width The stroke's thickness.
 * @param cornerRadius The corner radius in points.
 */
+ (instancetype)strokeWithFill:(TKFill*)fill width:(CGFloat)width cornerRadius:(CGFloat)cornerRadius;

/**
 The stroke's width.
 */
@property (nonatomic, assign) CGFloat width;

/**
 Line cap style.
 */
@property (nonatomic, assign) CGLineCap lineCap;

/**
 Line join style.
 */
@property (nonatomic, assign) CGLineJoin lineJoin;

/**
 Line miter limit.
 */
@property (nonatomic, assign) CGFloat miterLimit;

/**
 A value that specifies how far into the dash pattern the line starts, in units of the user space. For example,
 passing a value of 3 means the line is drawn with the dash pattern starting at three units from its beginning.
 Passing a value of 0 draws a line starting at the beginning of the dash pattern.
 */
@property (nonatomic, assign) CGFloat phase;

/**
 A bitmask value that identifies the corners that you want rounded. You can use this parameter to round only a 
 subset of the corners of the rectangle. The default is all corners. Ignored if cornerRadius is 0.
 */
@property (nonatomic, assign) UIRectCorner corners;

/**
 The radius to use when drawing rounded corners. The Default is 0.
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 Edge insets to apply. This property has no effect when using drawInContext:withPath: method.
 */
@property (nonatomic, assign) UIEdgeInsets insets;

/**
 Determines whether to use antialiasing when drawing the stroke
 */
@property (nonatomic, assign) BOOL allowsAntialiasing;

/**
 The sides of the stroke to draw. The default is all sides.

 @discussion The rectangle sides are defined as follows:
 
    typedef enum {
        TKRectSideTop = 1 << 0,     // Draw stroke on top side.
        TKRectSideBottom = 1 << 1,  // Draw stroke on bottom side.
        TKRectSideLeft = 1 << 2,    // Draw stroke on left side.
        TKRectSideRight = 1 << 3,   // Draw stroke on right side.
        TKRectSideAll = ~0UL        // Draw stroke on all sides (default)
    } TKRectSide;

 */
@property (nonatomic, assign) TKRectSide strokeSides;

/**
 The dash patterns of the stroke. An array of NSNumber that specify the lengths of the painted segments and
 unpainted segments, respectively, of the dash pattern, or nil for no dash pattern.
 For example, passing an array with values [@2, @3] sets a dash pattern that alternates between
 a 2-user-space-unit-long painted segment and a 3-user-space-unit-long unpainted segment. 
 Passing values [@1, @3, @4, @2] sets the pattern to a 1-unit painted segment, a 3-unit unpainted segment,
 a 4-unit painted segment, and a 2-unit unpainted segment.
 */
@property (nonatomic, strong) NSArray* dashPattern;

/**
 The stroke's brush.
 */
@property (nonatomic, strong) TKFill *fill;

/**
 The stroke color.
 */
- (UIColor*)color;

/**
 Defines the stroke with a solid color.
 @param color The solid color.
 */
- (id)initWithColor:(UIColor*)color;

/**
 Defines the stroke with a solid color and thickness.
 @param color The solid color
 @param width The stroke's thickness.
 */
- (id)initWithColor:(UIColor*)color width:(CGFloat)width;

/**
 Initializes the stroke with a fill.
 @param fill The fill used for the stroke.
 */
- (id)initWithFill:(TKFill*)fill;

/**
 Initializes the stroke with a fill and thickness.
 @param fill The fill used for the stroke.
 @param width The stroke's thickness.
 */
- (id)initWithFill:(TKFill*)fill width:(CGFloat)width;

@end
