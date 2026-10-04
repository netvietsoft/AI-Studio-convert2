// Library: libhiai.so
// Function ID: libhiai::0x265d4
// Recovered Name: sub_265d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x265d4 | Size: 272 bytes | SHA256: c9fb14a9e402cbf00b2d33b119b0c5d655478fdaf410975583e99f20d769df0b
// Callers: 1 | Callees: 4 | Imports: 5

// Calls external APIs: AI_Log_Print, _ZdlPv, _ZnwmRKSt9nothrow_t, __stack_chk_fail, __strrchr_chk
// Strings referenced:
//   "/srv/workspace/cann_ddk_ndkr27_0723/work_code/vendor/hisi/npu/src/framework/model_runtime/direct/direct_model_compatible_proxy.cpp"
//   "DirectModelCompatibleProxy"
//   "HIAI_DDK_MSG"
//   "libhiai_model_compatible.so"

void sub_265d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x265d4 */ sub sp, sp, #0x40;
    /* 0x265d8 */ stp x30, x21, [sp, #0x20];
    /* 0x265dc */ stp x20, x19, [sp, #0x30];
    /* 0x265e0 */ mrs x21, tpidr_el0;
    /* 0x265e4 */ adrp x1, #0x72000;
    /* 0x265e8 */ mov x19, x0;
    /* 0x265ec */ ldr x8, [x21, #0x28];
    /* 0x265f0 */ mov w0, #0x50;
    /* 0x265f4 */ str x8, [sp, #0x18];
    /* 0x265f8 */ ldr x1, [x1, #0xfe8];
    _ZnwmRKSt9nothrow_t();
    sub_4e5b0();
    sub_266e4();
    sub_4e600();
    _ZdlPv();
    sub_4e5dc();
    _ZdlPv();
    return x0;
    __strrchr_chk();
    __stack_chk_fail();
}
