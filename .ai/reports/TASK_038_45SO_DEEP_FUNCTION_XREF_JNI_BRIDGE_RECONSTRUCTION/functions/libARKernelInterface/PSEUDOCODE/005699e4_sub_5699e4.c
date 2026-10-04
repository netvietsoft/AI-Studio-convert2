// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5699e4
// Recovered Name: sub_5699e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5699e4 | Size: 196 bytes | SHA256: 6d4cf3b2745217e950e14fc19f8661f6781f3d1a200d0bdbc9bb23c30c937548
// Callers: 0 | Callees: 4 | Imports: 4

// Dynamic Registration: nativeCreateInstance()J (table at 0x10ccd70)
// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, memset

jlong sub_5699e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x5699e4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5699e8 */ stp x28, x21, [sp, #0x10];
    /* 0x5699ec */ stp x20, x19, [sp, #0x20];
    /* 0x5699f0 */ mov x29, sp;
    /* 0x5699f4 */ sub sp, sp, #7, lsl #12;
    /* 0x5699f8 */ sub sp, sp, #0x320;
    /* 0x5699fc */ mrs x21, tpidr_el0;
    /* 0x569a00 */ mov w0, #0x7318;
    /* 0x569a04 */ ldr x8, [x21, #0x28];
    /* 0x569a08 */ stur x8, [x29, #-8];
    _Znwm();
    sub_569aa8();
    memset();
    sub_569aa8();
    sub_569d64();
    sub_569e84();
    return x0;
    sub_569e84();
    _ZdlPv();
    sub_1042be4();
    __stack_chk_fail();
}
