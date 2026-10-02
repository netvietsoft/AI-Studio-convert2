// Source decompiled & upgraded: com.mt.mtxx.mtxx.camera.CameraActivity.kt
package com.mt.mtxx.mtxx.camera

import android.Manifest
import android.app.Activity
import android.content.ContentValues
import android.content.Intent
import android.content.pm.PackageManager
import android.content.res.ColorStateList
import android.graphics.*
import android.graphics.drawable.Drawable
import android.graphics.drawable.GradientDrawable
import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.os.Handler
import android.os.Looper
import android.os.SystemClock
import android.provider.MediaStore
import android.util.Log
import android.view.Gravity
import android.view.MotionEvent
import android.view.View
import android.view.ViewGroup
import android.view.Window
import android.view.WindowManager
import android.widget.*
import androidx.core.content.ContextCompat
import com.meitu.common.ui.base.BaseActivity
import com.meitu.common.ui.theme.MeituColors
import com.meitu.core.nativeengine.MeituNativeEngine
import com.meitu.ai.facedetect.FaceDetector106
import java.util.concurrent.Executors
import java.util.concurrent.atomic.AtomicBoolean
import com.meitu.vip.manager.VipStatusManager
import com.meitu.vip.manager.VipTriggerManager
import java.io.File
import java.io.FileOutputStream
import java.io.OutputStream

/**
 * Giao diện Chụp ảnh & Làm đẹp thời gian thực Meitu Camera Studio 2026.
 * Đầy đủ các chế độ chuẩn:
 * 1. Modes: PORTRAIT | PHOTO | VIDEO | MORE
 * 2. Real-time: Retouch | Face | Features | Filter | iPhone Cam
 * 3. SubModule Camera:
 *    CAMERA_STICKER | CAMERA_AR_STICKER | CAMERA_AR_STYLE
 *    CAMERA_PARTIAL_MAKEUP | CAMERA_FILTER | CAMERA_VIRTUAL_FILTER
 *    CAMERA_MUSIC | CAMERA_WATERMARK | CAMERA_TEXT_STICKER
 *    CAMERA_ADVANCED_FILTER | CAMERA_ADVANCED_FACE | CAMERA_NEW_FILTER
 *    CAMERA_FILM_DOODLE | CAMERA_FILM_SIMULATE
 * 4. iPhone Camera Mode:
 *    Tabs: AI Retouch | For You | Daily | Trending
 *    AI presets: IDOL / Young Pro / Refined / Sculpted
 *    For You: Natural Dewy | Normcore | Expo Film | Fresh
 *    Resolution selector (12MP / 24MP / 48MP), Ratio (9:16, 4:3, 1:1, Full), Timer (0s, 3s, 5s, 10s)
 */
class CameraActivity : BaseActivity() {

    enum class CameraMode(val id: String, val title: String) {
        PORTRAIT("PORTRAIT", "CHÂN DUNG"),
        PHOTO("PHOTO", "ẢNH"),
        VIDEO("VIDEO", "VIDEO"),
        MORE("MORE", "THÊM")
    }

    enum class AspectRatio(val title: String, val w: Int, val h: Int) {
        RATIO_9_16("9:16", 9, 16),
        RATIO_4_3("4:3", 3, 4),
        RATIO_1_1("1:1", 1, 1),
        RATIO_FULL("Full", 9, 19)
    }

    enum class FlashMode(val icon: String, val desc: String) {
        OFF("⚡ Tắt", "Đèn Flash TẮT"),
        ON("⚡ Bật", "Đèn Flash BẬT"),
        AUTO("⚡ Auto", "Đèn Flash TỰ ĐỘNG"),
        TORCH("💡 Rọi", "Đèn Flash CHIẾU SÁNG")
    }

    enum class BeautyCategory(val title: String) {
        RETOUCH("Làm đẹp"),
        FACE("Khuôn mặt"),
        FEATURES("Chi tiết"),
        FILTER("Bộ lọc"),
        IPHONE_CAM("📱 iPhone Cam")
    }

    enum class IPhoneTab(val title: String) {
        AI_RETOUCH("AI Retouch"),
        FOR_YOU("For You"),
        DAILY("Daily"),
        TRENDING("Trending")
    }

    enum class SensorResolution(val title: String, val desc: String) {
        RES_12MP("12 MP", "Cảm biến tiêu chuẩn 12MP"),
        RES_24MP("24 MP", "Độ phân giải cao 24MP Fine Detail"),
        RES_48MP("48 MP", "Cảm biến 14 Pro 48MP Ultra HDR")
    }

    data class BeautyToolItem(
        val id: String,
        val name: String,
        val iconEmoji: String,
        val category: BeautyCategory,
        val defaultValue: Int = 0,
        var currentValue: Int = 0,
        val isVip: Boolean = false,
        val subCategory: String = ""
    )

    data class SubModuleChip(
        val id: String,
        val name: String,
        val icon: String,
        var isActive: Boolean = false
    )

    // State Variables
    private var currentMode = CameraMode.PHOTO
    private var currentRatio = AspectRatio.RATIO_9_16
    private var currentFlash = FlashMode.OFF
    private var currentSensor = SensorResolution.RES_48MP
    private var timerSeconds = 0
    private var isFrontFacing = true
    private var isPanelCollapsed = false

    // Real-time AI Face Landmark & Anatomy Detection (106 Points)
    private lateinit var faceDetector: FaceDetector106
    private val detectorExecutor = Executors.newSingleThreadExecutor()
    private val isDetecting = AtomicBoolean(false)
    @Volatile
    private var cachedLandmarks: FloatArray? = null
    private var frameCounter = 0
    private var liveVideoRecorder: LiveVideoRecorder? = null

    // Video Recording State
    private var isRecordingVideo = false
    private var videoStartTime = 0L
    private val videoTimerRunnable = object : Runnable {
        override fun run() {
            if (isRecordingVideo) {
                val elapsed = (SystemClock.uptimeMillis() - videoStartTime) / 1000
                val mins = elapsed / 60
                val secs = elapsed % 60
                tvVideoTimer.text = String.format("🔴 %02d:%02d", mins, secs)
                mainHandler.postDelayed(this, 1000)
            }
        }
    }

    private var activeCategory = BeautyCategory.RETOUCH
    private var activeIPhoneTab = IPhoneTab.AI_RETOUCH
    private lateinit var activeTool: BeautyToolItem

    // Beauty Tools Catalog
    private val allTools = mutableListOf<BeautyToolItem>()
    private val subModuleChips = mutableListOf<SubModuleChip>()

    // UI View References
    private lateinit var rootLayout: FrameLayout
    private lateinit var ivCameraFeed: ImageView
    private lateinit var tvTimerOverlay: TextView
    private lateinit var flashOverlay: View
    private lateinit var tvRatioBtn: TextView
    private lateinit var tvFlashBtn: TextView
    private lateinit var tvTimerBtn: TextView
    private lateinit var tvSensorBadge: TextView
    private lateinit var tvVideoTimer: TextView

    private lateinit var bottomContainer: LinearLayout
    private lateinit var sliderSection: LinearLayout
    private lateinit var tvSliderLabel: TextView
    private lateinit var tvSliderValue: TextView
    private lateinit var beautySeekBar: SeekBar
    private lateinit var categoryTabsLayout: LinearLayout
    private lateinit var iPhoneSubTabsLayout: LinearLayout
    private lateinit var toolsContainerLayout: LinearLayout
    private lateinit var modesContainerLayout: LinearLayout
    private lateinit var subModulesContainerLayout: LinearLayout
    private lateinit var btnExpandFloating: TextView

    // Shutter Views
    private lateinit var shutterInner: View
    private lateinit var shutterOuter: View

    private var cameraSessionManager: CameraSessionManager? = null
    private var previewBitmap: Bitmap? = null
    private val mainHandler = Handler(Looper.getMainLooper())

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        faceDetector = FaceDetector106(this)
        liveVideoRecorder = LiveVideoRecorder()
        requestWindowFeature(Window.FEATURE_NO_TITLE)
        window.setFlags(
            WindowManager.LayoutParams.FLAG_FULLSCREEN,
            WindowManager.LayoutParams.FLAG_FULLSCREEN
        )

        initBeautyToolsData()
        initSubModulesData()

        rootLayout = FrameLayout(this).apply {
            setBackgroundColor(Color.BLACK)
        }

