// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96490
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setSecondEditBrushCache
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96490 | Size: 32 bytes | SHA256: eb2a8b4100087379244a8d93243316037c03961519543515fa66e0ece06abee5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVGraffitiPenControl23setSecondEditBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE
// Strings referenced:
//   "std::vector< mtlabar3::BrushCache * > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setSecondEditBrushCache(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x96490 */ cbz x4, #0x964a0;
    /* 0x96494 */ mov x0, x2;
    /* 0x96498 */ mov x1, x4;
    /* 0x9649c */ b #0xa4c60;
    /* 0x964a0 */ adrp x2, #0x6d000;
    /* 0x964a4 */ add x2, x2, #0xedd;
    /* 0x964a8 */ mov w1, #7;
    /* 0x964ac */ b #0x882c8;
}
