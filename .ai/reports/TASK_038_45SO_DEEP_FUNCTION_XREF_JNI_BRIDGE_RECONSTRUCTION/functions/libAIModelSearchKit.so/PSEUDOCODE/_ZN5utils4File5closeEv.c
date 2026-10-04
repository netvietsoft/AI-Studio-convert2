// Function: utils::File::close()
// RVA: 0x78694, Size: 44 bytes
int64_t _ZN5utils4File5closeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fclose(...); // call imported API via PLT at 0x786ac
    return a0;
}
