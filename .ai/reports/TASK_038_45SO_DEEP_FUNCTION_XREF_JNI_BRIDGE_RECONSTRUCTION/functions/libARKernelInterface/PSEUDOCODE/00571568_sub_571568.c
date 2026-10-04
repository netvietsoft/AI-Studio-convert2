// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x571568
// Recovered Name: sub_571568
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x571568 | Size: 16 bytes | SHA256: d7e9b86339cbb29ad8cc762f24b2fbd7f487b6aedfc300c9df16737701323885
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeRelease(J)V (table at 0x10cd670)

jlong sub_571568(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x571568 */ cbz x2, #0x571574;
    /* 0x57156c */ mov x0, x2;
    /* 0x571570 */ b #0x891f90;
    return x0;
}
