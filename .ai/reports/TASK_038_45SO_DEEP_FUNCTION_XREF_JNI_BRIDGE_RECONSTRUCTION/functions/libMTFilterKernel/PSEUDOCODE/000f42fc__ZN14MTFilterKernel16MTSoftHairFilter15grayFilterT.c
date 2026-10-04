// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf42fc
// Recovered Name: _ZN14MTFilterKernel16MTSoftHairFilter15grayFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xf42fc | Size: 260 bytes | SHA256: 0999c778b8fd5385af81049e78795bce70a9c09457370ca4f4d8f40dd15b41e6
// Callers: 1 | Callees: 6 | Imports: 4

// Calls external APIs: glActiveTexture, glBindTexture, glClear, glDrawArrays
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"

void _ZN14MTFilterKernel16MTSoftHairFilter15grayFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0xf42fc */ stp x29, x30, [sp, #-0x30]!;
    /* 0xf4300 */ stp x22, x21, [sp, #0x10];
    /* 0xf4304 */ stp x20, x19, [sp, #0x20];
    /* 0xf4308 */ mov x29, sp;
    /* 0xf430c */ mov x20, x0;
    /* 0xf4310 */ ldr x19, [x0, #0x1c8];
    /* 0xf4314 */ mov x0, x4;
    /* 0xf4318 */ mov x21, x3;
    /* 0xf431c */ mov x22, x1;
    _ZN14MTFilterKernel19GPUImageFramebuffer19activateFramebufferEv();
    /* 0xf4324 */ mov w0, #0x4000;
    glClear();
    _ZN14MTFilterKernel15GPUImageProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel15GPUImageProgram12SetUniform1iEPKcjb();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
    _ZN14MTFilterKernel12MTFilterBase29textureCoordinatesForRotationENS_20GPUImageRotationModeE();
    _ZN14MTFilterKernel15GPUImageContext9fetchMeshEPKfjjbPKcPvl();
    _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE();
}
