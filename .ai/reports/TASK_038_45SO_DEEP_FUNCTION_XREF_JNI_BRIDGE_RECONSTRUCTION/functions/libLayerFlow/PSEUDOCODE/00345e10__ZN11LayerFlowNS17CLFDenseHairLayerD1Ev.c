// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345e10
// Recovered Name: _ZN11LayerFlowNS17CLFDenseHairLayerD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345e10 | Size: 60 bytes | SHA256: eadeeba18dcd436dd029a370daf157c72b2c2a2fa2d72d74d549575b5aa83b3d
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN11LayerFlowNS17CLFDenseHairLayerD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x345e10 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x345e14 */ str x19, [sp, #0x10];
    /* 0x345e18 */ mov x29, sp;
    /* 0x345e1c */ adrp x8, #0x54a000;
    /* 0x345e20 */ mov x19, x0;
    /* 0x345e24 */ ldr x8, [x8, #0xb70];
    /* 0x345e28 */ ldr x1, [x0, #0x4e0];
    /* 0x345e2c */ add x8, x8, #0x10;
    /* 0x345e30 */ str x8, [x0];
    /* 0x345e34 */ add x0, x0, #0x4d8;
    sub_33f2f0();
}
