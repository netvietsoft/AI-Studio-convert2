package com.mt.mtxx.mtxx.camera

import org.junit.Assert.assertEquals
import org.junit.Assert.assertNotNull
import org.junit.Assert.assertTrue
import org.junit.Test

class CameraConfigTest {

    @Test
    fun testCameraModesCompleteness() {
        val modes = CameraActivity.CameraMode.values()
        assertEquals(4, modes.size)
        assertTrue(modes.contains(CameraActivity.CameraMode.PHOTO))
        assertTrue(modes.contains(CameraActivity.CameraMode.PORTRAIT_BOKEH))
        assertTrue(modes.contains(CameraActivity.CameraMode.SHORT_VIDEO))
        assertTrue(modes.contains(CameraActivity.CameraMode.NIGHT_AI))
    }

    @Test
    fun testFlashModesCompleteness() {
        val flashes = CameraActivity.FlashMode.values()
        assertEquals(4, flashes.size)
        assertNotNull(CameraActivity.FlashMode.OFF.icon)
        assertNotNull(CameraActivity.FlashMode.ON.icon)
        assertNotNull(CameraActivity.FlashMode.AUTO.icon)
        assertNotNull(CameraActivity.FlashMode.TORCH.icon)
    }

    @Test
    fun testTimerCycleLogic() {
        fun nextTimer(curr: Int): Int = when (curr) {
            0 -> 3
            3 -> 5
            5 -> 10
            else -> 0
        }

        assertEquals(3, nextTimer(0))
        assertEquals(5, nextTimer(3))
        assertEquals(10, nextTimer(5))
        assertEquals(0, nextTimer(10))
    }
}
