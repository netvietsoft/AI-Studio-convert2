// Function: Mat4::rotate(Vec3 const&, float, Mat4*) const
// RVA: 0x139db4, Size: 364 bytes
int64_t _ZNK4Mat46rotateERK4Vec3fPS_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4Mat4C1Ev(...); // call internal at 0x139df4
    sincosf(...); // call PLT API at 0x139e50
    _ZN8MathUtil14multiplyMatrixEPKfS1_Pf(...); // call internal at 0x139ee0
    _ZN4Mat4D2Ev(...); // call internal at 0x139ee8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x139f1c
}
