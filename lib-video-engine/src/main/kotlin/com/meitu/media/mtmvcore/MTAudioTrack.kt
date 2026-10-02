// Source decompiled: com.meitu.media.mtmvcore.MTAudioTrack.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep

/**
 * Track âm thanh độc lập trên Timeline (MTMV Audio Track / BGM / Voiceover).
 * Independent audio track supporting volume fading, pitch shifting and repeat looping.
 */
@Keep
class MTAudioTrack(nativeHandle: Long) : MTIEffectTrack(nativeHandle) {

    companion object {
        @JvmStatic
        fun a(startTimeUs: Long, durationUs: Long, offsetUs: Long, audioPath: String?): MTAudioTrack? {
            if (audioPath.isNullOrEmpty()) return null
            val handle = nativeCreate(audioPath, startTimeUs, durationUs, offsetUs)
            return if (handle != 0L) MTAudioTrack(handle) else null
        }

        @JvmStatic
        fun create(audioPath: String?, startTimeUs: Long = 0L, durationUs: Long = 0L, offsetUs: Long = 0L): MTAudioTrack? {
            return a(startTimeUs, durationUs, offsetUs, audioPath)
        }

        @JvmStatic
        private external fun nativeCreate(audioPath: String, startTimeUs: Long, durationUs: Long, offsetUs: Long): Long
    }

    var audioPath: String? = null
    var inPointUs: Long = 0L
    var outPointUs: Long = 0L
    private var mAudioVolume: Float = 1.0f
    private var mAudioPitch: Float = 1.0f

    private external fun nativeGetFileStartTime(handle: Long): Long
    private external fun nativeSetFileStartTime(handle: Long, startTimeUs: Long)
    private external fun nativeSetRepeat(handle: Long, repeat: Boolean, repeatTimeUs: Long)
    private external fun setAudioTimescaleMode(handle: Long, mode: Int)
    private external fun setMusicFXManager(handle: Long, fxHandle: Long)
    private external fun setSpeedEffectManager(handle: Long, speedHandle: Long): Int

    fun b(repeat: Boolean, repeatTimeUs: Long) {
        if (mNativeContext != 0L) nativeSetRepeat(mNativeContext, repeat, repeatTimeUs)
    }

    fun setRepeat(repeat: Boolean, repeatTimeUs: Long = 0L) = b(repeat, repeatTimeUs)

    fun getFileStartTime(): Long = if (mNativeContext != 0L) nativeGetFileStartTime(mNativeContext) else 0L

    fun setFileStartTime(startTimeUs: Long) {
        if (mNativeContext != 0L) nativeSetFileStartTime(mNativeContext, startTimeUs)
    }

    fun setAudioTimescaleMode(mode: Int) {
        if (mNativeContext != 0L) setAudioTimescaleMode(mNativeContext, mode)
    }

    fun trim(newInPointUs: Long, newOutPointUs: Long) {
        this.inPointUs = newInPointUs
        this.outPointUs = newOutPointUs
        setFileStartTime(newInPointUs)
    }

    fun getTrackVolume(): Float = mAudioVolume

    fun setTrackVolume(vol: Float) {
        this.mAudioVolume = vol.coerceIn(0.0f, 2.0f)
        setVolume(this.mAudioVolume)
    }

    fun getAudioPitch(): Float = mAudioPitch

    fun setAudioPitch(p: Float) {
        this.mAudioPitch = p.coerceIn(0.5f, 2.0f)
    }
}
