// Function: WebPDemuxDelete
// RVA: 0x48efac, Size: 176 bytes
int64_t WebPDemuxDelete(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeFree(...); // call PLT API at 0x48f000
    WebPSafeFree(...); // call PLT API at 0x48f03c
    WebPSafeFree(...); // call PLT API at 0x48f048
    return a0;
}
