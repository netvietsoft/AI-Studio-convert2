// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573570
// Recovered Name: sub_573570
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573570 | Size: 16 bytes | SHA256: 1de819587de0914a73e3f29e224c3f62b341ef462e1f32789f4992d3c6776ac2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHumanBodyCount(JI)V (table at 0x10cda30)

jlong sub_573570(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x573570 */ cbz x2, #0x57357c;
    /* 0x573574 */ sxtw x8, w3;
    /* 0x573578 */ str x8, [x2, #0x18];
    return x0;
}
