// Function: MMDetectionPlugin::FaceModule::getFaceDataImage(void*, media::Image*)
// RVA: 0x5856c, Size: 120 bytes
int64_t _ZN17MMDetectionPlugin10FaceModule16getFaceDataImageEPvPN5media5ImageE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN17MMDetectionPlugin10FaceModule19createFaceDataImageEPvPN5media5ImageE(...); // call imported API via PLT at 0x58578
    _ZNK5media5Image17getColorPrimariesEv(...); // call imported API via PLT at 0x58588
    _ZNK5media5Image17getColorPrimariesEv(...); // call imported API via PLT at 0x58598
    _ZNK5media5Image16getColorTransferEv(...); // call imported API via PLT at 0x585a4
    _ZN5media16MTColorFunctions17convertColorSpaceEPNS_5ImageENS_16MTColorPrimariesENS_15MTColorTransferES3_S4_(...); // call imported API via PLT at 0x585bc
    _ZN5media3Ref7releaseEv(...); // call imported API via PLT at 0x585c8
    return a0;
}
