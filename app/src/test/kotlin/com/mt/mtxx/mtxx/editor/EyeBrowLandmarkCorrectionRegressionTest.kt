package com.mt.mtxx.mtxx.editor

import com.meitu.ai.facedetect.FaceDetector106
import org.junit.Assert.assertEquals
import org.junit.Assert.assertFalse
import org.junit.Assert.assertNotNull
import org.junit.Assert.assertTrue
import org.junit.Test

/**
 * Deterministic Focused Regression Test Suite for Eye and Eyebrow Landmark Corrections (TASK_015).
 *
 * Verifies that:
 * 1. Eye anchor resolution correctly prioritizes Iris Dense Mesh when available and valid.
 * 2. Corrupt or inner-mouth landmarks (points 104 & 105) are strictly rejected by anatomical sanity checks.
 * 3. Canonical eye landmarks (38/57, 70/80, or eye contours 62..79) are resolved correctly above nose and mouth.
 * 4. Eyebrow anchor resolution averages landmarks 33..42 & 43..52 and strictly enforces lyBrow < lyEye.
 * 5. Eyebrow tools (BROW_01..BROW_06) are properly wired and configured in the production editor suite.
 */
class EyeBrowLandmarkCorrectionRegressionTest {

    private val width = 960
    private val height = 1280
    private val noseY = 560f
    private val mouthY = 740f

    @Test
    fun testResolveAnatomicalEyes_withValidIrisTrack() {
        val iris = FaceDetector106.IrisTrackInfo(
            leftCenterX = 350f,
            leftCenterY = 460f,
            leftRadius = 25f,
            rightCenterX = 610f,
            rightCenterY = 460f,
            rightRadius = 25f
        )
        val dummyLandmarks = FloatArray(106 * 2) { 0f }

        val eyes = PhotoEditorActivity.resolveAnatomicalEyes(
            dummyLandmarks, iris, width, height, noseY, mouthY
        )

        assertTrue("Sanity check must pass for valid iris track", eyes.isSanityPassed)
        assertEquals("Source must be IRIS_TRACK", "IRIS_TRACK", eyes.source)
        assertEquals(350f, eyes.lx, 0.01f)
        assertEquals(460f, eyes.ly, 0.01f)
        assertEquals(610f, eyes.rx, 0.01f)
        assertEquals(460f, eyes.ry, 0.01f)
        assertTrue("Eyes must be strictly above nose", eyes.ly < noseY && eyes.ry < noseY)
        assertTrue("Eyes must be strictly above mouth", eyes.ly < mouthY - 30f && eyes.ry < mouthY - 30f)
    }

    @Test
    fun testResolveAnatomicalEyes_rejectsInnerMouthPoints104And105() {
        // Construct landmarks where 104 and 105 are inner-mouth points (Y=762, 769),
        // but points 38 and 57 are true eyes (Y=460)
        val lmk = FloatArray(106 * 2) { 0f }

        // Points 104 & 105 (inner mouth / lips)
        lmk[104 * 2] = 423f
        lmk[104 * 2 + 1] = 762f // Near mouthY (740)
        lmk[105 * 2] = 478f
        lmk[105 * 2 + 1] = 769f

        // True eye landmarks 38 & 57
        lmk[38 * 2] = 340f
        lmk[38 * 2 + 1] = 455f
        lmk[57 * 2] = 620f
        lmk[57 * 2 + 1] = 455f

        val eyes = PhotoEditorActivity.resolveAnatomicalEyes(
            lmk, null, width, height, noseY, mouthY
        )

        assertTrue("Sanity check must pass", eyes.isSanityPassed)
        assertEquals("Must select LANDMARKS_38_57, never inner mouth", "LANDMARKS_38_57", eyes.source)
        assertEquals(340f, eyes.lx, 0.01f)
        assertEquals(455f, eyes.ly, 0.01f)
        assertEquals(620f, eyes.rx, 0.01f)
        assertEquals(455f, eyes.ry, 0.01f)
        assertTrue("Resolved eyes Y must be well above mouth region", eyes.ly < 500f)
    }

    @Test
    fun testResolveAnatomicalEyes_fallbackToContourAverage() {
        // Points 38 & 57 invalid (below mouth), but eye contour points 62..79 valid
        val lmk = FloatArray(106 * 2) { 0f }

        // Make 38 & 57 invalid
        lmk[38 * 2] = 400f
        lmk[38 * 2 + 1] = 800f
        lmk[57 * 2] = 500f
        lmk[57 * 2 + 1] = 800f

        // Make 70 & 80 invalid
        lmk[70 * 2] = 400f
        lmk[70 * 2 + 1] = 800f
        lmk[80 * 2] = 500f
        lmk[80 * 2 + 1] = 800f

        // Valid left contour 62..69 at X=350, Y=450
        for (i in 62..69) {
            lmk[i * 2] = 350f
            lmk[i * 2 + 1] = 450f
        }
        // Valid right contour 72..79 at X=610, Y=450
        for (i in 72..79) {
            lmk[i * 2] = 610f
            lmk[i * 2 + 1] = 450f
        }

        val eyes = PhotoEditorActivity.resolveAnatomicalEyes(
            lmk, null, width, height, noseY, mouthY
        )

        assertTrue(eyes.isSanityPassed)
        assertEquals("CONTOUR_AVERAGE", eyes.source)
        assertEquals(350f, eyes.lx, 0.01f)
        assertEquals(450f, eyes.ly, 0.01f)
        assertEquals(610f, eyes.rx, 0.01f)
        assertEquals(450f, eyes.ry, 0.01f)
    }

