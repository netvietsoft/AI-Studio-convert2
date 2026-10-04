// Library: libbytehook.so
// Function ID: libbytehook::0x92f0
// Recovered Name: sub_92f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x92f0 | Size: 28 bytes | SHA256: e993348c210a81ab22a9b371d3886a7061c0b6aaa1a5e95efa928a20a10f2588
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeGetMode()I (table at 0x117f0)
// Calls external APIs: bytehook_get_mode

jlong sub_92f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92f4 */ mov x29, sp;
    bytehook_get_mode();
    /* 0x92fc */ cmp w0, #0;
    /* 0x9300 */ cset w0, ne;
    /* 0x9304 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
