// Library: libaicodec.so
// Function ID: libaicodec::0x117acc
// Recovered Name: sub_117acc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x117acc | Size: 12 bytes | SHA256: ec27e204f1d7763f5662306e20503a5cefd0d66df6c1c30c8c2f52ab342166cb
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_start(J)I (table at 0x1ff1e8)
// Calls external APIs: _ZN7MMCodec13MediaRecorder5startEv

jlong sub_117acc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x117acc */ cbz x2, #0x117ad8;
    /* 0x117ad0 */ mov x0, x2;
    /* 0x117ad4 */ b #0x1f54f0;
}
