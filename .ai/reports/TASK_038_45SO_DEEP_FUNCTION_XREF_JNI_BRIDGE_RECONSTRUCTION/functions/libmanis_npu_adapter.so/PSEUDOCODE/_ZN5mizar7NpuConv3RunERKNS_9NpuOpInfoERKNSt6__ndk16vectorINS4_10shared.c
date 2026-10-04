// Function: mizar::NpuConv::Run(mizar::NpuOpInfo const&, std::__ndk1::vector<std::__ndk1::shared_ptr<ge::Operator>, std::__ndk1::allocator<std::__ndk1::shared_ptr<ge::Operator>>> const&)
// RVA: 0x79ab0, Size: 4096 bytes
int64_t _ZN5mizar7NpuConv3RunERKNS_9NpuOpInfoERKNSt6__ndk16vectorINS4_10shared_ptrIN2ge8OperatorEEENS4_9allocatorIS9_EEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call PLT API at 0x79b74
    _ZN4hiai2op11ConvolutionC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE(...); // call PLT API at 0x79b9c
    _ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_(...); // call PLT API at 0x79bbc
    _ZdlPv(...); // call PLT API at 0x79bd0
    _Znwm(...); // call PLT API at 0x79bd8
    _ZN4hiai2op5ConstC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE(...); // call PLT API at 0x79c00
    _ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEERKNS_15NpuTensorBufferE(...); // call PLT API at 0x79c14
    _ZNK5mizar6Status7IsErrorEv(...); // call PLT API at 0x79c1c
    _ZN5mizar6StatusneEi(...); // call PLT API at 0x79c2c
    _ZNK5mizar6Status11DescriptionEv(...); // call PLT API at 0x79f60
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x79f94
    _ZdlPv(...); // call PLT API at 0x79fa4
    _ZNK5mizar6Status11DescriptionEv(...); // call PLT API at 0x7a2b0
    fprintf(...); // call PLT API at 0x7a2e4
    _ZdlPv(...); // call PLT API at 0x7a2f4
    _Znwm(...); // call PLT API at 0x7a300
    const char* str = "Could not find weight for Conv!";
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0x7a670
    fprintf(...); // call PLT API at 0x7a98c
    _ZN5mizar6StatusC1EiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(...); // call PLT API at 0x7a99c
    _Znwm(...); // call PLT API at 0x7a9a8
    const char* str = "Weight for Conv must be const!";
}
