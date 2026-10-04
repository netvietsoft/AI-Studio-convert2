// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf4400
// Recovered Name: _ZN14MTFilterKernel16MTSoftHairFilter19hairMaskFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xf4400 | Size: 296 bytes | SHA256: ea82240b3b4eafb1168f46f3c3e7e02fd91a0ea13d7469d3b99fec727ef004a8
// Callers: 1 | Callees: 7 | Imports: 4

// Calls external APIs: glActiveTexture, glBindTexture, glClear, glDrawArrays
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"
//   "shiftingSize"

void _ZN14MTFilterKernel16MTSoftHairFilter19hairMaskFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 74 instructions
    /* 0xf4400 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xf4404 */ stp x22, x21, [sp, #0x10];
    /* 0xf4408 */ stp x20, x19, [sp, #0x20];
    /* 0xf440c */ mov x29, sp;
    /* 0xf4410 */ mov x20, x0;
    /* 0xf4414 */ ldr x19, [x0, #0x1d0];
    /* 0xf4418 */ mov x0, x4;
    /* 0xf441c */ mov x21, x3;
    /* 0xf4420 */ mov x22, x1;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    /* 0xf4428 */ mov w0, #0x4000;
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform2fEPKcffb();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
}
