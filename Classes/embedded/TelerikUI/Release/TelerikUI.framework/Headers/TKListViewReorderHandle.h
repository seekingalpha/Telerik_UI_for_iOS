//
//  TKListViewReorderHandle.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKStroke;

/**
 A visual glyph representing a drag/reorder handle.
 */
@interface TKListViewReorderHandle : UIView

@property (nonatomic, strong) TKStroke *lineStroke;

@property (nonatomic) UIEdgeInsets lineInsets;

@property (nonatomic) NSInteger rowCount;

@property (nonatomic) NSInteger rowSpacing;

@property (nonatomic) CGSize desiredSize;

@end
