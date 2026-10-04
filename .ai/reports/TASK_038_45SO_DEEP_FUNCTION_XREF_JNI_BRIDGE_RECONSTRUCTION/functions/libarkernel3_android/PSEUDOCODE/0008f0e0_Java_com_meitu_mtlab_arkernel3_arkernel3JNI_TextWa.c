// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f0e0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextWarpConfigInterface_1getWarpConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f0e0 | Size: 64 bytes | SHA256: 3418bec5d28bfef8de1e0087daa6afc3fd83ae8ac3061837c459dfd9b7e9b96a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextWarpConfigInterface17getWarpConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextWarpConfigInterface_1getWarpConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8f0e0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8f0e4 */ str x19, [sp, #0x10];
    /* 0x8f0e8 */ mov x29, sp;
    /* 0x8f0ec */ mov x19, x0;
    /* 0x8f0f0 */ mov x0, x2;
    _ZNK8mtlabar323TextWarpConfigInterface17getWarpConfigPathEv();
    /* 0x8f0f8 */ ldr x8, [x19];
    /* 0x8f0fc */ ldrb w9, [x0];
    /* 0x8f100 */ ldr x10, [x0, #0x10];
    /* 0x8f104 */ tst w9, #1;
    /* 0x8f108 */ ldr x2, [x8, #0x538];
}
