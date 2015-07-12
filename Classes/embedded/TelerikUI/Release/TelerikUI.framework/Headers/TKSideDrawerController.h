//
//  TKSideDrawerController.h
//  TelerikUI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//
@class TKSideDrawer;

/**
 @discussion The container UIViewController that holds TKSideDrawer instance
 */
@interface TKSideDrawerController : UIViewController

/**
 The content controller of TKSideDrawerController.
 */
@property (nonatomic, strong) UIViewController *contentController;

/**
 The TKSideDrawer instance attached to TKSideDrawerController.
 */
@property (nonatomic, strong, readonly) TKSideDrawer *sideDrawer;

/**
 Initializes the TKSideDrawerController with content.
 @param contentController TKSideDrawerController's content UIViewController.
 */
- (id)initWithContent:(UIViewController *)contentController;

@end


