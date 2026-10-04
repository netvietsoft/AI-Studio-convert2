// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x86fec
// Recovered Name: sub_86fec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x86fec | Size: 80 bytes | SHA256: 05d28098882ab648e0f1780fc1332f3a5b9264ba8db5d95dbcff1bdf9e0295cc
// Callers: 15 | Callees: 2 | Imports: 3

// Calls external APIs: __cxa_allocate_exception, __cxa_free_exception, __cxa_throw

void sub_86fec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x86fec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x86ff0 */ stp x20, x19, [sp, #0x10];
    /* 0x86ff4 */ mov x29, sp;
    /* 0x86ff8 */ mov x20, x0;
    /* 0x86ffc */ mov w0, #0x10;
    __cxa_allocate_exception();
    /* 0x87004 */ mov x19, x0;
    /* 0x87008 */ mov x1, x20;
    sub_8703c();
    /* 0x87010 */ adrp x1, #0xaa000;
    /* 0x87014 */ adrp x2, #0xaa000;
    __cxa_throw();
    __cxa_free_exception();
    sub_9c5c8();
}
