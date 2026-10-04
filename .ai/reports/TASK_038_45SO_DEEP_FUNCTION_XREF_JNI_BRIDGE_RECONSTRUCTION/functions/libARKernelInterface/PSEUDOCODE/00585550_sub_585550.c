// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585550
// Recovered Name: sub_585550
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585550 | Size: 32 bytes | SHA256: 353a81197ec2235546f7d69d0464d2a29ae9888e60eadb409878067ddb94fe65
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAreaLimit(JJZ)V (table at 0x10cfab8)

jlong sub_585550(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x585550 */ cbz x2, #0x58556c;
    /* 0x585554 */ tst w4, #0xff;
    /* 0x585558 */ mov x0, x2;
    /* 0x58555c */ mov x1, x3;
    /* 0x585560 */ cset w8, ne;
    /* 0x585564 */ mov w2, w8;
    /* 0x585568 */ b #0x58439c;
    return x0;
}
