// Library: libc++_shared.so
// Function ID: libc++_shared::0x9edac
// Recovered Name: sub_9edac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9edac | Size: 328 bytes | SHA256: a8709fa05f4dea9743f3ec79c46485cb215da493a5d9efb02f862adbebca0924
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __cxa_get_globals
// Strings referenced:
//   "terminating due to %s exception of type %s"
//   "terminating due to %s exception of type %s: %s"
//   "terminating due to %s foreign exception"

void sub_9edac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 82 instructions
    /* 0x9edac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9edb0 */ str x21, [sp, #0x10];
    /* 0x9edb4 */ stp x20, x19, [sp, #0x20];
    /* 0x9edb8 */ mov x29, sp;
    __cxa_get_globals();
    /* 0x9edc0 */ cbz x0, #0x9edcc;
    /* 0x9edc4 */ ldr x19, [x0];
    /* 0x9edc8 */ cbnz x19, #0x9edd8;
    /* 0x9edcc */ nop ;
    /* 0x9edd0 */ adr x0, #0x56f78;
    sub_a0110();
    sub_ba934();
    sub_ba928();
    sub_a0110();
    sub_1327e8();
    sub_a0110();
    sub_a0110();
    sub_12e82c();
    sub_9ef48();
}
