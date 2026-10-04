// Library: libkoom-strip-dump.so
// Function ID: libkoom-strip-dump::0x37da8
// Recovered Name: sub_37da8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37da8 | Size: 788 bytes | SHA256: 6c35a71320faed14eacd62de38d1e16e820363c646043c54030e735b7d62de36
// Callers: 0 | Callees: 7 | Imports: 7

// Calls external APIs: _ZN4kwai6linker5DlFcn6dlopenEPKci, _ZN4kwai6linker5DlFcn7dlcloseEPv, _ZNSt6__ndk110unique_ptrIA_cNS_14default_deleteIS1_EEE5resetB8ne180000IPcTnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvS8_, _Znam, __errno, __stack_chk_fail, async_safe_format_log
// Strings referenced:
//   "/builds/MtAnalytics-Android/mtappcia/mtmcollector/src/main/cpp/koom/src/hprof_dump.cpp"
//   "CHECK failed at %s (line: %d) - <%s>: %s: %s"
//   "HprofDump"
//   "Initialize"
//   "_ZN3art16ScopedSuspendAllC1EPKcb"

void sub_37da8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 197 instructions
    /* 0x37da8 */ stp x29, x30, [sp, #0x10];
    /* 0x37dac */ str x21, [sp, #0x20];
    /* 0x37db0 */ stp x20, x19, [sp, #0x30];
    /* 0x37db4 */ add x29, sp, #0x10;
    sub_38370();
    /* 0x37dbc */ cbnz w8, #0x3809c;
    /* 0x37dc0 */ ldr w8, [x0, #4];
    /* 0x37dc4 */ mov x20, x0;
    /* 0x37dc8 */ cmp w8, #0x15;
    /* 0x37dcc */ b.lt #0x3809c;
    /* 0x37dd0 */ nop ;
    _ZN4kwai6linker5DlFcn6dlopenEPKci();
    sub_38320();
    sub_38320();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_38348();
    _Znam();
    sub_38358();
    _ZNSt6__ndk110unique_ptrIA_cNS_14default_deleteIS1_EEE5resetB8ne180000IPcTnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvS8_();
    sub_37d9c();
    _Znam();
    sub_38358();
    _ZNSt6__ndk110unique_ptrIA_cNS_14default_deleteIS1_EEE5resetB8ne180000IPcTnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvS8_();
    sub_37d9c();
    sub_38320();
    sub_38320();
    sub_38320();
    sub_38320();
    sub_38320();
    sub_38320();
    sub_38320();
    _ZN4kwai6linker5DlFcn7dlcloseEPv();
    __errno();
    sub_38318();
    sub_382f0();
    async_safe_format_log();
    sub_38348();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    __errno();
    sub_38318();
    sub_382f0();
    async_safe_format_log();
    _ZN4kwai6linker5DlFcn7dlcloseEPv();
    sub_38348();
    return x0;
    __stack_chk_fail();
}
