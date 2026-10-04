// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x6faf8
// Recovered Name: _ZN17MMDetectionPlugin17ExDenseHairModule16setEnableFaceIdsERNSt6__ndk16vectorIlNS1_9allocatorIlEEEEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6faf8 | Size: 72 bytes | SHA256: 0f2cb113668e2ff473aa5374c530c1a249b7f0a3932ad31cf5cbb7f7581dafac
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk16vectorIlNS_9allocatorIlEEE18__assign_with_sizeB8ne180000IPlS5_EEvT_T0_l

void _ZN17MMDetectionPlugin17ExDenseHairModule16setEnableFaceIdsERNSt6__ndk16vectorIlNS1_9allocatorIlEEEEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x6faf8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x6fafc */ stp x20, x19, [sp, #0x10];
    /* 0x6fb00 */ mov x29, sp;
    /* 0x6fb04 */ mov x19, x0;
    /* 0x6fb08 */ add x0, x0, #0x50;
    /* 0x6fb0c */ mov w20, w2;
    /* 0x6fb10 */ cmp x0, x1;
    /* 0x6fb14 */ b.eq #0x6fb2c;
    /* 0x6fb18 */ ldp x8, x2, [x1];
    /* 0x6fb1c */ sub x9, x2, x8;
    /* 0x6fb20 */ mov x1, x8;
    _ZNSt6__ndk16vectorIlNS_9allocatorIlEEE18__assign_with_sizeB8ne180000IPlS5_EEvT_T0_l();
    return x0;
}
