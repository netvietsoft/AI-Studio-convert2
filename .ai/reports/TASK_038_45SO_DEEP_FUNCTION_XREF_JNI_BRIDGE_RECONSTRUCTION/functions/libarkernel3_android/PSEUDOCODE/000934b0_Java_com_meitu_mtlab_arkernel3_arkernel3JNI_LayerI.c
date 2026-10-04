// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x934b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setEnableSelected
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x934b0 | Size: 16 bytes | SHA256: 170b6e32267753e4b4e1cf6883f9f94b5e711d83068d07b485a937bd8e8cd808
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction17setEnableSelectedEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setEnableSelected(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x934b0 */ tst w4, #0xff;
    /* 0x934b4 */ mov x0, x2;
    /* 0x934b8 */ cset w1, ne;
    /* 0x934bc */ b #0xa3820;
}
