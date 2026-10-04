// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1239c8
// Recovered Name: sub_1239c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1239c8 | Size: 1600 bytes | SHA256: d2b12bed1c888bf8eeb81be73a6a5c25e087dc3f98d25df29d800ad424c607dd
// Callers: 0 | Callees: 8 | Imports: 10

// Calls external APIs: __android_log_print, __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glDeleteFramebuffers, glDeleteTextures, glDrawArrays, glViewport, sinf
// Strings referenced:
//   "FilterKernel"
//   "alpha"
//   "bind blur fbo failed"
//   "bind fbo fail"
//   "direction"

void sub_1239c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 400 instructions
    /* 0x1239c8 */ stp x29, x30, [sp, #0x70];
    /* 0x1239cc */ stp x28, x27, [sp, #0x80];
    /* 0x1239d0 */ stp x26, x25, [sp, #0x90];
    /* 0x1239d4 */ stp x24, x23, [sp, #0xa0];
    /* 0x1239d8 */ stp x22, x21, [sp, #0xb0];
    /* 0x1239dc */ stp x20, x19, [sp, #0xc0];
    /* 0x1239e0 */ add x29, sp, #0x70;
    /* 0x1239e4 */ str w3, [sp, #4];
    /* 0x1239e8 */ mrs x8, tpidr_el0;
    /* 0x1239ec */ mov x19, x0;
    /* 0x1239f0 */ str x8, [sp, #8];
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteFramebuffers();
    glDeleteTextures();
    glClear();
    glViewport();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    sinf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glDrawArrays();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    sinf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glDrawArrays();
    glClear();
    glViewport();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii();
    glViewport();
    glClear();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glDrawArrays();
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv();
    __stack_chk_fail();
    MTRTFILTERKERNEL_GetLogLevel();
}
