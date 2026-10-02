package com.meitu.core

import androidx.annotation.Keep

@Keep
class MTAuroraRender : TypesBaseClass() {
    private var nativeInstance: Long = 0L

    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("arkernel3")
        nativeInstance = nCreate()
    }

    fun release() {
        if (nativeInstance != 0L) {
            nRelease(nativeInstance)
            nativeInstance = 0L
        }
    }

    private external fun nCreate(): Long
    private external fun nRelease(instance: Long)
}
