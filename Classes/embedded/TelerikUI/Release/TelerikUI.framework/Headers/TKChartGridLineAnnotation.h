//
//  TKChartLineAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"

@class TKChartAxis;
@class TKChartGridLineAnnotationStyle;
@class TKStroke;

/**
 A vertical or horizontal line annotation.
 */
@interface TKChartGridLineAnnotation : TKChartAnnotation

/**
 Initializes the annotation with a value.
 @param value The place to locate the annotation.
 @param axis The axis to which the value belongs.
 */
- (id)initWithValue:(id)value forAxis:(TKChartAxis*)axis;

/**
 Initializes the annotation with a value and stroke.
 @param value The place to locate the annotation.
 @param axis The axis to which the value belongs.
 @param stroke The stroke to use when rendering the annotation.
 */
- (id)initWithValue:(id)value forAxis:(TKChartAxis*)axis withStroke:(TKStroke*)stroke;

/**
 The axis to which this annotation belongs.
 */
@property (nonatomic, strong) TKChartAxis *axis;

/**
 The value used when positioning the annotation.
 */
@property (nonatomic, strong) id value;

/**
 The annotation style. It can be used to customize the annotation appearance.
 */
@property (nonatomic, strong, readonly) TKChartGridLineAnnotationStyle *style;

@end
