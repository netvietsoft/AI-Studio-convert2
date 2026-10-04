// Library: libarkernel3.so
// Function ID: libarkernel3::0x56b9f8
// Recovered Name: sub_56b9f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x56b9f8 | Size: 3792 bytes | SHA256: 5f0f58b2927f432738ea0afd26a32e6ebef602c3693e402e3e9163900048f2cb
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "DataRequireKey::ARFaceMesh"
//   "DataRequireKey::ARGyroscopeQuaternion"
//   "DataRequireKey::ARInstantPlacement"
//   "DataRequireKey::ARLightEstimate"
//   "DataRequireKey::ARPlaneAnchor"

void sub_56b9f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 948 instructions
    /* 0x56b9f8 */ stp x29, x30, [sp, #0x20];
    /* 0x56b9fc */ stp x28, x27, [sp, #0x30];
    /* 0x56ba00 */ stp x26, x25, [sp, #0x40];
    /* 0x56ba04 */ stp x24, x23, [sp, #0x50];
    /* 0x56ba08 */ stp x22, x21, [sp, #0x60];
    /* 0x56ba0c */ stp x20, x19, [sp, #0x70];
    /* 0x56ba10 */ add x29, sp, #0x20;
    /* 0x56ba14 */ mrs x20, tpidr_el0;
    /* 0x56ba18 */ ldr x8, [x20, #0x28];
    /* 0x56ba1c */ stur x8, [x29, #-8];
    /* 0x56ba20 */ adrp x8, #0x10fd000;
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    sub_56cb94();
    return x0;
    __stack_chk_fail();
}
