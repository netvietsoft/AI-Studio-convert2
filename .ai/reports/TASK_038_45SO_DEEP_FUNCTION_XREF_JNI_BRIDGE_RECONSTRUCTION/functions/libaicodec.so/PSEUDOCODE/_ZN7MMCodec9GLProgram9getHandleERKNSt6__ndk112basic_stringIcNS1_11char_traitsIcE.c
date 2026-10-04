// Function: MMCodec::GLProgram::getHandle(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&)
// RVA: 0x1796c8, Size: 496 bytes
int64_t _ZN7MMCodec9GLProgram9getHandleERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1796f8
    _ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE4findIS7_EENS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEERKT_(...); // call imported API via PLT at 0x179704
    glGetAttribLocation(...); // call imported API via PLT at 0x179728
    glGetUniformLocation(...); // call imported API via PLT at 0x179750
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_700ce = "[%s(%d)]:> Could not get attrib or uniform location for %s"; // string xref
    const char* s_79cae = "getHandle"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1797c8
    const char* s_76f04 = "%s/MTMV_AICodec: [%s(%d)]:> Could not get attrib or uniform location for %s
"; // string xref
    const char* s_79cae = "getHandle"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x179814
    sub_D2278(...); // call internal func at 0x17982c
    _ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JNS_4pairIS7_iEEEEENSK_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_(...); // call imported API via PLT at 0x179840
    _ZdlPv(...); // call imported API via PLT at 0x179850
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x179858
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x179898
    __stack_chk_fail(...); // call imported API via PLT at 0x1798b4
}
