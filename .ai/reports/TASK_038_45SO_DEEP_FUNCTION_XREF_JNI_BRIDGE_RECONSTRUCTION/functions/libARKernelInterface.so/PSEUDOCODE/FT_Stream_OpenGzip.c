// Function: FT_Stream_OpenGzip
// RVA: 0xed8fb4, Size: 644 bytes
int64_t FT_Stream_OpenGzip(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_ED9238(...); // call internal at 0xed8ff4
    sub_EBD698(...); // call internal at 0xed9020
    sub_EBCA0C(...); // call internal at 0xed903c
    return a0;
    sub_ED9238(...); // call internal at 0xed90c4
    sub_EBD3F0(...); // call internal at 0xed90d8
    const char* str = "1.2.8";
    inflateInit2_(...); // call PLT API at 0xed9118
    sub_EB6F98(...); // call internal at 0xed9130
    sub_EBDA44(...); // call internal at 0xed9140
    sub_EBCA0C(...); // call internal at 0xed915c
    sub_EB6E54(...); // call internal at 0xed917c
    sub_ED93D0(...); // call internal at 0xed919c
    inflateEnd(...); // call PLT API at 0xed91ac
    sub_EB6F98(...); // call internal at 0xed91d4
    sub_ED93D0(...); // call internal at 0xed921c
    sub_EB6F98(...); // call internal at 0xed9228
    __stack_chk_fail(...); // call PLT API at 0xed9234
}
