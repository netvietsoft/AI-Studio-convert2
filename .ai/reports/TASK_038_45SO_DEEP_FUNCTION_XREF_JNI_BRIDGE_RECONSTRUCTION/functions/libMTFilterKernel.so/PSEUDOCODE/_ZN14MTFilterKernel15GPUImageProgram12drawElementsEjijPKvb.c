// Function: MTFilterKernel::GPUImageProgram::drawElements(unsigned int, int, unsigned int, void const*, bool)
// RVA: 0x168c90, Size: 100 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram12drawElementsEjijPKvb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel11RenderState9renderPreEv(...); // call internal at 0x168cc0
    glDrawElements(...); // call PLT API at 0x168cd4
    _ZN14MTFilterKernel11RenderState9renderEndEv(...); // call internal at 0x168cf0
}
