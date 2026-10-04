// Library: libfntvcrash.so
// Function ID: libfntvcrash::0x936c
// Recovered Name: sub_936c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x936c | Size: 472 bytes | SHA256: 2b29dfc5156d027f798b25e266ae19c1672e560d9d0671e8528c8774c7ade967
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nativeInit(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZZ)I (table at 0x15600)
// Calls external APIs: gettimeofday

jlong sub_936c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 118 instructions
    /* 0x936c */ stp x29, x30, [sp, #-0x60]!;
    sub_c9f0();
    /* 0x9374 */ sub sp, sp, #1, lsl #12;
    /* 0x9378 */ sub sp, sp, #0x1f0;
    /* 0x937c */ mrs x21, tpidr_el0;
    /* 0x9380 */ ldr x8, [x21, #0x28];
    /* 0x9384 */ stur x8, [x29, #-0x18];
    /* 0x9388 */ adrp x8, #0x17000;
    /* 0x938c */ ldrb w9, [x8, #0x32c];
    /* 0x9390 */ tbz w9, #0, #0x939c;
    /* 0x9394 */ mov w24, #0x3f7;
    sub_ca0c();
    sub_cbb8();
    sub_ca0c();
    sub_ca0c();
    sub_cc44();
    sub_ca0c();
    sub_ca0c();
    sub_ca0c();
    sub_ca0c();
    sub_ca0c();
    sub_ca0c();
    gettimeofday();
}
