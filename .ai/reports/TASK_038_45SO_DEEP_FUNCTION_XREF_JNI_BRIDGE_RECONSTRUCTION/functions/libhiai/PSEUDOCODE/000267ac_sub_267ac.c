// Library: libhiai.so
// Function ID: libhiai::0x267ac
// Recovered Name: sub_267ac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x267ac | Size: 68 bytes | SHA256: bca738dec3f0aeb68590c4b69f7c5d2c3c52c5fa19872f101b4f33b0fb141dde
// Callers: 1 | Callees: 1 | Imports: 0


void sub_267ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x267ac */ str x30, [sp, #-0x20]!;
    /* 0x267b0 */ stp x20, x19, [sp, #0x10];
    /* 0x267b4 */ mov x19, x0;
    sub_26568();
    /* 0x267bc */ adrp x20, #0x78000;
    /* 0x267c0 */ ldr x8, [x20, #0x7f0];
    /* 0x267c4 */ cbz x8, #0x267e0;
    sub_26568();
    /* 0x267cc */ ldr x0, [x20, #0x7f0];
    /* 0x267d0 */ mov x1, x19;
    /* 0x267d4 */ ldp x20, x19, [sp, #0x10];
    return x0;
}
