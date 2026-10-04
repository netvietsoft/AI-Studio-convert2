// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3ef30
// Recovered Name: _ZN2ge9AttrValue10NamedAttrsC1ERKS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x3ef30 | Size: 104 bytes | SHA256: 4b5091644fc392d3c6d1e02ca24100ccc21e5ec32ed2d04770aa8f0dcf886d48
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN4hiai12ProtoFactory18CreateNamedAttrDefEv, _ZN4hiai12ProtoFactory8InstanceEv

void _ZN2ge9AttrValue10NamedAttrsC1ERKS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x3ef30 */ str x30, [sp, #-0x20]!;
    /* 0x3ef34 */ stp x20, x19, [sp, #0x10];
    /* 0x3ef38 */ mov x19, x1;
    /* 0x3ef3c */ mov x20, x0;
    _ZN4hiai12ProtoFactory8InstanceEv();
    _ZN4hiai12ProtoFactory18CreateNamedAttrDefEv();
    /* 0x3ef48 */ adrp x8, #0xda000;
    /* 0x3ef4c */ mov w9, #1;
    /* 0x3ef50 */ ldr x8, [x8, #0x3d0];
    /* 0x3ef54 */ str xzr, [x20, #0x28];
    /* 0x3ef58 */ strb w9, [x20, #0x10];
    return x0;
}
