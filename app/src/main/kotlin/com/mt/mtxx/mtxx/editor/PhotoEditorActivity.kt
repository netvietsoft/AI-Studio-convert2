package com.mt.mtxx.mtxx.editor

import android.app.Activity
import android.content.Intent
import android.graphics.*
import android.graphics.drawable.GradientDrawable
import android.net.Uri
import android.os.Bundle
import android.util.Log
import android.provider.MediaStore
import android.view.Gravity
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import android.widget.*
import com.meitu.common.ui.theme.MeituColors
import com.meitu.core.liquify.MTLiquifyImage
import com.meitu.core.nativeengine.MeituNativeEngine
import com.meitu.photoeditor.beauty.SkinSoftenProcessor
import com.meitu.photoeditor.beauty.SlimReshapeProcessor
import com.meitu.photoeditor.filter.FilterLutProcessor
import com.meitu.photoeditor.makeup.MakeupProcessor
import com.meitu.photoeditor.pipeline.BeautyPipeline
import com.meitu.ai.facedetect.FaceDetector106
import com.meitu.ai.segment.FaceParsingEngine
import com.meitu.vip.dialog.XXVipDialogHelper
import com.meitu.vip.manager.VipStatusManager
import com.meitu.vip.manager.VipTriggerManager
import java.io.InputStream
import java.util.Stack
import kotlin.math.max
import kotlin.math.min

/**
 * PhotoEditorActivity: Không gian làm việc chỉnh sửa ảnh chân dung chuẩn Meitu Studio.
 * Tích hợp 100% C++ Native Engine (libmeitu_reborn_native.so), OpenMP đa luồng,
 * Nắn bóp giải phẫu khuôn mặt (Liquify Warp), Làm trắng răng, Thẩm mỹ tai,
 * Nâng tông da sứ Bilateral, Trang điểm 3D và Bộ lọc LUT điện ảnh.
 */
class PhotoEditorActivity : Activity() {

    data class ToolItem(
        val id: String,
        val name: String,
        val nameEn: String,
        val isVip: Boolean,
        val nativeLib: String,
        val defaultVal: Int,
        val minVal: Int,
        val maxVal: Int,
        val unit: String
    )
    data class CategoryItem(val id: String, val title: String, val subtitle: String, val tools: List<ToolItem>)

