// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8d3658
// Recovered Name: sub_8d3658
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8d3658 | Size: 3464 bytes | SHA256: 659f811b77abfdecb8776318fb3d8249ec490ebbcd7d1796b6c16fb9e14354cb
// Callers: 0 | Callees: 7 | Imports: 2

// Calls external APIs: _ZdlPv, memmove
// Strings referenced:
//   "BaseFSPath"
//   "BaseVSPath"
//   "EyeBrowLutPath"
//   "EyeFSPath"
//   "EyeLBlinkBSPath"

void sub_8d3658(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 866 instructions
    /* 0x8d3658 */ stp x29, x30, [sp, #0x150];
    /* 0x8d365c */ stp x28, x27, [sp, #0x160];
    /* 0x8d3660 */ stp x26, x25, [sp, #0x170];
    /* 0x8d3664 */ stp x24, x23, [sp, #0x180];
    /* 0x8d3668 */ stp x22, x21, [sp, #0x190];
    /* 0x8d366c */ stp x20, x19, [sp, #0x1a0];
    /* 0x8d3670 */ add x29, sp, #0x150;
    /* 0x8d3674 */ mrs x8, tpidr_el0;
    /* 0x8d3678 */ mov x19, x1;
    /* 0x8d367c */ mov x20, x0;
    /* 0x8d3680 */ stur x8, [x29, #-0x60];
    sub_61bfa0();
    sub_5abbf8();
    memmove();
    _ZdlPv();
    sub_570f58();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_5b9000();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
}
