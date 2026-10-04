// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x32fa40
// Recovered Name: _ZN65_$LT$object..common..SegmentFlags$u20$as$u20$core..fmt..Debug$GT$3fmt17hb326b0ffbf632eddE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x32fa40 | Size: 332 bytes | SHA256: e6f37bf8e5d820243f89e0b1087b0af8383d6ea91426eaa3bde831b2227b038d
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _ZN4core3fmt9Formatter26debug_struct_field1_finish17h3ce2c041f21a85bbE, _ZN4core3fmt9Formatter26debug_struct_field3_finish17h754642d57d06dce9E, _ZN4core3fmt9Formatter9write_str17h1c5c93915ba5f2c6E
// Strings referenced:
//   "initprote_lfanew"
//   "l2"

void _ZN65_$LT$object..common..SegmentFlags$u20$as$u20$core..fmt..Debug$GT$3fmt17hb326b0ffbf632eddE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 83 instructions
    /* 0x32fa40 */ sub sp, sp, #0x60;
    /* 0x32fa44 */ str x30, [sp, #0x50];
    /* 0x32fa48 */ ldr w8, [x0];
    /* 0x32fa4c */ adrp x9, #0xdf000;
    /* 0x32fa50 */ add x9, x9, #0x6ce;
    /* 0x32fa54 */ adr x10, #0x32fa64;
    /* 0x32fa58 */ ldrb w11, [x9, x8];
    /* 0x32fa5c */ add x10, x10, x11, lsl #2;
    /* 0x32fa60 */ br x10;
    /* 0x32fa64 */ ldr x30, [sp, #0x50];
    /* 0x32fa68 */ adrp x8, #0xcc000;
    _ZN4core3fmt9Formatter26debug_struct_field3_finish17h754642d57d06dce9E();
    return x0;
    _ZN4core3fmt9Formatter26debug_struct_field1_finish17h3ce2c041f21a85bbE();
    return x0;
    _ZN4core3fmt9Formatter26debug_struct_field1_finish17h3ce2c041f21a85bbE();
    return x0;
}
