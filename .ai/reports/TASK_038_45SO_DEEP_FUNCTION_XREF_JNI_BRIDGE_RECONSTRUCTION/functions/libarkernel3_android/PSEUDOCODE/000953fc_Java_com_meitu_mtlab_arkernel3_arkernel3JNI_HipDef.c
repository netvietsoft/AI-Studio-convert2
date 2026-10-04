// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x953fc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_HipDeformControl_1getHipDeformEffectState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x953fc | Size: 32 bytes | SHA256: 4343fe162d3c510b214ba9c240e33ce63d77f3231b5bce52ed46f1b66ea67abd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316HipDeformControl23getHipDeformEffectStateEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_HipDeformControl_1getHipDeformEffectState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x953fc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95400 */ mov x29, sp;
    /* 0x95404 */ mov x1, x4;
    /* 0x95408 */ mov x0, x2;
    _ZN8mtlabar316HipDeformControl23getHipDeformEffectStateEPNS_18FrameDataInterfaceE();
    /* 0x95410 */ and w0, w0, #1;
    /* 0x95414 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
