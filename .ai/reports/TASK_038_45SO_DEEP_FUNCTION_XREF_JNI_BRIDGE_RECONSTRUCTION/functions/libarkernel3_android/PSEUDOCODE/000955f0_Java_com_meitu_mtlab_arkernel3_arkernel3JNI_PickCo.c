// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x955f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1setCurrentValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x955f0 | Size: 32 bytes | SHA256: 61194ec7d2979f98f658cbc5ea266ac66bab3b2eea2e4dd34c9bd3b163d91c49
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316PickColorControl15setCurrentValueEmfff

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1setCurrentValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x955f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x955f4 */ mov x29, sp;
    /* 0x955f8 */ mov x1, x4;
    /* 0x955fc */ mov x0, x2;
    _ZN8mtlabar316PickColorControl15setCurrentValueEmfff();
    /* 0x95604 */ and w0, w0, #1;
    /* 0x95608 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
