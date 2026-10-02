# P0 HAIR MATTE OUTPUT CONTRACT SPECIFICATION

**Phase:** P0-C — Production Integration & Final P0 Acceptance  
**Document:** `P0_HAIR_MATTE_OUTPUT_CONTRACT.md`  
**Purpose:** Formal contract governing the output matte produced by Phase P0 Hair Matting Engine for downstream consumption by Phase P1 (Hair Orientation/Flow), Phase P2-P6 (Texture, Specular, Material, GPU), and the existing Hair Dye Pipeline.

---

## 1. Technical Contract Specification

```
HairMatteContract {
    dataType:               float (IEEE 754 single precision)
    valueRange:             [0.0f, 1.0f] continuous
    width:                  Image Width W (int, > 0)
    height:                 Image Height H (int, > 0)
    channelCount:           1 (Monochrome Alpha)
    coordinateSpace:        Row-major raster, top-left origin (0, 0)
    rowStrideBytes:         W * sizeof(float)
    memoryBuffer:           std::vector<float>(W * H)
    bufferOwnership:        Caller-allocated or callee-resized, caller lifecycle
    threadSafety:           Thread-safe re-entrant execution (no static state mutation)
    executionMode:          Synchronous CPU (OpenMP multi-threaded)
}
```

---

## 2. Value Semantics & Boundary Invariants

| Alpha Value | Physical Semantic | Downstream Rendering Action | Invariant Rule |
| :---: | :--- | :--- | :--- |
| **`0.000f`** | **Protected Non-Hair** | Zero color modification, 100% original pixel preservation | Hard guarantee on eyes, nose, lips, neck, clothes, UI toolbars |
| **`1.000f`** | **Definite Hair Core** | Full dye blend, texture synthesis, directional flow | Guaranteed within confirmed hair interior ($\ge 75\%$ core preservation) |
| **`(0.0f, 1.0f)`** | **Sub-pixel Boundary** | Continuous alpha compositing, soft optical blending | Monotonic transition at hairline, fine strands, and flyaways |

---

## 3. Boundary & Edge Case Contracts

### 3.1 Bald / Shaved Scalp Negative Contract
- If an image contains a bald head, shaved scalp, or monk portrait with no hair strands, the engine must return $\alpha(x, y) = 0.0f$ uniformly across the scalp.
- Downstream color dye engines will apply 0% color modification.

### 3.2 Mobile Screenshot & UI Chrome Contract
- If the image contains mobile operating system toolbars, sliders, status bars, or navigation buttons, `ImageContentGuard` strictly forces $\alpha(x, y) = 0.0f$ across all UI regions ($M_{\text{ui}} \le 1.0\%$ gate).

### 3.3 Border-Touching Hair Contract
- Real hair strands that naturally touch the top or side borders of the camera frame are validated via `SubjectGraph` and preserved up to the frame edge.

### 3.4 Multi-Person Contract
- In portraits with multiple individuals, `SubjectGraph` decomposes independent face clusters and ensures hair masses do not bleed across boundaries between subjects.

---

## 4. Failure & Fallback Protocol
- **Input Error:** If `pixels == nullptr` or $W \le 0$ or $H \le 0$, return `false` immediately with error logging.
- **Model Unavailable:** If BiSeNet NCNN model is uninitialized, the engine executes a deterministic landmark-guided elliptical fallback matte and logs an operational warning.
- **Zero Crash Guarantee:** Under no condition shall an invalid image or corrupt input cause a native segfault, buffer overflow, or unhandled exception.
