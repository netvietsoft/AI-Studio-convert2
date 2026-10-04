// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc333dc
// Recovered Name: sub_c333dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc333dc | Size: 2204 bytes | SHA256: 30ceda2b62cb513c93798527078c4281a1db045af57153d281776fd3f4d49ca8
// Callers: 0 | Callees: 31 | Imports: 4

// Calls external APIs: _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_, _ZdlPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "AdvanceMakeupParmeters"
//   "DebugMakeupAlphaParameters"
//   "EnableFaceLiftSharp"
//   "EnvironmentAlphaAdjustParameters"
//   "EyeOcclusionOptimizeEnable"

void sub_c333dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 551 instructions
    /* 0xc333dc */ stp x29, x30, [sp, #0xa0];
    /* 0xc333e0 */ stp x28, x27, [sp, #0xb0];
    /* 0xc333e4 */ stp x26, x25, [sp, #0xc0];
    /* 0xc333e8 */ stp x24, x23, [sp, #0xd0];
    /* 0xc333ec */ stp x22, x21, [sp, #0xe0];
    /* 0xc333f0 */ stp x20, x19, [sp, #0xf0];
    /* 0xc333f4 */ add x29, sp, #0xa0;
    /* 0xc333f8 */ mrs x8, tpidr_el0;
    /* 0xc333fc */ mov x19, x0;
    /* 0xc33400 */ sub x0, x29, #0x28;
    /* 0xc33404 */ str x8, [sp];
    sub_5ab12c();
    sub_58f19c();
    sub_5a86c8();
    _ZdlPv();
    sub_5ab8b8();
    sub_5a8818();
    sub_5ab268();
    sub_5ab6a8();
    sub_5a8cfc();
    sub_c33c78();
    sub_5a8cfc();
    sub_c345b0();
    sub_5a8cfc();
    sub_c34b58();
    sub_5a8cfc();
    sub_c34bd8();
    sub_5a8cfc();
    sub_baba0c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8cfc();
    sub_c34c5c();
    sub_5a8cfc();
    sub_c34ed8();
    sub_5a8cfc();
    sub_c34ff8();
    sub_5a8cfc();
    sub_c353a8();
    sub_5a8cfc();
    sub_c354cc();
    sub_5a8cfc();
    sub_c35748();
    sub_5a8cfc();
    sub_c35b3c();
    sub_5a8cfc();
    sub_c35c00();
    sub_5a8cfc();
    sub_c35ccc();
    sub_5a8cfc();
    sub_c35ec8();
    sub_5a8cfc();
    sub_c3675c();
    sub_5a8cfc();
    sub_c36820();
    sub_5a8cfc();
    sub_c368a4();
    sub_5a8cfc();
    sub_c36968();
    sub_5a8de8();
    sub_5a8818();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    sub_5a6b20();
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5ab178();
    return x0;
    __stack_chk_fail();
}
