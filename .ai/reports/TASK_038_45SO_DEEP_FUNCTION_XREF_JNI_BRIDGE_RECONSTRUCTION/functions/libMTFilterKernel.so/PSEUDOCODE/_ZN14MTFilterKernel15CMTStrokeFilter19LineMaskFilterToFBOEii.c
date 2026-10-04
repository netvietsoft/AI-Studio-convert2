// Function: MTFilterKernel::CMTStrokeFilter::LineMaskFilterToFBO(int, int)
// RVA: 0x135dc4, Size: 872 bytes
int64_t _ZN14MTFilterKernel15CMTStrokeFilter19LineMaskFilterToFBOEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(...); // call internal at 0x135e20
    return a0;
    glDeleteTextures(...); // call PLT API at 0x135e68
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii(...); // call internal at 0x135e78
    glGenFramebuffers(...); // call PLT API at 0x135e88
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEjj(...); // call internal at 0x135e9c
    glClearColor(...); // call PLT API at 0x135eb4
    glClear(...); // call PLT API at 0x135ebc
    glViewport(...); // call PLT API at 0x135ed0
    glEnable(...); // call PLT API at 0x135ed8
    glBlendFunc(...); // call PLT API at 0x135ee4
    glUseProgram(...); // call PLT API at 0x135eec
    glUniform1i(...); // call PLT API at 0x135ef8
    (*x8)(...);
    glUniform3f(...); // call PLT API at 0x135f1c
    glEnableVertexAttribArray(...); // call PLT API at 0x135f44
    glVertexAttribPointer(...); // call PLT API at 0x135f60
    _ZN14MTFilterKernel15setOrthoFrustumEffffff(...); // call internal at 0x135f84
    glUniformMatrix4fv(...); // call PLT API at 0x135fd8
    glEnableVertexAttribArray(...); // call PLT API at 0x136074
    glVertexAttribPointer(...); // call PLT API at 0x136090
    glDrawArrays(...); // call PLT API at 0x1360a0
    glDisable(...); // call PLT API at 0x136114
    __stack_chk_fail(...); // call PLT API at 0x136128
}
