// Library: libManis.so
// Function ID: libManis::0x32be54
// Recovered Name: sub_32be54
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32be54 | Size: 1468 bytes | SHA256: b24cdb4c3a97b8655a8d7b7c042a7fe3b51d9b59adcadc9518b726d9cff74a6c
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZnamRKSt9nothrow_t, __android_log_print, __stack_chk_fail, fprintf
// Strings referenced:
//   "Mizar"
//   "anisEngineExecutor_Expand - Failed to match the given parameters to a valid function signature."
//   "ll"

void sub_32be54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 367 instructions
    /* 0x32be54 */ stp x29, x30, [sp, #0xf0];
    /* 0x32be58 */ str x28, [sp, #0x100];
    /* 0x32be5c */ stp x22, x21, [sp, #0x110];
    /* 0x32be60 */ stp x20, x19, [sp, #0x120];
    /* 0x32be64 */ add x29, sp, #0xf0;
    /* 0x32be68 */ mrs x20, tpidr_el0;
    /* 0x32be6c */ adrp x1, #0x979000;
    /* 0x32be70 */ mov x19, x0;
    /* 0x32be74 */ ldr x8, [x20, #0x28];
    /* 0x32be78 */ stur x8, [x29, #-8];
    /* 0x32be7c */ ldr x1, [x1, #0x5d0];
    _ZnamRKSt9nothrow_t();
    __android_log_print();
    fprintf();
    return x0;
    __stack_chk_fail();
}
