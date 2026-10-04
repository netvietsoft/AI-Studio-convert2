// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8941e0
// Recovered Name: sub_8941e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8941e0 | Size: 144 bytes | SHA256: 7865c2be184cb2070083c9149176c1e1099c707b5fbe6c1b823b93d19db17f32
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "CoreMaskDaubPart::SetHairMakeUpInfo:%p"
//   "arkernel"

void sub_8941e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x8941e0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8941e4 */ stp x20, x19, [sp, #0x10];
    /* 0x8941e8 */ mov x29, sp;
    /* 0x8941ec */ adrp x8, #0x10c5000;
    /* 0x8941f0 */ mov x19, x1;
    /* 0x8941f4 */ mov x20, x0;
    /* 0x8941f8 */ ldr x8, [x8, #0x7a8];
    /* 0x8941fc */ ldr w8, [x8];
    /* 0x894200 */ cmp w8, #2;
    /* 0x894204 */ b.gt #0x894254;
    /* 0x894208 */ adrp x8, #0x1108000;
    sub_5a6b20();
    __android_log_print();
    sub_c40e68();
    return x0;
}
