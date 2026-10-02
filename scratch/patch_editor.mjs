import fs from 'node:fs';

const filePath = 'app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt';
let code = fs.readFileSync(filePath, 'utf8');

// 1. Add getMaterialBitmap after getBeardThumbnail
const helperTarget = `    private fun getBeardThumbnail(filename: String, density: Float): Bitmap? {
        if (beardThumbnails.containsKey(filename)) return beardThumbnails[filename]
        val fullBmp = getBeardBitmap(filename) ?: return null
        return try {
            val size = (38 * density).toInt()
            val thumb = Bitmap.createScaledBitmap(fullBmp, size, size, true)
            beardThumbnails[filename] = thumb
            thumb
        } catch (e: Exception) {
            null
        }
    }`;

const helperReplacement = `${helperTarget}

    private val materialBitmaps = mutableMapOf<String, Bitmap>()
    private fun getMaterialBitmap(assetPath: String): Bitmap? {
        if (materialBitmaps.containsKey(assetPath)) return materialBitmaps[assetPath]
        return try {
            assets.open(assetPath).use { inputStream ->
                val bmp = BitmapFactory.decodeStream(inputStream)
                if (bmp != null) materialBitmaps[assetPath] = bmp
                bmp
            }
        } catch (e: Exception) {
            Log.w("PhotoEditorActivity", "Cannot load material asset: " + assetPath + " (" + e.message + ")")
            null
        }
    }`;

if (!code.includes('private fun getMaterialBitmap')) {
  code = code.replace(helperTarget, helperReplacement);
}

// 2. Add 5002 Hair tools into cat_hair
const hairTarget = `            ToolItem("tool_hair_natural_black", "Nhuộm Đen Tự Nhiên Pure Black", "Natural Black Dye", false, "libmeitu_reborn_native.so", 70, 0, 100, "%")
        )),`;

const hairReplacement = `            ToolItem("tool_hair_natural_black", "Nhuộm Đen Tự Nhiên Pure Black", "Natural Black Dye", false, "libmeitu_reborn_native.so", 70, 0, 100, "%"),
            ToolItem("tool_hair_5002_brick_red", "Nhuộm Đỏ Gạch Quý Phái [5002]", "Brick Red 5002", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_matcha", "Nhuộm Xanh Matcha Cá Tính [5002]", "Matcha Green 5002", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_sky_blue", "Nhuộm Xanh Sky Blue [VIP] [5002]", "Sky Blue VIP 5002", true, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_lavender", "Nhuộm Tím Lavender [VIP] [5002]", "Lavender VIP 5002", true, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_emerald", "Nhuộm Xanh Ngọc Lục Bảo [VIP] [5002]", "Emerald Green VIP 5002", true, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_olive_moss", "Nhuộm Xanh Rêu Thời Thượng [5002]", "Olive Moss 5002", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_hair_5002_mint_ice", "Nhuộm Xanh Băng Mint Ice [VIP] [5002]", "Mint Ice VIP 5002", true, "libmeitu_reborn_native.so", 75, 0, 100, "%")
        )),`;

if (!code.includes('tool_hair_5002_brick_red')) {
  code = code.replace(hairTarget, hairReplacement);
}

// 3. Add 3D Makeup tools into cat_makeup
const makeupTarget = `            ToolItem("tool_contour_wocan", "Bọng mắt cười Wocan 3D", "Aegyo Sal Wocan 3D", true, "libmeitu_reborn_native.so", 70, 0, 100, "%")
        )),`;

