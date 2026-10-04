// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bfe5c
// Recovered Name: _ZN11LayerFlowNS24LFCreativeStickerInfoJNI23nGetStickerLocateStatusEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bfe5c | Size: 52 bytes | SHA256: 0fdfa2577d6a22910f04ab611304dba03a0189018449cb67dad17ea5d37c527b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetStickerLocateStatus(J)J (table at 0x5401f8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS24LFCreativeStickerInfoJNI23nGetStickerLocateStatusEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x3bfe5c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3bfe60 */ str x19, [sp, #0x10];
    /* 0x3bfe64 */ mov x29, sp;
    /* 0x3bfe68 */ mov w0, #0x24;
    /* 0x3bfe6c */ mov x19, x2;
    _Znwm();
    /* 0x3bfe74 */ ldp q0, q1, [x19, #0x30];
    /* 0x3bfe78 */ ldr w8, [x19, #0x50];
    /* 0x3bfe7c */ stp q0, q1, [x0];
    /* 0x3bfe80 */ str w8, [x0, #0x20];
    /* 0x3bfe84 */ ldr x19, [sp, #0x10];
    return x0;
}
