//
//  TKChartBandAnnotation.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartAnnotation.h"

@class TKRange;
@class TKChartAxis;
@class TKChartBandAnnotationStyle;
@class TKFill;
@class TKStroke;

/**
 A band annotation. The band specifies a horizontal or vertical range of specific axis.
 */
@interface TKChartBandAnnotation : TKChartAnnotation

/**
 Initializes the annotation with a range.
 @param aRange The range where to locate the annotation.
 @param anAxis The axis to which the value belongs.
 */
- (id)initWithRange:(TKRange*)aRange forAxis:(TKChartAxis*)anAxis;

/**
 Initializes the annotation with a value.
 @param aRange The range where to locate the annotation.
 @param anAxis The axis to which the value belongs.
 @param fill The fill to use when rendering the annotation.
 @param stroke The stroke to use when rendering the annotation.
 */
- (id)initWithRange:(TKRange *)aRange forAxis:(TKChartAxis *)anAxis withFill:(TKFill*)fill withStroke:(TKStroke*)stroke;

/**
 The range used when positioning the annotation.
 */
@property (nonatomic, strong) TKRange *range;

/**
 The axis to which this annotation belongs.
 */
@property (nonatomic, strong) TKChartAxis *axis;

/**
 The annotation style. It can be used to customize the annotation appearance.
 */
@property (nonatomic, strong, readonly) TKChartBandAnnotationStyle *style;

@end

