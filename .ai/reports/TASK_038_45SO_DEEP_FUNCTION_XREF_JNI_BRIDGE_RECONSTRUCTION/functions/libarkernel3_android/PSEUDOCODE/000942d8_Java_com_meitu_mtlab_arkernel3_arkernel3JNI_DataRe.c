// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x942d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x942d8 | Size: 28 bytes | SHA256: 7e7a5a8c8ab483391be521fd37c4ffb7bd0f4924d1c6d5401513dc638edbfeb5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireSkinMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x942d8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x942dc */ mov x29, sp;
    /* 0x942e0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireSkinMaskEv();
    /* 0x942e8 */ and w0, w0, #1;
    /* 0x942ec */ ldp x29, x30, [sp], #0x10;
    return x0;
}
