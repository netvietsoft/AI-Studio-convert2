// Function: MTFilterKernel::CMTGlitterBrushFilter::FilterToFBO(int, int, bool)
// RVA: 0x125c4c, Size: 1668 bytes
int64_t _ZN14MTFilterKernel21CMTGlitterBrushFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteFramebuffers(...); // call PLT API at 0x125cbc
    glDeleteTextures(...); // call PLT API at 0x125cd8
    glDeleteTextures(...); // call PLT API at 0x125cf4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm(...); // call internal at 0x125d84
    memcpy(...); // call PLT API at 0x125d9c
    _ZN14MTFilterKernel10CGLProgram12GetProgramIDEv(...); // call internal at 0x125da4
    glGetUniformLocation(...); // call PLT API at 0x125db8
    _Znwm(...); // call PLT API at 0x125e20
    _ZdlPv(...); // call PLT API at 0x125ec8
    _ZdlPv(...); // call PLT API at 0x125ee0
    const char* str = "white.png";
    _ZN14MTFilterKernel7GLUtils16LoadTexture_FileEPKcS2_PiS3_iii(...); // call internal at 0x125f54
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x125f60
    const char* str = "FilterKernel";
    const char* str = "[xiaoxw]--------- subbrushMaskTexture mask is null ----- m_Material:%p --  subbrushMaskTexture:%d";
    __android_log_print(...); // call PLT API at 0x125f88
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x125f98
    glViewport(...); // call PLT API at 0x125fb8
    glClearColor(...); // call PLT API at 0x125fcc
    glClear(...); // call PLT API at 0x125fd4
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x125fdc
    const char* str = "projection";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x126010
    const char* str = "modelview";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12605c
    const char* str = "averageFaceLuminance";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x126078
    const char* str = "averageLipsLuminance";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(...); // call internal at 0x126094
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0x1260ac
    glBindTexture(...); // call PLT API at 0x1260b8
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1260cc
    glActiveTexture(...); // call PLT API at 0x1260d4
    glBindTexture(...); // call PLT API at 0x1260e0
    const char* str = "glitterPatternTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x1260f4
    glActiveTexture(...); // call PLT API at 0x1260fc
    glBindTexture(...); // call PLT API at 0x126108
    const char* str = "maskTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12611c
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x126170
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x126194
    glDrawArrays(...); // call PLT API at 0x1261a4
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x1261b4
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1261c4
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x1261d4
    glUseProgram(...); // call PLT API at 0x1261dc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1261f4
    const char* str = "FilterKernel";
    const char* str = "BindFBO fail-->CMTGlitterBrushFilter::FilterToFBO";
    __android_log_print(...); // call PLT API at 0x126214
    return a0;
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x126254
    sub_EF718(...); // call internal at 0x12627c
    sub_C8A94(...); // call internal at 0x126294
    _ZdlPv(...); // call PLT API at 0x1262ac
    sub_1B0544(...); // call internal at 0x1262c8
    __stack_chk_fail(...); // call PLT API at 0x1262cc
}
