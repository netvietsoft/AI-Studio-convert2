// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x122d88
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilter18ScalingFilterToFBOEiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x122d88 | Size: 228 bytes | SHA256: 734fb72b5cab5d6dad6807e2f79ef64acc0aeea841f2d38b94b6b4e08276e306
// Callers: 1 | Callees: 3 | Imports: 6

// Calls external APIs: glActiveTexture, glBindFramebuffer, glBindTexture, glClear, glDrawArrays, glViewport
// Strings referenced:
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"

void _ZN14MTFilterKernel18CMTBokehBlurFilter18ScalingFilterToFBOEiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x122d88 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x122d8c */ stp x22, x21, [sp, #0x10];
    /* 0x122d90 */ stp x20, x19, [sp, #0x20];
    /* 0x122d94 */ mov x29, sp;
    /* 0x122d98 */ ldr x21, [x0, #0xf8];
    /* 0x122d9c */ mov w22, w1;
    /* 0x122da0 */ mov w0, #0x8d40;
    /* 0x122da4 */ mov w1, w2;
    /* 0x122da8 */ mov w19, w4;
    /* 0x122dac */ mov w20, w3;
    glBindFramebuffer();
    glViewport();
    glClear();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
}
