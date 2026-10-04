// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b6c0
// Recovered Name: _Z17loadLibraryHandlev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1b6c0 | Size: 164 bytes | SHA256: 14da2a63cefdd98d46bb018b28115ad469e6dcf0c5a66b3d4b807887a2da1215
// Callers: 0 | Callees: 1 | Imports: 6

// Calls external APIs: __android_log_print, __cxa_guard_abort, __cxa_guard_acquire, __cxa_guard_release, dlerror, dlopen
// Strings referenced:
//   "AIModelKitJni"
//   "Failed to load libManis.so: %s"
//   "libManis.so"

void _Z17loadLibraryHandlev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x1b6c0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1b6c4 */ str x19, [sp, #0x10];
    /* 0x1b6c8 */ mov x29, sp;
    /* 0x1b6cc */ nop ;
    /* 0x1b6d0 */ adr x8, #0x4bed8;
    /* 0x1b6d4 */ adrp x19, #0x4b000;
    /* 0x1b6d8 */ ldarb w8, [x8];
    /* 0x1b6dc */ tbz w8, #0, #0x1b718;
    /* 0x1b6e0 */ ldr x0, [x19, #0xed0];
    /* 0x1b6e4 */ cbnz x0, #0x1b70c;
    dlerror();
    __android_log_print();
    return x0;
    __cxa_guard_acquire();
    dlopen();
    __cxa_guard_release();
    __cxa_guard_abort();
    sub_3bb6c();
}
