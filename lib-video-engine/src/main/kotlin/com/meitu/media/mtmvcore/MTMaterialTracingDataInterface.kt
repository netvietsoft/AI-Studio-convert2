// Source decompiled: com.meitu.media.mtmvcore.MTMaterialTracingDataInterface.java
package com.meitu.media.mtmvcore

import android.util.Log
import androidx.annotation.Keep
import java.io.Serializable

/**
 * Giao diện dữ liệu theo vết vật thể / bám dính chuyển động (Motion & Face Tracking Data).
 * Motion tracking and face detection data wrapper for timeline tracks.
 */
@Keep
open class MTMaterialTracingDataInterface(nativeContext: Long = 0L) : Serializable {

    @Keep
    protected var mNativeContext: Long = nativeContext

    @Keep
    protected var mOriginHashCode: Int = if (nativeContext != 0L) hashCode() else -1

    fun getNativeContext(): Long = mNativeContext

    fun releaseDataInterface() {
        if (mNativeContext != 0L && mOriginHashCode == hashCode()) {
            MTITrack.releaseMaterialTracingDataInterface(mNativeContext)
        }
        mNativeContext = 0L
    }

    companion object {
        private const val serialVersionUID = -3318617790181025690L
    }
}
