// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xaa791c
// Recovered Name: sub_aa791c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaa791c | Size: 400 bytes | SHA256: b2e12ef1bc22871d78a13923cbf1fc96e51c6d34fbef2d468cc9d93f4e95e23e
// Callers: 0 | Callees: 5 | Imports: 11

// Calls external APIs: __stack_chk_fail, glActiveTexture, glBindTexture, glDisableVertexAttribArray, glDrawArrays, glEnableVertexAttribArray, glGetUniformLocation, glUniform1i, glUseProgram, glVertexAttribPointer, glViewport
// Strings referenced:
//   "u_blurTex0"
//   "u_blurTex1"
//   "u_blurTex2"
//   "u_srcTex"

void sub_aa791c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 100 instructions
    /* 0xaa791c */ stp x29, x30, [sp, #0x30];
    /* 0xaa7920 */ stp x20, x19, [sp, #0x40];
    /* 0xaa7924 */ add x29, sp, #0x30;
    /* 0xaa7928 */ mrs x20, tpidr_el0;
    /* 0xaa792c */ adrp x9, #0x26a000;
    /* 0xaa7930 */ add x9, x9, #0x7d8;
    /* 0xaa7934 */ ldr x8, [x20, #0x28];
    /* 0xaa7938 */ mov x19, x0;
    /* 0xaa793c */ ldr q0, [x9];
    /* 0xaa7940 */ ldr q1, [x9, #0x10];
    /* 0xaa7944 */ stur x8, [x29, #-8];
    sub_697fb4();
    glViewport();
    glUseProgram();
    glVertexAttribPointer();
    glEnableVertexAttribArray();
    glActiveTexture();
    sub_698574();
    sub_69b7c4();
    glBindTexture();
    glGetUniformLocation();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glGetUniformLocation();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glGetUniformLocation();
    glUniform1i();
    glActiveTexture();
    glBindTexture();
    glGetUniformLocation();
    glUniform1i();
    glDrawArrays();
    glDisableVertexAttribArray();
    sub_698448();
    sub_697894();
    return x0;
    __stack_chk_fail();
}
