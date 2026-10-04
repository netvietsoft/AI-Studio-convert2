// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf46d4
// Recovered Name: sub_f46d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf46d4 | Size: 420 bytes | SHA256: b84f7907a2e5617db155e2fc5ab05180cf5f62f4f3ec5c38c145a759d0375d3f
// Callers: 0 | Callees: 7 | Imports: 5

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glDrawArrays
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp"
//   "Offsets"
//   "Weights"
//   "inputImageTexture"
//   "inputTextureCoordinate"

void sub_f46d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 105 instructions
    /* 0xf46d4 */ stp x29, x30, [sp, #0x40];
    /* 0xf46d8 */ str x23, [sp, #0x50];
    /* 0xf46dc */ stp x22, x21, [sp, #0x60];
    /* 0xf46e0 */ stp x20, x19, [sp, #0x70];
    /* 0xf46e4 */ add x29, sp, #0x40;
    /* 0xf46e8 */ mrs x23, tpidr_el0;
    /* 0xf46ec */ mov x20, x0;
    /* 0xf46f0 */ mov x22, x3;
    /* 0xf46f4 */ ldr x8, [x23, #0x28];
    /* 0xf46f8 */ mov x21, x1;
    /* 0xf46fc */ stur x8, [x29, #-8];
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib();
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    glDrawArrays();
    return x0;
    __stack_chk_fail();
}
