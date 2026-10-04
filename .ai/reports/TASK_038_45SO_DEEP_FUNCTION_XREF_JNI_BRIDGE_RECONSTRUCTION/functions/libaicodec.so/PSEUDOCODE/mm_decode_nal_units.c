// Function: mm_decode_nal_units
// RVA: 0x17390c, Size: 420 bytes
int64_t mm_decode_nal_units(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    MM_AV_RB32(...); // call imported API via PLT at 0x173950
    MM_AV_RB32(...); // call imported API via PLT at 0x173960
    MM_AV_RB32(...); // call imported API via PLT at 0x173980
    MM_AV_RB32(...); // call imported API via PLT at 0x173990
    mm_ff_h2645_packet_split(...); // call imported API via PLT at 0x1739b8
    const char* s_7d559 = "Unknown NAL code: %d (%d bits)
"; // string xref
    av_log(...); // call imported API via PLT at 0x173a0c
    const char* s_82ac8 = "Error splitting the input into NAL units.
"; // string xref
    av_log(...); // call imported API via PLT at 0x173a8c
    return a0;
}
