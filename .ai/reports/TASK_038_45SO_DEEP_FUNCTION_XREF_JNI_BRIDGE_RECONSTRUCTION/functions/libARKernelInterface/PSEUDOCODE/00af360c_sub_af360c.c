// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xaf360c
// Recovered Name: sub_af360c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaf360c | Size: 264 bytes | SHA256: ae559567193503bf776aa495f0eb71bafc45074d492cc1e3ca86d9220d5f9b8d
// Callers: 0 | Callees: 3 | Imports: 0

// Strings referenced:
//   "BlurCount"
//   "LargeFactor"
//   "TriggerFactor"

void sub_af360c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 66 instructions
    /* 0xaf360c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xaf3610 */ stp x22, x21, [sp, #0x10];
    /* 0xaf3614 */ stp x20, x19, [sp, #0x20];
    /* 0xaf3618 */ mov x29, sp;
    /* 0xaf361c */ mov x21, x1;
    /* 0xaf3620 */ mov x19, x0;
    sub_61bfa0();
    /* 0xaf3628 */ mov w20, w0;
    /* 0xaf362c */ tbz w0, #0, #0xaf3700;
    /* 0xaf3630 */ ldr x8, [x21];
    /* 0xaf3634 */ mov x0, x21;
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8d1c();
    return x0;
}
