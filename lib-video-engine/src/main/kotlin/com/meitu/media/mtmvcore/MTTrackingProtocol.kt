// Source decompiled: com.meitu.media.mtmvcore.MTTrackingProtocol.java
package com.meitu.media.mtmvcore

import androidx.annotation.Keep

/**
 * Giao thức bám vết khuôn mặt và vật thể trên Timeline (Tracking Protocol).
 * Motion tracking and face anchor point protocol for timeline clips.
 */
@Keep
interface MTTrackingProtocol {
    fun copyMaterialDetectData(track: MTITrack?): Boolean
    fun getApplyFaceTracing(): Boolean
    fun getApplyFaceTrackingNeedHidden(): Boolean
    fun getApplyMaterialDataClock(): Long
    fun getApplyMaterialDetectData(): Boolean
    fun getApplyMaterialTrackingNeedHidden(): Boolean
    fun getEnableMaterialDetect(): Boolean
    fun getFaceTracingId(): Long
    fun getFinalPositionX(): Float
    fun getFinalPositionY(): Float
    fun getFinalRotate(): Float
    fun getFinalScaleX(): Float
    fun getFinalScaleY(): Float
    fun getMaterialTracingDataInterface(): MTMaterialTracingDataInterface?
    fun getMaterialTracingDataJson(): String?
    fun getTouchTransScale(): Float
    fun getTrackingDefaultSizeHeight(): Float
    fun getTrackingDefaultSizeWidth(): Float
    fun getUseMouthTranslation(): Boolean
    fun setApplyFaceTracing(enable: Boolean)
    fun setApplyFaceTrackingNeedHidden(enable: Boolean)
    fun setApplyMaterialDetectData(enable: Boolean)
    fun setApplyMaterialTrackingNeedHidden(enable: Boolean)
    fun setEnableMaterialDetect(enable: Boolean)
    fun setFaceTracingId(id: Long)
    fun setFinalPosition(x: Float, y: Float)
    fun setFinalRotate(rotation: Float)
    fun setFinalScale(scaleX: Float, scaleY: Float)
    fun setMTMaterialTracingDataInterface(data: MTMaterialTracingDataInterface?): Boolean
    fun setMaterialInitRect(left: Float, top: Float, right: Float, bottom: Float)
    fun setMaterialTracingDataJsonPath(path: String?)
    fun setOffsetPosition(offset: Long)
    fun setTrackingDefaultSize(width: Float, height: Float)
    fun setUseMouthTranslation(enable: Boolean)
}
