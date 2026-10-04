// Function: MTFilterKernel::GPUImageProgram::SetMesh(char const*, MTFilterKernel::Mesh*)
// RVA: 0x168bb8, Size: 132 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram7SetMeshEPKcPNS_4MeshE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram17GetAttribLocationEPKc(...); // call internal at 0x168bd0
    _ZN14MTFilterKernel11RenderState23enableVertexAttribArrayEi(...); // call internal at 0x168bec
    _ZNK14MTFilterKernel4Mesh13getVertexSizeEv(...); // call internal at 0x168bf4
    _ZNK14MTFilterKernel4Mesh16getVertexDataPtrEv(...); // call internal at 0x168c00
    glVertexAttribPointer(...); // call PLT API at 0x168c28
    return a0;
}
