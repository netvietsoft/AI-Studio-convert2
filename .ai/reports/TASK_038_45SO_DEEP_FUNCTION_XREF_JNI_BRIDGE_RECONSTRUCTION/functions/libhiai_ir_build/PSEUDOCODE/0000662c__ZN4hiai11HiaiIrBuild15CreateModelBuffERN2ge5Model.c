// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x662c
// Recovered Name: _ZN4hiai11HiaiIrBuild15CreateModelBuffERN2ge5ModelERNS_15ModelBufferDataEj
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x662c | Size: 1364 bytes | SHA256: 36fafa14710c9b8a3c7a37f5bebb60860680319e32890e7325c59faf14a53b49
// Callers: 0 | Callees: 2 | Imports: 14

// Calls external APIs: AI_Log_Print, _ZN2ge6BufferC1Ev, _ZN2ge6BufferD1Ev, _ZNK2ge5Model4SaveERNS_6BufferE, _ZNK2ge6Buffer7GetSizeEv, _ZdlPv, __stack_chk_fail, __strrchr_chk, dlclose, dlerror, dlopen, dlsym, free, malloc
// Strings referenced:
//   "%s %s(%d)::"create model buffer failed. malloc fail!""
//   "%s %s(%d)::"create model buffer failed.""
//   "%s %s(%d)::"createMembuffer failed.""
//   "%s %s(%d)::"customSize limit: [209715200], now size is: %u""
//   "%s %s(%d)::"dlopen ai client failed.""

void _ZN4hiai11HiaiIrBuild15CreateModelBuffERN2ge5ModelERNS_15ModelBufferDataEj(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 341 instructions
    /* 0x662c */ sub sp, sp, #0xa0;
    /* 0x6630 */ stp x30, x25, [sp, #0x60];
    /* 0x6634 */ stp x24, x23, [sp, #0x70];
    /* 0x6638 */ stp x22, x21, [sp, #0x80];
    /* 0x663c */ stp x20, x19, [sp, #0x90];
    /* 0x6640 */ mrs x25, tpidr_el0;
    /* 0x6644 */ mov w9, #1;
    /* 0x6648 */ mov w21, w3;
    /* 0x664c */ ldr x8, [x25, #0x28];
    /* 0x6650 */ movk w9, #0xc80, lsl #16;
    /* 0x6654 */ cmp w3, w9;
    __strrchr_chk();
    AI_Log_Print();
    sub_74e4();
    dlopen();
    dlsym();
    dlerror();
    sub_659c();
    sub_659c();
    dlsym();
    _ZdlPv();
    __strrchr_chk();
    AI_Log_Print();
    dlsym();
    dlerror();
    _ZN2ge6BufferC1Ev();
    _ZNK2ge5Model4SaveERNS_6BufferE();
    malloc();
    _ZNK2ge6Buffer7GetSizeEv();
    free();
    _ZN2ge6BufferD1Ev();
    __strrchr_chk();
    AI_Log_Print();
    dlclose();
    __strrchr_chk();
    AI_Log_Print();
    _ZdlPv();
    return x0;
    __strrchr_chk();
    AI_Log_Print();
    AI_Log_Print();
    dlsym();
    dlerror();
    free();
    __strrchr_chk();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    AI_Log_Print();
    __strrchr_chk();
    __strrchr_chk();
    AI_Log_Print();
    free();
    _ZN2ge6BufferD1Ev();
    dlclose();
    _ZdlPv();
    __stack_chk_fail();
}
