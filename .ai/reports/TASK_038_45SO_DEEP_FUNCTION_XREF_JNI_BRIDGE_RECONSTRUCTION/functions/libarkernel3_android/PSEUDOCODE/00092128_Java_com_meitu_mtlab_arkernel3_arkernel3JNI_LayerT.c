// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92128
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableEdit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92128 | Size: 28 bytes | SHA256: c4e42fb1355a00deabd7f54e196b74fb464eb00dba9aa84335fe270de3a53c90
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction13getEnableEditEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableEdit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92128 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9212c */ mov x29, sp;
    /* 0x92130 */ mov x0, x2;
    _ZN8mtlabar320LayerTextInteraction13getEnableEditEv();
    /* 0x92138 */ and w0, w0, #1;
    /* 0x9213c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
