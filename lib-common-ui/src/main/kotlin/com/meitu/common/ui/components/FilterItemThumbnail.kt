package com.meitu.common.ui.components

import android.content.Context
import android.graphics.drawable.GradientDrawable
import android.util.AttributeSet
import android.view.Gravity
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.TextView
import com.meitu.common.ui.theme.MeituColors

/**
 * Component hiển thị một ô Thumbnail của Bộ lọc ảnh (Filter Item)
 * Hỗ trợ trạng thái Selected (Viền hồng Gradient) và Vip Badge.
 */
class FilterItemThumbnail @JvmOverloads constructor(
    context: Context,
    attrs: AttributeSet? = null,
    defStyleAttr: Int = 0
) : LinearLayout(context, attrs, defStyleAttr) {

    val imageView = ImageView(context)
    val titleView = TextView(context)
    var isVip: Boolean = false
        set(value) {
            field = value
            updateBadge()
        }

    var isSelectedFilter: Boolean = false
        set(value) {
            field = value
            updateSelectionBorder()
        }

    init {
        orientation = VERTICAL
        gravity = Gravity.CENTER_HORIZONTAL

        imageView.layoutParams = LayoutParams(140, 140)
        imageView.scaleType = ImageView.ScaleType.CENTER_CROP
        addView(imageView)

        titleView.layoutParams = LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT).apply {
            topMargin = 8
        }
        titleView.textSize = 12f
        titleView.setTextColor(MeituColors.TextSecondary)
        addView(titleView)

        updateSelectionBorder()
    }

    private fun updateSelectionBorder() {
        if (isSelectedFilter) {
            val border = GradientDrawable().apply {
                shape = GradientDrawable.RECTANGLE
                cornerRadius = 16f
                setStroke(4, MeituColors.PrimaryPink)
            }
            imageView.background = border
            titleView.setTextColor(MeituColors.PrimaryPink)
        } else {
            imageView.background = null
            titleView.setTextColor(MeituColors.TextSecondary)
        }
    }

    private fun updateBadge() {
        // Có thể bổ sung icon vương miện VIP góc trên thumbnail
    }
}
