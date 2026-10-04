// Function: pugi::xml_document::save_file(wchar_t const*, char const*, unsigned int, pugi::xml_encoding) const
// RVA: 0x18d55c, Size: 264 bytes
int64_t _ZNK4pugi12xml_document9save_fileEPKwPKcjNS_12xml_encodingE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_18CC18(...); // call internal at 0x18d5b0
    _ZN4pugi15xml_writer_fileC2EPv(...); // call internal at 0x18d5c4
    _ZNK4pugi12xml_document4saveERNS_10xml_writerEPKcjNS_12xml_encodingE(...); // call internal at 0x18d5dc
    ferror(...); // call PLT API at 0x18d5e4
    fclose(...); // call PLT API at 0x18d5f4
    return a0;
    fclose(...); // call PLT API at 0x18d644
    sub_1B0544(...); // call internal at 0x18d65c
    __stack_chk_fail(...); // call PLT API at 0x18d660
}
