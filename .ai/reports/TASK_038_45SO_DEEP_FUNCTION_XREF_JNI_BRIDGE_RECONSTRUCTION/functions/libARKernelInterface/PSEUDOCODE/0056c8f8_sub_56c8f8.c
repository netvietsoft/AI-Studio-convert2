// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56c8f8
// Recovered Name: sub_56c8f8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56c8f8 | Size: 12 bytes | SHA256: af7df404a2f00c61aa083cbdf4f7bbafdcbbfc2ef17e3b5594e4ff332b718fff
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetExpressionInfoByteBuffer(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V (table at 0x10cd280)

jlong sub_56c8f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56c8f8 */ cbz x2, #0x56ca28;
    /* 0x56c8fc */ cmp w3, #0x13;
    /* 0x56c900 */ b.hi #0x56ca28;
}
