// Function: input_done
// RVA: 0x2976dc, Size: 200 bytes
int64_t input_done(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    verbose_close(...); // call PLT API at 0x29770c
    Gif_DeleteStream(...); // call PLT API at 0x297714
    output_frames(...); // call PLT API at 0x29777c
    return a0;
}
