// Function: sub_A5ACB8
// RVA: 0xa5acb8, Size: 1208 bytes
int64_t sub_A5ACB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fmodf(...); // call PLT API at 0xa5ad54
    sub_A5AAA8(...); // call internal at 0xa5ad64
    sub_FC2858(...); // call internal at 0xa5ae4c
    memcpy(...); // call PLT API at 0xa5ae5c
    sub_A5B170(...); // call internal at 0xa5b070
    memcpy(...); // call PLT API at 0xa5b098
    sub_A5B170(...); // call internal at 0xa5b11c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa5b16c
}
