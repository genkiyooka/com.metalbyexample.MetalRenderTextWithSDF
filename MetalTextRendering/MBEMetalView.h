//
//  MBEMetalView.h
//  TextRendering
//
//  Created by Warren Moore on 11/7/14.
//  Copyright (c) 2014 Metal By Example. All rights reserved.
//

@import UIKit;
@import QuartzCore.CAMetalLayer;

NS_ASSUME_NONNULL_BEGIN

@interface MBEMetalView : UIView

@property (retain, nonatomic, readonly) CAMetalLayer *metalLayer;

@end

NS_ASSUME_NONNULL_END
