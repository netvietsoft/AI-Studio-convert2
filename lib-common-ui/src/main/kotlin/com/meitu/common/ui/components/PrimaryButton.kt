package com.meitu.common.ui.components

import android.content.Context
import android.graphics.drawable.GradientDrawable
import android.util.AttributeSet
import android.view.Gravity
import androidx.appcompat.widget.AppCompatButton
import com.meitu.common.ui.theme.MeituColors

/**
 * Nút bấm phong cách Meitu Reborn bo tròn kèm gradient thương hiệu.
 */
class PrimaryButton @JvmOverloads constructor(
    context: Context,
    attrs: AttributeSet? = null,
    defStyleAttr: Int = 0
) : AppCompatButton(context, attrs, defStyleAttr) {

    init {
        val bgDrawable = GradientDrawable().apply {
            shape = GradientDrawable.RECTANGLE
            cornerRadius = 48f
            colors = intArrayOf(MeituColors.PrimaryPink, MeituColors.PrimaryCoral)
            orientation = GradientDrawable.Orientation.LEFT_RIGHT
        }
        background = bgDrawable
        setTextColor(MeituColors.TextPrimary)
        gravity = Gravity.CENTER
        textSize = 15f
        isAllCaps = false
    }
}
