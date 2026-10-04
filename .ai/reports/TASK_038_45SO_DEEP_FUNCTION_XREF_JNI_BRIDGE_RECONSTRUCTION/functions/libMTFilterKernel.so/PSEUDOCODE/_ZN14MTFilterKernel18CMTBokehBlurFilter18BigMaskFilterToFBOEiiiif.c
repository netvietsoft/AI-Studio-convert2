// Function: MTFilterKernel::CMTBokehBlurFilter::BigMaskFilterToFBO(int, int, int, int, float)
// RVA: 0x122fa8, Size: 300 bytes
int64_t _ZN14MTFilterKernel18CMTBokehBlurFilter18BigMaskFilterToFBOEiiiif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindFramebuffer(...); // call PLT API at 0x122fd8
    glViewport(...); // call PLT API at 0x122fec
    glClear(...); // call PLT API at 0x122ff4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x122ffc
    const char* str = "textureWidth";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123010
    const char* str = "textureHeight";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123024
    const char* str = "radius";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x123038
    glActiveTexture(...); // call PLT API at 0x123040
    glBindTexture(...); // call PLT API at 0x12304c
    const char* str = "inputImageTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x123060
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x123088
    const char* str = "inputTextureCoordinate";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x1230b0
    glDrawArrays(...); // call PLT API at 0x1230d0
}
