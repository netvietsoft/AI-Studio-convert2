// Source decompiled: jadx_src/sources/com/layer/flow/datas/LFMakeUpData.java
package com.layer.flow.datas

import androidx.annotation.Keep
import com.layer.flow.LayerFlow
import java.util.HashMap

@Keep
open class LFMakeUpData {
    @Keep
    open class LFMakeUpModular(
        var nativeHandler: Long = 0L
    ) {
        init {
            LayerFlow
        }

        fun clearFaceData() {
            if (nativeHandler != 0L) nClearFaceData(nativeHandler)
        }

        fun destroy() {
            val ptr = nativeHandler
            if (ptr != 0L) {
                nDestroyModular(ptr)
                nativeHandler = 0L
            }
        }

        fun getEnable(): Boolean = if (nativeHandler != 0L) nGetEnable(nativeHandler) else false
        fun setEnable(enable: Boolean) { if (nativeHandler != 0L) nSetEnable(nativeHandler, enable) }

        fun getFaceDataByFaceId(faceId: Int): Long = if (nativeHandler != 0L) nGetFaceDataByFaceId(nativeHandler, faceId) else 0L
        fun putFaceDataByFaceId(faceId: Int, dataPtr: Long) { if (nativeHandler != 0L) nPutFaceDataByFaceId(nativeHandler, faceId, dataPtr) }
        fun removeFaceDataByFaceId(faceId: Int) { if (nativeHandler != 0L) nRemoveFaceDataByFaceId(nativeHandler, faceId) }

        fun getFaceIds(): IntArray? = if (nativeHandler != 0L) nGetFaceIdsFromFaceMaps(nativeHandler) else null

        fun getModular(): String? = if (nativeHandler != 0L) nGetModular(nativeHandler) else null
        fun setModular(modular: String?) { if (nativeHandler != 0L) nSetModular(nativeHandler, modular) }

        override fun equals(other: Any?): Boolean {
            if (this === other) return true
            if (other !is LFMakeUpModular) return false
            return this.nativeHandler == other.nativeHandler
        }

        override fun hashCode(): Int = nativeHandler.hashCode()

        protected fun finalize() {
            destroy()
        }

        companion object {
            @JvmStatic
            private external fun nClearFaceData(handler: Long)

            @JvmStatic
            private external fun nDestroyModular(handler: Long)

            @JvmStatic
            private external fun nGetEnable(handler: Long): Boolean

            @JvmStatic
            private external fun nGetFaceDataByFaceId(handler: Long, faceId: Int): Long

            @JvmStatic
            private external fun nGetFaceIdsFromFaceMaps(handler: Long): IntArray?

            @JvmStatic
            private external fun nGetFaceMap(handler: Long): HashMap<Int, Long>?

            @JvmStatic
            private external fun nGetModular(handler: Long): String?

            @JvmStatic
            private external fun nPutFaceDataByFaceId(handler: Long, faceId: Int, dataPtr: Long)

            @JvmStatic
            private external fun nRemoveFaceDataByFaceId(handler: Long, faceId: Int)

            @JvmStatic
            private external fun nSetEnable(handler: Long, enable: Boolean)

            @JvmStatic
            private external fun nSetModular(handler: Long, modular: String?)
        }
    }
}
