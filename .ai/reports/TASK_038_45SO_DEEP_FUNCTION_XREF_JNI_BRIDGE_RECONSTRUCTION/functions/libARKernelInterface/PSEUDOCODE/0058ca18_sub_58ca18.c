// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ca18
// Recovered Name: sub_58ca18
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58ca18 | Size: 212 bytes | SHA256: f54122d375764ce5818bec8474b027246c5897207f9a9efcf990cb6ffdf9085c
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

void sub_58ca18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x58ca18 */ stp x29, x30, [sp, #8];
    /* 0x58ca1c */ str x19, [sp, #0x18];
    /* 0x58ca20 */ add x29, sp, #8;
    /* 0x58ca24 */ cbz x2, #0x58cab8;
    /* 0x58ca28 */ mov x0, x2;
    /* 0x58ca2c */ mov x19, x2;
    /* 0x58ca30 */ fmov s8, s0;
    sub_8e0920();
    /* 0x58ca38 */ cmp w0, #0x6e;
    /* 0x58ca3c */ b.ne #0x58ca70;
    /* 0x58ca40 */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
