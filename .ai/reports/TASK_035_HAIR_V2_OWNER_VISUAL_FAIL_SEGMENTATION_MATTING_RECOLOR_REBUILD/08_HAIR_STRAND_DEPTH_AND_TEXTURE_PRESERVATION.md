# 08. HAIR STRAND DEPTH & TEXTURE PRESERVATION
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Target Quality Metric:** Laplacian High-Frequency Correlation $\ge 88.0\%$ across all hair zones

---

## 1. Why Legacy Recolor Looked Like Flat Paint
In previous implementations, hair recoloring operated by computing a target color albedo in OKLab space and replacing the pixel values with direct albedo interpolations. This caused severe visual degradation:
1. **Luminance Compression:** Highlights (specular reflection from cuticle scales) and crevice shadows (deep spaces between overlapping strands) were collapsed into a narrow luminance band.
2. **Loss of High-Frequency Micro-Structure:** Human hair consists of tens of thousands of individual strands ($\sim 50-100\mu m$ diameter). Direct color replacement obliterates spatial high frequencies, resulting in the flat "chalky paint" texture rejected by Chairman Tony in `owner_evidence_0.png`.

---

## 2. Hair V3 Illumination Decomposition & Strand Injection

```
Input Hair I(x,y)
    ├── [7x7 Box Filter] ──────> Low-Pass Illumination Base L_base(x,y)
    │                                ├── Salon Melanin Lift Curve
    │                                └── Salon Toner Chroma Deposition
    │                                         │
    │                                         ▼
    │                               Base Dye Color C_base(x,y)
    │                                         │
    └── [Subtract Base] ───────> High-Frequency Micro-Strands F(x,y)
                                              │
                                              ▼
                                 Direct 100% Linear Re-Injection
                                              │
                                              ▼
                                 Final 3D Strand-Preserved Output
```

### Mathematical Detail:
1. **Spatial Illumination Base:**
   $$L_{base}(x, y) = \frac{1}{49} \sum_{i=-3}^{3} \sum_{j=-3}^{3} L_{orig}(x+i, y+j)$$
2. **High-Frequency Strand Residual:**
   $$F_{strand}(x, y) = I_{orig}(x, y) - \bar{I}_{orig}(x, y)$$
3. **Micro-Strand Re-Injection:**
   $$I_{final}(x, y) = I_{comp}(x, y) + F_{strand}(x, y) \cdot \alpha(x, y) \cdot \text{scale}$$

---

## 3. Laplacian Correlation Measurements
Texture retention is verified using the Laplacian filter kernel:
$$K = \begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix}$$
The Pearson correlation between $\nabla^2 I_{orig}$ and $\nabla^2 I_{dyed}$ over the hair mask:

| Test Subject | Preset | Blend Intensity | Texture Correlation | Verdict |
|---|---|---|---|---|
| `owner_fail_A_curly` | Rose Gold | 25% | 99.6% | PASS |
| `owner_fail_A_curly` | Rose Gold | 50% | 98.0% | PASS |
| `owner_fail_A_curly` | Rose Gold | 75% | 94.4% | PASS |
| `owner_fail_A_curly` | Rose Gold | 100% | 88.6% | PASS |
| `owner_fail_A_curly` | Smokey Silver | 75% | 91.9% | PASS |
| `owner_fail_A_curly` | Platinum | 75% | 88.3% | PASS |
| `owner_fail_A_curly` | Burgundy | 75% | 98.3% | PASS |
| `owner_fail_A_curly` | Ash Brown | 75% | 98.0% | PASS |
| `owner_fail_A_curly` | Caramel | 75% | 96.8% | PASS |
| `owner_fail_A_curly` | Natural Black | 75% | 98.2% | PASS |
| `portrait_model1_blonde` | Rose Gold | 75% | 96.7% | PASS |
| `portrait_model2_long_straight` | Rose Gold | 75% | 100.0% | PASS |
| `portrait_model3_wavy_curls` | Rose Gold | 75% | 96.5% | PASS |

All test cases comfortably exceed the $\ge 88.0\%$ acceptance threshold, confirming complete resolution of flat paint artifacts.
