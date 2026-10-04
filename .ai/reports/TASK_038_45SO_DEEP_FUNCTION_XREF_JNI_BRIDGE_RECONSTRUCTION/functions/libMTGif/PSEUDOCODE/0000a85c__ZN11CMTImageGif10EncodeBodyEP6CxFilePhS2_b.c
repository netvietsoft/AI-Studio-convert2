// Library: libMTGif.so
// Function ID: libMTGif::0xa85c
// Recovered Name: _ZN11CMTImageGif10EncodeBodyEP6CxFilePhS2_b
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xa85c | Size: 380 bytes | SHA256: 1c324f8bb0bc6c4feb27725608d8db110c875e0f23d0507f56b6d55cfeffed7f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN11CMTImageGif11compressLZWEiPhP6CxFile

void _ZN11CMTImageGif10EncodeBodyEP6CxFilePhS2_b(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 95 instructions
    /* 0xa85c */ stp x29, x30, [sp, #-0x50]!;
    /* 0xa860 */ str x25, [sp, #0x10];
    /* 0xa864 */ stp x24, x23, [sp, #0x20];
    /* 0xa868 */ stp x22, x21, [sp, #0x30];
    /* 0xa86c */ stp x20, x19, [sp, #0x40];
    /* 0xa870 */ mov x29, sp;
    /* 0xa874 */ str xzr, [x0, #0x10];
    /* 0xa878 */ mov x21, x0;
    /* 0xa87c */ mov x19, x1;
    /* 0xa880 */ ldr x8, [x1];
    /* 0xa884 */ add x25, x0, #0xc, lsl #12;
    _ZN11CMTImageGif11compressLZWEiPhP6CxFile();
}
