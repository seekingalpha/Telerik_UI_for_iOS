//
//  TKListViewStaggeredLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKListViewGridLayout.h"

@class TKListViewStaggeredLayout;

@protocol TKListViewStaggeredLayoutDelegate<NSObject>

- (CGSize)staggeredLayout:(TKListViewStaggeredLayout*)layout sizeForItemAtIndexPath:(NSIndexPath*)indexPath;

@end

@interface TKListViewStaggeredLayout : TKListViewGridLayout

@property (nonatomic, weak) id<TKListViewStaggeredLayoutDelegate> delegate;

@property (nonatomic) BOOL alignLastLine;

@end
