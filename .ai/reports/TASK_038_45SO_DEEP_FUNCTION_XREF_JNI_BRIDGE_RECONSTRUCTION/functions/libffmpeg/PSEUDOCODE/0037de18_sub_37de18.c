// Library: libffmpeg.so
// Function ID: libffmpeg::0x37de18
// Recovered Name: sub_37de18
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37de18 | Size: 180 bytes | SHA256: fbe09a5e0505300a8101624dcfd181bc310b001c38ce37ede23c76eea3aaebed
// Callers: 0 | Callees: 7 | Imports: 2

// Calls external APIs: ff_cbs_write_simple_unsigned, ff_cbs_write_unsigned
// Strings referenced:
//   "cm_ref_layer_id[i]"
//   "colour_mapping_enabled_flag"
//   "min_spatial_segmentation_idc"
//   "num_cm_ref_layers_minus1"

void sub_37de18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    sub_39df08();
    /* 0x37de1c */ adrp x3, #0xb7000;
    /* 0x37de20 */ add x3, x3, #0x271;
    /* 0x37de24 */ b #0x37b858;
    /* 0x37de28 */ ldr x8, [sp, #0x18];
    /* 0x37de2c */ adrp x3, #0xbf000;
    /* 0x37de30 */ add x3, x3, #0x7e;
    sub_39dee0();
    /* 0x37de38 */ ldrb w4, [x8, #0x22];
    ff_cbs_write_simple_unsigned();
    /* 0x37de40 */ tbnz w0, #0x1f, #0x37e80c;
    sub_39dfa4();
    sub_389770();
    sub_3a1160();
    sub_3a0afc();
    ff_cbs_write_unsigned();
    sub_39e558();
}
