// Function: MTFilterKernel::CMTXTDetailsFilter::blur(unsigned int, float, float)
// RVA: 0x132f84, Size: 584 bytes
int64_t _ZN14MTFilterKernel18CMTXTDetailsFilter4blurEjff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(...); // call internal at 0x132ff8
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x133010
    glGenFramebuffers(...); // call PLT API at 0x13302c
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(...); // call internal at 0x13303c
    _Znwm(...); // call PLT API at 0x13304c
    const char* str = "attribute vec4 position; attribute vec4 inputTextureCoordinate; uniform float texBlurWidthOffset; uniform float texBlurHeightOff";
    const char* str = "precision lowp float; uniform sampler2D srcImageTex; varying highp vec2 textureCoord; varying highp vec4 texBlurShift1; varying ";
    _ZN14MTFilterKernel10CGLProgramC1ENS_11ProgramTypeEPKcS3_S3_(...); // call internal at 0x13306c
    glViewport(...); // call PLT API at 0x133084
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x13308c
    const char* str = "texBlurWidthOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1330c0
    const char* str = "texBlurHeightOffset";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x1330d4
    glClearColor(...); // call PLT API at 0x1330e8
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x13310c
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x133130
    glActiveTexture(...); // call PLT API at 0x133138
    glBindTexture(...); // call PLT API at 0x133144
    const char* str = "srcImageTex";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x133158
    glDrawArrays(...); // call PLT API at 0x133168
    glBindFramebuffer(...); // call PLT API at 0x133174
    return a0;
    _ZdlPv(...); // call PLT API at 0x1331bc
    sub_1B0544(...); // call internal at 0x1331c4
    __stack_chk_fail(...); // call PLT API at 0x1331c8
}
