// Function: MTFilterKernel::JavaHelper::getAndroidCpuCount()
// RVA: 0xc1550, Size: 24 bytes
int64_t _ZN14MTFilterKernel10JavaHelper18getAndroidCpuCountEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sysconf(...); // call PLT API at 0xc155c
    return a0;
}
