package com.meitu.core.facelift

import android.graphics.Bitmap
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader
import com.meitu.core.TypesBaseClass

/**
 * Cầu nối JNI thu nhỏ / phóng to đầu và khuôn mặt (Head Scale).
 * Nguồn: com.meitu.core.facelift.MTHeadScale.java
 */
@Keep
class MTHeadScale : TypesBaseClass() {

    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("MTFilterKernel")
    }

    fun scaleHead(bitmap: Bitmap, scaleFactor: Float): Boolean {
        return nativeScaleHead(bitmap, scaleFactor)
    }

    private external fun nativeScaleHead(bitmap: Bitmap, scaleFactor: Float): Boolean
}
