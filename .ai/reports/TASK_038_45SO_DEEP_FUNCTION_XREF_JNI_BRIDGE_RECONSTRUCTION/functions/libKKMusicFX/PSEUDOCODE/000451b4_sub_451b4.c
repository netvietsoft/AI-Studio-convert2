// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x451b4
// Recovered Name: sub_451b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x451b4 | Size: 108 bytes | SHA256: e09265ee6310e96cef2818d083da75eb514509c87abedf1628aa59011d632bcb
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeRelease()V (table at 0x7f930)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "com_meitu_media_mfx_KKLoudMeter_nativeRelease"

jlong sub_451b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x451b4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x451b8 */ mov x29, sp;
    sub_44f2c();
    /* 0x451c0 */ cbz x0, #0x451d4;
    /* 0x451c4 */ ldr x8, [x0];
    /* 0x451c8 */ ldr x1, [x8, #8];
    /* 0x451cc */ ldp x29, x30, [sp], #0x10;
    /* 0x451d0 */ br x1;
    /* 0x451d4 */ adrp x8, #0x81000;
    /* 0x451d8 */ ldr x8, [x8, #0xd20];
    /* 0x451dc */ ldr w8, [x8];
    return x0;
}
