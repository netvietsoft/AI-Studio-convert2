// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58acf0
// Recovered Name: sub_58acf0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58acf0 | Size: 36 bytes | SHA256: 71c8804844ce3fec73a01b9e3cbf52fa32d2345d0e07cfdad9c0d3e97ff0c119
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValue(JZ)V (table at 0x10d0580)

jlong sub_58acf0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x58acf0 */ cbz x2, #0x58ad10;
    /* 0x58acf4 */ ldr x9, [x2];
    /* 0x58acf8 */ and w8, w3, #0xff;
    /* 0x58acfc */ mov x0, x2;
    /* 0x58ad00 */ cmp w8, #1;
    /* 0x58ad04 */ ldr x3, [x9, #0x70];
    /* 0x58ad08 */ cset w1, eq;
    /* 0x58ad0c */ br x3;
    return x0;
}
