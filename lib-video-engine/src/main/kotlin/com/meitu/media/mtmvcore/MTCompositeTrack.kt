// Source decompiled: com.meitu.media.mtmvcore.MTCompositeTrack.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep

/**
 * Track ghép lớp đa tầng đồ họa (Composite Multi-Layer Track).
 * Multi-layer compositor track grouping several visual tracks inside one composite canvas.
 */
@Keep
class MTCompositeTrack(nativeHandle: Long) : MTIMediaTrack(nativeHandle) {

    companion object {
        @JvmStatic
        fun create(startTimeUs: Long = 0L, durationUs: Long = 0L): MTCompositeTrack? {
            val handle = createCompositeTrack(startTimeUs, durationUs)
            return if (handle != 0L) MTCompositeTrack(handle) else null
        }

        @JvmStatic
        private external fun createCompositeTrack(startTimeUs: Long, durationUs: Long): Long
    }

    private external fun addTrack(handle: Long, trackHandle: Long): Boolean
    private external fun applyBackEffectInsideCompositeBuffer(handle: Long, enable: Boolean)
    private external fun bindToMedia(handle: Long, trackHandle: Long, effectHandle: Long, mode: Int): Boolean
    private external fun clearAllTrack(handle: Long)
    private external fun getBoundingPointsSizeOffsetX(handle: Long): Float
    private external fun getBoundingPointsSizeOffsetY(handle: Long): Float
    private external fun getEnableRenderBufferLimit(handle: Long): Boolean
    private external fun getTrack(handle: Long, trackId: Long): MTITrack?
    private external fun getTracks(handle: Long): Array<MTITrack>?
    private external fun removeTrackById(handle: Long, trackId: Long): Boolean
    private external fun removeTrackByNativePtr(handle: Long, trackHandle: Long): Boolean
    private external fun setClearColor(handle: Long, color: Int)
    private external fun setEnableRenderBufferLimit(handle: Long, enable: Boolean)

    fun addTrack(track: MTITrack?): Boolean {
        return if (mNativeContext != 0L && track != null) {
            addTrack(mNativeContext, MTITrack.getCPtr(track))
        } else {
            false
        }
    }

    fun applyBackEffectInsideCompositeBuffer(enable: Boolean) {
        if (mNativeContext != 0L) applyBackEffectInsideCompositeBuffer(mNativeContext, enable)
    }

    fun bindToMedia(mediaTrack: MTITrack?, effectTrack: MTIEffectTrack?, mode: Int): Boolean {
        return if (mNativeContext != 0L && mediaTrack != null && effectTrack != null) {
            bindToMedia(mNativeContext, MTITrack.getCPtr(mediaTrack), MTITrack.getCPtr(effectTrack), mode)
        } else {
            false
        }
    }

    fun clearAllTracks() {
        if (mNativeContext != 0L) clearAllTrack(mNativeContext)
    }

    fun setClearColor(color: Int) {
        if (mNativeContext != 0L) setClearColor(mNativeContext, color)
    }
}
