// Library: libfntvcrash.so
// Function ID: libfntvcrash::0xbe88
// Recovered Name: sub_be88
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbe88 | Size: 892 bytes | SHA256: fb47c908ed55ab9f998120d060766ea27a5a66e1186a0c9ce4f8968a41a4baf8
// Callers: 0 | Callees: 14 | Imports: 0

// Dynamic Registration: set0(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/Object;)V (table at 0x15660)
// Strings referenced:
//   "illegal class, field name or sig"
//   "illegal name"
//   "illegal object, field name or sig"
//   "illegal sig"

jlong sub_be88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 223 instructions
    /* 0xbe88 */ stp x29, x30, [sp, #-0x60]!;
    /* 0xbe8c */ str x27, [sp, #0x10];
    /* 0xbe90 */ stp x26, x25, [sp, #0x20];
    /* 0xbe94 */ stp x24, x23, [sp, #0x30];
    /* 0xbe98 */ stp x22, x21, [sp, #0x40];
    /* 0xbe9c */ stp x20, x19, [sp, #0x50];
    /* 0xbea0 */ mov x29, sp;
    sub_cc14();
    /* 0xbea8 */ mov x25, x6;
    /* 0xbeac */ mov x21, x5;
    /* 0xbeb0 */ ldr x8, [x8, #0x548];
    sub_c978();
    sub_ca0c();
    sub_c978();
    sub_cc50();
    sub_b658();
    sub_c978();
    sub_c9b8();
    sub_cc74();
    sub_c9b8();
    sub_c9b8();
    sub_cc74();
    sub_c9b8();
    sub_cc88();
    sub_c978();
    sub_cc3c();
    sub_cb08();
    sub_c978();
    sub_cc9c();
    sub_ca14();
    sub_c978();
    sub_cc3c();
    sub_ca70();
    sub_cac4();
    sub_cac4();
    sub_cac4();
    sub_cac4();
}
