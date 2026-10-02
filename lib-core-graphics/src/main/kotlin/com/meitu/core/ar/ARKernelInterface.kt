package com.meitu.core.ar

import android.content.Context
import androidx.annotation.Keep
import com.meitu.core.MteApplication
import java.util.concurrent.atomic.AtomicBoolean

/**
 * AR Kernel Interface chuẩn C++ Native của Meitu.
 * Nguồn: com.meitu.mtlab.arkernelinterface.core.ARKernelInterfaceJNI
 * Kết nối trực tiếp với libarkernel3.so, libARKernelInterface.so, libARSPM.so, libMTARMPM.so.
 */
@Keep
class ARKernelInterface {

    companion object {
        private val isLoaded = AtomicBoolean(false)

        init {
            loadNativeLibraries()
        }

        @JvmStatic
        @Synchronized
        fun loadNativeLibraries() {
            if (isLoaded.get()) return
            try {
                System.loadLibrary("c++_shared")
                System.loadLibrary("ffmpeg")
                System.loadLibrary("aicodec")
                System.loadLibrary("MTARMPM")
                System.loadLibrary("ARSPM")
                System.loadLibrary("ARKernelInterface")
                isLoaded.set(true)
            } catch (e: UnsatisfiedLinkError) {
                try {
                    val ctx = MteApplication.getInstance().getContext()
                    if (ctx != null) {
                        System.loadLibrary("ARKernelInterface")
                        isLoaded.set(true)
                    }
                } catch (ignored: Throwable) {}
            }
        }
    }

    private var nativeInstance: Long = 0L

    init {
        try {
            if (isLoaded.get()) {
                nativeInstance = nativeCreateInstance()
            }
        } catch (e: UnsatisfiedLinkError) {
            nativeInstance = 0L
        }
    }

    // JNI Native methods matching libARKernelInterface.so
    private external fun nativeCreateInstance(): Long
    private external fun nativeDestroyInstance(handle: Long)
    private external fun nativeInitialize(handle: Long, glContext: Long, configPath: String)
    private external fun nativeInitializeWithNoOpenGLContext(handle: Long)
    private external fun nativeParserConfiguration(handle: Long, packagePath: String, plist: String, json: String, type: Int): Long
    private external fun nativeDeleteConfiguration(handle: Long, configHandle: Long)
    private external fun nativeOnDrawFrame(handle: Long, textureIn: Int, textureOut: Int, width: Int, height: Int, orientation: Int, mirror: Int): Boolean
    private external fun nativeOnTouchBegin(handle: Long, x: Float, y: Float, pointerId: Int)
    private external fun nativeOnTouchMove(handle: Long, x: Float, y: Float, pointerId: Int)
    private external fun nativeOnTouchEnd(handle: Long, x: Float, y: Float, pointerId: Int)
    private external fun nativeGetTotalFaceState(handle: Long): Int
    private external fun nativeGetMemoryUsage(handle: Long): Long

    fun isNativeReady(): Boolean = nativeInstance != 0L

    fun initialize(glContext: Long = 0L, configPath: String = "") {
        if (nativeInstance != 0L) {
            if (glContext != 0L) {
                nativeInitialize(nativeInstance, glContext, configPath)
            } else {
                nativeInitializeWithNoOpenGLContext(nativeInstance)
            }
        }
    }

    fun loadStickerPackage(packagePath: String, plistName: String = "config.plist", jsonName: String = "package.json"): Long {
        if (nativeInstance == 0L) return 0L
        return nativeParserConfiguration(nativeInstance, packagePath, plistName, jsonName, 0)
    }

    fun removeStickerPackage(configHandle: Long) {
        if (nativeInstance != 0L && configHandle != 0L) {
            nativeDeleteConfiguration(nativeInstance, configHandle)
        }
    }

    fun drawFrame(textureIn: Int, textureOut: Int, width: Int, height: Int, orientation: Int = 0, mirror: Int = 0): Boolean {
        if (nativeInstance == 0L) return false
        return nativeOnDrawFrame(nativeInstance, textureIn, textureOut, width, height, orientation, mirror)
    }

    fun dispatchTouchEvent(action: Int, x: Float, y: Float, pointerId: Int = 0) {
        if (nativeInstance == 0L) return
        when (action) {
            0 -> nativeOnTouchBegin(nativeInstance, x, y, pointerId)
            2 -> nativeOnTouchMove(nativeInstance, x, y, pointerId)
            1, 3 -> nativeOnTouchEnd(nativeInstance, x, y, pointerId)
        }
    }

    fun getMemoryUsage(): Long {
        if (nativeInstance == 0L) return 0L
        return nativeGetMemoryUsage(nativeInstance)
    }

    protected fun finalize() {
        if (nativeInstance != 0L) {
            val handle = nativeInstance
            nativeInstance = 0L
            try {
                nativeDestroyInstance(handle)
            } catch (ignored: Throwable) {}
        }
    }
}
