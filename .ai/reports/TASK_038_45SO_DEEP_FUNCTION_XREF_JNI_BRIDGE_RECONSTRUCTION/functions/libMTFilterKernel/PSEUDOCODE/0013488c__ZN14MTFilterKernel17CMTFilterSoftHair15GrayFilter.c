// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x13488c
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair15GrayFilterToFBOEiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x13488c | Size: 228 bytes | SHA256: 37a31f718896e600cc8d397d531aea363566e1ac713933a86ffe2fdf0cdef596
// Callers: 1 | Callees: 3 | Imports: 6

// Calls external APIs: glActiveTexture, glBindFramebuffer, glBindTexture, glClear, glDrawArrays, glViewport
// Strings referenced:
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"

void _ZN14MTFilterKernel17CMTFilterSoftHair15GrayFilterToFBOEiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x13488c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x134890 */ stp x22, x21, [sp, #0x10];
    /* 0x134894 */ stp x20, x19, [sp, #0x20];
    /* 0x134898 */ mov x29, sp;
    /* 0x13489c */ ldr x21, [x0, #0xf8];
    /* 0x1348a0 */ mov w22, w1;
    /* 0x1348a4 */ mov w0, #0x8d40;
    /* 0x1348a8 */ mov w1, w2;
    /* 0x1348ac */ mov w19, w4;
    /* 0x1348b0 */ mov w20, w3;
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
