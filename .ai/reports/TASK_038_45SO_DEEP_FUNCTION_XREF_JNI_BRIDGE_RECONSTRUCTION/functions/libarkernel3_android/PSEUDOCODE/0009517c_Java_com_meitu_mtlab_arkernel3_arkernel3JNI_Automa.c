// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9517c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_AutomaticBodySlimControlInstance_1isSupportForMultiDataControl
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9517c | Size: 28 bytes | SHA256: 59c06a4dfa3983413d683441729435c8a61a2b74f5f9dc2762a8d61ee5f73515
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar332AutomaticBodySlimControlInstance28isSupportForMultiDataControlEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_AutomaticBodySlimControlInstance_1isSupportForMultiDataControl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9517c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95180 */ mov x29, sp;
    /* 0x95184 */ mov x0, x2;
    _ZN8mtlabar332AutomaticBodySlimControlInstance28isSupportForMultiDataControlEv();
    /* 0x9518c */ and w0, w0, #1;
    /* 0x95190 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
