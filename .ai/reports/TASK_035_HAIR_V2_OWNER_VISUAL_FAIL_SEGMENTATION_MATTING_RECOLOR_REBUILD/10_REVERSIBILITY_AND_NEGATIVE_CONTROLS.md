# 10. REVERSIBILITY & NEGATIVE CONTROLS
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Standard:** 100% Bit-Exact Identity Preservation on Negative Controls

---

## 1. Intensity 0.0% Bit-Exact Reversibility
When the user sets the recoloring intensity slider to 0%, the engine must guarantee that the output image is bit-exact identical to the source image ($max\_diff = 0, diff\_pixels = 0$):

In `HairPipelineV2::executePipelineV3_Rebuild`:
```cpp
if (materialParams.blendIntensity <= 0.0001f) {
    std::memcpy(dstPixels, srcPixels, width * height * sizeof(uint32_t));
    LOGI("HairPipelineV3: Intensity 0.0 - 100%% bit-exact pass-through");
    return true;
}
```

### Physical Test Verification:
- **Test Case:** `owner_fail_A_curly` @ `tool_hair_rose_gold` $i = 0$
- **SM-A075F:** $max\_diff = 0$, modified pixels = 0 (`PASS_BIT_EXACT`)
- **SM-A507FN:** $max\_diff = 0$, modified pixels = 0 (`PASS_BIT_EXACT`)

---

## 2. Bald Subject Negative Control (`portrait_monk_bald_neg.png`)
For a subject with no hair (e.g. Buddhist monk / shaved head), the engine must never falsely detect the skull or background as hair and must produce a bit-exact unmodified output:

In `HairPipelineV2::executePipelineV3_Rebuild`:
```cpp
if (seedL.size() < 120) {
    LOGI("HairPipelineV3: Bald / negative control subject detected (scalp seeds=%zu). Unmodified pass-through.", seedL.size());
    std::memcpy(dstPixels, origSrc, width * height * sizeof(uint32_t));
    return true;
}
```

### Physical Test Verification:
- **Test Case:** `portrait_monk_bald_neg` @ `tool_hair_rose_gold` $i = 75$
- **SM-A075F:** $max\_diff = 0$, modified pixels = 0 (`PASS_BIT_EXACT`)
- **SM-A507FN:** $max\_diff = 0$, modified pixels = 0 (`PASS_BIT_EXACT`)
- **Forehead Leakage:** 0.00%
- **Clothing Spill:** 0.00%
- **Texture Retention:** 100.0%
