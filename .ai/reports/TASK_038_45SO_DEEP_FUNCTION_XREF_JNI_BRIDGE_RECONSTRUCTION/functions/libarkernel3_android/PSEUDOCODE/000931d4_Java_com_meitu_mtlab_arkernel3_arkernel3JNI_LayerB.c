// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x931d4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getBorderVertexPosition2
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x931d4 | Size: 52 bytes | SHA256: 59f00efed36f91df210ac4de8d9ee150bb1445a2a521b17ce01441142c60bfb7
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction24getBorderVertexPosition2ENS_15LayerVertexEnumE, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getBorderVertexPosition2(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x931d4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x931d8 */ str x19, [sp, #0x10];
    /* 0x931dc */ mov x29, sp;
    /* 0x931e0 */ mov w1, w4;
    /* 0x931e4 */ mov x0, x2;
    _ZN8mtlabar322LayerBorderInteraction24getBorderVertexPosition2ENS_15LayerVertexEnumE();
    /* 0x931ec */ mov x19, x0;
    /* 0x931f0 */ mov w0, #8;
    _Znwm();
    /* 0x931f8 */ str x19, [x0];
    /* 0x931fc */ ldr x19, [sp, #0x10];
    return x0;
}
