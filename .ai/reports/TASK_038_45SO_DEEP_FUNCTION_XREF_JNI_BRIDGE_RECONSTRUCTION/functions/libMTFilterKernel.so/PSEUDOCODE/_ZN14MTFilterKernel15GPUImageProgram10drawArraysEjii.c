// Function: MTFilterKernel::GPUImageProgram::drawArrays(unsigned int, int, int)
// RVA: 0x168c3c, Size: 84 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram10drawArraysEjii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel11RenderState9renderPreEv(...); // call internal at 0x168c64
    glDrawArrays(...); // call PLT API at 0x168c74
    _ZN14MTFilterKernel11RenderState9renderEndEv(...); // call internal at 0x168c8c
}
