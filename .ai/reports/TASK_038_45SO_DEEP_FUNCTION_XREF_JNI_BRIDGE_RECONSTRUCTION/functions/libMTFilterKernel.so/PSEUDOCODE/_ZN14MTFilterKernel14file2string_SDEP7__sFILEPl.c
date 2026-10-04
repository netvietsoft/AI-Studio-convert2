// Function: MTFilterKernel::file2string_SD(__sFILE*, long*)
// RVA: 0xc32b8, Size: 296 bytes
int64_t _ZN14MTFilterKernel14file2string_SDEP7__sFILEPl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fseek(...); // call PLT API at 0xc32ec
    ftell(...); // call PLT API at 0xc32f4
    fseek(...); // call PLT API at 0xc3308
    fread(...); // call PLT API at 0xc3328
    fseek(...); // call PLT API at 0xc3348
    fseek(...); // call PLT API at 0xc3374
    _Znam(...); // call PLT API at 0xc3384
    fread(...); // call PLT API at 0xc3398
    fclose(...); // call PLT API at 0xc33bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xc33dc
}
