// Function: verbose_endline
// RVA: 0x2811d4, Size: 68 bytes
int64_t verbose_endline(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fputc(...); // call PLT API at 0x2811fc
    fflush(...); // call PLT API at 0x281204
    return a0;
}
