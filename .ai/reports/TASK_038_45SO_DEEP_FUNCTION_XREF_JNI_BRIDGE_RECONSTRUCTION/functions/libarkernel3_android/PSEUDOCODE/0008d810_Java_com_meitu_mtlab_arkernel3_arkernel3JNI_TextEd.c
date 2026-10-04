// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d810
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setPinyinEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d810 | Size: 16 bytes | SHA256: 0d7f570623ed26ad30b4dbe97c30e16375e886d300538c3fe23eef65cfdb3b62
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325TextEditableConfiguration17setPinyinEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1setPinyinEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8d810 */ tst w4, #0xff;
    /* 0x8d814 */ mov x0, x2;
    /* 0x8d818 */ cset w1, ne;
    /* 0x8d81c */ b #0xa0fc0;
}
