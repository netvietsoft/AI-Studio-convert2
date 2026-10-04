# 09. NATURAL SALON DYE REALISM EVIDENCE
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Standard:** Physically Plausible Salon Tone Mapping (OKLab)

---

## 1. Salon Dye Formulations
The Hair V3 engine incorporates a calibrated palette of professional salon dyes designed to match high-end salon formulations:

| Tool ID | Display Name | Target L | Target a | Target b | Bleach Power | Deposition Behavior |
|---|---|---|---|---|---|---|
| `tool_hair_smokey_silver` | Smokey Silver | 0.68 | -0.01 | -0.02 | 0.85 | Cool ash silver with neutral reflections |
| `tool_hair_platinum` | Platinum Blonde | 0.78 | 0.01 | 0.05 | 0.92 | High-lift pale blonde preserving highlight sheen |
| `tool_hair_rose_gold` | Rose Gold | 0.62 | 0.12 | 0.08 | 0.70 | Warm pink-gold balanced tone |
| `tool_hair_burgundy` | Burgundy Red | 0.38 | 0.16 | 0.04 | 0.45 | Rich deep wine with dimensional shadow depth |
| `tool_hair_ash_brown` | Ash Brown | 0.45 | 0.02 | 0.04 | 0.40 | Natural cool brown tone |
| `tool_hair_caramel` | Caramel Honey | 0.55 | 0.06 | 0.14 | 0.60 | Golden amber warm multi-tone |
| `tool_hair_natural_black` | Natural Black | 0.22 | 0.00 | 0.01 | 0.15 | Deep natural espresso brunette |

---

## 2. Multi-Tone Highlights & Specular Sheen Preservation
Real hair dyed in a salon does not have uniform single-frequency color. It reflects ambient lighting via Fresnel reflection off cuticle plates:
- **Cuticle Specular Sheen:** Hair V3 extracts an anisotropic highlight map $S(x, y)$ from high-luminance peaks of the original hair.
- **Translucent Blend:** The specular glint is blended into the final dyed hair with neutral tint preservation:
  $$I_{sheen}(x, y) = I_{dye}(x, y) \cdot (1 - S_{sheen}) + I_{orig}(x, y) \cdot S_{sheen}$$
- Result: Hair retains authentic silky sheen and reacts dynamically to ambient scene lighting.
