// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xfbc70
// Recovered Name: sub_fbc70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xfbc70 | Size: 1268 bytes | SHA256: 211d154cf482d17f3a36420b1bef60d8953db75e5ad44ff862659f44e1525679
// Callers: 0 | Callees: 10 | Imports: 4

// Calls external APIs: __stack_chk_fail, glClear, glClearColor, glUniform1f
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/MTBlurAlongFilter.cpp"
//   "inputImageTexture"
//   "inputImageTexture2"
//   "inputImageTexture3"
//   "inputTextureCoordinate"

void sub_fbc70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 317 instructions
    /* 0xfbc70 */ stp x29, x30, [sp, #0xb0];
    /* 0xfbc74 */ stp x28, x27, [sp, #0xc0];
    /* 0xfbc78 */ stp x26, x25, [sp, #0xd0];
    /* 0xfbc7c */ stp x24, x23, [sp, #0xe0];
    /* 0xfbc80 */ stp x22, x21, [sp, #0xf0];
    /* 0xfbc84 */ stp x20, x19, [sp, #0x100];
    /* 0xfbc88 */ add x29, sp, #0xb0;
    /* 0xfbc8c */ stp x4, x2, [sp, #0x28];
    /* 0xfbc90 */ mrs x8, tpidr_el0;
    /* 0xfbc94 */ mov x23, x3;
    /* 0xfbc98 */ str x8, [sp, #0x38];
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji();
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc();
    glUniform1f();
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc();
    glUniform1f();
    glClearColor();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii();
    _ZN14MTFilterKernel15GPUImageContext16fetchFramebufferENS_6CGSizeENS_17GPUTextureOptionsEbjji();
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc();
    glUniform1f();
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc();
    glUniform1f();
    glClearColor();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    glClearColor();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj();
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj();
    _ZN14MTFilterKernel15GPUImageProgram12SetTexture2DEPKcj();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    return x0;
    __stack_chk_fail();
}
