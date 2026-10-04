# 16 — HAIR DEEP RECONSTRUCTION SYNTHESIS & FINDINGS

### Core Forensic Findings

1. **Why Vendor Hair Looks Physically Realistic While Initial Reconstructions Suffered:**
   - Vendor does **NOT** recolor in Oklab / Lab uniform chroma shift. Instead, vendor uses a specialized **Pegtop Soft Light** equation on the luminance channel, modulated by high-frequency strand micro-contrast.
   - Hair edge feathering is performed by a dedicated **13-tap separable Gaussian blur** ($W = [0.046118 .. 0.100731]$), preventing the sharp halo or blocky box-filter artifacts seen in CPU approximations.
   - Specular glints and highlights are preserved through a **dual tone-curve LUT mapping** (`s_lightLutMap` and `s_vibranceLutMap`), ensuring that bleached or brightly lit blonde/rose gold strands retain gloss without turning pastel chalk.

2. **Zero Leakage Protection:**
   - Vendor binds the neural segmentation mask directly from `libManis.so` (BiSeNet Class 17) and enforces strict skin-luminance gating in `HairMaskFilterToFBO`, ensuring zero dye seepage onto skin, forehead, or ears.

3. **Frozen Contract Preservation:**
   - P0 contract (`tau_aspect = 1.80`) is strictly preserved and consumed via adapter.
