// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f7e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setScale
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f7e0 | Size: 32 bytes | SHA256: 089153f4976ea7423946c807a1cc38aa740898cdd1ee8a47fadc708418b328e5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324CustomTransformInterface8setScaleERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Point3F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setScale(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f7e0 */ cbz x4, #0x8f7f0;
    /* 0x8f7e4 */ mov x0, x2;
    /* 0x8f7e8 */ mov x1, x4;
    /* 0x8f7ec */ b #0xa21e0;
    /* 0x8f7f0 */ adrp x2, #0x6e000;
    /* 0x8f7f4 */ add x2, x2, #0x1a9;
    /* 0x8f7f8 */ mov w1, #7;
    /* 0x8f7fc */ b #0x882c8;
}
