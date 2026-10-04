// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x963a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setBrushCache
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x963a8 | Size: 32 bytes | SHA256: 000f34ad54ef7b8d5e904ff1c69f48a46e0919e757546d62136a43e04a379087
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVGraffitiPenControl13setBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE
// Strings referenced:
//   "std::vector< mtlabar3::BrushCache * > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setBrushCache(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x963a8 */ cbz x4, #0x963b8;
    /* 0x963ac */ mov x0, x2;
    /* 0x963b0 */ mov x1, x4;
    /* 0x963b4 */ b #0xa4c40;
    /* 0x963b8 */ adrp x2, #0x6d000;
    /* 0x963bc */ add x2, x2, #0xedd;
    /* 0x963c0 */ mov w1, #7;
    /* 0x963c4 */ b #0x882c8;
}
