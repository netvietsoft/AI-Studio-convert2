// Function: utils::File::~File()
// RVA: 0x78650, Size: 68 bytes
int64_t _ZN5utils4FileD2Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fclose(...); // call imported API via PLT at 0x78668
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x78690
}
