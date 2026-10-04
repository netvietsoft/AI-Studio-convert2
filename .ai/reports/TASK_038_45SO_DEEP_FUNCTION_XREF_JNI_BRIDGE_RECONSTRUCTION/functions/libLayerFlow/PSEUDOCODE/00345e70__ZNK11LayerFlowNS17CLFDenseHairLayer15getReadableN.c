// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x345e70
// Recovered Name: _ZNK11LayerFlowNS17CLFDenseHairLayer15getReadableNameEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x345e70 | Size: 36 bytes | SHA256: 31be4d5194f40aebe69b328b9a2c98e826ad4e15a28124fdd0cfb3e0b29fc067
// Callers: 0 | Callees: 0 | Imports: 0

// Strings referenced:
//   "denseHair"

void _ZNK11LayerFlowNS17CLFDenseHairLayer15getReadableNameEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x345e70 */ mov w9, #0x12;
    /* 0x345e74 */ adrp x10, #0x1e8000;
    /* 0x345e78 */ add x10, x10, #0x37e;
    /* 0x345e7c */ strb w9, [x8];
    /* 0x345e80 */ ldr x9, [x10];
    /* 0x345e84 */ mov w11, #0x72;
    /* 0x345e88 */ sturh w11, [x8, #9];
    /* 0x345e8c */ stur x9, [x8, #1];
    return x0;
}
