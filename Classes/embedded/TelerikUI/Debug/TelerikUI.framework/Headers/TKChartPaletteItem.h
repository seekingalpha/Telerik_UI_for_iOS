//
//  TKChartPaletteItem.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;

/**
 @discussion Represents a single palette item used in TKChart.
 */
@interface TKChartPaletteItem : NSObject

/**
 Creates a palette item with a specified fill.
 @param fill The TKFill to set.
 */
+ (instancetype)paletteItemWithFill:(TKFill *)fill;

/**
 Creates a palette item with a specified stroke.
 @param stroke The TKStroke to set.
 */
+ (instancetype)paletteItemWithStroke:(TKStroke *)stroke;

/**
 Creates a palette item with a specified stroke & fill.
 @param stroke The TKStroke to set.
 @param fill The TKFill to set.
 */
+ (instancetype)paletteItemWithStroke:(TKStroke *)stroke andFill:(TKFill *)fill;

/**
 Creates a palette item with drawables. Drawing is performed in the order of the array elements.
 @param drawables The Array of the TKDrawing implementations.
 */
+ (instancetype)paletteItemWithDrawables:(NSArray *)drawables;

/**
 Initializes with a specified fill.
 @param fill The TKFill to set.
 */
- (id)initWithFill:(TKFill *)fill;

/**
 Initializes with a specified stroke.
 @param stroke The TKStroke to set.
 */
- (id)initWithStroke:(TKStroke *)stroke;

/**
 Initializes with a specified stroke & fill.
 @param stroke The TKStroke to set.
 @param fill The TKFill to set.
 */
- (id)initWithStroke:(TKStroke *)stroke andFill:(TKFill *)fill;

/**
 Initializes with drawables. Drawing is performed in the order of the array elements.
 @param drawables The Array of the TKDrawing implementations.
 */
- (id)initWithDrawables:(NSArray *)drawables;

/**
 The palette's text color.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 The palette's font.
 */
@property (nonatomic, strong) UIFont *font;

/**
 The fill color of the palette item.
 @return An instance of UIColor representing the fill color.
 */
@property (nonatomic, strong) TKFill *fill;

/**
 The stroke color of the palette item.
 @return An instance of UIColor representing the stroke color.
 */
@property (nonatomic, strong) TKStroke *stroke;

/**
 An array of the TKDrawing implementations.
 All is drawn in the order of the elements in the array.
*/
@property (nonatomic, strong) NSArray *drawables;

@end
