// Function: LayerFlowNS::CLFImageUtils::saveImage(std::__ndk1::shared_ptr<MTImageKitNS::Image>, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>>)
// RVA: 0x43efc4, Size: 368 bytes
int64_t _ZN11LayerFlowNS13CLFImageUtils9saveImageENSt6__ndk110shared_ptrIN12MTImageKitNS5ImageEEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN12MTImageKitNS5Image8getWidthEv(...); // call PLT API at 0x43eff8
    _ZN12MTImageKitNS5Image9getHeightEv(...); // call PLT API at 0x43f004
    _ZNK12MTImageKitNS5Image9imageDataEv(...); // call PLT API at 0x43f028
    _ZN12MTImageKitNS5Image8getWidthEv(...); // call PLT API at 0x43f038
    _ZN12MTImageKitNS5Image9getHeightEv(...); // call PLT API at 0x43f048
    const char* str = "clfImageUtils<%s:%d> invalid params, %s";
    const char* str = "saveImage";
    _ZN12MTImageKitNS8CMTIKLog3logEiPKcz(...); // call PLT API at 0x43f094
    return a0;
    sub_2BC260(...); // call internal at 0x43f0d0
    _ZN12MTImageKitNS14ImageDiskCache13saveImageDataEPhiiNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS_16MTIKColorChannelE(...); // call PLT API at 0x43f0e8
    _ZdlPv(...); // call PLT API at 0x43f0fc
    _ZdlPv(...); // call PLT API at 0x43f114
    sub_526544(...); // call internal at 0x43f12c
    __stack_chk_fail(...); // call PLT API at 0x43f130
}
