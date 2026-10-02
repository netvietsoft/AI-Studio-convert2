// Source decompiled: com.meitu.media.mtmvcore.MTITransition.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

/**
 * Hiệu ứng chuyển cảnh giữa các clip trên Timeline (MTMV Transition).
 * Video transition effect between timeline groups/clips (Dissolve, Wipe, Slide, Zoom, 3D).
 */
@Keep
class MTITransition(handle: Long = 0L, isWeak: Boolean = false) {

    @Keep
    protected var mNativeContext: Long = 0L
    protected var mNativeReleased: Boolean = false
    protected var mReferenceWeak: Boolean = isWeak

    companion object {
        const val kTransitionTimeLineHead = 0
        const val kTransitionTimeLineTail = 1
        const val kTransitionBetweenTrack = 2
        const val kTransitionMixDuration = 0
        const val kTransitionSpeed = 1
        const val kTransitionMixMode = 2
        const val kTransitionTransitionDuration = 3

        init {
            MeituNativeLoader.loadLibraries()
        }

        @JvmStatic
        fun getCPtr(transition: MTITransition?): Long = transition?.mNativeContext ?: 0L

        @JvmStatic
        external fun retainTransition(handle: Long)
    }

    init {
        mNativeReleased = false
        mReferenceWeak = isWeak
        native_setup(handle)
    }

    private external fun native_setup(handle: Long)
    private external fun native_finalize()

    external fun getConfigPath(): String?
    external fun getMemoryUsed(): Long
    external fun getMinTime(): Long
    external fun getMixTime(): Long
    external fun getModelFamily(): String?

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
