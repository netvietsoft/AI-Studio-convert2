// Source decompiled: com.meitu.media.mtmvcore.MTMVTrack.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep

/**
 * Track video/ảnh chính trên Timeline (MTMV Video Track).
 * Primary video/image timeline track with hardware decoding and audio pitch-correction.
 */
@Keep
class MTMVTrack(nativeHandle: Long) : MTIMediaTrack(nativeHandle) {

    companion object {
        const val kMTVideoStabilizationNone = 0
        const val kMTVideoStabilizationLow = 1
        const val kMTVideoStabilizationMedium = 2
        const val kMTVideoStabilizationHigh = 3

        @JvmStatic
        fun create(sourcePath: String?, startTimeUs: Long = 0L, durationUs: Long = 0L, offsetUs: Long = 0L): MTMVTrack? {
            if (sourcePath.isNullOrEmpty()) return null
            val handle = createVideoTrack(sourcePath, startTimeUs, durationUs, offsetUs)
            return if (handle != 0L) MTMVTrack(handle) else null
        }

        @JvmStatic
        fun createAsync(sourcePath: String?, startTimeUs: Long = 0L, durationUs: Long = 0L, offsetUs: Long = 0L): MTMVTrack? {
            if (sourcePath.isNullOrEmpty()) return null
            val handle = createVideoTrackAsync(sourcePath, startTimeUs, durationUs, offsetUs)
            return if (handle != 0L) MTMVTrack(handle) else null
        }

        @JvmStatic
        private external fun createVideoTrack(source: String, startTimeUs: Long, durationUs: Long, offsetUs: Long): Long

        @JvmStatic
        private external fun createVideoTrackAsync(source: String, startTimeUs: Long, durationUs: Long, offsetUs: Long): Long
    }

    var sourcePath: String? = null
    var inPointUs: Long = 0L
    var outPointUs: Long = 0L
    private var mSpeed: Float = 1.0f
    private var mTrackVolume: Float = 1.0f

    private external fun getFileDuration(handle: Long): Long
    private external fun getFileStartTime(handle: Long): Long
    private external fun getFramePts(handle: Long): Long
    private external fun setAudioTimescaleMode(handle: Long, mode: Int)
    private external fun setAudioTrack(handle: Long, audioPath: String?)
    private external fun setFileStartTime(handle: Long, startTimeUs: Long)
    private external fun setMusicFXManager(handle: Long, fxHandle: Long)
    private external fun setSpeedEffectManager(handle: Long, speedHandle: Long): Int
    private external fun setStabilizationMode(handle: Long, mode: Int, strength: Int)

    fun getFileDuration(): Long = if (mNativeContext != 0L) getFileDuration(mNativeContext) else 0L

    fun getFileStartTime(): Long = if (mNativeContext != 0L) getFileStartTime(mNativeContext) else 0L

    fun getFramePts(): Long = if (mNativeContext != 0L) getFramePts(mNativeContext) else 0L

    fun setAudioTimescaleMode(mode: Int) {
        if (mNativeContext != 0L) setAudioTimescaleMode(mNativeContext, mode)
    }

    fun setAudioTrack(audioPath: String?) {
        if (mNativeContext != 0L) setAudioTrack(mNativeContext, audioPath)
    }

    fun setFileStartTime(startTimeUs: Long) {
        if (mNativeContext != 0L) setFileStartTime(mNativeContext, startTimeUs)
    }

    fun setStabilizationMode(mode: Int, strength: Int = 1) {
        if (mNativeContext != 0L) setStabilizationMode(mNativeContext, mode, strength)
    }

    fun trim(newInPointUs: Long, newOutPointUs: Long) {
        this.inPointUs = newInPointUs
        this.outPointUs = newOutPointUs
        setFileStartTime(newInPointUs)
    }

    fun getPlaybackSpeed(): Float = mSpeed

    fun setPlaybackSpeed(speedMultiplier: Float) {
        this.mSpeed = speedMultiplier.coerceIn(0.1f, 100.0f)
        setSpeed(this.mSpeed.toDouble())
    }

    fun getTrackVolume(): Float = mTrackVolume

    fun setTrackVolume(vol: Float) {
        this.mTrackVolume = vol.coerceIn(0.0f, 2.0f)
        setVolume(this.mTrackVolume)
    }

    fun split(splitPointUs: Long): Pair<MTMVTrack, MTMVTrack>? {
        val path = sourcePath ?: return null
        if (splitPointUs <= inPointUs || (outPointUs > 0 && splitPointUs >= outPointUs)) return null
        val left = create(path, inPointUs, splitPointUs - inPointUs, 0L) ?: return null
        left.sourcePath = path
        left.inPointUs = inPointUs
        left.outPointUs = splitPointUs

        val rightDuration = if (outPointUs > 0) outPointUs - splitPointUs else 0L
        val right = create(path, splitPointUs, rightDuration, 0L) ?: return null
        right.sourcePath = path
        right.inPointUs = splitPointUs
        right.outPointUs = outPointUs

        return Pair(left, right)
    }
}
