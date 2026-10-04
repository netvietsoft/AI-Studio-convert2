// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97be4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97be4 | Size: 68 bytes | SHA256: 315c56e36bf14248f8faecac1a41771daf2ee70926949e4701e74d0f500f5727
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl13getCustomNameEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x97be4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x97be8 */ str x19, [sp, #0x10];
    /* 0x97bec */ mov x29, sp;
    /* 0x97bf0 */ mov x19, x0;
    /* 0x97bf4 */ mov x0, x2;
    _ZN8mtlabar311PartControl13getCustomNameEv();
    /* 0x97bfc */ cbz x0, #0x97c1c;
    /* 0x97c00 */ ldr x8, [x19];
    /* 0x97c04 */ mov x1, x0;
    /* 0x97c08 */ ldr x2, [x8, #0x538];
    /* 0x97c0c */ mov x0, x19;
    return x0;
}
