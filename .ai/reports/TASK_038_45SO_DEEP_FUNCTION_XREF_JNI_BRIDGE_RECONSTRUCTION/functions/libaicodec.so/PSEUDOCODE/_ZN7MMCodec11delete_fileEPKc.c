// Function: MMCodec::delete_file(char const*)
// RVA: 0x163a04, Size: 76 bytes
int64_t _ZN7MMCodec11delete_fileEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_6c69c = "wb"; // string xref
    fopen(...); // call imported API via PLT at 0x163a20
    fclose(...); // call imported API via PLT at 0x163a28
    remove(...); // call imported API via PLT at 0x163a30
    return a0;
}
