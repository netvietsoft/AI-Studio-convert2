package com.mt.mtxx.mtxx.material

import android.app.Dialog
import android.content.Intent
import android.content.Context
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.GradientDrawable
import android.view.Gravity
import android.view.ViewGroup
import android.widget.LinearLayout
import android.widget.ScrollView
import android.widget.TextView
import android.widget.Toast
import com.meitu.common.ui.theme.MeituColors
import com.meitu.photoeditor.repo.PhotoRemoteMaterialRepository
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

/**
 * OnlineMaterialDialog: Hiển thị bộ lọc và phong cách trang điểm nạp trực tiếp từ Backend Cổng 9999.
 * Dialog displaying online LUT filters and 3D makeup styles fetched from Backend Port 9999.
 */
class OnlineMaterialDialog(
    context: Context,
    private val onFilterSelected: ((PhotoRemoteMaterialRepository.RemoteFilterItem) -> Unit)? = null,
    private val onMakeupSelected: ((PhotoRemoteMaterialRepository.RemoteMakeupStyle) -> Unit)? = null
) : Dialog(context, android.R.style.Theme_Black_NoTitleBar_Fullscreen) {

    private val scope = CoroutineScope(Dispatchers.Main)
    private lateinit var contentContainer: LinearLayout

    init {
        val density = context.resources.displayMetrics.density

        val root = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(MeituColors.DarkBackground)
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // Header
        val header = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(MeituColors.DarkSurface)
        }

        val btnBack = TextView(context).apply {
            text = "←"
            textSize = 24f
            setTextColor(Color.WHITE)
            setPadding(0, 0, (16 * density).toInt(), 0)
            setOnClickListener { dismiss() }
        }

        val titleTv = TextView(context).apply {
            text = "🎨 Kho Tài Nguyên Online (Port 9999)"
            textSize = 17f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
        }
        header.addView(btnBack)
        header.addView(titleTv)
        root.addView(header)

        // Scrollable content
        val scrollView = ScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }
        contentContainer = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
        }
        scrollView.addView(contentContainer)
        root.addView(scrollView)

        setContentView(root)

        loadOnlineMaterials(density)
    }

    private fun loadOnlineMaterials(density: Float) {
        val loadingTv = TextView(context).apply {
            text = "⏳ Đang kết nối Backend Port 9999 tải danh mục bộ lọc & makeup..."
            textSize = 13f
            setTextColor(MeituColors.TextSecondary)
            gravity = Gravity.CENTER
            val pad = (24 * density).toInt()
            setPadding(pad, pad, pad, pad)
        }
        contentContainer.addView(loadingTv)

        scope.launch {
            val filters = PhotoRemoteMaterialRepository.fetchFilters()
            val makeups = PhotoRemoteMaterialRepository.fetchMakeupStyles()

            contentContainer.removeAllViews()

            // 1. SECTION: BỘ LỌC NGHỆ THUẬT LUTS
            val secFilter = TextView(context).apply {
                text = "🎞️ BỘ LỌC MÀU NGHỆ THUẬT (${filters.size} ITEMS ONLINE)"
                textSize = 13f
                setTextColor(MeituColors.TextMuted)
                setTypeface(typeface, Typeface.BOLD)
                setPadding(0, 8, 0, 12)
            }
            contentContainer.addView(secFilter)

            filters.forEach { item ->
                val card = LinearLayout(context).apply {
                    orientation = LinearLayout.HORIZONTAL
                    gravity = Gravity.CENTER_VERTICAL
                    val pad = (12 * density).toInt()
                    setPadding(pad, pad, pad, pad)
                    val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                        topMargin = (6 * density).toInt()
                    }
                    layoutParams = lp
                    val bg = GradientDrawable().apply {
                        shape = GradientDrawable.RECTANGLE
                        cornerRadius = 16f
                        setColor(MeituColors.DarkSurface)
                    }
                    background = bg
                                        setOnClickListener {
                        Toast.makeText(context, "✅ Áp dụng Filter: ${item.name}", Toast.LENGTH_SHORT).show()
                        if (onFilterSelected != null) {
                            onFilterSelected.invoke(item)
                        } else {
                            try {
                                val intent = Intent(context, com.mt.mtxx.mtxx.editor.PhotoEditorActivity::class.java).apply {
                                    putExtra("APPLY_FILTER_ID", item.id)
                                    putExtra("APPLY_FILTER_NAME", item.name)
                                }
                                context.startActivity(intent)
                            } catch (_: Throwable) {}
                        }
                        dismiss()
                    }
                }

                val title = TextView(context).apply {
                    text = "${if (item.isVip) "👑 " else ""}${item.name}"
                    textSize = 14f
                    setTextColor(if (item.isVip) MeituColors.VipGold else Color.WHITE)
                    setTypeface(typeface, Typeface.BOLD)
                    layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
                }

                val badge = TextView(context).apply {
                    text = "📥 ${item.downloads}"
                    textSize = 12f
                    setTextColor(MeituColors.TextMuted)
                }

                card.addView(title)
                card.addView(badge)
                contentContainer.addView(card)
            }

            // 2. SECTION: PHONG CÁCH MAKEUP 3D
            val secMakeup = TextView(context).apply {
                text = "💄 PHONG CÁCH TRANG ĐIỂM 3D (${makeups.size} STYLES ONLINE)"
                textSize = 13f
                setTextColor(MeituColors.TextMuted)
                setTypeface(typeface, Typeface.BOLD)
                val padTop = (24 * density).toInt()
                setPadding(0, padTop, 0, 12)
            }
            contentContainer.addView(secMakeup)

            makeups.forEach { mk ->
                val card = LinearLayout(context).apply {
                    orientation = LinearLayout.HORIZONTAL
                    gravity = Gravity.CENTER_VERTICAL
                    val pad = (12 * density).toInt()
                    setPadding(pad, pad, pad, pad)
                    val lp = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                        topMargin = (6 * density).toInt()
                    }
                    layoutParams = lp
                    val bg = GradientDrawable().apply {
                        shape = GradientDrawable.RECTANGLE
                        cornerRadius = 16f
                        setColor(MeituColors.DarkSurface)
                    }
                    background = bg
                                        setOnClickListener {
                        Toast.makeText(context, "✅ Áp dụng Makeup 3D: ${mk.name}", Toast.LENGTH_SHORT).show()
                        if (onMakeupSelected != null) {
                            onMakeupSelected.invoke(mk)
                        } else {
                            try {
                                val intent = Intent(context, com.mt.mtxx.mtxx.editor.PhotoEditorActivity::class.java).apply {
                                    putExtra("APPLY_MAKEUP_ID", mk.id)
                                    putExtra("APPLY_MAKEUP_NAME", mk.name)
                                }
                                context.startActivity(intent)
                            } catch (_: Throwable) {}
                        }
                        dismiss()
                    }
                }

                val title = TextView(context).apply {
                    text = "${if (mk.isVip) "👑 " else ""}${mk.name}"
                    textSize = 14f
                    setTextColor(if (mk.isVip) MeituColors.VipGold else Color.WHITE)
                    setTypeface(typeface, Typeface.BOLD)
                    layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
                }

                val categoryTv = TextView(context).apply {
                    text = mk.category
                    textSize = 11f
                    setTextColor(MeituColors.PrimaryPink)
                }

                card.addView(title)
                card.addView(categoryTv)
                contentContainer.addView(card)
            }
        }
    }
}
