// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56c6f4
// Recovered Name: sub_56c6f4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56c6f4 | Size: 12 bytes | SHA256: 2cca2c9b4f0a4f47effb84e3d56a8de6b7cb76f61296d234e503569df0f9a163
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMeshInfoByteBuffer(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V (table at 0x10cd268)

jlong sub_56c6f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56c6f4 */ cbz x2, #0x56c8f4;
    /* 0x56c6f8 */ cmp w3, #0x13;
    /* 0x56c6fc */ b.hi #0x56c8f4;
}
