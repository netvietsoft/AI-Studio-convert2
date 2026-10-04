// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf452c
// Recovered Name: sub_f452c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf452c | Size: 420 bytes | SHA256: eb29cdee9c131cc717a09ef56badc71095f44808710115de5327a94b9e76ef36
// Callers: 0 | Callees: 7 | Imports: 5

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glDrawArrays
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp"
//   "Offsets"
//   "Weights"
//   "inputImageTexture"
//   "inputTextureCoordinate"

void sub_f452c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 105 instructions
    /* 0xf452c */ stp x29, x30, [sp, #0x40];
    /* 0xf4530 */ str x23, [sp, #0x50];
    /* 0xf4534 */ stp x22, x21, [sp, #0x60];
    /* 0xf4538 */ stp x20, x19, [sp, #0x70];
    /* 0xf453c */ add x29, sp, #0x40;
    /* 0xf4540 */ mrs x23, tpidr_el0;
    /* 0xf4544 */ mov x20, x0;
    /* 0xf4548 */ mov x22, x3;
    /* 0xf454c */ ldr x8, [x23, #0x28];
    /* 0xf4550 */ mov x21, x1;
    /* 0xf4554 */ stur x8, [x29, #-8];
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
