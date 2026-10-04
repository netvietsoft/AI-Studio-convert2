// Function: MTFilterKernel::CMTXTDetailsFilter::drawWithBlurAndMask(unsigned int)
// RVA: 0x1331cc, Size: 888 bytes
int64_t _ZN14MTFilterKernel18CMTXTDetailsFilter19drawWithBlurAndMaskEj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm(...); // call internal at 0x1332a0
    memcpy(...); // call PLT API at 0x1332b4
    _ZdlPv(...); // call PLT API at 0x1332f4
    _Znwm(...); // call PLT API at 0x133300
    const char* str = "attribute vec4 position; attribute vec4 inputTextureCoordinate; varying vec2 texCoord; void main() { gl_Position = vec4(position";
    const char* str = "precision highp float; varying vec2 texCoord; uniform sampler2D inputImageTexture; uniform sampler2D inputImageMaskTexture; unif";
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_(...); // call internal at 0x133320
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x133334
    _ZdlPv(...); // call PLT API at 0x133350
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(...); // call internal at 0x133360
    glViewport(...); // call PLT API at 0x133370
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x133378
    const char* str = "texWidthOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1333bc
    const char* str = "texHeightOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1333dc
    const char* str = "mode";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1333f0
    glClearColor(...); // call PLT API at 0x133404
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x133428
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x13344c
    glActiveTexture(...); // call PLT API at 0x133454
    glBindTexture(...); // call PLT API at 0x133460
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x133474
    glActiveTexture(...); // call PLT API at 0x13347c
    glBindTexture(...); // call PLT API at 0x13348c
    const char* str = "inputImageMaskTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1334a0
    glActiveTexture(...); // call PLT API at 0x1334a8
    glBindTexture(...); // call PLT API at 0x1334b4
    const char* str = "blurImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1334c8
    glDrawArrays(...); // call PLT API at 0x1334d8
    glBindFramebuffer(...); // call PLT API at 0x1334e4
    return a0;
    _ZdlPv(...); // call PLT API at 0x133534
    sub_1B0544(...); // call internal at 0x13353c
    __stack_chk_fail(...); // call PLT API at 0x133540
}
