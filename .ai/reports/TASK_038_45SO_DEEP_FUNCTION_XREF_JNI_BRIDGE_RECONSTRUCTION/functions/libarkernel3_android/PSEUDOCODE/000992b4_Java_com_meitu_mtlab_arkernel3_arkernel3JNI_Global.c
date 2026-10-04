// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x992b4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1mountFileSystem
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x992b4 | Size: 144 bytes | SHA256: 086a923d9cd2d686399d88308ce2e5b06492dd1917df4fa625d6bd9a9d4021db
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting15mountFileSystemEPKcPNS_17VirtualFileSystemE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1mountFileSystem(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x992b4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x992b8 */ stp x22, x21, [sp, #0x10];
    /* 0x992bc */ stp x20, x19, [sp, #0x20];
    /* 0x992c0 */ mov x29, sp;
    /* 0x992c4 */ mov x21, x3;
    /* 0x992c8 */ cbz x2, #0x99318;
    /* 0x992cc */ ldr x8, [x0];
    /* 0x992d0 */ mov x19, x2;
    /* 0x992d4 */ mov x1, x2;
    /* 0x992d8 */ mov x2, xzr;
    /* 0x992dc */ mov x20, x0;
    _ZN8mtlabar313GlobalSetting15mountFileSystemEPKcPNS_17VirtualFileSystemE();
    _ZN8mtlabar313GlobalSetting15mountFileSystemEPKcPNS_17VirtualFileSystemE();
    return x0;
}
