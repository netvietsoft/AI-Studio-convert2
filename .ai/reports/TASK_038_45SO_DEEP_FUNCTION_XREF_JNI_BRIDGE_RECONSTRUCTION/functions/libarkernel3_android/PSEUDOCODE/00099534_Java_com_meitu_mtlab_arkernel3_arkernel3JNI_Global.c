// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99534
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getAIModelPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99534 | Size: 68 bytes | SHA256: a82ae756823add4f8c4a2be495e8c05251e11fd040586c610fa87053b46f6af2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting14getAIModelPathENS_11AIModelTypeE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getAIModelPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x99534 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x99538 */ str x19, [sp, #0x10];
    /* 0x9953c */ mov x29, sp;
    /* 0x99540 */ mov x19, x0;
    /* 0x99544 */ mov w0, w2;
    _ZN8mtlabar313GlobalSetting14getAIModelPathENS_11AIModelTypeE();
    /* 0x9954c */ cbz x0, #0x9956c;
    /* 0x99550 */ ldr x8, [x19];
    /* 0x99554 */ mov x1, x0;
    /* 0x99558 */ ldr x2, [x8, #0x538];
    /* 0x9955c */ mov x0, x19;
    return x0;
}
