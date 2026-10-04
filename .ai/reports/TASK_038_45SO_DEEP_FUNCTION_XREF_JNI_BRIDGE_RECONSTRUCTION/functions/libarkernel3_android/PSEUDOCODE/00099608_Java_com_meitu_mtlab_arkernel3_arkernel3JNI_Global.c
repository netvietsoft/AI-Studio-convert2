// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99608
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1pauseSoundService
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99608 | Size: 12 bytes | SHA256: 6529b379c6ad72a072703919173fe932a22a561df5a0912a0265a16df06230f4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting17pauseSoundServiceEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1pauseSoundService(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x99608 */ tst w2, #0xff;
    /* 0x9960c */ cset w0, ne;
    /* 0x99610 */ b #0xa57c0;
}
