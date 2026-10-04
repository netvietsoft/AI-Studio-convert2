// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x62bc3c
// Recovered Name: sub_62bc3c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x62bc3c | Size: 1156 bytes | SHA256: 3bb215b5fb839a1a9be54cf3e99f1f9af359bf27cb49429ac4bc9bb884f470a3
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "%.f,%.f,%.f,%.f"
//   "%.f,%.f,%.f,%.f,%.f"
//   "BlendMode"
//   "HAIR"
//   "HairType"

void sub_62bc3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 289 instructions
    /* 0x62bc3c */ stp x29, x30, [sp, #0x160];
    /* 0x62bc40 */ stp x28, x27, [sp, #0x170];
    /* 0x62bc44 */ stp x26, x25, [sp, #0x180];
    /* 0x62bc48 */ stp x24, x23, [sp, #0x190];
    /* 0x62bc4c */ stp x22, x21, [sp, #0x1a0];
    /* 0x62bc50 */ stp x20, x19, [sp, #0x1b0];
    /* 0x62bc54 */ add x29, sp, #0x160;
    /* 0x62bc58 */ mrs x8, tpidr_el0;
    /* 0x62bc5c */ mov x19, x0;
    /* 0x62bc60 */ str x8, [sp, #8];
    /* 0x62bc64 */ ldr x8, [x8, #0x28];
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_691180();
    _Znwm();
    sub_691180();
    _Znwm();
    sub_691180();
    sub_62c0c0();
    sub_58f19c();
    _ZdlPv();
    sub_62c0c0();
    sub_58f19c();
    _ZdlPv();
    sub_61d798();
    return x0;
    __stack_chk_fail();
}
