// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb6a0
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter14mixFilterToFBOEiiiPNS_19GPUImageFramebufferE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xeb6a0 | Size: 360 bytes | SHA256: 07b371a496d9bfbf9fa2e78f27a6ab20639bd387eae150740675ff22b9c73eb6
// Callers: 1 | Callees: 5 | Imports: 3

// Calls external APIs: glActiveTexture, glBindTexture, glClear
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp"
//   "bodyMaskTexture"
//   "gradientTexture"
//   "inputImageTexture"
//   "inputTextureCoordinate"

void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter14mixFilterToFBOEiiiPNS_19GPUImageFramebufferE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 90 instructions
    /* 0xeb6a0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xeb6a4 */ str x23, [sp, #0x10];
    /* 0xeb6a8 */ stp x22, x21, [sp, #0x20];
    /* 0xeb6ac */ stp x20, x19, [sp, #0x30];
    /* 0xeb6b0 */ mov x29, sp;
    /* 0xeb6b4 */ mov x19, x0;
    /* 0xeb6b8 */ ldr x20, [x0, #0x218];
    /* 0xeb6bc */ mov x0, x4;
    /* 0xeb6c0 */ mov w21, w3;
    /* 0xeb6c4 */ mov w22, w2;
    /* 0xeb6c8 */ mov w23, w1;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
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
}
