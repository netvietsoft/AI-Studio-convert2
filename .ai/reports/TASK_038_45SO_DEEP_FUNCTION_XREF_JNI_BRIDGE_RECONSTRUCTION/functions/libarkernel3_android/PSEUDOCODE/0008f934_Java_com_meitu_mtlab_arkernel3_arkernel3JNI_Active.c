// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f934
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f934 | Size: 32 bytes | SHA256: a081459ba22d5925231f693b06f16f595d8170398e1b95a229566861f37a0d21
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321ActiveWordBgInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f934 */ cbz x4, #0x8f944;
    /* 0x8f938 */ mov x0, x2;
    /* 0x8f93c */ mov x1, x4;
    /* 0x8f940 */ b #0xa22e0;
    /* 0x8f944 */ adrp x2, #0x6d000;
    /* 0x8f948 */ add x2, x2, #0xdc9;
    /* 0x8f94c */ mov w1, #7;
    /* 0x8f950 */ b #0x882c8;
}
