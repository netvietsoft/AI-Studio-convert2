// Library: libhiai.so
// Function ID: libhiai::0x26810
// Recovered Name: sub_26810
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x26810 | Size: 384 bytes | SHA256: 23b47f6d2ab45cfd92be73813b5492a8fdbfa2173461cd3cd3f7b55cf268efd4
// Callers: 1 | Callees: 2 | Imports: 10

// Calls external APIs: AI_Log_Print, HIAI_MR_ModelBuildOptions_GetFormatModeOption, HIAI_MR_ModelBuildOptions_GetTuningConfig, HIAI_MR_TuningConfig_GetTuningMode, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZdlPv, _ZnamRKSt9nothrow_t, __stack_chk_fail, __strrchr_chk, memset
// Strings referenced:
//   "/srv/workspace/cann_ddk_ndkr27_0723/work_code/vendor/hisi/npu/src/framework/model_runtime/direct/direct_model_builder.cpp"
//   "AI_INFRA"
//   "CreateOptionBuffer"
//   "tuningMode=auto;"
//   "useOriginFormat=true;"

void sub_26810(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 96 instructions
    /* 0x26810 */ sub sp, sp, #0x50;
    /* 0x26814 */ str x30, [sp, #0x20];
    /* 0x26818 */ stp x22, x21, [sp, #0x30];
    /* 0x2681c */ stp x20, x19, [sp, #0x40];
    /* 0x26820 */ mrs x21, tpidr_el0;
    /* 0x26824 */ mov x19, x0;
    /* 0x26828 */ adrp x1, #0x16000;
    /* 0x2682c */ add x1, x1, #0x4a2;
    /* 0x26830 */ ldr x8, [x21, #0x28];
    /* 0x26834 */ mov x0, sp;
    /* 0x26838 */ str x8, [sp, #0x18];
    sub_266e4();
    HIAI_MR_ModelBuildOptions_GetFormatModeOption();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    HIAI_MR_ModelBuildOptions_GetTuningConfig();
    HIAI_MR_TuningConfig_GetTuningMode();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZnamRKSt9nothrow_t();
    memset();
    sub_6af3c();
    _ZdlPv();
    return x0;
    __strrchr_chk();
    AI_Log_Print();
    __stack_chk_fail();
}
