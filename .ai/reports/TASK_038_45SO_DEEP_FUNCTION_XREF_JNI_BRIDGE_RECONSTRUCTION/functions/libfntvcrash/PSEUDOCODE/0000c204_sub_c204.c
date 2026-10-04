// Library: libfntvcrash.so
// Function ID: libfntvcrash::0xc204
// Recovered Name: sub_c204
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xc204 | Size: 948 bytes | SHA256: fd7e1d09feb6aa6bb76a7d2cd5cbd78294bf261968c4f7cd2a2bce43458b64ba
// Callers: 0 | Callees: 20 | Imports: 0

// Dynamic Registration: get0(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;)Ljava/lang/Object; (table at 0x15678)
// Strings referenced:
//   "8iq"
//   "illegal class, field name or sig"
//   "illegal name"
//   "illegal object, field name or sig"
//   "illegal sig"

jlong sub_c204(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 237 instructions
    /* 0xc204 */ stp x29, x30, [sp, #-0x60]!;
    /* 0xc208 */ str x27, [sp, #0x10];
    /* 0xc20c */ stp x26, x25, [sp, #0x20];
    /* 0xc210 */ stp x24, x23, [sp, #0x30];
    /* 0xc214 */ stp x22, x21, [sp, #0x40];
    /* 0xc218 */ stp x20, x19, [sp, #0x50];
    /* 0xc21c */ mov x29, sp;
    sub_cc14();
    /* 0xc224 */ mov x20, x5;
    /* 0xc228 */ mov w25, w4;
    /* 0xc22c */ ldr x8, [x8, #0x548];
    sub_c978();
    sub_cc50();
    sub_ca0c();
    sub_c978();
    sub_c9b8();
    sub_ca70();
    return x0;
    sub_cc88();
    sub_c978();
    sub_ccdc();
    sub_c9b8();
    sub_cb08();
    sub_c978();
    sub_cc9c();
    sub_ca14();
    sub_c978();
    sub_ccdc();
    sub_cb90();
    sub_ca34();
    sub_ca70();
    sub_cc50();
    sub_c9b8();
    sub_c978();
    sub_cc5c();
    sub_bccc();
    sub_c9b8();
    sub_ca5c();
    sub_ca5c();
    sub_cab4();
    sub_cafc();
    sub_ccc8();
    sub_cab4();
    sub_cbd8();
    sub_ccc8();
    sub_cb90();
    sub_ca34();
    sub_cab4();
    sub_cafc();
}
