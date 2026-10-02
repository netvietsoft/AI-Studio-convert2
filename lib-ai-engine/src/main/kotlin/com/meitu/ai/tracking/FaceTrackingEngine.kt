package com.meitu.ai.tracking

import android.graphics.PointF
import android.graphics.RectF
import androidx.annotation.Keep
import com.meitu.core.nativeengine.MeituNativeEngine
import com.meitu.core.types.FaceData
import kotlin.math.*

/**
 * Engine định vị & bám chuyển động khuôn mặt 3D theo thời gian thực (AR & Face Tracking Engine).
 * Tích hợp trực tiếp thuật toán C++ Native (libmeitu_reborn_native.so)
 * Xác định chính xác 5 điểm neo (Anchor Points): Mắt, Mũi, Cằm, Trán, Khóe miệng.
 * Tích hợp bộ lọc làm mượt chuyển động (EMA Filter) chống rung lắc sticker.
 */
@Keep
class FaceTrackingEngine {

    data class AnchorPoint(
        val x: Float,
        val y: Float,
        val z: Float = 0f,
        val rotationDeg: Float = 0f,
        val scale: Float = 1f,
        val confidence: Float = 1f
    )

    data class TrackingFrame(
        val faceId: Int,
        val isTracking: Boolean,
        val forehead: AnchorPoint,
        val eyeBridge: AnchorPoint,
        val leftEye: AnchorPoint,
        val rightEye: AnchorPoint,
        val noseTip: AnchorPoint,
        val mouth: AnchorPoint,
        val chin: AnchorPoint,
        val mouthOpenRatio: Float,  // 0.0: ngậm miệng, 1.0: há to (trigger animation)
        val eyeBlinkLeft: Float,    // 0.0: mở mắt, 1.0: nhắm mắt
        val eyeBlinkRight: Float
    )

    private var lastTrackingFrame: TrackingFrame? = null
    private val smoothingFactor = 0.35f

