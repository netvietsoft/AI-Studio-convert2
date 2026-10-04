// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x312058
// Recovered Name: sub_312058
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x312058 | Size: 284 bytes | SHA256: e4885b3186d274529ebe61d9c7d37eb8e2aaf1909e7dde6cef6aee14ca3ebc3a
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "hairCleanAlpha"
//   "optType"
//   "skinCleanAlpha"

void sub_312058(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0x312058 */ stp x29, x30, [sp, #0x40];
    /* 0x31205c */ str x25, [sp, #0x50];
    /* 0x312060 */ stp x24, x23, [sp, #0x60];
    /* 0x312064 */ stp x22, x21, [sp, #0x70];
    /* 0x312068 */ stp x20, x19, [sp, #0x80];
    /* 0x31206c */ add x29, sp, #0x40;
    /* 0x312070 */ mrs x25, tpidr_el0;
    /* 0x312074 */ mov x19, x3;
    /* 0x312078 */ ldr x8, [x25, #0x28];
    /* 0x31207c */ cmp x1, x2;
    /* 0x312080 */ stur x8, [x29, #-8];
    _ZN8nlohmann16extended_to_jsonIdEEvRNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRKT_();
    _ZN8nlohmann16extended_to_jsonIdEEvRNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRKT_();
    _ZN8nlohmann16extended_to_jsonIiEEvRNS_16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS3_6vectorENS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEblmdS9_NS1_14adl_serializerENS5_IhNS9_IhEEEEvEEPKcRKT_();
    return x0;
    _ZN8nlohmann16json_abi_v3_12_010basic_jsonINSt6__ndk13mapENS2_6vectorENS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEblmdS8_NS0_14adl_serializerENS4_IhNS8_IhEEEEvE4dataD2Ev();
    sub_2fc370();
    sub_526544();
    __stack_chk_fail();
}
