// Function: sub_B1F64
// RVA: 0xb1f64, Size: 1128 bytes
int64_t sub_B1F64(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xb20fc
    memmove(...); // call imported API via PLT at 0xb2158
    (*x8)(...); // indirect call at 0xb21bc
    (*x8)(...); // indirect call at 0xb2244
    memmove(...); // call imported API via PLT at 0xb2370
    return a0;
}
