// Function: sub_A7DB80
// RVA: 0xa7db80, Size: 196 bytes
int64_t sub_A7DB80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xa7dbbc
    malloc(...); // call imported API via PLT at 0xa7dbd0
    (*x8)(...); // indirect call at 0xa7dbfc
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl(...); // call imported API via PLT at 0xa7dc14
    free(...); // call imported API via PLT at 0xa7dc1c
    return a0;
    sub_562D14(...); // call internal func at 0xa7dc40
}
