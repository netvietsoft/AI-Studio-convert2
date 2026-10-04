// Function: utils::File::size()
// RVA: 0x787d0, Size: 100 bytes
int64_t _ZN5utils4File4sizeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fseek(...); // call imported API via PLT at 0x787f0
    ftell(...); // call imported API via PLT at 0x787f8
    fseek(...); // call imported API via PLT at 0x78810
    return a0;
    return a0;
}
