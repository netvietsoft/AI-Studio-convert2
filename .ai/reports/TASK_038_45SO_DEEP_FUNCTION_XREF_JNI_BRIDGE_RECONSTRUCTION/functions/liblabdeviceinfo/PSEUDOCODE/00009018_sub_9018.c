// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x9018
// Recovered Name: sub_9018
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9018 | Size: 152 bytes | SHA256: 4018d32d003fdfb47ba1fd53946c723916d37dbec0890bcc452a1df42390fbae
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_9018(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x9018 */ stp x29, x30, [sp, #0x100];
    /* 0x901c */ stp x28, x19, [sp, #0x110];
    /* 0x9020 */ add x29, sp, #0x100;
    /* 0x9024 */ stp x3, x4, [x29, #-0x78];
    /* 0x9028 */ sub x9, x29, #0x78;
    /* 0x902c */ mov x10, sp;
    /* 0x9030 */ stp x5, x6, [x29, #-0x68];
    /* 0x9034 */ add x10, x10, #0x80;
    /* 0x9038 */ sub x3, x29, #0x50;
    /* 0x903c */ stur x7, [x29, #-0x58];
    /* 0x9040 */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
