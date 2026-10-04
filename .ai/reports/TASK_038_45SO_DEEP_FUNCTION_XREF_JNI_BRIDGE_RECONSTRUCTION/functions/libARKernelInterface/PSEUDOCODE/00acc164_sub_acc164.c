// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xacc164
// Recovered Name: sub_acc164
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xacc164 | Size: 1588 bytes | SHA256: ceaa2f144b090d05bc88e8424d91d7ae9691e2462e3e3f7bbaf32811dc935946
// Callers: 0 | Callees: 7 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BackTexture"
//   "BlackTexture"
//   "BlurFSPath"
//   "BlurRadius"
//   "BlurRadius2"

void sub_acc164(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 397 instructions
    /* 0xacc164 */ stp x29, x30, [sp, #0x30];
    /* 0xacc168 */ str x23, [sp, #0x40];
    /* 0xacc16c */ stp x22, x21, [sp, #0x50];
    /* 0xacc170 */ stp x20, x19, [sp, #0x60];
    /* 0xacc174 */ add x29, sp, #0x30;
    /* 0xacc178 */ mrs x23, tpidr_el0;
    /* 0xacc17c */ mov x21, x1;
    /* 0xacc180 */ mov x19, x0;
    /* 0xacc184 */ ldr x8, [x23, #0x28];
    /* 0xacc188 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8cfc();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    return x0;
    __stack_chk_fail();
}
