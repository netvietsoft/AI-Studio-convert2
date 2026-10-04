// Function: void nlohmann::json_abi_v3_12_0::detail::get_arithmetic_value<nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void>, int, 0>(nlohmann::json_abi_v3_12_0::basic_json<std::__ndk1::map, std::__ndk1::vector, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>, bool, long, unsigned long, double, std::__ndk1::allocator, nlohmann::json_abi_v3_12_0::adl_serializer, std::__ndk1::vector<unsigned char, std::__ndk1::allocator<unsigned char>>, void> const&, int&)
// RVA: 0x3849f4, Size: 344 bytes
int64_t _ZN8nlohmann16json_abi_v3_12_06detail20get_arithmetic_valueINS0_10basic_jsonINSt6__ndk13mapENS4_6vectorENS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEblmdSA_NS0_14adl_serializerENS6_IhNSA_IhEEEEvEEiTnNS4_9enable_ifIXaasr3std13is_arithmeticIT0_EE5valuentsr3std7is_sameISI_NT_9boolean_tEEE5valueEiE4typeELi0EEEvRKSJ_RSI_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    __cxa_allocate_exception(...); // call PLT API at 0x384a88
    _ZNK8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE9type_nameEv(...); // call internal at 0x384a98
    const char* str = "type must be number, but is ";
    _ZN8nlohmann16json_abi_v3_12_06detail6concatINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEJRA29_KcPSA_EEET_DpOT0_(...); // call internal at 0x384ab0
    _ZN8nlohmann16json_abi_v3_12_06detail10type_error6createIPKNS0_10basic_jsonINSt6__ndk13mapENS5_6vectorENS5_12basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEEblmdSB_NS0_14adl_serializerENS7_IhNSB_IhEEEEvEETnNS5_9enable_ifIXsr21is_basic_json_contextIT_EE5valueEiE4typeELi0EEES2_iRKSD_SL_(...); // call internal at 0x384ac8
    __cxa_throw(...); // call PLT API at 0x384af8
    _ZdlPv(...); // call PLT API at 0x384b14
    __cxa_free_exception(...); // call PLT API at 0x384b28
    sub_526544(...); // call internal at 0x384b44
    __stack_chk_fail(...); // call PLT API at 0x384b48
}
