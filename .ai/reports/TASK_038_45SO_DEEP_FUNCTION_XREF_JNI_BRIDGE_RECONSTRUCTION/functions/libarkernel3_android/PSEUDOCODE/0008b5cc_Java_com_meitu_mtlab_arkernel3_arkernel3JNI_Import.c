// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b5cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportBytesData_1imageSize_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b5cc | Size: 16 bytes | SHA256: 013ea2fe60feaeff56d3ae146d0776b78c791bde0829c1cfe4a0316a9ce3e2d8
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportBytesData_1imageSize_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b5cc */ cbz x2, #0x8b5d8;
    /* 0x8b5d0 */ ldr x8, [x4];
    /* 0x8b5d4 */ str x8, [x2, #8];
    return x0;
}
