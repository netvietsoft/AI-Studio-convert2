// Library: libarkernel3.so
// Function ID: libarkernel3::0x886c70
// Recovered Name: sub_886c70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x886c70 | Size: 2352 bytes | SHA256: 7db321bed11fe6aa636e5ce45ad96fe2bf5b059ebefa34ba3a3988ed22ff1036
// Callers: 0 | Callees: 51 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "FaceReconstructorResult is nullptr!"
//   "Mesh vertex or indices data is nullptr for face id %d!"
//   "MeshReconstructData is nullptr for face id %d!"
//   "a_position"
//   "a_texcoord"

void sub_886c70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 588 instructions
    /* 0x886c70 */ mov w0, #2;
    /* 0x886c74 */ add sp, sp, #0x1e0;
    /* 0x886c78 */ ldp x20, x19, [sp, #0x60];
    /* 0x886c7c */ ldp x22, x21, [sp, #0x50];
    /* 0x886c80 */ ldp x24, x23, [sp, #0x40];
    /* 0x886c84 */ ldp x26, x25, [sp, #0x30];
    /* 0x886c88 */ ldp x28, x27, [sp, #0x20];
    /* 0x886c8c */ ldp x29, x30, [sp, #0x10];
    /* 0x886c90 */ ldr d8, [sp], #0x70;
    /* 0x886c94 */ b #0xcccfe0;
    /* 0x886c98 */ ldr x8, [x28, #0x28];
    sub_a5000c();
    sub_a429dc();
    sub_a429f0();
    sub_a42088();
    sub_a434b4();
    sub_a434b4();
    sub_a42080();
    sub_a429c4();
    sub_8882a0();
    sub_a434b4();
    sub_66f754();
    sub_a417b8();
    sub_aa29c8();
    sub_a41e9c();
    sub_a41ecc();
    sub_a8ad80();
    sub_aa29c8();
    sub_a41ea4();
    sub_a41ecc();
    sub_a8ad80();
    sub_aa29c8();
    sub_a42078();
    sub_a42080();
    sub_a8b058();
    sub_a7fc40();
    sub_a82238();
    sub_8867ec();
    sub_a03b18();
    sub_a03b20();
    sub_a03b28();
    sub_5604d4();
    _Znwm();
    sub_66a110();
    sub_a0392c();
    sub_5604d4();
    _Znwm();
    sub_66a110();
    sub_a0392c();
    sub_a03b00();
    sub_a69d40();
    sub_a69d40();
    sub_8875a0();
    sub_751824();
    sub_751824();
    sub_a59cac();
    sub_668cb4();
    sub_a6e7f4();
    sub_668cb4();
    sub_a6e7f4();
    sub_668cb4();
    sub_a434b4();
    sub_911258();
    sub_668cb4();
    sub_66a274();
    _ZdlPv();
    sub_66a274();
    _ZdlPv();
    sub_763f0c();
    sub_7655f8();
    sub_763f0c();
    sub_763f0c();
    sub_a59cc4();
    sub_a7fc40();
    sub_a82210();
    sub_a7fc40();
    sub_a59d1c();
    sub_a59d24();
    sub_5edc30();
    sub_9fdf90();
    sub_a59cf4();
    sub_a0426c();
    sub_a03b30();
    sub_a5a194();
    sub_a59d2c();
    sub_5ee85c();
    _ZdlPv();
    return x0;
    sub_a434b4();
    sub_562d14();
    sub_5ee85c();
    sub_66a274();
    _ZdlPv();
    sub_66a274();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
