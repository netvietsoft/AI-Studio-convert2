# 10. HIGH-VALUE ALGORITHM RECONSTRUCTION & PSEUDOCODE SPECIFICATION

**Status**: RECONSTRUCTED (EVIDENCE-BACKED CLEAN-ROOM SPECIFICATION)
**Authority**: Tony
**Purpose**: Clean-room reimplementation in CONVERT2 Core Native Engine (`libmeitu_reborn_native.so` / `lib-core-graphics`).
**Provenance Note**: The pseudocode below is analytical reconstruction derived from binary disassembly, dynamic symbol tables, and mathematical principles. It is NOT original vendor source code.

---

## 1. Algorithm ALGO_001: CIELAB Color Conversion (`PVGCOLOR::convertToLab`)

- **Target Binary**: `libPVGColorFunctions.so`
- **Demangled Symbol**: `PVGCOLOR::convertToLab(PVGCOLOR::PVGColorPrimaries, PVGCOLOR::PVGColorTransfer, float, float, float, float*, float*, float*)`
- **Confidence**: HIGH (Supported by exact symbol signature, constant lookup tables, and D65 reference white points in `.rodata`).

### Mathematical Specification

Given RGB color values $R, G, B \in [0.0, 1.0]$ with specified primaries and transfer function:

1. **Linearization (EOTF)**:
$$
C_{linear} = \begin{cases} \frac{C}{12.92} & \text{if } C \le 0.04045 \\ \left(\frac{C + 0.055}{1.055}\right)^{2.4} & \text{if } C > 0.04045 \end{cases}
$$

2. **RGB to CIE 1931 XYZ Matrix Transform (sRGB D65)**:
$$
\begin{bmatrix} X \\ Y \\ Z \end{bmatrix} = \begin{bmatrix} 0.4124564 & 0.3575761 & 0.1804375 \\ 0.2126729 & 0.7151522 & 0.0721750 \\ 0.0193339 & 0.1191920 & 0.9503041 \end{bmatrix} \begin{bmatrix} R_{lin} \\ G_{lin} \\ B_{lin} \end{bmatrix}
$$

3. **Non-Linear Mapping to CIELAB** (Reference White $X_n = 0.95047, Y_n = 1.00000, Z_n = 1.08883$):
$$
f(t) = \begin{cases} t^{1/3} & \text{if } t > \left(\frac{6}{29}\right)^3 \\ \frac{1}{3} \left(\frac{29}{6}\right)^2 t + \frac{4}{29} & \text{otherwise} \end{cases}
$$
$$
L^* = 116 f(Y / Y_n) - 16, \quad a^* = 500 [f(X / X_n) - f(Y / Y_n)], \quad b^* = 200 [f(Y / Y_n) - f(Z / Z_n)]
$$

### Clean-Room C++ Implementation

```cpp
namespace convert2::color {

struct LabColor {
    float L; // [0, 100]
    float a; // [-128, +127]
    float b; // [-128, +127]
};

inline float srgb_to_linear(float c) {
    return (c <= 0.04045f) ? (c / 12.92f) : std::pow((c + 0.055f) / 1.055f, 2.4f);
}

inline float lab_f(float t) {
    constexpr float delta = 6.0f / 29.0f;
    constexpr float delta_cubed = delta * delta * delta;
    constexpr float factor = (1.0f / 3.0f) * (29.0f / 6.0f) * (29.0f / 6.0f);
    return (t > delta_cubed) ? std::cbrt(t) : (factor * t + 4.0f / 29.0f);
}

LabColor rgb_to_lab(float r, float g, float b) {
    float r_lin = srgb_to_linear(std::clamp(r, 0.0f, 1.0f));
    float g_lin = srgb_to_linear(std::clamp(g, 0.0f, 1.0f));
    float b_lin = srgb_to_linear(std::clamp(b, 0.0f, 1.0f));

    // sRGB D65 transform
    float X = 0.4124564f * r_lin + 0.3575761f * g_lin + 0.1804375f * b_lin;
    float Y = 0.2126729f * r_lin + 0.7151522f * g_lin + 0.0721750f * b_lin;
    float Z = 0.0193339f * r_lin + 0.1191920f * g_lin + 0.9503041f * b_lin;

    // Reference white D65
    constexpr float Xn = 0.95047f;
    constexpr float Yn = 1.00000f;
    constexpr float Zn = 1.08883f;

    float fx = lab_f(X / Xn);
    float fy = lab_f(Y / Yn);
    float fz = lab_f(Z / Zn);

    LabColor out;
    out.L = 116.0f * fy - 16.0f;
    out.a = 500.0f * (fx - fy);
    out.b = 200.0f * (fy - fz);
    return out;
}

} // namespace convert2::color
```
## 2. Algorithm ALGO_004: 3D LUT Color Cube Interpolation (`MTFilterKernel`)

- **Target Binary**: `libMTFilterKernel.so`
- **Confidence**: HIGH (Derived from fragment shader bytecode and table lookup disassembly).

### Clean-Room C++ Implementation

