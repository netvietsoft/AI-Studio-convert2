// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99344
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1unmountFileSystem
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99344 | Size: 132 bytes | SHA256: ea6ac8e84d53deb584b923ef9f099851ae27371b6be4fcac9b0c884d2112fcfb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting17unmountFileSystemEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1unmountFileSystem(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x99344 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x99348 */ stp x22, x21, [sp, #0x10];
    /* 0x9934c */ stp x20, x19, [sp, #0x20];
    /* 0x99350 */ mov x29, sp;
    /* 0x99354 */ cbz x2, #0x993a0;
    /* 0x99358 */ ldr x8, [x0];
    /* 0x9935c */ mov x19, x2;
    /* 0x99360 */ mov x1, x2;
    /* 0x99364 */ mov x2, xzr;
    /* 0x99368 */ mov x20, x0;
    /* 0x9936c */ ldr x8, [x8, #0x548];
    _ZN8mtlabar313GlobalSetting17unmountFileSystemEPKc();
    _ZN8mtlabar313GlobalSetting17unmountFileSystemEPKc();
    return x0;
}