const makeupReplacement = `            ToolItem("tool_contour_wocan", "Bọng mắt cười Wocan 3D", "Aegyo Sal Wocan 3D", true, "libmeitu_reborn_native.so", 70, 0, 100, "%"),
            ToolItem("tool_lip_dudu_3d", "Môi Căng Mọng Dudu Lips 3D [VIP]", "Dudu Lips PBR 3D", true, "libmeitu_reborn_native.so", 80, 0, 100, "%"),
            ToolItem("tool_skin_watery_3d", "Da Căng Bóng Ngậm Nước 3D", "Watery Skin Dewy 3D", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_skin_dodge_burn", "Đánh Khối Dodge & Burn Studio [VIP]", "Dodge & Burn Contour", true, "libmeitu_reborn_native.so", 70, 0, 100, "%"),
            ToolItem("tool_skin_delicate", "Làn Da Tinh Tế Delicate Skin", "Delicate Studio Skin", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_makeup_look_4005", "Trang Điểm Tổng Hợp Meitu 4005 [VIP]", "Full Look 4005", true, "libmeitu_reborn_native.so", 80, 0, 100, "%")
        )),`;

if (!code.includes('tool_lip_dudu_3d')) {
  code = code.replace(makeupTarget, makeupReplacement);
}

// 4. Add Apple and Samsung Camera filters into cat_filters
const filterTarget = `        // 13. FILTERS (2.14 3D LUT & Bokeh Xóa Phông)
        CategoryItem("cat_filters", "🎞️ Bộ Lọc", "3D LUTs & Bokeh", listOf(
            ToolItem("tool_filter_retro_film", "Retro Film 35mm Classic", "Kodachrome 35mm C++", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),`;

const filterReplacement = `        // 13. FILTERS (2.14 3D LUT & Bokeh Xóa Phông)
        CategoryItem("cat_filters", "🎞️ Bộ Lọc", "3D LUTs & Bokeh", listOf(
            ToolItem("tool_filter_apple_4s", "iPhone 4S Cổ Điển CCD [Material]", "iPhone 4S Film LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_5s", "iPhone 5S Tone Ấm Mộc [Material]", "iPhone 5S Warm LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_6s", "iPhone 6S Film Hoài Niệm [Material]", "iPhone 6S Classic LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_8p", "iPhone 8 Plus Chân Dung [Material]", "iPhone 8P Portrait LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_xr", "iPhone XR Tươi Tắn [Material]", "iPhone XR Vivid Pop LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_xs", "iPhone XS Max Ánh Vàng [Material]", "iPhone XS Max Gold LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_11p", "iPhone 11 Pro Tự Nhiên [Material]", "iPhone 11 Pro Natural LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_13p", "iPhone 13 Pro TrueTone [Material]", "iPhone 13 Pro TrueTone", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_apple_15p", "iPhone 15 Pro Mộc Raw [Material]", "iPhone 15 Pro Raw Crisp", false, "libmeitu_reborn_native.so", 80, 0, 100, "%"),
            ToolItem("tool_filter_apple_16p", "iPhone 16 Pro Studio HDR [Material]", "iPhone 16 Pro Studio HDR", true, "libmeitu_reborn_native.so", 80, 0, 100, "%"),
            ToolItem("tool_filter_apple_17p", "iPhone 17 Pro Dynamic [Material]", "iPhone 17 Pro Dynamic LUT", true, "libmeitu_reborn_native.so", 80, 0, 100, "%"),
            ToolItem("tool_filter_samsung_s", "Samsung Galaxy S Rực Rỡ [Material]", "Samsung Galaxy Vibrant LUT", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),
            ToolItem("tool_filter_retro_film", "Retro Film 35mm Classic", "Kodachrome 35mm C++", false, "libmeitu_reborn_native.so", 75, 0, 100, "%"),`;

if (!code.includes('tool_filter_apple_4s')) {
  code = code.replace(filterTarget, filterReplacement);
}

// 5. Add execution cases in applyCurrentToolToBitmap
const applyContourTarget = `            "tool_contour_wocan" -> {
                MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 3, p)
            }`;

