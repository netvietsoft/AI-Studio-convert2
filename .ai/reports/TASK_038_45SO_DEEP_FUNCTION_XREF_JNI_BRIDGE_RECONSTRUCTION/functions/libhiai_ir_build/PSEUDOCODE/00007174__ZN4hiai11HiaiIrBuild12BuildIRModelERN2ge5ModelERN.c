// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x7174
// Recovered Name: _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x7174 | Size: 220 bytes | SHA256: fb0875ca0e10032c57f81d259534c2dbc21824f6e1f3fad79fd67ae58c78a45b
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataERKNS_12BuildOptionsE, _ZdlPv, __stack_chk_fail

void _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x7174 */ sub sp, sp, #0xc0;
    /* 0x7178 */ stp x30, x23, [sp, #0x90];
    /* 0x717c */ stp x22, x21, [sp, #0xa0];
    /* 0x7180 */ stp x20, x19, [sp, #0xb0];
    /* 0x7184 */ mrs x21, tpidr_el0;
    /* 0x7188 */ mov x22, sp;
    /* 0x718c */ mov x20, x1;
    /* 0x7190 */ ldr x8, [x21, #0x28];
    /* 0x7194 */ adrp x1, #0x1000;
    /* 0x7198 */ add x1, x1, #0xd0c;
    /* 0x719c */ add x0, x22, #0x68;
    sub_659c();
    _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataERKNS_12BuildOptionsE();
    _ZdlPv();
    _ZdlPv();
    sub_7250();
    sub_72c8();
    return x0;
    __stack_chk_fail();
}
