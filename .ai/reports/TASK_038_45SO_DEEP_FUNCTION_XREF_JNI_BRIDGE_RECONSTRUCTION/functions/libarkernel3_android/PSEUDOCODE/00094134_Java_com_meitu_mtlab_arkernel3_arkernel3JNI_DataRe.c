// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94134
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionRigging
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94134 | Size: 28 bytes | SHA256: dc46e9e05429d407cf630cfce06c7acb961a85f7818abd1d4b1cfcf1e674ad44
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire34requireFaceDL3DDataAdditionRiggingEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDL3DDataAdditionRigging(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94134 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94138 */ mov x29, sp;
    /* 0x9413c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire34requireFaceDL3DDataAdditionRiggingEv();
    /* 0x94144 */ and w0, w0, #1;
    /* 0x94148 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
