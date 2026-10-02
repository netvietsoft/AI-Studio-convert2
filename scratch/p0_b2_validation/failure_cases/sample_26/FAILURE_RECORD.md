# FAILURE CASE: sample_26
- **Dataset Role:** Regression
- **Failure Type:** HAIR_CORE_LOSS
- **Description:** Low Core Preservation: 73.3% (< 75.0% threshold)
- **Root Cause:** Semantic anchor failure in BiSeNet 19-class model on non-standard aspect ratio and UI-laden mobile screenshot.
- **Evidence:** See 01_original.png, 05_p0_b2_alpha.png, 08_p0_b2_composite.png, 11_background_or_ui_crop.png.
- **Mitigation/Suggested Fix:** Classical boundary heuristic cannot overcome semantic misclassification of background as headwear when aspect ratio is extreme (2.22:1). Requires dedicated lightweight portrait cropping/normalization prior to BiSeNet or Phase P0-D Model Replacement.
