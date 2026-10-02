package com.meitu.videoedit.engine

import com.meitu.media.mtmvcore.MTAudioTrack
import com.meitu.media.mtmvcore.MTFilterTrack
import com.meitu.media.mtmvcore.MTMVTrack
import org.junit.Assert.*
import org.junit.Test

/**
 * Unit Tests kiểm định toàn diện chất lượng Khối 2: Video Editor (Video Engine).
 */
class VideoEngineTest {

    @Test
    fun testVideoResolutionConfigs() {
        val r720 = VideoExportManager.Resolution.RES_720P
        assertEquals(720, r720.width)
        assertEquals(1280, r720.height)
        assertEquals(4_000_000L, r720.defaultBitrate)

        val r1080 = VideoExportManager.Resolution.RES_1080P
        assertEquals(1080, r1080.width)
        assertEquals(1920, r1080.height)
        assertEquals(8_000_000L, r1080.defaultBitrate)

        val r4k = VideoExportManager.Resolution.RES_4K
        assertEquals(2160, r4k.width)
        assertEquals(3840, r4k.height)
        assertEquals(25_000_000L, r4k.defaultBitrate)
    }

    @Test
    fun testExportStateFlowObjects() {
        val idle = VideoExportManager.ExportState.Idle
        assertNotNull(idle)

        val progress = VideoExportManager.ExportState.Progress(0.75f)
        assertEquals(0.75f, progress.percentage, 0.001f)

        val success = VideoExportManager.ExportState.Success("/sdcard/DCIM/meitu_video.mp4")
        assertEquals("/sdcard/DCIM/meitu_video.mp4", success.outputPath)

        val error = VideoExportManager.ExportState.Error("MediaCodec hardware timeout")
        assertEquals("MediaCodec hardware timeout", error.message)
    }

    @Test
    fun testVideoCacheManagerMemoryBudget() {
        val cache = VideoCacheManager.createForTest(32 * 1024 * 1024)
        assertEquals(32L * 1024 * 1024, cache.getMaxSizeBytes())
        assertEquals(0L, cache.getCurrentSizeBytes())
        assertEquals(0.0f, cache.getCacheHitRate(), 0.001f)
        assertFalse(cache.hasFrame(1000L))
        assertNull(cache.getFrame(1000L))

        cache.clear()
        assertEquals(0L, cache.getCurrentSizeBytes())
    }

    @Test
    fun testMTMVTrackEditingProperties() {
        val track = MTMVTrack(0L)
        track.sourcePath = "/storage/emulated/0/DCIM/clip1.mp4"
        assertEquals("/storage/emulated/0/DCIM/clip1.mp4", track.sourcePath)

        track.trim(1000000L, 5000000L)
        assertEquals(1000000L, track.inPointUs)
        assertEquals(5000000L, track.outPointUs)

        track.setPlaybackSpeed(2.5f)
        assertEquals(2.5f, track.getPlaybackSpeed(), 0.001f)

        // Clamping check
        track.setPlaybackSpeed(0.01f)
        assertEquals(0.1f, track.getPlaybackSpeed(), 0.001f)

        track.setPlaybackSpeed(200.0f)
        assertEquals(100.0f, track.getPlaybackSpeed(), 0.001f)

        track.setTrackVolume(1.8f)
        assertEquals(1.8f, track.getTrackVolume(), 0.001f)

        track.setTrackVolume(5.0f)
        assertEquals(2.0f, track.getTrackVolume(), 0.001f)
    }

    @Test
    fun testMTAudioTrackEditingProperties() {
        val audioTrack = MTAudioTrack(0L)
        audioTrack.audioPath = "/storage/emulated/0/Music/bgm.mp3"
        assertEquals("/storage/emulated/0/Music/bgm.mp3", audioTrack.audioPath)

        audioTrack.trim(500000L, 12000000L)
        assertEquals(500000L, audioTrack.inPointUs)
        assertEquals(12000000L, audioTrack.outPointUs)

        audioTrack.setTrackVolume(0.8f)
        assertEquals(0.8f, audioTrack.getTrackVolume(), 0.001f)

        audioTrack.setAudioPitch(1.5f)
        assertEquals(1.5f, audioTrack.getAudioPitch(), 0.001f)

        audioTrack.setAudioPitch(0.1f)
        assertEquals(0.5f, audioTrack.getAudioPitch(), 0.001f)
    }

    @Test
    fun testMTFilterTrackIntensityClamping() {
        val filterTrack = MTFilterTrack(0L)
        filterTrack.filterPath = "luts/tokyo_35mm.png"
        assertEquals("luts/tokyo_35mm.png", filterTrack.filterPath)

        filterTrack.setFilterIntensity(0.7f)
        assertEquals(0.7f, filterTrack.getFilterIntensity(), 0.001f)

        filterTrack.setFilterIntensity(-0.5f)
        assertEquals(0.0f, filterTrack.getFilterIntensity(), 0.001f)

        filterTrack.setFilterIntensity(2.0f)
        assertEquals(1.0f, filterTrack.getFilterIntensity(), 0.001f)
    }
}
