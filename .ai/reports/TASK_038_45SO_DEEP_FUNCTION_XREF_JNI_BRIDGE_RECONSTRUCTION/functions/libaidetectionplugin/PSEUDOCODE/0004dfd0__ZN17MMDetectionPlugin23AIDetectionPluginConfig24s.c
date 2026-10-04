// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x4dfd0
// Recovered Name: _ZN17MMDetectionPlugin23AIDetectionPluginConfig24setDenseHairModelQualityEi
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x4dfd0 | Size: 16 bytes | SHA256: e11e60c91bc2a67ea591042e277369830ab959a788899dce38ac5db13336b701
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN17MMDetectionPlugin23AIDetectionPluginConfig24setDenseHairModelQualityEi(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x4dfd0 */ adrp x8, #0x82000;
    /* 0x4dfd4 */ ldr x8, [x8, #0xf48];
    /* 0x4dfd8 */ str w0, [x8];
    return x0;
}
