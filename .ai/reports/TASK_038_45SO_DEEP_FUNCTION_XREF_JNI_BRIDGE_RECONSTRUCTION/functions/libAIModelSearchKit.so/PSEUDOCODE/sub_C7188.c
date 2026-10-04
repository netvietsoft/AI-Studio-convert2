// Function: sub_C7188
// RVA: 0xc7188, Size: 840 bytes
int64_t sub_C7188(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0xc71e4
    (*x8)(...); // indirect call at 0xc72b0
    (*x8)(...); // indirect call at 0xc731c
    free(...); // call imported API via PLT at 0xc745c
    return a0;
    _ZSt17__throw_bad_allocv(...); // call imported API via PLT at 0xc74b0
    free(...); // call imported API via PLT at 0xc74c4
}
