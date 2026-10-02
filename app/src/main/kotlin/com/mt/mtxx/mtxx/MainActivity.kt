package com.mt.mtxx.mtxx

import android.app.Dialog
import android.content.Intent
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.GradientDrawable
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.view.Gravity
import android.view.View
import android.view.ViewGroup
import android.widget.*
import androidx.appcompat.app.AppCompatActivity
import com.meitu.vip.dialog.XXVipDialogHelper
import com.meitu.vip.manager.VipStatusManager
import com.meitu.vip.manager.VipTriggerManager
import com.mt.mtxx.mtxx.camera.CameraActivity
import com.mt.mtxx.mtxx.editor.PhotoEditorActivity
import com.mt.mtxx.mtxx.material.CollageDialog
import com.mt.mtxx.mtxx.material.IdPhotoDialog
import com.mt.mtxx.mtxx.material.OnlineMaterialDialog
import com.mt.mtxx.mtxx.roboneo.RoboNeoChatDialog
import com.mt.mtxx.mtxx.video.VideoEditorActivity

/**
 * Giao diện Trang Chủ Meitu Chuẩn 100% Theo FUNCTIONAL_MAP_MEITU.txt:
 * Mục 1. HOME — Màn hình chính
 * - Bottom Nav (4 tab): Home | Discover | AI Creation | Me
 * - Quick Launch Bar (cuộn ngang 6 món): Photo | Camera | Beautify | Collage | Edit Video | Video Retouch
 * - Featured (13 công cụ AI): Enhancer [AI], Flash [AI], iPhone Camera, ID Photos, AI Removal, Seamless Collage,
 *                             Creative Effects, Edit Live, AI Agent [NEW], Removal, AI Group Photo, Design, All
 * - Trending (11 mục thịnh hành): Video Retouch, AI Dance, AI Art, AI Extender, Watermark, AI Portrait...
 * - Content Feed (4 cards): Exclusive Flash Sale VIP, Back to Retro, Hair Trending, Filter Trending
 */
class MainActivity : AppCompatActivity() {

    private lateinit var vipStatusManager: VipStatusManager
    private lateinit var containerLayout: FrameLayout
    private lateinit var bottomNav: LinearLayout

    private var currentTabIndex = 0

    // Views cho 4 Tabs
    private lateinit var homeView: View
    private lateinit var discoverView: View
    private lateinit var aiCreationView: View
    private lateinit var meView: View

    data class ActionItem(
        val name: String,
        val icon: String,
        val isVip: Boolean = false,
        val isHot: Boolean = false,
        val isAi: Boolean = false,
        val action: () -> Unit
    )

    private fun openHairEditor(toolId: String = "tool_hair_rose_gold") {
        val intent = Intent(this, PhotoEditorActivity::class.java).apply {
            putExtra("target_category", "cat_hair")
            putExtra("tool_id", toolId)
        }
        startActivity(intent)
    }

