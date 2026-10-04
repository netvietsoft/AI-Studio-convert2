// Function: MTFilterKernel::CMTOldDynamicFilter::FilterToFBO(int, int, bool)
// RVA: 0x121408, Size: 668 bytes
int64_t _ZN14MTFilterKernel19CMTOldDynamicFilter11FilterToFBOEiib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter7BindFBOEii(...); // call internal at 0x12143c
    glClearColor(...); // call PLT API at 0x121454
    glClear(...); // call PLT API at 0x12145c
    glViewport(...); // call PLT API at 0x121474
    _ZN14MTFilterKernel18MTCalTexCoordTools18GetDisPlayTexCoodsENS_16FilterKernelRectEi(...); // call internal at 0x1214b0
    glUseProgram(...); // call PLT API at 0x1214c0
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0x1214fc
    glBindTexture(...); // call PLT API at 0x121508
    glUniform1i(...); // call PLT API at 0x12151c
    _ZN14MTFilterKernel19CMTOldDynamicFilter14changeFaceInfoEv(...); // call internal at 0x121524
    (*x8)(...);
    glUniform1f(...); // call PLT API at 0x121558
    glUniform1f(...); // call PLT API at 0x121568
    glUniform1i(...); // call PLT API at 0x12157c
    glUniform1i(...); // call PLT API at 0x121590
    glEnable(...); // call PLT API at 0x121598
    glBlendFunc(...); // call PLT API at 0x1215a4
    glEnableVertexAttribArray(...); // call PLT API at 0x1215ac
    glVertexAttribPointer(...); // call PLT API at 0x1215c8
    glEnableVertexAttribArray(...); // call PLT API at 0x1215d0
    glVertexAttribPointer(...); // call PLT API at 0x1215ec
    glEnableVertexAttribArray(...); // call PLT API at 0x1215f8
    glVertexAttribPointer(...); // call PLT API at 0x121614
    glDrawArrays(...); // call PLT API at 0x121624
    _ZdaPv(...); // call PLT API at 0x121630
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv(...); // call internal at 0x12163c
    glDisable(...); // call PLT API at 0x121644
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x121650
    const char* str = "FilterKernel";
    const char* str = "bin fbo fail";
    __android_log_print(...); // call PLT API at 0x121670
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1216a0
}
