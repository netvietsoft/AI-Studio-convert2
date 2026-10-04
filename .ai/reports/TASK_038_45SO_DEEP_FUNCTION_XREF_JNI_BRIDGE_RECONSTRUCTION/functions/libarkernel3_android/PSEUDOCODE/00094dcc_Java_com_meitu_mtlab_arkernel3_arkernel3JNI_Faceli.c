// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94dcc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControl_1getFaceliftControlKeyName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94dcc | Size: 72 bytes | SHA256: c7301c5266db61c7590f51b1b3a6128a5db44ff30328099fc09ebf9a849f1a2a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar315FaceliftControl25getFaceliftControlKeyNameEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControl_1getFaceliftControlKeyName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x94dcc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x94dd0 */ str x19, [sp, #0x10];
    /* 0x94dd4 */ mov x29, sp;
    /* 0x94dd8 */ mov x1, x4;
    /* 0x94ddc */ mov x19, x0;
    /* 0x94de0 */ mov x0, x2;
    _ZNK8mtlabar315FaceliftControl25getFaceliftControlKeyNameEm();
    /* 0x94de8 */ cbz x0, #0x94e08;
    /* 0x94dec */ ldr x8, [x19];
    /* 0x94df0 */ mov x1, x0;
    /* 0x94df4 */ ldr x2, [x8, #0x538];
    return x0;
}
