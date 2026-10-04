// Function: sub_6FA8C8
// RVA: 0x6fa8c8, Size: 180 bytes
int64_t sub_6FA8C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "ro.build.version.sdk";
    __system_property_get(...); // call PLT API at 0x6fa928
    atoi(...); // call PLT API at 0x6fa930
    const char* str = "-DFORCE_FP32";
    sub_6684E0(...); // call internal at 0x6fa948
    sub_33ACE0(...); // call internal at 0x6fa950
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x6fa978
}
