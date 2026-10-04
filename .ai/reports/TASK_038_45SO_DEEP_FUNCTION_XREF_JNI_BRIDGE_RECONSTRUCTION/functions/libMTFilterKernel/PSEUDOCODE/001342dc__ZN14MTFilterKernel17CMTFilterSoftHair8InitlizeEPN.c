// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1342dc
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair8InitlizeEPNS_18DynamicFilterParamEPKc
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1342dc | Size: 524 bytes | SHA256: abf6d58228d77c230f6e20f2f2529882e8a88458227cb413c7fa0575380a0ce2
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }"

void _ZN14MTFilterKernel17CMTFilterSoftHair8InitlizeEPNS_18DynamicFilterParamEPKc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 131 instructions
    /* 0x1342dc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1342e0 */ str x21, [sp, #0x10];
    /* 0x1342e4 */ stp x20, x19, [sp, #0x20];
    /* 0x1342e8 */ mov x29, sp;
    /* 0x1342ec */ ldr x20, [x0, #0x90];
    /* 0x1342f0 */ mov x19, x0;
    /* 0x1342f4 */ mov x21, x1;
    /* 0x1342f8 */ cbz x20, #0x13430c;
    /* 0x1342fc */ mov x0, x20;
    _ZN14MTFilterKernel18DynamicFilterParamD2Ev();
    /* 0x134304 */ mov x0, x20;
    _ZdlPv();
    _Znwm();
    _ZN14MTFilterKernel18DynamicFilterParamC2EPS0_();
    sub_ef55c();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    _Znwm();
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_();
    return x0;
    _ZdlPv();
    sub_1b0544();
    _ZdlPv();
    sub_1b0544();
    _ZdlPv();
    sub_1b0544();
    _ZdlPv();
    sub_1b0544();
    _ZdlPv();
    sub_1b0544();
    _ZdlPv();
    sub_1b0544();
}
