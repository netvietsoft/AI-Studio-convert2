// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58baac
// Recovered Name: sub_58baac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58baac | Size: 40 bytes | SHA256: 6515ca894909697ccefd855ce3ab3f513cb84a855f1788ea607b2bb5d6951ec7
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeCreateInstance()J (table at 0x10d0808)
// Calls external APIs: _Znwm

jlong sub_58baac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x58baac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x58bab0 */ mov x29, sp;
    /* 0x58bab4 */ mov w0, #0x38;
    _Znwm();
    /* 0x58babc */ movi v0.2d, #0000000000000000;
    /* 0x58bac0 */ stp q0, q0, [x0];
    /* 0x58bac4 */ str q0, [x0, #0x20];
    /* 0x58bac8 */ str xzr, [x0, #0x30];
    /* 0x58bacc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
