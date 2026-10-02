package com.meitu.core

import android.graphics.PointF
import android.graphics.RectF
import androidx.annotation.Keep

/**
 * Cấu trúc dữ liệu nhận diện khuôn mặt nạp vào Filter Kernel C++.
 * Nguồn: com.meitu.core.MTFilterKernelFaceData.java
 */
@Keep
class MTFilterKernelFaceData : TypesBaseClass() {

    var nativeInstance: Long = 0L
        private set

    init {
        nativeInstance = nativeCreate()
    }

    enum class MTFilterKernelGender(val id: Int) {
        UNDEFINE_GENDER(-1),
        FEMALE(0),
        MALE(1);

        companion object {
            fun fromId(id: Int) = values().firstOrNull { it.id == id } ?: UNDEFINE_GENDER
        }
    }

    enum class MTFilterRace(val id: Int) {
        UNDEFINE_SKIN_RACE(-1),
        BLACK_SKIN_RACE(0),
        WHITE_SKIN_RACE(1),
        YELLOW_SKIN_RACE(2);

        companion object {
            fun fromId(id: Int) = values().firstOrNull { it.id == id } ?: UNDEFINE_SKIN_RACE
        }
    }

    fun clear() {
        if (nativeInstance != 0L) {
            nativeClear(nativeInstance)
        }
    }

    fun release() {
        if (nativeInstance != 0L) {
            finalizer(nativeInstance)
            nativeInstance = 0L
        }
    }

    protected fun finalize() {
        release()
    }

    // --- NATIVE METHODS ---
    private external fun nativeCreate(): Long
    private external fun nativeClear(instance: Long)
    private external fun finalizer(instance: Long)
}
