// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa59704
// Recovered Name: sub_a59704
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa59704 | Size: 592 bytes | SHA256: d581f19e4b484d24882ff723718a867f0e6352e46db5b6e93a92ed0aee12685c
// Callers: 1 | Callees: 5 | Imports: 0

// Strings referenced:
//   "FabbyMaskType"
//   "FollowToGesture"
//   "HandDepthFactor"
//   "HandTransFactor"
//   "IsNeedBodySegment"

void sub_a59704(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 148 instructions
    /* 0xa59704 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xa59708 */ str x21, [sp, #0x10];
    /* 0xa5970c */ stp x20, x19, [sp, #0x20];
    /* 0xa59710 */ mov x29, sp;
    /* 0xa59714 */ mov x20, x1;
    /* 0xa59718 */ mov x19, x0;
    sub_61bfa0();
    /* 0xa59720 */ tbz w0, #0, #0xa598dc;
    /* 0xa59724 */ add x1, x19, #0x928;
    /* 0xa59728 */ mov x0, x20;
    sub_baa8e4();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8da0();
    sub_5a8de8();
    sub_5a8d1c();
    return x0;
}
