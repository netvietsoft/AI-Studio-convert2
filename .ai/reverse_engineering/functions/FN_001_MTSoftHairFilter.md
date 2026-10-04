# FUNCTION DOSSIER: FN_001 MTSoftHairFilter::renderToTexture
- **SO Name:** `libMTFilterKernel.so`
- **Offset:** `0x000f3f58`
- **Mangled Symbol:** `_ZN14MTFilterKernel16MTSoftHairFilter51renderToTextureWithVerticesAndTextureCoordinatesEPKfS2_PNS_19GPUImageFramebufferES4_RKNS_18MTImgTextureMangerE`
- **Demangled Symbol:** `MTFilterKernel::MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates`
- **Architecture:** ARM64 little-endian ELF64
- **Instruction Count:** 164
- **Basic Blocks:** 12
- **Cyclomatic Complexity:** 8
- **Domain:** HAIR_COLOR_RENDER_ENGINE
- **Maturity:** LEVEL_5_REIMPLEMENTABLE
- **Confidence:** PROVEN
- **5 Pass Sequence:**
  1. `grayFilterToFBO` (0xf42fc)
  2. `hairMaskFilterToFBO` (0xf4400)
  3. `blurHFilterToFBO` (0xf4528)
  4. `blurVFilterToFBO` (0xf46d0)
  5. `softHairFilterToFBO` (0xf4878)
