// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x13375c
// Recovered Name: sub_13375c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x13375c | Size: 1296 bytes | SHA256: c041f7373d3da6d07bb8b99585a31879e0ea5bed14d0782b7a0a700b00605593
// Callers: 0 | Callees: 7 | Imports: 18

// Calls external APIs: __android_log_print, __stack_chk_fail, glActiveTexture, glBindFramebuffer, glBindTexture, glClearColor, glDeleteFramebuffers, glDeleteTextures, glDrawArrays, glEnableVertexAttribArray, glGetAttribLocation, glGetError, glGetUniformLocation, glUniform1f, glUniform1i, glUseProgram, glVertexAttribPointer, glViewport
// Strings referenced:
//   "/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/OnlineFilter/Filters/MTXTDetailsFilter.cpp"
//   "FilterKernel"
//   "bin fbo fail"
//   "blurImageTexture"
//   "colorA"

void sub_13375c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 324 instructions
    /* 0x13375c */ ldr w8, [x19, #0x3c];
    /* 0x133760 */ cmp w8, w22;
    /* 0x133764 */ b.ne #0x133774;
    /* 0x133768 */ ldr w8, [x19, #0x40];
    /* 0x13376c */ cmp w8, w21;
    /* 0x133770 */ b.eq #0x13380c;
    /* 0x133774 */ mov x20, x19;
    /* 0x133778 */ mov w8, #1;
    /* 0x13377c */ ldr w9, [x20, #0x98]!;
    /* 0x133780 */ strb w8, [x20, #0x48];
    /* 0x133784 */ stp w22, w21, [x20, #-0x5c];
    glDeleteFramebuffers();
    glDeleteTextures();
    glDeleteTextures();
    glDeleteTextures();
    glDeleteTextures();
    _ZN14MTFilterKernel18CMTXTDetailsFilter4blurEjff();
    _ZN14MTFilterKernel18CMTXTDetailsFilter19drawWithBlurAndMaskEj();
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    _ZN14MTFilterKernel16CMTDynamicFilter19CopyTextureContentsEjj();
    glGetError();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii();
    glViewport();
    glUseProgram();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetUniformLocation();
    glGetAttribLocation();
    glGetAttribLocation();
    glUniform1f();
    glUniform1f();
    glUniform1f();
    glUniform1f();
    glUniform1f();
    glUniform1f();
    glClearColor();
    glEnableVertexAttribArray();
    glVertexAttribPointer();
    glEnableVertexAttribArray();
    glVertexAttribPointer();
    glActiveTexture();
    glBindTexture();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glUniform1i();
    glDrawArrays();
    glBindFramebuffer();
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    __stack_chk_fail();
}
