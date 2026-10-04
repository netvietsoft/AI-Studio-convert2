// Library: libarkernel3.so
// Function ID: libarkernel3::0x6351bc
// Recovered Name: sub_6351bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6351bc | Size: 344 bytes | SHA256: 40f5b59ee2231d3e2acffb31acbe492aba58eb7b3190701837f64e82a3aec99f
// Callers: 0 | Callees: 10 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Invalid number of parameters (expected 1)."
//   "lua_ScriptHost_getMultiplySegmentType - Failed to match the given parameters to a valid function signature."

void sub_6351bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 86 instructions
    /* 0x6351bc */ stp x29, x30, [sp, #0x20];
    /* 0x6351c0 */ str x21, [sp, #0x30];
    /* 0x6351c4 */ stp x20, x19, [sp, #0x40];
    /* 0x6351c8 */ add x29, sp, #0x20;
    /* 0x6351cc */ mrs x20, tpidr_el0;
    /* 0x6351d0 */ mov x19, x0;
    /* 0x6351d4 */ ldr x8, [x20, #0x28];
    /* 0x6351d8 */ stur x8, [x29, #-8];
    sub_b783a0();
    /* 0x6351e0 */ cmp w0, #1;
    /* 0x6351e4 */ b.ne #0x635280;
    sub_b7868c();
    sub_6344a0();
    sub_635c94();
    sub_b792a8();
    sub_b78d10();
    sub_b78d10();
    sub_b79498();
    sub_b78de0();
    sub_b79ca8();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
