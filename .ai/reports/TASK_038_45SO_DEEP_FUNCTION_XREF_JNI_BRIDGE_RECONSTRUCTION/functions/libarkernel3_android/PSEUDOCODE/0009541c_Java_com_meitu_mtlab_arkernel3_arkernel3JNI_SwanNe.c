// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9541c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SwanNeckControl_1getSwanNeckEffectState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9541c | Size: 32 bytes | SHA256: e068e302527ce058a8be413ac026b01f040c194cba08bd18f264f9ee55029909
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315SwanNeckControl22getSwanNeckEffectStateEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SwanNeckControl_1getSwanNeckEffectState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x9541c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95420 */ mov x29, sp;
    /* 0x95424 */ mov x1, x4;
    /* 0x95428 */ mov x0, x2;
    _ZN8mtlabar315SwanNeckControl22getSwanNeckEffectStateEPNS_18FrameDataInterfaceE();
    /* 0x95430 */ and w0, w0, #1;
    /* 0x95434 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
