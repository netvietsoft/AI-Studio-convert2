// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1204cc
// Recovered Name: sub_1204cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1204cc | Size: 236 bytes | SHA256: 9d909c7ad5cddc28593c792d09b19839bbba91f4212d0b07a1c81117311ce5a9
// Callers: 0 | Callees: 0 | Imports: 3

// Dynamic Registration: native_finalize(J)I (table at 0x13a6d0)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIMediaEntries_native_finalize"
//   "PVGCodec"

jlong sub_1204cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x1204cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1204d0 */ str x19, [sp, #0x10];
    /* 0x1204d4 */ mov x29, sp;
    /* 0x1204d8 */ cbz x2, #0x120510;
    /* 0x1204dc */ ldr x8, [x2];
    /* 0x1204e0 */ mov x0, x2;
    /* 0x1204e4 */ mov x19, x2;
    /* 0x1204e8 */ ldr x8, [x8, #0x18];
    /* 0x1204ec */ blr x8;
    /* 0x1204f0 */ ldr x8, [x19];
    /* 0x1204f4 */ mov x0, x19;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