    private fun openBeardEditor(toolId: String = "tool_beard_quai_non") {
        val intent = Intent(this, PhotoEditorActivity::class.java).apply {
            putExtra("target_category", "cat_beard")
            putExtra("tool_id", toolId)
        }
        startActivity(intent)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        vipStatusManager = VipStatusManager.getInstance(this)

        val density = resources.displayMetrics.density

        val rootLayout = RelativeLayout(this).apply {
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // ==========================================
        // 1. TOP SEARCH & VIP BAR
        // ==========================================
        val topBar = LinearLayout(this).apply {
            id = View.generateViewId()
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val padH = (16 * density).toInt()
            val padV = (10 * density).toInt()
            setPadding(padH, padV, padH, padV)
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = RelativeLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                addRule(RelativeLayout.ALIGN_PARENT_TOP)
            }
        }

        val searchBox = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val pad = (10 * density).toInt()
            setPadding((14 * density).toInt(), pad, (14 * density).toInt(), pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 24f * density
                setColor(Color.parseColor("#1C1C22"))
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            setOnClickListener { showSearchDialog() }
        }

        val tvSearchIcon = TextView(this).apply {
            text = "🔍 "
            textSize = 13f
        }
        val tvSearchHint = TextView(this).apply {
            text = "Tìm kiếm công thức, sticker..."
            textSize = 13f
            setTextColor(Color.parseColor("#8E8E9F"))
        }
        searchBox.addView(tvSearchIcon)
        searchBox.addView(tvSearchHint)

        val btnVipPill = TextView(this).apply {
            text = "VIP"
            textSize = 12f
            setTypeface(typeface, Typeface.BOLD)
            setTextColor(Color.parseColor("#F5C344"))
            val padH = (14 * density).toInt()
            val padV = (6 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 20f * density
                setColor(Color.TRANSPARENT)
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                leftMargin = (12 * density).toInt()
            }
            setOnClickListener {
                XXVipDialogHelper.showPaywall(this@MainActivity, VipTriggerManager.Scenario.APP_LAUNCH_PROMO)
            }
        }

        topBar.addView(searchBox)
        topBar.addView(btnVipPill)
        rootLayout.addView(topBar)

        // ==========================================
        // 2. BOTTOM NAVIGATION BAR (4 TABS CHUẨN MEITU)
        // ==========================================
        bottomNav = LinearLayout(this).apply {
            id = View.generateViewId()
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setBackgroundColor(Color.parseColor("#101014"))
            val h = (58 * density).toInt()
            layoutParams = RelativeLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, h).apply {
                addRule(RelativeLayout.ALIGN_PARENT_BOTTOM)
            }
        }

