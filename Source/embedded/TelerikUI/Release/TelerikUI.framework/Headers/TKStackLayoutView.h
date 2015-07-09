//
//  StackLayoutView.h
//  TestLayout
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKStackLayout.h"

/**
 @discussion A view that layouts its subviews by using a stack layout.
 */
@interface TKStackLayoutView : UIScrollView

/**
 The stack layout used to arrange sub views in this view.
 */
@property (nonatomic, strong) TKStackLayout *stack;

@end
