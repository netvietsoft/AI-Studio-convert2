// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e408
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getSvgPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e408 | Size: 64 bytes | SHA256: 3e5ea8ea5cf1cc642cc2dec1b312be16c41c65507a481c537fa3d9685e6424e2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface10getSvgPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getSvgPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8e408 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8e40c */ str x19, [sp, #0x10];
    /* 0x8e410 */ mov x29, sp;
    /* 0x8e414 */ mov x19, x0;
    /* 0x8e418 */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface10getSvgPathEv();
    /* 0x8e420 */ ldr x8, [x19];
    /* 0x8e424 */ ldrb w9, [x0];
    /* 0x8e428 */ ldr x10, [x0, #0x10];
    /* 0x8e42c */ tst w9, #1;
    /* 0x8e430 */ ldr x2, [x8, #0x538];
}
