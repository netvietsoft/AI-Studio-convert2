// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c9610
// Recovered Name: _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c9610 | Size: 176 bytes | SHA256: b509250f3d00ffd32fe0beddb31348f7d91ec3d75c1bbde3230ec06356be4146
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533440)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called,addr => %p"

jobject _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x2c9610 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c9614 */ str x21, [sp, #0x10];
    /* 0x2c9618 */ stp x20, x19, [sp, #0x20];
    /* 0x2c961c */ mov x29, sp;
    /* 0x2c9620 */ mov x19, x2;
    /* 0x2c9624 */ nop ;
    /* 0x2c9628 */ adr x1, #0x1e1361;
    /* 0x2c962c */ adrp x2, #0x1d9000;
    /* 0x2c9630 */ add x2, x2, #0xa24;
    /* 0x2c9634 */ mov w0, #6;
    /* 0x2c9638 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
