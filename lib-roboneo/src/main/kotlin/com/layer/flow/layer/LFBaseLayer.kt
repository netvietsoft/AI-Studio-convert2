// Source decompiled: jadx_src/sources/com/layer/flow/layer/LFBaseLayer.java
package com.layer.flow.layer

import androidx.annotation.Keep
import com.layer.flow.LayerFlow

@Keep
open class LFBaseLayer(
    var nativeHandler: Long = 0L,
    var sharedCppObj: Boolean = false
) {

    fun getLayerId(): Long {
        val ptr = nativeHandler
        return if (ptr != 0L) nGetLayerId(ptr) else 0L
    }

    fun getName(): String {
        val ptr = nativeHandler
        return if (ptr != 0L) nGetName(ptr) ?: "" else ""
    }

    fun getFilterUUID(): Long {
        val ptr = nativeHandler
        return if (ptr != 0L) nGetFilterUUID(ptr) else 0L
    }

    fun destroy() {
        val ptr = nativeHandler
        if (ptr != 0L && !sharedCppObj) {
            nDestroy(ptr)
            nativeHandler = 0L
        }
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (other !is LFBaseLayer) return false
        return this.nativeHandler == other.nativeHandler
    }

    override fun hashCode(): Int = nativeHandler.hashCode()

    protected fun finalize() {
        destroy()
    }

    companion object {
        init {
            // Đảm bảo thư viện libLayerFlow.so đã được nạp
            LayerFlow
        }

        @JvmStatic
        external fun nDestroy(handler: Long)

        @JvmStatic
        external fun nGetName(handler: Long): String?

        @JvmStatic
        external fun nGetLayerId(handler: Long): Long

        @JvmStatic
        external fun nGetFilterUUID(handler: Long): Long

        @JvmStatic
        external fun nCreateLayerByCategoryFunction(
            category: Int,
            subCategory: Int,
            functionId: Int,
            type: Int,
            extra: Int
        ): Long

        @JvmStatic
        fun createLayerByCategoryFunction(
            category: Int,
            subCategory: Int,
            functionId: Int,
            type: Int,
            extra: Int = 0
        ): LFBaseLayer {
            val ptr = nCreateLayerByCategoryFunction(category, subCategory, functionId, type, extra)
            return LFBaseLayer(ptr)
        }
    }
}
