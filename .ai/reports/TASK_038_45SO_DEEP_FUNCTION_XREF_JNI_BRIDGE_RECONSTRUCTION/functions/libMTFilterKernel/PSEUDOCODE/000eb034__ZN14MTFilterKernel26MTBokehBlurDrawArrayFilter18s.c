// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb034
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xeb034 | Size: 256 bytes | SHA256: f23764bcca50e8fca9c697561553a52d0a266014be8fc0b78ba68f10c7cf67ea
// Callers: 1 | Callees: 5 | Imports: 3

// Calls external APIs: glActiveTexture, glBindTexture, glClear
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"

void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter18scalingFilterToFBOEiPNS_19GPUImageFramebufferE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0xeb034 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xeb038 */ str x21, [sp, #0x10];
    /* 0xeb03c */ stp x20, x19, [sp, #0x20];
    /* 0xeb040 */ mov x29, sp;
    /* 0xeb044 */ mov x19, x0;
    /* 0xeb048 */ ldr x20, [x0, #0x68];
    /* 0xeb04c */ mov x0, x2;
    /* 0xeb050 */ mov w21, w1;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    /* 0xeb058 */ mov w0, #0x4000;
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
}
