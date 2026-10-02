// Source decompiled: com.meitu.media.mtmvcore.MTITrack.java
package com.meitu.media.mtmvcore

import android.graphics.Bitmap
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader
import java.io.Serializable

/**
 * Lớp cơ sở cho mọi Track đồ họa/âm thanh/hiệu ứng trên MTMV Timeline.
 * Base class for all media, audio, and visual tracks on the MTMV Timeline.
 */
@Keep
open class MTITrack(
    @Keep
    protected var mNativeContext: Long = 0L
) : MTTrackingProtocol {

    protected var mNativeReleased: Boolean = false
    protected var mReferenceWeak: Boolean = false

    companion object {
        const val AUDIO_TIMESCALE_MODE_DEFAULT = 0
        const val AUDIO_TIMESCALE_MODE_SOLA = 1

        const val BIND_TYPE_NONE = 0
        const val BIND_TYPE_NORMAL = 1
        const val BIND_TYPE_SCALE = 2
        const val BIND_TYPE_MIRROR = 3

        const val MT_BACKGROUND_COLOR = 1
        const val MT_BACKGROUND_GAUSS = 2
        const val MT_BACKGROUND_TEXTURE = 3
        const val MT_BACKGROUND_CLARITY = 4

        // 13+ Blend modes
        const val aeBlendNormal = 0
        const val aeBlendDarken = 1
        const val aeBlendMultiply = 2
        const val aeBlendColorBurn = 3
        const val aeBlendLinearBurn = 4
        const val aeBlendDarkerColor = 5
        const val aeBlendAdd = 6
        const val aeBlendLighten = 7
        const val aeBlendScreen = 8
        const val aeBlendColorDodge = 9
        const val aeBlendLinearDodge = 10
        const val aeBlendLighterColor = 11
        const val aeBlendOverlay = 12
        const val aeBlendSoftLight = 13
        const val aeBlendHardLight = 14
        const val aeBlendVividLight = 15
        const val aeBlendLinearLight = 16
        const val aeBlendPinLight = 17
        const val aeBlendHardMix = 18
        const val aeBlendDifference = 19
        const val aeBlendExclusion = 20
        const val aeBlendSubtract = 21
        const val aeBlendDivide = 22

        init {
            MeituNativeLoader.loadLibraries()
        }

        @JvmStatic
        fun getCPtr(track: MTITrack?): Long = track?.mNativeContext ?: 0L

        @JvmStatic
        external fun releaseMaterialTracingDataInterface(handle: Long)
    }

    open class MTBaseKeyframeInfo : Serializable {
        var time: Long = 0L
        var controlX1: Float = 0.0f
        var controlX2: Float = 0.0f
        var controlY1: Float = 0.0f
        var controlY2: Float = 0.0f
        var isLinear: Boolean = true
        var tag: String? = null
    }

    private external fun nativeFinalize(handle: Long)
    private external fun nativeSetVolume(handle: Long, volume: Float)
    private external fun nativeGetVolume(handle: Long): Float
    private external fun nativeSetTrackTime(handle: Long, startTimeUs: Long, durationUs: Long)
    private external fun nativeGetDuration(handle: Long): Long
    private external fun nativeSetSpeed(handle: Long, speed: Double)
    private external fun nativeGetSpeed(handle: Long): Double
    private external fun nativeSetZOrder(handle: Long, zOrder: Int)
    private external fun nativeGetZOrder(handle: Long): Int
    private external fun nativeSetAlpha(handle: Long, alpha: Float)
    private external fun nativeGetAlpha(handle: Long): Float
    private external fun nativeSetRotation(handle: Long, rotation: Float)
    private external fun nativeSetScale(handle: Long, scaleX: Float, scaleY: Float)
    private external fun nativeSetPosition(handle: Long, x: Float, y: Float)
    private external fun nativeSetBlendMode(handle: Long, blendMode: Int)

    fun getNativeContext(): Long = mNativeContext

    open fun setVolume(volume: Float) {
        if (mNativeContext != 0L) nativeSetVolume(mNativeContext, volume)
    }

    fun getVolume(): Float = if (mNativeContext != 0L) nativeGetVolume(mNativeContext) else 1.0f

    fun setTrackTime(startTimeUs: Long, durationUs: Long) {
        if (mNativeContext != 0L) nativeSetTrackTime(mNativeContext, startTimeUs, durationUs)
    }

    fun getDuration(): Long = if (mNativeContext != 0L) nativeGetDuration(mNativeContext) else 0L

    fun setSpeed(speed: Double) {
        if (mNativeContext != 0L) nativeSetSpeed(mNativeContext, speed)
    }

    fun getSpeed(): Double = if (mNativeContext != 0L) nativeGetSpeed(mNativeContext) else 1.0

    fun setZOrder(zOrder: Int) {
        if (mNativeContext != 0L) nativeSetZOrder(mNativeContext, zOrder)
    }

    fun getZOrder(): Int = if (mNativeContext != 0L) nativeGetZOrder(mNativeContext) else 0

    fun setAlpha(alpha: Float) {
        if (mNativeContext != 0L) nativeSetAlpha(mNativeContext, alpha)
    }

    fun getAlpha(): Float = if (mNativeContext != 0L) nativeGetAlpha(mNativeContext) else 1.0f

    fun setRotation(rotation: Float) {
        if (mNativeContext != 0L) nativeSetRotation(mNativeContext, rotation)
    }

    fun setScale(scaleX: Float, scaleY: Float) {
        if (mNativeContext != 0L) nativeSetScale(mNativeContext, scaleX, scaleY)
    }

    fun setPosition(x: Float, y: Float) {
        if (mNativeContext != 0L) nativeSetPosition(mNativeContext, x, y)
    }

    fun setBlendMode(blendMode: Int) {
        if (mNativeContext != 0L) nativeSetBlendMode(mNativeContext, blendMode)
    }

    open fun release() {
        if (!mNativeReleased && mNativeContext != 0L && !mReferenceWeak) {
            val handle = mNativeContext
            mNativeContext = 0L
            mNativeReleased = true
            try {
                nativeFinalize(handle)
            } catch (e: Throwable) {
                // Ignore
            }
        }
    }

    // MTTrackingProtocol stub implementations
    override fun copyMaterialDetectData(track: MTITrack?): Boolean = false
    override fun getApplyFaceTracing(): Boolean = false
    override fun getApplyFaceTrackingNeedHidden(): Boolean = false
    override fun getApplyMaterialDataClock(): Long = 0L
    override fun getApplyMaterialDetectData(): Boolean = false
    override fun getApplyMaterialTrackingNeedHidden(): Boolean = false
    override fun getEnableMaterialDetect(): Boolean = false
    override fun getFaceTracingId(): Long = 0L
    override fun getFinalPositionX(): Float = 0.0f
    override fun getFinalPositionY(): Float = 0.0f
    override fun getFinalRotate(): Float = 0.0f
    override fun getFinalScaleX(): Float = 1.0f
    override fun getFinalScaleY(): Float = 1.0f
    override fun getMaterialTracingDataInterface(): MTMaterialTracingDataInterface? = null
    override fun getMaterialTracingDataJson(): String? = null
    override fun getTouchTransScale(): Float = 1.0f
    override fun getTrackingDefaultSizeHeight(): Float = 0.0f
    override fun getTrackingDefaultSizeWidth(): Float = 0.0f
    override fun getUseMouthTranslation(): Boolean = false
    override fun setApplyFaceTracing(enable: Boolean) {}
    override fun setApplyFaceTrackingNeedHidden(enable: Boolean) {}
    override fun setApplyMaterialDetectData(enable: Boolean) {}
    override fun setApplyMaterialTrackingNeedHidden(enable: Boolean) {}
    override fun setEnableMaterialDetect(enable: Boolean) {}
    override fun setFaceTracingId(id: Long) {}
    override fun setFinalPosition(x: Float, y: Float) {}
    override fun setFinalRotate(rotation: Float) {}
    override fun setFinalScale(scaleX: Float, scaleY: Float) {}
    override fun setMTMaterialTracingDataInterface(data: MTMaterialTracingDataInterface?): Boolean = false
    override fun setMaterialInitRect(left: Float, top: Float, right: Float, bottom: Float) {}
    override fun setMaterialTracingDataJsonPath(path: String?) {}
    override fun setOffsetPosition(offset: Long) {}
    override fun setTrackingDefaultSize(width: Float, height: Float) {}
    override fun setUseMouthTranslation(enable: Boolean) {}
}
