// Function: sub_A7DE88
// RVA: 0xa7de88, Size: 152 bytes
int64_t sub_A7DE88(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_A7FC18(...); // call internal at 0xa7de98
    const char* str = "libvlmonitor.so";
    dlopen(...); // call PLT API at 0xa7dec4
    const char* str = "vlmonitor_checkpoint";
    dlsym(...); // call PLT API at 0xa7ded8
    const char* str = "vlmonitor_checkrange_begin";
    dlsym(...); // call PLT API at 0xa7def0
    const char* str = "vlmonitor_checkrange_end";
    dlsym(...); // call PLT API at 0xa7df08
    return a0;
    sub_562D14(...); // call internal at 0xa7df1c
}
