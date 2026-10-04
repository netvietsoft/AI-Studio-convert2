// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc37ea8
// Recovered Name: sub_c37ea8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc37ea8 | Size: 1672 bytes | SHA256: 6d131f77ea1a37d3edc9e1954cf19e8d39f20de1ecb89f857cc9b583bb454f3e
// Callers: 0 | Callees: 24 | Imports: 4

// Calls external APIs: _ZdaPv, _ZdlPv, _Znam, __android_log_print
// Strings referenced:
//   "GetSegmentMask == NULL"
//   "arkernel"

void sub_c37ea8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 418 instructions
    /* 0xc37ea8 */ stp x29, x30, [sp, #0x30];
    /* 0xc37eac */ stp x28, x27, [sp, #0x40];
    /* 0xc37eb0 */ stp x26, x25, [sp, #0x50];
    /* 0xc37eb4 */ stp x24, x23, [sp, #0x60];
    /* 0xc37eb8 */ stp x22, x21, [sp, #0x70];
    /* 0xc37ebc */ stp x20, x19, [sp, #0x80];
    /* 0xc37ec0 */ add x29, sp, #0x30;
    /* 0xc37ec4 */ sub sp, sp, #0x5e0;
    /* 0xc37ec8 */ stp q1, q0, [sp, #0x30];
    /* 0xc37ecc */ mrs x28, tpidr_el0;
    /* 0xc37ed0 */ mov w21, w3;
    sub_c38b3c();
    sub_69add8();
    sub_c14f88();
    _ZdaPv();
    sub_c396e4();
    sub_c39778();
    sub_5a6b20();
    sub_69b7cc();
    sub_69b7d4();
    sub_c41220();
    sub_69b7cc();
    sub_69b7d4();
    sub_69c424();
    sub_c3cd6c();
    sub_69c64c();
    sub_69b7cc();
    sub_69b7d4();
    sub_69d6f0();
    sub_69c9d8();
    sub_69daa4();
    sub_69d9c8();
    sub_69d704();
    sub_69da84();
    sub_69c4e8();
    sub_69b7cc();
    sub_69b7d4();
    __android_log_print();
    sub_c41220();
    sub_69c424();
    sub_c3cd6c();
    sub_69c64c();
    sub_69d6f0();
    sub_69c9d8();
    sub_69daa4();
    sub_69d9c8();
    sub_69d704();
    sub_69da84();
    sub_69c4e8();
    sub_69b7cc();
    sub_69b7d4();
    sub_69b7cc();
    sub_69b7d4();
    _ZdaPv();
    _Znam();
    sub_c3afa8();
    sub_c38d54();
    sub_89914c();
    sub_c39610();
    sub_763a3c();
    _ZdlPv();
}
