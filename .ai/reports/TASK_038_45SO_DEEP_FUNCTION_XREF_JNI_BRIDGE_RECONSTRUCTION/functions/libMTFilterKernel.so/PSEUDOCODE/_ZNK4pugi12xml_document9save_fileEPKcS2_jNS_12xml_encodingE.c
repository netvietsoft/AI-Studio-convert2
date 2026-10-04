// Function: pugi::xml_document::save_file(char const*, char const*, unsigned int, pugi::xml_encoding) const
// RVA: 0x18d454, Size: 264 bytes
int64_t _ZNK4pugi12xml_document9save_fileEPKcS2_jNS_12xml_encodingE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "wb";
    fopen(...); // call PLT API at 0x18d4a8
    _ZN4pugi15xml_writer_fileC2EPv(...); // call internal at 0x18d4bc
    _ZNK4pugi12xml_document4saveERNS_10xml_writerEPKcjNS_12xml_encodingE(...); // call internal at 0x18d4d4
    ferror(...); // call PLT API at 0x18d4dc
    fclose(...); // call PLT API at 0x18d4ec
    return a0;
    fclose(...); // call PLT API at 0x18d53c
    sub_1B0544(...); // call internal at 0x18d554
    __stack_chk_fail(...); // call PLT API at 0x18d558
}
