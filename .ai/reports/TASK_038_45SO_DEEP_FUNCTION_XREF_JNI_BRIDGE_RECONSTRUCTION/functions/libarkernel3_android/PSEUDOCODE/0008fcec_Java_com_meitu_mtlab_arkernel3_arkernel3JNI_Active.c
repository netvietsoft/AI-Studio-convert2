// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fcec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fcec | Size: 64 bytes | SHA256: 4e25b5e60c3142bc84a66e2b669f5b8a47a25ac84461c783d48204acf4a519fd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324ActiveWordStyleInterface13getConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8fcec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8fcf0 */ str x19, [sp, #0x10];
    /* 0x8fcf4 */ mov x29, sp;
    /* 0x8fcf8 */ mov x19, x0;
    /* 0x8fcfc */ mov x0, x2;
    _ZNK8mtlabar324ActiveWordStyleInterface13getConfigPathEv();
    /* 0x8fd04 */ ldr x8, [x19];
    /* 0x8fd08 */ ldrb w9, [x0];
    /* 0x8fd0c */ ldr x10, [x0, #0x10];
    /* 0x8fd10 */ tst w9, #1;
    /* 0x8fd14 */ ldr x2, [x8, #0x538];
}
