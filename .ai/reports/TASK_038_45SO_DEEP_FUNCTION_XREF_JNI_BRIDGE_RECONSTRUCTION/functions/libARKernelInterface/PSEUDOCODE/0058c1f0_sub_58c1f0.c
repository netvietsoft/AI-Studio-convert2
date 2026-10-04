// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c1f0
// Recovered Name: sub_58c1f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c1f0 | Size: 80 bytes | SHA256: 5ab3123c3447710b8d2769688c0159a299bcca3c780f0e6bfed18d28ce3e62b9
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x10d0880)
// Calls external APIs: _Znwm

jlong sub_58c1f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x58c1f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x58c1f4 */ mov x29, sp;
    /* 0x58c1f8 */ mov w0, #0x40;
    _Znwm();
    /* 0x58c200 */ fmov d0, xzr;
    /* 0x58c204 */ adrp x8, #0x252000;
    /* 0x58c208 */ str xzr, [x0, #0x28];
    /* 0x58c20c */ ldr q1, [x8, #0x8c0];
    /* 0x58c210 */ adrp x8, #0x257000;
    /* 0x58c214 */ strb wzr, [x0, #0x14];
    /* 0x58c218 */ ldr d2, [x8, #0xf10];
    return x0;
}
