package com.meitu.core.types

import android.graphics.PointF
import android.graphics.Rect
import android.graphics.RectF
import androidx.annotation.Keep
import com.meitu.core.MteApplication
import java.util.ArrayList

/**
 * Cấu trúc dữ liệu khuôn mặt và điểm mốc Landmark chuẩn C++ Native của Meitu.
 * Nguồn: com.meitu.core.types.FaceData.java
 * Kết nối trực tiếp với libbmpKit.so và libaidetectionplugin.so.
 */
@Keep
class FaceData {

    @get:JvmName("getNativeInstance")
    val nativeInstance: Long

    enum class MTGender(val id: Int) {
        UNDEFINE_GENDER(-1),
        FEMALE(0),
        MALE(1);

        override fun toString(): String {
            return when (id) {
                -1 -> "UNDEFINE_GENDER"
                0 -> "FEMALE"
                1 -> "MALE"
                else -> super.toString()
            }
        }
    }

    enum class MTRace(val id: Int) {
        UNDEFINE_SKIN_RACE(-1),
        BLACK_SKIN_RACE(0),
        WHITE_SKIN_RACE(1),
        YELLOW_SKIN_RACE(2);

        override fun toString(): String {
            return when (id) {
                -1 -> "UNDEFINE_SKIN_RACE"
                0 -> "BLACK_SKIN_RACE"
                1 -> "WHITE_SKIN_RACE"
                2 -> "YELLOW_SKIN_RACE"
                else -> super.toString()
            }
        }
    }

    companion object {
        const val LANDMARK_TYPE_39 = 0
        const val LANDMARK_TYPE_83 = 1
        const val LANDMARK_TYPE_2D = 2
        const val LANDMARK_TYPE_3D = 3

        init {
            MteApplication.loadLibrary()
        }

        @JvmStatic
        fun getFaceDataStructureVersion(): String {
            return try {
                "3.1.0-" + nativeGetFaceDataLength()
            } catch (e: UnsatisfiedLinkError) {
                "3.1.0-compat"
            }
        }

        @JvmStatic
        private external fun finalizer(j: Long)

        @JvmStatic
        private external fun nativeClear(j: Long)

        @JvmStatic
        private external fun nativeCopy(j: Long, j2: Long): Boolean

        @JvmStatic
        private external fun nativeCopyFaceDataFromByte(j: Long, bArr: ByteArray): Boolean

        @JvmStatic
        private external fun nativeCopyFaceDataToByte(j: Long): ByteArray?

        @JvmStatic
        private external fun nativeCopyWithFaceIndex(j: Long, iArr: IntArray, j2: Long): Boolean

        @JvmStatic
        private external fun nativeCreate(): Long

        @JvmStatic
        private external fun nativeGetAge(j: Long, i: Int): Int

        @JvmStatic
        private external fun nativeGetAvgBrightness(j: Long): Int

        @JvmStatic
        private external fun nativeGetClusterID(j: Long, i: Int): Int

        @JvmStatic
        private external fun nativeGetDetectHeight(j: Long): Int

        @JvmStatic
        private external fun nativeGetDetectWidth(j: Long): Int

        @JvmStatic
        private external fun nativeGetFaceCode(j: Long, i: Int): FloatArray?

        @JvmStatic
        private external fun nativeGetFaceCount(j: Long): Int

        @JvmStatic
        private external fun nativeGetFaceDataLength(): Int

        @JvmStatic
        private external fun nativeGetFaceID(j: Long, i: Int): Int

        @JvmStatic
        private external fun nativeGetFaceRect(j: Long, i: Int): FloatArray?

        @JvmStatic
        private external fun nativeGetGender(j: Long, i: Int): Int

        @JvmStatic
        private external fun nativeGetLandmark(j: Long, landmarkType: Int, faceIndex: Int): FloatArray?

        @JvmStatic
        private external fun nativeGetPitchAngle(j: Long, i: Int): Float

        @JvmStatic
        private external fun nativeGetRace(j: Long, i: Int): Int

        @JvmStatic
        private external fun nativeGetRollAngle(j: Long, i: Int): Float

        @JvmStatic
        private external fun nativeGetYawAngle(j: Long, i: Int): Float

        @JvmStatic
        private external fun nativeSetAge(j: Long, faceIdx: Int, age: Int)

        @JvmStatic
        private external fun nativeSetClusterID(j: Long, faceIdx: Int, clusterId: Int)

        @JvmStatic
        private external fun nativeSetDetectHeight(j: Long, h: Int)

        @JvmStatic
        private external fun nativeSetDetectWidth(j: Long, w: Int)

        @JvmStatic
        private external fun nativeSetFaceCode(j: Long, faceIdx: Int, code: FloatArray): Boolean

        @JvmStatic
        private external fun nativeSetFaceRect(j: Long, faceIdx: Int, rect: FloatArray)

        @JvmStatic
        private external fun nativeSetGender(j: Long, faceIdx: Int, gender: Int)

        @JvmStatic
        private external fun nativeSetLandmark(j: Long, landmarkType: Int, faceIdx: Int, landmarks: FloatArray): Boolean

        @JvmStatic
        private external fun nativeSetRace(j: Long, faceIdx: Int, race: Int)

        @JvmStatic
        private external fun nativeSetRollAngle(j: Long, faceIdx: Int, roll: Float)
    }

