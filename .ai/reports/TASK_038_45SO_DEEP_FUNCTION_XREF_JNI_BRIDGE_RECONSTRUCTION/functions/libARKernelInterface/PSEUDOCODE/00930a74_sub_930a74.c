// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x930a74
// Recovered Name: sub_930a74
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x930a74 | Size: 1156 bytes | SHA256: c58e443b0d019f83d13c484a6bc30e8de12695033b5908e038f73e47f987d040
// Callers: 0 | Callees: 18 | Imports: 7

// Calls external APIs: __android_log_print, __stack_chk_fail, glBindBuffer, glBindTexture, glBlendFunc, glDisable, glViewport
// Strings referenced:
//   "<DoubleBuffer>"
//   "CoreScriptPart::initialize can't find function seekWithConfig, check your lua code, it means you need multiplyInstance"
//   "ScriptPart QuerySegmentMask error! segmentType = %d"
//   "arkernel"
//   "fi"

void sub_930a74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 289 instructions
    /* 0x930a74 */ stp x29, x30, [sp, #0x28];
    /* 0x930a78 */ str x27, [sp, #0x38];
    /* 0x930a7c */ stp x26, x25, [sp, #0x40];
    /* 0x930a80 */ stp x24, x23, [sp, #0x50];
    /* 0x930a84 */ stp x22, x21, [sp, #0x60];
    /* 0x930a88 */ stp x20, x19, [sp, #0x70];
    /* 0x930a8c */ add x29, sp, #0x28;
    /* 0x930a90 */ mrs x27, tpidr_el0;
    /* 0x930a94 */ mov x19, x0;
    /* 0x930a98 */ mov x20, x1;
    /* 0x930a9c */ ldr x8, [x27, #0x28];
    sub_6b0f70();
    sub_c39340();
    sub_5a6b20();
    __android_log_print();
    sub_c37e9c();
    sub_c39340();
    sub_5a6b20();
    __android_log_print();
    sub_c39340();
    sub_698564();
    sub_69856c();
    sub_bbbca0();
    glViewport();
    sub_d44604();
    sub_d7fb90();
    sub_d45160();
    sub_d7fbb4();
    glBindTexture();
    sub_5e9450();
    sub_5e964c();
    glDisable();
    glBlendFunc();
    sub_d8206c();
    sub_d44604();
    sub_d91784();
    sub_d93800();
    sub_5a6b20();
    __android_log_print();
    sub_c42150();
    sub_d93800();
    sub_d93800();
    sub_d93800();
    sub_d8206c();
    glBindBuffer();
    glBindBuffer();
    sub_697894();
    return x0;
    __stack_chk_fail();
}
