//
//  TKRadialGradientFill.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKGradientFill.h"

/**
 Specifies the radius units type for startRadius and endRadius.
 */
typedef NS_ENUM(NSInteger, TKGradientRadiusType) {
    /**
     The radius is in pixels.
     */
    TKGradientRadiusTypePixels,
    
    /**
     The radius is in the interval of 0 (0%) to 1 (100%) using minimum of drawing rectangle sizes.
     */
    TKGradientRadiusTypeRectMin,
    
    /**
     The radius is in interval of 0 (0%) to 1 (100%) using maximum of drawing rectangle sizes.
     */
    TKGradientRadiusTypeRectMax
};

/**
 * Represents a radial fill.
 */
@interface TKRadialGradientFill : TKGradientFill

/**
 Creates a radial gradient fill with colors.
 @param colors The array of UIColor containing gradient colors.
 */
+ (instancetype)radialGradientFillWithColors:(NSArray *)colors;

/**
 Reverses a radial gradient fill.
 @param fill The radial gradient fill.
 @return The reversed fill.
 */
+ (instancetype)reverse:(TKRadialGradientFill*)fill;

/**
 Initializes a radial gradient fill.
 @param colors The array of UIColor containing gradient colors.
 @param startCenter The center point for gradient drawing. Both values are in the interval of 0 to 1.
 @param startRadius The radius of start circle.
 @param endCenter The end point for gradient drawing. Both values are in the interval of 0 to 1.
 @param endRadius The radius of end circle.
 */
- (id)initWithColors:(NSArray *)colors
         startCenter:(CGPoint)startCenter
         startRadius:(CGFloat)startRadius
           endCenter:(CGPoint)endCenter
           endRadius:(CGFloat)endRadius;

/**
 Initializes a radial gradient fill.
 @param colors The array of UIColor containing gradient colors.
 @param startCenter The center point for gradient drawing. Both values are in the interval of 0 to 1.
 @param startRadius The radius of start circle.
 @param endCenter The end point for gradient drawing. Both values are in the interval of 0 to 1.
 @param endRadius The radius of end circle.
 @param radiusType The radius type.
 */
- (id)initWithColors:(NSArray *)colors
         startCenter:(CGPoint)startCenter
         startRadius:(CGFloat)startRadius
           endCenter:(CGPoint)endCenter
           endRadius:(CGFloat)endRadius
          radiusType:(TKGradientRadiusType)radiusType;

/**
 The units used for startRadius and endRadius. The default value is TKGradientRadiusTypeRectMin.

 @discussion The radius types are defined as follows:
 
    typedef enum {
        TKGradientRadiusTypePixels,     // The radius is in pixels.
        TKGradientRadiusTypeRectMin,    // The radius is in the interval of 0 (0%) to 1 (100%) using minimum of drawing rectangle sizes.
        TKGradientRadiusTypeRectMax     // The radius is in interval of 0 (0%) to 1 (100%) using maximum of drawing rectangle sizes.
    } TKGradientRadiusType;

 */
@property (nonatomic, assign) TKGradientRadiusType gradientRadiusType;

/**
 The radius of a start circle with center at the start point. Used only for radial gradients. The default value is 0.5 (with TKGradientRadiusType = TKGradientRadiusTypeRectMin).
 */
@property (nonatomic, assign) CGFloat startRadius;

/**
 The radius of a end circle with center at the end point. Used only for radial gradients. The default value is 0.5 (with TKGradientRadiusType = TKGradientRadiusTypeRectMin).
 */
@property (nonatomic, assign) CGFloat endRadius;

/**
 The start center for radial gradients. The default value is (0.5f, 0.0f).
 */
@property (nonatomic, assign) CGPoint startCenter;

/**
  The end center for radial gradients. The default value is (0.5f, 1.0f).
 */
@property (nonatomic, assign) CGPoint endCenter;

@end
