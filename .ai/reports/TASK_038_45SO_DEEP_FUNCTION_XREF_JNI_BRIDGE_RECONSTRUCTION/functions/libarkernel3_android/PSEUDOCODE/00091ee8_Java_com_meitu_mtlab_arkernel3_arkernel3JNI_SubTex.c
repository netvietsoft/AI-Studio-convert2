// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91ee8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getContainMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91ee8 | Size: 28 bytes | SHA256: dff43b82175c169789a502ba28c775f783f3fd5ec88367106cf35c3c5336b265
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14getContainMaskEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getContainMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91ee8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91eec */ mov x29, sp;
    /* 0x91ef0 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction14getContainMaskEv();
    /* 0x91ef8 */ and w0, w0, #1;
    /* 0x91efc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