        // ==========================================
        // 3. CONTAINER CHO CÁC TAB NỘI DUNG
        // ==========================================
        containerLayout = FrameLayout(this).apply {
            layoutParams = RelativeLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT).apply {
                addRule(RelativeLayout.BELOW, topBar.id)
                addRule(RelativeLayout.ABOVE, bottomNav.id)
            }
        }
        rootLayout.addView(containerLayout)
        rootLayout.addView(bottomNav)

        // Khởi tạo 4 View cho 4 Tab
        homeView = buildHomeView(density)
        discoverView = buildDiscoverView(density)
        aiCreationView = buildAiCreationView(density)
        meView = buildMeView(density)

        containerLayout.addView(homeView)
        containerLayout.addView(discoverView)
        containerLayout.addView(aiCreationView)
        containerLayout.addView(meView)

        renderBottomNav(density)
        switchTab(0)

        setContentView(rootLayout)
    }

    private fun renderBottomNav(density: Float) {
        bottomNav.removeAllViews()
        val navItems = listOf(
            Pair("🏠", "Home"),
            Pair("🧭", "Discover"),
            Pair("✨", "AI Creation"),
            Pair("👤", "Me")
        )

        navItems.forEachIndexed { index, (icon, label) ->
            val isSelected = (index == currentTabIndex)
            val tabView = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.MATCH_PARENT, 1f)
                setOnClickListener { switchTab(index) }
            }

            val tvIcon = TextView(this).apply {
                text = icon
                textSize = 17f
            }
            val tvLabel = TextView(this).apply {
                text = label
                textSize = 10f
                setTextColor(if (isSelected) Color.parseColor("#FF2465") else Color.parseColor("#8E8E9F"))
                setTypeface(typeface, if (isSelected) Typeface.BOLD else Typeface.NORMAL)
            }
            tabView.addView(tvIcon)
            tabView.addView(tvLabel)
            bottomNav.addView(tabView)
        }
    }

    private fun switchTab(index: Int) {
        currentTabIndex = index
        homeView.visibility = if (index == 0) View.VISIBLE else View.GONE
        discoverView.visibility = if (index == 1) View.VISIBLE else View.GONE
        aiCreationView.visibility = if (index == 2) View.VISIBLE else View.GONE
        meView.visibility = if (index == 3) View.VISIBLE else View.GONE

        val density = resources.displayMetrics.density
        renderBottomNav(density)
    }

    // =========================================================================
    // TAB 1: HOME VIEW (MỤC 1 TRONG FUNCTIONAL_MAP_MEITU.txt)
    // =========================================================================
    private fun buildHomeView(density: Float): View {
        val scrollView = ScrollView(this).apply {
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        val scrollContent = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val padH = (16 * density).toInt()
            setPadding(padH, (6 * density).toInt(), padH, (24 * density).toInt())
        }

        // 1.1 Hero Banner (Gradient Meitu VIP Flash Sale)
        val banner = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 22f * density
                colors = intArrayOf(Color.parseColor("#FF2A75"), Color.parseColor("#931758"))
                orientation = GradientDrawable.Orientation.TL_BR
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, (115 * density).toInt()).apply {
                bottomMargin = (14 * density).toInt()
            }
            setOnClickListener {
                XXVipDialogHelper.showPaywall(this@MainActivity, VipTriggerManager.Scenario.APP_LAUNCH_PROMO)
            }
        }

        val vipTag = TextView(this).apply {
            text = "VIP EXCLUSIVE FLASH SALE"
            textSize = 9f
            setTypeface(typeface, Typeface.BOLD)
            setTextColor(Color.WHITE)
            val padH = (8 * density).toInt()
            val padV = (2 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 8f * density
                setColor(Color.parseColor("#4D000000"))
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT)
        }

        val tvBannerTitle = TextView(this).apply {
            text = "Selfie Da Thuỷ Tinh Glass Skin Căng Bóng"
            textSize = 16f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, (6 * density).toInt(), 0, 0)
        }

        val tvBannerAuthor = TextView(this).apply {
            text = "Linh Đan Makeup • Mẫu Thịnh Hành Giảm 50%"
            textSize = 11f
            setTextColor(Color.parseColor("#FFE0EB"))
            setPadding(0, 2, 0, 0)
        }

        banner.addView(vipTag)
        banner.addView(tvBannerTitle)
        banner.addView(tvBannerAuthor)
        scrollContent.addView(banner)

        // 1.2 QUICK LAUNCH BAR (CUỘN NGANG 6 MỤC CHUẨN MAP)
        val tvQuickTitle = TextView(this).apply {
            text = "Khởi Động Nhanh (Quick Launch)"
            textSize = 14f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (8 * density).toInt())
        }
        scrollContent.addView(tvQuickTitle)

        val quickScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (16 * density).toInt()
            }
        }
        val quickContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
        }

        val quickItems = listOf(
            ActionItem("Photo", "🎨") { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Beautify", "✨") { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Tóc [VIP]", "💇", isHot = true) { openHairEditor() },
            ActionItem("Râu [VIP]", "🧔", isHot = true) { openBeardEditor() },
            ActionItem("Camera", "📷") { startActivity(Intent(this, CameraActivity::class.java)) },
            ActionItem("Collage", "🧵") { CollageDialog(this).show() },
            ActionItem("Edit Video", "🎬") { startActivity(Intent(this, VideoEditorActivity::class.java)) },
            ActionItem("Video Retouch", "💄") { startActivity(Intent(this, VideoEditorActivity::class.java)) }
        )

        quickItems.forEach { item ->
            val pill = LinearLayout(this).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                val padH = (14 * density).toInt()
                val padV = (10 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 20f * density
                    setColor(Color.parseColor("#18181E"))
                }
                background = bg
                layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    rightMargin = (8 * density).toInt()
                }
                setOnClickListener { item.action() }
            }
            val ic = TextView(this).apply {
                text = item.icon
                textSize = 16f
                setPadding(0, 0, (6 * density).toInt(), 0)
            }
            val nm = TextView(this).apply {
                text = item.name
                textSize = 12f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
            }
            pill.addView(ic)
            pill.addView(nm)
            quickContainer.addView(pill)
        }
        quickScroll.addView(quickContainer)
        scrollContent.addView(quickScroll)

        // 1.3 FEATURED (13 CÔNG CỤ CHÍNH TRANG 1 & 2)
        val tvFeaturedTitle = TextView(this).apply {
            text = "Tính Năng Nổi Bật (Featured Tools)"
            textSize = 14f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (8 * density).toInt())
        }
        scrollContent.addView(tvFeaturedTitle)

        val featuredList = listOf(
            ActionItem("Tóc (Hair) [VIP]", "💇", isHot = true, isAi = true) { openHairEditor() },
            ActionItem("Râu (Beard) [VIP]", "🧔", isHot = true, isAi = true) { openBeardEditor() },
            ActionItem("Enhancer", "⚡", isAi = true) { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Flash AI", "💡", isAi = true) { startActivity(Intent(this, CameraActivity::class.java)) },
            ActionItem("iPhone Cam", "📱") { startActivity(Intent(this, CameraActivity::class.java)) },
            ActionItem("ID Photos", "👔", isHot = true, isAi = true) { IdPhotoDialog(this).show() },

            ActionItem("AI Removal", "🪄", isAi = true) { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Seamless", "🧩") { CollageDialog(this).show() },
            ActionItem("Creative", "🔮") { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Edit Live", "🎞️") { startActivity(Intent(this, PhotoEditorActivity::class.java)) },

            ActionItem("AI Agent", "🤖", isHot = true) { RoboNeoChatDialog(this).show() },
            ActionItem("Removal", "✂️") { startActivity(Intent(this, PhotoEditorActivity::class.java)) },
            ActionItem("Group Photo", "👥", isAi = true) { CollageDialog(this).show() },
            ActionItem("Design", "📜") { OnlineMaterialDialog(this).show() },

            ActionItem("All Tools", "🔍") { showSearchDialog() }
        )

        val gridLayout = GridLayout(this).apply {
            columnCount = 4
            alignmentMode = GridLayout.ALIGN_BOUNDS
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (18 * density).toInt()
            }
        }

        featuredList.forEach { tool ->
            val itemContainer = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER_HORIZONTAL
                val padV = (8 * density).toInt()
                setPadding(0, padV, 0, padV)
                val param = GridLayout.LayoutParams().apply {
                    width = 0
                    height = ViewGroup.LayoutParams.WRAP_CONTENT
                    columnSpec = GridLayout.spec(GridLayout.UNDEFINED, 1f)
                }
                layoutParams = param
                setOnClickListener { tool.action() }
            }

            val iconCard = FrameLayout(this).apply {
                val sqSize = (50 * density).toInt()
                layoutParams = LinearLayout.LayoutParams(sqSize, sqSize).apply {
                    gravity = Gravity.CENTER_HORIZONTAL
                }
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 16f * density
                    setColor(Color.WHITE)
                }
                background = bg
            }

            val tvEmoji = TextView(this).apply {
                text = tool.icon
                textSize = 22f
                gravity = Gravity.CENTER
                layoutParams = FrameLayout.LayoutParams(FrameLayout.LayoutParams.MATCH_PARENT, FrameLayout.LayoutParams.MATCH_PARENT)
            }
            iconCard.addView(tvEmoji)

            val tvName = TextView(this).apply {
                text = tool.name
                textSize = 10.5f
                setTextColor(Color.WHITE)
                gravity = Gravity.CENTER
                maxLines = 1
                setPadding(0, (5 * density).toInt(), 0, 0)
            }

            itemContainer.addView(iconCard)
            itemContainer.addView(tvName)
            gridLayout.addView(itemContainer)
        }
        scrollContent.addView(gridLayout)

        // 1.4 TRENDING SECTION (11 MỤC THỊNH HÀNH)
        val trendHeader = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setPadding(0, 0, 0, (8 * density).toInt())
        }
        val tvTrendTitle = TextView(this).apply {
            text = "Thịnh Hành (Trending Now)"
            textSize = 14f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }
        val tvSeeAll = TextView(this).apply {
            text = "Xem tất cả >"
            textSize = 12f
            setTextColor(Color.parseColor("#FF2465"))
            setOnClickListener { OnlineMaterialDialog(this@MainActivity).show() }
        }
        trendHeader.addView(tvTrendTitle)
        trendHeader.addView(tvSeeAll)
        scrollContent.addView(trendHeader)

        val trendingScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (18 * density).toInt()
            }
        }
        val trendingContainer = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
        }

        val trendingItems = listOf(
            Pair("Tóc & Râu VIP", "🧔"),
            Pair("Video Retouch", "🎬"),
            Pair("AI Dance", "💃"),
            Pair("AI Art", "🎨"),
            Pair("AI Extender", "🔭"),
            Pair("Watermark", "💧"),
            Pair("AI Portrait", "👩"),
            Pair("Wallpaper", "🖼️"),
            Pair("Batch Editing", "📑"),
            Pair("Concert", "🎤"),
            Pair("Shared Album", "📁"),
            Pair("Cutout", "✂️")
        )

        trendingItems.forEach { (title, ic) ->
            val card = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                val w = (110 * density).toInt()
                val h = (120 * density).toInt()
                layoutParams = LinearLayout.LayoutParams(w, h).apply {
                    rightMargin = (10 * density).toInt()
                }
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 14f * density
                    setColor(Color.parseColor("#181820"))
                }
                background = bg
                val pad = (10 * density).toInt()
                setPadding(pad, pad, pad, pad)
                setOnClickListener {
                    when (title) {
                        "Tóc VIP", "Tóc (Hair) [VIP]" -> openHairEditor()
                        "Râu VIP", "Râu (Beard) [VIP]", "Tóc & Râu VIP" -> openBeardEditor()
                        "Video Retouch" -> startActivity(Intent(this@MainActivity, VideoEditorActivity::class.java))
                        "AI Dance", "AI Art", "AI Extender", "AI Portrait" -> RoboNeoChatDialog(this@MainActivity).show()
                        else -> startActivity(Intent(this@MainActivity, PhotoEditorActivity::class.java))
                    }
                }
            }

            val iconTxt = TextView(this).apply {
                text = ic
                textSize = 28f
            }
            val titleTxt = TextView(this).apply {
                text = title
                textSize = 12f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
                setPadding(0, (8 * density).toInt(), 0, 0)
            }
            val hotTag = TextView(this).apply {
                text = "HOT"
                textSize = 8f
                setTextColor(Color.parseColor("#FF2465"))
                setTypeface(typeface, Typeface.BOLD)
            }

            card.addView(iconTxt)
            card.addView(titleTxt)
            card.addView(hotTag)
            trendingContainer.addView(card)
        }
        trendingScroll.addView(trendingContainer)
        scrollContent.addView(trendingScroll)

        scrollView.addView(scrollContent)
        return scrollView
    }

    // =========================================================================
    // TAB 2: DISCOVER VIEW (MỤC 8 TRONG FUNCTIONAL_MAP_MEITU.txt)
    // =========================================================================
    private fun buildDiscoverView(density: Float): View {
        val root = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        val tvTitle = TextView(this).apply {
            text = "Khám Phá Công Thức (Discover)"
            textSize = 18f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (12 * density).toInt())
        }
        root.addView(tvTitle)

        val chips = listOf("Tất cả", "Retro 90s", "Chân Dung Da Thuỷ Tinh", "Tone Hồng Hàn", "Film 35mm", "Cyberpunk")
        val chipsScroll = HorizontalScrollView(this).apply {
            isHorizontalScrollBarEnabled = false
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (16 * density).toInt()
            }
        }
        val chipsContainer = LinearLayout(this).apply { orientation = LinearLayout.HORIZONTAL }
        chips.forEachIndexed { idx, chip ->
            val pill = TextView(this).apply {
                text = chip
                textSize = 12f
                setTextColor(if (idx == 0) Color.BLACK else Color.WHITE)
                setTypeface(typeface, if (idx == 0) Typeface.BOLD else Typeface.NORMAL)
                val padH = (14 * density).toInt()
                val padV = (6 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 16f * density
                    setColor(if (idx == 0) Color.WHITE else Color.parseColor("#1C1C24"))
                }
                background = bg
                layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    rightMargin = (8 * density).toInt()
                }
            }
            chipsContainer.addView(pill)
        }
        chipsScroll.addView(chipsContainer)
        root.addView(chipsScroll)

        val btnOpenStore = TextView(this).apply {
            text = "Mở Kho Công Thức Meitu Store 📂"
            textSize = 14f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            gravity = Gravity.CENTER
            val pad = (14 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 16f * density
                setColor(Color.parseColor("#FF2465"))
            }
            background = bg
            setOnClickListener { OnlineMaterialDialog(this@MainActivity).show() }
        }
        root.addView(btnOpenStore)

        return root
    }

    // =========================================================================
    // TAB 3: AI CREATION VIEW (MỤC 6 TRONG FUNCTIONAL_MAP_MEITU.txt)
    // =========================================================================
    private fun buildAiCreationView(density: Float): View {
        val root = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        val tvTitle = TextView(this).apply {
            text = "AI Creation Studio (Mục 6)"
            textSize = 18f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (6 * density).toInt())
        }
        val tvSub = TextView(this).apply {
            text = "Hệ sinh thái AI tạo sinh & chỉnh sửa ảnh đỉnh cao"
            textSize = 12f
            setTextColor(Color.parseColor("#8E8E9F"))
            setPadding(0, 0, 0, (16 * density).toInt())
        }
        root.addView(tvTitle)
        root.addView(tvSub)

        val aiTools = listOf(
            Triple("RoboNeo AI Agent", "🤖 Trợ lý ảo chỉnh ảnh bằng giọng nói & văn bản", true),
            Triple("AI Photo Enhancer", "⚡ Phục chế ảnh Ultra HD 4K trong 1 chạm", false),
            Triple("AI ID Photos", "👔 Ảnh thẻ chuẩn hộ chiếu 4x6, 3x4 quốc tế", true),
            Triple("AI Dance & Avatar", "💃 Chuyển đổi chân dung thành video vũ đạo", true),
            Triple("AI Outpaint Extender", "🔭 Mở rộng khung ảnh AI tự nhiên", false)
        )

        aiTools.forEach { (name, desc, isVip) ->
            val card = LinearLayout(this).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                val padH = (14 * density).toInt()
                val padV = (12 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 14f * density
                    setColor(Color.parseColor("#181820"))
                }
                background = bg
                layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    bottomMargin = (10 * density).toInt()
                }
                setOnClickListener {
                    if (name.contains("ID")) {
                        IdPhotoDialog(this@MainActivity).show()
                    } else {
                        RoboNeoChatDialog(this@MainActivity).show()
                    }
                }
            }

            val infoLayout = LinearLayout(this).apply {
                orientation = LinearLayout.VERTICAL
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            }
            val nm = TextView(this).apply {
                text = name
                textSize = 14f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
            }
            val ds = TextView(this).apply {
                text = desc
                textSize = 11.5f
                setTextColor(Color.parseColor("#9CA3AF"))
                setPadding(0, (2 * density).toInt(), 0, 0)
            }
            infoLayout.addView(nm)
            infoLayout.addView(ds)
            card.addView(infoLayout)

            if (isVip) {
                val tag = TextView(this).apply {
                    text = "VIP"
                    textSize = 9f
                    setTextColor(Color.BLACK)
                    setTypeface(typeface, Typeface.BOLD)
                    val p = (4 * density).toInt()
                    setPadding(p * 2, p, p * 2, p)
                    val bg = GradientDrawable().apply {
                        shape = GradientDrawable.RECTANGLE
                        cornerRadius = 6f * density
                        setColor(Color.parseColor("#F5C344"))
                    }
                    background = bg
                }
                card.addView(tag)
            }

            root.addView(card)
        }

        return root
    }

    // =========================================================================
    // TAB 4: ME VIEW (MỤC 9 TRONG FUNCTIONAL_MAP_MEITU.txt)
    // =========================================================================
    private fun buildMeView(density: Float): View {
        val root = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // Profile Header
        val profileRow = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            setPadding(0, (10 * density).toInt(), 0, (20 * density).toInt())
        }
        val avatar = TextView(this).apply {
            text = "👤"
            textSize = 28f
            gravity = Gravity.CENTER
            val sz = (56 * density).toInt()
            layoutParams = LinearLayout.LayoutParams(sz, sz)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.OVAL
                setColor(Color.parseColor("#262633"))
            }
            background = bg
        }
        val infoCol = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f).apply {
                leftMargin = (12 * density).toInt()
            }
        }
        val tvName = TextView(this).apply {
            text = "Meitu VIP Member"
            textSize = 17f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
        }
        val tvId = TextView(this).apply {
            text = "ID: MT-888992 • Trạng thái: Đã Kích Hoạt VIP"
            textSize = 11.5f
            setTextColor(Color.parseColor("#F5C344"))
            setPadding(0, 2, 0, 0)
        }
        infoCol.addView(tvName)
        infoCol.addView(tvId)
        profileRow.addView(avatar)
        profileRow.addView(infoCol)
        root.addView(profileRow)

        // VIP Card
        val vipCard = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 16f * density
                colors = intArrayOf(Color.parseColor("#3B2D14"), Color.parseColor("#1C150A"))
                orientation = GradientDrawable.Orientation.LEFT_RIGHT
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                bottomMargin = (18 * density).toInt()
            }
            setOnClickListener {
                XXVipDialogHelper.showPaywall(this@MainActivity, VipTriggerManager.Scenario.APP_LAUNCH_PROMO)
            }
        }
        val tvVipTitle = TextView(this).apply {
            text = "✨ ĐẶC QUYỀN MEITU VIP TRỌN ĐỜI"
            textSize = 13f
            setTextColor(Color.parseColor("#F5C344"))
            setTypeface(typeface, Typeface.BOLD)
        }
        val tvVipDesc = TextView(this).apply {
            text = "Mở khóa 100% Shaders, C++ Native Engine, Cắt ghọt khuôn mặt 106 điểm neo"
            textSize = 11f
            setTextColor(Color.parseColor("#E5E7EB"))
            setPadding(0, (4 * density).toInt(), 0, 0)
        }
        vipCard.addView(tvVipTitle)
        vipCard.addView(tvVipDesc)
        root.addView(vipCard)

        // Menu items
        val menuItems = listOf(
            Pair("Quản lý tài khoản & Bảo mật", "🔒"),
            Pair("Cài đặt cá nhân hóa", "🎨"),
            Pair("Quét mã QR", "📷"),
            Pair("Trợ giúp & Phản hồi", "💬"),
            Pair("Điều khoản & Chính sách quyền riêng tư", "📜")
        )

        menuItems.forEach { (title, ic) ->
            val row = LinearLayout(this).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                val padV = (14 * density).toInt()
                setPadding(0, padV, 0, padV)
            }
            val icon = TextView(this).apply {
                text = ic
                textSize = 18f
                setPadding(0, 0, (12 * density).toInt(), 0)
            }
            val titleTxt = TextView(this).apply {
                text = title
                textSize = 13.5f
                setTextColor(Color.WHITE)
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            }
            val arrow = TextView(this).apply {
                text = ">"
                textSize = 13f
                setTextColor(Color.parseColor("#71717A"))
            }
            row.addView(icon)
            row.addView(titleTxt)
            row.addView(arrow)
            root.addView(row)
        }

        return root
    }

    // =========================================================================
    // DIALOG TÌM KIẾM
    // =========================================================================
    private fun showSearchDialog() {
        val density = resources.displayMetrics.density
        val dialog = Dialog(this, android.R.style.Theme_Black_NoTitleBar_Fullscreen)
        val root = LinearLayout(this).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            setPadding((16 * density).toInt(), (20 * density).toInt(), (16 * density).toInt(), (16 * density).toInt())
        }

        val searchHeader = LinearLayout(this).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
        }
        val btnClose = TextView(this).apply {
            text = "✕"
            textSize = 20f
            setTextColor(Color.WHITE)
            setPadding(0, 0, (16 * density).toInt(), 0)
            setOnClickListener { dialog.dismiss() }
        }
        val etSearch = EditText(this).apply {
            hint = "Nhập từ khóa tìm kiếm (Ví dụ: Chân dung, VIP, Film)..."
            setHintTextColor(Color.parseColor("#71717A"))
            setTextColor(Color.WHITE)
            textSize = 14f
            val pad = (10 * density).toInt()
            setPadding(pad, pad, pad, pad)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 12f * density
                setColor(Color.parseColor("#1C1C22"))
            }
            background = bg
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }
        searchHeader.addView(btnClose)
        searchHeader.addView(etSearch)
        root.addView(searchHeader)

        dialog.setContentView(root)
        dialog.show()
    }
}
