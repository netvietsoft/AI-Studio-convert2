// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x46c258
// Recovered Name: sub_46c258
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x46c258 | Size: 1104 bytes | SHA256: 069acfbae6ef7de95119ad2f0cdf617639302fe72a033051c7493de6cef9423a
// Callers: 0 | Callees: 4 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __dynamic_cast, memcpy
// Strings referenced:
//   "MTAi_BodyInOneBox"
//   "MTAi_BodyInOneBreast_Image"
//   "MTAi_BodyInOneContour"
//   "MTAi_BodyInOneNeck_Image"
//   "MTAi_BodyInOnePose"

void sub_46c258(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 276 instructions
    /* 0x46c258 */ mov x9, x25;
    /* 0x46c25c */ add x8, sp, #0xa68;
    /* 0x46c260 */ ldrb w10, [x9, #0x78]!;
    /* 0x46c264 */ ldp q0, q1, [x9, #-0x20];
    /* 0x46c268 */ stur q0, [x20, #0x38];
    /* 0x46c26c */ stur q1, [x20, #0x48];
    /* 0x46c270 */ tbnz w10, #0, #0x46c330;
    /* 0x46c274 */ ldr q0, [x9];
    /* 0x46c278 */ ldr x9, [x9, #0x10];
    /* 0x46c27c */ stur q0, [x8, #0x40];
    /* 0x46c280 */ stur x9, [x8, #0x50];
    sub_2bc260();
    _Znwm();
    memcpy();
    sub_2bc260();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    __dynamic_cast();
    sub_5263b0();
    _ZN11LayerFlowNS22CLFOneClickBeautyLayer19getSubFormulaLayersEv();
    _Znwm();
    sub_5263b0();
    sub_46b134();
    _ZdlPv();
}
