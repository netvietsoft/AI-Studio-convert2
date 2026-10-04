// Function: MTFilterKernel::MeshIndex::setIndexData(void const*, unsigned int, unsigned int)
// RVA: 0x16e5a8, Size: 296 bytes
int64_t _ZN14MTFilterKernel9MeshIndex12setIndexDataEPKvjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindBuffer(...); // call PLT API at 0x16e5d4
    glBufferSubData(...); // call PLT API at 0x16e648
    glBufferData(...); // call PLT API at 0x16e688
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x16e68c
    const char* str = "FilterKernel";
    const char* str = "Unsupported index format (%d).";
    __android_log_print(...); // call PLT API at 0x16e6bc
    return a0;
}
