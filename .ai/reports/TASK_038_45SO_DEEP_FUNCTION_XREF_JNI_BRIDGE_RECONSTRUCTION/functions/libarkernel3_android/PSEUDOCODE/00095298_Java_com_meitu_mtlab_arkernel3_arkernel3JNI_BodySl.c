// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95298
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1getBodySlimOperateSwitch
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95298 | Size: 24 bytes | SHA256: d7466778a0bd686285305756e5c4739401de35a6f89640d4f61974c45aae08af
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl24getBodySlimOperateSwitchEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1getBodySlimOperateSwitch(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x95298 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9529c */ mov x29, sp;
    /* 0x952a0 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl24getBodySlimOperateSwitchEv();
    /* 0x952a8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
