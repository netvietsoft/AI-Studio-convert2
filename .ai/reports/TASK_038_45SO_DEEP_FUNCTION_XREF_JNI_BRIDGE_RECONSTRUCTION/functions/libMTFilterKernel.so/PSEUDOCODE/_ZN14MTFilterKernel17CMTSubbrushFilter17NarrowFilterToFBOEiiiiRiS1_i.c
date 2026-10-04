// Function: MTFilterKernel::CMTSubbrushFilter::NarrowFilterToFBO(int, int, int, int, int&, int&, int)
// RVA: 0x12b620, Size: 604 bytes
int64_t _ZN14MTFilterKernel17CMTSubbrushFilter17NarrowFilterToFBOEiiiiRiS1_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7bindFBOEiiRjS1_(...); // call internal at 0x12b678
    glViewport(...); // call PLT API at 0x12b694
    glClearColor(...); // call PLT API at 0x12b6a8
    glClear(...); // call PLT API at 0x12b6b0
    _ZN14MTFilterKernel10CGLProgram3UseEv(...); // call internal at 0x12b6b8
    const char* str = "projection";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12b6ec
    const char* str = "modelview";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(...); // call internal at 0x12b738
    const char* str = "texture";
    _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix3fvEPKcPKfbi(...); // call internal at 0x12b770
    glActiveTexture(...); // call PLT API at 0x12b778
    glBindTexture(...); // call PLT API at 0x12b784
    const char* str = "sourceTexture";
    _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(...); // call internal at 0x12b798
    const char* str = "position";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12b7f0
    const char* str = "texcoord";
    _ZN14MTFilterKernel10CGLProgram22SetVertexAttribPointerEPKcijhiPKv(...); // call internal at 0x12b818
    glDrawArrays(...); // call PLT API at 0x12b828
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12b834
    _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(...); // call internal at 0x12b840
    glBindFramebuffer(...); // call PLT API at 0x12b84c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x12b878
}
