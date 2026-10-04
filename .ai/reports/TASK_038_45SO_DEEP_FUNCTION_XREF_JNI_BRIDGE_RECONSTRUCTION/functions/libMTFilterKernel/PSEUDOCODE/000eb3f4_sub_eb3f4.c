// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb3f4
// Recovered Name: sub_eb3f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xeb3f4 | Size: 684 bytes | SHA256: b39aad8aabc6e291835d1a78c459d9bb97989409b0a566f8dcf176ed03c1e33e
// Callers: 0 | Callees: 7 | Imports: 4

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glClear
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp"
//   "diaphragmImage"
//   "farDepth"
//   "farRadius"
//   "highlights"

void sub_eb3f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 171 instructions
    /* 0xeb3f4 */ stp x29, x30, [sp, #0x50];
    /* 0xeb3f8 */ str x25, [sp, #0x60];
    /* 0xeb3fc */ stp x24, x23, [sp, #0x70];
    /* 0xeb400 */ stp x22, x21, [sp, #0x80];
    /* 0xeb404 */ stp x20, x19, [sp, #0x90];
    /* 0xeb408 */ add x29, sp, #0x50;
    /* 0xeb40c */ mrs x25, tpidr_el0;
    /* 0xeb410 */ mov x19, x0;
    /* 0xeb414 */ mov x24, x4;
    /* 0xeb418 */ ldr x8, [x25, #0x28];
    /* 0xeb41c */ mov w20, w3;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1fEPKcfb();
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
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii();
    return x0;
    __stack_chk_fail();
}
