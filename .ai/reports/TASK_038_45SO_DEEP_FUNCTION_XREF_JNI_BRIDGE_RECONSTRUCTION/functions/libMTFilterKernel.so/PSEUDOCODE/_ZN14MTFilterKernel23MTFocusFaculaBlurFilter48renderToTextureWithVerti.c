// Function: MTFilterKernel::MTFocusFaculaBlurFilter::renderToTextureWithVerticesAndTextureCoordinates(float const*, float const*, MTFilterKernel::GPUImageFramebuffer*, MTFilterKernel::GPUImageFramebuffer*)
// RVA: 0xdc760, Size: 4096 bytes
int64_t _ZN14MTFilterKernel23MTFocusFaculaBlurFilter48renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    _ZN14MTFilterKernel7GLUtils16LoadTexture_BYTEEPhiij(...); // call internal at 0xdc85c
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdc8c8
    glClearColor(...); // call PLT API at 0xdc8d4
    glClear(...); // call PLT API at 0xdc8dc
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdc8e4
    const char* str = "fabbyMask";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdc8fc
    const char* str = "textureWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdc918
    const char* str = "textureHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdc934
    const char* str = "radius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdc970
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTFocusFaculaBlurFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdc9a0
    const char* str = "a_position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdc9b8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdc9e0
    const char* str = "a_texCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdc9f8
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdca0c
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdca4c
    glClearColor(...); // call PLT API at 0xdca58
    glClear(...); // call PLT API at 0xdca60
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdca68
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdca78
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdca8c
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcaa0
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcad8
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTFocusFaculaBlurFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcb08
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcb18
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcb40
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcb50
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdcb64
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdcba4
    glClearColor(...); // call PLT API at 0xdcbb0
    glClear(...); // call PLT API at 0xdcbb8
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdcbc0
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdcbd4
    const char* str = "type";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcbec
    const char* str = "singleStepOffsetWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcc14
    const char* str = "singleStepOffsetHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcc30
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcc58
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcc68
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcc90
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcca0
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdccb4
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdccbc
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdcd00
    glClearColor(...); // call PLT API at 0xdcd0c
    glClear(...); // call PLT API at 0xdcd14
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdcd1c
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdcd30
    const char* str = "type";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcd4c
    const char* str = "singleStepOffsetWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcd68
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcd8c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTFocusFaculaBlurFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcdbc
    const char* str = "a_position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcdd4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcdfc
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdce0c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdce20
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdce28
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdce6c
    glClearColor(...); // call PLT API at 0xdce78
    glClear(...); // call PLT API at 0xdce80
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdce88
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdcea0
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdceb4
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcec8
    const char* str = "singleStepOffsetHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdcef4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcf1c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcf2c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdcf54
    const char* str = "a_texCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdcf6c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdcf80
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdcfbc
    glClearColor(...); // call PLT API at 0xdcfc8
    glClear(...); // call PLT API at 0xdcfd0
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdcfd8
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdcfec
    const char* str = "type";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd004
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd028
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd03c
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTFocusFaculaBlurFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd070
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd080
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd0ac
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd0bc
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdd0d0
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdd0d8
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdd190
    glClearColor(...); // call PLT API at 0xdd19c
    glClear(...); // call PLT API at 0xdd1a4
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdd1ac
    const char* str = "inputImage";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd1c0
    const char* str = "maskResult";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd1d8
    const char* str = "diaphragmImage";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd1ec
    const char* str = "imagewidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd204
    const char* str = "imageheight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd220
    const char* str = "maskradius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd23c
    const char* str = "farDepth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd25c
    const char* str = "nearDepth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd274
    const char* str = "farRadius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd28c
    const char* str = "nearRadius";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd2a4
    const char* str = "highlights";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd2c0
    const char* str = "vivid";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd2e0
    const char* str = "mattebox";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd2f8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd31c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd32c
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd354
    const char* str = "a_texCoord";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd36c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdd380
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdd388
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdd390
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdd3d4
    glClearColor(...); // call PLT API at 0xdd3e0
    glClear(...); // call PLT API at 0xdd3e8
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdd3f0
    const char* str = "texture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd408
    const char* str = "type";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd420
    const char* str = "singleStepOffsetWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd438
    const char* str = "singleStepOffsetHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd460
    const char* str = "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/Defocus/MTFocusFaculaBlurFilter.cpp";
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd490
    const char* str = "a_position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd4a8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd4d8
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd4e8
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdd4fc
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdd538
    glClearColor(...); // call PLT API at 0xdd544
    glClear(...); // call PLT API at 0xdd54c
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdd554
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd564
    const char* str = "type";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd57c
    const char* str = "singleStepOffsetWidth";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd5a4
    const char* str = "singleStepOffsetHeight";
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb(...); // call internal at 0xdd5bc
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd5e4
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd5f4
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd61c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd62c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdd640
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdd648
    (*x8)(...);
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv(...); // call internal at 0xdd684
    glClearColor(...); // call PLT API at 0xdd690
    glClear(...); // call PLT API at 0xdd698
    _ZN14MTFilterKernel15GPUImageProgram3UseEv(...); // call internal at 0xdd6a0
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd6b4
    const char* str = "blurTexture";
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj(...); // call internal at 0xdd6c8
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd6f0
    const char* str = "a_position";
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd704
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl(...); // call internal at 0xdd72c
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(...); // call internal at 0xdd73c
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(...); // call internal at 0xdd750
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv(...); // call internal at 0xdd758
}
