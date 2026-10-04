// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x134970
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair19HairMaskFilterToFBOEiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x134970 | Size: 288 bytes | SHA256: e9b1082fc0c7c8954d64287e5a32dcb93b0f24f185479916557dd8123acc64a3
// Callers: 1 | Callees: 4 | Imports: 6

// Calls external APIs: glActiveTexture, glBindFramebuffer, glBindTexture, glClear, glDrawArrays, glViewport
// Strings referenced:
//   "inputImageTexture"
//   "inputTextureCoordinate"
//   "position"
//   "shiftingSize"

void _ZN14MTFilterKernel17CMTFilterSoftHair19HairMaskFilterToFBOEiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 72 instructions
    /* 0x134970 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x134974 */ str x23, [sp, #0x10];
    /* 0x134978 */ stp x22, x21, [sp, #0x20];
    /* 0x13497c */ stp x20, x19, [sp, #0x30];
    /* 0x134980 */ mov x29, sp;
    /* 0x134984 */ mov x22, x0;
    /* 0x134988 */ ldr x19, [x0, #0x108];
    /* 0x13498c */ mov w23, w1;
    /* 0x134990 */ mov w0, #0x8d40;
    /* 0x134994 */ mov w1, w2;
    /* 0x134998 */ mov w20, w4;
    glBindFramebuffer();
    glViewport();
    glClear();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
}
