// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x68760
// Recovered Name: sub_68760
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x68760 | Size: 84 bytes | SHA256: bdade74c70ba34582a68696e5ba7303c1c950581bcf846bf86a51715e0ec3e84
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: usleep

void sub_68760(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x68760 */ mov w8, #0x3e8;
    /* 0x68764 */ mul w0, w0, w8;
    /* 0x68768 */ b #0x132830;
    /* 0x6876c */ cbz x0, #0x6877c;
    /* 0x68770 */ ldr x8, [x0];
    /* 0x68774 */ ldr x3, [x8, #0x10];
    /* 0x68778 */ br x3;
    /* 0x6877c */ mov w0, #-1;
    return x0;
    /* 0x68784 */ cbz x0, #0x68794;
    /* 0x68788 */ ldr x8, [x0];
    return x0;
    return x0;
}
