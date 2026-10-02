package com.meitu.core.types

import android.graphics.Bitmap
import androidx.annotation.Keep
import com.meitu.core.MeituNativeLoader
import java.nio.ByteBuffer
import java.util.concurrent.locks.ReentrantReadWriteLock

/**
 * Cấu trúc quản lý bộ nhớ C++ cốt lõi (C++ Native Memory Context) cho toàn bộ hệ sinh thái Meitu.
 * Nắm giữ con trỏ bộ nhớ `nativeBitmap: Long` tương ứng với struct `MBitmap*` trong libbmpKit.so.
 *
 * Mọi thao tác xử lý ảnh C++ (MTFilterKernel, MTLiquify, FaceDetect, Beauty)
 * đều bắt buộc phải thông qua NativeBitmap để cấp phát và giải phóng bộ nhớ RAM ngoài JVM Heap.
 */
@Keep
class NativeBitmap private constructor(
    protected val nativeBitmap: Long,
    private var mWidth: Int,
    private var mHeight: Int
) {
    protected var nativeFinalized: Boolean = false
    private val rwLock = ReentrantReadWriteLock()
    private val readLock = rwLock.readLock()
    private val writeLock = rwLock.writeLock()

    companion object {
        const val COLOR_TYPE_RGBA = 0
        const val COLOR_TYPE_BGRA = 1
        const val COLOR_TYPE_ARGB = 2
        const val COLOR_TYPE_ABGR = 3

        init {
            MeituNativeLoader.loadLibrary("c++_shared")
            MeituNativeLoader.loadLibrary("bmpKit")
        }

        /**
         * Cấp phát bộ nhớ C++ thuần túy với chiều rộng và chiều cao chỉ định.
         */
        @JvmStatic
        fun createBitmap(width: Int, height: Int): NativeBitmap {
            val handle = try {
                nativeCreate(width, height)
            } catch (e: Throwable) {
                0L
            }
            return NativeBitmap(handle, width, height)
        }

        /**
         * Chuyển đổi Android Bitmap sang C++ NativeBitmap (Sao chép pixel vào RAM C++ native).
         */
        @JvmStatic
        fun createBitmap(bitmap: Bitmap?): NativeBitmap? {
            if (bitmap == null || bitmap.isRecycled) {
                return null
            }
            val nb = createBitmap(bitmap.width, bitmap.height)
            nb.setImage(bitmap)
            return nb
        }

        @JvmStatic
        fun createBitmap(tag: String, bitmap: Bitmap?): NativeBitmap? {
            return createBitmap(bitmap)
        }

        // --- NATIVE STATIC JNI BRIDGES (TƯƠNG THÍCH CHÍNH XÁC VỚI libbmpKit.so) ---
        @JvmStatic private external fun nativeCreate(w: Int, h: Int): Long
        @JvmStatic private external fun nativeSetImage(instance: Long, bitmap: Bitmap): Boolean
        @JvmStatic private external fun nativeGetImage(instance: Long, w: Int, h: Int): Bitmap?
        @JvmStatic private external fun nativeRelease(instance: Long)
        @JvmStatic private external fun nativeCopyToBitmap(instance: Long, bitmap: Bitmap): Boolean
        @JvmStatic private external fun nativeCopy(src: Long, dst: Long): Boolean
        @JvmStatic private external fun nativeScale(src: Long, dst: Long): Boolean
        @JvmStatic private external fun nativeGetWidth(instance: Long): Int
        @JvmStatic private external fun nativeGetHeight(instance: Long): Int
        @JvmStatic private external fun nativeGetChannel(instance: Long): Int
        @JvmStatic private external fun nativeGetPixelsPointer(instance: Long): Long
        @JvmStatic private external fun nativeIsRecycled(instance: Long): Boolean
        @JvmStatic private external fun native_BitmapTexImage2D(instance: Long, target: Int): Boolean
        @JvmStatic private external fun native_copyPixelsFromBuffer(instance: Long, buffer: ByteBuffer): Boolean
        @JvmStatic private external fun native_copyPixelsToBuffer(instance: Long, buffer: ByteBuffer): Boolean
        @JvmStatic private external fun finalizer(instance: Long)
    }

    /**
     * Nạp dữ liệu ảnh từ Android Bitmap vào vùng nhớ Native C++.
     */
    fun setImage(bitmap: Bitmap): Boolean {
        if (nativeBitmap == 0L || bitmap.isRecycled) return false
        writeLock.lock()
        return try {
            mWidth = bitmap.width
            mHeight = bitmap.height
            nativeSetImage(nativeBitmap, bitmap)
        } catch (e: Throwable) {
            false
        } finally {
            writeLock.unlock()
        }
    }

    /**
     * Xuất dữ liệu ảnh từ vùng nhớ Native C++ ngược trở lại Android Bitmap.
     */
    fun getImage(): Bitmap? {
        return getImage(getWidth(), getHeight())
    }

    fun getImage(w: Int, h: Int): Bitmap? {
        if (nativeBitmap == 0L) return null
        readLock.lock()
        return try {
            nativeGetImage(nativeBitmap, w, h)
        } catch (e: Throwable) {
            null
        } finally {
            readLock.unlock()
        }
    }

    /**
     * Trả về địa chỉ con trỏ bộ nhớ C++ (Pointer handle) phục vụ các module xử lý khác.
     */
    fun nativeInstance(): Long = nativeBitmap

    fun getWidth(): Int {
        if (nativeBitmap == 0L) return mWidth
        return try { nativeGetWidth(nativeBitmap) } catch (e: Throwable) { mWidth }
    }

    fun getHeight(): Int {
        if (nativeBitmap == 0L) return mHeight
        return try { nativeGetHeight(nativeBitmap) } catch (e: Throwable) { mHeight }
    }

    fun getChannel(): Int {
        if (nativeBitmap == 0L) return 4
        return try { nativeGetChannel(nativeBitmap) } catch (e: Throwable) { 4 }
    }

    fun getPixelsPointer(): Long {
        if (nativeBitmap == 0L) return 0L
        return try { nativeGetPixelsPointer(nativeBitmap) } catch (e: Throwable) { 0L }
    }

    fun isRecycled(): Boolean {
        if (nativeFinalized || nativeBitmap == 0L) return true
        return try { nativeIsRecycled(nativeBitmap) } catch (e: Throwable) { true }
    }

    /**
     * Giải phóng bộ nhớ C++ (Tránh rò rỉ RAM).
     */
    fun isNativeActive(): Boolean = !isRecycled()

    fun copy(): NativeBitmap {
        val w = getWidth()
        val h = getHeight()
        val dst = createBitmap(w, h)
        nativeCopy(this.nativeBitmap, dst.nativeBitmap)
        return dst
    }

    fun release() {
        recycle()
    }

    fun <T> runBlockWithLock(action: (NativeBitmap) -> T): T {
        readLock.lock()
        try {
            return action(this)
        } finally {
            readLock.unlock()
        }
    }

    fun recycle() {
        if (!nativeFinalized && nativeBitmap != 0L) {
            writeLock.lock()
            try {
                nativeRelease(nativeBitmap)
                nativeFinalized = true
            } catch (e: Throwable) {
                // Ignore
            } finally {
                writeLock.unlock()
            }
        }
    }

    protected fun finalize() {
        if (!nativeFinalized && nativeBitmap != 0L) {
            try {
                finalizer(nativeBitmap)
                nativeFinalized = true
            } catch (e: Throwable) {
                // Ignore
            }
        }
    }
}
