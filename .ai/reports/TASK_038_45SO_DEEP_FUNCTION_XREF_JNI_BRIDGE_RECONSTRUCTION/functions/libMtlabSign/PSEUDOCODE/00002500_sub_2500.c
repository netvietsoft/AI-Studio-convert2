// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x2500
// Recovered Name: sub_2500
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2500 | Size: 24 bytes | SHA256: b73ab58b6a3cd5f19af75b1e75682efabfd5b694c389889f8368081ef0e23621
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk122__libcpp_verbose_abortEPKcz
// Strings referenced:
//   "length_error was thrown in -fno-exceptions mode with message "%s""

void sub_2500(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2500 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2504 */ mov x29, sp;
    /* 0x2508 */ mov x1, x0;
    /* 0x250c */ adrp x0, #0x1000;
    /* 0x2510 */ add x0, x0, #0x58b;
    _ZNSt6__ndk122__libcpp_verbose_abortEPKcz();
}
