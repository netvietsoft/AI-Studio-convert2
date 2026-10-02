package com.meitu.media.PVGCodec

import android.app.Application
import android.content.Context
import androidx.annotation.Keep

/**
 * Quản lý ngữ cảnh ứng dụng cho PVGCodec (Legacy Bridge).
 * Backwards-compatible context holder bridging to PVGContextHolder.
 */
@Keep
object q {
    @Volatile
    @JvmField
    var a: Context? = null

    @JvmField
    val b = Any()

    /**
     * Khởi tạo context cho PVGCodec từ Application instance.
     */
    @JvmStatic
    fun a(application: Application?) {
        PVGContextHolder.init(application)
        a = application?.applicationContext
    }

    /**
     * Helper Kotlin thiết lập context / Set context helper.
     */
    fun init(context: Context) {
        PVGContextHolder.setContext(context)
        a = context.applicationContext
    }
}

/**
 * Clean architectural alias for PVG context adapter.
 */
typealias PVGLegacyContextAdapter = q
