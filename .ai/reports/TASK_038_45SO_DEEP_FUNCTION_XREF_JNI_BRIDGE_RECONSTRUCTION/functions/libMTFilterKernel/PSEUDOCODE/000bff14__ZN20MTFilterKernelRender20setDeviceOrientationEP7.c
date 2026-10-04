// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbff14
// Recovered Name: _ZN20MTFilterKernelRender20setDeviceOrientationEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbff14 | Size: 104 bytes | SHA256: e663576fa951892df12da9deae9e7841abc5e9518811fc87bec0ffb6346e062c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetDeviceOrientation(JI)V (table at 0x1ca5c0)

jlong _ZN20MTFilterKernelRender20setDeviceOrientationEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0xbff14 */ cbz x2, #0xbff38;
    /* 0xbff18 */ cmp w3, #0xb3;
    /* 0xbff1c */ b.gt #0xbff3c;
    /* 0xbff20 */ cbz w3, #0xbff64;
    /* 0xbff24 */ cmp w3, #0x5a;
    /* 0xbff28 */ b.ne #0xbff58;
    /* 0xbff2c */ mov w1, #4;
    /* 0xbff30 */ mov x0, x2;
    /* 0xbff34 */ b #0x1aa0bc;
    return x0;
    /* 0xbff3c */ cmp w3, #0xb4;
}
