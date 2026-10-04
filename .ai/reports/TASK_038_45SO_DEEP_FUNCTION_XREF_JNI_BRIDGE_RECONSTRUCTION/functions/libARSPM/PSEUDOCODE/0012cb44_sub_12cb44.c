// Library: libARSPM.so
// Function ID: libARSPM::0x12cb44
// Recovered Name: sub_12cb44
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x12cb44 | Size: 228 bytes | SHA256: 926359f4a6e38e4e45c1a877a9906a06d53b32077ba950552a6d0c89a3b58c99
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _Znwm, __stack_chk_fail

void sub_12cb44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x12cb44 */ stp x29, x30, [sp, #0x20];
    /* 0x12cb48 */ stp x20, x19, [sp, #0x30];
    /* 0x12cb4c */ add x29, sp, #0x20;
    /* 0x12cb50 */ mrs x20, tpidr_el0;
    /* 0x12cb54 */ mov x19, x0;
    /* 0x12cb58 */ ldr x8, [x20, #0x28];
    /* 0x12cb5c */ stur x8, [x29, #-8];
    /* 0x12cb60 */ stp xzr, xzr, [x0];
    /* 0x12cb64 */ mov w0, #0x60;
    _Znwm();
    /* 0x12cb6c */ adrp x8, #0x4f5000;
    sub_131380();
    sub_4ecb70();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_1313dc();
    sub_4eccd4();
    __stack_chk_fail();
}
