package com.meitu.media.PVGCodec

import android.app.Application
import android.content.Context
import androidx.annotation.Keep

/**
 * Quản lý ngữ cảnh ứng dụng cho PVGCodec media framework.
 * Standardized application context holder singleton for PVGCodec.
 */
@Keep
object PVGContextHolder {
    @Volatile
    var applicationContext: Context? = null
        private set

    private val lock = Any()

    /**
     * Khởi tạo context từ Application instance.
     */
    @JvmStatic
    fun init(application: Application?) {
        if (application == null) return
        synchronized(lock) {
            if (applicationContext == null) {
                applicationContext = application.applicationContext
            }
        }
    }

    /**
     * Khởi tạo context từ Context tổng quát.
     */
    @JvmStatic
    fun setContext(context: Context) {
        synchronized(lock) {
            if (applicationContext == null) {
                applicationContext = context.applicationContext
            }
        }
    }

    @JvmStatic
    fun getContext(): Context? = applicationContext
}
