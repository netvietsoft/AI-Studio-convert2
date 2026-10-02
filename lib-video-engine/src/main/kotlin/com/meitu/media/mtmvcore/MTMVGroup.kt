// Source decompiled: com.meitu.media.mtmvcore.MTMVGroup.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

/**
 * Nhóm các Track đồng bộ trên Timeline (MTMV Group).
 * Group container coordinating parallel media tracks on the timeline.
 */
@Keep
class MTMVGroup(handle: Long = 0L) {

    @Keep
    protected var mNativeContext: Long = 0L
    protected var mNativeReleased: Boolean = false
    protected var mReferenceWeak: Boolean = false

    companion object {
        init {
            MeituNativeLoader.loadLibraries()
        }

        @JvmStatic
        fun create(startTimeUs: Long = 0L): MTMVGroup? {
            val handle = nativeCreate(startTimeUs)
            return if (handle != 0L) MTMVGroup(handle) else null
        }

        @JvmStatic
        fun getCPtr(group: MTMVGroup?): Long = group?.mNativeContext ?: 0L

        @JvmStatic
        private external fun nativeCreate(startTimeUs: Long): Long

        @JvmStatic
        external fun retainGroup(handle: Long)
    }

    init {
        mNativeReleased = false
        mReferenceWeak = false
        native_setup(handle)
    }

    private external fun native_setup(handle: Long)
    private external fun native_finalize()
    private external fun native_cleanup()
    private external fun addTrack(trackHandle: Long): Boolean
    private external fun getTrack_native(trackId: Long): Long

    external fun changeZOrder(zOrder: Int)

    fun addTrack(track: MTITrack?): Boolean {
        return if (mNativeContext != 0L && track != null) {
            addTrack(MTITrack.getCPtr(track))
        } else {
            false
        }
    }

    fun cleanup() {
        if (mNativeContext != 0L) native_cleanup()
    }

    fun release() {
        if (!mNativeReleased && mNativeContext != 0L && !mReferenceWeak) {
            mNativeReleased = true
            mNativeContext = 0L
            try {
                native_finalize()
            } catch (e: Throwable) {
                // Ignore
            }
        }
    }

    fun getNativeContext(): Long = mNativeContext
}
