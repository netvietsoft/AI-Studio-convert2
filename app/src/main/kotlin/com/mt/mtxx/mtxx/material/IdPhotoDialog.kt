package com.mt.mtxx.mtxx.material

import android.app.Dialog
import android.content.Context
import android.content.Intent
import android.graphics.Color
import android.graphics.Typeface
import android.graphics.drawable.GradientDrawable
import android.view.Gravity
import android.view.View
import android.view.ViewGroup
import android.widget.*
import com.meitu.common.ui.theme.MeituColors
import com.mt.mtxx.mtxx.camera.CameraActivity
import com.mt.mtxx.mtxx.editor.PhotoEditorActivity

/**
 * IdPhotoDialog: Chuẩn hóa theo Mục 7 của FUNCTIONAL_MAP_MEITU.txt:
 * 7. ID PHOTOS — Ảnh Thẻ / Hộ Chiếu
 * - Danh mục kích thước: Hộ chiếu VN (40x60mm), Hồ sơ xin việc (30x40mm), Bằng lái, Giấy khám SK...
 * - Đổi màu phông: Trắng, Xanh dương, Đỏ, Xám
 * - Công cụ: Chỉnh dung lượng file (KB), Crop photo, Profile Photo LinkedIn
 */
class IdPhotoDialog(context: Context) : Dialog(context, android.R.style.Theme_Black_NoTitleBar_Fullscreen) {

    data class IdSpec(val name: String, val sizeMm: String, val pxDesc: String, val isHot: Boolean = false)

    private val specs = listOf(
        IdSpec("Hộ chiếu Việt Nam (Passport)", "40 x 60 mm", "472 x 709 px", true),
        IdSpec("Hồ sơ xin việc / CV / HR Docs", "30 x 40 mm", "354 x 472 px", true),
        IdSpec("Bằng tốt nghiệp Đại học", "30 x 40 mm", "354 x 472 px"),
        IdSpec("Giấy phép lao động (Work Permit)", "40 x 60 mm", "472 x 709 px"),
        IdSpec("Giấy khám sức khỏe", "40 x 60 mm", "472 x 709 px"),
        IdSpec("Visa Mỹ / Quốc tế (Square)", "50 x 50 mm", "600 x 600 px", true),
        IdSpec("Bằng lái xe quốc tế", "35 x 45 mm", "413 x 531 px")
    )

    private val bgColors = listOf(
        Pair("Trắng", Color.WHITE),
        Pair("Xanh Chuẩn", Color.parseColor("#1D4ED8")),
        Pair("Xanh Nhạt", Color.parseColor("#38BDF8")),
        Pair("Đỏ", Color.parseColor("#DC2626")),
        Pair("Xám Studio", Color.parseColor("#64748B"))
    )

    private var selectedSpec = specs[0]
    private var selectedBgColor = bgColors[1].second

    init {
        val density = context.resources.displayMetrics.density

        val root = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            setBackgroundColor(Color.parseColor("#0C0C0F"))
            layoutParams = ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }

