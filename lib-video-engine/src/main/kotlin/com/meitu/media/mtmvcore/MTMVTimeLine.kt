// Source decompiled: com.meitu.media.mtmvcore.MTMVTimeLine.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader

/**
 * Trình quản trị Timeline đa tầng video (MTMV Video Timeline Engine).
 * Multi-track video timeline controller managing video clips, audio tracks, BGM, and transitions.
 */
@Keep
class MTMVTimeLine @JvmOverloads constructor(nativeHandle: Long = 0L, ownMemory: Boolean = true) {

    @Keep
    private var mNativeContext: Long = 0L
    protected var mNativeReleased: Boolean = false
    protected var swigCMemOwn: Boolean = ownMemory

    companion object {
        const val MTMV_VOLUME_OF_VIDEO_ORIGINAL_SOUND = 0
        const val MTMV_VOLUME_OF_BACKGROUND_MUSIC = 1
        const val MTMV_VOLUME_VFX_MUSIC = 2
        const val kMainTrackDuration = 0
        const val kAllTrackDuration = 1

        init {
            MeituNativeLoader.loadLibraries()
        }
    }

    init {
        mNativeReleased = false
        swigCMemOwn = ownMemory
        native_setup(nativeHandle)
    }

    private external fun native_setup(handle: Long)
    private external fun native_finalize()
    private external fun native_cleanup()
    private external fun nativeGetVolume(): Float
    private external fun nativeSetVolume(volume: Float)
    private external fun nativeGetBgm(): Long
    private external fun setBgm(trackHandle: Long)
    private external fun addMixTrack(trackHandle: Long)
    private external fun removeMixTrack(trackHandle: Long)
    private external fun pushBackGroup(groupHandle: Long)
    private external fun pushFrontGroup(groupHandle: Long)
    private external fun removeGroup(groupHandle: Long): Boolean
    private external fun changeGroupPosition(groupHandle1: Long, groupHandle2: Long): Boolean
    private external fun insertGroupBefore(groupHandle1: Long, groupHandle2: Long): Boolean
    private external fun runTransition(groupHandle: Long, position: Int, transitionHandle: Long): Boolean
    private external fun removeTransition(groupHandle: Long, position: Int): Boolean
    private external fun updateTransition(groupHandle: Long, position: Int, mode: Int, speed: Float): Boolean
    private external fun getTransitionWithGroup(groupHandle: Long): Long

    external fun clearTransition()
    external fun getDuration(): Long
    external fun getMainTrackDuration(): Long
    external fun getGroupNum(): Int
    external fun getGroups(): Array<MTMVGroup>?
    external fun removeAllGroups()
    external fun setAudioFadeIn(durationMs: Int)
    external fun setAudioFadeOut(durationMs: Int)
    external fun setBackgroundColor(r: Int, g: Int, b: Int)
    external fun setBackgroundType(type: Int, param: Float): Boolean
    external fun setEnableTransparentBackground(enable: Boolean)
    external fun setSaveSection(startUs: Long, endUs: Long)
    external fun setTimeLineType(type: Int)
    external fun sortGroups(order: IntArray?): Boolean
    external fun invalidate()

    fun getNativeTimeLine(): Long {
        val h = mNativeContext
        if (h != 0L) return h
        throw RuntimeException("MTMVTimeLine has been released or native setup failure")
    }

    fun getVolume(): Float = nativeGetVolume()

    fun setVolume(volume: Float) {
        nativeSetVolume(volume)
    }

    fun getBgm(): MTITrack? {
        val bgmHandle = nativeGetBgm()
        return if (bgmHandle != 0L) MTITrack(bgmHandle) else null
    }

    fun setBgm(track: MTMVTrack?) {
        setBgm(MTITrack.getCPtr(track))
    }

    fun addMixTrack(track: MTITrack?) {
        if (track != null) addMixTrack(MTITrack.getCPtr(track))
    }

    fun removeMixTrack(track: MTITrack?) {
        if (track != null) removeMixTrack(MTITrack.getCPtr(track))
    }

    fun pushBackGroup(group: MTMVGroup?) {
        if (group != null) pushBackGroup(MTMVGroup.getCPtr(group))
    }

    fun pushFrontGroup(group: MTMVGroup?) {
        if (group != null) pushFrontGroup(MTMVGroup.getCPtr(group))
    }

    fun removeGroup(group: MTMVGroup?): Boolean {
        return if (group != null) removeGroup(MTMVGroup.getCPtr(group)) else false
    }

    fun changeGroupPosition(g1: MTMVGroup?, g2: MTMVGroup?): Boolean {
        return if (g1 != null && g2 != null) changeGroupPosition(MTMVGroup.getCPtr(g1), MTMVGroup.getCPtr(g2)) else false
    }

    fun insertGroupBefore(g1: MTMVGroup?, g2: MTMVGroup?): Boolean {
        return if (g1 != null && g2 != null) insertGroupBefore(MTMVGroup.getCPtr(g1), MTMVGroup.getCPtr(g2)) else false
    }

    fun runTransition(group: MTMVGroup?, position: Int, transition: MTITransition?): Boolean {
        return if (group != null && transition != null) {
            runTransition(MTMVGroup.getCPtr(group), position, MTITransition.getCPtr(transition))
        } else {
            false
        }
    }

    fun removeTransition(group: MTMVGroup?, position: Int): Boolean {
        return if (group != null) removeTransition(MTMVGroup.getCPtr(group), position) else false
    }

    fun updateTransition(group: MTMVGroup?, position: Int, mode: Int, speed: Float): Boolean {
        return if (group != null) updateTransition(MTMVGroup.getCPtr(group), position, mode, speed) else false
    }

    fun cleanup() {
        native_cleanup()
    }

    @Synchronized
    fun release() {
        if (swigCMemOwn) {
            swigCMemOwn = false
            if (!mNativeReleased && mNativeContext != 0L) {
                native_finalize()
            }
        }
        mNativeReleased = true
        mNativeContext = 0L
    }

    fun isNativeReleased(): Boolean = mNativeReleased
}
