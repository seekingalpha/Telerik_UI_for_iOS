//
//  TKSideDrawerView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TKSideDrawer;

@interface TKSideDrawerView : UIView

@property (nonatomic, strong, readonly) TKSideDrawer *sideDrawer;

@property (nonatomic, strong) UIView *mainView;

@property (nonatomic, weak) UIView *sideDrawerContentView;

- (id)initWithFrame:(CGRect)frame mainView:(UIView *)mainView;

@end
