//
//  MBEMesh.h
//  TextRendering
//
//  Created by Warren Moore on 11/10/14.
//  Copyright (c) 2014 Metal By Example. All rights reserved.
//

@import UIKit;
@import Metal;

NS_ASSUME_NONNULL_BEGIN

@interface MBEMesh : NSObject

@property (retain, nonatomic, readonly) id<MTLBuffer> vertexBuffer;
@property (retain, nonatomic, readonly) id<MTLBuffer> indexBuffer;

@end

NS_ASSUME_NONNULL_END
