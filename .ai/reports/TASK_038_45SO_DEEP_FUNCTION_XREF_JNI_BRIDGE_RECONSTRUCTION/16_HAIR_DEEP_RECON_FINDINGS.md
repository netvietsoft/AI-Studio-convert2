# TASK_038 — Comprehensive Hair Deep Reconstruction Findings

## 1. Objective of Analysis
Chairman Tony and Agent 0 authorized this forensic audit to uncover **why vendor/V1 hair coloring behaves differently** from Convert2 and to provide mathematical and algorithmic evidence exact enough that a future engineering task can cleanly replicate the desired natural hair color realism.

---

## 2. Core Forensic Discoveries

### Discovery 1: The 2x2 Structure Tensor Orientation Field
Vendor V1 does not blur hair colors isotropically like a Gaussian smear. Instead, Pass 2 (`HairMaskFilterToFBO`) computes a 2x2 Structure Tensor:
$$\mathbf{J} = \begin{pmatrix} g_x^2 & g_x g_y \\ g_x g_y & g_y^2 \end{pmatrix}$$
Represented in shader coordinates as double-angle vectors:
$$\vec{u} = \left(\frac{g_x^2 - g_y^2}{g_x^2 + g_y^2}, \frac{2 g_x g_y}{g_x^2 + g_y^2}\right)$$
This ensures that whether a hair strand flows upward or downward along its axis, the orientation vector is identical, preventing destructive interference when smoothed.

### Discovery 2: The 10-Tap Strand-Aligned Bilateral Filter
Pass 5 (`SoftHairFilterToFBO`) samples along the strand tangent angle:
$$\theta = \frac{1}{2} \operatorname{atan2}(u_y, u_x) + \frac{\pi}{2}$$
Sampling occurs symmetrically along $\vec{d} = (\cos\theta, \sin\theta) \cdot \text{shiftingSize}$ across 10 discrete steps with Gaussian weights:
$$W = \{1.000, 0.980, 0.923, 0.835, 0.726, 0.607, 0.487, 0.375, 0.278, 0.198\}$$
This blurs color **exclusively along individual hair strands**, never across them. Consequently, hair preserves crisp strand boundaries, natural specular highlights, and micro-pores without producing the "flat painted wall" look.

### Discovery 3: Separation of Luma from Chroma
Pass 1 isolates luminance before any dye color is composited. The Photoshop Soft Light blend curve is modulated by the underlying strand luminance rather than raw RGB, ensuring that hair highlights remain bright and deep shadow crevices remain dark.

---

## 3. Recommended Follow-Up Engineering Roadmap (TASK_040+)
1. **Shader Core Upgrade:** Integrate the reconstructed 5-pass shader pipeline into `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp` and Vulkan SPIR-V compute kernels.
2. **Double-Angle Orientation Field:** Replace isotropic Sobel operator with the Meitu Structure Tensor double-angle formulation.
3. **10-Tap Anisotropic Kernel:** Implement the exact $\sigma = 5.0$ 10-tap Gaussian strand-following loop.
4. **Scope Control:** Do not touch P0 frozen scopes. All changes must reside within the graphics post-processing pass.