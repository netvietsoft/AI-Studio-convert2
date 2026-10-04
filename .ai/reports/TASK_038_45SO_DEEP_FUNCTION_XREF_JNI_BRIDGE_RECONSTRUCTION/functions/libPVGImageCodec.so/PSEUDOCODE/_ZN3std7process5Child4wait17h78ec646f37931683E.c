// Function: std::process::Child::wait::h78ec646f37931683
// RVA: 0x30ff44, Size: 192 bytes
int64_t _ZN3std7process5Child4wait17h78ec646f37931683E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    close(...); // call PLT API at 0x30ff6c
    waitpid(...); // call PLT API at 0x30ff98
    __errno(...); // call PLT API at 0x30ffa4
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x30ffb0
    return a0;
    return a0;
}
