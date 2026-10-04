// Function: MTFilterKernel::CGLProgram::DisableVertexAttribPointer(char const*)
// RVA: 0x1406e4, Size: 36 bytes
int64_t _ZN14MTFilterKernel10CGLProgram26DisableVertexAttribPointerEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram17GetAttribLocationEPKc(...); // call internal at 0x1406ec
    glDisableVertexAttribArray(...); // call PLT API at 0x1406fc
    return a0;
}
