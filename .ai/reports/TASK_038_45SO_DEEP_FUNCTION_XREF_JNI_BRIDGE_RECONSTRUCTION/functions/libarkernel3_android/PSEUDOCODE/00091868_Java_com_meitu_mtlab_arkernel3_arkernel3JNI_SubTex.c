// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91868
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsStaticShow
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91868 | Size: 28 bytes | SHA256: f71ea687223149e7e50adc6055c18082dc94cae1d83b672bfeb12f83fcde7993
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction15getIsStaticShowEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getIsStaticShow(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91868 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9186c */ mov x29, sp;
    /* 0x91870 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction15getIsStaticShowEv();
    /* 0x91878 */ and w0, w0, #1;
    /* 0x9187c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
