// Function: sub_93C4A0
// RVA: 0x93c4a0, Size: 472 bytes
int64_t sub_93C4A0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    getauxval(...); // call PLT API at 0x93c4e0
    getauxval(...); // call PLT API at 0x93c4ec
    sigfillset(...); // call PLT API at 0x93c54c
    sigdelset(...); // call PLT API at 0x93c558
    sigdelset(...); // call PLT API at 0x93c564
    sigdelset(...); // call PLT API at 0x93c570
    sigdelset(...); // call PLT API at 0x93c57c
    sigdelset(...); // call PLT API at 0x93c588
    sigprocmask(...); // call PLT API at 0x93c5b4
    sigaction(...); // call PLT API at 0x93c5c4
    sigaction(...); // call PLT API at 0x93c5d4
    sigprocmask(...); // call PLT API at 0x93c5e4
    sub_957098(...); // call internal at 0x93c5fc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x93c65c
    siglongjmp(...); // call PLT API at 0x93c674
}
