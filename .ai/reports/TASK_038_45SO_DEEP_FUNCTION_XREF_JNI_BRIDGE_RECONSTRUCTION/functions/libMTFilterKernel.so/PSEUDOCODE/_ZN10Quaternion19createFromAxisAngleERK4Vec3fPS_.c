// Function: Quaternion::createFromAxisAngle(Vec3 const&, float, Quaternion*)
// RVA: 0x13b42c, Size: 196 bytes
int64_t _ZN10Quaternion19createFromAxisAngleERK4Vec3fPS_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4Vec3C1ERKS_(...); // call internal at 0x13b45c
    _ZN4Vec39normalizeEv(...); // call internal at 0x13b464
    sincosf(...); // call PLT API at 0x13b478
    _ZN4Vec3D2Ev(...); // call internal at 0x13b4a0
    return a0;
    _ZN4Vec3D2Ev(...); // call internal at 0x13b4d0
    sub_1B0544(...); // call internal at 0x13b4e8
    __stack_chk_fail(...); // call PLT API at 0x13b4ec
}
