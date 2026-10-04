// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d918
// Recovered Name: sub_57d918
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d918 | Size: 12 bytes | SHA256: dd89d9b7b3c6cdc3ffac18cc126f21a8bdfcd80dca2f209c585b4939ee829657
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerRotateAdsorbIValue(JI)V (table at 0x10cf140)

jlong sub_57d918(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d918 */ cbz x2, #0x57d920;
    /* 0x57d91c */ str w3, [x2, #0xf8];
    return x0;
}
