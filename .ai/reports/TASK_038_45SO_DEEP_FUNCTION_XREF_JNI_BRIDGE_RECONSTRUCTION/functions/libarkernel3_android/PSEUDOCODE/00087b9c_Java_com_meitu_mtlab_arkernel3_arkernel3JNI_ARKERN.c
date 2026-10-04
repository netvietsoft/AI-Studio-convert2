// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x87b9c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ARKERNEL3_1VERSION_1get
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x87b9c | Size: 20 bytes | SHA256: 641e6e1e6edf6ef93a747e799a14eec61804c3b89522166a68eb5f2016beed0e
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ARKERNEL3_1VERSION_1get(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x87b9c */ ldr x8, [x0];
    /* 0x87ba0 */ nop ;
    /* 0x87ba4 */ adr x1, #0x6e27c;
    /* 0x87ba8 */ ldr x2, [x8, #0x538];
    /* 0x87bac */ br x2;
}
