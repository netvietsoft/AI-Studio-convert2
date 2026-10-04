// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x426540
// Recovered Name: _ZNSt6__ndk16vectorIN12MTImageKitNS27CMTIKWakeSkinBodyEffectTypeENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x426540 | Size: 304 bytes | SHA256: c0aacf3e0bd4a1f7d608e61500192433f5dc0c72409bf89476957c921ea43083
// Callers: 4 | Callees: 1 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, memcpy, memmove

void _ZNSt6__ndk16vectorIN12MTImageKitNS27CMTIKWakeSkinBodyEffectTypeENS_9allocatorIS2_EEE18__assign_with_sizeB8ne180000IPS2_S7_EEvT_T0_l(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 76 instructions
    /* 0x426540 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x426544 */ str x23, [sp, #0x10];
    /* 0x426548 */ stp x22, x21, [sp, #0x20];
    /* 0x42654c */ stp x20, x19, [sp, #0x30];
    /* 0x426550 */ mov x29, sp;
    /* 0x426554 */ ldr x8, [x0, #0x10];
    /* 0x426558 */ ldr x21, [x0];
    /* 0x42655c */ mov x20, x2;
    /* 0x426560 */ mov x19, x0;
    /* 0x426564 */ sub x9, x8, x21;
    /* 0x426568 */ cmp x3, x9, asr #2;
    _ZdlPv();
    _Znwm();
    memcpy();
    memmove();
    memmove();
    return x0;
    sub_426670();
}
