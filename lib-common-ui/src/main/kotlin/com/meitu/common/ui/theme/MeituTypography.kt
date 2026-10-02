package com.meitu.common.ui.theme

import android.content.Context
import android.graphics.Typeface
import java.util.concurrent.ConcurrentHashMap

/**
 * Quản lý nạp 29 Custom Fonts từ thư mục assets/fonts/.
 */
object MeituTypography {
    private val fontCache = ConcurrentHashMap<String, Typeface>()

    const val FONT_TITLE = "fonts/DIN-Bold.otf"
    const val FONT_REGULAR = "fonts/DIN-Medium.otf"
    const val FONT_BEAUTY = "fonts/f2905141b7147b45ad081f9a886f7b15.ttf"

    fun getTypeface(context: Context, fontAssetPath: String): Typeface {
        return fontCache.getOrPut(fontAssetPath) {
            try {
                Typeface.createFromAsset(context.assets, fontAssetPath)
            } catch (e: Exception) {
                Typeface.DEFAULT
            }
        }
    }
}
