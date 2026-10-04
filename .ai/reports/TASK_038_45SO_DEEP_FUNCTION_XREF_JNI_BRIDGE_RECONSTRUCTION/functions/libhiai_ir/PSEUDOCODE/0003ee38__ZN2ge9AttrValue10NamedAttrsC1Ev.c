// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ee38
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ee38 | Size: 64 bytes | SHA256: 34efef2b5605af94487bee5a7b3ef54b1afc11f6b4a20203354c955582dc5027
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4hiai12ProtoFactory18CreateNamedAttrDefEv, _ZN4hiai12ProtoFactory8InstanceEv

void _ZN2ge9AttrValue10NamedAttrsC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x3ee38 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x3ee3c */ mov x19, x0;
    _ZN4hiai12ProtoFactory8InstanceEv();
    _ZN4hiai12ProtoFactory18CreateNamedAttrDefEv();
    /* 0x3ee48 */ adrp x8, #0xda000;
    /* 0x3ee4c */ mov w9, #1;
    /* 0x3ee50 */ ldr x8, [x8, #0x3d0];
    /* 0x3ee54 */ str xzr, [x19, #0x28];
    /* 0x3ee58 */ strb w9, [x19, #0x10];
    /* 0x3ee5c */ add x8, x8, #0x10;
    /* 0x3ee60 */ stp x8, x0, [x19];
    return x0;
}
