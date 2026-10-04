// Function: MTFilterKernel::CMTDetailsFilter::SetUniformParam()
// RVA: 0x12486c, Size: 60 bytes
int64_t _ZN14MTFilterKernel16CMTDetailsFilter15SetUniformParamEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel16CMTDynamicFilter15SetUniformParamEv(...); // call internal at 0x12487c
    glActiveTexture(...); // call PLT API at 0x124884
    glBindTexture(...); // call PLT API at 0x124890
    glUniform1i(...); // call PLT API at 0x1248a4
}
