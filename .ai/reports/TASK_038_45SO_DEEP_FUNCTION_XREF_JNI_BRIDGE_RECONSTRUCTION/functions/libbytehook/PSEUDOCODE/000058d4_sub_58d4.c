// Library: libbytehook.so
// Function ID: libbytehook::0x58d4
// Recovered Name: sub_58d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58d4 | Size: 644 bytes | SHA256: a2996385c02bf267b737bad31b6d9b3d8805a962fca5c044a456ffb77338fac7
// Callers: 0 | Callees: 3 | Imports: 8

// Calls external APIs: __open_2, __stack_chk_fail, calloc, close, free, fstat, getauxval, strcmp
// Strings referenced:
//   ".symtab"
//   "/system/bin/linker64"

void sub_58d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 161 instructions
    /* 0x58d4 */ stp x29, x30, [sp, #0x90];
    /* 0x58d8 */ stp x28, x27, [sp, #0xa0];
    /* 0x58dc */ stp x26, x25, [sp, #0xb0];
    /* 0x58e0 */ stp x24, x23, [sp, #0xc0];
    /* 0x58e4 */ stp x22, x21, [sp, #0xd0];
    /* 0x58e8 */ stp x20, x19, [sp, #0xe0];
    /* 0x58ec */ add x29, sp, #0x90;
    /* 0x58f0 */ mrs x26, tpidr_el0;
    /* 0x58f4 */ adrp x9, #0x11000;
    /* 0x58f8 */ ldr x8, [x26, #0x28];
    /* 0x58fc */ ldr x9, [x9, #0xaa0];
    getauxval();
    calloc();
    __open_2();
    fstat();
    close();
    sub_5cd8();
    free();
    free();
    free();
    return x0;
    sub_5c20();
    sub_5ccc();
    strcmp();
    sub_5ccc();
    sub_5ccc();
    close();
    sub_5cd8();
    free();
    __stack_chk_fail();
}
