// Function: clear_frameset
// RVA: 0x284d30, Size: 48 bytes
int64_t clear_frameset(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    blank_frameset(...); // call PLT API at 0x284d4c
    return a0;
}
