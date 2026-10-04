// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a468
// Recovered Name: sub_90a468
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a468 | Size: 144 bytes | SHA256: 5bb6b5d04da0dc39227c9e2bd3581135443d5418315c545a91b83b779cd5aa88
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_7"
//   "pNX"

void sub_90a468(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x90a468 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a46c */ str x19, [sp, #0x10];
    /* 0x90a470 */ mov x29, sp;
    /* 0x90a474 */ mov x19, x0;
    /* 0x90a478 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a480 */ ldur q0, [x19, #8];
    /* 0x90a484 */ adrp x8, #0x1078000;
    /* 0x90a488 */ add x8, x8, #0xac0;
    /* 0x90a48c */ str x8, [x0];
    /* 0x90a490 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
