# FUNCTION DOSSIER: FN_002 grayFilterToFBO
- **SO Name:** `libMTFilterKernel.so`
- **Offset:** `0x000f42fc`
- **Demangled Symbol:** `MTFilterKernel::MTSoftHairFilter::grayFilterToFBO`
- **Instruction Count:** 84
- **Domain:** HAIR_COLOR_RENDER_ENGINE
- **Maturity:** LEVEL_5_REIMPLEMENTABLE
- **Confidence:** PROVEN
- **Formula:** ITU-R BT.601 `dot(color.rgb, vec3(0.299, 0.587, 0.114))`
