// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x120dec
// Recovered Name: sub_120dec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x120dec | Size: 20 bytes | SHA256: 99fd5f7580b14b4ab150a08cb49b48d65dd6cbe211f81dd062f9cc1f9e380abd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getFramesNb(J)I (table at 0x13a760)

jlong sub_120dec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x120dec */ cbz x2, #0x120e00;
    /* 0x120df0 */ ldr x8, [x2];
    /* 0x120df4 */ mov x0, x2;
    /* 0x120df8 */ ldr x1, [x8, #0x30];
    /* 0x120dfc */ br x1;
}
