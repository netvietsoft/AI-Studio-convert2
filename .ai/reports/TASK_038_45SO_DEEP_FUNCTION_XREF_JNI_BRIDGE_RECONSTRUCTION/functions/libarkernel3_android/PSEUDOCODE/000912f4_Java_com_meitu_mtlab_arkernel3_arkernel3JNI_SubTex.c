// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x912f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getInputFlag
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x912f4 | Size: 68 bytes | SHA256: 0530fa0ea21567077736545a785cf290a50df3a4dbb89b043e4e6d454be9f728
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12getInputFlagEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getInputFlag(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x912f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x912f8 */ str x19, [sp, #0x10];
    /* 0x912fc */ mov x29, sp;
    /* 0x91300 */ mov x19, x0;
    /* 0x91304 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction12getInputFlagEv();
    /* 0x9130c */ cbz x0, #0x9132c;
    /* 0x91310 */ ldr x8, [x19];
    /* 0x91314 */ mov x1, x0;
    /* 0x91318 */ ldr x2, [x8, #0x538];
    /* 0x9131c */ mov x0, x19;
    return x0;
}
