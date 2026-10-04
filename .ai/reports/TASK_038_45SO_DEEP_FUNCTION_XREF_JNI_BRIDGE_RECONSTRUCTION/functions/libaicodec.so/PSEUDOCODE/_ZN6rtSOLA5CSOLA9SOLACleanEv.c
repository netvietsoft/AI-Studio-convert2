// Function: rtSOLA::CSOLA::SOLAClean()
// RVA: 0x11cb64, Size: 108 bytes
int64_t _ZN6rtSOLA5CSOLA9SOLACleanEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call imported API via PLT at 0x11cb7c
    free(...); // call imported API via PLT at 0x11cb8c
    free(...); // call imported API via PLT at 0x11cb9c
    free(...); // call imported API via PLT at 0x11cbac
    free(...); // call imported API via PLT at 0x11cbbc
    return a0;
}
