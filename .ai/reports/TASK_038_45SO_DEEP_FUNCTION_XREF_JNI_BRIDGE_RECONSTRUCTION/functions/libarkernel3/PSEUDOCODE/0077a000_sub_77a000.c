// Library: libarkernel3.so
// Function ID: libarkernel3::0x77a000
// Recovered Name: sub_77a000
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x77a000 | Size: 1516 bytes | SHA256: 9225acdb9229a3b97aa7a6f976984384849898d45ef8b2be32f46cf26b342acb
// Callers: 0 | Callees: 33 | Imports: 4

// Calls external APIs: _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "<DoubleBuffer>"
//   "<FParamBase>"
//   "ScriptPart QuerySegmentMask error! segmentType = %d"
//   "ScriptPart::initialize can't find function seekWithConfig, check your lua code, it means you need multiplyInstance"
//   "fi"

void sub_77a000(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 379 instructions
    /* 0x77a000 */ stp x29, x30, [sp, #0x60];
    /* 0x77a004 */ stp x28, x27, [sp, #0x70];
    /* 0x77a008 */ stp x26, x25, [sp, #0x80];
    /* 0x77a00c */ stp x24, x23, [sp, #0x90];
    /* 0x77a010 */ stp x22, x21, [sp, #0xa0];
    /* 0x77a014 */ stp x20, x19, [sp, #0xb0];
    /* 0x77a018 */ add x29, sp, #0x60;
    /* 0x77a01c */ mrs x25, tpidr_el0;
    /* 0x77a020 */ mov x27, x1;
    /* 0x77a024 */ mov x19, x0;
    /* 0x77a028 */ ldr x8, [x25, #0x28];
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_a43064();
    sub_a576d8();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c190();
    sub_5fb7d8();
    sub_aa29ec();
    sub_a8e5a8();
    sub_d7c64c();
    sub_d7d420();
    sub_9fe8fc();
    sub_a43054();
    sub_a469bc();
    sub_76d78c();
    sub_864b34();
    sub_5fd9ac();
    _ZdlPv();
    sub_5fa1cc();
    sub_77a5ec();
    _ZNSt6__ndk15mutex4lockEv();
    sub_d7c64c();
    sub_e2b908();
    sub_e2d984();
    _ZNSt6__ndk15mutex6unlockEv();
    sub_d7c64c();
    sub_e2b908();
    sub_e2d984();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c190();
    sub_cccfe0();
    sub_e2d984();
    sub_d7c64c();
    sub_a59d1c();
    sub_a59d24();
    sub_e168d8();
    sub_d7ce5c();
    sub_e168fc();
    sub_a59d1c();
    sub_a59d24();
    sub_e2d984();
    sub_5ed1f8();
    sub_e2d984();
    sub_5ed8d8();
    sub_77ade0();
    sub_77ae4c();
    _ZdlPv();
    return x0;
    sub_5fd998();
    sub_e168fc();
    _ZNSt6__ndk15mutex6unlockEv();
    sub_77ae4c();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
