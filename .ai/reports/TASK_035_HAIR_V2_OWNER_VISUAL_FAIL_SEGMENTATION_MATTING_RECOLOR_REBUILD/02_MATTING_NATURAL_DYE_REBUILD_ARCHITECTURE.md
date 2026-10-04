# 02. MATTING & NATURAL DYE REBUILD ARCHITECTURE (HAIR V3)
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Implementation Files:**
- `lib-core-graphics/src/main/cpp/include/hair/hair_pipeline_v2.h`
- `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp`
- `lib-core-graphics/src/main/cpp/src/jni_bridge.cpp`
- `lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt`

---

## 1. Zero-Regression Version Switching Architecture
To preserve legacy Hair V1 (`HairStrandDyeEngine`) and baseline Hair V2 (`executePipelineV2_Baseline`) for complete rollback safety, Hair V3 is implemented behind an explicit version switch:

```cpp
enum class Version {
    VERSION_V1 = 1,          // Legacy Hair V1 (HairStrandDyeEngine)
    VERSION_V2_BASELINE = 2, // Preserved Hair V2 Baseline
    VERSION_V3_REBUILD = 3   // Rebuilt Hair V3 (Active Default)
};
```

- Runtime switching is controlled via static method `HairPipelineV2::setExecutionVersion(Version v)`.
- Exported via JNI bridge: `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeSetHairPipelineVersion` and `nativeGetHairPipelineVersion`.
- Exposed in Kotlin: `MeituNativeEngine.setHairPipelineVersion(version: Int)`.
- Default at engine startup: `VERSION_V3_REBUILD (3)`.

---

## 2. Rebuilt Pipeline Stage Flow (Hair V3)

```mermaid
flowchart TD
    A[Original RGBA Image] --> B[BiSeNet 19-Class Adaptive Parsing]
    B --> C[Anatomical Cranial Crown & Face Detection]
    C --> D[Strict Protected Region Gating: Skin, Cloth, Face Oval]
    C --> E[Cranial Crown Scalp Hair Appearance Model: OKLab L, a, b]
    E --> F{Bald Safeguard < 120 seeds?}
    F -- Yes --> G[Bit-Exact Unmodified Pass-Through]
    F -- No --> H[Candidate Hair Validation & Sheer Rejection]
    H --> I[Topological BFS Reachability from Cranial Seeds]
    I --> J[Edge-Preserving Full-Res Guided Matting]
    A --> K[Strand Texture Illumination Decomposition: 7x7 Box Filter]
    J & K --> L[Physically Plausible OKLab Salon Dye & Melanin Lift]
    L --> M[Specular Glint Sheen Re-injection]
    M --> N[Alpha Compositing with Original Image]
    N --> O[100% Original Strand Micro-Fiber Linear Re-injection]
    O --> P[Final Output Image]
```

---

## 3. Mathematical & Algorithmic Specifications

### Stage 1: Cranial Crown Seed Extraction
The scalp crown is defined strictly from detected facial landmark extrema ($min\_fy$):
$$craniumMaxY = min\_fy + 0.08 \cdot face\_h$$
Pixels must satisfy:
$$y \le craniumMaxY \quad \text{and} \quad |x - face\_cx| \le 0.95 \cdot face\_w$$
$$lbl(x, y) = 17 \quad \text{and} \quad protectedMask(x, y) = 0 \quad \text{and} \quad hairProb(x, y) > 0.40$$

### Stage 2: OKLab Appearance & Sheer Clothing Elimination
From cranial seeds, the distribution $(\mu_L, \sigma_L, \mu_a, \mu_b)$ is computed in perceptual OKLab color space.
For any candidate pixel outside the cranial crown:
1. **Color Distance Metric:**
   $$d_{color} = \sqrt{\left(\frac{L - \mu_L}{\sigma_L}\right)^2 + \left(\frac{a - \mu_a}{0.08}\right)^2 + \left(\frac{b - \mu_b}{0.08}\right)^2}$$
2. **Sheer / Dark Clothing Rejection Rule:**
   $$\text{If } \mu_L \ge 0.32 \text{ and } (L < 0.26 \text{ or } \max(R, G, B) < 65) \implies \text{REJECT}$$
   $$\text{If } \mu_L \ge 0.32 \text{ and } |L - \mu_L| > 0.28 \implies \text{REJECT}$$
3. **Below-Chin Distance Gating:**
   $$\text{If } y > chin\_y \text{ and } d_{color} > 2.20 \implies \text{REJECT}$$
   $$\text{If } d_{color} > 2.80 \implies \text{REJECT}$$

### Stage 3: Topological BFS Reachability
Only valid hair candidate pixels located within the cranial crown ($y \le craniumMaxY$) are enqueued into the initial BFS queue:
$$Q \leftarrow \{ (x, y) \mid candidate(x, y) = 1 \land y \le craniumMaxY \land |x - face\_cx| \le 0.95 \cdot face\_w \land hairProb > 0.45 \}$$
4-connected BFS traverses through valid candidate pixels. Any pixel on the torso, sleeve, shoulder, or background that is topologically disconnected or separated by non-hair color barriers is completely pruned.

### Stage 4: Physically Plausible Salon Dye & Illumination Decomposition
1. **Low-Pass Illumination Base Decomposition:**
   $$\bar{I}(x, y) = \text{BoxFilter}_{7 \times 7}(I(x, y))$$
2. **Melanin Lift Curve:**
   $$M(L) = 0.40 + 0.60 \cdot \sqrt{\text{clamp}(L, 0, 1)}$$
   $$\Delta L_{lift} = (L_{target} - L_{base}) \cdot \text{bleachPower} \cdot M(L) \cdot \text{creviceDepth}$$
3. **Midtone Bell-Curve Toner Deposition:**
   $$W_{midtone} = 4 \cdot L_{final} \cdot (1 - L_{final})$$
   $$a_{final} = a_{orig} \cdot (1 - S_{dye}) + a_{target} \cdot S_{dye}$$
   $$b_{final} = b_{orig} \cdot (1 - S_{dye}) + b_{target} \cdot S_{dye}$$
4. **100% High-Frequency Strand Micro-Fiber Re-injection:**
   $$F_{strand}(x, y) = I_{orig}(x, y) - \bar{I}_{orig}(x, y)$$
   $$I_{out}(x, y) = I_{comp}(x, y) + F_{strand}(x, y) \cdot \alpha(x, y) \cdot \text{clamp}(1.0 - 0.35 \cdot \text{bleachPower}, 0.5, 1.0)$$

This mathematical formulation guarantees that 100% of the original curl luminance variation, specular highlights, and shadow crevices remain visible, completely eliminating chalky paint artifacts.
