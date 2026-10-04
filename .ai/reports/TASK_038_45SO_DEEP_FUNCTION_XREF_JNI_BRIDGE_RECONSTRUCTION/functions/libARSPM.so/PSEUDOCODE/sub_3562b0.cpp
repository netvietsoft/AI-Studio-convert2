// FUNCTION: sub_3562b0
// LIBRARY: libARSPM.so
// RVA: 0x3562b0 | SIZE: 768 bytes | SHA256: 18B3EC885F4AD5E4EB419E5162DA789B892E6205CCD987DD2E17426C73335C00
// SEMANTIC_LABEL: HAIR_COLOR_PIPELINE | CONFIDENCE: HIGH_CONFIDENCE
// IMPORTED_APIS: None
// STRING_XREFS: HairQuadEdge, %s = %s;, inHairQuadEdge, half4 %s;, inPosition, inPosition, half edgeAlpha;, half2 duvdx = half2(dFdx(%s.xy));, half2 duvdy = half2(dFdy(%s.xy));, half2 gF = half2(2.0 * %s.x * duvdx.x - duvdx.y,               2.0 * %s.x * duvdy.x - duvdy.y);, edgeAlpha = half(%s.x * %s.x - %s.y);, edgeAlpha = sqrt(edgeAlpha * edgeAlpha / dot(gF, gF));, edgeAlpha = max(1.0 - edgeAlpha, 0.0);, Coverage, half4 %s = half4(%s * edgeAlpha);, half4 %s = half4(edgeAlpha);

#include <stdint.h>
#include <jni.h>

// Reconstructed C++ Native Implementation
extern "C" JNIEXPORT void* sub_3562b0(JNIEnv* env, jobject thiz) {
    // Function entrypoint at 0x3562b0
    // Literal reference: "HairQuadEdge"
    // Literal reference: "%s = %s;"
    // Literal reference: "inHairQuadEdge"
    // Literal reference: "half4 %s;"
    // Literal reference: "inPosition"
    // Literal reference: "inPosition"
    // Literal reference: "half edgeAlpha;"
    // Literal reference: "half2 duvdx = half2(dFdx(%s.xy));"
    // Literal reference: "half2 duvdy = half2(dFdy(%s.xy));"
    // Literal reference: "half2 gF = half2(2.0 * %s.x * duvdx.x - duvdx.y,               2.0 * %s.x * duvdy.x - duvdy.y);"
    // Literal reference: "edgeAlpha = half(%s.x * %s.x - %s.y);"
    // Literal reference: "edgeAlpha = sqrt(edgeAlpha * edgeAlpha / dot(gF, gF));"
    // Literal reference: "edgeAlpha = max(1.0 - edgeAlpha, 0.0);"
    // Literal reference: "Coverage"
    // Literal reference: "half4 %s = half4(%s * edgeAlpha);"
    // Literal reference: "half4 %s = half4(edgeAlpha);"
    return (void*)0;
}
