// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dc68
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dc68 | Size: 64 bytes | SHA256: 3259e9a67f9ae4429c1f156dcd6c7e5a95d8f5499b201646f0959e310a2b587e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface13getConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8dc68 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8dc6c */ str x19, [sp, #0x10];
    /* 0x8dc70 */ mov x29, sp;
    /* 0x8dc74 */ mov x19, x0;
    /* 0x8dc78 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface13getConfigPathEv();
    /* 0x8dc80 */ ldr x8, [x19];
    /* 0x8dc84 */ ldrb w9, [x0];
    /* 0x8dc88 */ ldr x10, [x0, #0x10];
    /* 0x8dc8c */ tst w9, #1;
    /* 0x8dc90 */ ldr x2, [x8, #0x538];
}
