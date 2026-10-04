// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c014
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c014 | Size: 32 bytes | SHA256: c38ed79e653a7355fbc2adae6cfa9a9e94ff7617e4b22014853a9508622b8a01
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextStrokeConfiguration9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8c014 */ cbz x4, #0x8c024;
    /* 0x8c018 */ mov x0, x2;
    /* 0x8c01c */ mov x1, x4;
    /* 0x8c020 */ b #0xa0de0;
    /* 0x8c024 */ adrp x2, #0x6d000;
    /* 0x8c028 */ add x2, x2, #0xdc9;
    /* 0x8c02c */ mov w1, #7;
    /* 0x8c030 */ b #0x882c8;
}
