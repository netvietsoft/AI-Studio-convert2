// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x4b570
// Recovered Name: _ZN17MMDetectionPlugin13FaceConverter32initResultMTFaceBodyFromFaceBodyEP21vldp_face_body_handlePKNS_19FaceDetectionResult8FaceBodyE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x4b570 | Size: 520 bytes | SHA256: 2c7a01bd0ddedab4fa3e65ca563c5f377d3704e70d187deb3ef519eea75743b4
// Callers: 0 | Callees: 0 | Imports: 18

// Calls external APIs: vldp_create_float_array_pointer, vldp_create_point2f_array_pointer, vldp_get_face_body_body_point_score, vldp_get_face_body_body_points, vldp_get_float_array_pointer_ref, vldp_get_point2f_array_pointer_ref, vldp_release_float_array_pointer, vldp_release_point2f_array_pointer, vldp_set_face_body_body_id, vldp_set_face_body_body_rect, vldp_set_face_body_body_rect_roll, vldp_set_face_body_body_score, vldp_set_face_body_has_body_id, vldp_set_face_body_has_body_rect, vldp_set_face_body_has_body_rect_roll, vldp_set_face_body_has_body_score, vldp_set_float_array_pointer_hold, vldp_set_point2f_array_pointer_hold

void _ZN17MMDetectionPlugin13FaceConverter32initResultMTFaceBodyFromFaceBodyEP21vldp_face_body_handlePKNS_19FaceDetectionResult8FaceBodyE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x4b570 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x4b574 */ str x25, [sp, #0x10];
    /* 0x4b578 */ stp x24, x23, [sp, #0x20];
    /* 0x4b57c */ stp x22, x21, [sp, #0x30];
    /* 0x4b580 */ stp x20, x19, [sp, #0x40];
    /* 0x4b584 */ mov x29, sp;
    /* 0x4b588 */ cmp x0, #0;
    /* 0x4b58c */ ccmp x1, #0, #4, ne;
    /* 0x4b590 */ cset w19, ne;
    /* 0x4b594 */ b.eq #0x4b75c;
    /* 0x4b598 */ mov x21, x0;
    vldp_set_face_body_has_body_id();
    vldp_set_face_body_body_id();
    vldp_set_face_body_has_body_score();
    vldp_set_face_body_body_score();
    vldp_set_face_body_has_body_rect_roll();
    vldp_set_face_body_body_rect_roll();
    vldp_set_face_body_has_body_rect();
    vldp_set_face_body_body_rect();
    vldp_get_face_body_body_points();
    vldp_create_point2f_array_pointer();
    vldp_get_point2f_array_pointer_ref();
    vldp_set_point2f_array_pointer_hold();
    vldp_release_point2f_array_pointer();
    vldp_get_face_body_body_point_score();
    vldp_create_float_array_pointer();
    vldp_get_float_array_pointer_ref();
    vldp_set_float_array_pointer_hold();
    vldp_release_float_array_pointer();
    return x0;
}
