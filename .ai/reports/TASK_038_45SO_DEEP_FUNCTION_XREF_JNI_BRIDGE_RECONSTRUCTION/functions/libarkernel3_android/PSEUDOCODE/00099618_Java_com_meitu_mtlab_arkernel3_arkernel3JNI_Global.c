// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99618
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1isStopedSoundService
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99618 | Size: 24 bytes | SHA256: fe99f201481010632f372c81daac9047520db907da52fac78dbfe52ee098faf4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting20isStopedSoundServiceEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1isStopedSoundService(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x99618 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9961c */ mov x29, sp;
    _ZN8mtlabar313GlobalSetting20isStopedSoundServiceEv();
    /* 0x99624 */ and w0, w0, #1;
    /* 0x99628 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
