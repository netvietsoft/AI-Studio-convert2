// Source decompiled: com.meitu.videoedit.manager.VideoTimelineManager.kt
package com.meitu.videoedit.engine

import android.util.Log
import androidx.annotation.Keep
import com.meitu.media.mtmvcore.*

/**
 * Trình quản lý luồng Timeline biên tập video tầng cao (Video Timeline Manager).
 * High-level coordinator managing video clips, audio tracks, BGM, filters, and transitions.
 */
@Keep
class VideoTimelineManager {
    private val TAG = "VideoTimelineManager"
    private var timeline: MTMVTimeLine = MTMVTimeLine()
    private val videoTracks = mutableListOf<MTMVTrack>()
    private val filterTracks = mutableListOf<MTFilterTrack>()
    private var bgmTrack: MTMVTrack? = null
    private var currentGroup: MTMVGroup? = null

    init {
        val group = MTMVGroup.create(0L)
        if (group != null) {
            currentGroup = group
            timeline.pushBackGroup(group)
        }
    }

    /**
     * Thêm một đoạn video clip vào Timeline.
     * Add a video clip into the timeline.
     * @param videoPath Đường dẫn file video / File path.
     * @param startTimeUs Thời điểm bắt đầu (micro giây) / Start time in microseconds.
     * @param durationUs Thời lượng (micro giây) / Duration in microseconds.
     */
    fun addVideoClip(videoPath: String, startTimeUs: Long = 0L, durationUs: Long = 0L): Boolean {
        return try {
            val track = MTMVTrack.create(videoPath, startTimeUs, durationUs, 0L)
            if (track != null) {
                videoTracks.add(track)
                currentGroup?.addTrack(track)
                timeline.invalidate()
                true
            } else {
                Log.e(TAG, "Failed to create MTMVTrack for: $videoPath")
                false
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error adding video clip: ${e.message}")
            false
        }
    }

    /**
     * Thiết lập nhạc nền (BGM) cho toàn bộ video.
     * Set background music for the video timeline.
     */
    fun setBackgroundMusic(audioPath: String, volume: Float = 0.8f): Boolean {
        return try {
            val track = MTMVTrack.create(audioPath, 0L, 0L, 0L)
            if (track != null) {
                track.setVolume(volume)
                bgmTrack = track
                timeline.setBgm(track)
                true
            } else {
                false
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error setting BGM: ${e.message}")
            false
        }
    }

    /**
     * Thêm bộ lọc màu / 3D LUT lên video.
     * Apply color filter / 3D LUT effect onto video.
     */
    fun addFilterEffect(filterPath: String, configPath: String = "", startTimeUs: Long = 0L, durationUs: Long = 0L): Boolean {
        return try {
            val filter = MTFilterTrack.createWithFilename(filterPath, configPath, startTimeUs, durationUs)
            if (filter != null) {
                filterTracks.add(filter)
                timeline.addMixTrack(filter)
                true
            } else {
                false
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error adding filter: ${e.message}")
            false
        }
    }

    /**
     * Thêm hiệu ứng chuyển cảnh giữa hai clip.
     * Apply transition effect between clips.
     */
    fun applyTransition(transition: MTITransition, position: Int = 0): Boolean {
        val group = currentGroup ?: return false
        return timeline.runTransition(group, position, transition)
    }

    /**
     * Lấy tổng thời lượng của Timeline (micro giây).
     * Get total timeline duration in microseconds.
     */
    fun getTotalDuration(): Long = timeline.getDuration()

    /**
     * Điều chỉnh âm lượng tổng thể.
     * Adjust master volume.
     */
    fun setMasterVolume(volume: Float) {
        timeline.setVolume(volume)
    }

    /**
     * Giải phóng toàn bộ tài nguyên Timeline C++ native.
     * Release all native timeline resources.
     */
    fun release() {
        videoTracks.forEach { it.release() }
        videoTracks.clear()
        filterTracks.forEach { it.release() }
        filterTracks.clear()
        bgmTrack?.release()
        bgmTrack = null
        currentGroup?.release()
        currentGroup = null
        timeline.release()
    }
}
