// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11f504
// Recovered Name: sub_11f504
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11f504 | Size: 12 bytes | SHA256: bef5f3c44e1614e16e2f6446d97051f4ad759e56feceea0bb6ca86d205c7f1a5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_process(J)I (table at 0x13a5e0)
// Calls external APIs: _ZN3PVG13MediaCombiner7processEv

jlong sub_11f504(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x11f504 */ cbz x2, #0x11f510;
    /* 0x11f508 */ mov x0, x2;
    /* 0x11f50c */ b #0x132a20;
}
