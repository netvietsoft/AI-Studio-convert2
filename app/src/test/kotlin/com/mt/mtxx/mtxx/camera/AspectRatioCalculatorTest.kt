package com.mt.mtxx.mtxx.camera

import org.junit.Assert.assertEquals
import org.junit.Test

class AspectRatioCalculatorTest {

    @Test
    fun testStandardAspectRatios() {
        val ratios = CameraActivity.AspectRatio.values()
        assertEquals(4, ratios.size)

        // 4:3 Ratio
        val r43 = CameraActivity.AspectRatio.RATIO_4_3
        assertEquals(3, r43.w)
        assertEquals(4, r43.h)

        // 9:16 Ratio
        val r916 = CameraActivity.AspectRatio.RATIO_9_16
        assertEquals(9, r916.w)
        assertEquals(16, r916.h)

        // 1:1 Square Ratio
        val r11 = CameraActivity.AspectRatio.RATIO_1_1
        assertEquals(1, r11.w)
        assertEquals(1, r11.h)
    }

    @Test
    fun testViewportHeightCalculation() {
        fun calcHeight(w: Int, ratio: CameraActivity.AspectRatio): Int {
            return when (ratio) {
                CameraActivity.AspectRatio.RATIO_1_1 -> w
                CameraActivity.AspectRatio.RATIO_4_3 -> (w * 4) / 3
                CameraActivity.AspectRatio.RATIO_9_16 -> (w * 16) / 9
                CameraActivity.AspectRatio.RATIO_FULL -> (w * 19) / 9
            }
        }

        val baseWidth = 600
        assertEquals(600, calcHeight(baseWidth, CameraActivity.AspectRatio.RATIO_1_1))
        assertEquals(800, calcHeight(baseWidth, CameraActivity.AspectRatio.RATIO_4_3))
        assertEquals(1066, calcHeight(baseWidth, CameraActivity.AspectRatio.RATIO_9_16))
    }
}
