package com.meitu.core

import android.content.Context
import androidx.annotation.Keep

/**
 * Điểm khởi tạo môi trường đồ hoạ Core của Meitu.
 * Nguồn: com.meitu.core.MteApplication.java
 */
@Keep
class MteApplication private constructor() {

    private var context: Context? = null
    private var isForTest = false

    companion object {
        @Volatile
        private var instance: MteApplication? = null
        private var hasLoadedLibrary = false
        private val syncLock = Any()

        @JvmStatic
        fun getInstance(): MteApplication {
            return instance ?: synchronized(syncLock) {
                instance ?: MteApplication().also { instance = it }
            }
        }

        @JvmStatic
        fun init(ctx: Context) {
            getInstance().context = ctx.applicationContext
            loadLibrary()
        }

        @JvmStatic
        fun loadLibrary(): Boolean {
            synchronized(syncLock) {
                if (!hasLoadedLibrary) {
                    hasLoadedLibrary = MeituNativeLoader.loadLibrary("c++_shared")
                }
                return hasLoadedLibrary
            }
        }
    }

    fun getContext(): Context? = context

    fun setForTest(forTest: Boolean) {
        this.isForTest = forTest
    }
}
