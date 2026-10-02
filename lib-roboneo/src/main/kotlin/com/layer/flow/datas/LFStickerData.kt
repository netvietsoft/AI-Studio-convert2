// Source decompiled: jadx_src/sources/com/layer/flow/datas/LFStickerData.java
package com.layer.flow.datas

import androidx.annotation.Keep
import com.layer.flow.LayerFlow

@Keep
open class LFStickerData {
    @Keep
    open class LFStickerModular(
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

        fun getAlpha(): Double = if (nativeHandler != 0L) nGetAlpha(nativeHandler) else 1.0
        fun setAlpha(alpha: Double) { if (nativeHandler != 0L) nSetAlpha(nativeHandler, alpha) }

        fun getBlendModeId(): Int = if (nativeHandler != 0L) nGetBlendModeId(nativeHandler) else 0
        fun setBlendModeId(mode: Int) { if (nativeHandler != 0L) nSetBlendModeId(nativeHandler, mode) }

        fun getCenterX(): Double = if (nativeHandler != 0L) nGetCenterX(nativeHandler) else 0.5
        fun setCenterX(x: Double) { if (nativeHandler != 0L) nSetCenterX(nativeHandler, x) }

        fun getCenterY(): Double = if (nativeHandler != 0L) nGetCenterY(nativeHandler) else 0.5
        fun setCenterY(y: Double) { if (nativeHandler != 0L) nSetCenterY(nativeHandler, y) }

        fun getCustomMaterialIds(): List<Long>? = if (nativeHandler != 0L) nGetCustomMaterialIds(nativeHandler) else null
        fun setCustomMaterialIds(ids: List<Long>) { if (nativeHandler != 0L) nSetCustomMaterialIds(nativeHandler, ids) }

        fun getEnable(): Boolean = if (nativeHandler != 0L) nGetEnable(nativeHandler) else false
        fun setEnable(enable: Boolean) { if (nativeHandler != 0L) nSetEnable(nativeHandler, enable) }

        fun getHorizontalFlip(): Boolean = if (nativeHandler != 0L) nGetHorizontalFlip(nativeHandler) else false
        fun setHorizontalFlip(flip: Boolean) { if (nativeHandler != 0L) nSetHorizontalFlip(nativeHandler, flip) }

        fun getImageFullPath(): String? = if (nativeHandler != 0L) nGetImageFullPath(nativeHandler) else null
        fun setImageFullPath(path: String?) { if (nativeHandler != 0L) nSetImageFullPath(nativeHandler, path) }

        fun getIsMaskCovered(): Boolean = if (nativeHandler != 0L) nGetIsMaskCovered(nativeHandler) else false
        fun setIsMaskCovered(covered: Boolean) { if (nativeHandler != 0L) nSetIsMaskCovered(nativeHandler, covered) }

        fun getIsStretched(): Boolean = if (nativeHandler != 0L) nGetIsStretched(nativeHandler) else false
        fun setIsStretched(stretched: Boolean) { if (nativeHandler != 0L) nSetIsStretched(nativeHandler, stretched) }

        fun getMaterialId(): Long = if (nativeHandler != 0L) nGetMaterialId(nativeHandler) else 0L
        fun setMaterialId(id: Long) { if (nativeHandler != 0L) nSetMaterialId(nativeHandler, id) }

        fun getRotate(): Double = if (nativeHandler != 0L) nGetRotate(nativeHandler) else 0.0
        fun setRotate(deg: Double) { if (nativeHandler != 0L) nSetRotate(nativeHandler, deg) }

        fun getStickerType(): Int = if (nativeHandler != 0L) nGetStickerType(nativeHandler) else 0
        fun setStickerType(type: Int) { if (nativeHandler != 0L) nSetStickerType(nativeHandler, type) }

        fun getVerticalFlip(): Boolean = if (nativeHandler != 0L) nGetVerticalFlip(nativeHandler) else false
        fun setVerticalFlip(flip: Boolean) { if (nativeHandler != 0L) nSetVerticalFlip(nativeHandler, flip) }

        fun getWhRatio(): Double = if (nativeHandler != 0L) nGetWhRatio(nativeHandler) else 1.0
        fun setWhRatio(ratio: Double) { if (nativeHandler != 0L) nSetWhRatio(nativeHandler, ratio) }

        fun getWidthRatio(): Double = if (nativeHandler != 0L) nGetWidthRatio(nativeHandler) else 1.0
        fun setWidthRatio(ratio: Double) { if (nativeHandler != 0L) nSetWidthRatio(nativeHandler, ratio) }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (other !is LFStickerModular) return false
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
            private external fun nGetAlpha(handler: Long): Double

            @JvmStatic
            private external fun nGetBlendModeId(handler: Long): Int

            @JvmStatic
            private external fun nGetCenterX(handler: Long): Double

            @JvmStatic
            private external fun nGetCenterY(handler: Long): Double

            @JvmStatic
            private external fun nGetCustomMaterialIds(handler: Long): List<Long>?

            @JvmStatic
            private external fun nGetEnable(handler: Long): Boolean

            @JvmStatic
            private external fun nGetHorizontalFlip(handler: Long): Boolean

            @JvmStatic
            private external fun nGetImageFullPath(handler: Long): String?

            @JvmStatic
            private external fun nGetIsMaskCovered(handler: Long): Boolean

            @JvmStatic
            private external fun nGetIsStretched(handler: Long): Boolean

            @JvmStatic
            private external fun nGetMaterialId(handler: Long): Long

            @JvmStatic
            private external fun nGetRotate(handler: Long): Double

            @JvmStatic
            private external fun nGetStickerType(handler: Long): Int

            @JvmStatic
            private external fun nGetVerticalFlip(handler: Long): Boolean

            @JvmStatic
            private external fun nGetWhRatio(handler: Long): Double

            @JvmStatic
            private external fun nGetWidthRatio(handler: Long): Double

            @JvmStatic
            private external fun nSetAlbumId(handler: Long, id: Long)

            @JvmStatic
            private external fun nSetAlpha(handler: Long, alpha: Double)

            @JvmStatic
            private external fun nSetBlendModeId(handler: Long, mode: Int)

            @JvmStatic
            private external fun nSetCenterX(handler: Long, x: Double)

            @JvmStatic
            private external fun nSetCenterY(handler: Long, y: Double)

            @JvmStatic
            private external fun nSetCustomMaterialIds(handler: Long, ids: List<Long>)

            @JvmStatic
            private external fun nSetEnable(handler: Long, enable: Boolean)

            @JvmStatic
            private external fun nSetHorizontalFlip(handler: Long, flip: Boolean)

            @JvmStatic
            private external fun nSetImageFullPath(handler: Long, path: String?)

            @JvmStatic
            private external fun nSetIsMaskCovered(handler: Long, covered: Boolean)

            @JvmStatic
            private external fun nSetIsStretched(handler: Long, stretched: Boolean)

            @JvmStatic
            private external fun nSetMaterialId(handler: Long, id: Long)

            @JvmStatic
            private external fun nSetRotate(handler: Long, deg: Double)

            @JvmStatic
            private external fun nSetStickerType(handler: Long, type: Int)

            @JvmStatic
            private external fun nSetVerticalFlip(handler: Long, flip: Boolean)

            @JvmStatic
            private external fun nSetWhRatio(handler: Long, ratio: Double)

            @JvmStatic
            private external fun nSetWidthRatio(handler: Long, ratio: Double)
        }
    }
}
