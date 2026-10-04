// Function: MTFilterKernel::MeshIndex::create(void const*, MTFilterKernel::MeshIndex::IndexFormat, unsigned int, bool)
// RVA: 0x16e42c, Size: 356 bytes
int64_t _ZN14MTFilterKernel9MeshIndex6createEPKvNS0_11IndexFormatEjb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenBuffers(...); // call PLT API at 0x16e46c
    glBindBuffer(...); // call PLT API at 0x16e478
    glBufferData(...); // call PLT API at 0x16e4c8
    _Znwm(...); // call PLT API at 0x16e4d0
    _ZN14MTFilterKernel9MeshIndexC1Ev(...); // call internal at 0x16e4d8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x16e504
    const char* str = "FilterKernel";
    const char* str = "Unsupported index format (%d).";
    __android_log_print(...); // call PLT API at 0x16e528
    glDeleteBuffers(...); // call PLT API at 0x16e534
    return a0;
    _ZdlPv(...); // call PLT API at 0x16e570
    sub_1B0544(...); // call internal at 0x16e588
    __stack_chk_fail(...); // call PLT API at 0x16e58c
}
