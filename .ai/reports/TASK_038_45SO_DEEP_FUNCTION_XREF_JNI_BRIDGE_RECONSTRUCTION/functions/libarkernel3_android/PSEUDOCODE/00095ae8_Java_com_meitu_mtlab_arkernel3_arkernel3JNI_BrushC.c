// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95ae8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setNextPoint
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95ae8 | Size: 32 bytes | SHA256: 0770e557e5343204928e5f69d83a69303ebf827014976b2ac67d7c7833c8a57c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache12setNextPointERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Float3 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setNextPoint(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95ae8 */ cbz x4, #0x95af8;
    /* 0x95aec */ mov x0, x2;
    /* 0x95af0 */ mov x1, x4;
    /* 0x95af4 */ b #0xa49a0;
    /* 0x95af8 */ adrp x2, #0x6d000;
    /* 0x95afc */ add x2, x2, #0xcd3;
    /* 0x95b00 */ mov w1, #7;
    /* 0x95b04 */ b #0x882c8;
}