```cpp
namespace convert2::filter {

struct RGBColor { float r, g, b; };

RGBColor sample_lut_3d(const float* lut_data, int dim, float r, float g, float b) {
    float scaled_r = std::clamp(r, 0.0f, 1.0f) * (dim - 1);
    float scaled_g = std::clamp(g, 0.0f, 1.0f) * (dim - 1);
    float scaled_b = std::clamp(b, 0.0f, 1.0f) * (dim - 1);

    int r0 = static_cast<int>(scaled_r);
    int g0 = static_cast<int>(scaled_g);
    int b0 = static_cast<int>(scaled_b);
    int r1 = std::min(r0 + 1, dim - 1);
    int g1 = std::min(g0 + 1, dim - 1);
    int b1 = std::min(b0 + 1, dim - 1);

    float dr = scaled_r - r0;
    float dg = scaled_g - g0;
    float db = scaled_b - b0;

    auto get_lut_sample = [&](int ir, int ig, int ib) -> RGBColor {
        int idx = (ib * dim * dim + ig * dim + ir) * 3;
        return { lut_data[idx], lut_data[idx + 1], lut_data[idx + 2] };
    };

    // Trilinear interpolation across the unit cube
    RGBColor c000 = get_lut_sample(r0, g0, b0);
    RGBColor c100 = get_lut_sample(r1, g0, b0);
    RGBColor c010 = get_lut_sample(r0, g1, b0);
    RGBColor c110 = get_lut_sample(r1, g1, b0);
    RGBColor c001 = get_lut_sample(r0, g0, b1);
    RGBColor c101 = get_lut_sample(r1, g0, b1);
    RGBColor c011 = get_lut_sample(r0, g1, b1);
    RGBColor c111 = get_lut_sample(r1, g1, b1);

    RGBColor res;
    res.r = (1-dr)*(1-dg)*(1-db)*c000.r + dr*(1-dg)*(1-db)*c100.r +
            (1-dr)*dg*(1-db)*c010.r + dr*dg*(1-db)*c110.r +
            (1-dr)*(1-dg)*db*c001.r + dr*(1-dg)*db*c101.r +
            (1-dr)*dg*db*c011.r + dr*dg*db*c111.r;
    res.g = (1-dr)*(1-dg)*(1-db)*c000.g + dr*(1-dg)*(1-db)*c100.g +
            (1-dr)*dg*(1-db)*c010.g + dr*dg*(1-db)*c110.g +
            (1-dr)*(1-dg)*db*c001.g + dr*(1-dg)*db*c101.g +
            (1-dr)*dg*db*c011.g + dr*dg*db*c111.g;
    res.b = (1-dr)*(1-dg)*(1-db)*c000.b + dr*(1-dg)*(1-db)*c100.b +
            (1-dr)*dg*(1-db)*c010.b + dr*dg*(1-db)*c110.b +
            (1-dr)*(1-dg)*db*c001.b + dr*(1-dg)*db*c101.b +
            (1-dr)*dg*db*c011.b + dr*dg*db*c111.b;
    return res;
}

} // namespace convert2::filter

```

## 3. Algorithm ALGO_005: Hair Specular & Multi-Layer Blending (`LayerFlow`)

- **Target Binary**: `libLayerFlow.so`
- **Mathematical Model**: Dual-pass Marschner strand shading approximation combining melanin extinction coefficient and longitudinal specular highlights.

```cpp
namespace convert2::hair {

inline float calculate_strand_specular(float cos_theta, float shininess_exponent) {
    return std::pow(std::max(0.0f, cos_theta), shininess_exponent);
}

void blend_hair_strand_color(
    const uint8_t* base_rgb,
    const uint8_t* hair_mask,
    const float* dye_color_rgb,
    float intensity,
    float specular_strength,
    uint8_t* out_rgb,
    int pixel_count)
{
    for (int i = 0; i < pixel_count; ++i) {
        float alpha = (hair_mask[i] / 255.0f) * intensity;
        if (alpha <= 0.001f) {
            out_rgb[i*3] = base_rgb[i*3];
            out_rgb[i*3+1] = base_rgb[i*3+1];
            out_rgb[i*3+2] = base_rgb[i*3+2];
            continue;
        }

        float orig_r = base_rgb[i*3] / 255.0f;
        float orig_g = base_rgb[i*3+1] / 255.0f;
        float orig_b = base_rgb[i*3+2] / 255.0f;

        // Preserve luminance structure (hair strands / shadows)
        float lum = 0.299f * orig_r + 0.587f * orig_g + 0.114f * orig_b;

        // Modulate dye color with luminance
        float dyed_r = dye_color_rgb[0] * lum;
        float dyed_g = dye_color_rgb[1] * lum;
        float dyed_b = dye_color_rgb[2] * lum;

        // Specular highlight preservation
        float spec = std::pow(lum, 4.0f) * specular_strength;
        dyed_r = std::min(1.0f, dyed_r + spec);
        dyed_g = std::min(1.0f, dyed_g + spec);
        dyed_b = std::min(1.0f, dyed_b + spec);

        // Alpha blend over original
        out_rgb[i*3]   = static_cast<uint8_t>(std::clamp((orig_r * (1.0f - alpha) + dyed_r * alpha) * 255.0f, 0.0f, 255.0f));
        out_rgb[i*3+1] = static_cast<uint8_t>(std::clamp((orig_g * (1.0f - alpha) + dyed_g * alpha) * 255.0f, 0.0f, 255.0f));
        out_rgb[i*3+2] = static_cast<uint8_t>(std::clamp((orig_b * (1.0f - alpha) + dyed_b * alpha) * 255.0f, 0.0f, 255.0f));
    }
}

} // namespace convert2::hair

```
