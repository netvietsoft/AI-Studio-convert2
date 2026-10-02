package com.meitu.core

import androidx.annotation.Keep
import java.nio.ByteBuffer

/**
 * Cầu nối JNI Render chính điều khiển pipeline bộ lọc, làm đẹp da, blend màu C++.
 * Nguồn: com.meitu.core.MTFilterKernelRender.java
 */
@Keep
class MTFilterKernelRender : TypesBaseClass() {

    private var nativeInstance: Long = 0L

    init {
        MeituNativeLoader.loadLibrary("c++_shared")
        MeituNativeLoader.loadLibrary("MTFilterKernel")
        nativeInstance = nCreate()
    }

    fun init() {
        if (nativeInstance != 0L) {
            nInit(nativeInstance)
        }
    }

    fun loadFilterConfig(configPath: String): Boolean {
        return if (nativeInstance != 0L) {
            nLoadFilterConfig(nativeInstance, configPath)
        } else false
    }

    fun renderToTexture(
        inTexture: Int,
        outTexture: Int,
        width: Int,
        height: Int,
        orientation: Int = 0,
        flip: Int = 0,
        format: Int = 0
    ): Int {
        return if (nativeInstance != 0L) {
            nRenderToOutTexture(nativeInstance, inTexture, outTexture, width, height, orientation, flip)
        } else -1
    }

    fun setFaceData(faceDataInstance: Long) {
        if (nativeInstance != 0L) {
            nSetFaceData(nativeInstance, faceDataInstance)
        }
    }

    fun activeEffect() {
        if (nativeInstance != 0L) {
            nActiveEffect(nativeInstance)
        }
    }

    fun release() {
        if (nativeInstance != 0L) {
            nRelease(nativeInstance)
            nFinalizer(nativeInstance)
            nativeInstance = 0L
        }
    }

    protected fun finalize() {
        release()
    }

    // --- NATIVE METHODS (BẢO TOÀN NGUYÊN VẸN SIGNATURE) ---
    private external fun nCreate(): Long
    private external fun nInit(instance: Long)
    private external fun nLoadFilterConfig(instance: Long, path: String): Boolean
    private external fun nRenderToOutTexture(
        instance: Long,
        inTex: Int,
        outTex: Int,
        w: Int,
        h: Int,
        orientation: Int,
        flip: Int
    ): Int
    private external fun nSetFaceData(instance: Long, faceData: Long)
    private external fun nActiveEffect(instance: Long)
    private external fun nRelease(instance: Long)
    private external fun nFinalizer(instance: Long)
}
