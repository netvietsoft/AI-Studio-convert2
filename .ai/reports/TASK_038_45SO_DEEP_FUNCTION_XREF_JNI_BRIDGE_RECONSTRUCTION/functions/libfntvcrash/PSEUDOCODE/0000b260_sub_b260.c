// Library: libfntvcrash.so
// Function ID: libfntvcrash::0xb260
// Recovered Name: sub_b260
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb260 | Size: 876 bytes | SHA256: 78f00bc66291b76a35489061f7468cb0c59cbfa894976dac4645fd08f0b09a8d
// Callers: 0 | Callees: 19 | Imports: 1

// Dynamic Registration: inv0(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object; (table at 0x15648)
// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "illegal arg sig"
//   "illegal name"
//   "illegal return sig"

jlong sub_b260(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 219 instructions
    /* 0xb260 */ stp x29, x30, [sp, #-0x60]!;
    sub_c9f0();
    /* 0xb268 */ sub sp, sp, #0x50;
    /* 0xb26c */ mrs x23, tpidr_el0;
    /* 0xb270 */ mov x25, x2;
    /* 0xb274 */ mov x1, x3;
    /* 0xb278 */ ldr x8, [x23, #0x28];
    /* 0xb27c */ mov x2, xzr;
    /* 0xb280 */ mov x26, x7;
    /* 0xb284 */ mov x27, x6;
    /* 0xb288 */ mov x24, x5;
    sub_ca0c();
    sub_c978();
    sub_cbb8();
    sub_c978();
    sub_ca0c();
    sub_c978();
    sub_cc28();
    sub_ccec();
    sub_cc28();
    sub_b658();
    sub_ccc8();
    sub_c9b8();
    sub_ca14();
    sub_c978();
    sub_ca70();
    sub_ca70();
    sub_c9b8();
    sub_ccec();
    sub_cc68();
    sub_ca14();
    sub_ca50();
    sub_ca1c();
    return x0;
    sub_c978();
    sub_ccf4();
    sub_b7b8();
    sub_ca70();
    sub_ccf4();
    sub_ba64();
    sub_c978();
    sub_bcb8();
    sub_bccc();
    sub_c9b8();
    __stack_chk_fail();
}
