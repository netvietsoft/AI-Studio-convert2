// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x995f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1startSoundService
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x995f0 | Size: 24 bytes | SHA256: 1954af8f9af28dd57a06518cb5f16144d3d803e4068a9ec1d7572ba8d2d5993f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting17startSoundServiceEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1startSoundService(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x995f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x995f4 */ mov x29, sp;
    _ZN8mtlabar313GlobalSetting17startSoundServiceEv();
    /* 0x995fc */ and w0, w0, #1;
    /* 0x99600 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