    companion object {
        private const val REQUEST_PICK_IMAGE = 1001
        private const val MAX_UNDO_STACK = 10

        const val PARAM_PHILTRUM_LENGTH = 1701
        const val PARAM_PHILTRUM_WIDTH = 1702
        const val PARAM_PHILTRUM_GROOVE_DEPTH = 1703
        const val PARAM_PHILTRUM_CUPID_ACCENT = 1704

        const val BROW_COLOR_BLACK = 0
        const val BROW_COLOR_DARK_BROWN = 1
        const val BROW_COLOR_LIGHT_BROWN = 2
        const val BROW_COLOR_ASH_GRAY = 3
        const val BROW_COLOR_AUBURN = 4

        const val PARAM_NORMAL_NOSE_SCULPT = 2402
        const val PARAM_CLAVICLE_HIGHLIGHT = 2201
        const val PARAM_SHOULDER_SLIM = 2203

        const val TEETH_SHAPE_SIZE = 0
        const val TEETH_SHAPE_ALIGN = 1
        const val TEETH_SHAPE_PROTRUSION = 2

        @JvmStatic
        fun mapPhiltrumTool(toolId: String): Int? = when (toolId) {
            "tool_philtrum_high" -> PARAM_PHILTRUM_LENGTH
            "tool_philtrum_warp" -> PARAM_PHILTRUM_CUPID_ACCENT
            "tool_philtrum_depth" -> PARAM_PHILTRUM_GROOVE_DEPTH
            "tool_philtrum_width" -> PARAM_PHILTRUM_WIDTH
            else -> null
        }

        @JvmStatic
        fun mapBrowColor(toolId: String): Int? = when (toolId) {
            "tool_brow_color_black" -> BROW_COLOR_BLACK
            "tool_brow_color_dark_brown" -> BROW_COLOR_DARK_BROWN
            "tool_brow_color_light_brown" -> BROW_COLOR_LIGHT_BROWN
            "tool_brow_color_ash_gray" -> BROW_COLOR_ASH_GRAY
            "tool_brow_color_auburn" -> BROW_COLOR_AUBURN
            else -> null
        }

        @JvmStatic
        fun computeTeethReshapeValue(sliderIntensity: Int): Float {
            val p = sliderIntensity.toFloat() / 100f
            return p * 50.0f
        }

        @JvmStatic
        fun computeLashParameters(toolId: String, p: Float): Triple<Float, Float, Float> {
            val clampedP = p.coerceIn(0f, 1f)
            return when (toolId) {
                "tool_lash_density" -> Triple(1.0f, 1.0f + clampedP, 0.0f)
                "tool_lash_length" -> Triple(1.0f + clampedP * 1.2f, 1.0f, 0.0f)
                "tool_lash_curl" -> Triple(1.0f, 1.0f, clampedP * 2.0f)
                else -> Triple(1.0f, 1.0f, 0.0f)
            }
        }

        @JvmStatic
        fun mapEarStyleCode(toolId: String): Int = when (toolId) {
            "tool_ear_buddha" -> 4
            "tool_ear_mouse" -> 3
            "tool_ear_pig" -> 2
            "tool_ear_elf", "tool_ear_size" -> 0
            "tool_ear_press" -> 1
            "tool_ear_thickness" -> 5
            "tool_ear_protrude" -> 6
            else -> 4
        }

        @JvmStatic
        val PRODUCTION_CATEGORIES: List<CategoryItem> = listOf(
        // 1. FACE (Khuôn Mặt) — MTARBeautyParm.java (2.2.1 OVERALL & 2.2.2 RATIO / SHAPE)
        CategoryItem("cat_face", "👤 Khuôn Mặt", "Face & Ratio", listOf(
            // 2.2.1 OVERALL (Tổng Thể Khuôn Mặt)
            ToolItem("tool_hd_portrait", "HD Portrait [AI]", "kParamFlag_Face_Whittle", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_auto_face", "Tự động AI (Auto)", "Auto Beauty AI", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_width", "Thu chiều ngang (Width)", "kParamFlag_Face_Whittle", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_lift", "Nâng gương mặt (Lift)", "kParamFlag_FaceVShape", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_smooth", "Làm mịn da mặt [VIP]", "Smooth Bilateral VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_overall", "Cường độ tổng thể", "Overall Face Slider", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),

            // 2.2.2 RATIO / SHAPE (Tỷ Lệ Khuôn Mặt)
            ToolItem("tool_face_narrow", "Thu gọn mặt (Narrow Face)", "kParamFlag_Narrow_Face", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_small", "Mặt nhỏ (Small Face)", "kParamFlag_Face_Smaller", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_vline", "Slim V-Line", "SlimDeform.lua", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_forehead", "Trán (Forehead)", "kParamFlag_Face_Forehead", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_cheekbone", "Gò má (Cheekbone)", "kParamFlag_Cheekbone", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_temple", "Thái dương (Temple)", "kParamFlag_BeautyFaceTemple", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_mandible", "Hàm (Mandible)", "kParamFlag_MandibleLine", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_chin", "Cằm nhọn/tròn (Chin)", "kParamFlag_PointedAndRoundChin", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_round_head", "Vòm sọ tròn (Round Head)", "kParamFlag_RoundHead", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_lower", "Hạ tầng mặt (Lower Face)", "kParamFlag_LowerFace", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_middle", "Trung tầng mặt (Middle Half)", "kParamFlag_MiddleHalfOfFace", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_face_vshape", "Face V-Shape", "kParamFlag_FaceVShape", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 2. HAIR ENGINE (Tóc - SPEC Mục 5 C++ Native [VIP])
        CategoryItem("cat_hair", "💇 Tóc (Hair Studio) [VIP]", "Hair Engine C++ Native", listOf(
            // Đổi màu / Highlight / Ombre
            ToolItem("tool_hair_rose_gold", "Nhuộm Vàng Hồng Rose Gold [VIP]", "Rose Gold Dye VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_platinum", "Nhuộm Bạch Kim Platinum [VIP]", "Platinum Blonde Dye", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_smokey_silver", "Nhuộm Bạc Khói Smokey Silver [VIP]", "Smokey Silver Dye", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_burgundy", "Nhuộm Đỏ Rượu Vang Burgundy", "Wine Burgundy Dye", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_pastel_pink", "Nhuộm Hồng Pastel [VIP]", "Pastel Pink Dye VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_ash_brown", "Nhuộm Nâu Khói Thời Thượng", "Ash Brown Dye C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_caramel", "Nhuộm Nâu Mật Ong Caramel", "Caramel Honey Dye", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_navy_blue", "Nhuộm Xanh Navy Blue [VIP]", "Navy Blue Dye VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_natural_black", "Nhuộm Đen Tự Nhiên Pure Black", "Natural Black Dye", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_highlight", "Highlight Sợi Tóc C++ [VIP]", "Strand Highlights C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_ombre", "Nhuộm Ombre Hai Tông [VIP]", "Two-Tone Ombre C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            // 7 Tông Meitu 5002
            ToolItem("tool_hair_5002_brick_red", "Đỏ Gạch [Mitu 5002]", "5002 Brick Red", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_matcha", "Xanh Matcha [Mitu 5002]", "5002 Matcha Green", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_sky_blue", "Xanh Trời [Mitu 5002]", "5002 Sky Blue", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_lavender", "Tím Lavender [Mitu 5002]", "5002 Lavender", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_emerald", "Ngọc Lục Bảo [Mitu 5002]", "5002 Emerald Green", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_olive", "Rêu Olive [Mitu 5002]", "5002 Olive Moss", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_5002_mint", "Bạc Hà [Mitu 5002]", "5002 Mint Ice", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            // Cấu trúc, Phồng & Thẳng/Xoăn
            ToolItem("tool_hair_volume", "Làm phồng chân tóc (Volume)", "Fluffy Volume Boost", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_density", "Độ dày mỏng biểu kiến", "Apparent Density C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_curl_wave", "Uốn Xoăn / Duỗi Thẳng", "Curl & Wave Transform", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_line", "Hạ đường chân tóc (Hairline)", "Hairline Adjustment", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_bangs", "Tóc Mái Thưa / Mái Bay", "Bangs & Fringe Shape", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_wrapped", "Tóc ôm gọn viền mặt", "Hair Wrapped Face", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_scalp_remove", "Xóa Tóc & Da Đầu Nhẵn", "Scalp Reconstruction", true, "libmeitu_reborn_native.so", 0, 0, 100, "%"),
            // Tạo kiểu & Cắt tóc ngắn (Short Haircut & Hairstyle Suite)
            ToolItem("tool_hair_short_crop", "Tóc tém Pixie / Cắt ngắn", "Pixie & Short Crop Cut", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_buzzcut", "Tóc húi cua Buzzcut [VIP]", "Buzzcut 3mm Style", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_fade", "Tóc Fade Undercut [VIP]", "Side Fade Undercut", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_side_part", "Tóc 2 mái Hàn Quốc (Side Part)", "Korean Side Part 7/3", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_short_bob", "Tóc Bob ngắn thời thượng", "Short Bob Jawline Cut", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hair_layer", "Tóc tỉa Layer bồng bềnh", "Feathered Layer Cut", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 3. BEARD ENGINE (Râu - 478 Landmark Beard Studio C++ [VIP])
        CategoryItem("cat_beard", "🧔 Râu (Beard Studio) [VIP]", "478 Landmark Beard Studio C++", listOf(
            // 10 MẪU RÂU PNG CÓ SẴN (AUTO-RESIZE, WARP THEO 478 LANDMARK & ĐỔI MÀU / NHUỘM)
            ToolItem("tool_preset_beard_01", "Râu Chòm Dê (Goatee)", "01_goatee.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_02", "Râu Vuông Ngắn (Short Boxed)", "02_short_boxed_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_03", "Râu Dày Tự Nhiên (Full Natural)", "03_full_natural_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_04", "Râu Kiểu Balbo (Balbo Beard)", "04_balbo_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_05", "Râu Van Dyke Quý Tộc (Van Dyke)", "05_van_dyke_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_06", "Râu Tròn Cổ Điển (Circle Beard)", "06_circle_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_07", "Râu Mỏ Neo (Anchor Beard)", "07_anchor_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_08", "Râu Quai Nón Viền (Chinstrap)", "08_chinstrap_beard.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_09", "Ria Mép Chevron Dày (Chevron)", "09_chevron_mustache.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_beard_10", "Ria Mép Uốn Cong (Handlebar)", "10_handlebar_mustache.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),

            // PHÂN HỆ RÂU PROCEDURAL AI
            ToolItem("tool_beard_mustache_goatee", "Ria Mép & Râu Cằm [AI]", "Mustache & Goatee 478 Landmark", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_quai_non", "Râu Quai Nón Full [AI]", "Full Chinstrap Beard C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_mustache_only", "Ria Mép Quý Ông (Mustache)", "Mustache Gentleman C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_goatee_only", "Chòm Râu Cằm (Goatee / Chin)", "Goatee Soul Patch C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_dye", "Nhuộm Râu C++ Espresso [VIP]", "Beard Dye C++ VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_gray_away", "Phủ Bạc Râu Gray-Away 478 Landmark", "Beard Gray-Away C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_thickness", "Độ Dày Mỏng Sợi Râu", "Beard Thickness & Density", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_width", "Độ Rộng Râu (Spread)", "Beard Width & Spread", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_beard_height", "Cao Thấp Vị Trí Râu", "Beard Height Offset", true, "libmeitu_reborn_native.so", 0, -100, 100, "px")
        )),



        // 2. FACE PRESETS (Loại Khuôn Mặt — 2.2.3 face_list)
        CategoryItem("cat_face_presets", "✨ Dáng Mặt Preset", "Face Presets 3D", listOf(
            ToolItem("tool_preset_origin", "Nguyên bản (Origin)", "id: 62149", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_finetuning", "Tinh chỉnh (FineTuning)", "id: 62164", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_photogenic", "Ảnh chụp đẹp (PhotoGenic)", "id: 62186", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_round", "Mặt tròn (Round)", "id: 62107", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_square", "Mặt vuông (Square)", "id: 62108", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_long", "Mặt dài (Long)", "id: 62109", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_preset_short", "Mặt ngắn (Short)", "id: 62110", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 3. RESHAPE 3DMM (6,330 Vertices Morph)
        CategoryItem("cat_reshape_3dmm", "📐 3DMM Reshape", "3DMM 6,330 Vertices", listOf(
            ToolItem("tool_3dmm_jaw", "Gọt hàm / V-Line (FACE_JAW)", "3DMM Mandible Sculpt", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_chin", "Chỉnh cằm nhọn/tròn (FACE_CHIN)", "3DMM Chin Deform", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_narrow", "Thu hẹp mặt (FACE_NARROW)", "3DMM Narrow Face", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_smile", "Khóe miệng cười 3D (FACE_SMILE)", "3DMM Smile Corners", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_nose", "Thu nhỏ/Nâng mũi (FACE_NOSE)", "3DMM Nose Slim & Lift", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_nose_width", "Cánh mũi (FACE_NOSE_WIDTH)", "3DMM Alar Width", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_nose_bridge", "Sống mũi cao (FACE_NOSE_BRIDGE)", "3DMM Bridge Lift", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_nose_tip", "Đầu mũi (FACE_NOSE_TIP)", "3DMM Nasal Tip", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_eyes_size", "Kích thước mắt (FACE_EYES_SIZE)", "3DMM Eyes Scale", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_eyes_tilt", "Góc nghiêng mắt (FACE_EYES_TILT)", "3DMM Canthal Tilt", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_eyes_width", "Chiều rộng mắt (FACE_EYES_WIDTH)", "3DMM Eye Aperture", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_eyes_distance", "Khoảng cách 2 mắt (FACE_EYES_DISTANCE)", "3DMM Interpupillary Dist", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_brow_shape", "Dáng lông mày (FACE_BROW_SHAPE)", "3DMM Eyebrow Arch", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_brow_thickness", "Độ dày lông mày (FACE_BROW_THICKNESS)", "3DMM Brow Thickness", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_brow_height", "Vị trí chân mày (FACE_BROW_HEIGHT)", "3DMM Brow Elevation", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_lips", "Tổng thể môi (FACE_LIPS)", "3DMM Lips Volume", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_upper_lip", "Môi trên (FACE_UPPER_LIP)", "3DMM Upper Vermilion", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_lower_lip", "Môi dưới (FACE_LOWER_LIP)", "3DMM Lower Vermilion", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_symmetry", "Cân đối 2 bên mặt (FACE_SYMMETRY)", "3DMM Bilateral Symmetry", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_head", "Tỷ lệ đầu (FACE_HEAD)", "3DMM Cranial Scale", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_3dmm_forehead", "Trán (FACE_FOREHEAD)", "3DMM Forehead Dome", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 4. RESHAPE FREEFORM & RESIZES
        CategoryItem("cat_freeform_reshape", "🖐️ Nắn Bóp Tự Do", "Freeform & Resizes", listOf(
            ToolItem("tool_reshape_warp", "Vuốt nắn tự do (WARP)", "Freeform Mesh Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_reshape_refine", "Tinh chỉnh làm mượt (REFINE)", "Mesh Edge Refine", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_reshape_resize", "Thu to / Phóng to (RESIZE)", "Radial Area Resize", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_reshape_restore", "Hoàn tác về gốc (RESTORE)", "Bilinear Restore", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_resize_head", "Kích thước đầu (RESIZE_HEAD)", "Head Radial Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_resize_eyes", "Kích thước mắt (RESIZE_EYES)", "Eyes Radial Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_resize_nose", "Kích thước mũi (RESIZE_NOSE)", "Nose Radial Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_resize_mouth", "Kích thước miệng (RESIZE_MOUTH)", "Mouth Radial Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_resize_ears", "Kích thước tai (RESIZE_EARS)", "Ears Radial Warp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 2. EYES - HÌNH DÁNG (2.3.1 EYE SHAPE)
        CategoryItem("cat_eyes", "👁️ Dáng Mắt", "Eyes Shape & Size", listOf(
            ToolItem("tool_eye_enlarge", "Mắt to (Enlarge)", "Zoom_Eye C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_height", "Chiều cao mắt (Eye Height)", "Eye Height Morph", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_width", "Chiều rộng mắt (Eye Width)", "Eye Width Scale", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_tilt", "Góc nghiêng mắt (Eye Tilt)", "Eye Tilt Angle", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_updown", "Vị trí mắt cao/thấp", "Eye UpDown Position", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_longer", "Mắt dài hơn (Eye Longer)", "Eye Longer Span", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_end", "Đuôi mắt (Eye End)", "Outer Eye End Lift", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_eyelid", "Mí mắt (Eyelid)", "Eyelid Contour Refine", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_inner_corner", "Góc mắt trong (Inner Corner)", "Inner Canthus Span", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_outer_corner", "Góc mắt ngoài (Outer Corner)", "Outer Canthus Span", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_phoenix", "Mắt phượng (Inner Canthus Adj)", "Phoenix Eye Reshape", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_distance", "Khoảng cách 2 mắt (Distance)", "Interocular Distance", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_pupil_enlarge", "Phóng to đồng tử (Pupil)", "Enlarge Pupil C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 2B. EYE EFFECTS (2.3.2 & 2.3.3 Độ Sáng & Hiệu Ứng Mắt)
        CategoryItem("cat_eye_effects", "✨ Hiệu Ứng Mắt", "Eye Effects", listOf(
            ToolItem("tool_eye_bright", "Sáng mắt (Bright Eye)", "Bright_Eye Shader C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_whiten_sclera", "Làm sáng lòng trắng (Whiten)", "Whiten Sclera C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_remove_redness", "Xóa đỏ mắt (Remove Redness)", "De-Redness Filter C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_double_eyelid", "Tạo mí đôi (Double Eyelid)", "Double Eyelid Crease", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_sharpen", "Làm nét tròng mắt (Sharpen)", "Eye Sharpen Filter", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_clarity", "Làm trong mắt (Clarity)", "Eye Clarity Enhance", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_red_flash", "Xóa mắt đỏ Flash", "Flash Red Eye Removal", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 2C. EYE COLOR (Màu Mắt 8 Tones)
        CategoryItem("cat_eye_color", "🌈 Màu Mắt", "Eye Color 8 Tones", listOf(
            ToolItem("tool_eye_color_natural", "Màu tự nhiên (Natural)", "Natural Tone C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_color_blue", "Xanh biển Sapphire [VIP]", "Blue Sapphire C++", true, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_green", "Xanh ngọc lục bảo (Green)", "Emerald Green C++", true, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_hazel", "Hổ phách quyến rũ (Hazel)", "Hazel Amber C++", false, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_gray", "Xám khói huyền bí (Gray)", "Smoky Gray C++", true, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_violet", "Tím hoàng gia (Violet)", "Royal Violet C++", true, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_amber", "Nâu vàng hoàng kim (Amber)", "Golden Amber C++", false, "libmeitu_reborn_native.so", 80, -100, 100, "%"),
            ToolItem("tool_eye_color_honey", "Nâu mật ong ngọt ngào (Honey)", "Honey Brown C++", false, "libmeitu_reborn_native.so", 80, -100, 100, "%")
        )),

        // 2D. EYE CATCHLIGHT (8 Kiểu Ánh Sáng Phản Xạ Đồng Tử)
        CategoryItem("cat_eye_catchlight", "💡 Ánh Mắt Sáng", "Catchlight Studio", listOf(
            ToolItem("tool_catchlight_circle", "Vòng tròn Studio Ring [VIP]", "Studio Ring Light", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_star", "Ngôi sao lấp lánh (Star)", "Sparkle Star 4-Point", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_heart", "Trái tim tình yêu (Heart)", "Sweetheart Glint", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_softbox", "Hộp sáng Studio Softbox", "Square Softbox Glint", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_double_dot", "Chấm đôi Anime (Double Dot)", "Anime Double Highlight", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_crescent", "Trăng khuyết huyền bí (Crescent)", "Crescent Moon Beam", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_diamond", "Kim cương giác cạnh (Diamond)", "Diamond Facet Flare", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_catchlight_flower", "Cánh hoa tinh khôi (Flower)", "Floral Petal Glint", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 2E. EYE PRESETS (2.3.5 Preset Mắt Photo_13)
        CategoryItem("cat_eye_presets", "🌟 Preset Mắt", "Eye Presets Suite", listOf(
            ToolItem("tool_eye_preset_origin", "Manual / Nguyên bản", "Original Natural Eyes", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_preset_spiced_tea", "Spiced Tea (Trà Thơm)", "Warm Tea Tone Eyes", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_preset_tender_ai", "Tender [AI] Dịu Dàng", "AI Tender Portrait", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_preset_soft_grace", "Soft Grace (Duyên Dáng)", "Soft Graceful Charm", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_preset_pink_tale", "Pink Tale (Mộng Mơ)", "Pink Romantic Tale", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_eye_preset_pure_crystal", "Pure Crystal (Pha Lê)", "Crystal Clarity Glance", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 3. NOSE (2.5 Mũi — MTARBeautyParm.java)
        CategoryItem("cat_nose", "👃 Dáng Mũi", "Nose Slender Studio", listOf(
            ToolItem("tool_nose_shrink", "Thu cánh mũi (Shrink/Narrow)", "Ala Nasi Narrow", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_tip", "Thu nhỏ đầu mũi (Nose Tip)", "Nasal Tip Refine", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_root", "Nâng sống mũi (Nasal Root)", "Bridge Lift C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_longer", "Kéo dài dáng mũi (Longer)", "Nose Elongation", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_resize", "Kích thước tổng thể (Resize)", "Nose Scale Overall", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_distance", "Khoảng cách mũi-mắt (Distance)", "Intercanthal Distance", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_nose_narrow", "Thu hẹp tháp mũi (Narrow)", "Dorsal Narrowing", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 4. MOUTH / LIPS (2.6 Miệng & Môi — MTARBeautyParm.java)
        CategoryItem("cat_mouth", "👄 Dáng Môi", "Mouth & Lips Studio", listOf(
            ToolItem("tool_lip_overall", "Môi mọng tổng thể (Lip)", "Lip Volume Overall", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_upper", "Môi trên đầy đặn (Upper Lip)", "Upper Lip Vermilion", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_lower", "Môi dưới căng tràn (Lower Lip)", "Lower Lip Tubercle", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_mouth_width", "Thu nhỏ khuôn miệng (Width)", "Oral Commissure Width", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_mouth_rotate", "Xoay cân chỉnh miệng (Rotate)", "Mouth Symmetry Rotate", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_mouth_lateral", "Dịch chuyển miệng (Lateral)", "Mouth Lateral Move", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_philtrum_high", "Thu ngắn nhân trung (Philtrum)", "Philtrum High Lift", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_philtrum_warp", "Uốn nét nhân trung (Cupid)", "Cupid Bow Philtrum", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_philtrum_depth", "Độ sâu rãnh nhân trung", "3D Philtrum Groove Depth", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_comic_mouth_m", "Môi cười cánh én M [VIP]", "Comic M-Shape Lips", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_convex_mouth", "Thu môi nhô vổ (Convex)", "Convex Retraction", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_mouth_smile", "Khóe cười rạng rỡ (Smile)", "Smile Lip Lifter C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_bunny", "Môi thỏ tròn xinh (Bunny)", "Bunny Plump Double", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 5. SKIN (2.7 Làn Da & Loại Da — beauty JSON & MTARBeautyParm.java)
        CategoryItem("cat_skin", "💆 Làn Da", "Skin Perfection Suite", listOf(
            ToolItem("tool_skin_smooth", "Làm mịn lụa (Smooth)", "Realtime Bilateral C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_bright", "Nâng tông trắng sứ (Whiten)", "Porcelain Whiten C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_tone_rosy", "Tông: Trắng hồng mịn màng", "Rosy Porcelain White C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_tone_honey", "Tông: Da bánh mật khỏe", "Honey Bronze Athletic C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_acne", "Xóa thâm mụn AI (Acne)", "Neural Inpaint Patch", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_eyebags", "Xóa bọng quầng thâm mắt", "Eye Bags Concealer C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_smile_lines", "Xóa rãnh cười mũi má", "Nasolabial Laugh Lines", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_neck_lines", "Xóa nếp nhăn cổ", "Neck Lines Remover C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_clear", "Xóa tàn nhang đốm nâu", "Freckle Clear C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_detail", "Chi tiết biểu bì tự nhiên", "Epidermis Pores Detail C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_oil_control", "Kiềm bóng dầu Matte", "Anti-Shine Matte Filter", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_type_oily", "Chế độ: Da Dầu (64804)", "Oily Skin Specular Defuse", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_type_dry", "Chế độ: Da Khô (64805)", "Dry Skin Dewy Radiance", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_type_combined", "Chế độ: Da Hỗn Hợp (64806)", "Combined Skin T-Zone", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_type_sensitive", "Chế độ: Da Nhạy Cảm (64807)", "Sensitive Anti-Redness", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
        )),

        // 6. TEETH (2.11 Chỉnh Răng)
        CategoryItem("cat_teeth", "🦷 Chỉnh Răng", "Teeth Aesthetic", listOf(
            ToolItem("tool_teeth_whiten", "Làm trắng răng tự nhiên", "Teeth Whitening C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_teeth_porcelain", "Trắng sứ Hollywood [VIP]", "Porcelain White C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_teeth_ivory", "Trắng ngà quý phái", "Ivory Shade C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_teeth_enamel", "Phục hồi men sáng bóng", "Enamel Gloss C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_teeth_align", "Chỉnh răng đều đặn", "Teeth Align Warp", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_teeth_protrusion", "Thu răng hô móm", "Teeth Protrusion", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 7. EARS (Thẩm Mỹ Tai C++)
        CategoryItem("cat_ears", "👂 Thẩm Mỹ Tai", "Ears Aesthetic", listOf(
            ToolItem("tool_ear_buddha", "Tai Phật (Đại Phú Quý)", "Buddha Lobe Elongation C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_mouse", "Tai Chuột (Tròn Xòe)", "Mouse Round Helix C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_pig", "Tai Heo (Vểnh Khum)", "Pig Ear Flared C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_elf", "Tai Yêu Tinh (Elf Ears)", "Elf Ear Reshape C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_press", "Ép Tai Vểnh (Tự Nhiên)", "Ear Press Flatten", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
                    ToolItem("tool_ear_protrude", "Tai Vểnh Đón Gió", "Flared Ear Protrusion", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_thickness", "Dái Tai Dày (Quý Tướng)", "Ear Lobe Plump", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ear_rosy", "Tai Ửng Hồng (E Thẹn)", "Ear Rosy Tone C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 8. MAKEUP (2.8 Trang Điểm 3D — SubModule.MAKEUP)
        CategoryItem("cat_makeup", "💄 Trang Điểm 3D", "3D Makeup Studio", listOf(
            ToolItem("tool_lip_french_rose", "Son Hồng Pháp (Matte)", "French Rose Velvet", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_velvet_red", "Son Đỏ Nhung [VIP]", "Velvet Luxury Red", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_glossy_coral", "Son Bóng Pha Lê Coral [VIP]", "Glossy Coral Shimmer", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_gradient_ruby", "Son Lòng Môi Ombre Ruby", "Gradient Ombre Ruby", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lip_overlip_terracotta", "Son Tràn Viền Terracotta", "Overlip 3D Plump", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_blush_peachy", "Má hồng Đào trong veo", "Peach Blusher 3D", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_blush_rosy", "Má hồng Cánh Sen dịu dàng", "Rosy Cheek Glow", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_blush_sun_kissed", "Má ửng nắng Sun-kissed", "Sun-kissed Amber", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_shadow_sunset", "Phấn mắt Sunset Peach", "Sunset Eye Shadow", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_shadow_smokey", "Phấn mắt khói Smokey Brown", "Smokey Shadow VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_contour_nose", "Tạo khối sống mũi 3D", "Nose Bridge Contour", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_contour_wocan", "Bọng mắt cười Wocan 3D", "Aegyo Sal Wocan 3D", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            // CHÂN MÀY & LÔNG MI C++ (EYEBROW & EYELASH NATIVE ENGINE)
            ToolItem("tool_brow_thickness", "Độ Dày Chân Mày", "Eyebrow Thickness C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_arch", "Độ Cong Đỉnh Mày", "Eyebrow Arch C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_density", "Mật Độ Sợi Chân Mày", "Eyebrow Density C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_color_black", "Chân mày: Đen Tự Nhiên", "Eyebrow Natural Black", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_color_dark_brown", "Chân mày: Nâu Đen", "Eyebrow Dark Brown", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_color_light_brown", "Chân mày: Nâu Sáng", "Eyebrow Light Brown", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_color_ash_gray", "Chân mày: Xám Tro", "Eyebrow Ash Gray", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_brow_color_auburn", "Chân mày: Nâu Đỏ Ánh Đồng", "Eyebrow Auburn", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lash_density", "Lông mi: Độ Dày Dặn", "Keratin Lash Density C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lash_length", "Lông mi: Chiều Dài", "Keratin Lash Length C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_lash_curl", "Lông mi: Độ Cong Vút", "Keratin Lash Curl C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            // TRANG ĐIỂM 3D TỪ BỘ MATERIAL MEITU (4001, beautyPart3, 4005)
            ToolItem("tool_lip_dudu_3d", "Son 3D DuDu [Mitu]", "material/makeup/lip_lut.png", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_watery_3d", "Da Căng Bóng [Mitu]", "3D Highlight Shimmer", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_skin_dodge_burn", "Tạo Khối D&B [Mitu]", "adSkin DodgeBurn", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_makeup_look_4005", "Trang Điểm 4005 [Mitu]", "Full Face Look 4005", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),


        // 10. BODY (2.10 Thon Gọn Dáng — SubModule.REMOLD)
        CategoryItem("cat_body", "💃 Thon Dáng", "Body Reshape Suite", listOf(
            ToolItem("tool_body_slim", "Thon gọn toàn thân (Slim)", "Full Body Slender", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_waist", "Eo thon con kiến (Waist) [VIP]", "Slim Waist Warp", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_shoulder", "Vai vuông móc áo (Shoulder)", "Straight Shoulder", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_neck", "Cổ thiên nga thon dài (Swan Neck)", "Swan Neck Lengthen", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_clavicle_enhance", "Xương quai xanh quyến rũ (Clavicle)", "Clavicle Highlight", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_legs", "Kéo dài chân tỉ lệ vàng", "Golden Ratio Legs", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_chest", "Nâng ngực tự nhiên (Chest)", "Chest Natural Enlarge", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_body_hip", "Nở nang đường cong hông (Hip)", "Curvy Hip Deform", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 11. AI RETOUCH (2.12 Smart Beautify 1-Touch)
        CategoryItem("cat_ai_retouch", "🤖 AI Retouch", "AI Smart Retouch", listOf(
            ToolItem("tool_ai_idol", "Chân dung Idol K-Pop [VIP]", "K-Pop Idol Portrait", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ai_sculpted", "Đường nét Điêu Khắc [VIP]", "Sculpted Facial Form", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ai_dewy", "Da căng bóng Dewy Glass", "Dewy Glass Hydration", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ai_fresh", "Phong cách Fresh Tinh Khôi", "Fresh Natural Glow", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 12. ADJUST / TONE (2.14 Điều Chỉnh Màu & HSL 8 Kênh)
        CategoryItem("cat_adjust", "🎛️ Chỉnh Màu", "Color & Tone Studio", listOf(
            ToolItem("tool_tone_exposure", "Phơi sáng (Exposure)", "Photographic Exposure", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_tone_contrast", "Độ tương phản (Contrast)", "Contrast Curve C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_tone_saturation", "Độ bão hòa (Saturation)", "Vivid Saturation", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_tone_temp", "Nhiệt độ màu (Temperature)", "Color Temperature Kelvin", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_tone_tint", "Sắc thái màu (Tint)", "Green-Magenta Tint", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hsl_red", "HSL: Kênh Đỏ (Red Tone)", "HSL Red Hue Shift", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hsl_orange", "HSL: Kênh Cam (Da mặt)", "HSL Orange Skin Tone", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_hsl_blue", "HSL: Kênh Lam (Bầu trời/Áo)", "HSL Blue Atmosphere", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 13. FILTERS (2.14 3D LUT & Bokeh Xóa Phông)
        CategoryItem("cat_filters", "🎞️ Bộ Lọc", "3D LUTs & Bokeh", listOf(
            ToolItem("tool_filter_retro_film", "Retro Film 35mm Classic", "Kodachrome 35mm C++", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_portrait_glow", "Portrait Glow Hồng Hào", "Porcelain Glow LUT", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_cyberpunk", "Cyberpunk Neon Teal & Orange [VIP]", "Sci-Fi Cyberpunk VIP", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_golden_hour", "Golden Hour Hoàng Hôn", "Warm Sunset Hour", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_moody_bw", "Moody B&W Điện Ảnh", "Noir Dramatic B&W", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_defocus_portrait", "AI Xóa phông Bokeh DSLR [VIP]", "Portrait Bokeh Blur C++", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            // 11 BỘ LỌC IPHONE & 1 BỘ LỌC SAMSUNG TỪ BỘ MATERIAL MEITU
            ToolItem("tool_filter_apple_4s", "iPhone 4s Film [Mitu]", "material/apple_camera/lut_4s.png", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_5s", "iPhone 5s Cold [Mitu]", "material/apple_camera/lut_5s.png", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_6s", "iPhone 6s Gold [Mitu]", "material/apple_camera/lut_6s.png", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_8p", "iPhone 8 Plus [Mitu]", "material/apple_camera/lut_8p.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_xr", "iPhone XR Vivid [Mitu]", "material/apple_camera/lut_xr.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_xs", "iPhone XS Max [Mitu]", "material/apple_camera/lut_xs.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_11p", "iPhone 11 Pro [Mitu]", "material/apple_camera/lut_11p.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_13p", "iPhone 13 Pro [Mitu]", "material/apple_camera/lut_13p.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_15p", "iPhone 15 Pro [Mitu]", "material/apple_camera/lut_15p.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_16p", "iPhone 16 Pro [Mitu]", "material/apple_camera/lut_16p.webp", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_apple_17p", "iPhone 17 Pro [Mitu]", "material/apple_camera/lut_17p.png", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_filter_samsung_s", "Samsung Galaxy S [Mitu]", "material/samsung_camera/lut_samsung.png", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 14. ẢNH THẺ & HỘ CHIẾU (7. ID PHOTOS — FUNCTIONAL_MAP_MEITU.txt)
        CategoryItem("cat_id_photo", "👔 Ảnh Thẻ", "ID & Passport Photo Suite", listOf(
            ToolItem("tool_id_bg_white", "Phông Nền Trắng Chuẩn Quốc Tế", "White Background ID", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_bg_blue", "Phông Nền Xanh Chuẩn VN [VIP]", "Navy Blue Background VN", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_bg_cyan", "Phông Nền Xanh Nhạt [VIP]", "Light Cyan Background", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_bg_gray", "Phông Nền Xám Studio [VIP]", "Studio Gray Background", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_bg_red", "Phông Nền Đỏ (Red Background)", "Red Background ID", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_crop_3x4", "Cắt Chuẩn 3x4 cm (HR Docs)", "3x4 cm Standard Crop", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_id_crop_4x6", "Cắt Chuẩn 4x6 cm (Hộ Chiếu)", "4x6 cm Passport Crop", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 15. GHÉP ẢNH (5. COLLAGE GRID — FUNCTIONAL_MAP_MEITU.txt)
        CategoryItem("cat_collage", "🧵 Ghép Ảnh", "Creative Collage Suite", listOf(
            ToolItem("tool_collage_grid_2", "Ghép Lưới 2 Ảnh (Dọc)", "2-Photo Vertical Grid", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_collage_grid_3", "Ghép Lưới 3 Ảnh (Tạp chí)", "3-Photo Magazine Grid", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_collage_grid_4", "Ghép Lưới 4 Ảnh Vuông [VIP]", "4-Photo Square Grid", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_collage_grid_9", "Ghép Lưới 9 Ảnh (Nine-box)", "9-Photo Plog Grid", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_collage_border", "Đường Viền & Bo Góc Khung", "Border Spacing & Radius", false, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        )),

        // 16. STICKER & VẼ NGHỆ THUẬT (2.15 STICKERS / MAGIC PEN — FUNCTIONAL_MAP_MEITU.txt)
        CategoryItem("cat_stickers_art", "🎨 Sticker & Art", "Sticker & Magic Pen Studio", listOf(
            ToolItem("tool_sticker_sparkle", "Hạt Lấp Lánh Bling Bling", "Sparkle Glitter FX", false, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_magic_pen_neon", "Bút Dạ Quang Neon Magic Pen", "Neon Glow Magic Pen", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_magic_pen_galaxy", "Bút Vẽ Sao Rơi Galaxy [VIP]", "Galaxy Stars Magic Pen", true, "libmeitu_reborn_native.so", 0, -100, 100, "%"),
            ToolItem("tool_ai_eraser", "Tẩy Xóa Vật Thể AI Inpaint", "AI Object Eraser Inpaint", true, "libmeitu_reborn_native.so", 0, -100, 100, "%")
        ))
    )
    }

    /** Định dạng nhãn hiển thị cho thanh trượt lưỡng cực [-100, +100] / Format label for bipolar slider */
    private fun formatSliderText(value: Int, unit: String): String {
        return if (unit == "%") {
            if (value > 0) "+$value%" else if (value < 0) "$value%" else "0%"
        } else {
            if (value > 0) "+$value$unit" else if (value < 0) "$value$unit" else "0$unit"
        }
    }


    private lateinit var canvasContainer: FrameLayout
    private lateinit var ivCanvasPreview: ImageView
    private lateinit var tvEffectTag: TextView
    private lateinit var tvNativeLibInfo: TextView
    private lateinit var sliderContainer: LinearLayout
    private lateinit var tvToolTitle: TextView
    private lateinit var tvSliderValue: TextView
    private lateinit var seekBarIntensity: SeekBar
    private lateinit var subToolsScroll: HorizontalScrollView
    private lateinit var subToolsContainer: LinearLayout
    private lateinit var categoryContainer: LinearLayout
    private lateinit var categoryScroll: HorizontalScrollView

    private lateinit var rawOriginalBitmap: Bitmap
    private lateinit var baseLayerBitmap: Bitmap
    private lateinit var originalBitmap: Bitmap // Giữ tương thích tham chiếu ảnh gốc ban đầu
    private lateinit var currentProcessedBitmap: Bitmap

    private val undoStack = Stack<Bitmap>()
    private val redoStack = Stack<Bitmap>()

    private var currentCategory = "👤 Khuôn Mặt"
    private var currentToolId = "tool_eye_enlarge"
    private var currentToolName = "Mở to mắt (Enlarge)"
    private var currentToolEn = "Zoom Eye Deform"
    private var currentNativeLib = "libmeitu_reborn_native.so"
    private var currentIntensity = 0

        private var isComparingOriginal = false

    // Beard Tuning State (Độ dày mỏng, Cao thấp, Độ rộng, Đậm nhạt C++)
    private var beardParamMode = "intensity" // "intensity", "thickness", "width", "height"
    private var beardIntensity = 0 // -100..100 (%), default 0 = Neutral
    private var beardThicknessVal = 0 // -100..100 (%), default 0 = Neutral (1.0f)
    private var beardWidthVal = 0 // -100..100 (%), default 0 = Neutral (1.0f)
    private var beardHeightOffsetVal = 0 // -100..+100 (px)
    private var beardHorizontalOffsetVal = 0 // -100..+100 (px)
    private var isDraggingBeard = false
    private var dragStartX = 0f
    private var dragStartY = 0f
    private var dragInitOffsetH = 0
    private var dragInitOffsetV = 0
    private lateinit var dragBeardHud: LinearLayout
    private lateinit var tvDragBeardText: TextView
    private lateinit var btnResetBeardPos: TextView
    private lateinit var chipBeardHorizontal: TextView
    private var activeBeardStyle = 1 // 1: Mustache & Goatee, 0: Full Chinstrap, 2: Mustache, 3: Goatee
    private var activeBeardR = 32
    private var activeBeardG = 24
    private var activeBeardB = 20
    private var isBeardDyeCustomActive = false
    private val beardBitmaps = mutableMapOf<String, Bitmap>()
    private val beardThumbnails = mutableMapOf<String, Bitmap>()
    private lateinit var beardColorScroll: HorizontalScrollView
    private lateinit var beardColorContainer: LinearLayout
    private val beardColorChips = mutableListOf<TextView>()

    data class BeardColorOption(val name: String, val r: Int, val g: Int, val b: Int, val isNatural: Boolean)
    private val beardColorList = listOf(
        BeardColorOption("🔘 Tự Nhiên", 0, 0, 0, true),
        BeardColorOption("⬛ Đen Tuyền", 22, 18, 16, false),
        BeardColorOption("🟫 Nâu Espresso", 45, 30, 22, false),
        BeardColorOption("🟤 Nâu Hạt Dẻ", 78, 48, 32, false),
        BeardColorOption("🟡 Vàng Caramel", 115, 80, 48, false),
        BeardColorOption("⚪ Bạc Khói", 145, 145, 150, false),
        BeardColorOption("🍷 Đỏ Burgundy", 95, 25, 38, false),
        BeardColorOption("✨ Bạch Kim", 165, 150, 120, false)
    )

    private fun getBeardBitmap(filename: String): Bitmap? {
        if (beardBitmaps.containsKey(filename)) return beardBitmaps[filename]
        return try {
            assets.open("beards/$filename").use { inputStream ->
                val bmp = BitmapFactory.decodeStream(inputStream)
                if (bmp != null) beardBitmaps[filename] = bmp
                bmp
            }
        } catch (e: Exception) {
            null
        }
    }

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
            android.util.Log.e("PhotoEditorActivity", "Error loading material asset: $assetPath: ${e.message}")
            null
        }
    }

    private fun getBeardThumbnail(filename: String, density: Float): Bitmap? {
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
    }
    private lateinit var beardTuningScroll: HorizontalScrollView
    private lateinit var beardTuningContainer: LinearLayout
    private lateinit var chipBeardIntensity: TextView
    private lateinit var chipBeardThickness: TextView
    private lateinit var chipBeardWidth: TextView
    private lateinit var chipBeardHeight: TextView

    private lateinit var filterLutProcessor: FilterLutProcessor
    private lateinit var faceParsingEngine: FaceParsingEngine
    private lateinit var faceDetector: FaceDetector106

    // Tọa độ giải phẫu khuôn mặt mẫu (chuẩn hóa theo kích thước ảnh thật)
    private var lxEye = 325f
    private var lyEye = 430f
    private var rxEye = 571f
    private var ryEye = 430f
    private var noseX = 448f
    private var noseY = 560f
    private var mouthX = 448f
    private var mouthY = 665f
    private var chinX = 448f
    private var chinY = 780f
    private var lJawX = 240f
    private var lJawY = 540f
    private var rJawX = 656f
    private var rJawY = 540f
    private var lEarX = 195f
    private var lEarY = 490f
    private var rEarX = 700f
    private var rEarY = 490f

    private var landmarks106: FloatArray = FloatArray(212)
    private var detectedIrisTrack: FaceDetector106.IrisTrackInfo? = null
    private var detectedLeftSmileLine: FloatArray? = null
    private var detectedRightSmileLine: FloatArray? = null
    private var detectedCanthusPoints: FloatArray? = null
    private var detectedDenseMesh478: FloatArray? = null
    private var hasRealFace = false

    // Danh sách 14 danh mục chuẩn Meitu v12.17.8 bao phủ toàn diện theo FUNCTIONAL_MAP_MEITU.txt
    private val categories = PRODUCTION_CATEGORIES

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        filterLutProcessor = FilterLutProcessor(this)
        faceParsingEngine = FaceParsingEngine(this)
        faceDetector = FaceDetector106(this)

        // 1. Khởi tạo BiSeNet 19-Class Face & Hair Parser (Độ chính xác từng bit/pixel, phủ 100% hộp sọ)
        try {
            val bisenetDir = java.io.File(filesDir, "models/bisenet")
            bisenetDir.mkdirs()
            val bisenetParam = java.io.File(bisenetDir, "bisenet_face_19.param")
            val bisenetBin = java.io.File(bisenetDir, "bisenet_face_19.bin")
            if (!bisenetParam.exists() || bisenetParam.length() < 5000L) {
                assets.open("models/bisenet_face_19.param").use { inp ->
                    java.io.FileOutputStream(bisenetParam).use { out -> inp.copyTo(out) }
                }
            }
            if (!bisenetBin.exists() || bisenetBin.length() < 25000000L) {
                assets.open("models/bisenet_face_19.bin").use { inp ->
                    java.io.FileOutputStream(bisenetBin).use { out -> inp.copyTo(out) }
                }
            }
            val bisenetOk = MeituNativeEngine.nativeInitBiSeNetParser(
                bisenetParam.absolutePath,
                bisenetBin.absolutePath
            )
            Log.i("PhotoEditorActivity", "BiSeNet 19-Class Parser Initialized in Activity: $bisenetOk (bin size: ${bisenetBin.length()})")
        } catch (e: Throwable) {
            Log.w("PhotoEditorActivity", "Failed to init BiSeNet Parser: ${e.message}")
        }

        // 2. Khởi tạo mạng NCNN Hair Matting Mobile chuyên dụng (512x512)
        try {
            val modelDir = java.io.File(filesDir, "models/ncnn")
            modelDir.mkdirs()
            val paramFile = java.io.File(modelDir, "hair_matting_mobile.param")
            val binFile = java.io.File(modelDir, "hair_matting_mobile.bin")
            if (!paramFile.exists() || paramFile.length() == 0L) {
                assets.open("models/ncnn/hair_matting_mobile.param").use { inp ->
                    java.io.FileOutputStream(paramFile).use { out -> inp.copyTo(out) }
                }
            }
            if (!binFile.exists() || binFile.length() == 0L) {
                assets.open("models/ncnn/hair_matting_mobile.bin").use { inp ->
                    java.io.FileOutputStream(binFile).use { out -> inp.copyTo(out) }
                }
            }
            val hairMattingOk = MeituNativeEngine.nativeInitHairMatting(
                paramFile.absolutePath,
                binFile.absolutePath
            )
            Log.i("PhotoEditorActivity", "NCNN Hair Matting Initialized in Activity: $hairMattingOk")
        } catch (e: Throwable) {
            Log.w("PhotoEditorActivity", "Failed to init Hair Matting: ${e.message}")
        }

        initDefaultPortraitPhoto()

        val density = resources.displayMetrics.density

        val root = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(0xFF09090D.toInt())
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // 1. Top Header Bar (Sleek Studio Header)
        val topBar = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val padH = (14 * density).toInt()
            val padV = (10 * density).toInt()
            setPadding(padH, padV, padH, padV)
            setBackgroundColor(0xFF121218.toInt())
        }

        val btnClose = TextView(this).apply {
            text = "✕"
            textSize = 18f
            setTextColor(Color.WHITE)
            setPadding(8, 0, 16, 0)
            setOnClickListener { finish() }
        }

        val tvTitle = TextView(this).apply {
            text = "Meitu Studio Reborn"
            textSize = 15f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            val lp = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            layoutParams = lp
        }

        // Nút chọn ảnh từ Thư Viện máy thật
        val btnPick = TextView(this).apply {
            text = "📁 Mở Ảnh"
            textSize = 12f
            setTextColor(Color.WHITE)
            val padH = (10 * density).toInt()
            val padV = (5 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (16 * density)
                setColor(0x22FFFFFF)
            }
            background = bg
            setOnClickListener {
                pickPhotoFromGallery()
            }
        }

        // Nút Undo
        val btnUndo = TextView(this).apply {
            text = "↩️"
            textSize = 16f
            setPadding(10, 0, 10, 0)
            setOnClickListener { performUndo() }
        }

        // Nút Redo
        val btnRedo = TextView(this).apply {
            text = "↪️"
            textSize = 16f
            setPadding(10, 0, 12, 0)
            setOnClickListener { performRedo() }
        }

        // Nút Lưu/Xuất
        val btnSave = TextView(this).apply {
            text = "Xuất Ảnh"
            textSize = 13f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            val padH = (14 * density).toInt()
            val padV = (6 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val btnBg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 18f
                colors = intArrayOf(MeituColors.PrimaryPink, MeituColors.PrimaryRose)
                orientation = GradientDrawable.Orientation.LEFT_RIGHT
            }
            background = btnBg
            setOnClickListener {
                saveAndExportImage()
            }
        }

        topBar.addView(btnClose)
        topBar.addView(tvTitle)
        topBar.addView(btnPick)
        topBar.addView(btnUndo)
        topBar.addView(btnRedo)
        topBar.addView(btnSave)
        root.addView(topBar)

        // 2. Main Live Canvas Work Area (Tràn viền, tối ưu hóa không gian hiển thị ảnh thật)
        canvasContainer = FrameLayout(this).apply {
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 0, 1f)
            layoutParams = lp
            setBackgroundColor(0xFF09090D.toInt())
        }

        ivCanvasPreview = ImageView(this).apply {
            layoutParams = FrameLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT).apply {
                gravity = Gravity.CENTER
            }
            scaleType = ImageView.ScaleType.FIT_CENTER
            setImageBitmap(currentProcessedBitmap)
        }
        canvasContainer.addView(ivCanvasPreview)

        // Floating Glass Badge: Hiển thị trạng thái bộ xử lý C++
        val statusPill = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            gravity = Gravity.CENTER_HORIZONTAL
            val padH = (14 * density).toInt()
            val padV = (6 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val pillBg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (20 * density)
                setColor(0xCC111116.toInt())
            }
            background = pillBg
            val lp = FrameLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                gravity = Gravity.TOP or Gravity.CENTER_HORIZONTAL
                topMargin = (10 * density).toInt()
            }
            layoutParams = lp
        }

        tvEffectTag = TextView(this).apply {
            text = "✨ $currentToolName (${formatSliderText(currentIntensity, "%")})"
            textSize = 12f
            setTextColor(MeituColors.PrimaryRose)
            setTypeface(typeface, Typeface.BOLD)
            gravity = Gravity.CENTER
        }

        tvNativeLibInfo = TextView(this).apply {
            text = "⚡ 100% C++ Engine • libmeitu_reborn_native.so • OpenMP"
            textSize = 9f
            setTextColor(MeituColors.TextMuted)
            gravity = Gravity.CENTER
        }

        statusPill.addView(tvEffectTag)
        statusPill.addView(tvNativeLibInfo)
        canvasContainer.addView(statusPill)

        // Floating Compare Button: Giữ để xem ảnh gốc ban đầu
        val btnCompare = TextView(this).apply {
            text = "👁️ Chạm & Giữ để xem ảnh gốc"
            textSize = 11f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            val padH = (16 * density).toInt()
            val padV = (8 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (20 * density)
                setColor(0xD9181622.toInt())
            }
            background = bg
            val lp = FrameLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                gravity = Gravity.BOTTOM or Gravity.CENTER_HORIZONTAL
                bottomMargin = (12 * density).toInt()
            }
            layoutParams = lp

            setOnTouchListener { _, event ->
                when (event.action) {
                    MotionEvent.ACTION_DOWN -> {
                        isComparingOriginal = true
                        ivCanvasPreview.setImageBitmap(rawOriginalBitmap)
                        tvEffectTag.text = "📷 [ẢNH GỐC BAN ĐẦU]"
                        tvEffectTag.setTextColor(0xFFCCCCCC.toInt())
                        true
                    }
                    MotionEvent.ACTION_UP, MotionEvent.ACTION_CANCEL -> {
                        isComparingOriginal = false
                        ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
                        tvEffectTag.text = "✨ $currentToolName (${formatSliderText(currentIntensity, "%")})"
                        tvEffectTag.setTextColor(MeituColors.PrimaryRose)
                        true
                    }
                    else -> false
                }
            }
        }
        canvasContainer.addView(btnCompare)

        // 2B. Floating Touch Drag Guide & Live Position Pill (Căn chỉnh vị trí râu tự do bằng cảm ứng)
        dragBeardHud = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val padH = (14 * density).toInt()
            val padV = (7 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (18 * density)
                setColor(0xEE161320.toInt())
            }
            background = bg
            val lp = FrameLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                gravity = Gravity.BOTTOM or Gravity.CENTER_HORIZONTAL
                bottomMargin = (52 * density).toInt()
            }
            layoutParams = lp
            visibility = View.GONE
        }

        tvDragBeardText = TextView(this).apply {
            text = "🖐️ Chạm & Kéo trên ảnh để chỉnh vị trí râu"
            textSize = 10.5f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
        }
        dragBeardHud.addView(tvDragBeardText)

        btnResetBeardPos = TextView(this).apply {
            text = "  ↺ Đặt lại"
            textSize = 10.5f
            setTextColor(MeituColors.PrimaryRose)
            setTypeface(typeface, Typeface.BOLD)
            visibility = View.GONE
            setOnClickListener {
                beardHorizontalOffsetVal = 0
                beardHeightOffsetVal = 0
                updateBeardPosHud()
                updateBeardTuningChips(density)
                applyCurrentToolToBitmap()
                pushUndoState(currentProcessedBitmap)
                Toast.makeText(this@PhotoEditorActivity, "↺ Đã đặt lại vị trí râu về mặc định", Toast.LENGTH_SHORT).show()
            }
        }
        dragBeardHud.addView(btnResetBeardPos)
        canvasContainer.addView(dragBeardHud)

        // Touch listener on preview canvas to drag and adjust beard position in real time
        ivCanvasPreview.setOnTouchListener { _, event ->
            if (!isBeardToolActive()) {
                return@setOnTouchListener false
            }

            when (event.actionMasked) {
                MotionEvent.ACTION_DOWN -> {
                    val bmp = baseLayerBitmap ?: return@setOnTouchListener false
                    val vW = ivCanvasPreview.width.toFloat()
                    val vH = ivCanvasPreview.height.toFloat()
                    if (vW <= 0f || vH <= 0f || bmp.width <= 0 || bmp.height <= 0) return@setOnTouchListener false

                    val scale = minOf(vW / bmp.width, vH / bmp.height)
                    val imgLeft = (vW - bmp.width * scale) / 2f
                    val imgTop = (vH - bmp.height * scale) / 2f

                    if (event.x >= imgLeft && event.x <= imgLeft + bmp.width * scale &&
                        event.y >= imgTop && event.y <= imgTop + bmp.height * scale) {
                        isDraggingBeard = true
                        dragStartX = event.x
                        dragStartY = event.y
                        dragInitOffsetH = beardHorizontalOffsetVal
                        dragInitOffsetV = beardHeightOffsetVal
                        updateBeardPosHud()
                        true
                    } else {
                        false
                    }
                }
                MotionEvent.ACTION_MOVE -> {
                    if (isDraggingBeard) {
                        val bmp = baseLayerBitmap ?: return@setOnTouchListener true
                        val vW = ivCanvasPreview.width.toFloat()
                        val vH = ivCanvasPreview.height.toFloat()
                        val scale = minOf(vW / bmp.width, vH / bmp.height).coerceAtLeast(0.01f)

                        val deltaX = event.x - dragStartX
                        val deltaY = event.y - dragStartY

                        val deltaBmpX = (deltaX / scale).toInt()
                        val deltaBmpY = (deltaY / scale).toInt()

                        val newH = (dragInitOffsetH + deltaBmpX).coerceIn(-100, 100)
                        val newV = (dragInitOffsetV + deltaBmpY).coerceIn(-100, 100)

                        if (newH != beardHorizontalOffsetVal || newV != beardHeightOffsetVal) {
                            beardHorizontalOffsetVal = newH
                            beardHeightOffsetVal = newV
                            updateBeardPosHud()
                            if (beardParamMode == "height") {
                                seekBarIntensity.progress = beardHeightOffsetVal
                                tvSliderValue.text = "${beardHeightOffsetVal}px"
                            } else if (beardParamMode == "horizontal") {
                                seekBarIntensity.progress = beardHorizontalOffsetVal
                                tvSliderValue.text = "${beardHorizontalOffsetVal}px"
                            }
                            applyCurrentToolToBitmap()
                        }
                        true
                    } else {
                        false
                    }
                }
                MotionEvent.ACTION_UP, MotionEvent.ACTION_CANCEL -> {
                    if (isDraggingBeard) {
                        isDraggingBeard = false
                        updateBeardPosHud()
                        updateBeardTuningChips(density)
                        pushUndoState(currentProcessedBitmap)
                        true
                    } else {
                        false
                    }
                }
                else -> false
            }
        }
        root.addView(canvasContainer)

        // 3. Slider Control Panel
        sliderContainer = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val padH = (16 * density).toInt()
            val padV = (6 * density).toInt()
            setPadding(padH, padV, padH, padV)
            setBackgroundColor(0xFF14131A.toInt())
        }

        // Ribbon chọn thông số râu chuyên sâu (Đậm nhạt, Độ dày mỏng, Độ rộng, Cao thấp C++)
        beardTuningScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            visibility = View.GONE
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (6 * density).toInt()
            }
            layoutParams = lp
        }
        beardTuningContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
        }
        beardTuningScroll.addView(beardTuningContainer)

        fun createBeardChip(title: String): TextView {
            return TextView(this).apply {
                text = title
                textSize = 10.5f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
                val padH = (10 * density).toInt()
                val padV = (4 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    rightMargin = (6 * density).toInt()
                }
                layoutParams = lp
            }
        }

        chipBeardIntensity = createBeardChip("🎚️ Đậm Nhạt (85%)").apply {
            setOnClickListener { switchBeardParamMode("intensity", density) }
        }
        chipBeardThickness = createBeardChip("📏 Độ Dày (100%)").apply {
            setOnClickListener { switchBeardParamMode("thickness", density) }
        }
        chipBeardWidth = createBeardChip("↔️ Độ Rộng (100%)").apply {
            setOnClickListener { switchBeardParamMode("width", density) }
        }
        chipBeardHeight = createBeardChip("↕️ Cao Thấp (0px)").apply {
            setOnClickListener { switchBeardParamMode("height", density) }
        }
        chipBeardHorizontal = createBeardChip("↔️ Trái Phải (0px)").apply {
            setOnClickListener { switchBeardParamMode("horizontal", density) }
        }

        beardTuningContainer.addView(chipBeardIntensity)
        beardTuningContainer.addView(chipBeardThickness)
        beardTuningContainer.addView(chipBeardWidth)
        beardTuningContainer.addView(chipBeardHeight)
        beardTuningContainer.addView(chipBeardHorizontal)
                sliderContainer.addView(beardTuningScroll)

        // Palette đổi màu & nhuộm râu chuyên sâu
        beardColorScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            visibility = View.GONE
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (6 * density).toInt()
            }
            layoutParams = lp
        }
        beardColorContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
        }
        beardColorScroll.addView(beardColorContainer)

        beardColorList.forEach { opt ->
            val tv = TextView(this).apply {
                text = opt.name
                textSize = 9.5f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
                val padH = (8 * density).toInt()
                val padV = (3 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    rightMargin = (5 * density).toInt()
                }
                layoutParams = lp
                setOnClickListener {
                    isBeardDyeCustomActive = !opt.isNatural
                    activeBeardR = opt.r
                    activeBeardG = opt.g
                    activeBeardB = opt.b
                    updateBeardColorChips(density)
                    applyCurrentToolToBitmap()
                }
            }
            beardColorChips.add(tv)
            beardColorContainer.addView(tv)
        }
        sliderContainer.addView(beardColorScroll)

        val sliderHeader = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
        }

        tvToolTitle = TextView(this).apply {
            text = currentToolName
            textSize = 13f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            val lp = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            layoutParams = lp
        }

        tvSliderValue = TextView(this).apply {
            text = "$currentIntensity%"
            textSize = 13f
            setTextColor(MeituColors.PrimaryPink)
            setTypeface(typeface, Typeface.BOLD)
        }

        val btnApplyStep = TextView(this).apply {
            text = "✓ Lưu Bước"
            textSize = 12f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            val padH = (10 * density).toInt()
            val padV = (4 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (12 * density)
                colors = intArrayOf(MeituColors.PrimaryPink, MeituColors.PrimaryRose)
                orientation = GradientDrawable.Orientation.LEFT_RIGHT
            }
            background = bg
            val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                leftMargin = (12 * density).toInt()
            }
            layoutParams = lp
            setOnClickListener {
                if (commitCurrentToolState()) {
                    seekBarIntensity.progress = 0
                    tvSliderValue.text = "0%"
                    tvEffectTag.text = "✅ Đã lưu: $currentToolName"
                    Toast.makeText(this@PhotoEditorActivity, "✅ Đã lưu trạng thái ảnh! Tác vụ tiếp theo sẽ thực hiện trên ảnh này.", Toast.LENGTH_SHORT).show()
                } else {
                    Toast.makeText(this@PhotoEditorActivity, "Chưa có thay đổi để lưu", Toast.LENGTH_SHORT).show()
                }
            }
        }

        sliderHeader.addView(tvToolTitle)
        sliderHeader.addView(tvSliderValue)
        sliderHeader.addView(btnApplyStep)
        sliderContainer.addView(sliderHeader)

        val seekBarWrapper = FrameLayout(this).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT)
        }
        val centerTick = View(this).apply {
            val tickWidth = (2 * density).toInt()
            val tickHeight = (14 * density).toInt()
            val lp = FrameLayout.LayoutParams(tickWidth, tickHeight, Gravity.CENTER)
            layoutParams = lp
            setBackgroundColor(0x88FFFFFF.toInt())
        }
        seekBarIntensity = SeekBar(this).apply {
            min = -100
            max = 100
            progress = currentIntensity
            setPadding(0, (6 * density).toInt(), 0, (6 * density).toInt())
            setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
                override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                    if (currentToolId.startsWith("tool_beard") || currentToolId.startsWith("tool_preset_beard_")) {
                        when (beardParamMode) {
                            "thickness" -> {
                                beardThicknessVal = progress
                                tvSliderValue.text = "$progress%"
                                tvEffectTag.text = "✨ Độ Dày Mỏng Râu ($progress%)"
                            }
                            "width" -> {
                                beardWidthVal = progress
                                tvSliderValue.text = "$progress%"
                                tvEffectTag.text = "✨ Độ Rộng Râu ($progress%)"
                            }
                            "height" -> {
                                beardHeightOffsetVal = progress
                                tvSliderValue.text = "${progress}px"
                                tvEffectTag.text = "✨ Cao Thấp Râu (${progress}px)"
                                updateBeardPosHud()
                            }
                            "horizontal" -> {
                                beardHorizontalOffsetVal = progress
                                tvSliderValue.text = "${progress}px"
                                tvEffectTag.text = "✨ Vị Trí Trái Phải (${progress}px)"
                                updateBeardPosHud()
                            }
                            else -> {
                                beardIntensity = progress
                                tvSliderValue.text = "$progress%"
                                tvEffectTag.text = "✨ $currentToolName ($progress%)"
                            }
                        }
                        updateBeardTuningChips(density)
                    } else {
                        currentIntensity = progress
                        tvSliderValue.text = formatSliderText(progress, "%")
                        if (progress != 0) {
                            tvSliderValue.setTextColor(MeituColors.PrimaryPink)
                        } else {
                            tvSliderValue.setTextColor(Color.WHITE)
                        }
                        tvEffectTag.text = "✨ $currentToolName (${formatSliderText(progress, "%")})"
                    }
                    applyCurrentToolToBitmap()
                }

                override fun onStartTrackingTouch(seekBar: SeekBar?) {}
                override fun onStopTrackingTouch(seekBar: SeekBar?) {
                    // Preview tức thì đã được cập nhật. Trạng thái sẽ tự động lưu khi chuyển tác vụ hoặc bấm "✓ Lưu Bước"
                }
            })
        }
        seekBarWrapper.addView(centerTick)
        seekBarWrapper.addView(seekBarIntensity)
        sliderContainer.addView(seekBarWrapper)
        root.addView(sliderContainer)

        // 4. Sub-Tools Horizontal Scroll
        subToolsScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            setBackgroundColor(0xFF100F15.toInt())
        }
        subToolsContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            val pad = (6 * density).toInt()
            setPadding(pad, pad, pad, pad)
        }
        subToolsScroll.addView(subToolsContainer)
        root.addView(subToolsScroll)

        // 5. Category Tabs Ribbon
        categoryScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            setBackgroundColor(0xFF14131A.toInt())
        }
        categoryContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            val pad = (4 * density).toInt()
            setPadding(pad, pad, pad, pad)
        }
        categoryScroll.addView(categoryContainer)
        root.addView(categoryScroll)

        // Tự động căn chỉnh khoảng cách an toàn cho Status Bar và Navigation Bar của điện thoại
        root.setOnApplyWindowInsetsListener { _, insets ->
            topBar.setPadding(
                (14 * density).toInt(),
                (10 * density).toInt() + insets.systemWindowInsetTop,
                (14 * density).toInt(),
                (10 * density).toInt()
            )
            categoryScroll.setPadding(
                0,
                0,
                0,
                insets.systemWindowInsetBottom
            )
            insets
        }

        setContentView(root)

        buildCategoryTabs(density)
        selectCategory(categories[0], density)
        handleIntent(intent, density)
    }

    override fun onNewIntent(intent: Intent?) {
        super.onNewIntent(intent)
        setIntent(intent)
        handleIntent(intent, resources.displayMetrics.density)
    }

    private fun handleIntent(intent: Intent?, density: Float) {
        Log.i("PhotoEditorActivity", "=== handleIntent called with intent=$intent ===")
        if (intent == null) return
        val imagePath = intent.getStringExtra("image_path")
        if (imagePath != null && java.io.File(imagePath).exists()) {
            try {
                val b = BitmapFactory.decodeFile(imagePath)
                if (b != null) {
                    loadUserPhoto(b)
                }
            } catch (_: Throwable) {}
        }

        if (intent.getBooleanExtra("run_hce_benchmark", false)) {
            val benchBmp = if (::originalBitmap.isInitialized) originalBitmap else if (::currentProcessedBitmap.isInitialized) currentProcessedBitmap else null
            if (benchBmp != null) {
                val iter = intent.getIntExtra("benchmark_iterations", 3)
                val benchRes = MeituNativeEngine.nativeRunHceDeviceBenchmark(benchBmp, iter)
                Log.i("PhotoEditorActivity", "[HCE_DEVICE_BENCHMARK_RESULT] $benchRes")
            }
        }

        handleEditorIntent(intent, density)
    }

    private fun handleEditorIntent(intent: Intent, density: Float) {
        val targetCatId = intent.getStringExtra("target_category")
        val targetToolId = intent.getStringExtra("tool_id")
        val targetIntensity = intent.getIntExtra("intensity", -999)
        Log.i("PhotoEditorActivity", "handleIntent: targetCatId=$targetCatId, targetToolId=$targetToolId, targetIntensity=$targetIntensity")

        var matchedCat: CategoryItem? = null
        var matchedTool: ToolItem? = null

        if (targetToolId != null) {
            for (cat in categories) {
                val t = cat.tools.find { it.id == targetToolId }
                if (t != null) {
                    matchedCat = cat
                    matchedTool = t
                    break
                }
            }
        }

        if (matchedCat == null && targetCatId != null) {
            matchedCat = categories.find { it.id == targetCatId || (targetCatId == "cat_hair_beard" && it.id == "cat_hair") }
            matchedTool = matchedCat?.tools?.firstOrNull()
        }

        if (matchedCat != null && matchedTool != null) {
            commitCurrentToolState()
            currentCategory = matchedCat.title
            currentToolId = matchedTool.id
            currentToolName = matchedTool.name
            currentToolEn = matchedTool.nameEn
            currentNativeLib = matchedTool.nativeLib
            currentIntensity = if (targetIntensity != -999) targetIntensity else (if (matchedTool.defaultVal != 0) matchedTool.defaultVal else 75)

            buildCategoryTabs(density)
            selectCategory(matchedCat, density)

            // Khẳng định lại tool và intensity chính xác sau khi danh mục được nạp
            currentToolId = matchedTool.id
            currentToolName = matchedTool.name
            currentToolEn = matchedTool.nameEn
            currentNativeLib = matchedTool.nativeLib
            currentIntensity = if (targetIntensity != -999) targetIntensity else (if (matchedTool.defaultVal != 0) matchedTool.defaultVal else 75)

            tvToolTitle.text = matchedTool.name
            tvSliderValue.text = "${currentIntensity}${matchedTool.unit}"
            seekBarIntensity.min = matchedTool.minVal
            seekBarIntensity.max = matchedTool.maxVal
            seekBarIntensity.progress = currentIntensity
            tvEffectTag.text = "✨ ${matchedTool.name} (${currentIntensity}${matchedTool.unit})"
            tvNativeLibInfo.text = "⚡ 100% C++ Engine • ${matchedTool.nativeLib} • OpenMP"

            applyCurrentToolToBitmap()

            val autoSavePath = intent.getStringExtra("auto_save_path")
            if (autoSavePath != null) {
                try {
                    val f = if (autoSavePath.startsWith("/")) {
                        val baseName = java.io.File(autoSavePath).name
                        java.io.File(getExternalFilesDir(null) ?: filesDir, baseName)
                    } else {
                        java.io.File(getExternalFilesDir(null) ?: filesDir, autoSavePath)
                    }
                    java.io.FileOutputStream(f).use { fos ->
                        currentProcessedBitmap.compress(Bitmap.CompressFormat.PNG, 100, fos)
                        fos.flush()
                    }
                    Log.i("PhotoEditorActivity", "Auto-saved lossless PNG to " + f.absolutePath)
                } catch (e: Exception) {
                    Log.e("PhotoEditorActivity", "Failed to auto-save to $autoSavePath", e)
                }
            }

            categoryScroll.post {
                val index = categories.indexOf(matchedCat)
                if (index >= 0 && index < categoryContainer.childCount) {
                    val child = categoryContainer.getChildAt(index)
                    categoryScroll.smoothScrollTo(child.left, 0)
                }
            }
            subToolsScroll.post {
                val toolIndex = matchedCat.tools.indexOf(matchedTool)
                if (toolIndex >= 0 && toolIndex < subToolsContainer.childCount) {
                    val child = subToolsContainer.getChildAt(toolIndex)
                    subToolsScroll.smoothScrollTo(child.left, 0)
                }
            }
        }
    }

    private fun pickPhotoFromGallery() {
        val intent = Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI)
        try {
            startActivityForResult(intent, REQUEST_PICK_IMAGE)
        } catch (e: Exception) {
            Toast.makeText(this, "Không thể mở bộ sưu tập: " + e.message, Toast.LENGTH_SHORT).show()
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (requestCode == REQUEST_PICK_IMAGE && resultCode == RESULT_OK && data?.data != null) {
            val uri: Uri = data.data!!
            try {
                val inputStream: InputStream? = contentResolver.openInputStream(uri)
                val pickedBmp = BitmapFactory.decodeStream(inputStream)
                inputStream?.close()
                if (pickedBmp != null) {
                    loadUserPhoto(pickedBmp)
                    Toast.makeText(this, "✅ Đã nạp ảnh thành công: ${pickedBmp.width}x${pickedBmp.height}", Toast.LENGTH_SHORT).show()
                }
            } catch (e: Exception) {
                Toast.makeText(this, "Lỗi đọc ảnh: " + e.message, Toast.LENGTH_SHORT).show()
            }
        }
    }

    private fun loadUserPhoto(bmp: Bitmap) {
        val maxDim = 1280
        val scale = min(1.0f, maxDim.toFloat() / max(bmp.width, bmp.height))
        val targetW = (bmp.width * scale).toInt()
        val targetH = (bmp.height * scale).toInt()
        val scaled = Bitmap.createScaledBitmap(bmp, targetW, targetH, true)

        rawOriginalBitmap = scaled.copy(Bitmap.Config.ARGB_8888, true)
        originalBitmap = rawOriginalBitmap
        baseLayerBitmap = rawOriginalBitmap.copy(Bitmap.Config.ARGB_8888, true)
        currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)

        recomputeLandmarks(baseLayerBitmap.width, baseLayerBitmap.height)

        undoStack.clear()
        redoStack.clear()

        if (currentIntensity != 0) {
            applyCurrentToolToBitmap()
        } else {
            ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
        }
    }

    /**
     * Tự động điều chỉnh tọa độ giải phẫu khuôn mặt theo kích thước ảnh thật
     */
    private fun recomputeLandmarks(width: Int, height: Int) {
        val sx = width.toFloat() / 896f
        val sy = height.toFloat() / 1200f

        // Tọa độ giải phẫu chân dung 8K chuẩn xác 100%
        lxEye = 336f * sx
        lyEye = 455f * sy
        rxEye = 558f * sx
        ryEye = 455f * sy
        noseX = 455f * sx
        noseY = 570f * sy
        mouthX = 455f * sx
        mouthY = 680f * sy
        chinX = 455f * sx
        chinY = 810f * sy
        lJawX = 260f * sx
        lJawY = 640f * sy
        rJawX = 650f * sx
        rJawY = 640f * sy
        lEarX = 195f * sx
        lEarY = 490f * sy
        rEarX = 700f * sx
        rEarY = 490f * sy

        hasRealFace = false
        // Thử chạy AI Face Detector 106 điểm nếu có và hợp lệ
        try {
            val faceRes = faceDetector.detect(baseLayerBitmap)
            if (faceRes != null && faceRes.faceCount > 0 && faceRes.landmarks106.isNotEmpty()) {
                hasRealFace = true
                landmarks106 = FloatArray(faceRes.landmarks106.size * 2)
                for (i in faceRes.landmarks106.indices) {
                    landmarks106[i * 2] = faceRes.landmarks106[i].x
                    landmarks106[i * 2 + 1] = faceRes.landmarks106[i].y
                }
                detectedIrisTrack = faceRes.irisTrack
                detectedLeftSmileLine = faceRes.leftSmileLine
                detectedRightSmileLine = faceRes.rightSmileLine
                detectedCanthusPoints = faceRes.canthusPoints
                detectedDenseMesh478 = faceRes.denseMesh478
                Log.i("PhotoEditorActivity", "Loaded FaceRes: iris=$detectedIrisTrack, canthus=${detectedCanthusPoints?.size}, smileL=${detectedLeftSmileLine?.size}, smileR=${detectedRightSmileLine?.size}")
                
                if (landmarks106.size >= 106 * 2) {
                    // GROUND TRUTH 106-Point Model Anatomy:
                    // Chin: 16 (tip)
                    chinX = landmarks106[16 * 2]
                    chinY = landmarks106[16 * 2 + 1]
                    // Jaw angles (V-Line): 8 (left jaw corner) & 24 (right jaw corner)
                    lJawX = landmarks106[8 * 2]
                    lJawY = landmarks106[8 * 2 + 1]
                    rJawX = landmarks106[24 * 2]
                    rJawY = landmarks106[24 * 2 + 1]
                    // Nose: 60 (tip), 57 (left alar), 63 (right alar)
                    noseX = landmarks106[60 * 2]
                    noseY = landmarks106[60 * 2 + 1]
                    // Mouth: 84 (left corner), 90 (right corner), 87 (upper lip), 93 (lower lip)
                    mouthX = (landmarks106[84 * 2] + landmarks106[90 * 2]) * 0.5f
                    mouthY = (landmarks106[87 * 2 + 1] + landmarks106[93 * 2 + 1]) * 0.5f
                    // Eyes: 104 (left pupil), 105 (right pupil)
                    lxEye = detectedIrisTrack?.leftCenterX ?: landmarks106[104 * 2]
                    lyEye = detectedIrisTrack?.leftCenterY ?: landmarks106[104 * 2 + 1]
                    rxEye = detectedIrisTrack?.rightCenterX ?: landmarks106[105 * 2]
                    ryEye = detectedIrisTrack?.rightCenterY ?: landmarks106[105 * 2 + 1]
                    val earInitRep = landmarks106.let {
                        MeituNativeEngine.getEarAnatomyReport(baseLayerBitmap, it, baseLayerBitmap.width, baseLayerBitmap.height)
                    }
                    val eyeDist = kotlin.math.hypot(rxEye - lxEye, ryEye - lyEye)
                    val defaultLeftEarX = landmarks106[0 * 2] - 0.22f * eyeDist
                    val defaultLeftEarY = (landmarks106[0 * 2 + 1] + landmarks106[4 * 2 + 1]) * 0.5f
                    val defaultRightEarX = landmarks106[32 * 2] + 0.22f * eyeDist
                    val defaultRightEarY = (landmarks106[32 * 2 + 1] + landmarks106[28 * 2 + 1]) * 0.5f

                    if (earInitRep != null && earInitRep.isValid && (earInitRep.leftEarCenterX > 10f || earInitRep.rightEarCenterX > 10f)) {
                        lEarX = if (earInitRep.isLeftEarVisible && earInitRep.leftEarCenterX > 10f) earInitRep.leftEarCenterX else 0.0f
                        lEarY = if (earInitRep.isLeftEarVisible && earInitRep.leftEarCenterY > 10f) earInitRep.leftEarCenterY else 0.0f
                        rEarX = if (earInitRep.isRightEarVisible && earInitRep.rightEarCenterX > 10f) earInitRep.rightEarCenterX else 0.0f
                        rEarY = if (earInitRep.isRightEarVisible && earInitRep.rightEarCenterY > 10f) earInitRep.rightEarCenterY else 0.0f
                    } else {
                        lEarX = 0.0f
                        lEarY = 0.0f
                        rEarX = 0.0f
                        rEarY = 0.0f
                    }
                    Log.i("PhotoEditorActivity", "Extracted landmarks: nose=($noseX,$noseY), mouth=($mouthX,$mouthY), chin=($chinX,$chinY), eyes=(L:$lxEye,$lyEye, R:$rxEye,$ryEye), ears=(L:$lEarX,$lEarY, R:$rEarX,$rEarY)")
                    try {
                        val sb = StringBuilder()
                        for (idx in 0 until 106) {
                            sb.append("$idx: (${landmarks106[idx * 2]}, ${landmarks106[idx * 2 + 1]})\n")
                        }
                        java.io.File(filesDir, "landmarks_dump.txt").writeText(sb.toString())
                    } catch (_: Throwable) {}

                    // ĐỒNG BỘ 100% SANG C++ LANDMARK FUSION ENGINE
                    var minX = Float.MAX_VALUE
                    var maxX = Float.MIN_VALUE
                    var minY = Float.MAX_VALUE
                    var maxY = Float.MIN_VALUE
                    for (idx in 0 until 106) {
                        val x = landmarks106[idx * 2]
                        val y = landmarks106[idx * 2 + 1]
                        if (x < minX) minX = x
                        if (x > maxX) maxX = x
                        if (y < minY) minY = y
                        if (y > maxY) maxY = y
                    }
                    MeituNativeEngine.nativeUpdateFaceGeometry(
                        landmarks106,
                        detectedDenseMesh478,
                        minX, minY, maxX, maxY
                    )
                }
                return
            }
        } catch (_: Throwable) {}

        // Khởi tạo tọa độ 106 điểm mẫu giải phẫu chuẩn phân bố chính xác trên từng bộ phận khuôn mặt
        var fallbackCx = 455f * sx
        var fallbackCy = 570f * sy
        var fallbackRx = 200f * sx
        var fallbackRy = 240f * sy

        // Quét tìm cụm khuôn mặt thật ở 45% phần trên bức ảnh (chống lệch xuống ngực/bụng ở ảnh body)
        try {
            val step = 16
            var skinXSum = 0L
            var skinYSum = 0L
            var skinCnt = 0
            val maxScanY = (baseLayerBitmap.height * 0.45f).toInt()
            for (py in 20 until maxScanY step step) {
                for (px in 20 until baseLayerBitmap.width - 20 step step) {
                    val color = baseLayerBitmap.getPixel(px, py)
                    val r = (color shr 16) and 0xFF
                    val g = (color shr 8) and 0xFF
                    val b = color and 0xFF
                    if (r > 60 && g > 40 && b > 25 && r > b && (r - g) >= 10 && (r - b) >= 15) {
                        skinXSum += px
                        skinYSum += py
                        skinCnt++
                    }
                }
            }
            if (skinCnt > 15) {
                fallbackCx = (skinXSum / skinCnt).toFloat()
                fallbackCy = (skinYSum / skinCnt).toFloat()
                fallbackRx = (baseLayerBitmap.width * 0.16f).coerceIn(80f, 250f)
                fallbackRy = (baseLayerBitmap.height * 0.14f).coerceIn(90f, 300f)
                chinX = fallbackCx
                chinY = fallbackCy + fallbackRy * 0.85f
                noseX = fallbackCx
                noseY = fallbackCy
                lxEye = fallbackCx - fallbackRx * 0.45f
                lyEye = fallbackCy - fallbackRy * 0.35f
                rxEye = fallbackCx + fallbackRx * 0.45f
                ryEye = fallbackCy - fallbackRy * 0.35f
                mouthX = fallbackCx
                mouthY = fallbackCy + fallbackRy * 0.45f
                lJawX = fallbackCx - fallbackRx * 0.85f
                lJawY = fallbackCy + fallbackRy * 0.30f
                rJawX = fallbackCx + fallbackRx * 0.85f
                rJawY = fallbackCy + fallbackRy * 0.30f
            }
        } catch (_: Throwable) {}

        landmarks106 = FloatArray(106 * 2)
        // 0..32: Đường viền khuôn mặt (Face Contour từ thái dương -> quai hàm -> cằm -> thái dương phải)
        for (i in 0..32) {
            val t = i.toFloat() / 32f
            val angle = Math.PI * (1.0 - t)
            landmarks106[i * 2] = fallbackCx + fallbackRx * Math.cos(angle).toFloat()
            landmarks106[i * 2 + 1] = fallbackCy + fallbackRy * Math.sin(angle).toFloat()
        }
        // Gắn chính xác các điểm then chốt vào cấu trúc giải phẫu chuẩn
        landmarks106[4 * 2] = lJawX
        landmarks106[4 * 2 + 1] = lJawY
        landmarks106[16 * 2] = chinX
        landmarks106[16 * 2 + 1] = chinY
        landmarks106[28 * 2] = rJawX
        landmarks106[28 * 2 + 1] = rJawY
        landmarks106[38 * 2] = lxEye
        landmarks106[38 * 2 + 1] = lyEye
        landmarks106[57 * 2] = rxEye
        landmarks106[57 * 2 + 1] = ryEye
        landmarks106[46 * 2] = noseX
        landmarks106[46 * 2 + 1] = noseY
        landmarks106[72 * 2] = mouthX - 75f * sx
        landmarks106[72 * 2 + 1] = mouthY
        landmarks106[80 * 2] = mouthX + 75f * sx
        landmarks106[80 * 2 + 1] = mouthY
        landmarks106[76 * 2] = mouthX
        landmarks106[76 * 2 + 1] = mouthY + 20f * sy
        landmarks106[82 * 2] = mouthX
        landmarks106[82 * 2 + 1] = mouthY - 15f * sy

        // Fallback: Khi không có khuôn mặt trực diện (ảnh chụp nghiêng, profile, cận cảnh tai...)
        // Dùng thuật toán C++ TeethEarEngine::analyzeEarAnatomy với pixel-level outer helix boundary
        val earFallbackRep = MeituNativeEngine.getEarAnatomyReport(baseLayerBitmap, null, baseLayerBitmap.width, baseLayerBitmap.height)
        if (earFallbackRep != null && earFallbackRep.isValid) {
            if (earFallbackRep.isLeftEarVisible) {
                lEarX = earFallbackRep.leftEarCenterX
                lEarY = earFallbackRep.leftEarCenterY
            }
            if (earFallbackRep.isRightEarVisible) {
                rEarX = earFallbackRep.rightEarCenterX
                rEarY = earFallbackRep.rightEarCenterY
            }
            Log.i("PhotoEditorActivity", "Fallback ear detected: L=($lEarX,$lEarY, vis=${earFallbackRep.isLeftEarVisible}), R=($rEarX,$rEarY, vis=${earFallbackRep.isRightEarVisible}), radius=${earFallbackRep.earRadius}")
        }

        // ĐỒNG BỘ FALLBACK LANDMARKS SANG C++ LANDMARK FUSION ENGINE
        var minX = Float.MAX_VALUE
        var maxX = Float.MIN_VALUE
        var minY = Float.MAX_VALUE
        var maxY = Float.MIN_VALUE
        for (idx in 0 until 106) {
            val x = landmarks106[idx * 2]
            val y = landmarks106[idx * 2 + 1]
            if (x < minX) minX = x
            if (x > maxX) maxX = x
            if (y < minY) minY = y
            if (y > maxY) maxY = y
        }
        MeituNativeEngine.nativeUpdateFaceGeometry(
            landmarks106,
            null,
            minX, minY, maxX, maxY
        )
    }

    /**
     * Khởi tạo ảnh chân dung ban đầu chất lượng cao 8K từ assets (sample_model_portrait.jpg)
     */
    private fun initDefaultPortraitPhoto() {
        var loadedBmp: Bitmap? = null

        // 0. Ưu tiên nạp ảnh chân dung mẫu 0.jpg từ assets
        try {
            assets.open("sample_model_portrait.jpg").use { inputStream ->
                loadedBmp = BitmapFactory.decodeStream(inputStream)
                if (loadedBmp != null) {
                    Log.i("PhotoEditorActivity", "✅ Loaded default customer portrait 0.jpg from assets (${loadedBmp?.width}x${loadedBmp?.height})")
                }
            }
        } catch (_: Throwable) {}

        // 1. Thử nạp từ internal storage nếu có
        if (loadedBmp == null) {
            val candidateFiles = listOf(
                java.io.File(filesDir, "user_portrait.jpg"),
                java.io.File("/sdcard/user_portrait.jpg")
            )
            for (f in candidateFiles) {
                if (f.exists()) {
                    try {
                        val b = BitmapFactory.decodeFile(f.absolutePath)
                        if (b != null) {
                            loadedBmp = b
                            Log.i("PhotoEditorActivity", "✅ Loaded user portrait from: ${f.absolutePath} (${b.width}x${b.height})")
                            break
                        }
                    } catch (_: Throwable) {}
                }
            }
        }

        // 2. Thử nạp từ drawable nếu assets chưa có
        if (loadedBmp == null) {
            try {
                val resId = resources.getIdentifier("sample_model_portrait", "drawable", packageName)
                if (resId != 0) {
                    loadedBmp = BitmapFactory.decodeResource(resources, resId)
                }
            } catch (_: Throwable) {}
        }

        // 3. Fallback gradient cao cấp nếu cả 2 cách trên không nạp được
        if (loadedBmp == null) {
            val w = 896
            val h = 1200
            val bmp = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888)
            val canvas = Canvas(bmp)
            val bgPaint = Paint().apply {
                shader = LinearGradient(0f, 0f, 0f, h.toFloat(), 0xFF352B42.toInt(), 0xFF14121A.toInt(), Shader.TileMode.CLAMP)
            }
            canvas.drawRect(0f, 0f, w.toFloat(), h.toFloat(), bgPaint)
            loadedBmp = bmp
        }

        rawOriginalBitmap = loadedBmp!!.copy(Bitmap.Config.ARGB_8888, true)
        originalBitmap = rawOriginalBitmap
        baseLayerBitmap = rawOriginalBitmap.copy(Bitmap.Config.ARGB_8888, true)
        currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)

        recomputeLandmarks(baseLayerBitmap.width, baseLayerBitmap.height)
    }

    /**
     * Lưu trạng thái chỉnh sửa hiện tại vào lớp ảnh nền tích lũy (baseLayerBitmap).
     * Khi người dùng chuyển sang công cụ hoặc danh mục khác, các thay đổi sẽ được giữ nguyên 100%,
     * và tác vụ tiếp theo sẽ tiếp tục chỉnh sửa trên ảnh đã lưu trạng thái này.
     */
    private fun commitCurrentToolState(): Boolean {
        val isModified = (currentIntensity != 0) ||
                isBeardDyeCustomActive ||
                (beardHorizontalOffsetVal != 0) ||
                (beardHeightOffsetVal != 0) ||
                (currentToolId == "tool_id_bg_white" || currentToolId == "tool_id_bg_blue")

        if (isModified && ::currentProcessedBitmap.isInitialized && ::baseLayerBitmap.isInitialized) {
            pushUndoState(baseLayerBitmap)
            baseLayerBitmap = currentProcessedBitmap.copy(Bitmap.Config.ARGB_8888, true)
            recomputeLandmarks(baseLayerBitmap.width, baseLayerBitmap.height)

            // Đặt lại các biến điều khiển công cụ về trung tính
            currentIntensity = 0
            isBeardDyeCustomActive = false
            beardHorizontalOffsetVal = 0
            beardHeightOffsetVal = 0
            return true
        }
        return false
    }

    private fun pushUndoState(bmp: Bitmap) {
        if (undoStack.size >= MAX_UNDO_STACK) {
            val oldest = undoStack.removeAt(0)
            if (!oldest.isRecycled && oldest != rawOriginalBitmap && oldest != baseLayerBitmap && oldest != currentProcessedBitmap) {
                oldest.recycle()
            }
        }
        undoStack.push(bmp.copy(Bitmap.Config.ARGB_8888, true))
        redoStack.clear()
    }

    private fun performUndo() {
        if (currentIntensity != 0 || isBeardDyeCustomActive || beardHorizontalOffsetVal != 0 || beardHeightOffsetVal != 0) {
            currentIntensity = 0
            isBeardDyeCustomActive = false
            beardHorizontalOffsetVal = 0
            beardHeightOffsetVal = 0
            seekBarIntensity.progress = 0
            tvSliderValue.text = "0%"
            currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)
            ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
            tvEffectTag.text = "✨ $currentToolName (0%)"
            Toast.makeText(this, "↩️ Đã hủy điều chỉnh hiện tại", Toast.LENGTH_SHORT).show()
            return
        }
        if (undoStack.isNotEmpty()) {
            val prev = undoStack.pop()
            redoStack.push(baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true))
            baseLayerBitmap = prev.copy(Bitmap.Config.ARGB_8888, true)
            currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)
            recomputeLandmarks(baseLayerBitmap.width, baseLayerBitmap.height)
            ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
            Toast.makeText(this, "↩️ Đã hoàn tác bước trước", Toast.LENGTH_SHORT).show()
        } else {
            Toast.makeText(this, "Không còn thao tác để hoàn tác", Toast.LENGTH_SHORT).show()
        }
    }

    private fun performRedo() {
        if (redoStack.isNotEmpty()) {
            val next = redoStack.pop()
            undoStack.push(baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true))
            baseLayerBitmap = next.copy(Bitmap.Config.ARGB_8888, true)
            currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)
            currentIntensity = 0
            seekBarIntensity.progress = 0
            tvSliderValue.text = "0%"
            tvEffectTag.text = "✨ $currentToolName (0%)"
            recomputeLandmarks(baseLayerBitmap.width, baseLayerBitmap.height)
            ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
            Toast.makeText(this, "↪️ Đã làm lại bước tiếp theo", Toast.LENGTH_SHORT).show()
        } else {
            Toast.makeText(this, "Không có thao tác để làm lại", Toast.LENGTH_SHORT).show()
        }
    }

    private fun saveAndExportImage() {
        val bmp = currentProcessedBitmap
        val filename = "MEITU_PORTRAIT_${System.currentTimeMillis()}.jpg"
        try {
            val dir = getExternalFilesDir(android.os.Environment.DIRECTORY_PICTURES) ?: filesDir
            val file = java.io.File(dir, filename)
            java.io.FileOutputStream(file).use { fos ->
                bmp.compress(Bitmap.CompressFormat.JPEG, 98, fos)
                fos.flush()
            }

            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.Q) {
                val values = android.content.ContentValues().apply {
                    put(MediaStore.Images.Media.DISPLAY_NAME, filename)
                    put(MediaStore.Images.Media.MIME_TYPE, "image/jpeg")
                    put(MediaStore.Images.Media.RELATIVE_PATH, android.os.Environment.DIRECTORY_PICTURES + "/MeituReborn")
                    put(MediaStore.Images.Media.IS_PENDING, 1)
                }
                val uri = contentResolver.insert(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, values)
                if (uri != null) {
                    contentResolver.openOutputStream(uri)?.use { out ->
                        bmp.compress(Bitmap.CompressFormat.JPEG, 98, out)
                    }
                    values.clear()
                    values.put(MediaStore.Images.Media.IS_PENDING, 0)
                    contentResolver.update(uri, values, null, null)
                }
            } else {
                @Suppress("DEPRECATION")
                MediaStore.Images.Media.insertImage(contentResolver, file.absolutePath, filename, "Meitu Reborn Portrait")
            }

            Toast.makeText(this, "✅ Đã xuất ảnh chất lượng cao vào Thư Viện: ${file.name}", Toast.LENGTH_LONG).show()
        } catch (e: Exception) {
            Toast.makeText(this, "Lỗi khi lưu ảnh: ${e.message}", Toast.LENGTH_SHORT).show()
        }
    }

    /**
     * THI HÀNH 100% THUẬT TOÁN C++ NATIVE ENGINE CHO TẤT CẢ CÔNG CỤ TRÊN ẢNH CHÂN DUNG THẬT
     */

    private fun applyIrisColorOrLegacy(bitmap: Bitmap, toneId: Int, p: Float, lx: Float, ly: Float, rx: Float, ry: Float) {
        if (detectedIrisTrack != null) {
            val iris = detectedIrisTrack!!
            MeituNativeEngine.nativeApplyIrisMakeup(
                bitmap,
                iris.leftCenterX, iris.leftCenterY, iris.leftRadius,
                iris.rightCenterX, iris.rightCenterY, iris.rightRadius,
                0f, 0.4f * p, toneId, p, 0, 0f
            )
        } else {
            MeituNativeEngine.nativeApplyEyeColor(bitmap, lx, ly, rx, ry, toneId, p)
        }
    }

    private fun applyCatchlightOrLegacy(bitmap: Bitmap, typeId: Int, p: Float, lx: Float, ly: Float, rx: Float, ry: Float) {
        if (detectedIrisTrack != null) {
            val iris = detectedIrisTrack!!
            MeituNativeEngine.nativeApplyIrisMakeup(
                bitmap,
                iris.leftCenterX, iris.leftCenterY, iris.leftRadius,
                iris.rightCenterX, iris.rightCenterY, iris.rightRadius,
                0f, 0.5f * p, 0, 0f, typeId, p
            )
        } else {
            MeituNativeEngine.nativeApplyEyeCatchlight(bitmap, lx, ly, rx, ry, typeId, p)
        }
    }

    private fun applyCurrentToolToBitmap() {
        // Mức 0 trung tính: hiển thị ảnh nền tích lũy hiện tại, không tính toán dư thừa
        if (currentIntensity == 0 && !isBeardDyeCustomActive && beardHorizontalOffsetVal == 0 && beardHeightOffsetVal == 0 && currentToolId != "tool_id_bg_white" && currentToolId != "tool_id_bg_blue") {
            currentProcessedBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)
            ivCanvasPreview.setImageBitmap(currentProcessedBitmap)
            return
        }
        val workingBitmap = baseLayerBitmap.copy(Bitmap.Config.ARGB_8888, true)
        val factor = currentIntensity.toFloat()
        val p = factor / 100f
        val sx = workingBitmap.width.toFloat() / 896f
        Log.i("PhotoEditorActivity", "applyCurrentToolToBitmap: tool=$currentToolId, intensity=$currentIntensity, p=$p, iris=$detectedIrisTrack, canthus=${detectedCanthusPoints?.size}, smile=${detectedLeftSmileLine?.size}")

        when (currentToolId) {
            // ================= 1. KHUÔN MẶT (FACE & RATIO) — MTARBeautyParm.java =================
            "tool_hd_portrait" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 200007, p)
            }
            "tool_auto_face" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 200000, p)
            }
            "tool_face_width" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4112, p)
            }
            "tool_face_lift", "tool_face_vshape" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4679, p)
            }
            "tool_face_smooth" -> {
                MeituNativeEngine.nativeApplyLocalizedSkinBilateral(workingBitmap, noseX, noseY - 20f * sx, 240f * sx, 300f * sx, p, 0f)
            }
            "tool_face_overall" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 2000099, p)
            }
            "tool_face_narrow" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4125, p)
            }
            "tool_face_small", "tool_head_size" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyHeadSkull(workingBitmap, lmk, 1, p)
                if (!ok) MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4113, p)
            }
            "tool_face_vline" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 2000014, p)
            }
            "tool_face_forehead", "tool_forehead_height" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyHeadSkull(workingBitmap, lmk, 4, p)
                if (!ok) MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4114, p)
            }
            "tool_face_cheekbone" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4638, p)
            }
            "tool_face_temple", "tool_temple_width" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyHeadSkull(workingBitmap, lmk, 3, p)
                if (!ok) MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4169, p)
            }
            "tool_face_mandible" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4180, p)
            }
            "tool_face_chin" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4690, p)
            }
            "tool_face_round_head", "tool_skull_crown" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyHeadSkull(workingBitmap, lmk, 2, p)
                if (!ok) MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 2000011, p)
            }
            "tool_face_lower" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4234, p)
            }
            "tool_face_middle" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4216, p)
            }

