package com.meitu.core

import android.content.Context
import androidx.annotation.Keep

@Keep
object MTAuroraConfigJNI {
    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("arkernel3")
    }

    @JvmStatic
    fun init(context: Context): Boolean = nInit(context.applicationContext)

    @JvmStatic
    private external fun nInit(context: Context): Boolean
}
