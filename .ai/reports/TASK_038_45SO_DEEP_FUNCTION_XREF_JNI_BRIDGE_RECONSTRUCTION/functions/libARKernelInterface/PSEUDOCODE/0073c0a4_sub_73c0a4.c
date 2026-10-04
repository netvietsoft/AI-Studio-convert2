// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x73c0a4
// Recovered Name: sub_73c0a4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x73c0a4 | Size: 1196 bytes | SHA256: 55da0cddfc19e79cbd81eef32b78060526d8edf956a4aa91cb6f46d0ee368c69
// Callers: 1 | Callees: 2 | Imports: 0

// Strings referenced:
//   "EnableAnimal"
//   "EnableFace"
//   "EnableFace3DFA"
//   "EnableFace3DFAMesh"
//   "EnableFaceDL3DNet"

void sub_73c0a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 299 instructions
    /* 0x73c0a4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x73c0a8 */ str x21, [sp, #0x10];
    /* 0x73c0ac */ stp x20, x19, [sp, #0x20];
    /* 0x73c0b0 */ mov x29, sp;
    /* 0x73c0b4 */ ldr x8, [x0];
    /* 0x73c0b8 */ mov x20, x0;
    /* 0x73c0bc */ mov x19, x1;
    /* 0x73c0c0 */ ldr x8, [x8, #0xa8];
    /* 0x73c0c4 */ blr x8;
    /* 0x73c0c8 */ ldr x8, [x20];
    /* 0x73c0cc */ adrp x1, #0x23b000;
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8d1c();
    return x0;
}
