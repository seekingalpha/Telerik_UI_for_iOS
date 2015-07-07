//
//  TKView.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

@class TKFill;
@class TKStroke;
@class TKShape;
@protocol TKLayout;

/**
 UIView subclass which provides custom fill, stroke and layout information
 */
@interface TKView : UIView

/**
 Returns the version
 */
+ (NSString*)versionString;

/**
 The view's fill
 */
@property (nonatomic, strong) TKFill *fill;

/**
 The view's stroke
 */
@property (nonatomic, strong) TKStroke *stroke;

/**
 The view's layout
 */
@property (nonatomic, strong) id<TKLayout> layout;

/**
 The view's shape
 */
@property (nonatomic, strong) TKShape *shape;

/**
 Array containing drawables for TKView
 */
@property (nonatomic, strong) NSArray *drawables;

@end

void import_Components( );

__attribute__((used)) static void importComponentsAndTools ()
{
    import_Components();
}

