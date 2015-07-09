//
//  TKSideDrawerItem.h
//
//  Copyright (c) 2013 Telerik Inc. All rights reserved.
//

@class TKSideDrawerItemStyle;
@class TKStyleSheet;

/**
 Defines TKSideDrawer item.
 */
@interface TKSideDrawerItem : NSObject

/**
 TKSideDrawerItem's title.
 */
@property (nonatomic, strong) NSString *title;

/**
 TKSideDrawerItem's styles.
 */
@property (nonatomic, strong, readonly) TKSideDrawerItemStyle *style;

/**
 TKSideDrawerItem's image.
 */
@property (nonatomic, strong) UIImage *image;

/**
 Creates new TKSideDrawerItem instance.
 @param title Title for the TKSideDrawerItem that will be created.
 @return New TKSideDrawerItem instance.
 */
- (id)initWithTitle:(NSString *)title;

/**
 Creates new TKSideDrawerItem instance.
 @param title Title for the TKSideDrawerItem that will be created.
 @param image UIImage fot the TKSideDrawerItem that will be created.
 @return New TKSideDrawerItem instance.
 */
- (id)initWithTitle:(NSString *)title image:(UIImage *)image;

@end
