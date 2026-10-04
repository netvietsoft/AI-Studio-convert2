// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d1f8
// Recovered Name: sub_58d1f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58d1f8 | Size: 96 bytes | SHA256: 5db0232fca5521b89ef590703d33d5ab8e6488c7152c30be64cfdd98579621da
// Callers: 1 | Callees: 0 | Imports: 0

// Strings referenced:
//   "com/meitu/mtlab/arkernelinterface/core/PartControl/ARKernelHairDaubControlInterfaceJNI"

void sub_58d1f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x58d1f8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d1fc */ str x19, [sp, #0x10];
    /* 0x58d200 */ mov x29, sp;
    /* 0x58d204 */ ldr x8, [x0];
    /* 0x58d208 */ adrp x1, #0x21d000;
    /* 0x58d20c */ add x1, x1, #0x608;
    /* 0x58d210 */ mov x19, x0;
    /* 0x58d214 */ ldr x8, [x8, #0x30];
    /* 0x58d218 */ blr x8;
    /* 0x58d21c */ cbz x0, #0x58d248;
    /* 0x58d220 */ ldr x8, [x19];
    return x0;
}
