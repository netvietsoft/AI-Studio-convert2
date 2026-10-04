// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d864
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getJsonPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d864 | Size: 64 bytes | SHA256: 9310c862c288c69df3bad32bd120edbc0013f73702f438811fb42f7ebfc5db3f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration11getJsonPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getJsonPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8d864 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8d868 */ str x19, [sp, #0x10];
    /* 0x8d86c */ mov x29, sp;
    /* 0x8d870 */ mov x19, x0;
    /* 0x8d874 */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration11getJsonPathEv();
    /* 0x8d87c */ ldr x8, [x19];
    /* 0x8d880 */ ldrb w9, [x0];
    /* 0x8d884 */ ldr x10, [x0, #0x10];
    /* 0x8d888 */ tst w9, #1;
    /* 0x8d88c */ ldr x2, [x8, #0x538];
}
