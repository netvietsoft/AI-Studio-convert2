// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ee70
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ee70 | Size: 32 bytes | SHA256: 3445e5568d944483928cae5b80e97daed8f7cf9e41b559351114bb41689f6864
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceStyleInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ee70 */ cbz x4, #0x8ee80;
    /* 0x8ee74 */ mov x0, x2;
    /* 0x8ee78 */ mov x1, x4;
    /* 0x8ee7c */ b #0xa1c70;
    /* 0x8ee80 */ adrp x2, #0x6d000;
    /* 0x8ee84 */ add x2, x2, #0xdc9;
    /* 0x8ee88 */ mov w1, #7;
    /* 0x8ee8c */ b #0x882c8;
}
