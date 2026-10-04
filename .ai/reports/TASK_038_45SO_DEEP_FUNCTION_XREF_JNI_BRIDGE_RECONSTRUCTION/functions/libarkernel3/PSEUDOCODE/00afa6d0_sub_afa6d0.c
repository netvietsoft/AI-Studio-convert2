// Library: libarkernel3.so
// Function ID: libarkernel3::0xafa6d0
// Recovered Name: sub_afa6d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xafa6d0 | Size: 2744 bytes | SHA256: 9a4b19620376dcf25cfc71f9c13200427d2f8005c723200b242cf8b258d53bfa
// Callers: 0 | Callees: 85 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Align"
//   "Animate"
//   "BackgroundColorConfig"
//   "BeginTimestamp"
//   "Blur"

void sub_afa6d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 686 instructions
    /* 0xafa6d0 */ stp x29, x30, [sp, #0x20];
    /* 0xafa6d4 */ stp x28, x27, [sp, #0x30];
    /* 0xafa6d8 */ stp x26, x25, [sp, #0x40];
    /* 0xafa6dc */ stp x24, x23, [sp, #0x50];
    /* 0xafa6e0 */ stp x22, x21, [sp, #0x60];
    /* 0xafa6e4 */ stp x20, x19, [sp, #0x70];
    /* 0xafa6e8 */ add x29, sp, #0x20;
    /* 0xafa6ec */ mrs x8, tpidr_el0;
    /* 0xafa6f0 */ mov x19, x0;
    /* 0xafa6f4 */ str x8, [sp, #8];
    /* 0xafa6f8 */ ldr x8, [x8, #0x28];
    sub_aee9ac();
    sub_afb188();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb258();
    sub_afb448();
    sub_afb65c();
    sub_afb758();
    sub_afb854();
    sub_afb950();
    sub_afb950();
    sub_afba4c();
    sub_afbb48();
    sub_afbc44();
    sub_afbd40();
    sub_a2d4dc();
    sub_a2d510();
    sub_afbe3c();
    sub_afc050();
    sub_afc14c();
    sub_afc248();
    sub_afc248();
    sub_afc248();
    sub_a2d4dc();
    sub_a2d510();
    sub_add9cc();
    sub_afc344();
    sub_afc558();
    sub_afc634();
    sub_afc634();
    sub_afc730();
    sub_afc82c();
    sub_afc928();
    sub_afca24();
    sub_afca24();
    sub_afc928();
    sub_afcb20();
    sub_afcc1c();
    sub_a2d4dc();
    sub_a2d510();
    sub_afcd14();
    sub_afcf28();
    sub_afd024();
    sub_afd100();
    sub_afd1fc();
    sub_afd2f8();
    sub_afd3f4();
    sub_afd100();
    sub_afd4f0();
    sub_afd100();
    sub_a2d4dc();
    sub_a2d4dc();
    sub_a2d510();
    sub_afd5ec();
    sub_afd800();
    sub_afd8fc();
    sub_afd8fc();
    sub_afd9f8();
    sub_afdaf4();
    sub_afdd08();
    sub_afde04();
    sub_afdf00();
    sub_afdffc();
    sub_afe0d8();
    sub_afe0d8();
    sub_afe0d8();
    sub_afe1d4();
    sub_afdd08();
    sub_afdf00();
    sub_afe2d0();
    sub_afe2d0();
    sub_a2d4dc();
    sub_a2d4dc();
    sub_a2d510();
    sub_afe3cc();
    sub_afe5e0();
    sub_afe6dc();
    sub_afe7d8();
    sub_afe8d4();
    sub_afe9d0();
    sub_afebe4();
    sub_afece0();
    sub_afeddc();
    sub_afeddc();
    sub_afeddc();
    sub_afeddc();
    sub_afeed8();
    sub_a2d4dc();
    sub_a2d510();
    sub_afefd4();
    sub_aff1e8();
    sub_aff2e4();
    sub_aff3e0();
    sub_aff4dc();
    sub_aff1e8();
    sub_aff5d8();
    sub_aff6d4();
    sub_aff7d0();
    sub_aff8cc();
    sub_aff8cc();
    sub_aff7d0();
    sub_aff7d0();
    sub_aff7d0();
    sub_aff9c8();
    sub_aff8cc();
    sub_aff8cc();
    sub_aff8cc();
    sub_aff8cc();
    sub_aff7d0();
    sub_affac4();
    sub_affac4();
    sub_affac4();
    sub_a2d510();
    sub_affbc0();
    sub_affdd4();
    sub_affed0();
    sub_afffcc();
    sub_b000d4();
    sub_b001d0();
    sub_b002cc();
    sub_b003c4();
    sub_b004bc();
    sub_b005b4();
    sub_b006ac();
    sub_b007a4();
    sub_b0089c();
    sub_b00994();
    sub_b00a8c();
    sub_b00b84();
    return x0;
    __stack_chk_fail();
}