            // ================= 2. FACE PRESETS (Loại Khuôn Mặt — 2.2.3) =================
            "tool_preset_origin" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62149, p)
            }
            "tool_preset_finetuning" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62164, p)
            }
            "tool_preset_photogenic" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62186, p)
            }
            "tool_preset_round" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62107, p)
            }
            "tool_preset_square" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62108, p)
            }
            "tool_preset_long" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62109, p)
            }
            "tool_preset_short" -> {
                MeituNativeEngine.nativeApplyFacePreset(workingBitmap, landmarks106, 62110, p)
            }

            // ================= 3. RESHAPE 3DMM (6,330 Vertices Morph) =================
            "tool_3dmm_jaw" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 200008, p)
            }
            "tool_3dmm_chin" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4690, p)
            }
            "tool_3dmm_narrow" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4125, p)
            }
            "tool_3dmm_smile" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 600005, p)
            }
            "tool_3dmm_nose" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 400001, p)
            }
            "tool_3dmm_nose_width" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 400002, p)
            }
            "tool_3dmm_nose_bridge" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4158, p)
            }
            "tool_3dmm_nose_tip" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4159, p)
            }
            "tool_3dmm_eyes_size" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 300001, p)
            }
            "tool_3dmm_eyes_tilt" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4178, p)
            }
            "tool_3dmm_eyes_width" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4612, p)
            }
            "tool_3dmm_eyes_distance" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4109, p)
            }
            "tool_3dmm_brow_shape" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 500004, p)
            }
            "tool_3dmm_brow_thickness" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4189, p)
            }
            "tool_3dmm_brow_height" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4181, p)
            }
            "tool_3dmm_lips" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4188, p)
            }
            "tool_3dmm_upper_lip" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4130, p)
            }
            "tool_3dmm_lower_lip" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4131, p)
            }
            "tool_3dmm_symmetry" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 2000022, p)
            }
            "tool_3dmm_head" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4104, p)
            }
            "tool_3dmm_forehead" -> {
                MeituNativeEngine.nativeApply3DMMParam(workingBitmap, landmarks106, 4114, p)
            }

            // ================= 4. RESHAPE FREEFORM & RESIZES =================
            "tool_reshape_warp" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, lJawX, lJawY, lJawX + 30f * sx * p, lJawY, 140f * sx, 700001, p)
            }
            "tool_reshape_refine" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, noseX, noseY, noseX, noseY, 200f * sx, 700002, p)
            }
            "tool_reshape_resize" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, noseX, noseY, noseX, noseY + 20f * sx, 250f * sx, 700003, p)
            }
            "tool_reshape_restore" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, noseX, noseY, noseX, noseY, 300f * sx, 700004, p)
            }
            "tool_resize_head" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, noseX, lyEye - 100f * sx, noseX, lyEye - 100f * sx, 350f * sx, 800001, p)
            }
            "tool_resize_eyes" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, lxEye, lyEye, lxEye, lyEye, 90f * sx, 800002, p)
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, rxEye, ryEye, rxEye, ryEye, 90f * sx, 800002, p)
            }
            "tool_resize_nose" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, noseX, noseY, noseX, noseY, 80f * sx, 800003, p)
            }
            "tool_resize_mouth" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, mouthX, mouthY, mouthX, mouthY, 90f * sx, 800004, p)
            }
            "tool_resize_ears" -> {
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, lEarX, lEarY, lEarX - 20f * sx * p, lEarY, 90f * sx, 800005, p)
                MeituNativeEngine.nativeApplyFreeformReshape(workingBitmap, rEarX, rEarY, rEarX + 20f * sx * p, rEarY, 90f * sx, 800005, p)
            }

            // ================= 2.1 EYES - HÌNH DÁNG (2.3.1 EYE SHAPE) =================
            "tool_eye_enlarge", "tool_eyes_enlarge" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223101, p)
            }
            "tool_eye_height" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223102, p)
            }
            "tool_eye_width" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223103, p)
            }
            "tool_eye_tilt" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223104, p)
            }
            "tool_eye_updown" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223105, p)
            }
            "tool_eye_longer" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223106, p)
            }
            "tool_eye_end" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223107, p)
            }
            "tool_eye_eyelid" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223108, p)
            }
            "tool_eye_inner_corner" -> {
                if (detectedCanthusPoints != null) {
                    MeituNativeEngine.nativeAdjustCanthusDetail(workingBitmap, detectedCanthusPoints!!, p, 0f, 0f)
                } else {
                    MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223109, p)
                }
            }
            "tool_eye_outer_corner" -> {
                if (detectedCanthusPoints != null) {
                    MeituNativeEngine.nativeAdjustCanthusDetail(workingBitmap, detectedCanthusPoints!!, 0f, p, 0f)
                } else {
                    MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223110, p)
                }
            }
            "tool_eye_phoenix" -> {
                if (detectedCanthusPoints != null) {
                    MeituNativeEngine.nativeAdjustCanthusDetail(workingBitmap, detectedCanthusPoints!!, p * 0.7f, p * 1.2f, 0f)
                } else {
                    MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223111, p)
                }
            }
            "tool_eye_distance" -> {
                MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223112, p)
            }
            "tool_eye_pupil", "tool_eye_pupil_enlarge" -> {
                if (detectedIrisTrack != null) {
                    val iris = detectedIrisTrack!!
                    MeituNativeEngine.nativeApplyIrisMakeup(
                        workingBitmap,
                        iris.leftCenterX, iris.leftCenterY, iris.leftRadius,
                        iris.rightCenterX, iris.rightCenterY, iris.rightRadius,
                        p, 0f, 0, 0f, 0, 0f
                    )
                } else {
                    MeituNativeEngine.nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223113, p)
                }
            }

            // ================= 2.2 EYE EFFECTS (2.3.2 & 2.3.3 Độ Sáng & Hiệu Ứng Mắt) =================
            "tool_eye_bright" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223201, p)
            }
            "tool_eye_remove_redness", "tool_eye_redness" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223202, p)
            }
            "tool_eye_double_eyelid" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223203, p)
            }
            "tool_eye_sharpen" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223204, p)
            }
            "tool_eye_clarity" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223205, p)
            }
            "tool_eye_whiten_sclera" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223206, p)
            }
            "tool_eye_red_flash" -> {
                MeituNativeEngine.nativeApplyEyeEffect(workingBitmap, lxEye, lyEye, rxEye, ryEye, 223207, p)
            }

            // ================= 2.3 EYE COLOR (Màu Mắt 8 Tones) =================
            "tool_eye_color_natural" -> {
                applyIrisColorOrLegacy(workingBitmap, 0, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_blue" -> {
                applyIrisColorOrLegacy(workingBitmap, 1, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_green" -> {
                applyIrisColorOrLegacy(workingBitmap, 2, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_hazel" -> {
                applyIrisColorOrLegacy(workingBitmap, 3, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_gray" -> {
                applyIrisColorOrLegacy(workingBitmap, 4, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_violet" -> {
                applyIrisColorOrLegacy(workingBitmap, 5, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_amber" -> {
                applyIrisColorOrLegacy(workingBitmap, 6, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_eye_color_honey" -> {
                applyIrisColorOrLegacy(workingBitmap, 7, p, lxEye, lyEye, rxEye, ryEye)
            }

            // ================= 2.4 EYE CATCHLIGHT (8 Kiểu Ánh Sáng Phản Xạ Đồng Tử) =================
            "tool_catchlight_circle", "tool_eye_catch_light" -> {
                applyCatchlightOrLegacy(workingBitmap, 1, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_star" -> {
                applyCatchlightOrLegacy(workingBitmap, 2, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_heart" -> {
                applyCatchlightOrLegacy(workingBitmap, 3, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_softbox" -> {
                applyCatchlightOrLegacy(workingBitmap, 4, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_double_dot" -> {
                applyCatchlightOrLegacy(workingBitmap, 5, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_crescent" -> {
                applyCatchlightOrLegacy(workingBitmap, 6, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_diamond" -> {
                applyCatchlightOrLegacy(workingBitmap, 7, p, lxEye, lyEye, rxEye, ryEye)
            }
            "tool_catchlight_flower" -> {
                applyCatchlightOrLegacy(workingBitmap, 8, p, lxEye, lyEye, rxEye, ryEye)
            }

            // ================= 2.5 EYE PRESETS (Photo_13) =================
            "tool_eye_preset_origin" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 0, p)
            }
            "tool_eye_preset_spiced_tea" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 1, p)
            }
            "tool_eye_preset_tender_ai" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 2, p)
            }
            "tool_eye_preset_soft_grace" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 3, p)
            }
            "tool_eye_preset_pink_tale" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 4, p)
            }
            "tool_eye_preset_pure_crystal" -> {
                MeituNativeEngine.nativeApplyEyePreset(workingBitmap, lxEye, lyEye, rxEye, ryEye, 5, p)
            }

            // ================= 3. MŨI (2.5 NOSE) =================
            "tool_nose_shrink" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2501, p)
            }
            "tool_nose_tip" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2502, p)
            }
            "tool_nose_root" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2503, p)
            }
            "tool_nose_longer" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2504, p)
            }
            "tool_nose_resize" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2505, p)
            }
            "tool_nose_distance" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2506, p)
            }
            "tool_nose_narrow" -> {
                MeituNativeEngine.nativeApplyNoseReshape(workingBitmap, noseX, noseY, 2507, p)
            }

            // ================= 4. MIỆNG & MÔI (2.6 MOUTH / LIPS) =================
            "tool_lip_overall" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2601, p)
            }
            "tool_lip_upper" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2602, p)
            }
            "tool_lip_lower" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2603, p)
            }
            "tool_mouth_width" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2604, p)
            }
            "tool_mouth_rotate" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2605, p)
            }
            "tool_mouth_lateral" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2606, p)
            }
            "tool_philtrum_high" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1701, p)
                if (!ok) {
                    MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2607, p)
                }
            }
            "tool_philtrum_warp" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1704, p)
                if (!ok) {
                    MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2608, p)
                }
            }
            "tool_philtrum_depth" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyPhiltrumEdit(workingBitmap, lmk, 1703, p)
                if (!ok) {
                    MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2608, p)
                }
            }
            "tool_comic_mouth_m" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2609, p)
            }
            "tool_convex_mouth" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2610, p)
            }
            "tool_mouth_smile" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2611, p)
            }
            "tool_lip_bunny" -> {
                MeituNativeEngine.nativeApplyMouthReshape(workingBitmap, mouthX, mouthY, 2612, p)
            }

            // ================= 5. LÀN DA & LOẠI DA (2.7 SKIN) =================
            "tool_skin_smooth" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2701, p, landmarks106)
            }
            "tool_skin_bright" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2704, p, landmarks106)
            }
            "tool_skin_tone_rosy" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2712, p, landmarks106)
            }
            "tool_skin_tone_honey" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2713, p, landmarks106)
            }
            "tool_skin_acne" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2708, p, landmarks106)
            }
            "tool_skin_eyebags" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2705, p, landmarks106)
            }
            "tool_skin_smile_lines" -> {
                if (detectedLeftSmileLine != null && detectedRightSmileLine != null) {
                    MeituNativeEngine.nativeApplyNasolabialSmoothing(workingBitmap, detectedLeftSmileLine, detectedRightSmileLine, p)
                } else {
                    MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2706, p, landmarks106)
                }
            }
            "tool_skin_neck_lines" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2707, p, landmarks106)
            }
            "tool_skin_clear" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2703, p, landmarks106)
            }
            "tool_skin_detail" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2710, p, landmarks106)
            }
            "tool_skin_oil_control" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2709, p, landmarks106)
            }
            "tool_skin_type_oily" -> {
                MeituNativeEngine.nativeApplySkinType(workingBitmap, noseX, noseY, 260f * sx, 320f * sx, 64804, p, landmarks106)
            }
            "tool_skin_type_dry" -> {
                MeituNativeEngine.nativeApplySkinType(workingBitmap, noseX, noseY, 260f * sx, 320f * sx, 64805, p, landmarks106)
            }
            "tool_skin_type_combined" -> {
                MeituNativeEngine.nativeApplySkinType(workingBitmap, noseX, noseY, 260f * sx, 320f * sx, 64806, p, landmarks106)
            }
            "tool_skin_type_sensitive" -> {
                MeituNativeEngine.nativeApplySkinType(workingBitmap, noseX, noseY, 260f * sx, 320f * sx, 64807, p, landmarks106)
            }

            // ================= 6. CHỈNH RĂNG (2.11 TEETH) =================
            "tool_teeth_whiten", "tool_teeth_porcelain" -> {
                val mouthW = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[90 * 2] - landmarks106[84 * 2])
                } else 130f * sx
                val mouthH = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[93 * 2 + 1] - landmarks106[87 * 2 + 1])
                } else 35f * sx
                val radX = (mouthW * 0.55f).coerceAtLeast(35f * sx)
                val radY = (mouthH * 0.9f).coerceIn(18f * sx, 45f * sx)
                MeituNativeEngine.nativeApplyTeethWhitening(workingBitmap, mouthX, mouthY, radX, radY, 0, p)
            }
            "tool_teeth_ivory" -> {
                val mouthW = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[90 * 2] - landmarks106[84 * 2])
                } else 130f * sx
                val mouthH = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[93 * 2 + 1] - landmarks106[87 * 2 + 1])
                } else 35f * sx
                val radX = (mouthW * 0.55f).coerceAtLeast(35f * sx)
                val radY = (mouthH * 0.9f).coerceIn(18f * sx, 45f * sx)
                MeituNativeEngine.nativeApplyTeethWhitening(workingBitmap, mouthX, mouthY, radX, radY, 1, p)
            }
            "tool_teeth_enamel" -> {
                val mouthW = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[90 * 2] - landmarks106[84 * 2])
                } else 130f * sx
                val mouthH = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[93 * 2 + 1] - landmarks106[87 * 2 + 1])
                } else 35f * sx
                val radX = (mouthW * 0.55f).coerceAtLeast(35f * sx)
                val radY = (mouthH * 0.9f).coerceIn(18f * sx, 45f * sx)
                MeituNativeEngine.nativeApplyTeethWhitening(workingBitmap, mouthX, mouthY, radX, radY, 2, p)
            }
            "tool_teeth_align" -> {
                val mouthW = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[90 * 2] - landmarks106[84 * 2])
                } else 130f * sx
                val mouthH = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[93 * 2 + 1] - landmarks106[87 * 2 + 1])
                } else 35f * sx
                val radX = (mouthW * 0.55f).coerceAtLeast(35f * sx)
                val radY = (mouthH * 0.9f).coerceIn(18f * sx, 45f * sx)
                val reshapeVal = p * 50.0f
                val ok = MeituNativeEngine.nativeApplyTeethReshape(workingBitmap, mouthX, mouthY, radX, radY, 1, reshapeVal)
                if (!ok) {
                    val warpStrength = (p * 1.3f).coerceIn(0f, 1.5f)
                    val radius = 55f * sx
                    MeituNativeEngine.nativeApplyLiquifyWarp(workingBitmap, mouthX, mouthY + 8f * sx, mouthX, mouthY + 8f * sx, radius, warpStrength, MTLiquifyImage.WARP_MODE_PINCH)
                }
            }
            "tool_teeth_protrusion" -> {
                val mouthW = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[90 * 2] - landmarks106[84 * 2])
                } else 130f * sx
                val mouthH = if (landmarks106.size >= 106 * 2) {
                    Math.abs(landmarks106[93 * 2 + 1] - landmarks106[87 * 2 + 1])
                } else 35f * sx
                val radX = (mouthW * 0.55f).coerceAtLeast(35f * sx)
                val radY = (mouthH * 0.9f).coerceIn(18f * sx, 45f * sx)
                val reshapeVal = p * 50.0f
                val ok = MeituNativeEngine.nativeApplyTeethReshape(workingBitmap, mouthX, mouthY, radX, radY, 2, reshapeVal)
                if (!ok) {
                    val warpStrength = (p * 1.3f).coerceIn(0f, 1.5f)
                    val radius = 55f * sx
                    MeituNativeEngine.nativeApplyLiquifyWarp(workingBitmap, mouthX, mouthY + 8f * sx, mouthX, mouthY + 8f * sx, radius, warpStrength, MTLiquifyImage.WARP_MODE_PINCH)
                }
            }

            // ================= 7. THẨM MỸ TAI (EARS C++ ENGINE) =================
            "tool_ear_buddha", "tool_ear_mouse", "tool_ear_pig", "tool_ear_elf", "tool_ear_size",
            "tool_ear_press", "tool_ear_protrude", "tool_ear_thickness", "tool_ear_rosy" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val earRep = MeituNativeEngine.getEarAnatomyReport(rawOriginalBitmap, lmk, rawOriginalBitmap.width, rawOriginalBitmap.height)
                val isLeftVis = earRep?.isLeftEarVisible ?: false
                val isRightVis = earRep?.isRightEarVisible ?: false
                if (!isLeftVis && !isRightVis) {
                    Log.i("PhotoEditorActivity", "EarTool: No ear detected or visible for $currentToolId. Leaving image unchanged.")
                    return
                }
                val bw = rawOriginalBitmap.width.toFloat()
                val bh = rawOriginalBitmap.height.toFloat()
                val isLobeSpecificTool = (currentToolId == "tool_ear_buddha" || currentToolId == "tool_ear_thickness")
                val leftX = if (isLeftVis) {
                    (if (isLobeSpecificTool && earRep != null && earRep.leftLobeCenterX > 10f) earRep.leftLobeCenterX else (earRep?.leftEarCenterX?.takeIf { it > 10f } ?: lEarX)).coerceIn(10f, bw - 10f)
                } else 0f
                val leftY = if (isLeftVis) {
                    (if (isLobeSpecificTool && earRep != null && earRep.leftLobeCenterY > 10f) earRep.leftLobeCenterY else (earRep?.leftEarCenterY?.takeIf { it > 10f } ?: lEarY)).coerceIn(10f, bh - 10f)
                } else 0f
                val rightX = if (isRightVis) {
                    (if (isLobeSpecificTool && earRep != null && earRep.rightLobeCenterX > 10f) earRep.rightLobeCenterX else (earRep?.rightEarCenterX?.takeIf { it > 10f } ?: rEarX)).coerceIn(10f, bw - 10f)
                } else 0f
                val rightY = if (isRightVis) {
                    (if (isLobeSpecificTool && earRep != null && earRep.rightLobeCenterY > 10f) earRep.rightLobeCenterY else (earRep?.rightEarCenterY?.takeIf { it > 10f } ?: rEarY)).coerceIn(10f, bh - 10f)
                } else 0f
                val earRad = if (isLobeSpecificTool) {
                    (earRep?.earRadius?.takeIf { it > 15f } ?: (if (hasRealFace) kotlin.math.abs(rxEye - lxEye) * 0.48f else (85f * sx))).coerceIn(15f, bh * 0.35f) * 0.65f
                } else {
                    (earRep?.earRadius?.takeIf { it > 15f } ?: (if (hasRealFace) kotlin.math.abs(rxEye - lxEye) * 0.48f else (85f * sx))).coerceIn(20f, bh * 0.35f)
                }
                Log.i("PhotoEditorActivity", "EarTool: tool=$currentToolId, isLeftVis=$isLeftVis, isRightVis=$isRightVis, left=($leftX,$leftY), right=($rightX,$rightY), earRad=$earRad, p=$p")

                if (currentToolId == "tool_ear_rosy") {
                    MeituNativeEngine.nativeApplyEarColorTuning(workingBitmap, lmk, leftX, leftY, rightX, rightY, earRad, p * 50f, isLeftVis, isRightVis)
                } else {
                    val earStyleCode = when (currentToolId) {
                        "tool_ear_buddha" -> 4
                        "tool_ear_mouse" -> 3
                        "tool_ear_pig" -> 2
                        "tool_ear_elf", "tool_ear_size" -> 0
                        "tool_ear_press" -> 1
                        "tool_ear_thickness" -> 5
                        "tool_ear_protrude" -> 6
                        else -> 4
                    }
                    MeituNativeEngine.nativeApplyEarStyle(workingBitmap, lmk, leftX, leftY, rightX, rightY, earRad, earStyleCode, p * 100f, isLeftVis, isRightVis)
                }
            }

            // ================= 8. TRANG ĐIỂM 3D (2.8 MAKEUP) =================
            "tool_lip_french_rose" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 1, 0, p)
            }
            "tool_lip_velvet_red" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 2, 0, p)
            }
            "tool_lip_glossy_coral" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 8, 1, p)
            }
            "tool_lip_gradient_ruby" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 10, 6, p)
            }
            "tool_lip_overlip_terracotta" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 6, 5, p)
            }
            "tool_blush_peachy" -> {
                MeituNativeEngine.nativeApplyBlush(workingBitmap, lJawX + 70f * sx, lJawY - 20f * sx, rJawX - 70f * sx, rJawY - 20f * sx, 0, p)
            }
            "tool_blush_rosy" -> {
                MeituNativeEngine.nativeApplyBlush(workingBitmap, lJawX + 70f * sx, lJawY - 20f * sx, rJawX - 70f * sx, rJawY - 20f * sx, 1, p)
            }
            "tool_blush_sun_kissed" -> {
                MeituNativeEngine.nativeApplyBlush(workingBitmap, lJawX + 70f * sx, lJawY - 20f * sx, rJawX - 70f * sx, rJawY - 20f * sx, 4, p)
            }
            "tool_shadow_sunset" -> {
                MeituNativeEngine.nativeApplyEyeShadow(workingBitmap, lxEye, lyEye, rxEye, ryEye, 1, p)
            }
            "tool_shadow_smokey" -> {
                MeituNativeEngine.nativeApplyEyeShadow(workingBitmap, lxEye, lyEye, rxEye, ryEye, 7, p)
            }
            "tool_contour_nose" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyNormalSculpting(workingBitmap, lmk, 2402, p)
                if (!ok) {
                    MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 0, p)
                }
            }
            "tool_contour_wocan" -> {
                MeituNativeEngine.nativeApplyContour3D(workingBitmap, noseX, noseY, lxEye, lyEye, rxEye, ryEye, 3, p)
            }
            "tool_lip_dudu_3d" -> {
                val lipLut = getMaterialBitmap("material/makeup/lip_lut.png")
                if (lipLut != null) {
                    MeituNativeEngine.nativeApply3DLut(workingBitmap, lipLut, p * 0.85f)
                }
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 2, 2, p)
            }
            "tool_skin_watery_3d" -> {
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY - 50f * sx, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2707, p, landmarks106)
                MeituNativeEngine.nativeApplySkinType(workingBitmap, noseX, noseY, 220f * sx, 280f * sx, 1, p * 0.8f, landmarks106)
            }
            "tool_skin_dodge_burn" -> {
                MeituNativeEngine.nativeApply3DRelight(workingBitmap, landmarks106, null, 1, p * 0.75f)
                MeituNativeEngine.nativeApplySkinTool(workingBitmap, noseX, noseY, noseX, noseY, mouthX, mouthY, lxEye, lyEye, rxEye, ryEye, 2708, p, landmarks106)
            }
            "tool_makeup_look_4005" -> {
                MeituNativeEngine.nativeApplyLipstick(workingBitmap, landmarks106, mouthX, mouthY, 1, 2, p * 0.8f)
                MeituNativeEngine.nativeApplyBlush(workingBitmap, lJawX + 70f * sx, lJawY - 20f * sx, rJawX - 70f * sx, rJawY - 20f * sx, 1, p * 0.7f)
                MeituNativeEngine.nativeApplyEyeShadow(workingBitmap, lxEye, lyEye, rxEye, ryEye, 1, p * 0.65f)
            }

            // ================= 9. TÓC ĐẸP (2.9 HAIR) =================
            "tool_hair_line" -> {
                val hlX = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3]
                } else noseX
                val hlY = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3 + 1]
                } else if (landmarks106.size >= 106 * 2) {
                    val browY = (landmarks106[38 * 2 + 1] + landmarks106[57 * 2 + 1]) * 0.5f
                    browY - 0.40f * Math.abs(chinY - noseY)
                } else {
                    220f * sx
                }
                MeituNativeEngine.nativeApplyHair(workingBitmap, hlX, hlY, 2901, 0, p)
            }
            "tool_hair_volume" -> {
                val hlX = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3]
                } else noseX
                val hlY = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3 + 1]
                } else if (landmarks106.size >= 106 * 2) {
                    val browY = (landmarks106[38 * 2 + 1] + landmarks106[57 * 2 + 1]) * 0.5f
                    browY - 0.40f * Math.abs(chinY - noseY)
                } else {
                    220f * sx
                }
                MeituNativeEngine.nativeApplyHair(workingBitmap, hlX, hlY, 2904, 0, p)
            }
            "tool_hair_wrapped" -> {
                val hlX = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3]
                } else noseX
                val hlY = if (detectedDenseMesh478 != null && detectedDenseMesh478!!.size >= 468 * 3) {
                    detectedDenseMesh478!![10 * 3 + 1]
                } else if (landmarks106.size >= 106 * 2) {
                    val browY = (landmarks106[38 * 2 + 1] + landmarks106[57 * 2 + 1]) * 0.5f
                    browY - 0.40f * Math.abs(chinY - noseY)
                } else {
                    220f * sx
                }
                MeituNativeEngine.nativeApplyHair(workingBitmap, hlX, hlY, 2905, 0, p)
            }
            // ================= 9. TÓC & RÂU ĐỈNH CAO (HAIR STRAND DYE & BEARD ENGINE) =================
            "tool_hair_dye", "tool_hair_color", "tool_hair_rose_gold" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 5, p, 0.65f) // Rose Gold
            }
            "tool_hair_platinum", "tool_hair_blonde" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 3, p, 0.70f) // Platinum Blonde
            }
            "tool_hair_smokey_silver", "tool_hair_silver" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 4, p, 0.75f) // Smokey Silver
            }
            "tool_hair_pastel_pink", "tool_hair_peach_lilac" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 7, p, 0.65f) // Peach Lilac
            }
            "tool_hair_ash_brown" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, p, 0.50f) // Ash Brown
            }
            "tool_hair_burgundy", "tool_hair_wine" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 6, p, 0.50f) // Wine Burgundy
            }
            "tool_hair_caramel", "tool_hair_honey" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 9, p, 0.60f) // Caramel Honey
            }
            "tool_hair_navy_blue", "tool_hair_blue" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 8, p, 0.55f) // Navy Blue
            }
            "tool_hair_natural_black", "tool_hair_black" -> {
                MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 0, p, 0.40f) // Natural Black
            }
            "tool_hair_5002_brick_red" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 166, 58, 42, 0.65f, p, 0.65f)
            }
            "tool_hair_5002_matcha" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 107, 142, 35, 0.65f, p, 0.60f)
            }
            "tool_hair_5002_sky_blue" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 74, 144, 226, 0.70f, p, 0.70f)
            }
            "tool_hair_5002_lavender" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 147, 112, 219, 0.70f, p, 0.70f)
            }
            "tool_hair_5002_emerald" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 0, 155, 119, 0.65f, p, 0.65f)
            }
            "tool_hair_5002_olive" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 85, 107, 47, 0.60f, p, 0.55f)
            }
            "tool_hair_5002_mint" -> {
                if (p < 0f) MeituNativeEngine.nativeApplyHairStrandDye(workingBitmap, 2, kotlin.math.abs(p), 0.45f)
                else MeituNativeEngine.nativeApplyCustomHairDye(workingBitmap, 152, 255, 152, 0.75f, p, 0.75f)
            }
            "tool_hair_highlight" -> {
                MeituNativeEngine.nativeApplyHairMaterialRecolor(
                    workingBitmap,
                    220, 180, 140, 255, 230, 200, 0.5f, p, 0.60f, true
                )
            }
            "tool_hair_ombre" -> {
                MeituNativeEngine.nativeApplyHairMaterialRecolor(
                    workingBitmap,
                    60, 30, 20, 240, 150, 180, 0.5f, p, 0.40f, false
                )
            }
            "tool_hair_density" -> {
                MeituNativeEngine.nativeAdjustHairVolumeDensity(workingBitmap, 0f, p)
            }
            "tool_hair_curl_wave" -> {
                MeituNativeEngine.nativeAdjustHairCurlWave(workingBitmap, p)
            }
            "tool_hair_bangs" -> {
                val shape = if (p > 0.5f) 2 else if (p > 0f) 1 else 0
                MeituNativeEngine.nativeAdjustHairlineBangs(workingBitmap, shape, p * 0.5f)
            }
            "tool_hair_scalp_remove" -> {
                MeituNativeEngine.nativeRemoveHairScalp(workingBitmap, kotlin.math.abs(p))
            }
            "tool_hair_short_crop" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 1, kotlin.math.abs(p))
            }
            "tool_hair_buzzcut" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 2, kotlin.math.abs(p))
            }
            "tool_hair_fade" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 3, kotlin.math.abs(p))
            }
            "tool_hair_short_bob" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 4, kotlin.math.abs(p))
            }
            "tool_hair_side_part" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 5, kotlin.math.abs(p))
            }
            "tool_hair_layer" -> {
                MeituNativeEngine.nativeApplyHairstyleTrim(workingBitmap, 6, kotlin.math.abs(p))
            }

            // PRESET BEARDS FROM PNG ASSETS (Auto-resize, Warp & Dye Color)
                        "tool_preset_beard_01", "tool_preset_beard_02", "tool_preset_beard_03",
            "tool_preset_beard_04", "tool_preset_beard_05", "tool_preset_beard_06",
            "tool_preset_beard_07", "tool_preset_beard_08", "tool_preset_beard_09",
            "tool_preset_beard_10" -> {
                val filename = currentToolEn
                val beardBmp = getBeardBitmap(filename)
                if (beardBmp != null) {
                    val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                    val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                    val bHeightOffset = beardHeightOffsetVal.toFloat()
                    val bHorizontalOffset = beardHorizontalOffsetVal.toFloat()
                    val bIntensity = beardIntensity / 100f
                    MeituNativeEngine.nativeApplyPresetBeard(
                        workingBitmap,
                        beardBmp,
                        bIntensity,
                        activeBeardR, activeBeardG, activeBeardB,
                        isBeardDyeCustomActive,
                        bThickness,
                        bHeightOffset,
                        bWidth,
                        bHorizontalOffset
                    )
                }
            }

            // BEARD & GRAY AWAY (Râu & Phủ Bạc C++ 478 Landmark Fusion)
            "tool_beard_gray_away", "tool_beard_gray" -> {
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardGrayAway(
                    workingBitmap,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    activeBeardStyle
                )
            }
            "tool_beard_dye", "tool_beard_color" -> {
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    32, 24, 20, // Natural Espresso
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    activeBeardStyle,
                    beardHorizontalOffsetVal.toFloat()
                )
            }
            "tool_beard_mustache_goatee" -> {
                activeBeardStyle = 1
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    28, 22, 18,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    1,
                    beardHorizontalOffsetVal.toFloat()
                )
            }
            "tool_beard_mustache_only" -> {
                activeBeardStyle = 2
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    28, 22, 18,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    2
                )
            }
            "tool_beard_goatee_only" -> {
                activeBeardStyle = 3
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    28, 22, 18,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    3
                )
            }
            "tool_beard_quai_non" -> {
                activeBeardStyle = 0
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    26, 20, 18,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    0,
                    beardHorizontalOffsetVal.toFloat()
                )
            }
            "tool_beard_thickness", "tool_beard_width", "tool_beard_height" -> {
                val bThickness = (1.0f + beardThicknessVal / 100f).coerceIn(0.2f, 2.5f)
                val bWidth = (1.0f + beardWidthVal / 100f).coerceIn(0.4f, 2.2f)
                val bHeightOffset = beardHeightOffsetVal.toFloat()
                val bIntensity = beardIntensity / 100f
                MeituNativeEngine.nativeApplyBeardDye(
                    workingBitmap,
                    28, 22, 18,
                    bIntensity,
                    bThickness,
                    bHeightOffset,
                    bWidth,
                    activeBeardStyle,
                    beardHorizontalOffsetVal.toFloat()
                )
            }

            // ================= 10. THON DÁNG & FULL BODY BEAUTY (SPEC Sections 41-87) =================
            "tool_body_slim" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[2] = p // slimBody
                val ok = MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
                if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3001, p)
            }
            "tool_body_waist" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[3] = p // waistSlim
                params[4] = p * 0.8f // waistCurve
                val ok = MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
                if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3004, p)
            }
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
            "tool_body_arm", "tool_arm_slim" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[9] = p // armSlim
                MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
            }
            "tool_body_neck", "tool_neck_slim" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyNeckClavicle(workingBitmap, lmk, 1, p)
                if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3008, p)
            }
            "tool_neck_length", "tool_swan_neck" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyNeckClavicle(workingBitmap, lmk, 2, p)
            }
            "tool_clavicle_enhance" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val ok = MeituNativeEngine.nativeApplyClavicleShoulderEdit(workingBitmap, lmk, 2201, p)
                if (!ok) MeituNativeEngine.nativeApplyNeckClavicle(workingBitmap, lmk, 4, p)
            }
            "tool_face_neck_tone" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyNeckClavicle(workingBitmap, lmk, 5, p)
            }
            "tool_brow_thickness" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 1, p)
            }
            "tool_brow_arch" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 2, p)
            }
            "tool_brow_density" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyEyebrowLash(workingBitmap, lmk, 4, p)
            }
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
            "tool_scalp_reconstruct" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                MeituNativeEngine.nativeApplyScalpReconstruction(workingBitmap, lmk, p)
            }
            "tool_body_legs", "tool_long_legs", "tool_leg_length" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[10] = p // longLegs
                val ok = MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
                if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3002, p)
            }
            "tool_body_height", "tool_height" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[0] = p // bodyHeight
                MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
            }
            "tool_body_chest" -> {
                MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3010, p)
            }
            "tool_body_hip", "tool_hip_enhance" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[5] = p // hipEnhance
                val ok = MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
                if (!ok) MeituNativeEngine.nativeApplyBodyReshape(workingBitmap, 3011, p)
            }
            "tool_body_skin_smooth" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[13] = p // bodySkinSmooth
                MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
            }
            "tool_body_skin_whiten" -> {
                val lmk = if (landmarks106.size >= 106 * 2) landmarks106 else null
                val params = FloatArray(16)
                params[14] = p // bodySkinWhiten
                MeituNativeEngine.nativeApplyBodyBeauty(workingBitmap, null, lmk, params)
            }

            // ================= 11. AI RETOUCH (2.12 SMART BEAUTIFY) =================
            "tool_ai_idol" -> {
                MeituNativeEngine.nativeApplyAiRetouch(workingBitmap, 1201, p)
            }
            "tool_ai_sculpted" -> {
                MeituNativeEngine.nativeApplyAiRetouch(workingBitmap, 1204, p)
            }
            "tool_ai_dewy" -> {
                MeituNativeEngine.nativeApplyAiRetouch(workingBitmap, 1205, p)
            }
            "tool_ai_fresh" -> {
                MeituNativeEngine.nativeApplyAiRetouch(workingBitmap, 1206, p)
            }

            // ================= 12. CHỈNH MÀU & HSL (2.14 ADJUST / TONE) =================
            "tool_tone_exposure" -> {
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1401, factor)
            }
            "tool_tone_contrast" -> {
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1402, factor)
            }
            "tool_tone_saturation" -> {
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1403, factor)
            }
            "tool_tone_temp" -> {
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1405, factor)
            }
            "tool_tone_tint" -> {
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1406, factor)
            }
            "tool_hsl_red" -> {
                MeituNativeEngine.nativeApplyHslChannel(workingBitmap, 0, factor * 0.75f, factor, 0f)
            }
            "tool_hsl_orange" -> {
                MeituNativeEngine.nativeApplyHslChannel(workingBitmap, 1, factor * 0.6f, factor, 0f)
            }
            "tool_hsl_blue" -> {
                MeituNativeEngine.nativeApplyHslChannel(workingBitmap, 5, factor * 0.75f, factor, 0f)
            }

            // ================= 13. BỘ LỌC & DEFOCUS (2.14 / 2.15 FILTERS & BOKEH) =================
            "tool_filter_retro_film" -> {
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, 0f, -absP * 25f, -absP * 70f, -absP * 30f, 0f, 0f)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 1, p)
                }
            }
            "tool_filter_portrait_glow" -> {
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, 0f, -absP * 20f, -absP * 50f, 0f, 0f, -absP * 20f)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 2, p)
                }
            }
            "tool_filter_cyberpunk" -> {
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, 0f, absP * 20f, -absP * 60f, -absP * 40f, 0f, 0f)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 3, p)
                }
            }
            "tool_filter_golden_hour" -> {
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, 0f, -absP * 15f, -absP * 50f, -absP * 35f, 0f, 0f)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 6, p)
                }
            }
            "tool_filter_moody_bw" -> {
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, absP * 15f, absP * 30f, 0f, 0f, 0f, absP * 10f)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 5, p)
                }
            }
            "tool_defocus_portrait" -> {
                MeituNativeEngine.nativeApplyPortraitDefocus(workingBitmap, noseX, noseY, 260f * sx, 340f * sx, p)
            }
            "tool_filter_apple_4s", "tool_filter_apple_5s", "tool_filter_apple_6s",
            "tool_filter_apple_8p", "tool_filter_apple_xr", "tool_filter_apple_xs",
            "tool_filter_apple_11p", "tool_filter_apple_13p", "tool_filter_apple_15p",
            "tool_filter_apple_16p", "tool_filter_apple_17p", "tool_filter_samsung_s" -> {
                val lutAssetPath = currentToolEn
                val lutBmp = getMaterialBitmap(lutAssetPath)
                if (p < 0f) {
                    val absP = kotlin.math.abs(p)
                    // Kéo âm: Tone màu Vintage Monochrome / Film Grain cổ điển khử bão hòa
                    MeituNativeEngine.nativeApplyColorTuning(workingBitmap, 0f, -absP * 30f, -absP * 85f, 0f, 0f, -absP * 15f)
                } else if (lutBmp != null) {
                    MeituNativeEngine.nativeApply3DLut(workingBitmap, lutBmp, p)
                } else {
                    MeituNativeEngine.nativeApplyFilter(workingBitmap, 1, p)
                }
            }

            // ================= 14. ẢNH THẺ & HỘ CHIẾU (7. ID PHOTOS) =================
            "tool_id_bg_white" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 255, 255, 255, 2.5f)
            }
            "tool_id_bg_blue" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 29, 78, 216, 2.5f) // Chuẩn Việt Nam #1D4ED8
            }
            "tool_id_bg_cyan" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 56, 189, 248, 2.5f) // Xanh nhạt #38BDF8
            }
            "tool_id_bg_gray" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 100, 116, 139, 2.5f) // Xám studio #64748B
            }
            "tool_id_bg_red" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 220, 38, 38, 2.5f) // Đỏ #DC2626
            }
            "tool_id_crop_3x4", "tool_id_crop_4x6" -> {
                MeituNativeEngine.nativeApplyIdPhotoBackground(workingBitmap, 255, 255, 255, 2.0f)
                MeituNativeEngine.nativeApplyLocalizedSkinBilateral(workingBitmap, noseX, noseY, 200f * sx, 250f * sx, 0.6f, 0.15f)
            }

            // ================= 15. GHÉP ẢNH (5. COLLAGE GRID) =================
            "tool_collage_grid_2" -> {
                MeituNativeEngine.nativeApplyCollageGrid(workingBitmap, 2, 12, 16, 0xFFFFFFFF.toInt())
            }
            "tool_collage_grid_3" -> {
                MeituNativeEngine.nativeApplyCollageGrid(workingBitmap, 3, 12, 16, 0xFFFFFFFF.toInt())
            }
            "tool_collage_grid_4" -> {
                MeituNativeEngine.nativeApplyCollageGrid(workingBitmap, 4, 14, 20, 0xFFFFFFFF.toInt())
            }
            "tool_collage_grid_9" -> {
                MeituNativeEngine.nativeApplyCollageGrid(workingBitmap, 9, 8, 12, 0xFFFFFFFF.toInt())
            }
            "tool_collage_border" -> {
                MeituNativeEngine.nativeApplyCollageGrid(workingBitmap, 4, (factor * 0.3f).toInt().coerceAtLeast(4), (factor * 0.4f).toInt(), 0xFFE2E8F0.toInt())
            }

            // ================= 16. STICKER & VẼ NGHỆ THUẬT (2.15 STICKERS / MAGIC PEN) =================
            "tool_sticker_sparkle" -> {
                MeituNativeEngine.nativeApplyEyeCatchlight(workingBitmap, lxEye, lyEye, rxEye, ryEye, 3, p)
                MeituNativeEngine.nativeApplyToneParam(workingBitmap, 1401, 15f * p)
            }
            "tool_magic_pen_neon" -> {
                MeituNativeEngine.nativeApplyFilter(workingBitmap, 3, 0.8f) // Cyberpunk neon glow
            }
            "tool_magic_pen_galaxy" -> {
                MeituNativeEngine.nativeApplyFilter(workingBitmap, 6, 0.75f) // Golden sunset / star glow
            }
            "tool_ai_eraser" -> {
                MeituNativeEngine.nativeApplyLocalizedSkinBilateral(workingBitmap, noseX, noseY + 60f * sx, 80f * sx, 80f * sx, 0.95f, 0f)
            }
            else -> {
                MeituNativeEngine.nativeApplyColorTuning(workingBitmap, factor * 0.1f, factor * 0.1f, factor * 0.1f, 0f, 0f, 0f)
            }
        }

        currentProcessedBitmap = workingBitmap
        ivCanvasPreview.setImageBitmap(currentProcessedBitmap)



        // Kiem tra bo vien, bien da co the & khuyet thieu theo yeu cau Chu tich
        if (currentToolId.startsWith("tool_skin_") || currentToolId.startsWith("tool_body_")) {
            val contourReport = MeituNativeEngine.getBodyContourReport(workingBitmap, landmarks106)
            if (contourReport != null && contourReport.isValid) {
                android.util.Log.i("BodyContour", "Bo vien: topY=${contourReport.topY}, bottomY=${contourReport.bottomY}, leftW=${contourReport.maxLeftWidth}, rightW=${contourReport.maxRightWidth}, symmetry=${contourReport.symmetryRatio}, isAsymmetric=${contourReport.isAsymmetric}, chipped=${contourReport.hasChippedParts}, holes=${contourReport.internalHoleCount}")
                val statusText = if (contourReport.internalHoleCount == 0 && !contourReport.hasChippedParts) {
                    "⚡ C++ Engine • Bo viền da: Chuẩn • Khuyết/Thiếu: 0 • Lệch: ${if (contourReport.isAsymmetric) "Có" else "Không"}"
                } else {
                    "⚡ C++ Engine • Bo viền: Khuyết ${contourReport.internalHoleCount} điểm • Lệch: ${if (contourReport.isAsymmetric) "Có" else "Không"}"
                }
                tvNativeLibInfo.text = statusText
            }
        }

        // Báo cáo giải phẫu tai C++ theo yêu cầu Chủ tịch: Bo viền, vị trí so với má, cằm, mắt, hướng tai, nhận diện vành tai & che khuất
        if (currentToolId.startsWith("tool_ear_")) {
            val earReport = MeituNativeEngine.getEarAnatomyReport(rawOriginalBitmap, if (landmarks106.size >= 106 * 2) landmarks106 else null, rawOriginalBitmap.width, rawOriginalBitmap.height)
            if (earReport != null && earReport.isValid) {
                val lAng = String.format(java.util.Locale.US, "%.1f", earReport.leftEarAngleDeg)
                val rAng = String.format(java.util.Locale.US, "%.1f", earReport.rightEarAngleDeg)
                val eyeDist = String.format(java.util.Locale.US, "%.0f", (earReport.leftEyeToEarDist + earReport.rightEyeToEarDist) * 0.5f)
                val chinDist = String.format(java.util.Locale.US, "%.0f", earReport.earToChinVertical)
                val cheekDist = String.format(java.util.Locale.US, "%.0f", earReport.earToCheekDistance)
                val protrude = String.format(java.util.Locale.US, "%.0f%%", earReport.earProtrusionRatio * 100f)

                val visText = when {
                    earReport.isLeftEarVisible && earReport.isRightEarVisible -> "2 Tai Rõ"
                    earReport.isLeftEarVisible -> "1 Tai (Trái ảnh / Phải người • Bên kia khuất)"
                    earReport.isRightEarVisible -> "1 Tai (Phải ảnh / Trái người • Bên kia khuất)"
                    else -> "Khuất cả 2 tai"
                }

                tvNativeLibInfo.text = "👂 C++ Giải Phẫu • $visText • Nghiêng: L ${lAng}° / R ${rAng}° • Vểnh: ${protrude}"
                android.util.Log.i("EarAnatomy", "Tai C++: Visibility=$visText, Huong=L ${lAng}deg / R ${rAng}deg, Mat=${eyeDist}px, Ma=${cheekDist}px, Cam=${chinDist}px, Vanh=${protrude}, BoVien=[L-Helix: (${earReport.leftHelixTopX.toInt()},${earReport.leftHelixTopY.toInt()}) -> L-Lobe: (${earReport.leftLobeBottomX.toInt()},${earReport.leftLobeBottomY.toInt()})]")
            }
        }
    }

    private fun buildCategoryTabs(density: Float) {
        categoryContainer.removeAllViews()
        categories.forEach { cat ->
            val tabView = TextView(this).apply {
                text = cat.title
                textSize = 13f
                setTextColor(if (cat.title == currentCategory) MeituColors.PrimaryPink else MeituColors.TextSecondary)
                setTypeface(typeface, if (cat.title == currentCategory) Typeface.BOLD else Typeface.NORMAL)
                val padH = (14 * density).toInt()
                val padV = (10 * density).toInt()
                setPadding(padH, padV, padH, padV)
                setOnClickListener {
                    if (currentCategory != cat.title) {
                        commitCurrentToolState()
                        currentCategory = cat.title
                        buildCategoryTabs(density)
                        selectCategory(cat, density)
                    }
                }
            }
            categoryContainer.addView(tabView)
        }
    }

    
    private fun isBeardToolActive(): Boolean {
        return currentToolId.startsWith("tool_beard") ||
               currentToolId.startsWith("tool_preset_beard_") ||
               currentCategory.contains("Tóc & Râu")
    }

    private fun updateBeardPosHud() {
        if (!::dragBeardHud.isInitialized) return
        if (isBeardToolActive()) {
            dragBeardHud.visibility = View.VISIBLE
            val isShifted = (beardHorizontalOffsetVal != 0 || beardHeightOffsetVal != 0)
            if (isShifted) {
                tvDragBeardText.text = "🖐️ Vị trí: X: ${beardHorizontalOffsetVal}px | Y: ${beardHeightOffsetVal}px"
                btnResetBeardPos.visibility = View.VISIBLE
            } else {
                tvDragBeardText.text = "🖐️ Chạm & Kéo trên ảnh để chỉnh vị trí râu"
                btnResetBeardPos.visibility = View.GONE
            }
        } else {
            dragBeardHud.visibility = View.GONE
        }
    }

    private fun updateBeardTuningChips(density: Float) {
        if (!::chipBeardIntensity.isInitialized) return
        chipBeardIntensity.text = "🎚️ Đậm Nhạt ($beardIntensity%)"
        chipBeardThickness.text = "📏 Độ Dày ($beardThicknessVal%)"
        chipBeardWidth.text = "↔️ Độ Rộng ($beardWidthVal%)"
        chipBeardHeight.text = "↕️ Cao Thấp (${beardHeightOffsetVal}px)"
        if (::chipBeardHorizontal.isInitialized) {
            chipBeardHorizontal.text = "↔️ Trái Phải (${beardHorizontalOffsetVal}px)"
        }

        fun setChipStyle(chip: TextView, isSelected: Boolean) {
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = (14 * density)
                setColor(if (isSelected) 0x55FF2465.toInt() else 0x22FFFFFF.toInt())
            }
            chip.background = bg
            chip.setTextColor(if (isSelected) MeituColors.PrimaryPink else Color.WHITE)
        }

        setChipStyle(chipBeardIntensity, beardParamMode == "intensity")
        setChipStyle(chipBeardThickness, beardParamMode == "thickness")
        setChipStyle(chipBeardWidth, beardParamMode == "width")
        setChipStyle(chipBeardHeight, beardParamMode == "height")
        if (::chipBeardHorizontal.isInitialized) {
            setChipStyle(chipBeardHorizontal, beardParamMode == "horizontal")
        }
    }

    private fun switchBeardParamMode(mode: String, density: Float) {
        beardParamMode = mode
        when (mode) {
            "thickness" -> {
                tvToolTitle.text = "$currentToolName: Độ Dày Mỏng"
                tvSliderValue.text = "$beardThicknessVal%"
                seekBarIntensity.min = 20
                seekBarIntensity.max = 200
                seekBarIntensity.progress = beardThicknessVal
            }
            "width" -> {
                tvToolTitle.text = "$currentToolName: Độ Rộng Râu"
                tvSliderValue.text = "$beardWidthVal%"
                seekBarIntensity.min = 50
                seekBarIntensity.max = 180
                seekBarIntensity.progress = beardWidthVal
            }
            "height" -> {
                tvToolTitle.text = "$currentToolName: Cao Thấp Vị Trí"
                tvSliderValue.text = "${beardHeightOffsetVal}px"
                seekBarIntensity.min = -80
                seekBarIntensity.max = 80
                seekBarIntensity.progress = beardHeightOffsetVal
            }
            "horizontal" -> {
                tvToolTitle.text = "$currentToolName: Trái Phải Vị Trí"
                tvSliderValue.text = "${beardHorizontalOffsetVal}px"
                seekBarIntensity.min = -80
                seekBarIntensity.max = 80
                seekBarIntensity.progress = beardHorizontalOffsetVal
            }
            else -> { // "intensity"
                tvToolTitle.text = "$currentToolName: Đậm Nhạt"
                tvSliderValue.text = "$beardIntensity%"
                seekBarIntensity.min = 0
                seekBarIntensity.max = 100
                seekBarIntensity.progress = beardIntensity
            }
        }
        updateBeardTuningChips(density)
    }

    private fun updateBeardColorChips(density: Float) {
        beardColorList.forEachIndexed { i, opt ->
            if (i < beardColorChips.size) {
                val chip = beardColorChips[i]
                val isSelected = if (opt.isNatural) !isBeardDyeCustomActive else (isBeardDyeCustomActive && activeBeardR == opt.r && activeBeardG == opt.g && activeBeardB == opt.b)
                val bg = GradientDrawable().apply {
                    cornerRadius = (10 * density)
                    setColor(if (isSelected) 0x55FF2465.toInt() else 0xFF22202A.toInt())
                }
                chip.background = bg
                chip.setTextColor(if (isSelected) MeituColors.PrimaryPink else Color.WHITE)
            }
        }
    }

    private fun selectCategory(category: CategoryItem, density: Float) {
        // Auto-select first tool of category if currentToolId is not in this category
        val currentInCat = category.tools.find { it.id == currentToolId }
        val activeTool = currentInCat ?: category.tools.firstOrNull()
        if (activeTool != null && activeTool.id != currentToolId) {
            commitCurrentToolState()
            currentToolId = activeTool.id
            currentToolName = activeTool.name
            currentToolEn = activeTool.nameEn
            currentNativeLib = activeTool.nativeLib
            currentIntensity = activeTool.defaultVal

            val isBeard = activeTool.id.startsWith("tool_beard") || activeTool.id.startsWith("tool_preset_beard_")
            beardTuningScroll.visibility = if (isBeard) View.VISIBLE else View.GONE
            beardColorScroll.visibility = if (isBeard) View.VISIBLE else View.GONE
            if (isBeard) updateBeardColorChips(density)
            updateBeardPosHud()
            if (isBeard) {
                when (activeTool.id) {
                    "tool_beard_mustache_goatee" -> {
                        activeBeardStyle = 1
                        switchBeardParamMode("intensity", density)
                    }
                    "tool_beard_quai_non" -> {
                        activeBeardStyle = 0
                        switchBeardParamMode("intensity", density)
                    }
                    "tool_beard_mustache_only" -> {
                        activeBeardStyle = 2
                        switchBeardParamMode("intensity", density)
                    }
                    "tool_beard_goatee_only" -> {
                        activeBeardStyle = 3
                        switchBeardParamMode("intensity", density)
                    }
                    "tool_beard_thickness" -> switchBeardParamMode("thickness", density)
                    "tool_beard_width" -> switchBeardParamMode("width", density)
                    "tool_beard_height" -> switchBeardParamMode("height", density)
                    else -> switchBeardParamMode("intensity", density)
                }
            } else {
                tvToolTitle.text = activeTool.name
                tvSliderValue.text = "${activeTool.defaultVal}${activeTool.unit}"
                seekBarIntensity.min = activeTool.minVal
                seekBarIntensity.max = activeTool.maxVal
                seekBarIntensity.progress = activeTool.defaultVal
            }
            tvEffectTag.text = "✨ ${activeTool.name} (${seekBarIntensity.progress}${activeTool.unit})"
            tvNativeLibInfo.text = "⚡ 100% C++ Engine • ${activeTool.nativeLib} • OpenMP"
            applyCurrentToolToBitmap()
        }

        subToolsContainer.removeAllViews()
        category.tools.forEach { tool ->
            val isMitu = tool.id.startsWith("tool_filter_apple_") ||
                    tool.id == "tool_filter_samsung_s" ||
                    tool.id.startsWith("tool_hair_5002_") ||
                    tool.id == "tool_lip_dudu_3d" ||
                    tool.id == "tool_skin_watery_3d" ||
                    tool.id == "tool_skin_dodge_burn" ||
                    tool.id == "tool_makeup_look_4005" ||
                    tool.nameEn.startsWith("material/") ||
                    tool.name.contains("[Mitu")

            val card = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER
                val cardW = (100 * density).toInt()
                val cardH = (86 * density).toInt()
                layoutParams = LinearLayout.LayoutParams(cardW, cardH).apply {
                    val m = (4 * density).toInt()
                    setMargins(m, 0, m, 0)
                }
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = (14 * density)
                    setColor(if (tool.id == currentToolId) 0x38FF2465.toInt() else 0xFF181720.toInt())
                }
                background = bg

                setOnClickListener {
                    if (tool.isVip && !VipStatusManager.getInstance(this@PhotoEditorActivity).isVip()) {
                        android.widget.Toast.makeText(this@PhotoEditorActivity, "👑 Đã kích hoạt tính năng VIP!", android.widget.Toast.LENGTH_SHORT).show()
                        return@setOnClickListener
                    }
                    if (tool.id != currentToolId) {
                        commitCurrentToolState()
                    }
                    currentToolId = tool.id
                    currentToolName = tool.name
                    currentToolEn = tool.nameEn
                    currentNativeLib = tool.nativeLib
                    currentIntensity = tool.defaultVal

                    val isBeard = tool.id.startsWith("tool_beard") || tool.id.startsWith("tool_preset_beard_")
                    beardTuningScroll.visibility = if (isBeard) View.VISIBLE else View.GONE
                    beardColorScroll.visibility = if (isBeard) View.VISIBLE else View.GONE
                    if (isBeard) updateBeardColorChips(density)
                    updateBeardPosHud()
                    if (isBeard) {
                        when (tool.id) {
                            "tool_beard_thickness" -> switchBeardParamMode("thickness", density)
                            "tool_beard_width" -> switchBeardParamMode("width", density)
                            "tool_beard_height" -> switchBeardParamMode("height", density)
                            else -> switchBeardParamMode("intensity", density)
                        }
                    } else {
                        tvToolTitle.text = tool.name
                        tvSliderValue.text = "${tool.defaultVal}${tool.unit}"
                        seekBarIntensity.min = tool.minVal
                        seekBarIntensity.max = tool.maxVal
                        seekBarIntensity.progress = tool.defaultVal
                    }
                    tvEffectTag.text = "✨ ${if (isMitu) "[Mitu] " else ""}${tool.name} (${seekBarIntensity.progress}${tool.unit})"

                    applyCurrentToolToBitmap()
                    selectCategory(category, density)
                }

                if (tool.id.startsWith("tool_preset_beard_")) {
                    val filename = tool.nameEn
                    val thumbBmp = getBeardThumbnail(filename, density)
                    if (thumbBmp != null) {
                        val ivIcon = ImageView(this@PhotoEditorActivity).apply {
                            setImageBitmap(thumbBmp)
                            scaleType = ImageView.ScaleType.FIT_CENTER
                            val iconSize = (38 * density).toInt()
                            layoutParams = LinearLayout.LayoutParams(iconSize, iconSize).apply {
                                gravity = Gravity.CENTER_HORIZONTAL
                                bottomMargin = (2 * density).toInt()
                                topMargin = (2 * density).toInt()
                            }
                        }
                        addView(ivIcon)
                    }
                } else if (isMitu) {
                    val mituBadge = TextView(this@PhotoEditorActivity).apply {
                        text = "🏷️ MITU"
                        textSize = 7.5f
                        setTextColor(0xFF00E5FF.toInt())
                        setTypeface(typeface, Typeface.BOLD)
                        val bgMitu = GradientDrawable().apply {
                            shape = GradientDrawable.RECTANGLE
                            cornerRadius = (4 * density)
                            setColor(0x2800E5FF.toInt())
                        }
                        background = bgMitu
                        val padH = (4 * density).toInt()
                        val padV = (1 * density).toInt()
                        setPadding(padH, padV, padH, padV)
                        layoutParams = LinearLayout.LayoutParams(
                            LinearLayout.LayoutParams.WRAP_CONTENT,
                            LinearLayout.LayoutParams.WRAP_CONTENT
                        ).apply {
                            gravity = Gravity.CENTER_HORIZONTAL
                            bottomMargin = (2 * density).toInt()
                        }
                    }
                    addView(mituBadge)
                } else if (tool.isVip) {
                    val vipBadge = TextView(this@PhotoEditorActivity).apply {
                        text = "👑 VIP UNLOCKED"
                        textSize = 9f
                        setTextColor(MeituColors.VipGold)
                        setTypeface(typeface, Typeface.BOLD)
                    }
                    addView(vipBadge)
                }

                val tvName = TextView(this@PhotoEditorActivity).apply {
                    text = tool.name
                    textSize = 9.5f
                    setTextColor(if (tool.id == currentToolId) Color.WHITE else MeituColors.TextSecondary)
                    setTypeface(typeface, if (tool.id == currentToolId) Typeface.BOLD else Typeface.NORMAL)
                    gravity = Gravity.CENTER
                    val pad = (4 * density).toInt()
                    setPadding(pad, 1, pad, 0)
                }

                val tvEn = TextView(this@PhotoEditorActivity).apply {
                    text = if (isMitu) "✨ Mitu Effect" else tool.nameEn
                    textSize = 7.5f
                    setTextColor(if (isMitu) 0xFF00E5FF.toInt() else MeituColors.TextMuted)
                    gravity = Gravity.CENTER
                }

                addView(tvName)
                addView(tvEn)
            }
            subToolsContainer.addView(card)
        }
    }
}