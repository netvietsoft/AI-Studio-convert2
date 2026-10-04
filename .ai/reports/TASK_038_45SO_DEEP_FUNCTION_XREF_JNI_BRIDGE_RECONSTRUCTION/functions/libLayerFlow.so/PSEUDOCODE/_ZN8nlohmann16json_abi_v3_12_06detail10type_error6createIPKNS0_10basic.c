// Function: nlohmann::json_abi_v3_12_0::detail::type_error nlohmann::json_abi_v3_12_0::detail::type_error::create<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void> const*, 0>(int, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&, nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void> const*)
// RVA: 0x2fb3a4, Size: 496 bytes
int64_t _ZN8nlohmann16json_abi_v3_12_06detail10type_error6createIPKNS0_10basic_jsonINSt6__ndk13mapENS5_6vectorENS5_12basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEEblmdSB_NS0_14adl_serializerENS7_IhNSB_IhEEEEvEETnNS5_9enable_ifIXsr21is_basic_json_contextIT_EE5valueEiE4typeELi0EEES2_iRKSD_SL_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "type_error";
    _ZNSt6__ndk19to_stringEi(...); // call PLT API at 0x2fb400
    const char* str = "[json.exception.";
    const char* str = "] ";
    _ZN8nlohmann16json_abi_v3_12_06detail6concatINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEJRA17_KcRKS9_cS9_RA3_SA_EEET_DpOT0_(...); // call internal at 0x2fb424
    _ZdlPv(...); // call PLT API at 0x2fb434
    _ZN8nlohmann16json_abi_v3_12_06detail6concatINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEJS9_S9_RKS9_EEET_DpOT0_(...); // call internal at 0x2fb44c
    _ZdlPv(...); // call PLT API at 0x2fb46c
    _ZNSt13runtime_errorC1EPKc(...); // call PLT API at 0x2fb4a0
    _ZdlPv(...); // call PLT API at 0x2fb4c0
    return a0;
    _ZdlPv(...); // call PLT API at 0x2fb4ec
    _ZdlPv(...); // call PLT API at 0x2fb4fc
    _ZNSt9exceptionD2Ev(...); // call PLT API at 0x2fb514
    _ZdlPv(...); // call PLT API at 0x2fb538
    _ZdlPv(...); // call PLT API at 0x2fb55c
    _ZdlPv(...); // call PLT API at 0x2fb574
    sub_526544(...); // call internal at 0x2fb58c
    __stack_chk_fail(...); // call PLT API at 0x2fb590
}
