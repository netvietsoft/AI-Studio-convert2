// Library: libarkernel3.so
// Function ID: libarkernel3::0x63512c
// Recovered Name: sub_63512c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x63512c | Size: 144 bytes | SHA256: d13cf4f09b165e1e211b9fada113daee20df010631757e43c02cc1b8d89eca83
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_ScriptHost_getSegmentType - Failed to match the given parameters to a valid function signature."

void sub_63512c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x63512c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x635130 */ str x19, [sp, #0x10];
    /* 0x635134 */ mov x29, sp;
    /* 0x635138 */ mov x19, x0;
    sub_b783a0();
    /* 0x635140 */ cmp w0, #1;
    /* 0x635144 */ b.ne #0x635184;
    /* 0x635148 */ mov x0, x19;
    /* 0x63514c */ mov w1, #1;
    sub_b7868c();
    /* 0x635154 */ cmp w0, #7;
    sub_6344a0();
    sub_b78d10();
    sub_b78de0();
    sub_b79ca8();
    return x0;
}
