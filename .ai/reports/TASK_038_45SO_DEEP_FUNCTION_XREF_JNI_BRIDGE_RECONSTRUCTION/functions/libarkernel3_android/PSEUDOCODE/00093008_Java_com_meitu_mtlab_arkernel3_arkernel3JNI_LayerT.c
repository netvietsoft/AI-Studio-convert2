// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93008
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setTrans
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93008 | Size: 32 bytes | SHA256: de1a35550031c58439e7eeb416108d4a7a814a182a0cbc7bd362f11d5dfdfa80
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerTransformInteraction8setTransENS_6Float2E
// Strings referenced:
//   "Attempt to dereference null mtlabar3::Point2F"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1setTrans(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x93008 */ cbz x4, #0x93018;
    /* 0x9300c */ ldp s0, s1, [x4];
    /* 0x93010 */ mov x0, x2;
    /* 0x93014 */ b #0xa34c0;
    /* 0x93018 */ adrp x2, #0x6d000;
    /* 0x9301c */ add x2, x2, #0xd55;
    /* 0x93020 */ mov w1, #7;
    /* 0x93024 */ b #0x882c8;
}
