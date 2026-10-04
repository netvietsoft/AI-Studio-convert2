// Function: MTFilterKernel::CMeituDefocus::AnyFileRead(char*, float*, unsigned long, unsigned long)
// RVA: 0xcfec0, Size: 188 bytes
int64_t _ZN14MTFilterKernel13CMeituDefocus11AnyFileReadEPcPfmm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "rb";
    fopen(...); // call PLT API at 0xcfef4
    fread(...); // call PLT API at 0xcff10
    fclose(...); // call PLT API at 0xcff28
    AAssetManager_open(...); // call PLT API at 0xcff3c
    AAsset_read(...); // call PLT API at 0xcff4c
    AAsset_close(...); // call PLT API at 0xcff64
    return a0;
}
