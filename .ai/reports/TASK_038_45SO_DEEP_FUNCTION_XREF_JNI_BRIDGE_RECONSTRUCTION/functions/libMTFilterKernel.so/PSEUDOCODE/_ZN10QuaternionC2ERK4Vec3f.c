// Function: Quaternion::Quaternion(Vec3 const&, float)
// RVA: 0x13b0b8, Size: 192 bytes
int64_t _ZN10QuaternionC2ERK4Vec3f(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4Vec3C1ERKS_(...); // call internal at 0x13b0e4
    _ZN4Vec39normalizeEv(...); // call internal at 0x13b0ec
    sincosf(...); // call PLT API at 0x13b100
    _ZN4Vec3D2Ev(...); // call internal at 0x13b128
    return a0;
    _ZN4Vec3D2Ev(...); // call internal at 0x13b158
    sub_1B0544(...); // call internal at 0x13b170
    __stack_chk_fail(...); // call PLT API at 0x13b174
}
