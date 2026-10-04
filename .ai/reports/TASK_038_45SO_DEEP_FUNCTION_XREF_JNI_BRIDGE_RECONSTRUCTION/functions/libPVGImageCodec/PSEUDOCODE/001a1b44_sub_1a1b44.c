// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x1a1b44
// Recovered Name: sub_1a1b44
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1a1b44 | Size: 80 bytes | SHA256: f8dcbfd988ebef32a9707f150ee801c8c8ff45ab83979f9c5dd644a7ac4248c5
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, __cxa_atexit

void sub_1a1b44(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x1a1b44 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1a1b48 */ str x19, [sp, #0x10];
    /* 0x1a1b4c */ mov x29, sp;
    /* 0x1a1b50 */ adrp x19, #0x4ec000;
    /* 0x1a1b54 */ add x19, x19, #0x890;
    /* 0x1a1b58 */ mov x0, x19;
    _ZNSt6__ndk15mutex4lockEv();
    /* 0x1a1b60 */ mov x0, x19;
    _ZNSt6__ndk15mutex6unlockEv();
    /* 0x1a1b68 */ mov w0, #1;
    /* 0x1a1b6c */ ldr x19, [sp, #0x10];
    return x0;
}
