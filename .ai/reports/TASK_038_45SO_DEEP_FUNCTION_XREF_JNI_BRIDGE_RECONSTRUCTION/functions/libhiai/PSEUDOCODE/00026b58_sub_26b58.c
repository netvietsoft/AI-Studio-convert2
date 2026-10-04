// Library: libhiai.so
// Function ID: libhiai::0x26b58
// Recovered Name: sub_26b58
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x26b58 | Size: 1164 bytes | SHA256: 6614b79e075090e804070051df392258761a71e91eafd44f6619feb1c260039f
// Callers: 0 | Callees: 11 | Imports: 8

// Calls external APIs: AI_Log_Print, _ZN4hiai17CreateLocalBufferEPvmb, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _ZnwmRKSt9nothrow_t, __stack_chk_fail, __strrchr_chk, malloc
// Strings referenced:
//   "%s %s(%d)::"Build model failed.""
//   "%s %s(%d)::"compatibleBuffer" "null, return FAIL.""
//   "%s %s(%d)::"model type %d unsupport origin format""
//   "%s %s(%d)::"outputBuffer" "null, return FAIL.""
//   "%s %s(%d)::"outputData" "null, return FAIL.""

void sub_26b58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 291 instructions
    /* 0x26b58 */ ldr x8, [x26, #0x28];
    /* 0x26b5c */ ldr x9, [sp, #0xf8];
    /* 0x26b60 */ cmp x8, x9;
    /* 0x26b64 */ b.ne #0x26fe0;
    /* 0x26b68 */ mov w0, w20;
    /* 0x26b6c */ ldp x20, x19, [sp, #0x140];
    /* 0x26b70 */ ldp x22, x21, [sp, #0x130];
    /* 0x26b74 */ ldp x24, x23, [sp, #0x120];
    /* 0x26b78 */ ldp x26, x25, [sp, #0x110];
    /* 0x26b7c */ ldp x29, x30, [sp, #0x100];
    /* 0x26b80 */ add sp, sp, #0x150;
    return x0;
    sub_2b668();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    sub_26fe4();
    sub_2b4e0();
    malloc();
    _ZN4hiai17CreateLocalBufferEPvmb();
    sub_2705c();
    sub_273cc();
    _ZnwmRKSt9nothrow_t();
    sub_266e4();
    sub_28388();
    _ZdlPv();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    __strrchr_chk();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    sub_274e4();
    sub_27524();
    sub_27564();
    sub_6bdb0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_6bdb0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    __stack_chk_fail();
}
