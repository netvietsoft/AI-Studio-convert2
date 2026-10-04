// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x951d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ManualBodySlimControlInstance_1isSupportForMultiDataControl
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x951d8 | Size: 28 bytes | SHA256: 797108ea2f476b84512846ab7057af2eab527601bbd099e5ab7634ef8cde6400
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar329ManualBodySlimControlInstance28isSupportForMultiDataControlEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ManualBodySlimControlInstance_1isSupportForMultiDataControl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x951d8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x951dc */ mov x29, sp;
    /* 0x951e0 */ mov x0, x2;
    _ZN8mtlabar329ManualBodySlimControlInstance28isSupportForMultiDataControlEv();
    /* 0x951e8 */ and w0, w0, #1;
    /* 0x951ec */ ldp x29, x30, [sp], #0x10;
    return x0;
}
