// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x953dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ShoulderMLSControl_1getShoulderMLSEffectState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x953dc | Size: 32 bytes | SHA256: c42a4513cff182d5a37d9a54edcb5daf6792276436141d220a60c451d9ea4655
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar318ShoulderMLSControl25getShoulderMLSEffectStateEPNS_18FrameDataInterfaceE

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ShoulderMLSControl_1getShoulderMLSEffectState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x953dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x953e0 */ mov x29, sp;
    /* 0x953e4 */ mov x1, x4;
    /* 0x953e8 */ mov x0, x2;
    _ZN8mtlabar318ShoulderMLSControl25getShoulderMLSEffectStateEPNS_18FrameDataInterfaceE();
    /* 0x953f0 */ and w0, w0, #1;
    /* 0x953f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