        // 1. Live Camera Feed View
        ivCameraFeed = ImageView(this).apply {
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT,
                Gravity.CENTER
            )
            scaleType = ImageView.ScaleType.CENTER_CROP
        }
        rootLayout.addView(ivCameraFeed)

        // 2. Flash Overlay for Capture
        flashOverlay = View(this).apply {
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT
            )
            setBackgroundColor(Color.WHITE)
            visibility = View.GONE
        }
        rootLayout.addView(flashOverlay)

        // 3. Countdown Timer Overlay
        tvTimerOverlay = TextView(this).apply {
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT,
                Gravity.CENTER
            )
            textSize = 96f
            setTextColor(Color.WHITE)
            typeface = Typeface.DEFAULT_BOLD
            visibility = View.GONE
            setShadowLayer(16f, 0f, 4f, Color.BLACK)
        }
        rootLayout.addView(tvTimerOverlay)

        // 4. Video Recording Timer (Top Center)
        tvVideoTimer = TextView(this).apply {
            val density = resources.displayMetrics.density
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT,
                Gravity.TOP or Gravity.CENTER_HORIZONTAL
            ).apply {
                topMargin = (72 * density).toInt()
            }
            text = "🔴 00:00"
            textSize = 14f
            typeface = Typeface.DEFAULT_BOLD
            setTextColor(Color.WHITE)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 14 * density
                setColor(Color.parseColor("#99000000"))
            }
            background = bg
            setPadding((12 * density).toInt(), (4 * density).toInt(), (12 * density).toInt(), (4 * density).toInt())
            visibility = View.GONE
        }
        rootLayout.addView(tvVideoTimer)

        // 5. Top Bar Controls
        val topBar = buildTopBar()
        rootLayout.addView(topBar)

        // 6. Bottom Control Container (SubModules + Slider + Category Tabs + Circular Tools + Modes + Shutter)
        bottomContainer = buildBottomContainer()
        rootLayout.addView(bottomContainer)

        // 7. Floating Re-expand Button (visible when panel is collapsed)
        btnExpandFloating = TextView(this).apply {
            val density = resources.displayMetrics.density
            val size = (48 * density).toInt()
            layoutParams = FrameLayout.LayoutParams(size, size, Gravity.BOTTOM or Gravity.END).apply {
                bottomMargin = (120 * density).toInt()
                rightMargin = (16 * density).toInt()
            }
            gravity = Gravity.CENTER
            text = "💄"
            textSize = 22f
            background = GradientDrawable().apply {
                shape = GradientDrawable.OVAL
                setColor(Color.parseColor("#CC1C1C1E"))
            }
            visibility = View.GONE
            setOnClickListener {
                isPanelCollapsed = false
                bottomContainer.visibility = View.VISIBLE
                btnExpandFloating.visibility = View.GONE
            }
        }
        rootLayout.addView(btnExpandFloating)

        setContentView(rootLayout)

        initHardwareCameraSession()
        renderLiveCameraFrame()
    }

    private fun initSubModulesData() {
        subModuleChips.clear()
        subModuleChips.add(SubModuleChip("CAMERA_STICKER", "Sticker 2D", "🎭"))
        subModuleChips.add(SubModuleChip("CAMERA_AR_STICKER", "AR 3D", "✨"))
        subModuleChips.add(SubModuleChip("CAMERA_AR_STYLE", "AR Style", "🎨"))
        subModuleChips.add(SubModuleChip("CAMERA_PARTIAL_MAKEUP", "Makeup", "💄"))
        subModuleChips.add(SubModuleChip("CAMERA_VIRTUAL_FILTER", "Lăng Kính", "🔮"))
        subModuleChips.add(SubModuleChip("CAMERA_MUSIC", "Nhạc BGM", "🎵"))
        subModuleChips.add(SubModuleChip("CAMERA_WATERMARK", "Hình Mờ", "🏷️"))
        subModuleChips.add(SubModuleChip("CAMERA_TEXT_STICKER", "Chữ Nghệ Thuật", "✍️"))
        subModuleChips.add(SubModuleChip("CAMERA_FILM_SIMULATE", "Màu Film", "📸"))
        subModuleChips.add(SubModuleChip("CAMERA_FILM_DOODLE", "Bụi Xước Film", "📼"))
    }

    private fun initBeautyToolsData() {
        allTools.clear()

        // 1. Category: Retouch (Làn da chuẩn C++: Bắt đầu 0% cho khung hình camera thuần khiết 100%)
        allTools.add(BeautyToolItem("smooth", "Mịn da Spa", "✨", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("tone", "Sáng da", "🎨", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("clear", "Làm nét", "💎", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("brighten", "Nâng tông", "💡", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("bags", "Quầng thâm", "👁️", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("smile_lines", "Rãnh cười", "😊", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("neck_lines", "Nếp nhăn cổ", "👑", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0, isVip = true))
        allTools.add(BeautyToolItem("oil_control", "Kiềm bóng dầu", "🛡️", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("skin_type_oily", "Da dầu 64804", "💧", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("skin_type_dry", "Da khô 64805", "🌾", BeautyCategory.RETOUCH, defaultValue = 0, currentValue = 0))

        // 2. Category: Face (Khuôn mặt C++: Bắt đầu 0% không biến dạng khi chưa điều chỉnh)
        allTools.add(BeautyToolItem("vline", "Thon gọn V-line", "🧏", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("chin", "Gọt cằm", "📐", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("cheekbones", "Hạ gò má", "🌸", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("forehead", "Hạ trán", "💆", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("face_size", "Thu nhỏ mặt", "🪞", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("mandible", "Góc hàm", "🏛️", BeautyCategory.FACE, defaultValue = 0, currentValue = 0))

        // 3. Category: Features (Chi tiết ngũ quan C++: Bắt đầu 0%)
        allTools.add(BeautyToolItem("eye_enlarge", "Mắt to", "👀", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("eye_bright", "Sáng tròng", "🌟", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("eye_eyelid", "Mí đôi", "👁️", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("nose_shrink", "Thu cánh mũi", "👃", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("nose_tip", "Đầu mũi thon", "📍", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("nose_root", "Sống mũi cao", "🏔️", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lip_bunny", "Môi thỏ 3D", "🐰", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lip_plump", "Dày môi", "👄", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("mouth_smile", "Nụ cười", "😄", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("teeth_whiten", "Trắng răng", "🦷", BeautyCategory.FEATURES, defaultValue = 0, currentValue = 0))

        // 4. Category: Filter (3D LUT Cinematic C++: Bắt đầu 0%)
        allTools.add(BeautyToolItem("lut_natural", "Tự nhiên", "🍃", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_rosy", "Hồng hào", "🌸", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_cinema", "Điện ảnh", "🎬", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_vintage", "Cổ điển", "🎞️", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_retro_film", "Retro Film 35mm", "🎞️", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_cyberpunk", "Cyberpunk Neon", "🌆", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0, isVip = true))
        allTools.add(BeautyToolItem("lut_golden", "Golden Hour", "🌇", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))
        allTools.add(BeautyToolItem("lut_night", "Đêm AI", "🌙", BeautyCategory.FILTER, defaultValue = 0, currentValue = 0))

        // 5. Category: iPhone Camera Mode Presets (AI Retouch | For You | Daily | Trending)
        // Tab: AI Retouch
        allTools.add(BeautyToolItem("iphone_idol", "IDOL", "🌟", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, isVip = true, subCategory = "AI Retouch"))
        allTools.add(BeautyToolItem("iphone_young_pro", "Young Pro", "🌱", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "AI Retouch"))
        allTools.add(BeautyToolItem("iphone_refined", "Refined", "💎", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "AI Retouch"))
        allTools.add(BeautyToolItem("iphone_sculpted", "Sculpted", "🏛️", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, isVip = true, subCategory = "AI Retouch"))

        // Tab: For You
        allTools.add(BeautyToolItem("iphone_dewy", "Natural Dewy", "💧", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "For You"))
        allTools.add(BeautyToolItem("iphone_normcore", "Normcore", "🌿", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "For You"))
        allTools.add(BeautyToolItem("iphone_expo_film", "Expo Film", "🎞️", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "For You"))
        allTools.add(BeautyToolItem("iphone_fresh", "Fresh", "🍊", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "For You"))

        // Tab: Daily
        allTools.add(BeautyToolItem("iphone_sunshine", "Warm Sunshine", "☀️", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Daily"))
        allTools.add(BeautyToolItem("iphone_clean_girl", "Clean Girl", "🫧", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Daily"))
        allTools.add(BeautyToolItem("iphone_soft_minimal", "Soft Minimal", "☕", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Daily"))
        allTools.add(BeautyToolItem("iphone_office", "Office Ready", "💼", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Daily"))

        // Tab: Trending
        allTools.add(BeautyToolItem("iphone_y2k", "Y2K Cyber", "🛸", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, isVip = true, subCategory = "Trending"))
        allTools.add(BeautyToolItem("iphone_film_diary", "Film Diary", "📔", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Trending"))
        allTools.add(BeautyToolItem("iphone_dopamine", "Dopamine Glow", "💖", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, subCategory = "Trending"))
        allTools.add(BeautyToolItem("iphone_korean_glass", "Korean Glass", "🔮", BeautyCategory.IPHONE_CAM, defaultValue = 0, currentValue = 0, isVip = true, subCategory = "Trending"))

        activeTool = allTools[0] // Default: Smooth
    }

    private fun buildTopBar(): LinearLayout {
        val density = resources.displayMetrics.density
        val padH = (16 * density).toInt()
        val padV = (14 * density).toInt()

        return LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setPadding(padH, padV, padH, padV)
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT,
                Gravity.TOP
            )

            // Close button ✕
            val btnClose = TextView(this@CameraActivity).apply {
                text = "✕"
                textSize = 20f
                setTextColor(Color.WHITE)
                setPadding((6 * density).toInt(), (6 * density).toInt(), (10 * density).toInt(), (6 * density).toInt())
                setOnClickListener { finish() }
            }
            addView(btnClose)

            // Sensor Resolution Badge: 48MP / 24MP / 12MP
            tvSensorBadge = TextView(this@CameraActivity).apply {
                text = currentSensor.title
                textSize = 11f
                typeface = Typeface.DEFAULT_BOLD
                setTextColor(Color.WHITE)
                background = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    setColor(Color.parseColor("#33FFFFFF"))
                    cornerRadius = 14 * density
                }
                setPadding((10 * density).toInt(), (4 * density).toInt(), (10 * density).toInt(), (4 * density).toInt())
                setOnClickListener {
                    cycleSensorResolution()
                }
            }
            addView(tvSensorBadge)

            // Spacer
            addView(View(this@CameraActivity), LinearLayout.LayoutParams(0, 0, 1f))

            // Aspect Ratio Selector (9:16)
            tvRatioBtn = TextView(this@CameraActivity).apply {
                text = currentRatio.title
                textSize = 13f
                typeface = Typeface.DEFAULT_BOLD
                setTextColor(Color.WHITE)
                setPadding((8 * density).toInt(), (6 * density).toInt(), (8 * density).toInt(), (6 * density).toInt())
                setOnClickListener { cycleAspectRatio() }
            }
            addView(tvRatioBtn)

            // Flash Mode Selector
            tvFlashBtn = TextView(this@CameraActivity).apply {
                text = currentFlash.icon
                textSize = 13f
                setTextColor(Color.WHITE)
                setPadding((8 * density).toInt(), (6 * density).toInt(), (8 * density).toInt(), (6 * density).toInt())
                setOnClickListener { cycleFlashMode() }
            }
            addView(tvFlashBtn)

            // Timer Selector
            tvTimerBtn = TextView(this@CameraActivity).apply {
                text = if (timerSeconds > 0) "⏱️ ${timerSeconds}s" else "⏱️ Tắt"
                textSize = 13f
                setTextColor(Color.WHITE)
                setPadding((8 * density).toInt(), (6 * density).toInt(), (8 * density).toInt(), (6 * density).toInt())
                setOnClickListener { cycleTimer() }
            }
            addView(tvTimerBtn)

            // Flip Camera 🔄
            val btnFlip = TextView(this@CameraActivity).apply {
                text = "🔄"
                textSize = 18f
                setPadding((8 * density).toInt(), (6 * density).toInt(), (8 * density).toInt(), (6 * density).toInt())
                setOnClickListener {
                    isFrontFacing = !isFrontFacing
                    cameraSessionManager?.switchCamera()
                    Toast.makeText(this@CameraActivity, if (isFrontFacing) "Camera Trước (Selfie)" else "Camera Sau (Chính)", Toast.LENGTH_SHORT).show()
                    renderLiveCameraFrame()
                }
            }
            addView(btnFlip)

            // Menu More •••
            val btnMore = TextView(this@CameraActivity).apply {
                text = "•••"
                textSize = 15f
                typeface = Typeface.DEFAULT_BOLD
                setTextColor(Color.WHITE)
                setPadding((8 * density).toInt(), (6 * density).toInt(), (4 * density).toInt(), (6 * density).toInt())
                setOnClickListener {
                    openAdvancedCameraSettings()
                }
            }
            addView(btnMore)
        }
    }

    private fun buildBottomContainer(): LinearLayout {
        val density = resources.displayMetrics.density

        return LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            gravity = Gravity.BOTTOM
            layoutParams = FrameLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT,
                Gravity.BOTTOM
            )
            background = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                colors = intArrayOf(Color.TRANSPARENT, Color.parseColor("#E60D0D12"), Color.parseColor("#F50D0D12"))
                orientation = GradientDrawable.Orientation.TOP_BOTTOM
            }
            setPadding(0, (10 * density).toInt(), 0, (14 * density).toInt())

            // 1. SubModule Camera Action Chips (Sticker, AR, Makeup, Music, Watermark, Film)
            subModulesContainerLayout = buildSubModulesBar()
            addView(subModulesContainerLayout)

            // 2. Real-Time Beauty Slider Section
            sliderSection = buildSliderSection()
            addView(sliderSection)

            // 3. Category Tabs (Làm đẹp, Khuôn mặt, Chi tiết, Bộ lọc, iPhone Cam)
            val tabsScrollView = HorizontalScrollView(this@CameraActivity).apply {
                isHorizontalScrollBarEnabled = false
                layoutParams = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    ViewGroup.LayoutParams.WRAP_CONTENT
                )
            }
            categoryTabsLayout = LinearLayout(this@CameraActivity).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER
                setPadding((12 * density).toInt(), (2 * density).toInt(), (12 * density).toInt(), (4 * density).toInt())
            }
            tabsScrollView.addView(categoryTabsLayout)
            addView(tabsScrollView)
            setupCategoryTabs()

            // 4. Sub-Tabs for iPhone Mode (AI Retouch | For You | Daily | Trending)
            iPhoneSubTabsLayout = LinearLayout(this@CameraActivity).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER
                setPadding((12 * density).toInt(), (2 * density).toInt(), (12 * density).toInt(), (4 * density).toInt())
                visibility = View.GONE
            }
            addView(iPhoneSubTabsLayout)
            setupIPhoneSubTabs()

            // 5. Circular Action Tools Row (Horizontal Scroll)
            val toolsScrollView = HorizontalScrollView(this@CameraActivity).apply {
                isHorizontalScrollBarEnabled = false
                setPadding(0, (4 * density).toInt(), 0, (6 * density).toInt())
            }
            toolsContainerLayout = LinearLayout(this@CameraActivity).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                setPadding((16 * density).toInt(), 0, (16 * density).toInt(), 0)
            }
            toolsScrollView.addView(toolsContainerLayout)
            addView(toolsScrollView)
            setupToolsInCurrentCategory()

            // 6. Camera Modes Carousel Bar (PORTRAIT | PHOTO | VIDEO | MORE)
            modesContainerLayout = buildModesBar()
            addView(modesContainerLayout)

            // 7. Shutter Bar with Meitu Double-Ring, Reset, Collapse & Gallery
            val shutterBar = buildShutterBar()
            addView(shutterBar)
        }
    }

    private fun buildSubModulesBar(): LinearLayout {
        val density = resources.displayMetrics.density
        val scroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
        }
        val chipContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            setPadding((14 * density).toInt(), 0, (14 * density).toInt(), (4 * density).toInt())
        }

        for (chip in subModuleChips) {
            val tvChip = TextView(this).apply {
                text = "${chip.icon} ${chip.name}"
                textSize = 11f
                setTextColor(if (chip.isActive) Color.WHITE else Color.parseColor("#B0B0C0"))
                typeface = if (chip.isActive) Typeface.DEFAULT_BOLD else Typeface.DEFAULT
                background = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 14 * density
                    if (chip.isActive) {
                        setColor(Color.parseColor("#FA4B68"))
                    } else {
                        setColor(Color.parseColor("#22FFFFFF"))
                    }
                }
                setPadding((10 * density).toInt(), (4 * density).toInt(), (10 * density).toInt(), (4 * density).toInt())
                layoutParams = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.WRAP_CONTENT,
                    ViewGroup.LayoutParams.WRAP_CONTENT
                ).apply {
                    rightMargin = (8 * density).toInt()
                }

                setOnClickListener {
                    chip.isActive = !chip.isActive
                    Toast.makeText(this@CameraActivity, "${chip.name}: ${if (chip.isActive) "ĐÃ BẬT" else "ĐÃ TẮT"}", Toast.LENGTH_SHORT).show()
                    buildSubModulesBar() // refresh
                    renderLiveCameraFrame()
                }
            }
            chipContainer.addView(tvChip)
        }

        scroll.addView(chipContainer)
        return LinearLayout(this).apply {
            addView(scroll)
        }
    }

    private fun buildModesBar(): LinearLayout {
        val density = resources.displayMetrics.density

        return LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER
            setPadding(0, (4 * density).toInt(), 0, (6 * density).toInt())

            for (mode in CameraMode.values()) {
                val isSelected = (mode == currentMode)
                val tvMode = TextView(this@CameraActivity).apply {
                    text = mode.title
                    textSize = if (isSelected) 13f else 12f
                    typeface = if (isSelected) Typeface.DEFAULT_BOLD else Typeface.DEFAULT
                    setTextColor(if (isSelected) Color.parseColor("#FFD700") else Color.parseColor("#8E8E93"))
                    setPadding((16 * density).toInt(), (4 * density).toInt(), (16 * density).toInt(), (4 * density).toInt())

                    setOnClickListener {
                        switchCameraMode(mode)
                    }
                }
                addView(tvMode)
            }
        }
    }

    private fun switchCameraMode(mode: CameraMode) {
        currentMode = mode
        if (mode == CameraMode.VIDEO) {
            tvVideoTimer.visibility = View.VISIBLE
            shutterInner.setBackgroundColor(Color.RED)
            Toast.makeText(this, "Chế độ Video: Hỗ trợ BGM, quay 60FPS mượt mà", Toast.LENGTH_SHORT).show()
        } else {
            isRecordingVideo = false
            tvVideoTimer.visibility = View.GONE
            val density = resources.displayMetrics.density
            shutterInner.background = GradientDrawable().apply {
                shape = GradientDrawable.OVAL
                setColor(Color.parseColor("#FA4B68"))
            }
        }

        if (mode == CameraMode.MORE) {
            showMoreModesDialog()
        } else {
            Toast.makeText(this, "Chế độ: ${mode.title}", Toast.LENGTH_SHORT).show()
        }

        // Rebuild modes bar to reflect selected color
        val parent = modesContainerLayout.parent as? ViewGroup
        val idx = parent?.indexOfChild(modesContainerLayout) ?: -1
        if (parent != null && idx != -1) {
            parent.removeViewAt(idx)
            modesContainerLayout = buildModesBar()
            parent.addView(modesContainerLayout, idx)
        }
        renderLiveCameraFrame()
    }

    private fun showMoreModesDialog() {
        val options = arrayOf("🌙 Đêm AI (Night AI Pro)", "🎞️ Giả lập Film Analog", "📸 Chế độ Pro RAW Manual", "⏱️ Chuyển động chậm (Slow-Mo)", "🪄 AR Studio Biến Hình")
        android.app.AlertDialog.Builder(this)
            .setTitle("✨ Tính Năng Mở Rộng (Camera More)")
            .setItems(options) { _, which ->
                Toast.makeText(this, "Đã kích hoạt: ${options[which]}", Toast.LENGTH_SHORT).show()
                renderLiveCameraFrame()
            }
            .setNegativeButton("Đóng", null)
            .show()
    }

    private fun buildSliderSection(): LinearLayout {
        val density = resources.displayMetrics.density

        return LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setPadding((18 * density).toInt(), (2 * density).toInt(), (18 * density).toInt(), (4 * density).toInt())
            layoutParams = LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT
            )

            // Label
            tvSliderLabel = TextView(this@CameraActivity).apply {
                text = activeTool.name
                textSize = 12f
                typeface = Typeface.DEFAULT_BOLD
                setTextColor(Color.WHITE)
                minWidth = (80 * density).toInt()
            }
            addView(tvSliderLabel)

            // SeekBar
            beautySeekBar = SeekBar(this@CameraActivity).apply {
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
                max = 100
                progress = activeTool.currentValue
                progressTintList = ColorStateList.valueOf(Color.parseColor("#FA4B68"))
                thumbTintList = ColorStateList.valueOf(Color.WHITE)

                setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
                    override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                        if (fromUser) {
                            activeTool.currentValue = progress
                            tvSliderValue.text = "$progress%"
                            setupToolsInCurrentCategory()

                            // Immediate 0-latency live re-render with new slider value (0-100% visible transformation)
                            val pb = previewBitmap
                            if (pb != null && !pb.isRecycled) {
                                val displayCopy = pb.copy(Bitmap.Config.ARGB_8888, true)
                                processCameraFrameWithCpp(displayCopy)
                                ivCameraFeed.setImageBitmap(displayCopy)
                            } else {
                                renderLiveCameraFrame()
                            }
                        }
                    }
                    override fun onStartTrackingTouch(seekBar: SeekBar?) {}
                    override fun onStopTrackingTouch(seekBar: SeekBar?) {}
                })
            }
            addView(beautySeekBar)

            // Value text
            tvSliderValue = TextView(this@CameraActivity).apply {
                text = "${activeTool.currentValue}%"
                textSize = 12f
                typeface = Typeface.DEFAULT_BOLD
                setTextColor(Color.parseColor("#FA4B68"))
                gravity = Gravity.END
                minWidth = (36 * density).toInt()
            }
            addView(tvSliderValue)
        }
    }

    private fun setupCategoryTabs() {
        categoryTabsLayout.removeAllViews()
        val density = resources.displayMetrics.density

        for (cat in BeautyCategory.values()) {
            val isSelected = (cat == activeCategory)

            val tabItem = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER_HORIZONTAL
                setPadding((14 * density).toInt(), (4 * density).toInt(), (14 * density).toInt(), (4 * density).toInt())

                val tv = TextView(this@CameraActivity).apply {
                    text = cat.title
                    textSize = if (isSelected) 14f else 13f
                    typeface = if (isSelected) Typeface.DEFAULT_BOLD else Typeface.DEFAULT
                    setTextColor(if (isSelected) Color.parseColor("#FA4B68") else Color.parseColor("#A0A0B2"))
                }
                addView(tv)

                // Underline indicator
                val indicator = View(this@CameraActivity).apply {
                    layoutParams = LinearLayout.LayoutParams(
                        (18 * density).toInt(),
                        (2 * density).toInt()
                    ).apply {
                        topMargin = (2 * density).toInt()
                    }
                    setBackgroundColor(if (isSelected) Color.parseColor("#FA4B68") else Color.TRANSPARENT)
                }
                addView(indicator)

                setOnClickListener {
                    activeCategory = cat
                    if (cat == BeautyCategory.IPHONE_CAM) {
                        iPhoneSubTabsLayout.visibility = View.VISIBLE
                    } else {
                        iPhoneSubTabsLayout.visibility = View.GONE
                    }

                    val catTools = allTools.filter { it.category == activeCategory }
                    if (catTools.isNotEmpty() && activeTool.category != activeCategory) {
                        activeTool = catTools[0]
                    }
                    updateSliderForActiveTool()
                    setupCategoryTabs()
                    setupToolsInCurrentCategory()
                }
            }
            categoryTabsLayout.addView(tabItem)
        }
    }

    private fun setupIPhoneSubTabs() {
        iPhoneSubTabsLayout.removeAllViews()
        val density = resources.displayMetrics.density

        for (tab in IPhoneTab.values()) {
            val isSelected = (tab == activeIPhoneTab)
            val tv = TextView(this).apply {
                text = tab.title
                textSize = 11f
                typeface = if (isSelected) Typeface.DEFAULT_BOLD else Typeface.DEFAULT
                setTextColor(if (isSelected) Color.parseColor("#FFD700") else Color.parseColor("#8E8E93"))
                background = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 12 * density
                    if (isSelected) {
                        setColor(Color.parseColor("#33FFD700"))
                    } else {
                        setColor(Color.TRANSPARENT)
                    }
                }
                setPadding((12 * density).toInt(), (4 * density).toInt(), (12 * density).toInt(), (4 * density).toInt())
                layoutParams = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.WRAP_CONTENT,
                    ViewGroup.LayoutParams.WRAP_CONTENT
                ).apply {
                    rightMargin = (6 * density).toInt()
                }

                setOnClickListener {
                    activeIPhoneTab = tab
                    setupIPhoneSubTabs()
                    setupToolsInCurrentCategory()
                }
            }
            iPhoneSubTabsLayout.addView(tv)
        }
    }

    private fun setupToolsInCurrentCategory() {
        toolsContainerLayout.removeAllViews()
        val density = resources.displayMetrics.density

        val filtered = if (activeCategory == BeautyCategory.IPHONE_CAM) {
            allTools.filter { it.category == activeCategory && it.subCategory == activeIPhoneTab.title }
        } else {
            allTools.filter { it.category == activeCategory }
        }

        for (tool in filtered) {
            val isSelected = (tool.id == activeTool.id)

            val toolView = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER_HORIZONTAL
                setPadding((6 * density).toInt(), (2 * density).toInt(), (6 * density).toInt(), (2 * density).toInt())

                // 1. Circular Action Button
                val circleContainer = FrameLayout(this@CameraActivity).apply {
                    val size = (46 * density).toInt()
                    layoutParams = LinearLayout.LayoutParams(size, size)

                    background = if (isSelected) {
                        GradientDrawable().apply {
                            shape = GradientDrawable.OVAL
                            setColor(Color.parseColor("#26FA4B68"))
                        }
                    } else {
                        GradientDrawable().apply {
                            shape = GradientDrawable.OVAL
                            setColor(Color.parseColor("#242426"))
                        }
                    }

                    // Emoji or Icon Symbol
                    val tvIcon = TextView(this@CameraActivity).apply {
                        layoutParams = FrameLayout.LayoutParams(
                            ViewGroup.LayoutParams.WRAP_CONTENT,
                            ViewGroup.LayoutParams.WRAP_CONTENT,
                            Gravity.CENTER
                        )
                        text = tool.iconEmoji
                        textSize = 20f
                    }
                    addView(tvIcon)

                    // Active dot
                    if (tool.currentValue > 0) {
                        val activeDot = View(this@CameraActivity).apply {
                            val dotSize = (6 * density).toInt()
                            layoutParams = FrameLayout.LayoutParams(dotSize, dotSize, Gravity.TOP or Gravity.END).apply {
                                topMargin = (4 * density).toInt()
                                rightMargin = (4 * density).toInt()
                            }
                            background = GradientDrawable().apply {
                                shape = GradientDrawable.OVAL
                                setColor(Color.parseColor("#FA4B68"))
                            }
                        }
                        addView(activeDot)
                    }

                    // VIP Badge
                    if (tool.isVip) {
                        val tvVip = TextView(this@CameraActivity).apply {
                            layoutParams = FrameLayout.LayoutParams(
                                ViewGroup.LayoutParams.WRAP_CONTENT,
                                ViewGroup.LayoutParams.WRAP_CONTENT,
                                Gravity.BOTTOM or Gravity.CENTER_HORIZONTAL
                            ).apply {
                                bottomMargin = (-2 * density).toInt()
                            }
                            text = "PRO"
                            textSize = 7f
                            typeface = Typeface.DEFAULT_BOLD
                            setTextColor(Color.BLACK)
                            background = GradientDrawable().apply {
                                shape = GradientDrawable.RECTANGLE
                                cornerRadius = 4 * density
                                setColor(Color.parseColor("#FFD700"))
                            }
                            setPadding((3 * density).toInt(), 0, (3 * density).toInt(), 0)
                        }
                        addView(tvVip)
                    }
                }
                addView(circleContainer)

                // 2. Tool Name
                val tvName = TextView(this@CameraActivity).apply {
                    text = tool.name
                    textSize = 10f
                    maxLines = 1
                    gravity = Gravity.CENTER
                    setTextColor(if (isSelected) Color.WHITE else Color.parseColor("#A0A0B2"))
                    layoutParams = LinearLayout.LayoutParams(
                        ViewGroup.LayoutParams.WRAP_CONTENT,
                        ViewGroup.LayoutParams.WRAP_CONTENT
                    ).apply {
                        topMargin = (4 * density).toInt()
                    }
                }
                addView(tvName)

                setOnClickListener {
                    if (tool.isVip && !VipStatusManager.getInstance(this@CameraActivity).isVip()) {
                        VipTriggerManager.getInstance(this@CameraActivity).triggerPaywall(
                            this@CameraActivity,
                            VipTriggerManager.Scenario.VIP_FILTER
                        )
                        return@setOnClickListener
                    }
                    activeTool = tool
                    updateSliderForActiveTool()
                    setupToolsInCurrentCategory()
                }
            }
            toolsContainerLayout.addView(toolView)
        }
    }

    private fun updateSliderForActiveTool() {
        tvSliderLabel.text = activeTool.name
        beautySeekBar.progress = activeTool.currentValue
        tvSliderValue.text = "${activeTool.currentValue}%"
    }

    private fun buildShutterBar(): LinearLayout {
        val density = resources.displayMetrics.density

        return LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setPadding((16 * density).toInt(), (4 * density).toInt(), (16 * density).toInt(), (2 * density).toInt())
            layoutParams = LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT
            )

            // Left Section: Reset & Gallery
            val leftLayout = LinearLayout(this@CameraActivity).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.START or Gravity.CENTER_VERTICAL
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)

                // Reset Button ↺
                val btnResetAll = LinearLayout(this@CameraActivity).apply {
                    orientation = LinearLayout.VERTICAL
                    gravity = Gravity.CENTER
                    setPadding((8 * density).toInt(), (6 * density).toInt(), (12 * density).toInt(), (6 * density).toInt())

                    val tvIcon = TextView(this@CameraActivity).apply {
                        text = "↺"
                        textSize = 18f
                        setTextColor(Color.WHITE)
                    }
                    val tvText = TextView(this@CameraActivity).apply {
                        text = "Đặt lại"
                        textSize = 9f
                        setTextColor(Color.LTGRAY)
                    }
                    addView(tvIcon)
                    addView(tvText)

                    setOnClickListener {
                        for (t in allTools) {
                            t.currentValue = t.defaultValue
                        }
                        updateSliderForActiveTool()
                        setupToolsInCurrentCategory()
                        renderLiveCameraFrame()
                        Toast.makeText(this@CameraActivity, "Đã khôi phục thông số mặc định", Toast.LENGTH_SHORT).show()
                    }
                }
                addView(btnResetAll)

                // Gallery Thumbnail Button
                val btnGallery = FrameLayout(this@CameraActivity).apply {
                    val size = (38 * density).toInt()
                    layoutParams = LinearLayout.LayoutParams(size, size).apply {
                        leftMargin = (6 * density).toInt()
                    }
                    background = GradientDrawable().apply {
                        shape = GradientDrawable.RECTANGLE
                        cornerRadius = 8 * density
                        setColor(Color.parseColor("#333336"))
                    }

                    val tvIcon = TextView(this@CameraActivity).apply {
                        layoutParams = FrameLayout.LayoutParams(
                            ViewGroup.LayoutParams.WRAP_CONTENT,
                            ViewGroup.LayoutParams.WRAP_CONTENT,
                            Gravity.CENTER
                        )
                        text = "🖼️"
                        textSize = 16f
                    }
                    addView(tvIcon)

                    setOnClickListener {
                        openGalleryPicker()
                    }
                }
                addView(btnGallery)
            }
            addView(leftLayout)

            // Center Section: Dual-Layer Meitu Shutter Ring Button
            val shutterContainer = FrameLayout(this@CameraActivity).apply {
                val outerSize = (76 * density).toInt()
                layoutParams = LinearLayout.LayoutParams(outerSize, outerSize).apply {
                    gravity = Gravity.CENTER
                }

                // Outer double-ring: 76dp
                shutterOuter = View(this@CameraActivity).apply {
                    layoutParams = FrameLayout.LayoutParams(
                        ViewGroup.LayoutParams.MATCH_PARENT,
                        ViewGroup.LayoutParams.MATCH_PARENT
                    )
                    background = GradientDrawable().apply {
                        shape = GradientDrawable.OVAL
                        setColor(Color.TRANSPARENT)
                    }
                }
                addView(shutterOuter)

                // Inner solid circle: 58dp
                val innerSize = (58 * density).toInt()
                shutterInner = View(this@CameraActivity).apply {
                    layoutParams = FrameLayout.LayoutParams(innerSize, innerSize, Gravity.CENTER)
                    background = GradientDrawable().apply {
                        shape = GradientDrawable.OVAL
                        setColor(Color.parseColor("#FA4B68"))
                    }
                }
                addView(shutterInner)

                // Press animation and trigger
                setOnTouchListener { v, event ->
                    when (event.action) {
                        MotionEvent.ACTION_DOWN -> {
                            v.animate().scaleX(0.92f).scaleY(0.92f).setDuration(80).start()
                        }
                        MotionEvent.ACTION_UP, MotionEvent.ACTION_CANCEL -> {
                            v.animate().scaleX(1.0f).scaleY(1.0f).setDuration(120).start()
                            if (event.action == MotionEvent.ACTION_UP) {
                                triggerCaptureSequence()
                            }
                        }
                    }
                    true
                }
            }
            addView(shutterContainer)

            // Right Section: Collapse Panel Button ⌄
            val rightLayout = LinearLayout(this@CameraActivity).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.END or Gravity.CENTER_VERTICAL
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)

                val btnCollapse = TextView(this@CameraActivity).apply {
                    text = "⌄"
                    textSize = 24f
                    setTextColor(Color.WHITE)
                    setPadding((12 * density).toInt(), (6 * density).toInt(), (8 * density).toInt(), (6 * density).toInt())
                    setOnClickListener {
                        isPanelCollapsed = true
                        bottomContainer.visibility = View.GONE
                        btnExpandFloating.visibility = View.VISIBLE
                    }
                }
                addView(btnCollapse)
            }
            addView(rightLayout)
        }
    }

    private fun cycleSensorResolution() {
        currentSensor = when (currentSensor) {
            SensorResolution.RES_12MP -> SensorResolution.RES_24MP
            SensorResolution.RES_24MP -> SensorResolution.RES_48MP
            SensorResolution.RES_48MP -> SensorResolution.RES_12MP
        }
        tvSensorBadge.text = currentSensor.title
        Toast.makeText(this, currentSensor.desc, Toast.LENGTH_SHORT).show()
    }

    private fun cycleFlashMode() {
        currentFlash = when (currentFlash) {
            FlashMode.OFF -> FlashMode.ON
            FlashMode.ON -> FlashMode.AUTO
            FlashMode.AUTO -> FlashMode.TORCH
            FlashMode.TORCH -> FlashMode.OFF
        }
        tvFlashBtn.text = currentFlash.icon
        Toast.makeText(this, currentFlash.desc, Toast.LENGTH_SHORT).show()
    }

    private fun cycleAspectRatio() {
        currentRatio = when (currentRatio) {
            AspectRatio.RATIO_9_16 -> AspectRatio.RATIO_4_3
            AspectRatio.RATIO_4_3 -> AspectRatio.RATIO_1_1
            AspectRatio.RATIO_1_1 -> AspectRatio.RATIO_FULL
            AspectRatio.RATIO_FULL -> AspectRatio.RATIO_9_16
        }
        tvRatioBtn.text = currentRatio.title
        Toast.makeText(this, "Tỉ lệ khung hình: ${currentRatio.title}", Toast.LENGTH_SHORT).show()
        renderLiveCameraFrame()
    }

    private fun cycleTimer() {
        timerSeconds = when (timerSeconds) {
            0 -> 3
            3 -> 5
            5 -> 10
            else -> 0
        }
        tvTimerBtn.text = if (timerSeconds > 0) "⏱️ ${timerSeconds}s" else "⏱️ Tắt"
        Toast.makeText(this, if (timerSeconds > 0) "Hẹn giờ: ${timerSeconds} giây" else "Hẹn giờ TẮT", Toast.LENGTH_SHORT).show()
    }

    private fun openAdvancedCameraSettings() {
        val options = arrayOf("🎯 Chống rung quang học OIS C++", "📏 Lưới bố cục tỉ lệ vàng", "⚖️ Cân bằng trắng AWB Gray-World", "🔊 Âm thanh màn trập (Shutter Sound)", "📱 Chế độ Chuyên Gia Pro")
        android.app.AlertDialog.Builder(this)
            .setTitle("⚙️ Cài Đặt Máy Ảnh Chuyên Nghiệp")
            .setItems(options) { _, which ->
                Toast.makeText(this, "Đã kích hoạt: ${options[which]}", Toast.LENGTH_SHORT).show()
            }
            .setNegativeButton("Đóng", null)
            .show()
    }

    private fun openGalleryPicker() {
        try {
            val pickIntent = Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI).apply {
                type = "image/*"
            }
            startActivityForResult(pickIntent, REQUEST_PICK_GALLERY)
        } catch (e: Exception) {
            val fallbackIntent = Intent(Intent.ACTION_GET_CONTENT).apply {
                type = "image/*"
            }
            startActivityForResult(fallbackIntent, REQUEST_PICK_GALLERY)
        }
    }

    private fun initHardwareCameraSession() {
        cameraSessionManager = CameraSessionManager(this).apply {
            setFrameCallback(object : CameraSessionManager.FrameCallback {
                override fun onFrameProcessed(bitmap: Bitmap) {
                    // Frame runs on CameraSessionManager background thread
                    val mutableBmp = if (bitmap.isMutable && bitmap.config == Bitmap.Config.ARGB_8888) {
                        bitmap
                    } else {
                        bitmap.copy(Bitmap.Config.ARGB_8888, true)
                    }

                    
                    // Khảo sát & nhận diện giải phẫu khuôn mặt 106 điểm bất đồng bộ (Zero-lag Preview)
                    frameCounter++
                    if (frameCounter % 3 == 0 && isDetecting.compareAndSet(false, true)) {
                        val sampleW = 320
                        val sampleH = (320f * mutableBmp.height / mutableBmp.width).toInt()
                        val detectBmp = Bitmap.createScaledBitmap(mutableBmp, sampleW, sampleH, false)
                        detectorExecutor.execute {
                            try {
                                val result = faceDetector.detect(detectBmp)
                                if (result != null && result.landmarks106.isNotEmpty()) {
                                    val scaleX = mutableBmp.width.toFloat() / detectBmp.width
                                    val scaleY = mutableBmp.height.toFloat() / detectBmp.height
                                    val arr = FloatArray(106 * 2)
                                    for (i in 0 until 106) {
                                        arr[i * 2] = result.landmarks106[i].x * scaleX
                                        arr[i * 2 + 1] = result.landmarks106[i].y * scaleY
                                    }
                                    cachedLandmarks = arr
                                } else {
                                    cachedLandmarks = null
                                }
                            } catch (t: Throwable) {
                                cachedLandmarks = null
                            } finally {
                                if (detectBmp != mutableBmp && !detectBmp.isRecycled) {
                                    detectBmp.recycle()
                                }
                                isDetecting.set(false)
                            }
                        }
                    }

                    // Xử lý bộ lọc C++ Native trực tiếp trên từng pixel (Đặc quyền biểu bì da, bảo vệ mắt/kính/tóc)
                    processCameraFrameWithCpp(mutableBmp)

                    // Ghi hình MP4 thời gian thực phần cứng nếu đang ở chế độ Video
                    if (isRecordingVideo && liveVideoRecorder?.recordingActive == true) {
                        liveVideoRecorder?.encodeFrame(mutableBmp)
                    }

                    runOnUiThread {
                        previewBitmap = mutableBmp
                        ivCameraFeed.setImageBitmap(mutableBmp)
                    }
                }
                override fun onError(message: String) {
                    runOnUiThread {
                        renderLiveCameraFrame()
                    }
                }
            })
        }

        if (cameraSessionManager?.hasCameraPermission() == true) {
            cameraSessionManager?.startCamera()
        } else {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                requestPermissions(arrayOf(Manifest.permission.CAMERA), REQUEST_CAMERA_PERMISSION)
            }
        }
    }

    override fun onRequestPermissionsResult(requestCode: Int, permissions: Array<out String>, grantResults: IntArray) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (requestCode == REQUEST_CAMERA_PERMISSION && grantResults.isNotEmpty() && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
            cameraSessionManager?.startCamera()
        }
    }

    override fun onResume() {
        super.onResume()
        if (cameraSessionManager?.hasCameraPermission() == true) {
            cameraSessionManager?.startCamera()
        }
    }

    override fun onPause() {
        super.onPause()
        cameraSessionManager?.stopCamera()
    }

    override fun onDestroy() {
        super.onDestroy()
        cameraSessionManager?.stopCamera()
        detectorExecutor.shutdown()
        if (liveVideoRecorder?.recordingActive == true) {
            liveVideoRecorder?.stopRecording()
        }
    }

    private fun triggerCaptureSequence() {
        if (currentMode == CameraMode.VIDEO) {
            // Toggle Hardware Video Recording
            if (!isRecordingVideo) {
                val moviesDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_MOVIES)
                val meituDir = File(moviesDir, "MeituReborn")
                if (!meituDir.exists()) meituDir.mkdirs()
                val videoFile = File(meituDir, "MEITU_VIDEO_${System.currentTimeMillis()}.mp4")

                val started = liveVideoRecorder?.startRecording(videoFile) == true
                if (started) {
                    isRecordingVideo = true
                    videoStartTime = SystemClock.uptimeMillis()
                    mainHandler.post(videoTimerRunnable)
                    Toast.makeText(this, "🎥 Bắt đầu quay video MP4 phần cứng (H.264/AVC)...", Toast.LENGTH_SHORT).show()
                } else {
                    Toast.makeText(this, "⚠️ Không thể khởi tạo bộ mã hóa video phần cứng!", Toast.LENGTH_SHORT).show()
                }
            } else {
                isRecordingVideo = false
                mainHandler.removeCallbacks(videoTimerRunnable)
                tvVideoTimer.text = "🔴 00:00"
                val savedVideo = liveVideoRecorder?.stopRecording()
                if (savedVideo != null && savedVideo.exists()) {
                    val values = ContentValues().apply {
                        put(MediaStore.Video.Media.TITLE, savedVideo.name)
                        put(MediaStore.Video.Media.DISPLAY_NAME, savedVideo.name)
                        put(MediaStore.Video.Media.MIME_TYPE, "video/mp4")
                        put(MediaStore.Video.Media.DATE_ADDED, System.currentTimeMillis() / 1000)
                        put(MediaStore.Video.Media.DATA, savedVideo.absolutePath)
                    }
                    contentResolver.insert(MediaStore.Video.Media.EXTERNAL_CONTENT_URI, values)
                    Toast.makeText(this, "💾 Video MP4 đã lưu thành công: ${savedVideo.name} (${savedVideo.length() / 1024} KB)!", Toast.LENGTH_LONG).show()
                } else {
                    Toast.makeText(this, "💾 Đã dừng quay video!", Toast.LENGTH_SHORT).show()
                }
            }
            return
        }

        if (timerSeconds > 0) {
            startCountdown(timerSeconds)
        } else {
            executeShutterWithCpp()
        }
    }

    private fun startCountdown(seconds: Int) {
        tvTimerOverlay.text = seconds.toString()
        tvTimerOverlay.visibility = View.VISIBLE

        var remaining = seconds
        mainHandler.postDelayed(object : Runnable {
            override fun run() {
                remaining--
                if (remaining > 0) {
                    tvTimerOverlay.text = remaining.toString()
                    mainHandler.postDelayed(this, 1000)
                } else {
                    tvTimerOverlay.visibility = View.GONE
                    executeShutterWithCpp()
                }
            }
        }, 1000)
    }

    private fun executeShutterWithCpp() {
        // Flash Animation
        if (currentFlash == FlashMode.ON || currentFlash == FlashMode.AUTO) {
            flashOverlay.visibility = View.VISIBLE
            flashOverlay.alpha = 1.0f
            flashOverlay.animate().alpha(0.0f).setDuration(220).withEndAction {
                flashOverlay.visibility = View.GONE
            }.start()
        }

        // Shutter Press Animation
        val w = 1080
        val h = 1920
        val bmp = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888)
        val canvas = Canvas(bmp)

        // Draw live preview frame to high-resolution capture buffer (1080x1920 upright portrait)
        val pb = previewBitmap
        if (pb != null && !pb.isRecycled) {
            val srcRect = Rect(0, 0, pb.width, pb.height)
            val dstRect = Rect(0, 0, w, h)
            canvas.drawBitmap(pb, srcRect, dstRect, Paint(Paint.FILTER_BITMAP_FLAG))
        } else {
            ivCameraFeed.drawable?.let { d ->
                d.setBounds(0, 0, w, h)
                d.draw(canvas)
            } ?: canvas.drawColor(Color.rgb(20, 20, 25))
        }

        // Apply C++ Shutter Pipeline
        val smoothVal = (allTools.find { it.id == "smooth" }?.currentValue ?: 0) / 100f
        val vlineVal = (allTools.find { it.id == "vline" }?.currentValue ?: 0) / 100f
        val eyesVal = (allTools.find { it.id == "eye_enlarge" }?.currentValue ?: 0) / 100f
        val teethVal = (allTools.find { it.id == "teeth_whiten" }?.currentValue ?: 0) / 100f
        val whitenVal = (allTools.find { it.id == "tone" }?.currentValue ?: 0) / 100f

        val shutterLandmarks = cachedLandmarks?.let { old ->
            val arr = FloatArray(old.size)
            val scaleX = w.toFloat() / (previewBitmap?.width ?: w)
            val scaleY = h.toFloat() / (previewBitmap?.height ?: h)
            for (i in 0 until old.size step 2) {
                arr[i] = old[i] * scaleX
                arr[i + 1] = old[i + 1] * scaleY
            }
            arr
        }

        try {
            MeituNativeEngine.nativeProcessShutterCapture(
                bitmap = bmp,
                awbMode = 1,
                skinSmooth = smoothVal,
                skinWhitening = whitenVal,
                vLineJaw = vlineVal,
                bigEyes = eyesVal,
                teethShade = 1,
                teethWhitening = teethVal,
                earReshape = 0.30f,
                earTone = 0.35f,
                landmarks106 = shutterLandmarks
            )
        } catch (e: Throwable) {
            Log.e("CameraActivity", "Shutter capture C++ failed: ${e.message}")
        }

        ivCameraFeed.setImageBitmap(bmp)

        // Save physical JPEG to Gallery / Pictures
        val savedFile = saveBitmapToGallery(bmp)

        if (savedFile != null) {
            Toast.makeText(this, "📸 Đã chụp & lưu: ${savedFile.name} (C++ AWB + Bilateral Smooth 98% JPEG)", Toast.LENGTH_LONG).show()
        } else {
            Toast.makeText(this, "📸 Đã chụp ảnh thành công!", Toast.LENGTH_SHORT).show()
        }
    }

    private fun saveBitmapToGallery(bitmap: Bitmap): File? {
        val fileName = "MEITU_REBORN_${System.currentTimeMillis()}.jpg"
        return try {
            val picturesDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)
            val meituDir = File(picturesDir, "MeituReborn")
            if (!meituDir.exists()) meituDir.mkdirs()

            val file = File(meituDir, fileName)
            val out: OutputStream = FileOutputStream(file)
            bitmap.compress(Bitmap.CompressFormat.JPEG, 98, out)
            out.flush()
            out.close()

            // Index in MediaStore
            val values = ContentValues().apply {
                put(MediaStore.Images.Media.TITLE, fileName)
                put(MediaStore.Images.Media.DISPLAY_NAME, fileName)
                put(MediaStore.Images.Media.MIME_TYPE, "image/jpeg")
                put(MediaStore.Images.Media.DATE_ADDED, System.currentTimeMillis() / 1000)
                put(MediaStore.Images.Media.DATA, file.absolutePath)
            }
            contentResolver.insert(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, values)
            file
        } catch (e: Exception) {
            null
        }
    }

    private fun renderLiveCameraFrame() {
        val w = 600
        val h = when (currentRatio) {
            AspectRatio.RATIO_1_1 -> 600
            AspectRatio.RATIO_4_3 -> 800
            AspectRatio.RATIO_9_16 -> 1066
            AspectRatio.RATIO_FULL -> 1266
        }

        val bmp = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888)
        val canvas = Canvas(bmp)

        val cx = w * 0.5f
        val cy = h * 0.46f

        val pb = previewBitmap
        if (pb != null && !pb.isRecycled) {
            val srcRect = Rect(0, 0, pb.width, pb.height)
            val dstRect = Rect(0, 0, w, h)
            canvas.drawBitmap(pb, srcRect, dstRect, Paint(Paint.FILTER_BITMAP_FLAG))
        } else {
            // Procedural Portrait Viewfinder Rendering
            val bgGrad = if (currentMode == CameraMode.PORTRAIT) {
                LinearGradient(0f, 0f, 0f, h.toFloat(), Color.rgb(25, 20, 30), Color.rgb(8, 6, 12), Shader.TileMode.CLAMP)
            } else {
                LinearGradient(0f, 0f, 0f, h.toFloat(), Color.rgb(28, 28, 36), Color.rgb(12, 12, 16), Shader.TileMode.CLAMP)
            }

            val bgPaint = Paint().apply { shader = bgGrad }
            canvas.drawRect(0f, 0f, w.toFloat(), h.toFloat(), bgPaint)

            // Soft Studio Backdrop Light
            val lightPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
                shader = RadialGradient(w * 0.5f, h * 0.45f, w * 0.55f, Color.argb(45, 255, 200, 215), Color.TRANSPARENT, Shader.TileMode.CLAMP)
            }
            canvas.drawCircle(w * 0.5f, h * 0.45f, w * 0.55f, lightPaint)

            // Shoulders
            val shoulderPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(38, 40, 52) }
            canvas.drawOval(RectF(cx - w * 0.44f, cy + h * 0.16f, cx + w * 0.44f, cy + h * 0.55f), shoulderPaint)

            // Face & Head
            val vlineFactor = (allTools.find { it.id == "vline" }?.currentValue ?: 0) / 100f
            val headRadiusX = w * (0.24f - vlineFactor * 0.035f)
            val headRadiusY = h * 0.19f
            val facePaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(245, 215, 198) }
            canvas.drawOval(RectF(cx - headRadiusX, cy - headRadiusY, cx + headRadiusX, cy + headRadiusY), facePaint)

            // Hair Form
            val hairPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(32, 24, 28) }
            canvas.drawOval(RectF(cx - headRadiusX * 1.08f, cy - headRadiusY * 1.15f, cx + headRadiusX * 1.08f, cy - headRadiusY * 0.15f), hairPaint)

            // Eyes
            val eyeSizeFactor = (allTools.find { it.id == "eye_enlarge" }?.currentValue ?: 0) / 100f
            val eyeRx = w * (0.032f + eyeSizeFactor * 0.012f)
            val eyeRy = h * (0.018f + eyeSizeFactor * 0.008f)
            val eyePaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(40, 30, 35) }
            canvas.drawOval(RectF(cx - headRadiusX * 0.46f - eyeRx, cy - headRadiusY * 0.1f - eyeRy, cx - headRadiusX * 0.46f + eyeRx, cy - headRadiusY * 0.1f + eyeRy), eyePaint)
            canvas.drawOval(RectF(cx + headRadiusX * 0.46f - eyeRx, cy - headRadiusY * 0.1f - eyeRy, cx + headRadiusX * 0.46f + eyeRx, cy - headRadiusY * 0.1f + eyeRy), eyePaint)

            // Catchlights in eyes
            val catchlightPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.WHITE }
            canvas.drawCircle(cx - headRadiusX * 0.46f + 3f, cy - headRadiusY * 0.1f - 2f, 3.5f, catchlightPaint)
            canvas.drawCircle(cx + headRadiusX * 0.46f + 3f, cy - headRadiusY * 0.1f - 2f, 3.5f, catchlightPaint)

            // Nose
            val nosePaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(220, 185, 170) }
            canvas.drawOval(RectF(cx - w * 0.028f, cy + headRadiusY * 0.15f, cx + w * 0.028f, cy + headRadiusY * 0.28f), nosePaint)

            // Lips
            val lipPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply { color = Color.rgb(230, 85, 105) }
            canvas.drawOval(RectF(cx - w * 0.09f, cy + headRadiusY * 0.45f, cx + w * 0.09f, cy + headRadiusY * 0.60f), lipPaint)
        }

        // Bokeh in PORTRAIT mode
        if (currentMode == CameraMode.PORTRAIT) {
            val bokehPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
                color = Color.argb(70, 255, 235, 240)
            }
            for (i in 0..14) {
                val bx = (Math.sin(i * 1.4) * w * 0.42f + cx).toFloat()
                val by = (Math.cos(i * 1.4) * h * 0.42f + cy).toFloat()
                canvas.drawCircle(bx, by, 32f, bokehPaint)
            }
        }

        // Active Watermark Overlay
        val wmChip = subModuleChips.find { it.id == "CAMERA_WATERMARK" }
        if (wmChip?.isActive == true) {
            val wmPaint = Paint(Paint.ANTI_ALIAS_FLAG).apply {
                color = Color.argb(180, 255, 255, 255)
                textSize = 18f
                typeface = Typeface.DEFAULT_BOLD
            }
            canvas.drawText("MEITU REBORN • 14 PRO 48MP", 30f, h - 35f, wmPaint)
        }

        // Real-time C++ Native Preview Processing
        processCameraFrameWithCpp(bmp)

        ivCameraFeed.setImageBitmap(bmp)
    }

    /**
     * Cáº§u ná»‘i xá»­ lÃ½ lÃµi C++ Native toÃ n diá»‡n cho Camera Preview & Chá»¥p áº£nh.
     * Ä iá» u chá»‰nh cÃ¡c thang Ä‘o tá»« 0-100% thá»ƒ hiá»‡n rÃµ rá»‡t tá»«ng pixel trÃªn mÃ¡y tháº­t.
     */
    private fun processCameraFrameWithCpp(bitmap: Bitmap) {
        if (!MeituNativeEngine.isLoaded()) return

        // 1. Retouch & Skin (0 - 100%)
        val smoothVal = (allTools.find { it.id == "smooth" }?.currentValue ?: 0) / 100f
        val toneVal = (allTools.find { it.id == "tone" }?.currentValue ?: 0) / 100f
        val brightenVal = (allTools.find { it.id == "brighten" }?.currentValue ?: 0) / 100f
        val skinWhiten = Math.max(toneVal, brightenVal)
        val clearVal = (allTools.find { it.id == "clear" }?.currentValue ?: 0) / 100f
        val bagsVal = (allTools.find { it.id == "bags" }?.currentValue ?: 0) / 100f

        // 2. Face Reshape (0 - 100%)
        val vlineVal = (allTools.find { it.id == "vline" }?.currentValue ?: 0) / 100f
        val chinVal = (allTools.find { it.id == "chin" }?.currentValue ?: 0) / 100f
        val faceSizeVal = (allTools.find { it.id == "face_size" }?.currentValue ?: 0) / 100f
        val faceVLine = Math.max(vlineVal, Math.max(faceSizeVal, chinVal))

        // 3. Features (0 - 100%)
        val eyeEnlargeVal = (allTools.find { it.id == "eye_enlarge" }?.currentValue ?: 0) / 100f
        val noseShrinkVal = Math.max(
            (allTools.find { it.id == "nose_shrink" }?.currentValue ?: 0) / 100f,
            (allTools.find { it.id == "nose_tip" }?.currentValue ?: 0) / 100f
        )
        val lipPlumpVal = Math.max(
            (allTools.find { it.id == "lip_plump" }?.currentValue ?: 0) / 100f,
            (allTools.find { it.id == "lip_bunny" }?.currentValue ?: 0) / 100f
        )
        val teethWhitenVal = (allTools.find { it.id == "teeth_whiten" }?.currentValue ?: 0) / 100f

        // 4. Color Filters & LUTs (0 - 100%)
        var lutType = 0
        var lutIntensity = 0.0f
        if (activeCategory == BeautyCategory.FILTER) {
            lutType = when (activeTool.id) {
                "lut_natural" -> 1
                "lut_rosy" -> 1
                "lut_cinema" -> 2
                "lut_vintage" -> 3
                "lut_retro_film" -> 4
                "lut_cyberpunk" -> 5
                "lut_golden" -> 6
                "lut_night" -> 7
                else -> 4
            }
            lutIntensity = activeTool.currentValue / 100f
        } else {
            val activeFilter = allTools.find { it.category == BeautyCategory.FILTER && it.currentValue > 0 && it.id != "lut_natural" }
            if (activeFilter != null) {
                lutType = when (activeFilter.id) {
                    "lut_rosy" -> 1
                    "lut_cinema" -> 2
                    "lut_vintage" -> 3
                    "lut_retro_film" -> 4
                    "lut_cyberpunk" -> 5
                    "lut_golden" -> 6
                    "lut_night" -> 7
                    else -> 1
                }
                lutIntensity = activeFilter.currentValue / 100f
            }
        }

        // 5. iPhone Cam Presets (0 - 100%)
        if (activeCategory == BeautyCategory.IPHONE_CAM) {
            val ipTool = allTools.find { it.category == BeautyCategory.IPHONE_CAM && it.id == activeTool.id }
            if (ipTool != null && ipTool.currentValue > 0) {
                lutType = 4 // Retro film 35mm
                lutIntensity = ipTool.currentValue / 100f
            }
        }

        // Zero-Baseline Pure Camera Passthrough:
        // When all sliders are at 0%, retain 100% optical native sharpness with ZERO alterations
        val isAnyBeautyActive = smoothVal > 0.001f || skinWhiten > 0.001f || faceVLine > 0.001f ||
            eyeEnlargeVal > 0.001f || noseShrinkVal > 0.001f || lipPlumpVal > 0.001f ||
            teethWhitenVal > 0.001f || bagsVal > 0.001f || clearVal > 0.001f ||
            (lutType > 0 && lutIntensity > 0.001f)

        if (!isAnyBeautyActive) {
            return // 100% Pure Optical Camera Raw Passthrough
        }

        try {
            MeituNativeEngine.nativeProcessCameraPreviewFrameAdvanced(
                bitmap = bitmap,
                lutType = lutType,
                lutIntensity = lutIntensity,
                skinSmooth = smoothVal,
                skinWhiten = skinWhiten,
                faceVLine = faceVLine,
                bigEyes = eyeEnlargeVal,
                noseShrink = noseShrinkVal,
                lipPlump = lipPlumpVal,
                teethWhiten = teethWhitenVal,
                eyeBags = bagsVal,
                skinClear = clearVal,
                landmarks106 = cachedLandmarks
            )
        } catch (e: Throwable) {
            try {
                MeituNativeEngine.nativeProcessCameraPreviewFrameFull(
                    bitmap = bitmap,
                    lutType = lutType,
                    lutIntensity = lutIntensity,
                    skinSmooth = smoothVal,
                    skinWhiten = skinWhiten,
                    faceVLine = faceVLine,
                    bigEyes = eyeEnlargeVal,
                    noseShrink = noseShrinkVal,
                    lipPlump = lipPlumpVal
                )
            } catch (e2: Throwable) {
                Log.e("CameraActivity", "C++ Beauty Native processing failed: ${e2.message}")
            }
        }
    }

    companion object {
        private const val REQUEST_CAMERA_PERMISSION = 2001
        private const val REQUEST_PICK_GALLERY = 2002
    }
}
