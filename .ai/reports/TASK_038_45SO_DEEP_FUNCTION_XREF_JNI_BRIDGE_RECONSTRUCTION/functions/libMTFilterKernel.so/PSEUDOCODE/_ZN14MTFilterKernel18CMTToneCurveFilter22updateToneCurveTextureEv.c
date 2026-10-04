// Function: MTFilterKernel::CMTToneCurveFilter::updateToneCurveTexture()
// RVA: 0x12ea6c, Size: 560 bytes
int64_t _ZN14MTFilterKernel18CMTToneCurveFilter22updateToneCurveTextureEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glActiveTexture(...); // call PLT API at 0x12ea94
    glBindTexture(...); // call PLT API at 0x12eaa4
    glGenTextures(...); // call PLT API at 0x12eac4
    glBindTexture(...); // call PLT API at 0x12ead0
    glTexParameteri(...); // call PLT API at 0x12eae0
    glTexParameteri(...); // call PLT API at 0x12eaf0
    glTexParameteri(...); // call PLT API at 0x12eb00
    glTexParameteri(...); // call PLT API at 0x12eb10
    calloc(...); // call PLT API at 0x12eb5c
    glTexImage2D(...); // call PLT API at 0x12ec64
    free(...); // call PLT API at 0x12ec80
    return a0;
}
