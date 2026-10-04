// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1ba28
// Recovered Name: sub_1ba28
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1ba28 | Size: 268 bytes | SHA256: 3dc2a3098d32691fab342537179735d2db94c1867a875054580b2b2efe384e33
// Callers: 0 | Callees: 0 | Imports: 6

// Calls external APIs: _Z17loadLibraryHandlev, _Z20parseManisDeviceInfoPKci, __android_log_print, __stack_chk_fail, dlerror, dlsym
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to find ManisGetDeviceInfo: %s"
//   "Failed to load libManis.so"
//   "ManisGetDeviceInfo"
//   "ManisGetDeviceInfo returned nullptr"

void sub_1ba28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x1ba28 */ stp x29, x30, [sp, #0x10];
    /* 0x1ba2c */ str x19, [sp, #0x20];
    /* 0x1ba30 */ add x29, sp, #0x10;
    /* 0x1ba34 */ mrs x19, tpidr_el0;
    /* 0x1ba38 */ ldr x8, [x19, #0x28];
    /* 0x1ba3c */ str x8, [sp, #8];
    /* 0x1ba40 */ adrp x8, #0x4b000;
    /* 0x1ba44 */ ldrb w8, [x8, #0xee0];
    /* 0x1ba48 */ cbz w8, #0x1ba6c;
    /* 0x1ba4c */ ldr x8, [x19, #0x28];
    /* 0x1ba50 */ ldr x9, [sp, #8];
    return x0;
    _Z17loadLibraryHandlev();
    dlsym();
    _Z20parseManisDeviceInfoPKci();
    dlerror();
    __android_log_print();
    __stack_chk_fail();
}
