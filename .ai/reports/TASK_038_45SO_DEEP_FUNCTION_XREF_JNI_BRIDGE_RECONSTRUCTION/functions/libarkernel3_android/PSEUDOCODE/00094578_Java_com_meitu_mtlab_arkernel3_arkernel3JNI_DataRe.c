// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94578
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARGyroscopeQuaternion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94578 | Size: 28 bytes | SHA256: 40028b2c3743724e7d4ee72c75788f45353eb3e5359fb1dd7d49f9266458e064
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire28requireARGyroscopeQuaternionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARGyroscopeQuaternion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94578 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9457c */ mov x29, sp;
    /* 0x94580 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire28requireARGyroscopeQuaternionEv();
    /* 0x94588 */ and w0, w0, #1;
    /* 0x9458c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
