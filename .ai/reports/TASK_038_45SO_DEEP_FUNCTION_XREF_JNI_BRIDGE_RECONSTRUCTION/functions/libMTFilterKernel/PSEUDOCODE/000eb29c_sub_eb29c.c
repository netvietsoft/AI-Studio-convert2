// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb29c
// Recovered Name: sub_eb29c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xeb29c | Size: 340 bytes | SHA256: f15ed44d78ca8f87f4805349030f443c476c2021b245885fb51cc21054797b93
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: glActiveTexture, glBindTexture, glClear
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"
//   "radius"

void sub_eb29c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 85 instructions
    /* 0xeb29c */ stp x29, x30, [sp, #0x10];
    /* 0xeb2a0 */ stp x22, x21, [sp, #0x20];
    /* 0xeb2a4 */ stp x20, x19, [sp, #0x30];
    /* 0xeb2a8 */ add x29, sp, #0x10;
    /* 0xeb2ac */ mov x19, x0;
    /* 0xeb2b0 */ ldr x21, [x0, #0x210];
    /* 0xeb2b4 */ mov x0, x2;
    /* 0xeb2b8 */ fmov s8, s0;
    /* 0xeb2bc */ mov x20, x2;
    /* 0xeb2c0 */ mov w22, w1;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
}
