// Function: nlohmann::json_abi_v3_12_0::detail::type_error nlohmann::json_abi_v3_12_0::detail::type_error::create<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void>*, 0>(int, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&, nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void>*)
// RVA: 0x302f60, Size: 496 bytes
int64_t _ZN8nlohmann16json_abi_v3_12_06detail10type_error6createIPNS0_10basic_jsonINSt6__ndk13mapENS5_6vectorENS5_12basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEEblmdSB_NS0_14adl_serializerENS7_IhNSB_IhEEEEvEETnNS5_9enable_ifIXsr21is_basic_json_contextIT_EE5valueEiE4typeELi0EEES2_iRKSD_SK_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "type_error";
    _ZNSt6__ndk19to_stringEi(...); // call PLT API at 0x302fbc
    const char* str = "[json.exception.";
    const char* str = "] ";
    _ZN8nlohmann16json_abi_v3_12_06detail6concatINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEJRA17_KcRKS9_cS9_RA3_SA_EEET_DpOT0_(...); // call internal at 0x302fe0
    _ZdlPv(...); // call PLT API at 0x302ff0
    _ZN8nlohmann16json_abi_v3_12_06detail6concatINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEJS9_S9_RKS9_EEET_DpOT0_(...); // call internal at 0x303008
    _ZdlPv(...); // call PLT API at 0x303028
    _ZNSt13runtime_errorC1EPKc(...); // call PLT API at 0x30305c
    _ZdlPv(...); // call PLT API at 0x30307c
    return a0;
    _ZdlPv(...); // call PLT API at 0x3030a8
    _ZdlPv(...); // call PLT API at 0x3030b8
    _ZNSt9exceptionD2Ev(...); // call PLT API at 0x3030d0
    _ZdlPv(...); // call PLT API at 0x3030f4
    _ZdlPv(...); // call PLT API at 0x303118
    _ZdlPv(...); // call PLT API at 0x303130
    sub_526544(...); // call internal at 0x303148
    __stack_chk_fail(...); // call PLT API at 0x30314c
}