    constructor() {
        this.nativeInstance = try {
            nativeCreate()
        } catch (e: UnsatisfiedLinkError) {
            0L
        }
    }

    constructor(faceData: FaceData?) : this() {
        if (faceData != null && this.nativeInstance != 0L && faceData.nativeInstance != 0L) {
            try {
                nativeCopy(faceData.nativeInstance, this.nativeInstance)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    constructor(faceData: FaceData?, iArr: IntArray) : this() {
        if (faceData != null && this.nativeInstance != 0L && faceData.nativeInstance != 0L) {
            try {
                nativeCopyWithFaceIndex(faceData.nativeInstance, iArr, this.nativeInstance)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun nativeInstance(): Long = this.nativeInstance

    fun clear() {
        if (nativeInstance != 0L) {
            try {
                nativeClear(nativeInstance)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun copy(): FaceData = FaceData(this)

    fun copy(iArr: IntArray): FaceData = FaceData(this, iArr)

    fun copyFaceDataFromByte(bArr: ByteArray): Boolean {
        return if (nativeInstance != 0L) {
            try {
                nativeCopyFaceDataFromByte(nativeInstance, bArr)
            } catch (e: UnsatisfiedLinkError) {
                false
            }
        } else false
    }

    fun copyFaceDataToByte(): ByteArray? {
        return if (nativeInstance != 0L) {
            try {
                nativeCopyFaceDataToByte(nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                null
            }
        } else null
    }

    fun copyTo(faceData: FaceData): Boolean {
        return if (nativeInstance != 0L && faceData.nativeInstance != 0L) {
            try {
                nativeCopy(nativeInstance, faceData.nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                false
            }
        } else false
    }

    fun getAge(i: Int): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetAge(nativeInstance, i)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getAvgBright(): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetAvgBrightness(nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getClusterID(i: Int): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetClusterID(nativeInstance, i)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getDetectHeight(): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetDetectHeight(nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getDetectWidth(): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetDetectWidth(nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getFaceCode(i: Int): FloatArray? {
        return if (nativeInstance != 0L) {
            try {
                nativeGetFaceCode(nativeInstance, i)
            } catch (e: UnsatisfiedLinkError) {
                null
            }
        } else null
    }

    fun getFaceCount(): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetFaceCount(nativeInstance)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getFaceID(i: Int): Int {
        return if (nativeInstance != 0L) {
            try {
                nativeGetFaceID(nativeInstance, i)
            } catch (e: UnsatisfiedLinkError) {
                0
            }
        } else 0
    }

    fun getFaceLandmark(faceIdx: Int, landmarkType: Int, width: Int, height: Int): ArrayList<PointF>? {
        if (nativeInstance == 0L) return null
        val raw = try {
            nativeGetLandmark(nativeInstance, landmarkType, faceIdx)
        } catch (e: UnsatisfiedLinkError) {
            null
        }
        if (raw == null || raw.isEmpty()) return null

        val list = ArrayList<PointF>(raw.size / 2)
        for (i in 0 until raw.size / 2) {
            val i2 = i * 2
            list.add(PointF(raw[i2] * width, raw[i2 + 1] * height))
        }
        return list
    }

    fun getFaceLandmark(faceIdx: Int, landmarkType: Int): ArrayList<PointF>? {
        return getFaceLandmark(faceIdx, landmarkType, getDetectWidth(), getDetectHeight())
    }

    fun getFaceLandmarkRatio(faceIdx: Int, landmarkType: Int): ArrayList<PointF>? {
        if (nativeInstance == 0L) return null
        val raw = try {
            nativeGetLandmark(nativeInstance, landmarkType, faceIdx)
        } catch (e: UnsatisfiedLinkError) {
            null
        }
        if (raw == null || raw.isEmpty()) return null

        val list = ArrayList<PointF>(raw.size / 2)
        for (i in 0 until raw.size / 2) {
            val i2 = i * 2
            list.add(PointF(raw[i2], raw[i2 + 1]))
        }
        return list
    }

    fun getFaceRect(faceIdx: Int, width: Int, height: Int): Rect? {
        if (nativeInstance == 0L) return null
        val raw = try {
            nativeGetFaceRect(nativeInstance, faceIdx)
        } catch (e: UnsatisfiedLinkError) {
            null
        }
        if (raw == null || raw.size != 4) return null
        return Rect(
            (raw[0] * width).toInt(),
            (raw[1] * height).toInt(),
            (raw[2] * width).toInt(),
            (raw[3] * height).toInt()
        )
    }

    fun getFaceRect(faceIdx: Int): Rect? = getFaceRect(faceIdx, getDetectWidth(), getDetectHeight())

    fun getFaceRectList(): ArrayList<Rect>? {
        val count = getFaceCount()
        if (count <= 0) return null
        val list = ArrayList<Rect>(count)
        for (i in 0 until count) {
            getFaceRect(i)?.let { list.add(it) }
        }
        return list
    }

    fun getGender(faceIdx: Int): MTGender {
        val gender = if (nativeInstance != 0L) {
            try {
                nativeGetGender(nativeInstance, faceIdx)
            } catch (e: UnsatisfiedLinkError) {
                -1
            }
        } else -1
        return when (gender) {
            0 -> MTGender.FEMALE
            1 -> MTGender.MALE
            else -> MTGender.UNDEFINE_GENDER
        }
    }

    fun getNormalizedFaceRect(faceIdx: Int): RectF? {
        if (nativeInstance == 0L) return null
        val raw = try {
            nativeGetFaceRect(nativeInstance, faceIdx)
        } catch (e: UnsatisfiedLinkError) {
            null
        }
        if (raw == null || raw.size != 4) return null
        return RectF(raw[0], raw[1], raw[2], raw[3])
    }

    fun getPitchAngle(faceIdx: Int): Float {
        return if (nativeInstance != 0L) {
            try {
                nativeGetPitchAngle(nativeInstance, faceIdx)
            } catch (e: UnsatisfiedLinkError) {
                0f
            }
        } else 0f
    }

    fun getRace(faceIdx: Int): MTRace {
        val r = if (nativeInstance != 0L) {
            try {
                nativeGetRace(nativeInstance, faceIdx)
            } catch (e: UnsatisfiedLinkError) {
                -1
            }
        } else -1
        return when (r) {
            0 -> MTRace.BLACK_SKIN_RACE
            1 -> MTRace.WHITE_SKIN_RACE
            2 -> MTRace.YELLOW_SKIN_RACE
            else -> MTRace.UNDEFINE_SKIN_RACE
        }
    }

    fun getRollAngle(faceIdx: Int): Float {
        return if (nativeInstance != 0L) {
            try {
                nativeGetRollAngle(nativeInstance, faceIdx)
            } catch (e: UnsatisfiedLinkError) {
                0f
            }
        } else 0f
    }

    fun getYawAngle(faceIdx: Int): Float {
        return if (nativeInstance != 0L) {
            try {
                nativeGetYawAngle(nativeInstance, faceIdx)
            } catch (e: UnsatisfiedLinkError) {
                0f
            }
        } else 0f
    }

    fun setAge(faceIdx: Int, age: Int) {
        if (nativeInstance != 0L) {
            try {
                nativeSetAge(nativeInstance, faceIdx, age)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun setDetectHeight(h: Int) {
        if (nativeInstance != 0L) {
            try {
                nativeSetDetectHeight(nativeInstance, h)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun setDetectWidth(w: Int) {
        if (nativeInstance != 0L) {
            try {
                nativeSetDetectWidth(nativeInstance, w)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun setFaceLandmark(points: ArrayList<PointF>?, faceIdx: Int, landmarkType: Int, width: Int, height: Int): Boolean {
        if (points == null || points.isEmpty() || nativeInstance == 0L) return false
        val arr = FloatArray(points.size * 2)
        for (i in points.indices) {
            val i2 = i * 2
            arr[i2] = points[i].x / width
            arr[i2 + 1] = points[i].y / height
        }
        return try {
            nativeSetLandmark(nativeInstance, landmarkType, faceIdx, arr)
        } catch (e: UnsatisfiedLinkError) {
            false
        }
    }

    fun setFaceRect(rect: Rect, faceIdx: Int, width: Int, height: Int) {
        if (nativeInstance == 0L) return
        val w = width.toFloat()
        val h = height.toFloat()
        try {
            nativeSetFaceRect(nativeInstance, faceIdx, floatArrayOf(rect.left / w, rect.top / h, rect.right / w, rect.bottom / h))
        } catch (ignored: UnsatisfiedLinkError) {
        }
    }

    fun setGender(faceIdx: Int, gender: MTGender) {
        if (nativeInstance != 0L) {
            try {
                nativeSetGender(nativeInstance, faceIdx, gender.id)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun setNormalizedFaceLandmark(points: ArrayList<PointF>?, faceIdx: Int, landmarkType: Int): Boolean {
        if (points == null || points.isEmpty() || nativeInstance == 0L) return false
        val arr = FloatArray(points.size * 2)
        for (i in points.indices) {
            val i2 = i * 2
            arr[i2] = points[i].x
            arr[i2 + 1] = points[i].y
        }
        return try {
            nativeSetLandmark(nativeInstance, landmarkType, faceIdx, arr)
        } catch (e: UnsatisfiedLinkError) {
            false
        }
    }

    fun setRace(faceIdx: Int, race: MTRace) {
        if (nativeInstance != 0L) {
            try {
                nativeSetRace(nativeInstance, faceIdx, race.id)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    fun setRollAngle(faceIdx: Int, roll: Float) {
        if (nativeInstance != 0L) {
            try {
                nativeSetRollAngle(nativeInstance, faceIdx, roll)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }

    @Throws(Throwable::class)
    protected fun finalize() {
        if (nativeInstance != 0L) {
            try {
                finalizer(nativeInstance)
            } catch (ignored: UnsatisfiedLinkError) {
            }
        }
    }
}