const applyMakeupAddition = `${applyContourTarget}
            "tool_lip_dudu_3d" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, mouthX, mouthY, 8, 1, p)
                val lipMaskBmp = getMaterialBitmap("material/makeup/lip_mask.png")
                if (lipMaskBmp != null) {
                    MeituNativeEngine.nativeApplyIrisMakeup(workingBitmap, mouthX - 35f * sx, mouthY, mouthX + 35f * sx, mouthY, 20f * sx, 3, p * 0.45f)
                }
            }
            "tool_skin_watery_3d" -> {
                MeituNativeEngine.nativeApplyLocalizedSkinBilateral(workingBitmap, noseX, noseY, 260f * sx, 320f * sx, p, 0.20f * p)
            }
            "tool_skin_dodge_burn" -> {
                MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 0, p * 1.25f)
            }
            "tool_skin_delicate" -> {
                MeituNativeEngine.nativeApplyLocalizedSkinBilateral(workingBitmap, noseX, noseY, 250f * sx, 300f * sx, p * 0.85f, 0.05f)
            }
            "tool_makeup_look_4005" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, mouthX, mouthY, 2, 0, p * 0.85f)
                MeituNativeEngine.nativeApplyBlush(workingBitmap, lJawX + 70f * sx, lJawY - 20f * sx, rJawX - 70f * sx, rJawY - 20f * sx, 0, p * 0.8f)
                MeituNativeEngine.nativeApplyEyeShadow(workingBitmap, lxEye, lyEye, rxEye, ryEye, 1, p * 0.75f)
                MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 0, p * 0.7f)
            }`;

if (!code.includes('"tool_lip_dudu_3d" ->')) {
  code = code.replace(applyContourTarget, applyMakeupAddition);
}

// 6. Add 5002 Hair execution
const applyHairTarget = `            "tool_hair_natural_black", "tool_hair_black" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 0, p, 0.40f) // Natural Black
            }`;

const applyHairAddition = `${applyHairTarget}
            "tool_hair_5002_brick_red" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 6, p, 0.55f)
            }
            "tool_hair_5002_matcha" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.60f)
            }
            "tool_hair_5002_sky_blue" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.70f)
            }
            "tool_hair_5002_lavender" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 7, p, 0.65f)
            }
            "tool_hair_5002_emerald" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.65f)
            }
            "tool_hair_5002_olive_moss" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.50f)
            }
            "tool_hair_5002_mint_ice" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.75f)
            }`;

if (!code.includes('"tool_hair_5002_brick_red" ->')) {
  code = code.replace(applyHairTarget, applyHairAddition);
}

// 7. Add Apple and Samsung Filter execution
const applyFilterTarget = `            "tool_filter_retro_film" -> {
                MeituNativeEngine.nativeApplyFilter(workingBitmap, 1, p)
            }`;

const applyFilterAddition = `            "tool_filter_apple_4s" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_4s.png")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 1, p)
            }
            "tool_filter_apple_5s" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_5s.png")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 6, p)
            }
            "tool_filter_apple_6s" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_6s.png")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 1, p)
            }
            "tool_filter_apple_8p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_8p.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_xr" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_xr.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_xs" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_xs.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 6, p)
            }
            "tool_filter_apple_11p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_11p.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_13p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_13p.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_15p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_15p.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_16p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_16p.webp")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_apple_17p" -> {
                val lut = getMaterialBitmap("material/apple_camera/lut_17p.png")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
            }
            "tool_filter_samsung_s" -> {
                val lut = getMaterialBitmap("material/samsung_camera/lut_samsung.png")
                if (lut != null) MeituNativeEngine.nativeApply3DLut(workingBitmap, lut, p)
                else MeituNativeEngine.nativeApplyFilter(workingBitmap, 3, p)
            }
${applyFilterTarget}`;

if (!code.includes('"tool_filter_apple_4s" ->')) {
  code = code.replace(applyFilterTarget, applyFilterAddition);
}

fs.writeFileSync(filePath, code, 'utf8');
console.log('✅ Successfully patched PhotoEditorActivity.kt with all new materials!');
