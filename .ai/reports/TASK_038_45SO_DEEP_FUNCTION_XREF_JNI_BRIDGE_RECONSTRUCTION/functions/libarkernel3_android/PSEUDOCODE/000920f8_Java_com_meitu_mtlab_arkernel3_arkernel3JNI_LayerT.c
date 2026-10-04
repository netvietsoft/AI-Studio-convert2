// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x920f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setWatermarkConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x920f8 | Size: 32 bytes | SHA256: c60a476bb3227307b30e6d9da51bbe9a8c23cffc2adf2a530d3cc2ef58531de4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction18setWatermarkConfigERKNS_15WatermarkConfigE
// Strings referenced:
//   "mtlabar3::WatermarkConfig const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1setWatermarkConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x920f8 */ cbz x4, #0x92108;
    /* 0x920fc */ mov x0, x2;
    /* 0x92100 */ mov x1, x4;
    /* 0x92104 */ b #0xa2de0;
    /* 0x92108 */ adrp x2, #0x6d000;
    /* 0x9210c */ add x2, x2, #0x866;
    /* 0x92110 */ mov w1, #7;
    /* 0x92114 */ b #0x882c8;
}
