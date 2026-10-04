// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeb13c
// Recovered Name: sub_eb13c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xeb13c | Size: 348 bytes | SHA256: b584b1f24f52db3c039d2de4e81110ebbba82d605bf525f866547fa5dd5d94fe
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: glActiveTexture, glBindTexture, glClear
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTBokehBlurDrawArrayFilter.cpp"
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"
//   "singleStepOffsetHeight"

void sub_eb13c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 87 instructions
    /* 0xeb13c */ stp x29, x30, [sp, #0x18];
    /* 0xeb140 */ str x21, [sp, #0x28];
    /* 0xeb144 */ stp x20, x19, [sp, #0x30];
    /* 0xeb148 */ add x29, sp, #0x18;
    /* 0xeb14c */ mov x19, x0;
    /* 0xeb150 */ mov x0, x2;
    /* 0xeb154 */ fmov s8, s2;
    /* 0xeb158 */ ldr x20, [x19, #0x208];
    /* 0xeb15c */ fmov s9, s1;
    /* 0xeb160 */ fmov s10, s0;
    /* 0xeb164 */ mov w21, w1;
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
