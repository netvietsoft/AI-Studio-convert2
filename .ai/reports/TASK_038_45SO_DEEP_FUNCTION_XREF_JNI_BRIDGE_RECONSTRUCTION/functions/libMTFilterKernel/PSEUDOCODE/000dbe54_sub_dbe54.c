// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xdbe54
// Recovered Name: sub_dbe54
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xdbe54 | Size: 2316 bytes | SHA256: 2dd9c5923c9f83a59d5b9c6ac9eff5d38d602ff770e50c6e65008d1d8db7e8ac
// Callers: 0 | Callees: 7 | Imports: 6

// Calls external APIs: _ZdaPv, _ZdlPv, _Znwm, __stack_chk_fail, memmove, strlen
// Strings referenced:
//   "FocusFaculaBlur/faculaMask.png"
//   "FocusFaculaBlur/mask.png"
//   "Shaders/FocusFaculaBlur/MTFilter_FocusFaculaBlur.fs"
//   "Shaders/FocusFaculaBlur/MTFilter_FocusFaculaBlur.vs"
//   "Shaders/FocusFaculaBlur/MTFilter_GaussBlur.fs"

void sub_dbe54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 579 instructions
    /* 0xdbe54 */ stp x29, x30, [sp, #0x40];
    /* 0xdbe58 */ str x27, [sp, #0x50];
    /* 0xdbe5c */ stp x26, x25, [sp, #0x60];
    /* 0xdbe60 */ stp x24, x23, [sp, #0x70];
    /* 0xdbe64 */ stp x22, x21, [sp, #0x80];
    /* 0xdbe68 */ stp x20, x19, [sp, #0x90];
    /* 0xdbe6c */ add x29, sp, #0x40;
    /* 0xdbe70 */ mrs x27, tpidr_el0;
    /* 0xdbe74 */ mov x19, x1;
    /* 0xdbe78 */ mov x20, x0;
    /* 0xdbe7c */ ldr x8, [x27, #0x28];
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZN14MTFilterKernel15GPUImageProgram7IsValidEv();
    _ZdaPv();
    _ZdaPv();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    strlen();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZN14MTFilterKernel15GPUImageProgram7IsValidEv();
    _ZdaPv();
    _ZdaPv();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    strlen();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZN14MTFilterKernel15GPUImageProgram7IsValidEv();
    _ZdaPv();
    _ZdaPv();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    strlen();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel15GPUImageContext51programForVertexShaderStringAndFragmentShaderStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZN14MTFilterKernel15GPUImageProgram7IsValidEv();
    _ZdaPv();
    _ZdaPv();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils17file2ShaderStringEPKcRlb();
    _ZN14MTFilterKernel7GLUtils16LoadTexture_FileEPKcPiS3_iii();
    _ZN14MTFilterKernel7GLUtils16LoadTexture_FileEPKcPiS3_iii();
    strlen();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel12MTFilterBase4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_();
    _ZdaPv();
    _ZdaPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_1b0544();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
