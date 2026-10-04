// Function: MTFilterKernel::MTDrawArrayRenderFilter::renderToTexture(MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xf7ff4, Size: 1056 bytes
int64_t _ZN14MTFilterKernel23MTDrawArrayRenderFilter15renderToTextureEPNS_19GPUImageFramebufferES2_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel18MTImgTextureManger12setRatioTypeENS_24MTFilterPreviewRatioTypeE(...); // call internal at 0xf8114
    _ZN14MTFilterKernel18MTImgTextureManger14releaseTextureEv(...); // call internal at 0xf8168
    _ZN14MTFilterKernel18MTImgTextureManger14updateMaterialERNS_12InputTextureEii(...); // call internal at 0xf81a4
    _Znwm(...); // call PLT API at 0xf81d4
    _ZN14MTFilterKernel14FaceMaskFilterC2Ev(...); // call internal at 0xf81dc
    _ZN14MTFilterKernel14FaceMaskFilter10initializeEv(...); // call internal at 0xf81e8
    glDeleteTextures(...); // call PLT API at 0xf8200
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel14FaceMaskFilter19FaceMaskFilterToFBOEiiPNS_22FilterkernelNativeFaceE(...); // call internal at 0xf8254
    glDeleteTextures(...); // call PLT API at 0xf8278
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel22CalEyeMouthEyeBrowMaskEPNS_22FilterkernelNativeFaceEii(...); // call internal at 0xf82bc
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel17MTDrawArrayFilter14setDisPlayViewENS_16FilterKernelRectE(...); // call internal at 0xf8340
    _ZN14MTFilterKernel17MTDrawArrayFilter14setOrientationEi(...); // call internal at 0xf834c
    _ZN14MTFilterKernel23MTDrawArrayRenderFilter18updateInputTextureEPNS_17MTDrawArrayFilterEPNS_19GPUImageFramebufferE(...); // call internal at 0xf835c
    (*x8)(...);
    (*x8)(...);
    _ZN14MTFilterKernel17MTDrawArrayFilter17updateCalTexCoordEii(...); // call internal at 0xf8390
    _ZN14MTFilterKernel17MTDrawArrayFilter14setOrientationEi(...); // call internal at 0xf839c
    (*x8)(...);
    _ZN14MTFilterKernel16MidTextureManger29getTextureFromMidTextureArrayEiNS_6CGSizeE(...); // call internal at 0xf83d0
    return a0;
    _ZdlPv(...); // call PLT API at 0xf8408
    sub_1B0544(...); // call internal at 0xf8410
}
