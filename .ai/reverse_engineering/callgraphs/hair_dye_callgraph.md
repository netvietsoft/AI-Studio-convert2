# Hair Dye Complete Call Graph
1. `HairViewModel.onDyeSelected(2305)`
2. `EffectDenseHairDataJNI.nativeSetMaterialId(2305)`
3. `MTIKHairFilter.nativeSetHairMaskTexture(maskTexId)`
4. `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates(0x000f3f58)`
   -> `grayFilterToFBO(0x000f42fc)`
   -> `hairMaskFilterToFBO(0x000f4400)`
   -> `blurHFilterToFBO(0x000f4528)`
   -> `blurVFilterToFBO(0x000f46d0)`
   -> `softHairFilterToFBO(0x000f4878)`
5. `LFDenseHairModular::processStructureTensor(0x000245a0)`
6. `LFDenseHairModular::computeDirectionalLIC(0x00024880)`
