// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x12252c
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilter8InitlizeEPNS_18DynamicFilterParamEPKc
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x12252c | Size: 548 bytes | SHA256: 4f2ffb05708ac40404c97f765a1bac8638e32b9a18b764d8718e7d5be5891b26
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "attribute vec4 position; attribute vec4 inputTextureCoordinate; varying highp vec2 textureCoordinate; void main() { gl_Position = position; textureCoordinate = inputTextureCoordinate.xy; }"
//   "uniform sampler2D inputImageTexture; varying highp vec2 textureCoordinate; void main() { highp vec4 color = texture2D(inputImageTexture, textureCoordinate); gl_FragColor = color; }"

void _ZN14MTFilterKernel18CMTBokehBlurFilter8InitlizeEPNS_18DynamicFilterParamEPKc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 137 instructions
    /* 0x12252c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x122530 */ str x21, [sp, #0x10];
    /* 0x122534 */ stp x20, x19, [sp, #0x20];
    /* 0x122538 */ mov x29, sp;
    /* 0x12253c */ ldr x20, [x0, #0x90];
    /* 0x122540 */ mov x19, x0;
    /* 0x122544 */ mov x21, x1;
    /* 0x122548 */ cbz x20, #0x12255c;
    /* 0x12254c */ mov x0, x20;
    _ZN14MTFilterKernel18DynamicFilterParamD2Ev();
    /* 0x122554 */ mov x0, x20;
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
