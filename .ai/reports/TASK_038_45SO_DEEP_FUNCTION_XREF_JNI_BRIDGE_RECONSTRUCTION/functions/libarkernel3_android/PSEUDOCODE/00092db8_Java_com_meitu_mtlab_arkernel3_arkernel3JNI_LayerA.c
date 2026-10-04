// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92db8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getJsonPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92db8 | Size: 68 bytes | SHA256: 4c051cf00bbab38ecd2a0b4b5de7c5245b37def3165cd7bafd9481e7683e064c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction11getJsonPathEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getJsonPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x92db8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x92dbc */ str x19, [sp, #0x10];
    /* 0x92dc0 */ mov x29, sp;
    /* 0x92dc4 */ mov x19, x0;
    /* 0x92dc8 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction11getJsonPathEv();
    /* 0x92dd0 */ cbz x0, #0x92df0;
    /* 0x92dd4 */ ldr x8, [x19];
    /* 0x92dd8 */ mov x1, x0;
    /* 0x92ddc */ ldr x2, [x8, #0x538];
    /* 0x92de0 */ mov x0, x19;
    return x0;
}
