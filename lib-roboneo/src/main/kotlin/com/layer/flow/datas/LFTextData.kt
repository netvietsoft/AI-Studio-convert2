// Source decompiled: jadx_src/sources/com/layer/flow/datas/LFTextData.java
package com.layer.flow.datas

import androidx.annotation.Keep
import com.layer.flow.LayerFlow
import java.util.ArrayList

@Keep
open class LFTextData {
    @Keep
    open class LFTextModular(
        var nativeHandler: Long = 0L
    ) {
        init {
            LayerFlow
        }

        fun destroy() {
            val ptr = nativeHandler
            if (ptr != 0L) {
                nDestroy(ptr)
                nativeHandler = 0L
            }
        }

        fun getAlbumId(): Long = if (nativeHandler != 0L) nGetAlbumId(nativeHandler) else 0L
        fun setAlbumId(id: Long) { if (nativeHandler != 0L) nSetAlbumId(nativeHandler, id) }

        fun getCenterX(): Double = if (nativeHandler != 0L) nGetCenterX(nativeHandler) else 0.5
        fun setCenterX(x: Double) { if (nativeHandler != 0L) nSetCenterX(nativeHandler, x) }

        fun getCenterY(): Double = if (nativeHandler != 0L) nGetCenterY(nativeHandler) else 0.5
        fun setCenterY(y: Double) { if (nativeHandler != 0L) nSetCenterY(nativeHandler, y) }

        fun getEnable(): Boolean = if (nativeHandler != 0L) nGetEnable(nativeHandler) else false
        fun setEnable(enable: Boolean) { if (nativeHandler != 0L) nSetEnable(nativeHandler, enable) }

        fun getMaterialId(): Long = if (nativeHandler != 0L) nGetMaterialId(nativeHandler) else 0L
        fun setMaterialId(id: Long) { if (nativeHandler != 0L) nSetMaterialId(nativeHandler, id) }

        fun getRotate(): Double = if (nativeHandler != 0L) nGetRotate(nativeHandler) else 0.0
        fun setRotate(deg: Double) { if (nativeHandler != 0L) nSetRotate(nativeHandler, deg) }

        fun getWidthRatio(): Double = if (nativeHandler != 0L) nGetWidthRatio(nativeHandler) else 1.0
        fun setWidthRatio(ratio: Double) { if (nativeHandler != 0L) nSetWidthRatio(nativeHandler, ratio) }

        fun getWhRatio(): Double = if (nativeHandler != 0L) nGetWhRatio(nativeHandler) else 1.0
        fun setWhRatio(ratio: Double) { if (nativeHandler != 0L) nSetWhRatio(nativeHandler, ratio) }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (other !is LFTextModular) return false
            return this.nativeHandler == other.nativeHandler
        }

        override fun hashCode(): Int = nativeHandler.hashCode()

        protected fun finalize() {
            destroy()
        }

        companion object {
            @JvmStatic
            private external fun nDestroy(handler: Long)

            @JvmStatic
            private external fun nGetAlbumId(handler: Long): Long

            @JvmStatic
            private external fun nSetAlbumId(handler: Long, id: Long)

            @JvmStatic
            private external fun nGetCenterX(handler: Long): Double

            @JvmStatic
            private external fun nSetCenterX(handler: Long, x: Double)

            @JvmStatic
            private external fun nGetCenterY(handler: Long): Double

            @JvmStatic
            private external fun nSetCenterY(handler: Long, y: Double)

            @JvmStatic
            private external fun nGetEnable(handler: Long): Boolean

            @JvmStatic
            private external fun nSetEnable(handler: Long, enable: Boolean)

            @JvmStatic
            private external fun nGetMaterialId(handler: Long): Long

            @JvmStatic
            private external fun nSetMaterialId(handler: Long, id: Long)

            @JvmStatic
            private external fun nGetRotate(handler: Long): Double

            @JvmStatic
            private external fun nSetRotate(handler: Long, deg: Double)

            @JvmStatic
            private external fun nGetWidthRatio(handler: Long): Double

            @JvmStatic
            private external fun nSetWidthRatio(handler: Long, ratio: Double)

            @JvmStatic
            private external fun nGetWhRatio(handler: Long): Double

            @JvmStatic
            private external fun nSetWhRatio(handler: Long, ratio: Double)
        }
    }
}
