// Function: MTFilterKernel::MTPugiPlist::FormatHead()
// RVA: 0x180534, Size: 208 bytes
int64_t _ZN14MTFilterKernel11MTPugiPlist10FormatHeadEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4pugi8xml_node13prepend_childENS_13xml_node_typeE(...); // call internal at 0x18055c
    const char* str = "version";
    _ZN4pugi8xml_node16append_attributeEPKc(...); // call internal at 0x180570
    const char* str = "1.0";
    _ZN4pugi13xml_attributeaSEPKc(...); // call internal at 0x180584
    const char* str = "encoding";
    _ZN4pugi8xml_node16append_attributeEPKc(...); // call internal at 0x180594
    const char* str = "UTF-8";
    _ZN4pugi13xml_attributeaSEPKc(...); // call internal at 0x1805a8
    _ZN4pugi8xml_node12append_childENS_13xml_node_typeE(...); // call internal at 0x1805b4
    _ZN4pugi8xml_node9set_valueEPKc(...); // call internal at 0x1805d8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x180600
}
