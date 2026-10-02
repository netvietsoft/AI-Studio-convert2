package com.mt.mtxx.mtxx.material

import android.app.Dialog
import android.content.Context
import android.content.Intent
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.GradientDrawable
import android.view.Gravity
import android.view.ViewGroup
import android.widget.*
import com.mt.mtxx.mtxx.editor.PhotoEditorActivity

/**
 * CollageDialog: Chuẩn hóa theo Mục 5 của FUNCTIONAL_MAP_MEITU.txt:
 * 5. COLLAGE — Ghép Ảnh
 * - Grid (Lưới ảnh 2, 3, 4, 9 ô)
 * - Freeform (Tự do / Scrapbook)
 * - Template (Mẫu)
 * - Seamless Collage [AI]
 * - AI Group Photo [AI]
 */
class CollageDialog(context: Context) : Dialog(context, android.R.style.Theme_Black_NoTitleBar_Fullscreen) {

    data class CollageMode(val id: String, val name: String, val icon: String, val desc: String, val isAi: Boolean = false)

    private val modes = listOf(
        CollageMode("grid", "Lưới Cổ Điển (Grid)", "⊞", "Ghép từ 2 đến 9 ảnh theo bố cục lưới chuẩn tỉ lệ"),
        CollageMode("freeform", "Ghép Tự Do (Freeform)", "✂️", "Xoay, kéo, dán stickers và sắp xếp ảnh tự do theo ý thích"),
        CollageMode("template", "Mẫu Nghệ Thuật (Template)", "📰", "Hơn 500+ mẫu tạp chí, Poster, Plog thời thượng"),
        CollageMode("seamless", "Nối Liền Mạch (Seamless AI)", "🪄", "Tự động phân tích nối liền đường biên ảnh bằng AI", true),
        CollageMode("group_photo", "Ghép Ảnh Nhóm (AI Group Photo)", "👥", "Tổng hợp từng khuôn mặt đẹp nhất vào một bức ảnh chung", true)
    )

    init {
        val density = context.resources.displayMetrics.density

        val root = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // Header
        val header = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            gravity = Gravity.CENTER_VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, pad)
            setBackgroundColor(Color.parseColor("#141419"))
        }

        val btnClose = TextView(context).apply {
            text = "✕"
            textSize = 20f
            setTextColor(Color.WHITE)
            setPadding(0, 0, (16 * density).toInt(), 0)
            setOnClickListener { dismiss() }
        }

        val tvTitle = TextView(context).apply {
            text = "Ghép Ảnh Nghệ Thuật (Collage)"
            textSize = 18f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }

        header.addView(btnClose)
        header.addView(tvTitle)
        root.addView(header)

        // Body
        val scrollView = ScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }
        val body = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, (32 * density).toInt())
        }

        val tvSub = TextView(context).apply {
            text = "Chọn chế độ ghép ảnh sáng tạo:"
            textSize = 14f
            setTextColor(Color.parseColor("#A1A1AA"))
            setPadding(0, 0, 0, (14 * density).toInt())
        }
        body.addView(tvSub)

        modes.forEach { mode ->
            val card = LinearLayout(context).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                val padH = (16 * density).toInt()
                val padV = (14 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 16f * density
                    setColor(Color.parseColor("#18181B"))
                }
                background = bg
                layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    bottomMargin = (12 * density).toInt()
                }
                setOnClickListener {
                    val toolId = when (mode.id) {
                        "grid" -> "tool_collage_grid_4"
                        "freeform" -> "tool_collage_grid_2"
                        "template" -> "tool_collage_grid_3"
                        "seamless", "group_photo" -> "tool_collage_grid_9"
                        else -> "tool_collage_grid_4"
                    }
                    Toast.makeText(context, "Mở chế độ: ${mode.name}", Toast.LENGTH_SHORT).show()
                    dismiss()
                    val intent = Intent(context, PhotoEditorActivity::class.java).apply {
                        putExtra("tool_id", toolId)
                        putExtra("intensity", 50)
                    }
                    context.startActivity(intent)
                }
            }

            val icon = TextView(context).apply {
                text = mode.icon
                textSize = 28f
                setPadding(0, 0, (14 * density).toInt(), 0)
            }

            val infoLayout = LinearLayout(context).apply {
                orientation = LinearLayout.VERTICAL
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            }

            val tvName = TextView(context).apply {
                text = mode.name
                textSize = 15f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
            }

            val tvDesc = TextView(context).apply {
                text = mode.desc
                textSize = 12f
                setTextColor(Color.parseColor("#9CA3AF"))
                setPadding(0, (2 * density).toInt(), 0, 0)
            }

            infoLayout.addView(tvName)
            infoLayout.addView(tvDesc)
            card.addView(icon)
            card.addView(infoLayout)

            if (mode.isAi) {
                val tag = TextView(context).apply {
                    text = "AI"
                    textSize = 10f
                    setTextColor(Color.WHITE)
                    setTypeface(typeface, Typeface.BOLD)
                    val p = (4 * density).toInt()
                    setPadding(p * 2, p, p * 2, p)
                    val bg = GradientDrawable().apply {
                        shape = GradientDrawable.RECTANGLE
                        cornerRadius = 6f * density
                        setColor(Color.parseColor("#E11D48"))
                    }
                    background = bg
                }
                card.addView(tag)
            }

            body.addView(card)
        }

        scrollView.addView(body)
        root.addView(scrollView)
        setContentView(root)
    }
}
