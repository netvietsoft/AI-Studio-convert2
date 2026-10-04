// Function: VP8LGetInfo
// RVA: 0x41bcdc, Size: 324 bytes
int64_t VP8LGetInfo(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    VP8LCheckSignature(...); // call PLT API at 0x41bd38
    sub_487ECC(...); // call internal at 0x41bd60
    sub_41BE20(...); // call internal at 0x41bd74
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x41be1c
}
