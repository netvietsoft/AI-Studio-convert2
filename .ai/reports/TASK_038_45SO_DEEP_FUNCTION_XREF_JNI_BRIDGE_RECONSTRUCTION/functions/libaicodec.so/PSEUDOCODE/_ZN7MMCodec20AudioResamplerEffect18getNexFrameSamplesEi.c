// Function: MMCodec::AudioResamplerEffect::getNexFrameSamples(int)
// RVA: 0xed454, Size: 80 bytes
int64_t _ZN7MMCodec20AudioResamplerEffect18getNexFrameSamplesEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    swr_get_delay(...); // call imported API via PLT at 0xed478
    av_rescale_rnd(...); // call imported API via PLT at 0xed48c
    return a0;
    return a0;
}
