// Library: libarkernel3.so
// Function ID: libarkernel3::0xa547f0
// Recovered Name: sub_a547f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa547f0 | Size: 320 bytes | SHA256: 2df3399f2a27c90facb2eec1a5060d38936bbee4be61f3c7353c8df3f4707e80
// Callers: 1 | Callees: 6 | Imports: 10

// Calls external APIs: vldp_get_instance_seg_has_seg_rect, vldp_get_instance_seg_has_seg_rect_score, vldp_get_instance_seg_has_seg_tag, vldp_get_instance_seg_seg_mask_image, vldp_get_instance_seg_seg_mask_texture, vldp_get_instance_seg_seg_rect, vldp_get_instance_seg_seg_rect_score, vldp_get_instance_seg_seg_tag, vldp_image_valid, vldp_texture_valid
// Strings referenced:
//   "instance_segment"

void sub_a547f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 80 instructions
    /* 0xa547f0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xa547f4 */ str x23, [sp, #0x10];
    /* 0xa547f8 */ stp x22, x21, [sp, #0x20];
    /* 0xa547fc */ stp x20, x19, [sp, #0x30];
    /* 0xa54800 */ mov x29, sp;
    /* 0xa54804 */ mov x20, x0;
    /* 0xa54808 */ mov x0, x2;
    /* 0xa5480c */ mov x21, x2;
    /* 0xa54810 */ mov x19, x1;
    vldp_get_instance_seg_has_seg_rect();
    /* 0xa54818 */ tbz w0, #0, #0xa54834;
    vldp_get_instance_seg_seg_rect();
    vldp_get_instance_seg_has_seg_rect_score();
    vldp_get_instance_seg_seg_rect_score();
    vldp_get_instance_seg_has_seg_tag();
    vldp_get_instance_seg_seg_tag();
    vldp_get_instance_seg_seg_mask_texture();
    vldp_get_instance_seg_seg_mask_image();
    sub_a7fc40();
    sub_a81778();
    sub_a7fc40();
    sub_a821f8();
    vldp_texture_valid();
    sub_a5445c();
    sub_a596b4();
    vldp_image_valid();
    sub_a5445c();
    sub_a59934();
    return x0;
}
