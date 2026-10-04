// Function: frame_argument
// RVA: 0x297e98, Size: 408 bytes
int64_t frame_argument(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    parse_frame_spec(...); // call PLT API at 0x297ebc
    Gif_GetImage(...); // call PLT API at 0x297f44
    clear_frameset(...); // call PLT API at 0x297f84
    add_frame(...); // call PLT API at 0x297f94
    sub_296D0C(...); // call internal at 0x29800c
    return a0;
}
