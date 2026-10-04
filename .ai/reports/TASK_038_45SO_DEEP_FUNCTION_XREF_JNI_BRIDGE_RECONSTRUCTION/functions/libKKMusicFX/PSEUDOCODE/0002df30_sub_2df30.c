// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2df30
// Recovered Name: sub_2df30
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2df30 | Size: 528 bytes | SHA256: ae41017ad41c656e59807b79d7698d8a9aac75d59795472cc10bfef05a1d6079
// Callers: 0 | Callees: 6 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, free, memcpy, memset

void sub_2df30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x2df30 */ stp x29, x30, [sp, #0x38];
    /* 0x2df34 */ str x25, [sp, #0x48];
    /* 0x2df38 */ stp x24, x23, [sp, #0x50];
    /* 0x2df3c */ stp x22, x21, [sp, #0x60];
    /* 0x2df40 */ stp x20, x19, [sp, #0x70];
    /* 0x2df44 */ add x29, sp, #0x38;
    /* 0x2df48 */ mrs x23, tpidr_el0;
    /* 0x2df4c */ mov w22, w1;
    /* 0x2df50 */ mov x20, x0;
    /* 0x2df54 */ ldr x8, [x23, #0x28];
    /* 0x2df58 */ add x0, sp, #0x18;
    sub_5fa80();
    sub_5fb90();
    _Znwm();
    memset();
    memcpy();
    memset();
    sub_60fd4();
    sub_5fb74();
    _ZdlPv();
    free();
    sub_5fb54();
    return x0;
    free();
    sub_5fb54();
    sub_76b64();
    __stack_chk_fail();
}
