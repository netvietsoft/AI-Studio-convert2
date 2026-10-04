// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1331d0
// Recovered Name: sub_1331d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1331d0 | Size: 884 bytes | SHA256: cf677283fe22f1a7ab1a3c96f1f373a903c204118581f9c0b4118aca775d00b7
// Callers: 0 | Callees: 9 | Imports: 10

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDrawArrays, glViewport, memcpy
// Strings referenced:
//   "attribute vec4 position; attribute vec4 inputTextureCoordinate; varying vec2 texCoord; void main() { gl_Position = vec4(position.xyz, 1.0); texCoord = inputTextureCoordinate.xy; }"
//   "blurImageTexture"
//   "inputImageMaskTexture"
//   "inputImageTexture"
//   "inputTextureCoordinate"

void sub_1331d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 221 instructions
    /* 0x1331d0 */ stp x29, x30, [sp, #0x10];
    /* 0x1331d4 */ stp x28, x27, [sp, #0x20];
    /* 0x1331d8 */ stp x26, x25, [sp, #0x30];
    /* 0x1331dc */ stp x24, x23, [sp, #0x40];
    /* 0x1331e0 */ stp x22, x21, [sp, #0x50];
    /* 0x1331e4 */ stp x20, x19, [sp, #0x60];
    /* 0x1331e8 */ add x29, sp, #0x10;
    /* 0x1331ec */ sub sp, sp, #0x250;
    /* 0x1331f0 */ mrs x22, tpidr_el0;
    /* 0x1331f4 */ mov x19, x0;
    /* 0x1331f8 */ mov w20, w1;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm();
    memcpy();
    _ZdlPv();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    _ZdlPv();
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj();
    glViewport();
    _ZN14MTFilterKernel10CGLProgram3UseEv();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glClearColor();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glActiveTexture();
    glBindTexture();
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj();
    glDrawArrays();
    glBindFramebuffer();
    return x0;
    _ZdlPv();
    sub_1b0544();
    __stack_chk_fail();
}
