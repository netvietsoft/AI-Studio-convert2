// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x6ea0
// Recovered Name: _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataERKNS_12BuildOptionsE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6ea0 | Size: 704 bytes | SHA256: f88997376ad9a300ddbe668d12bcca89203da971a243181e92bd79f879e70ec8
// Callers: 0 | Callees: 4 | Imports: 9

// Calls external APIs: AI_Log_Print, _ZN2ge10GraphUtils15GetComputeGraphERKNS_5GraphE, _ZN2ge9AttrUtils6SetIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKl, _ZN4hiai13IRTransformer21VerifyIrReservedFieldENSt6__ndk110shared_ptrIN2ge12ComputeGraphEEE, _ZNK2ge5Model8GetGraphEv, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __stack_chk_fail, __strrchr_chk
// Strings referenced:
//   "%s %s(%d)::"VerifyIRAPI(graph)" "false, return %s.""
//   "%s %s(%d)::"graph" "null, return FAIL.""
//   "%s %s(%d)::"hiai::IRTransformer::VerifyIrReservedField(graph)" "false, return %s.""
//   "/srv/workspace/cann_ddk_ndkr27_0723/work_code/vendor/hisi/npu/src/framework/model_builder/ir/build/hiai_ir_build.cpp"
//   "AI_INFRA"

void _ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataERKNS_12BuildOptionsE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 176 instructions
    /* 0x6ea0 */ sub sp, sp, #0x80;
    /* 0x6ea4 */ stp x30, x25, [sp, #0x40];
    /* 0x6ea8 */ stp x24, x23, [sp, #0x50];
    /* 0x6eac */ stp x22, x21, [sp, #0x60];
    /* 0x6eb0 */ stp x20, x19, [sp, #0x70];
    /* 0x6eb4 */ mrs x25, tpidr_el0;
    /* 0x6eb8 */ mov x21, x1;
    /* 0x6ebc */ add x0, sp, #0x20;
    /* 0x6ec0 */ ldr x8, [x25, #0x28];
    /* 0x6ec4 */ mov x19, x3;
    /* 0x6ec8 */ mov x20, x2;
    sub_659c();
    _ZN2ge9AttrUtils6SetIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKl();
    _ZdlPv();
    _ZNK2ge5Model8GetGraphEv();
    _ZN2ge10GraphUtils15GetComputeGraphERKNS_5GraphE();
    sub_9a80();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_9390();
    sub_9390();
    _ZN4hiai13IRTransformer21VerifyIrReservedFieldENSt6__ndk110shared_ptrIN2ge12ComputeGraphEEE();
    sub_9a80();
    __strrchr_chk();
    AI_Log_Print();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    __strrchr_chk();
    AI_Log_Print();
    sub_9a80();
    sub_6ba4();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    __strrchr_chk();
    AI_Log_Print();
    sub_9a80();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    __stack_chk_fail();
}
