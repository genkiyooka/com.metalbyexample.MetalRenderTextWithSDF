//
//  Shaders.metal
//  TextRendering
//
//  Created by Warren Moore on 2/6/15.
//  Copyright (c) 2015 Metal By Example. All rights reserved.
//

#include <metal_stdlib>
#include <simd/simd.h>

// Including header shared between this Metal shader code and Swift/C code executing Metal API commands
#include "Shaders_struct_BridgingHeader.h"

using namespace metal;

struct TransformedVertex
{
    float4 position [[position]];
    float2 texCoords;
};

vertex TransformedVertex vertex_shade(constant const Vertex *vertices [[buffer(ShaderBufferIndex0)]],
                                      constant const MBEUniforms &uniforms [[buffer(ShaderBufferIndex1)]],
                                      uint vid [[vertex_id]])
{
    TransformedVertex outVert;
    outVert.position = uniforms.viewProjectionMatrix * uniforms.modelMatrix * float4(vertices[vid].position);
    outVert.texCoords = vertices[vid].texCoords;
    return outVert;
}

fragment half4 fragment_shade(TransformedVertex vert [[stage_in]],
                              constant const Uniforms &uniforms [[buffer(ShaderBufferIndex0)]],
                              sampler samplr [[sampler(SamplerIndex0)]],
                              texture2d<float, access::sample> texture [[texture(FragmentTextureIndex0)]])
{
    float4 color = uniforms.foregroundColor;
    // Outline of glyph is the isocontour with value 50%
    float edgeDistance = 0.5;
    // Sample the signed-distance field to find distance from this fragment to the glyph outline
    float sampleDistance = texture.sample(samplr, vert.texCoords).r;
    // Use local automatic gradients to find anti-aliased anisotropic edge width, cf. Gustavson 2012
    float edgeWidth = 0.75 * length(float2(dfdx(sampleDistance), dfdy(sampleDistance)));
    // Smooth the glyph edge by interpolating across the boundary in a band with the width determined above
    float insideness = smoothstep(edgeDistance - edgeWidth, edgeDistance + edgeWidth, sampleDistance);
    return half4(color.r, color.g, color.b, insideness);
}
