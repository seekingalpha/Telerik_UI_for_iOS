//
//  TKChartPointLabel.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKChartData.h"

@class TKChartPointLabelStyle;
@class TKChartVisualPoint;

/**
 Represents a point label.
 */
@interface TKChartPointLabel : NSObject

/**
 Point label's text.
 */
@property (nonatomic, copy) NSString *text;

/**
 Point label's style.
 */
@property (nonatomic, weak, readonly) TKChartPointLabelStyle *style;

/**
 The corresponding data point.
 */
@property (nonatomic, weak, readonly) id<TKChartData> dataPoint;

/**
 Initializes the point label with a data point, style and text.
 @param point The corresponding data point.
 @param style TKChartPointLabelStyle instance.
 @param text Point label's text.
 */
- (id)initWithPoint:(id<TKChartData>)point style:(TKChartPointLabelStyle *)style text:(NSString *)text;

/**
 Returns the point label's width and height.
 @param size The size available for the point label.
 */
- (CGSize)sizeThatFits:(CGSize)size;

/**
 Draws the point label in specified rect.
 @param ctx CGContext instance.
 @param bounds Point label's rect.
 @param visualPoint Point label's corresponding visual point.
 */
- (void)drawInContext:(CGContextRef)ctx inRect:(CGRect)bounds forVisualPoint:(TKChartVisualPoint *)visualPoint;

@end
