// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x6ba4
// Recovered Name: sub_6ba4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6ba4 | Size: 764 bytes | SHA256: 20e9f2bc1cd9cbab43fdd5f709bace7c6eaf28ef41013ff59c68b1640bf694d2
// Callers: 1 | Callees: 6 | Imports: 8

// Calls external APIs: AI_Log_Print, _ZN4hiai17CreateLocalBufferEPvmb, _ZNK2ge5Model7GetNameEv, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __stack_chk_fail, __strrchr_chk
// Strings referenced:
//   "%s %s(%d)::"build ir model successfully.""
//   "%s %s(%d)::"builtModel" "null, return FAIL.""
//   "%s %s(%d)::"model size limit: [209715200], now size is: %u""
//   "%s %s(%d)::"ret == hiai::SUCCESS && realSize > 0" "false, return %s.""
//   "/srv/workspace/cann_ddk_ndkr27_0723/work_code/vendor/hisi/npu/src/framework/model_builder/ir/build/hiai_ir_build.cpp"

void sub_6ba4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 191 instructions
    /* 0x6ba4 */ sub sp, sp, #0x160;
    /* 0x6ba8 */ str x29, [sp, #0x130];
    /* 0x6bac */ stp x30, x21, [sp, #0x140];
    /* 0x6bb0 */ stp x20, x19, [sp, #0x150];
    /* 0x6bb4 */ mrs x21, tpidr_el0;
    /* 0x6bb8 */ mov x0, x3;
    /* 0x6bbc */ mov x19, x2;
    /* 0x6bc0 */ ldr x8, [x21, #0x28];
    /* 0x6bc4 */ mov x20, x1;
    /* 0x6bc8 */ str x8, [sp, #0x128];
    /* 0x6bcc */ add x8, sp, #0x50;
    sub_84c8();
    sub_659c();
    _ZNK2ge5Model7GetNameEv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    sub_7f00();
    _ZN4hiai17CreateLocalBufferEPvmb();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    AI_Log_Print();
    sub_9a80();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_9a80();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_7340();
    _ZdlPv();
    sub_73b8();
    return x0;
    __stack_chk_fail();
}
