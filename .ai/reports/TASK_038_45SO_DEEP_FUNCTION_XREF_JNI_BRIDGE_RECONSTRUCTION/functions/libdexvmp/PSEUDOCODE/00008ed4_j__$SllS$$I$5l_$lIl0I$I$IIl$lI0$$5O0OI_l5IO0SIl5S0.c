// Library: libdexvmp.so
// Function ID: libdexvmp::0x8ed4
// Recovered Name: j__$SllS$$I$5l_$lIl0I$I$IIl$lI0$$5O0OI_l5IO0SIl5S0OS5$
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8ed4 | Size: 64 bytes | SHA256: 5191d877551371c5e40597e63fdb1f0267643fb3a6fd160c73e8efb59bc800b8
// Callers: 0 | Callees: 0 | Imports: 0


void j__$SllS$$I$5l_$lIl0I$I$IIl$lI0$$5O0OI_l5IO0SIl5S0OS5$(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8ed4 */ mov w8, #0x7e000000;
    /* 0x8ed8 */ cmp w0, w8;
    /* 0x8edc */ b.ls #0x8ee8;
    /* 0x8ee0 */ mov w0, wzr;
    return x0;
    /* 0x8ee8 */ sxtw x8, w0;
    /* 0x8eec */ mov x9, #-0x7f7f0001;
    /* 0x8ef0 */ movk x9, #0x8081;
    /* 0x8ef4 */ mul x8, x8, x9;
    /* 0x8ef8 */ lsr x8, x8, #0x20;
    /* 0x8efc */ add w8, w8, w0;
    return x0;
}
