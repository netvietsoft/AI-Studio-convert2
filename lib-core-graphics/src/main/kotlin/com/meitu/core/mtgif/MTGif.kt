package com.meitu.core.mtgif

import android.graphics.Bitmap
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader
import com.meitu.core.TypesBaseClass

/**
 * Cầu nối JNI giải mã và render ảnh động GIF chất lượng cao.
 * Nguồn: com.meitu.core.mtgif.MTGif.java
 */
@Keep
class MTGif : TypesBaseClass() {

    private var nativeInstance: Long = 0L

    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("MTGif")
        nativeInstance = nativeCreate()
    }

    fun openFile(filePath: String): Boolean = nativeOpenFile(nativeInstance, filePath)

    fun getNextFrame(targetBitmap: Bitmap): Int = nativeGetNextFrame(nativeInstance, targetBitmap)

    fun release() {
        if (nativeInstance != 0L) {
            nativeRelease(nativeInstance)
            nativeInstance = 0L
        }
    }

    private external fun nativeCreate(): Long
    private external fun nativeOpenFile(instance: Long, path: String): Boolean
    private external fun nativeGetNextFrame(instance: Long, bitmap: Bitmap): Int
    private external fun nativeRelease(instance: Long)
}
