// Function: LayerFlowNS::CLFMaterialDownloadPlugin::waitForAllDownloaded()
// RVA: 0x4551dc, Size: 264 bytes
int64_t _ZN11LayerFlowNS25CLFMaterialDownloadPlugin20waitForAllDownloadedEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call PLT API at 0x45520c
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call PLT API at 0x4552ac
    _ZNSt6__ndk15mutex6unlockEv(...); // call PLT API at 0x4552bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x4552e0
}
