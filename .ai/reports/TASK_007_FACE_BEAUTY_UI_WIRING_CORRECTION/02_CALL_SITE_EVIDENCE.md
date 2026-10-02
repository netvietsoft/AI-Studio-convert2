# TASK_007 — Face & Beauty UI Wiring Call-Site Evidence

## 1. Summary of Source Changes
- File modified: `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`
- Target methods wired:
  - `MeituNativeEngine.nativeApplyTeethReshape` (TeethEarEngine)
  - `MeituNativeEngine.nativeApplyPhiltrumEdit` (PhiltrumEngine)
  - `MeituNativeEngine.nativeApplyEyebrowColor` (EyeRetouchEngine)
  - `MeituNativeEngine.nativeApplyEyelash` (EyelashEngine)
  - `MeituNativeEngine.nativeApplyNormalSculpting` (SurfaceNormalEngine)
  - `MeituNativeEngine.nativeApplyClavicleShoulderEdit` (ClavicleShoulderEngine)

---

## 2. Category Definition Evidence (`setupCategoriesAndTools`)

### Category `cat_mouth` — Philtrum Depth Tool Added:
```kotlin
Category("cat_mouth", "Mouth", listOf(
    Tool("tool_mouth_size", "Size"),
    Tool("tool_lip_thickness", "Thickness"),
    Tool("tool_mouth_width", "Width"),
    Tool("tool_lip_peak", "Cupid Bow"),
    Tool("tool_smile", "Smile"),
    Tool("tool_mouth_height", "Height"),
    Tool("tool_philtrum_high", "Philtrum High"),
    Tool("tool_philtrum_warp", "Philtrum Warp"),
    Tool("tool_philtrum_depth", "Philtrum Depth"),
    Tool("tool_mouth_pout", "Pout"),
    Tool("tool_mouth_corner", "Corner")
))
```

### Category `cat_makeup` — Eyebrow Colors & Procedural Eyelash Tools Added:
```kotlin
Category("cat_makeup", "Makeup", listOf(
    Tool("tool_lipstick", "Lipstick"),
    Tool("tool_blush", "Blush"),
    Tool("tool_eyebrow", "Eyebrows"),
    Tool("tool_eyeshadow", "Eyeshadow"),
    Tool("tool_eyeliner", "Eyeliner"),
    Tool("tool_eyelash", "Eyelashes"),
    Tool("tool_contour_makeup", "Contour"),
    Tool("tool_highlight", "Highlight"),
    Tool("tool_foundation", "Foundation"),
    Tool("tool_hairline", "Hairline"),
    Tool("tool_freckles", "Freckles"),
    Tool("tool_glitter", "Glitter"),
    Tool("tool_contour_nose", "Contour Nose"),
    Tool("tool_contour_wocan", "Aegyo Sal"),
    Tool("tool_brow_thickness", "Brow Thickness"),
    Tool("tool_brow_arch", "Brow Arch"),
    Tool("tool_brow_density", "Brow Density"),
    Tool("tool_brow_color_black", "Brow Black"),
    Tool("tool_brow_color_dark_brown", "Brow D-Brown"),
    Tool("tool_brow_color_light_brown", "Brow L-Brown"),
    Tool("tool_brow_color_ash_gray", "Brow Ash"),
    Tool("tool_brow_color_auburn", "Brow Auburn"),
    Tool("tool_lash_density", "Lash Density"),
    Tool("tool_lash_length", "Lash Length"),
    Tool("tool_lash_curl", "Lash Curl")
))
```

---

## 3. Dispatch Wiring Evidence (`applyTool`)

### 3.1. Teeth Reshape Dispatch (Anatomical Mode 1 & Mode 2, Factor Normalized to [-50.0..50.0]):
```kotlin
"tool_teeth_align" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val reshapeVal = p * 50.0f
    MeituNativeEngine.nativeApplyTeethReshape(workingBitmap, lmk, 1, reshapeVal)
}
"tool_teeth_protrusion" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val reshapeVal = p * 50.0f
    MeituNativeEngine.nativeApplyTeethReshape(workingBitmap, lmk, 2, reshapeVal)
}
```

### 3.2. Philtrum Edit Dispatch (Param IDs 1701, 1704, 1703):
```kotlin
"tool_philtrum_high" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1701, p)
    if (!ok) MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, 5, p)
}
"tool_philtrum_warp" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1704, p)
    if (!ok) MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, 6, p)
}
"tool_philtrum_depth" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1703, p)
}
```

### 3.3. Eyebrow Natural Color Shades (0..4):
```kotlin
"tool_brow_color_black" -> {
    MeituNativeEngine.nativeApplyEyebrowColor(workingBitmap, lxEye, lyEye, rxEye, ryEye, 0, p)
}
"tool_brow_color_dark_brown" -> {
    MeituNativeEngine.nativeApplyEyebrowColor(workingBitmap, lxEye, lyEye, rxEye, ryEye, 1, p)
}
"tool_brow_color_light_brown" -> {
    MeituNativeEngine.nativeApplyEyebrowColor(workingBitmap, lxEye, lyEye, rxEye, ryEye, 2, p)
}
"tool_brow_color_ash_gray" -> {
    MeituNativeEngine.nativeApplyEyebrowColor(workingBitmap, lxEye, lyEye, rxEye, ryEye, 3, p)
}
"tool_brow_color_auburn" -> {
    MeituNativeEngine.nativeApplyEyebrowColor(workingBitmap, lxEye, lyEye, rxEye, ryEye, 4, p)
}
```

### 3.4. Procedural Eyelash Engine Dispatch with Safe Fallback:
```kotlin
"tool_lash_density" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyEyelash(
        workingBitmap, lmk, 0, p.coerceIn(0f, 1f),
        lengthScale = 1.0f,
        densityScale = 1.0f + p.coerceIn(0f, 1f),
        curlAngle = 0.0f
    )
    if (!ok) {
        MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 6, p)
    }
}
"tool_lash_length" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyEyelash(
        workingBitmap, lmk, 0, p.coerceIn(0f, 1f),
        lengthScale = 1.0f + p.coerceIn(0f, 1.2f),
        densityScale = 1.0f,
        curlAngle = 0.0f
    )
    if (!ok) {
        MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 7, p)
    }
}
"tool_lash_curl" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyEyelash(
        workingBitmap, lmk, 0, p.coerceIn(0f, 1f),
        lengthScale = 1.0f,
        densityScale = 1.0f,
        curlAngle = p.coerceIn(0f, 1f) * 2.0f
    )
    if (!ok) {
        MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 8, p)
    }
}
```

### 3.5. Surface Normal Sculpting (Param ID 2402):
```kotlin
"tool_contour_nose" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyNormalSculpting(workingBitmap, lmk, 2402, p)
    if (!ok) {
        MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 0, p)
    }
}
```

### 3.6. Clavicle & Shoulder Editing (Param IDs 2203 & 2201):
```kotlin
"tool_body_shoulder" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val okClavicle = MeituNativeEngine.nativeApplyClavicleShoulderEdit(workingBitmap, lmk, 2203, p)
    if (!okClavicle) {
        val params = FloatArray(16)
        params[7] = p // shoulderSlim
        params[8] = p * 0.5f // shoulderBalance
        val ok = MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
        if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3007, p)
    }
}
"tool_clavicle_enhance" -> {
    val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
    val ok = MeituNativeEngine.nativeApplyClavicleShoulderEdit(workingBitmap, lmk, 2201, p)
    if (!ok) MeituNativeEngine.nativeApplyNeckClavicle(workingBitmap, lmk, 4, p)
}
```
