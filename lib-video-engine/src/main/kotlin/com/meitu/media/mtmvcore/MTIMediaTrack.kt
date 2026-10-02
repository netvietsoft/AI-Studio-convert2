// Source decompiled: com.meitu.media.mtmvcore.MTIMediaTrack.java
package com.meitu.media.mtmvcore

import android.graphics.PointF
import android.graphics.RectF
import androidx.annotation.Keep

/**
 * Lớp cơ sở cho các Track đa phương tiện (Video, Image, Subtitle).
 * Base class for visual media tracks with transformation, deformation, and layout.
 */
@Keep
open class MTIMediaTrack(nativeHandle: Long) : MTITrack(nativeHandle) {

    companion object {
        const val kAllEffectDisabled = 1
        const val kAutoCompressMedia = 1
        const val kAvoidWarpIfNecessary = 2
        const val kEffectNone = 0
        const val kMTClrEnhanceNone = 0
        const val kMTClrEnhance9X64Mode = 1
        const val kMTMediaDeformationHorizontal = 0
        const val kMTMediaDeformationVertical = 1
        const val kMTMediaDeformationCenter = 2
    }

    external fun calculateDeformationExtremePoints(f: Float, f2: Float): FloatArray?
    external fun calculateDeformationFitMove(): PointF?
    external fun calculateDeformationFitScale(): Float
    external fun checkPointInDeformationMedia(f: Float, f2: Float): Boolean
    external fun enableDeformation(enable: Boolean)
    external fun enableRealScissor(enable: Boolean)
    external fun getDeformationAnchor(): PointF?
    external fun getDeformationMediaBounding(): Array<PointF>?
    external fun getDeformationMediaCenter(): PointF?
    external fun getDeformationPosition(): PointF?
    external fun getDeformationRotation(): Float
    external fun getDeformationScale(): Float
    external fun getDeformationScissorBox(): RectF?
    external fun getDeformationShapeValue(shapeIndex: Int): Float
}
