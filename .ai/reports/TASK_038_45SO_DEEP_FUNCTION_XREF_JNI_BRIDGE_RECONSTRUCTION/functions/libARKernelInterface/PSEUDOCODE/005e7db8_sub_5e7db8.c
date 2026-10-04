// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5e7db8
// Recovered Name: sub_5e7db8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5e7db8 | Size: 996 bytes | SHA256: b1ca453d288b92580f9b93ccd3f593e9008197b2f98aad0579dbde8600c58201
// Callers: 0 | Callees: 19 | Imports: 6

// Calls external APIs: __android_log_print, __stack_chk_fail, glBindBuffer, glBindTexture, glBlendFunc, glDisable
// Strings referenced:
//   "<DoubleBuffer>"
//   "<TextureSampler>"
//   "<TextureSampler><FrameBuffer>"
//   "<Vector2>"
//   "<Vector3>f<Vector3><Vector3>"

void sub_5e7db8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 249 instructions
    /* 0x5e7db8 */ stp x29, x30, [sp, #0x20];
    /* 0x5e7dbc */ str x27, [sp, #0x30];
    /* 0x5e7dc0 */ stp x26, x25, [sp, #0x40];
    /* 0x5e7dc4 */ stp x24, x23, [sp, #0x50];
    /* 0x5e7dc8 */ stp x22, x21, [sp, #0x60];
    /* 0x5e7dcc */ stp x20, x19, [sp, #0x70];
    /* 0x5e7dd0 */ add x29, sp, #0x20;
    /* 0x5e7dd4 */ mrs x26, tpidr_el0;
    /* 0x5e7dd8 */ mov x20, x4;
    /* 0x5e7ddc */ mov x21, x2;
    /* 0x5e7de0 */ ldr x8, [x26, #0x28];
    sub_c39340();
    sub_5a6b20();
    __android_log_print();
    glBindTexture();
    sub_5e9450();
    sub_5e964c();
    glDisable();
    glBlendFunc();
    sub_d8206c();
    sub_d44604();
    sub_d91784();
    sub_d93800();
    sub_d91784();
    sub_d94048();
    sub_d91784();
    sub_dafaac();
    sub_d93800();
    sub_bbbca0();
    sub_698564();
    sub_69856c();
    sub_d93800();
    sub_d91784();
    sub_728608();
    sub_728610();
    sub_728628();
    sub_728600();
    sub_d93800();
    sub_d91784();
    sub_dacbe8();
    sub_d93800();
    sub_d91784();
    sub_dafaac();
    sub_db0008();
    sub_d93800();
    sub_d93800();
    sub_d8206c();
    glBindBuffer();
    glBindBuffer();
    return x0;
    __stack_chk_fail();
    return x0;
}
