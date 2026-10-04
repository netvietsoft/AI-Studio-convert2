// Library: libhiai.so
// Function ID: libhiai::0x267fc
// Recovered Name: sub_267fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x267fc | Size: 20 bytes | SHA256: 05eb60a22754150df1d55294a75079f20ee47407c2b254d1cbeeb34b850d3ebf
// Callers: 29 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt6__ndk122__libcpp_verbose_abortEPKcz
// Strings referenced:
//   "length_error was thrown in -fno-exceptions mode with message "%s""

void sub_267fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x267fc */ str x30, [sp, #-0x10]!;
    /* 0x26800 */ mov x1, x0;
    /* 0x26804 */ adrp x0, #0x16000;
    /* 0x26808 */ add x0, x0, #0xf46;
    _ZNSt6__ndk122__libcpp_verbose_abortEPKcz();
}
