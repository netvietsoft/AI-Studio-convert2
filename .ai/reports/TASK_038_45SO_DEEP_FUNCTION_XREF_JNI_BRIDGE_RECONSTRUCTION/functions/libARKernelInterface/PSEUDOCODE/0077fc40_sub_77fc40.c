// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x77fc40
// Recovered Name: sub_77fc40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x77fc40 | Size: 1200 bytes | SHA256: 88cfa448e0659f26c84450ce0fe9b670028db786dbcc40287f2ddcd80c6887d5
// Callers: 0 | Callees: 14 | Imports: 8

// Calls external APIs: __android_log_print, __stack_chk_fail, glActiveTexture, glBindTexture, glClear, glClearColor, glDrawArrays, glViewport
// Strings referenced:
//   "Core3DBodyPart::blurAndMixTexture: FBO is null"
//   "a_position"
//   "a_texCoord"
//   "arkernel"
//   "degree"

void sub_77fc40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 300 instructions
    /* 0x77fc40 */ stp x29, x30, [sp, #0x110];
    /* 0x77fc44 */ stp x28, x27, [sp, #0x120];
    /* 0x77fc48 */ stp x26, x25, [sp, #0x130];
    /* 0x77fc4c */ stp x24, x23, [sp, #0x140];
    /* 0x77fc50 */ stp x22, x21, [sp, #0x150];
    /* 0x77fc54 */ stp x20, x19, [sp, #0x160];
    /* 0x77fc58 */ add x29, sp, #0x110;
    /* 0x77fc5c */ mrs x20, tpidr_el0;
    /* 0x77fc60 */ ldr x8, [x20, #0x28];
    /* 0x77fc64 */ stur x8, [x29, #-0x28];
    /* 0x77fc68 */ ldr x8, [x0, #0xd38];
    sub_69b7cc();
    sub_69b7d4();
    sub_c41220();
    sub_77e854();
    sub_c41788();
    sub_c41220();
    sub_77e854();
    sub_bc67b4();
    sub_fc2a84();
    sub_c40be0();
    sub_5a6b20();
    sub_bc0c54();
    sub_bc06fc();
    glClearColor();
    glClear();
    glViewport();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glActiveTexture();
    sub_69b7c4();
    glBindTexture();
    glDrawArrays();
    sub_bc0c54();
    sub_bc06fc();
    sub_c41788();
    sub_c40e68();
    sub_c40e68();
    sub_bc68d0();
    return x0;
    __android_log_print();
    __stack_chk_fail();
}
