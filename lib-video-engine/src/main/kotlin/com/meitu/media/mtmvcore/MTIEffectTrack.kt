// Source decompiled: com.meitu.media.mtmvcore.MTIEffectTrack.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep

/**
 * Lớp cơ sở cho các Track hiệu ứng video, bộ lọc màu, âm thanh.
 * Base class for effect tracks, filters, and audio processors.
 */
@Keep
open class MTIEffectTrack(nativeHandle: Long) : MTITrack(nativeHandle) {

    companion object {
        const val LabelActionMid = 0
        const val LabelActionIn = 1
        const val LabelActionOut = 2
        const val LabelActionAll = 3

        const val MT_APPLYKEYFRAMEMODE_NONE = 0
        const val MT_APPLYKEYFRAMEMODE_SELFTRACK = 1
        const val MT_APPLYKEYFRAMEMODE_BINDTRACK = 2

        const val TextHAlignmentLeft = 0
        const val TextHAlignmentCenter = 1
        const val TextHAlignmentRight = 2

        const val TimeTypeABS = 0
        const val TimeTypeREL = 1
    }

    private external fun getKeyframeBindTrackMode(handle: Long): Int
    private external fun nativeApplyEffectXComposite(handle: Long, enable: Boolean)
    private external fun nativeBind(handle: Long, targetHandle: Long, mode: Int): Boolean
    private external fun nativeBindDetect(handle: Long, detectHandle: Long): Boolean
    private external fun nativeBindDynamic(handle: Long): Boolean
    private external fun nativeBindDynamic(handle: Long, targetHandle: Long): Boolean
    private external fun nativeSetEffectFlags(handle: Long, flags: Int)
    private external fun nativeUnbind(handle: Long): Boolean
    private external fun nativeUnbindDetect(handle: Long): Boolean
    private external fun setKeyframeBindTrackMode(handle: Long, mode: Int)

    fun applyEffectXComposite(enable: Boolean) {
        if (mNativeContext != 0L) nativeApplyEffectXComposite(mNativeContext, enable)
    }

    fun bind(targetTrack: MTITrack?, mode: Int = 0): Boolean {
        return if (mNativeContext != 0L && targetTrack != null) {
            nativeBind(mNativeContext, getCPtr(targetTrack), mode)
        } else {
            false
        }
    }

    fun unbind(): Boolean {
        return if (mNativeContext != 0L) nativeUnbind(mNativeContext) else false
    }

    fun setEffectFlags(flags: Int) {
        if (mNativeContext != 0L) nativeSetEffectFlags(mNativeContext, flags)
    }
}
