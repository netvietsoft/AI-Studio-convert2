// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x999a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getSDKVersion
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x999a4 | Size: 64 bytes | SHA256: 7f07f66f8f2967f0ef668d3f127d08fff5bab2dadabf2eb6b35cc4b3527d432a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting13getSDKVersionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1getSDKVersion(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x999a4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x999a8 */ str x19, [sp, #0x10];
    /* 0x999ac */ mov x29, sp;
    /* 0x999b0 */ mov x19, x0;
    _ZN8mtlabar313GlobalSetting13getSDKVersionEv();
    /* 0x999b8 */ cbz x0, #0x999d8;
    /* 0x999bc */ ldr x8, [x19];
    /* 0x999c0 */ mov x1, x0;
    /* 0x999c4 */ ldr x2, [x8, #0x538];
    /* 0x999c8 */ mov x0, x19;
    /* 0x999cc */ ldr x19, [sp, #0x10];
    return x0;
}
