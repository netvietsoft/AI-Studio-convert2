// Function: sub_9B4B0
// RVA: 0x9b4b0, Size: 1176 bytes
int64_t sub_9B4B0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x9b50c
    (*x8)(...); // indirect call at 0x9b5dc
    (*x8)(...); // indirect call at 0x9b634
    (*x8)(...); // indirect call at 0x9b670
    (*x8)(...); // indirect call at 0x9b68c
    (*x8)(...); // indirect call at 0x9b704
    (*x8)(...); // indirect call at 0x9b78c
    free(...); // call imported API via PLT at 0x9b870
    return a0;
    (*x8)(...); // indirect call at 0x9b8c4
    (*x8)(...); // indirect call at 0x9b8f0
    _ZSt17__throw_bad_allocv(...); // call imported API via PLT at 0x9b918
    free(...); // call imported API via PLT at 0x9b93c
}
