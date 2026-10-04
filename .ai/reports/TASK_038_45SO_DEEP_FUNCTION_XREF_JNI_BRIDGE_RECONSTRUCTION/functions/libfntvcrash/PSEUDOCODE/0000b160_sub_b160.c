// Library: libfntvcrash.so
// Function ID: libfntvcrash::0xb160
// Recovered Name: sub_b160
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb160 | Size: 164 bytes | SHA256: 71f21b9d86dd91f64a36c89ca1412a6ec298f0fa2415a4f69affa82fdd3deeb1
// Callers: 0 | Callees: 6 | Imports: 0

// Dynamic Registration: fC(Ljava/lang/String;)Ljava/lang/Class; (table at 0x15630)
// Strings referenced:
//   "class name is null"

jlong sub_b160(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0xb160 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xb164 */ stp x22, x21, [sp, #0x10];
    /* 0xb168 */ stp x20, x19, [sp, #0x20];
    /* 0xb16c */ mov x29, sp;
    /* 0xb170 */ ldr x8, [x0];
    /* 0xb174 */ mov x20, x2;
    /* 0xb178 */ mov x1, x2;
    /* 0xb17c */ mov x2, xzr;
    /* 0xb180 */ mov x19, x0;
    sub_ca0c();
    /* 0xb188 */ ldr x8, [x19];
    sub_c978();
    sub_cc5c();
    sub_caec();
    sub_c9b8();
    sub_c9b8();
    sub_ca70();
    return x0;
}
