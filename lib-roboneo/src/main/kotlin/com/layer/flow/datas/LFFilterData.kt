// Source decompiled: jadx_src/sources/com/layer/flow/datas/LFFilterData.java
package com.layer.flow.datas

import androidx.annotation.Keep
import com.layer.flow.LayerFlow

@Keep
open class LFFilterData {
    @Keep
    open class LFFilterModular(
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

        fun getAiMaterialPath(): String? = if (nativeHandler != 0L) nGetAiMaterialPath(nativeHandler) else null
        fun setAiMaterialPath(path: String?) { if (nativeHandler != 0L) nSetAiMaterialPath(nativeHandler, path) }

        fun getBeautyValue(): Int = if (nativeHandler != 0L) nGetBeautyValue(nativeHandler) else 0
        fun setBeautyValue(value: Int) { if (nativeHandler != 0L) nSetBeautyValue(nativeHandler, value) }

        fun getEnable(): Boolean = if (nativeHandler != 0L) nGetEnable(nativeHandler) else false
        fun setEnable(enable: Boolean) { if (nativeHandler != 0L) nSetEnable(nativeHandler, enable) }

        fun getFilterAlpha(): Int = if (nativeHandler != 0L) nGetFilterAlpha(nativeHandler) else 100
        fun setFilterAlpha(alpha: Int) { if (nativeHandler != 0L) nSetFilterAlpha(nativeHandler, alpha) }

        fun getIsAiMaterial(): Boolean = if (nativeHandler != 0L) nGetIsAiMaterial(nativeHandler) else false
        fun setIsAiMaterial(isAi: Boolean) { if (nativeHandler != 0L) nSetIsAiMaterial(nativeHandler, isAi) }

        fun getMaterialId(): Long = if (nativeHandler != 0L) nGetMaterialId(nativeHandler) else 0L
        fun setMaterialId(id: Long) { if (nativeHandler != 0L) nSetMaterialId(nativeHandler, id) }

        fun getModular(): String? = if (nativeHandler != 0L) nGetModular(nativeHandler) else null
        fun setModular(modular: String?) { if (nativeHandler != 0L) nSetModular(nativeHandler, modular) }

        fun getRandomIndex(): Int = if (nativeHandler != 0L) nGetRandomIndex(nativeHandler) else 0
        fun setRandomIndex(index: Int) { if (nativeHandler != 0L) nSetRandomIndex(nativeHandler, index) }

        fun getTopicMaterialId(): Long = if (nativeHandler != 0L) nGetTopicMaterialId(nativeHandler) else 0L
        fun setTopicMaterialId(id: Long) { if (nativeHandler != 0L) nSetTopicMaterialId(nativeHandler, id) }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (other !is LFFilterModular) return false
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
            private external fun nGetAiMaterialPath(handler: Long): String?

            @JvmStatic
            private external fun nSetAiMaterialPath(handler: Long, path: String?)

            @JvmStatic
            private external fun nGetBeautyValue(handler: Long): Int

            @JvmStatic
            private external fun nSetBeautyValue(handler: Long, value: Int)

            @JvmStatic
            private external fun nGetEnable(handler: Long): Boolean

            @JvmStatic
            private external fun nSetEnable(handler: Long, enable: Boolean)

            @JvmStatic
            private external fun nGetFilterAlpha(handler: Long): Int

            @JvmStatic
            private external fun nSetFilterAlpha(handler: Long, alpha: Int)

            @JvmStatic
            private external fun nGetIsAiMaterial(handler: Long): Boolean

            @JvmStatic
            private external fun nSetIsAiMaterial(handler: Long, isAi: Boolean)

            @JvmStatic
            private external fun nGetMaterialId(handler: Long): Long

            @JvmStatic
            private external fun nSetMaterialId(handler: Long, id: Long)

            @JvmStatic
            private external fun nGetModular(handler: Long): String?

            @JvmStatic
            private external fun nSetModular(handler: Long, modular: String?)

            @JvmStatic
            private external fun nGetRandomIndex(handler: Long): Int

            @JvmStatic
            private external fun nSetRandomIndex(handler: Long, index: Int)

            @JvmStatic
            private external fun nGetTopicMaterialId(handler: Long): Long

            @JvmStatic
            private external fun nSetTopicMaterialId(handler: Long, id: Long)
        }
    }
}
