// Library: libarkernel3.so
// Function ID: libarkernel3::0x55ef5c
// Recovered Name: sub_55ef5c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55ef5c | Size: 172 bytes | SHA256: 78970a58489dba3a3c6150986d2aee7e7dc8b908b28ff562efe56765110b2db3
// Callers: 0 | Callees: 3 | Imports: 0


void sub_55ef5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x55ef5c */ stp x29, x30, [sp, #0x20];
    /* 0x55ef60 */ stp x24, x23, [sp, #0x30];
    /* 0x55ef64 */ stp x22, x21, [sp, #0x40];
    /* 0x55ef68 */ stp x20, x19, [sp, #0x50];
    /* 0x55ef6c */ add x29, sp, #0x20;
    /* 0x55ef70 */ mov x23, x0;
    /* 0x55ef74 */ mov x0, x3;
    /* 0x55ef78 */ mov w19, w4;
    /* 0x55ef7c */ fmov s8, s3;
    /* 0x55ef80 */ fmov s9, s2;
    /* 0x55ef84 */ fmov s10, s1;
    sub_56a46c();
    sub_56a448();
    sub_55f008();
    sub_56a46c();
    return x0;
}