        // 1. Header
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
            text = "Ảnh Thẻ & Hộ Chiếu AI"
            textSize = 18f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
        }

        val btnCamera = TextView(context).apply {
            text = "Chụp Ngay 📷"
            textSize = 13f
            setTextColor(Color.BLACK)
            setTypeface(typeface, Typeface.BOLD)
            val padH = (12 * density).toInt()
            val padV = (6 * density).toInt()
            setPadding(padH, padV, padH, padV)
            val bg = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 16f * density
                setColor(Color.parseColor("#F5C344"))
            }
            background = bg
            setOnClickListener {
                dismiss()
                context.startActivity(Intent(context, CameraActivity::class.java))
            }
        }

        header.addView(btnClose)
        header.addView(tvTitle)
        header.addView(btnCamera)
        root.addView(header)

        // 2. Scrollable Body
        val scrollView = ScrollView(context).apply {
            layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT)
        }
        val body = LinearLayout(context).apply {
            orientation = LinearLayout.VERTICAL
            val pad = (16 * density).toInt()
            setPadding(pad, pad, pad, (32 * density).toInt())
        }

        // Section: Đổi màu nền (Background Color)
        val tvBgHeader = TextView(context).apply {
            text = "1. Chọn Màu Phông Nền Chuẩn"
            textSize = 15f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (10 * density).toInt())
        }
        body.addView(tvBgHeader)

        val bgRow = LinearLayout(context).apply {
            orientation = LinearLayout.HORIZONTAL
            setPadding(0, 0, 0, (20 * density).toInt())
        }

        bgColors.forEach { (name, color) ->
            val colorBtn = LinearLayout(context).apply {
                orientation = LinearLayout.VERTICAL
                gravity = Gravity.CENTER
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
                setOnClickListener {
                    selectedBgColor = color
                    val toolId = when (name) {
                        "Trắng" -> "tool_id_bg_white"
                        "Xanh Chuẩn" -> "tool_id_bg_blue"
                        "Xanh Nhạt" -> "tool_id_bg_cyan"
                        "Đỏ" -> "tool_id_bg_red"
                        else -> "tool_id_bg_gray"
                    }
                    Toast.makeText(context, "Đã chọn phông nền: $name", Toast.LENGTH_SHORT).show()
                    dismiss()
                    val intent = Intent(context, PhotoEditorActivity::class.java).apply {
                        putExtra("tool_id", toolId)
                        putExtra("intensity", 100)
                    }
                    context.startActivity(intent)
                }
            }
            val circle = View(context).apply {
                val size = (38 * density).toInt()
                layoutParams = LinearLayout.LayoutParams(size, size).apply {
                    bottomMargin = (4 * density).toInt()
                }
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.OVAL
                    setColor(color)
                }
                background = bg
            }
            val label = TextView(context).apply {
                text = name
                textSize = 10f
                setTextColor(Color.parseColor("#A1A1AA"))
                gravity = Gravity.CENTER
            }
            colorBtn.addView(circle)
            colorBtn.addView(label)
            bgRow.addView(colorBtn)
        }
        body.addView(bgRow)

        // Section: Danh mục kích thước chuẩn (Standard Sizes)
        val tvSpecHeader = TextView(context).apply {
            text = "2. Tiêu Chuẩn Kích Thước Giấy Tờ"
            textSize = 15f
            setTextColor(Color.WHITE)
            setTypeface(typeface, Typeface.BOLD)
            setPadding(0, 0, 0, (10 * density).toInt())
        }
        body.addView(tvSpecHeader)

        specs.forEach { spec ->
            val card = LinearLayout(context).apply {
                orientation = LinearLayout.HORIZONTAL
                gravity = Gravity.CENTER_VERTICAL
                val padH = (14 * density).toInt()
                val padV = (12 * density).toInt()
                setPadding(padH, padV, padH, padV)
                val bg = GradientDrawable().apply {
                    shape = GradientDrawable.RECTANGLE
                    cornerRadius = 14f * density
                    setColor(Color.parseColor("#18181B"))
                }
                background = bg
                layoutParams = LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT).apply {
                    bottomMargin = (10 * density).toInt()
                }
                setOnClickListener {
                    selectedSpec = spec
                    val toolId = if (spec.sizeMm.contains("30")) "tool_id_crop_3x4" else "tool_id_crop_4x6"
                    Toast.makeText(context, "Đang mở trình tạo ảnh thẻ: ${spec.name}", Toast.LENGTH_SHORT).show()
                    dismiss()
                    val intent = Intent(context, PhotoEditorActivity::class.java).apply {
                        putExtra("tool_id", toolId)
                        putExtra("intensity", 100)
                    }
                    context.startActivity(intent)
                }
            }

            val icon = TextView(context).apply {
                text = "📄"
                textSize = 22f
                setPadding(0, 0, (12 * density).toInt(), 0)
            }

            val infoLayout = LinearLayout(context).apply {
                orientation = LinearLayout.VERTICAL
                layoutParams = LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f)
            }

            val tvName = TextView(context).apply {
                text = spec.name
                textSize = 14f
                setTextColor(Color.WHITE)
                setTypeface(typeface, Typeface.BOLD)
            }

            val tvDims = TextView(context).apply {
                text = "${spec.sizeMm}  •  ${spec.pxDesc}"
                textSize = 12f
                setTextColor(Color.parseColor("#F43F5E"))
            }

            infoLayout.addView(tvName)
            infoLayout.addView(tvDims)

            card.addView(icon)
            card.addView(infoLayout)

            if (spec.isHot) {
                val tag = TextView(context).apply {
                    text = "HOT"
                    textSize = 9f
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
