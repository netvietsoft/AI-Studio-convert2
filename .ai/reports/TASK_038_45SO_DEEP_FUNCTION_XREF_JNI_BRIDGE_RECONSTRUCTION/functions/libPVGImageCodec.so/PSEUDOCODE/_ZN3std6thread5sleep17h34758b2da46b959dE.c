// Function: std::thread::sleep::h34758b2da46b959d
// RVA: 0x2f71e8, Size: 176 bytes
int64_t _ZN3std6thread5sleep17h34758b2da46b959dE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    nanosleep(...); // call PLT API at 0x2f7220
    __errno(...); // call PLT API at 0x2f7238
    return a0;
    sub_2E50A0(...); // call internal at 0x2f7290
}
