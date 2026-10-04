// Function: mizar::NpuAdapterImpl::Process(std::__ndk1::vector<mizar::NpuTensorBuffer, std::__ndk1::allocator<mizar::NpuTensorBuffer>> const&, std::__ndk1::vector<mizar::NpuTensorBuffer, std::__ndk1::allocator<mizar::NpuTensorBuffer>>&)
// RVA: 0xe34bc, Size: 4096 bytes
int64_t _ZN5mizar14NpuAdapterImpl7ProcessERKNSt6__ndk16vectorINS_15NpuTensorBufferENS1_9allocatorIS3_EEEERS6_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    (*x8)(...);
    memcpy(...); // call PLT API at 0xe3670
    _ZN4hiai18AiModelMngerClient7ProcessERNS_9AiContextERNSt6__ndk16vectorINS3_10shared_ptrINS_8AiTensorEEENS3_9allocatorIS7_EEEESB_jRi(...); // call PLT API at 0xe36a8
    const char* str = "Client process failed!";
    const char* str = "Hiai NPU ERROR CODE: ";
    _ZN5mizar6detail14MakeStringImplIJNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPKciEEES8_DpRKT_(...); // call PLT API at 0xe3704
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0xe3a08
    fprintf(...); // call PLT API at 0xe3ce8
    _ZN5mizar6StatusC1EiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(...); // call PLT API at 0xe3cf8
    _ZdlPv(...); // call PLT API at 0xe3d08
    const char* str = "The input size of model is ";
    const char* str = ", but got ";
    _ZN5mizar6detail14MakeStringImplIJPKciS3_iEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_(...); // call PLT API at 0xe3d54
    const char* str = "Mizar";
    __android_log_print(...); // call PLT API at 0xe4054
    fprintf(...); // call PLT API at 0xe4334
    _ZN5mizar6StatusC1EiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(...); // call PLT API at 0xe4344
    const char* str = "The output size of model is ";
    const char* str = "but got ";
    _ZN5mizar6detail14MakeStringImplIJPKciS3_iEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_(...); // call PLT API at 0xe4390
}
