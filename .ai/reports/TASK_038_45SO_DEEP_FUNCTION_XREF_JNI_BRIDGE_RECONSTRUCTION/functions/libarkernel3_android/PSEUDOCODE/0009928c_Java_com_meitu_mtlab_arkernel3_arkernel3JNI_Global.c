// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9928c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1globalInit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9928c | Size: 24 bytes | SHA256: c344fd941a6f7ab6e5f3d05bafc9e6568f047daf002c1d14a3e461fbf153b264
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting10globalInitEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1globalInit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x9928c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x99290 */ mov x29, sp;
    _ZN8mtlabar313GlobalSetting10globalInitEv();
    /* 0x99298 */ and w0, w0, #1;
    /* 0x9929c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
