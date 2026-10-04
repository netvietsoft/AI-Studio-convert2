// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94adc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MakeupControlInstance_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94adc | Size: 32 bytes | SHA256: c635ce6fa974859431b6638a1e32279885d44cd76a427331c604eab8f571aebd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321MakeupControlInstance9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MakeupControlInstance_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x94adc */ cbz x4, #0x94aec;
    /* 0x94ae0 */ mov x0, x2;
    /* 0x94ae4 */ mov x1, x4;
    /* 0x94ae8 */ b #0xa4060;
    /* 0x94aec */ adrp x2, #0x6d000;
    /* 0x94af0 */ add x2, x2, #0xdc9;
    /* 0x94af4 */ mov w1, #7;
    /* 0x94af8 */ b #0x882c8;
}
