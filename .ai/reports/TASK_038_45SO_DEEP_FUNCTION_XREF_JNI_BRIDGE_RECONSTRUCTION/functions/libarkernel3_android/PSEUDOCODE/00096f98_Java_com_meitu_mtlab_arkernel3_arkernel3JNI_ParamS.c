// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96f98
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1setCurrentValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96f98 | Size: 16 bytes | SHA256: 2562bba31b7f287db2cdd4a6f09b61324d8e019feb08faae3d06b4ba17cc4ed1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311ParamSwitch15setCurrentValueEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1setCurrentValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x96f98 */ tst w4, #0xff;
    /* 0x96f9c */ mov x0, x2;
    /* 0x96fa0 */ cset w1, ne;
    /* 0x96fa4 */ b #0xa5090;
}
