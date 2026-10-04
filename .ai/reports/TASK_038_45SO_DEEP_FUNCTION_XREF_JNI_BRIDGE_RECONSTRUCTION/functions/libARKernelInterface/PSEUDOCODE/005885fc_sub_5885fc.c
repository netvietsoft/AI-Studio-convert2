// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5885fc
// Recovered Name: sub_5885fc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5885fc | Size: 60 bytes | SHA256: 4600d8fcc544997d4d478d147a9c5b3349416b429d6db842ced798f89c507dc5
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetHorizontal(J)Z (table at 0x10cfe60)

jlong sub_5885fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5885fc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588600 */ mov x29, sp;
    /* 0x588604 */ cbz x2, #0x588628;
    /* 0x588608 */ ldr x0, [x2, #0x860];
    /* 0x58860c */ cbz x0, #0x588634;
    /* 0x588610 */ ldr x8, [x0];
    /* 0x588614 */ ldr x8, [x8, #0x30];
    /* 0x588618 */ blr x8;
    /* 0x58861c */ and w0, w0, #1;
    /* 0x588620 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
