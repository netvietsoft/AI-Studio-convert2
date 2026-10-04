// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20dbc
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions20setColorspaceDetailsENS_17PVGColorPrimariesENS_16PVGColorTransferENS_14PVGColorMatrixENS_13PVGColorRangeES1_S2_S3_S4_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20dbc | Size: 196 bytes | SHA256: d4814aa37eb3e7ce33bf1ea77bc37a4925516c9b7dacb6ef31383546c7087864
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8PVGCOLOR17PVGColorFunctions20setColorspaceDetailsENS_17PVGColorPrimariesENS_16PVGColorTransferENS_14PVGColorMatrixENS_13PVGColorRangeES1_S2_S3_S4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x20dbc */ cmp w1, #0x19;
    /* 0x20dc0 */ mov w8, #3;
    /* 0x20dc4 */ b.eq #0x20e78;
    /* 0x20dc8 */ cmp w5, #0x19;
    /* 0x20dcc */ b.eq #0x20e78;
    /* 0x20dd0 */ cmp w3, #0xf;
    /* 0x20dd4 */ mov w8, #4;
    /* 0x20dd8 */ b.eq #0x20e78;
    /* 0x20ddc */ cmp w7, #0xf;
    /* 0x20de0 */ b.eq #0x20e78;
    /* 0x20de4 */ cmp w2, #0x65;
    return x0;
}
