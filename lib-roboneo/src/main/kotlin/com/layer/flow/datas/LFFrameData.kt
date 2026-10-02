// Source decompiled: jadx_src/sources/com/layer/flow/datas/LFFrameData.java
package com.layer.flow.datas

import androidx.annotation.Keep
import com.layer.flow.LayerFlow
import java.util.ArrayList

@Keep
open class LFFrameData {
    @Keep
    open class LFFrameModular(
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

        fun getBackgroundColor(): String? = if (nativeHandler != 0L) nGetBackgroundColor(nativeHandler) else null
        fun setBackgroundColor(color: String?) { if (nativeHandler != 0L) nSetBackgroundColor(nativeHandler, color) }

        fun getBackgroundFilterID(): Long = if (nativeHandler != 0L) nGetBackgroundFilterID(nativeHandler) else 0L
        fun setBackgroundFilterID(id: Long) { if (nativeHandler != 0L) nSetBackgroundFilterID(nativeHandler, id) }

        fun getColorIndex(): Int = if (nativeHandler != 0L) nGetColorIndex(nativeHandler) else 0
        fun setColorIndex(index: Int) { if (nativeHandler != 0L) nSetColorIndex(nativeHandler, index) }

        fun getEnable(): Boolean = if (nativeHandler != 0L) nGetEnable(nativeHandler) else false
        fun setEnable(enable: Boolean) { if (nativeHandler != 0L) nSetEnable(nativeHandler, enable) }

        fun getMaterialId(): Long = if (nativeHandler != 0L) nGetMaterialId(nativeHandler) else 0L
        fun setMaterialId(id: Long) { if (nativeHandler != 0L) nSetMaterialId(nativeHandler, id) }

        fun getModular(): String? = if (nativeHandler != 0L) nGetModular(nativeHandler) else null
        fun setModular(modular: String?) { if (nativeHandler != 0L) nSetModular(nativeHandler, modular) }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (other !is LFFrameModular) return false
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
            private external fun nGetBackgroundColor(handler: Long): String?

            @JvmStatic
            private external fun nSetBackgroundColor(handler: Long, color: String?)

            @JvmStatic
            private external fun nGetBackgroundFilterID(handler: Long): Long

            @JvmStatic
            private external fun nSetBackgroundFilterID(handler: Long, id: Long)

            @JvmStatic
            private external fun nGetColorIndex(handler: Long): Int

            @JvmStatic
            private external fun nSetColorIndex(handler: Long, index: Int)

            @JvmStatic
            private external fun nGetEnable(handler: Long): Boolean

            @JvmStatic
            private external fun nSetEnable(handler: Long, enable: Boolean)

            @JvmStatic
            private external fun nGetMaterialId(handler: Long): Long

            @JvmStatic
            private external fun nSetMaterialId(handler: Long, id: Long)

            @JvmStatic
            private external fun nGetModular(handler: Long): String?

            @JvmStatic
            private external fun nSetModular(handler: Long, modular: String?)
        }
    }
}
