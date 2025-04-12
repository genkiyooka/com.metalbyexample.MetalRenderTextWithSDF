//
// The exemplar for this technique comes from the default Xcode Swift Metal Game Template
//
// Seems trivial until someone updating the code revises a struct in Swift but forgets to update the shader,
// or adds a field to Swift that changes the alignment or the in-memory-layout of the Swift struct.
//
#ifndef Shaders_struct_BridgingHeader_h
#define Shaders_struct_BridgingHeader_h

#ifdef __METAL_VERSION__
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
typedef metal::int32_t EnumBackingType;
#else
#import <Foundation/Foundation.h>
typedef NSInteger EnumBackingType;
#endif

#include <simd/simd.h>

typedef struct Vertex {
    simd_float4 position;
    simd_float2 texCoords;
} MBEVertex;

typedef struct Uniforms
{
    simd_float4x4 modelMatrix;
    simd_float4x4 viewProjectionMatrix;
    simd_float4 foregroundColor;
} MBEUniforms;

typedef NS_ENUM(EnumBackingType, FragmentTexture)
{
    FragmentTextureIndex0 = 0,
    FragmentTextureIndex1 = 1,
};

typedef NS_ENUM(EnumBackingType, ShaderBuffer)
{
    ShaderBufferIndex0 = 0,
    ShaderBufferIndex1 = 1,
};

typedef NS_ENUM(EnumBackingType, Sampler)
{
    SamplerIndex0 = 0,
    SamplerIndex1 = 1,
};

#endif /* Shaders_struct_BridgingHeader_h */

