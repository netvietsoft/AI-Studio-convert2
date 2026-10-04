// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x89718c
// Recovered Name: sub_89718c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x89718c | Size: 104 bytes | SHA256: 076c9ac531fb53fd5934c9c39d0f0b8bdf7616bbf5aeaa2a5210bb025bcc59cb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "ZN8arkernel19CoreHairPartControl7PrepareEvE3$_0"

void sub_89718c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x89718c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x897190 */ str x19, [sp, #0x10];
    /* 0x897194 */ mov x29, sp;
    /* 0x897198 */ ldr x19, [x0, #8];
    /* 0x89719c */ ldr x8, [x19, #0x20];
    /* 0x8971a0 */ cbz x8, #0x8971bc;
    /* 0x8971a4 */ ldr x0, [x0, #0x10];
    /* 0x8971a8 */ ldr x8, [x0];
    /* 0x8971ac */ ldr x8, [x8, #0x70];
    /* 0x8971b0 */ blr x8;
    /* 0x8971b4 */ ldr x8, [x19, #0x20];
    return x0;
    return x0;
    return x0;
}
