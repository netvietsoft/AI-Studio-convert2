// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11d704
// Recovered Name: sub_11d704
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11d704 | Size: 36 bytes | SHA256: eb238863d667e1aa244ec3ba4d80438d2320e7de9f2ceeb2bfbd9d06c2559ad5
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: setAndroidContext(Landroid/content/Context;)V (table at 0x13a380)
// Calls external APIs: _ZN3PVG9PVGGlobal11getInstanceEv, _ZN3PVG9PVGGlobal17setAndroidContextEP8_jobject

jlong sub_11d704(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x11d704 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x11d708 */ str x19, [sp, #0x10];
    /* 0x11d70c */ mov x29, sp;
    /* 0x11d710 */ mov x19, x2;
    _ZN3PVG9PVGGlobal11getInstanceEv();
    /* 0x11d718 */ mov x1, x19;
    /* 0x11d71c */ ldr x19, [sp, #0x10];
    /* 0x11d720 */ ldp x29, x30, [sp], #0x20;
    /* 0x11d724 */ b #0x1341e0;
}
