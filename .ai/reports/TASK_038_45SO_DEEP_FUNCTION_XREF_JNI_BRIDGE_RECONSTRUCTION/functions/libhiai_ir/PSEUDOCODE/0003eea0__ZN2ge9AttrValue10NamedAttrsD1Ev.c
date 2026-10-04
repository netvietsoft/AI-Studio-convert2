// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3eea0
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3eea0 | Size: 72 bytes | SHA256: 159a18ef0f6c5ce48c4691be02478b77dd38ed7c24d9945b5f0ccb6818eaaeab
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4hiai12ProtoFactory19DestroyNamedAttrDefEPNS_13INamedAttrDefE, _ZN4hiai12ProtoFactory8InstanceEv

void _ZN2ge9AttrValue10NamedAttrsD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x3eea0 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x3eea4 */ adrp x8, #0xda000;
    /* 0x3eea8 */ mov x19, x0;
    /* 0x3eeac */ ldr x8, [x8, #0x3d0];
    /* 0x3eeb0 */ ldrb w9, [x0, #0x10];
    /* 0x3eeb4 */ add x8, x8, #0x10;
    /* 0x3eeb8 */ str x8, [x0];
    /* 0x3eebc */ cbz w9, #0x3eed4;
    /* 0x3eec0 */ ldr x8, [x19, #8];
    /* 0x3eec4 */ cbz x8, #0x3eed4;
    _ZN4hiai12ProtoFactory8InstanceEv();
    _ZN4hiai12ProtoFactory19DestroyNamedAttrDefEPNS_13INamedAttrDefE();
}
