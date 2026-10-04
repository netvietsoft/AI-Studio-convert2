// Function: MTFilterKernel::GPUImageFramebuffer::byteBuffer()
// RVA: 0x164638, Size: 236 bytes
int64_t _ZN14MTFilterKernel19GPUImageFramebuffer10byteBufferEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call PLT API at 0x164664
    glGetIntegerv(...); // call PLT API at 0x164670
    glBindFramebuffer(...); // call PLT API at 0x16467c
    glViewport(...); // call PLT API at 0x164694
    _Znam(...); // call PLT API at 0x1646b8
    glReadPixels(...); // call PLT API at 0x1646dc
    glBindFramebuffer(...); // call PLT API at 0x1646e8
    glViewport(...); // call PLT API at 0x1646f4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x164720
}
