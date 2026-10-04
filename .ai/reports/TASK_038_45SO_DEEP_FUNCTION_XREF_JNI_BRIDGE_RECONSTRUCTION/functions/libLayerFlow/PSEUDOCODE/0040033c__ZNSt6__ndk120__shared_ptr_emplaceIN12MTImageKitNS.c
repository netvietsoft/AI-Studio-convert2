// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x40033c
// Recovered Name: _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS25CMTIKWhiteHairAIGCRequestENS_9allocatorIS2_EEED0Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x40033c | Size: 52 bytes | SHA256: 7a6181c0571bf0d4aa50a68c7fcd9b79206ac0ceeebfeb8482c1266ed569126b
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdlPv

void _ZNSt6__ndk120__shared_ptr_emplaceIN12MTImageKitNS25CMTIKWhiteHairAIGCRequestENS_9allocatorIS2_EEED0Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x40033c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x400340 */ str x19, [sp, #0x10];
    /* 0x400344 */ mov x29, sp;
    /* 0x400348 */ adrp x8, #0x54b000;
    /* 0x40034c */ mov x19, x0;
    /* 0x400350 */ ldr x8, [x8, #0x190];
    /* 0x400354 */ add x8, x8, #0x10;
    /* 0x400358 */ str x8, [x0];
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    /* 0x400360 */ mov x0, x19;
    /* 0x400364 */ ldr x19, [sp, #0x10];
}
