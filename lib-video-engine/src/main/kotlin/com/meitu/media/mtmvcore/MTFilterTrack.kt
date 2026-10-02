// Source decompiled: com.meitu.media.mtmvcore.MTFilterTrack.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep
import java.io.Serializable

/**
 * Track bộ lọc màu GPU / 3D LUT shader trên Timeline (MTMV Filter Track).
 * GPU color grading, 3D LUT and shader effect track on the timeline.
 */
@Keep
class MTFilterTrack(nativeHandle: Long) : MTIEffectTrack(nativeHandle) {

    companion object {
        const val AUTOFILL = 1
        const val AUTOADAPTATION = 2

        @JvmStatic
        fun createWithFilename(filterPath: String?, configPath: String?, startTimeUs: Long = 0L, durationUs: Long = 0L): MTFilterTrack? {
            val handle = nativeCreateWithFilename(filterPath, configPath, startTimeUs, durationUs)
            return if (handle != 0L) MTFilterTrack(handle) else null
        }

        @JvmStatic
        fun createWithByteArray(filterData: String?, configData: String?, startTimeUs: Long = 0L, durationUs: Long = 0L): MTFilterTrack? {
            val handle = nativeCreateWithByteArray(filterData, configData, startTimeUs, durationUs)
            return if (handle != 0L) MTFilterTrack(handle) else null
        }

        @JvmStatic
        fun createWithShaderId(shaderId: Int, startTimeUs: Long = 0L, durationUs: Long = 0L): MTFilterTrack? {
            val handle = nativeCreateWithShaderId(shaderId, startTimeUs, durationUs)
            return if (handle != 0L) MTFilterTrack(handle) else null
        }

        @JvmStatic
        private external fun nativeCreateWithFilename(filterPath: String?, configPath: String?, startTimeUs: Long, durationUs: Long): Long

        @JvmStatic
        private external fun nativeCreateWithByteArray(filterData: String?, configData: String?, startTimeUs: Long, durationUs: Long): Long

        @JvmStatic
        private external fun nativeCreateWithShaderId(shaderId: Int, startTimeUs: Long, durationUs: Long): Long
    }

    var filterPath: String? = null
    private var mIntensity: Float = 1.0f

    fun getFilterIntensity(): Float = mIntensity

    fun setFilterIntensity(value: Float) {
        this.mIntensity = value.coerceIn(0.0f, 1.0f)
    }

    open class MTFilterTrackKeyframeInfo : MTITrack.MTBaseKeyframeInfo(), Serializable {
        var uniforms: Map<String, Float>? = null

        companion object {
            @JvmStatic
            fun create(
                time: Long,
                cx1: Float, cy1: Float,
                cx2: Float, cy2: Float,
                isLinear: Boolean,
                tag: String?,
                uniforms: Map<String, Float>?
            ): MTFilterTrackKeyframeInfo {
                val info = MTFilterTrackKeyframeInfo()
                info.time = time
                info.tag = tag
                info.controlX1 = cx1
                info.controlY1 = cy1
                info.controlX2 = cx2
                info.controlY2 = cy2
                info.isLinear = isLinear
                info.uniforms = uniforms
                return info
            }
        }
    }

    private external fun addFilterKeyframeWithInfo(handle: Long, info: MTFilterTrackKeyframeInfo?): Boolean

    fun addKeyframe(info: MTFilterTrackKeyframeInfo?): Boolean {
        return if (mNativeContext != 0L && info != null) {
            addFilterKeyframeWithInfo(mNativeContext, info)
        } else {
            false
        }
    }
}
