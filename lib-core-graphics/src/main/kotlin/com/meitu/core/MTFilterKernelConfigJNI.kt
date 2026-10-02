package com.meitu.core

import android.content.Context
import android.content.res.AssetManager
import androidx.annotation.Keep

/**
 * JNI Bridge cấu hình Filter Kernel C++.
 * Giữ nguyên 100% Package & Method Signature tương thích libMTFilterKernel.so.
 * Nguồn: com.meitu.core.MTFilterKernelConfigJNI.java
 */
@Keep
object MTFilterKernelConfigJNI {

    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("MTFilterKernel")
    }

    @JvmStatic
    fun init(context: Context): Boolean {
        return nInit(context.applicationContext, context.assets)
    }

    @JvmStatic
    fun setLogLevel(level: Int) {
        nSetLogLevel(level)
    }

    // --- NATIVE JNI METHODS ---
    @JvmStatic
    private external fun nInit(context: Context, assetManager: AssetManager): Boolean

    @JvmStatic
    private external fun nSetLogLevel(level: Int)
}
