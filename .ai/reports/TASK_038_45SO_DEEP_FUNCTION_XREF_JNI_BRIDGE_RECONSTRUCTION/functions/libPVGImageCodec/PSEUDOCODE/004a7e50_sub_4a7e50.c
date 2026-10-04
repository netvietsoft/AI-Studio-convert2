// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x4a7e50
// Recovered Name: sub_4a7e50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x4a7e50 | Size: 176 bytes | SHA256: eea662b60b115edc84cd3248e644b25c618e4261d0bee447bea8cda9d7cb6124
// Callers: 1 | Callees: 0 | Imports: 3

// Calls external APIs: _ZNSt6__ndk119__shared_weak_countD2Ev, _ZdaPv, _ZdlPv
// Strings referenced:
//   "NSt6__ndk114default_deleteIN22photos_editing_formats8image_io11DataSegmentEEE"

void sub_4a7e50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x4a7e50 */ cbz x1, #0x4a7e64;
    /* 0x4a7e54 */ ldr w8, [x1, #0x18];
    /* 0x4a7e58 */ cbz w8, #0x4a7e68;
    /* 0x4a7e5c */ mov x0, x1;
    /* 0x4a7e60 */ b #0x4c2ce0;
    return x0;
    /* 0x4a7e68 */ ldr x0, [x1, #0x10];
    /* 0x4a7e6c */ cbz x0, #0x4a7e5c;
    /* 0x4a7e70 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x4a7e74 */ mov x19, x1;
    _ZdaPv();
    _ZNSt6__ndk119__shared_weak_countD2Ev();
    return x0;
    _ZdaPv();
    return x0;
}
