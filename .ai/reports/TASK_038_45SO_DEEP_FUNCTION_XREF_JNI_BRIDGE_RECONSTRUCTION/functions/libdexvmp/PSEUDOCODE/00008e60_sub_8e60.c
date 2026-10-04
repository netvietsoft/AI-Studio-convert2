// Library: libdexvmp.so
// Function ID: libdexvmp::0x8e60
// Recovered Name: sub_8e60
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8e60 | Size: 108 bytes | SHA256: d813239add40eddf96c44af3bbf6771fe33b0826568ba725fcd3496b7ec19da3
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: j__$0_III$$0Il$$_$IOI$O$IIl$_IS_l$I550IO0OI$5IIOlIIS5$, j__$I050I$IIIII$$$5SI$50lO_$llIIS5OlI_II$l$SOIIIOI_S5$, j__$OIIII$lI50S$ll_O$$5l5$l$_I5II5l$I$OOIIIlI$$lIOIS5$
// Strings referenced:
//   "com/fort/andJni/JniLib1716343241"

void sub_8e60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x8e60 */ stp x29, x30, [sp, #0x10];
    /* 0x8e64 */ add x29, sp, #0x10;
    /* 0x8e68 */ sub sp, sp, #0x10;
    /* 0x8e6c */ str xzr, [sp, #8];
    /* 0x8e70 */ ldr x8, [x0];
    /* 0x8e74 */ ldr x8, [x8, #0x30];
    /* 0x8e78 */ mov w19, #0x10000;
    /* 0x8e7c */ movk w19, #4;
    /* 0x8e80 */ add x1, sp, #8;
    /* 0x8e84 */ mov w2, #0x10000;
    /* 0x8e88 */ movk w2, #4;
    j__$OIIII$lI50S$ll_O$$5l5$l$_I5II5l$I$OOIIIlI$$lIOIS5$();
    j__$I050I$IIIII$$$5SI$50lO_$llIIS5OlI_II$l$SOIIIOI_S5$();
    j__$0_III$$0Il$$_$IOI$O$IIl$_IS_l$I550IO0OI$5IIOlIIS5$();
    return x0;
}
