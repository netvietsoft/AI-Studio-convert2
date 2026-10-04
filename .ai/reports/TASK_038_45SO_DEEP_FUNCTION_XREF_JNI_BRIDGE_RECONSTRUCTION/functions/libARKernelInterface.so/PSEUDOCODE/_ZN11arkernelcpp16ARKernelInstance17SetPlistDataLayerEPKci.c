// Function: arkernelcpp::ARKernelInstance::SetPlistDataLayer(char const*, int)
// RVA: 0x591808, Size: 144 bytes
int64_t _ZN11arkernelcpp16ARKernelInstance17SetPlistDataLayerEPKci(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN11arkernelcpp16ARKernelInstance12GetPlistDataEPKc(...); // call PLT API at 0x591820
    _ZN11arkernelcpp26ARKernelPlistDataInterface8SetApplyEb(...); // call PLT API at 0x591830
    _ZN11arkernelcpp26ARKernelPlistDataInterface14GetPartControlEv(...); // call PLT API at 0x591838
    _ZN11arkernelcpp28ARKernelPartControlInterface19SetPartControlLayerEi(...); // call PLT API at 0x59186c
    return a0;
}
