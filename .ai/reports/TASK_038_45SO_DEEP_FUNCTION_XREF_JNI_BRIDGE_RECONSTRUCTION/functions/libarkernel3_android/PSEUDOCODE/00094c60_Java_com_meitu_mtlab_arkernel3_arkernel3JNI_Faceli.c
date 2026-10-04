// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94c60
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftSlider_1getControlKeyName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94c60 | Size: 68 bytes | SHA256: f0c42d07b075ad4aea55ad1f4703e6a799ab7bcdcd926fc4b2e9cc895ee5288c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar314FaceliftSlider17getControlKeyNameEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftSlider_1getControlKeyName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x94c60 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x94c64 */ str x19, [sp, #0x10];
    /* 0x94c68 */ mov x29, sp;
    /* 0x94c6c */ mov x19, x0;
    /* 0x94c70 */ mov x0, x2;
    _ZNK8mtlabar314FaceliftSlider17getControlKeyNameEv();
    /* 0x94c78 */ cbz x0, #0x94c98;
    /* 0x94c7c */ ldr x8, [x19];
    /* 0x94c80 */ mov x1, x0;
    /* 0x94c84 */ ldr x2, [x8, #0x538];
    /* 0x94c88 */ mov x0, x19;
    return x0;
}
