// Function: sub_D36C34
// RVA: 0xd36c34, Size: 400 bytes
int64_t sub_D36C34(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B7868C(...); // call internal func at 0xd36c5c
    sub_B7AC30(...); // call internal func at 0xd36c74
    const char* s_1fabbc = "sec"; // string xref
    sub_D36E48(...); // call internal func at 0xd36c94
    const char* s_1a297d = "min"; // string xref
    sub_D36E48(...); // call internal func at 0xd36cac
    const char* s_196ebe = "hour"; // string xref
    sub_D36E48(...); // call internal func at 0xd36cc4
    const char* s_2709e2 = "day"; // string xref
    sub_D36E48(...); // call internal func at 0xd36ce0
    const char* s_282511 = "month"; // string xref
    sub_D36E48(...); // call internal func at 0xd36cf8
    const char* s_24c759 = "year"; // string xref
    sub_D36E48(...); // call internal func at 0xd36d14
    const char* s_19d777 = "isdst"; // string xref
    sub_B791A8(...); // call internal func at 0xd36d30
    sub_B7868C(...); // call internal func at 0xd36d3c
    sub_B78A8C(...); // call internal func at 0xd36d4c
    mktime(...); // call imported API via PLT at 0xd36d68
    time(...); // call imported API via PLT at 0xd36d74
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xd36dc0
}
