// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92118
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableEdit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92118 | Size: 16 bytes | SHA256: 144b6c41efc3170baef790e2388e54cb5ee108ecfa145488b146dd5286d8683c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction13setEnableEditEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setEnableEdit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x92118 */ tst w4, #0xff;
    /* 0x9211c */ mov x0, x2;
    /* 0x92120 */ cset w1, ne;
    /* 0x92124 */ b #0xa2df0;
}
