// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92fe8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationManager_1setAnimationPriority
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92fe8 | Size: 32 bytes | SHA256: 6aab292a0b47fc0a77ab8b504743d7b332891a3b3cbe432a23ae3b48fd7ca2d5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321LayerAnimationManager20setAnimationPriorityERKNSt6__ndk16vectorINS_17AnimationTimeTypeENS1_9allocatorIS3_EEEE
// Strings referenced:
//   "std::vector< mtlabar3::AnimationTimeType > const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationManager_1setAnimationPriority(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x92fe8 */ cbz x4, #0x92ff8;
    /* 0x92fec */ mov x0, x2;
    /* 0x92ff0 */ mov x1, x4;
    /* 0x92ff4 */ b #0xa34b0;
    /* 0x92ff8 */ adrp x2, #0x6d000;
    /* 0x92ffc */ add x2, x2, #0xa1b;
    /* 0x93000 */ mov w1, #7;
    /* 0x93004 */ b #0x882c8;
}
