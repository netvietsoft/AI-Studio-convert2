// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x445e4
// Recovered Name: JNI_OnLoad
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x445e4 | Size: 168 bytes | SHA256: e8a5153433646c9efed190e9a464e63de327505bc5227c7c08a56b5f13c8d3fe
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: JUCE_JNI_OnLoad, __android_log_print
// Strings referenced:
//   "JNI_OnLoad"

jobject JNI_OnLoad(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x445e4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x445e8 */ str x21, [sp, #0x10];
    /* 0x445ec */ stp x20, x19, [sp, #0x20];
    /* 0x445f0 */ mov x29, sp;
    /* 0x445f4 */ mov x19, x1;
    /* 0x445f8 */ mov x20, x0;
    sub_4415c();
    sub_44024();
    /* 0x44604 */ mov x21, x0;
    /* 0x44608 */ mov x0, x20;
    /* 0x4460c */ mov x1, x19;
    JUCE_JNI_OnLoad();
    sub_44494();
    return x0;
    __android_log_print();
    return x0;
}
