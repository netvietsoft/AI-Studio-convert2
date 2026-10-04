// Library: libffmpeg.so
// Function ID: libffmpeg::0x21226c
// Recovered Name: ff_msmpeg4_common_init
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x21226c | Size: 212 bytes | SHA256: ab252e7642fd79a52de6302037794e28937719baa153a0f3c44ae91e13f4b03e
// Callers: 0 | Callees: 1 | Imports: 4

// Calls external APIs: ff_init_scantable, ff_permute_scantable, ff_rl_init, pthread_once

void ff_msmpeg4_common_init(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x21226c */ str x30, [sp, #-0x20]!;
    /* 0x212270 */ stp x20, x19, [sp, #0x10];
    /* 0x212274 */ ldr w8, [x0, #0x18fc];
    /* 0x212278 */ mov x19, x0;
    /* 0x21227c */ sub w9, w8, #4;
    /* 0x212280 */ cmp w9, #2;
    /* 0x212284 */ b.hs #0x2122f8;
    /* 0x212288 */ nop ;
    /* 0x21228c */ adr x8, #0x12e51a;
    sub_2127cc();
    /* 0x212294 */ adrp x20, #0x10c000;
    ff_init_scantable();
    ff_init_scantable();
    ff_permute_scantable();
    ff_permute_scantable();
    sub_2127cc();
}
