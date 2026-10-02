package com.meitu.videoedit.engine

import android.graphics.Bitmap
import android.util.Log
import androidx.annotation.Keep
import java.util.LinkedHashMap

/**
 * Trình quản lý bộ nhớ đệm khung hình video LRU chống tràn RAM (Video Frame LRU Cache Manager).
 * Memory-bounded LRU cache storing decoded video frames to guarantee 60 FPS scrubber seeking
 * while preventing Out-Of-Memory (OOM) crashes.
 *
 * Backed by thread-safe LinkedHashMap with byte size accounting, fully compatible
 * across Android ART and JVM test runners.
 */
@Keep
class VideoCacheManager private constructor(private val maxMemoryBytes: Long) {

    private val TAG = "VideoCacheManager"

    private var hitCount = 0L
    private var missCount = 0L
    private var currentSizeBytes = 0L

    // LRU order enabled by accessOrder = true
    private val frameMap = object : LinkedHashMap<Long, Bitmap>(16, 0.75f, true) {
        override fun removeEldestEntry(eldest: MutableMap.MutableEntry<Long, Bitmap>?): Boolean {
            return currentSizeBytes > maxMemoryBytes
        }
    }

    private fun logDebug(tag: String, msg: String) {
        try {
            Log.d(tag, msg)
        } catch (_: Throwable) {
            println("[$tag] $msg")
        }
    }

    private fun getBitmapSize(bitmap: Bitmap): Int {
        return try {
            bitmap.byteCount
        } catch (_: Throwable) {
            4096 // Fallback default for mock/test objects
        }
    }

    companion object {
        private const val DEFAULT_MAX_MEMORY_FRACTION = 8 // 1/8 of available heap
        private const val MAX_BUDGET_BYTES = 128L * 1024 * 1024 // 128 MB cap

        @Volatile
        private var instance: VideoCacheManager? = null

        @JvmStatic
        fun getInstance(): VideoCacheManager {
            return instance ?: synchronized(this) {
                instance ?: run {
                    val maxMemory = Runtime.getRuntime().maxMemory()
                    val calculatedBudget = (maxMemory / DEFAULT_MAX_MEMORY_FRACTION).coerceAtMost(MAX_BUDGET_BYTES)
                    val budget = calculatedBudget.coerceAtLeast(16L * 1024 * 1024) // min 16MB
                    VideoCacheManager(budget).also { instance = it }
                }
            }
        }

        @JvmStatic
        fun createForTest(budgetBytes: Long): VideoCacheManager {
            return VideoCacheManager(budgetBytes)
        }
    }

    /**
     * Lấy khung hình đã đệm tại mốc thời gian timeMs.
     */
    @Synchronized
    fun getFrame(timeMs: Long): Bitmap? {
        val cached = frameMap[timeMs]
        if (cached != null) {
            val isRecycled = try { cached.isRecycled } catch (_: Throwable) { false }
            if (!isRecycled) {
                hitCount++
                return cached
            } else {
                frameMap.remove(timeMs)
                currentSizeBytes -= getBitmapSize(cached)
            }
        }
        missCount++
        return null
    }

    /**
     * Lưu trữ khung hình vào bộ nhớ đệm LRU.
     */
    @Synchronized
    fun putFrame(timeMs: Long, bitmap: Bitmap) {
        val isRecycled = try { bitmap.isRecycled } catch (_: Throwable) { false }
        if (isRecycled) return

        val size = getBitmapSize(bitmap)
        val existing = frameMap.put(timeMs, bitmap)
        if (existing != null) {
            currentSizeBytes -= getBitmapSize(existing)
        }
        currentSizeBytes += size

        // Trim until within budget
        val iterator = frameMap.entries.iterator()
        while (currentSizeBytes > maxMemoryBytes && iterator.hasNext()) {
            val entry = iterator.next()
            currentSizeBytes -= getBitmapSize(entry.value)
            iterator.remove()
        }
    }

    /**
     * Kiểm tra xem khung hình có trong bộ đệm hay không.
     */
    @Synchronized
    fun hasFrame(timeMs: Long): Boolean {
        val cached = frameMap[timeMs] ?: return false
        val isRecycled = try { cached.isRecycled } catch (_: Throwable) { false }
        return !isRecycled
    }

    /**
     * Xóa toàn bộ bộ nhớ đệm khung hình.
     */
    @Synchronized
    fun clear() {
        frameMap.clear()
        currentSizeBytes = 0L
        hitCount = 0L
        missCount = 0L
        logDebug(TAG, "Video frame cache cleared.")
    }

    /**
     * Giải phóng bộ nhớ đệm khi hệ thống thông báo thiếu RAM (onTrimMemory).
     */
    @Synchronized
    fun trimMemory(level: Int) {
        if (level >= 60) { // TRIM_MEMORY_COMPLETE / MODERATE
            clear()
        } else if (level >= 15) { // TRIM_MEMORY_RUNNING_CRITICAL
            val targetSize = maxMemoryBytes / 2
            val iterator = frameMap.entries.iterator()
            while (currentSizeBytes > targetSize && iterator.hasNext()) {
                val entry = iterator.next()
                currentSizeBytes -= getBitmapSize(entry.value)
                iterator.remove()
            }
        }
    }

    /**
     * Tỉ lệ trúng cache (Cache hit rate 0.0 - 1.0).
     */
    @Synchronized
    fun getCacheHitRate(): Float {
        val total = hitCount + missCount
        return if (total > 0) (hitCount.toFloat() / total.toFloat()) else 0f
    }

    @Synchronized
    fun getCurrentSizeBytes(): Long = currentSizeBytes

    @Synchronized
    fun getMaxSizeBytes(): Long = maxMemoryBytes
}
