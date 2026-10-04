// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfee4
// Recovered Name: _ZN20MTFilterKernelRender18renderToOutTextureEP7_JNIEnvP8_jobjectliiiiii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfee4 | Size: 48 bytes | SHA256: 98ecedd7bf3b32001805885e1d15a5b914b08b74af70de2b7fc57941413b0266
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nRenderToOutTexture(JIIIIII)I (table at 0x1ca5a8)

jlong _ZN20MTFilterKernelRender18renderToOutTextureEP7_JNIEnvP8_jobjectliiiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0xbfee4 */ cbz x2, #0xbff0c;
    /* 0xbfee8 */ ldr w8, [sp];
    /* 0xbfeec */ fmov s0, #1.00000000;
    /* 0xbfef0 */ mov x0, x2;
    /* 0xbfef4 */ mov w1, w4;
    /* 0xbfef8 */ mov w2, w6;
    /* 0xbfefc */ mov w4, w5;
    /* 0xbff00 */ mov w5, w7;
    /* 0xbff04 */ mov w6, w8;
    /* 0xbff08 */ b #0x1aa804;
    /* 0xbff0c */ mov w0, w4;
    return x0;
}