    fun trackFace(faceData: FaceData, imageWidth: Int, imageHeight: Int, faceIndex: Int = 0): TrackingFrame? {
        if (faceData.getFaceCount() <= faceIndex) {
            lastTrackingFrame = null
            return null
        }

        val landmarks = faceData.getFaceLandmark(faceIndex, 106, imageWidth, imageHeight)
        if (landmarks == null || landmarks.size < 106) {
            return null
        }

        val roll = faceData.getRollAngle(faceIndex)
        val pitch = faceData.getPitchAngle(faceIndex)
        val yaw = faceData.getYawAngle(faceIndex)

        // 1. ƯU TIÊN 1: Chạy trực tiếp qua C++ Native Engine (libmeitu_reborn_native.so)
        if (MeituNativeEngine.isLoaded()) {
            val lmArray = FloatArray(106 * 2)
            for (i in 0 until min(106, landmarks.size)) {
                lmArray[i * 2] = landmarks[i].x
                lmArray[i * 2 + 1] = landmarks[i].y
            }
            val nativeOut = MeituNativeEngine.nativeTrackFaceAnchors(lmArray, imageWidth, imageHeight, roll, pitch, yaw)
            if (nativeOut != null && nativeOut.size >= 38) {
                val frame = TrackingFrame(
                    faceId = faceIndex,
                    isTracking = true,
                    forehead = AnchorPoint(nativeOut[0], nativeOut[1], nativeOut[2], nativeOut[3], nativeOut[4]),
                    eyeBridge = AnchorPoint(nativeOut[5], nativeOut[6], nativeOut[7], nativeOut[8], nativeOut[9]),
                    leftEye = AnchorPoint(nativeOut[10], nativeOut[11], nativeOut[12], nativeOut[13], nativeOut[14]),
                    rightEye = AnchorPoint(nativeOut[15], nativeOut[16], nativeOut[17], nativeOut[18], nativeOut[19]),
                    noseTip = AnchorPoint(nativeOut[20], nativeOut[21], nativeOut[22], nativeOut[23], nativeOut[24]),
                    mouth = AnchorPoint(nativeOut[25], nativeOut[26], nativeOut[27], nativeOut[28], nativeOut[29]),
                    chin = AnchorPoint(nativeOut[30], nativeOut[31], nativeOut[32], nativeOut[33], nativeOut[34]),
                    mouthOpenRatio = nativeOut[35],
                    eyeBlinkLeft = nativeOut[36],
                    eyeBlinkRight = nativeOut[37]
                )
                lastTrackingFrame = frame
                return frame
            }
        }

        // 2. Dự phòng Fallback: Giải thuật nội bộ nếu C++ chưa nạp
        val eyeLeftInner = landmarks[39]
        val eyeRightInner = landmarks[56]
        val eyeDistance = hypot(eyeRightInner.x - eyeLeftInner.x, eyeRightInner.y - eyeLeftInner.y)
        val eyeCenterX = (eyeLeftInner.x + eyeRightInner.x) * 0.5f
        val eyeCenterY = (eyeLeftInner.y + eyeRightInner.y) * 0.5f

        val radRoll = Math.toRadians(roll.toDouble())
        val upX = -sin(radRoll).toFloat()
        val upY = -cos(radRoll).toFloat()

        val foreheadDistance = eyeDistance * 0.85f
        val rawForehead = AnchorPoint(
            x = eyeCenterX + upX * foreheadDistance,
            y = eyeCenterY + upY * foreheadDistance,
            z = 0.1f,
            rotationDeg = roll,
            scale = eyeDistance / 100.0f
        )

        val rawEyeBridge = AnchorPoint(eyeCenterX, eyeCenterY, 0.3f, roll, eyeDistance / 120.0f)
        val leftEyeCenter = landmarks[38]
        val rightEyeCenter = landmarks[57]
        val rawLeftEye = AnchorPoint(leftEyeCenter.x, leftEyeCenter.y, 0.2f, roll, eyeDistance / 150.0f)
        val rawRightEye = AnchorPoint(rightEyeCenter.x, rightEyeCenter.y, 0.2f, roll, eyeDistance / 150.0f)

        val noseTipPt = landmarks[46]
        val rawNose = AnchorPoint(noseTipPt.x, noseTipPt.y, 0.8f, roll, eyeDistance / 180.0f)

        val upperLip = landmarks[86]
        val lowerLip = landmarks[92]
        val mouthCenterX = (upperLip.x + lowerLip.x) * 0.5f
        val mouthCenterY = (upperLip.y + lowerLip.y) * 0.5f
        val lipGap = hypot(lowerLip.x - upperLip.x, lowerLip.y - upperLip.y)
        val mouthOpenRatio = min(1.0f, max(0.0f, (lipGap / (eyeDistance * 0.28f)) - 0.15f))

        val rawMouth = AnchorPoint(mouthCenterX, mouthCenterY, 0.4f, roll, eyeDistance / 140.0f)
        val chinPt = landmarks[16]
        val rawChin = AnchorPoint(chinPt.x, chinPt.y, 0.0f, roll, eyeDistance / 150.0f)

        val leftEyeTop = landmarks[37]
        val leftEyeBottom = landmarks[41]
        val leftEyeHeight = hypot(leftEyeBottom.x - leftEyeTop.x, leftEyeBottom.y - leftEyeTop.y)
        val leftBlink = if (leftEyeHeight / eyeDistance < 0.06f) 1.0f else 0.0f

        val rightEyeTop = landmarks[58]
        val rightEyeBottom = landmarks[54]
        val rightEyeHeight = hypot(rightEyeBottom.x - rightEyeTop.x, rightEyeBottom.y - rightEyeTop.y)
        val rightBlink = if (rightEyeHeight / eyeDistance < 0.06f) 1.0f else 0.0f

        val currentFrame = TrackingFrame(
            faceId = faceIndex,
            isTracking = true,
            forehead = smoothAnchor(lastTrackingFrame?.forehead, rawForehead),
            eyeBridge = smoothAnchor(lastTrackingFrame?.eyeBridge, rawEyeBridge),
            leftEye = smoothAnchor(lastTrackingFrame?.leftEye, rawLeftEye),
            rightEye = smoothAnchor(lastTrackingFrame?.rightEye, rawRightEye),
            noseTip = smoothAnchor(lastTrackingFrame?.noseTip, rawNose),
            mouth = smoothAnchor(lastTrackingFrame?.mouth, rawMouth),
            chin = smoothAnchor(lastTrackingFrame?.chin, rawChin),
            mouthOpenRatio = mouthOpenRatio,
            eyeBlinkLeft = leftBlink,
            eyeBlinkRight = rightBlink
        )

        lastTrackingFrame = currentFrame
        return currentFrame
    }

    private fun smoothAnchor(prev: AnchorPoint?, current: AnchorPoint): AnchorPoint {
        if (prev == null) return current
        return AnchorPoint(
            x = prev.x + (current.x - prev.x) * smoothingFactor,
            y = prev.y + (current.y - prev.y) * smoothingFactor,
            z = prev.z + (current.z - prev.z) * smoothingFactor,
            rotationDeg = prev.rotationDeg + (current.rotationDeg - prev.rotationDeg) * smoothingFactor,
            scale = prev.scale + (current.scale - prev.scale) * smoothingFactor,
            confidence = current.confidence
        )
    }

    fun reset() {
        lastTrackingFrame = null
    }
}