    @Test
    fun testResolveAnatomicalEyes_geometricFallbackWhenAllCorrupt() {
        // All landmarks corrupt or zero
        val lmk = FloatArray(106 * 2) { 0f }

        val eyes = PhotoEditorActivity.resolveAnatomicalEyes(
            lmk, null, width, height, noseY, mouthY
        )

        assertFalse("Sanity check flag is false for geometric fallback", eyes.isSanityPassed)
        assertEquals("GEOMETRIC_FALLBACK", eyes.source)
        assertTrue("Fallback lx must be positive", eyes.lx > 0f)
        assertTrue("Fallback rx must be greater than lx", eyes.rx > eyes.lx)
        assertTrue("Fallback ly must be above nose", eyes.ly < noseY)
        assertTrue("Fallback ly must be above mouth", eyes.ly < mouthY - 30f)
    }

    @Test
    fun testResolveEyebrowAnchors_fromLandmarks33to52() {
        val lmk = FloatArray(106 * 2) { 0f }

        // Left brow points 33..42: Y=400 (above eye at Y=460)
        for (i in 33..42) {
            lmk[i * 2] = 300f + (i - 33) * 10f // X: 300..390 -> avg = 345
            lmk[i * 2 + 1] = 400f
        }
        // Right brow points 43..52: Y=400 (above eye at Y=460)
        for (i in 43..52) {
            lmk[i * 2] = 570f + (i - 43) * 10f // X: 570..660 -> avg = 615
            lmk[i * 2 + 1] = 400f
        }

        val brows = PhotoEditorActivity.resolveEyebrowAnchors(
            lmk, lxEye = 345f, lyEye = 460f, rxEye = 615f, ryEye = 460f,
            imgWidth = width, imgHeight = height
        )

        assertTrue("Valid eyebrows must pass sanity", brows.isSanityPassed)
        assertEquals("LANDMARKS_33_52", brows.source)
        assertEquals(345f, brows.lx, 0.01f)
        assertEquals(400f, brows.ly, 0.01f)
        assertEquals(615f, brows.rx, 0.01f)
        assertEquals(400f, brows.ry, 0.01f)
        assertTrue("Eyebrows must be strictly above eyes", brows.ly < 460f && brows.ry < 460f)
    }

    @Test
    fun testResolveEyebrowAnchors_rejectsEyebrowBelowEyes() {
        val lmk = FloatArray(106 * 2) { 0f }

        // Corrupted brow landmarks below eye line (e.g. Y=500 when eye is at Y=460)
        for (i in 33..42) {
            lmk[i * 2] = 345f
            lmk[i * 2 + 1] = 500f
        }
        for (i in 43..52) {
            lmk[i * 2] = 615f
            lmk[i * 2 + 1] = 500f
        }

        val brows = PhotoEditorActivity.resolveEyebrowAnchors(
            lmk, lxEye = 345f, lyEye = 460f, rxEye = 615f, ryEye = 460f,
            imgWidth = width, imgHeight = height
        )

        assertFalse("Corrupt brow below eye must fail sanity", brows.isSanityPassed)
        assertEquals("EYE_RELATIVE_FALLBACK", brows.source)
        // Fallback anchors eyebrow safely above eye
        assertTrue("Eyebrows must be anchored above eye", brows.ly < 460f && brows.ry < 460f)
        assertEquals(345f, brows.lx, 0.01f)
        assertEquals(615f, brows.rx, 0.01f)
    }

    @Test
    fun testDeviceSuite104Features_eyeAndBrowIntegrity() {
        val suite = PhotoEditorActivity.DEVICE_SUITE_104_FEATURES

        // Verify all 22 eye tools are present in MOD_01
        val eyeTools = suite.filter { it.moduleId == "MOD_01" }
        assertEquals("MOD_01 must contain exactly 22 eye features", 22, eyeTools.size)
        val eyeFeatureIds = eyeTools.map { it.featureId }.toSet()
        for (i in 1..22) {
            val expectedId = String.format(java.util.Locale.US, "EYE_%02d", i)
            assertTrue("Must contain $expectedId", eyeFeatureIds.contains(expectedId))
        }

        // Verify all 6 eyebrow tools are present in MOD_02
        val browTools = suite.filter { it.moduleId == "MOD_02" }
        assertEquals("MOD_02 must contain exactly 6 eyebrow features", 6, browTools.size)
        val browFeatureIds = browTools.map { it.featureId }.toSet()
        for (i in 1..6) {
            val expectedId = String.format(java.util.Locale.US, "BROW_%02d", i)
            assertTrue("Must contain $expectedId", browFeatureIds.contains(expectedId))
        }

        // Verify tool IDs
        assertEquals("tool_brow_density", browTools.find { it.featureId == "BROW_01" }?.toolId)
        assertEquals("tool_brow_thickness", browTools.find { it.featureId == "BROW_02" }?.toolId)
        assertEquals("tool_brow_arch", browTools.find { it.featureId == "BROW_03" }?.toolId)
        assertEquals("tool_3dmm_brow_height", browTools.find { it.featureId == "BROW_04" }?.toolId)
        assertEquals("tool_3dmm_brow_shape", browTools.find { it.featureId == "BROW_05" }?.toolId)
        assertEquals("tool_brow_color_black", browTools.find { it.featureId == "BROW_06" }?.toolId)
    }
}
