// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf4880
// Recovered Name: sub_f4880
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xf4880 | Size: 556 bytes | SHA256: c9ff6d933a722d535895ff9aa4654cef5747bf854f9de39274607623c020d726
// Callers: 0 | Callees: 9 | Imports: 5

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glDrawArrays
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp"
//   "gain"
//   "gradientTexture"
//   "hairMaskTexture"
//   "inputImageTexture"

void sub_f4880(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 139 instructions
    /* 0xf4880 */ stp x29, x30, [sp, #0x40];
    /* 0xf4884 */ str x25, [sp, #0x50];
    /* 0xf4888 */ stp x24, x23, [sp, #0x60];
    /* 0xf488c */ stp x22, x21, [sp, #0x70];
    /* 0xf4890 */ stp x20, x19, [sp, #0x80];
    /* 0xf4894 */ add x29, sp, #0x40;
    /* 0xf4898 */ mrs x25, tpidr_el0;
    /* 0xf489c */ mov x19, x0;
    /* 0xf48a0 */ fmov s8, s1;
    /* 0xf48a4 */ ldr x8, [x25, #0x28];
    /* 0xf48a8 */ fmov s9, s0;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb();
    _ZN14MTFilterKernel15GPUImageProgram13SetUniform1fvEPKcPKfib();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
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
