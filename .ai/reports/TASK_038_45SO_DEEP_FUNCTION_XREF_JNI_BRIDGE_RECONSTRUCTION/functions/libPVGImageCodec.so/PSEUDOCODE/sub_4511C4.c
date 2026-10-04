// Function: sub_4511C4
// RVA: 0x4511c4, Size: 348 bytes
int64_t sub_4511C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    SharpYuvGetConversionMatrix(...); // call PLT API at 0x451274
    SharpYuvConvert(...); // call PLT API at 0x4512dc
    sub_4526B8(...); // call internal at 0x4512f8
    return a0;
}
