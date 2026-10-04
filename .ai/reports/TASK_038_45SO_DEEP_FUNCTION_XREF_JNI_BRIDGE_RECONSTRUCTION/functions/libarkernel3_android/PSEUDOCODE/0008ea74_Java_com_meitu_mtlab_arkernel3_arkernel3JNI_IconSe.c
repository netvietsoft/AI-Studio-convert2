// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ea74
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1getImagePath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ea74 | Size: 64 bytes | SHA256: ba44b8ae306f49c726ebc2d391584f876e67fe2efdcae1e30a484f691b8fa7cd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326IconSequenceStyleInterface12getImagePathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1getImagePath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8ea74 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8ea78 */ str x19, [sp, #0x10];
    /* 0x8ea7c */ mov x29, sp;
    /* 0x8ea80 */ mov x19, x0;
    /* 0x8ea84 */ mov x0, x2;
    _ZNK8mtlabar326IconSequenceStyleInterface12getImagePathEv();
    /* 0x8ea8c */ ldr x8, [x19];
    /* 0x8ea90 */ ldrb w9, [x0];
    /* 0x8ea94 */ ldr x10, [x0, #0x10];
    /* 0x8ea98 */ tst w9, #1;
    /* 0x8ea9c */ ldr x2, [x8, #0x538];
}
