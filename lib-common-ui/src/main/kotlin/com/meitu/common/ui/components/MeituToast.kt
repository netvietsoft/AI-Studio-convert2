package com.meitu.common.ui.components

import android.content.Context
import android.widget.Toast

/**
 * Tiện ích hiển thị Toast thông báo nhanh chuẩn Meitu.
 */
object MeituToast {
    fun show(context: Context, message: String, isLong: Boolean = false) {
        val duration = if (isLong) Toast.LENGTH_LONG else Toast.LENGTH_SHORT
        Toast.makeText(context.applicationContext, message, duration).show()
    }
}
