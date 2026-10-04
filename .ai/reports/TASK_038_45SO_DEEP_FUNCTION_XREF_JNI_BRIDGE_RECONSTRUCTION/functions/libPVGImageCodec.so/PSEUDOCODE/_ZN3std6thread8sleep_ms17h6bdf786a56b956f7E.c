// Function: std::thread::sleep_ms::h6bdf786a56b956f7
// RVA: 0x2f70f4, Size: 244 bytes
int64_t _ZN3std6thread8sleep_ms17h6bdf786a56b956f7E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    nanosleep(...); // call PLT API at 0x2f7170
    __errno(...); // call PLT API at 0x2f7188
    return a0;
    sub_2E50A0(...); // call internal at 0x2f71e0
}
