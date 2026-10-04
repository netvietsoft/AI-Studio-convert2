// Function: MMCodec::MediaFilter::parseH2645Context(AVPacket*)
// RVA: 0x15ad44, Size: 972 bytes
int64_t _ZN7MMCodec11MediaFilter17parseH2645ContextEP8AVPacket(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mm_alloc_MMH264ExtraContext(...); // call imported API via PLT at 0x15adb4
    mm_h264_decode_extradata(...); // call imported API via PLT at 0x15addc
    mm_free_MMH264ExtraContext(...); // call imported API via PLT at 0x15adec
    mm_alloc_MMH264Context(...); // call imported API via PLT at 0x15ae60
    mm_h264_decode_extradata(...); // call imported API via PLT at 0x15aecc
    mm_alloc_MMH264Context(...); // call imported API via PLT at 0x15af3c
    return a0;
    mm_decode_nal_units(...); // call imported API via PLT at 0x15afac
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6db69 = "[%s(%d)]:> MediaFilter, MMH264Context pts %lld nal_ref_idc %d nal_type %d"; // string xref
    const char* s_6b604 = "parseH2645Context"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15aff8
    const char* s_799d6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaFilter, MMH264Context pts %lld nal_ref_idc %d nal_type %d
"; // string xref
    const char* s_6b604 = "parseH2645Context"; // string xref
    mm_decode_nal_units(...); // call imported API via PLT at 0x15b050
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6db69 = "[%s(%d)]:> MediaFilter, MMH264Context pts %lld nal_ref_idc %d nal_type %d"; // string xref
    const char* s_6b604 = "parseH2645Context"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15b09c
    const char* s_799d6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaFilter, MMH264Context pts %lld nal_ref_idc %d nal_type %d
"; // string xref
    const char* s_6b604 = "parseH2645Context"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x15b0e0
    mm_free_MMH264Context(...); // call imported API via PLT at 0x15b0ec
    _ZNSt6__ndk13mapIlPvNS_4lessIlEENS_9allocatorINS_4pairIKlS1_EEEEE6insertB8ne180000INS5_IlP13MMH264ContextEEvEENS5_INS_14__map_iteratorINS_15__tree_iteratorINS_12__value_typeIlS1_EEPNS_11__tree_nodeISH_S1_EElEEEEbEEOT_(...); // call imported API via PLT at 0x15b100
    __stack_chk_fail(...); // call imported API via PLT at 0x15b10c
}
