// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9945c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getDirectory
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9945c | Size: 68 bytes | SHA256: 80e66cc6fb7df8ea8a7d3ecfd3afcbf7d8423363f997b148a8dba53ecfa441b4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getDirectory(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x9945c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x99460 */ str x19, [sp, #0x10];
    /* 0x99464 */ mov x29, sp;
    /* 0x99468 */ mov x19, x0;
    /* 0x9946c */ mov w0, w2;
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    /* 0x99474 */ cbz x0, #0x99494;
    /* 0x99478 */ ldr x8, [x19];
    /* 0x9947c */ mov x1, x0;
    /* 0x99480 */ ldr x2, [x8, #0x538];
    /* 0x99484 */ mov x0, x19;
    return x0;
}
