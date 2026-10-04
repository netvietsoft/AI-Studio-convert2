# JNI & REGISTER_NATIVES FORENSIC EVIDENCE LOG
- **Dynamic Registration Mechanism:** `libLayerFlow.so` uses `JNI_OnLoad` dynamic `(*env)->RegisterNatives()` table.
- **Classes Registered:**
  - `com/layer/flow/datas/LFEffectDenseHairData$DenseHairInfo`
  - `com/layer/flow/datas/LFEffectDenseHairData$DenseHairModular`
- **Exported Symbols in `libMTFilterKernel.so`:**
  - `Java_com_meitu_mtimagekit_filters_specialFilters_abHairFilter_MTIKABHairFilter_nSetTraditionHairDyeIntensityAndShine`
  - `Java_com_meitu_mtimagekit_filters_specialFilters_abHairFilter_MTIKABHairFilter_nGetHairEffectMaterialConfigInfo`
  - `Java_com_meitu_mtimagekit_filters_specialFilters_abHairFilter_MTIKABHairFilter_nSetSmearMode`
