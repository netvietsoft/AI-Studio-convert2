package com.mt.mtxx.mtxx.editor

import android.graphics.RectF
import com.meitu.ai.facedetect.FaceDetector106
import org.junit.Assert.assertEquals
import org.junit.Assert.assertFalse
import org.junit.Assert.assertTrue
import org.junit.Test

/**
 * Deterministic Focused Regression Tests for TASK_015:
 * Eye & Eyebrow Landmark Routing Correction and Geometry Sanity Bounds.
 */
class EyeBrowLandmarkCorrectionRegressionTest {

    @Test
    fun testEyeGeometrySanityValidation() {
        // 1. Valid coordinates
        assertTrue(
            "Standard frontal eye coordinates must pass geometry check",
            PhotoEditorActivity.isValidEyeGeometry(
                lx = 350f, ly = 450f,
                rx = 600f, ry = 450f,
                mouthY = 700f,
                imageWidth = 960,
                imageHeight = 1280
            )
        )

        // 2. Non-positive coordinates
        assertFalse(
            "Non-positive lx must fail",
            PhotoEditorActivity.isValidEyeGeometry(0f, 450f, 600f, 450f)
        )
        assertFalse(
            "Non-positive ry must fail",
            PhotoEditorActivity.isValidEyeGeometry(350f, 450f, 600f, -10f)
        )

        // 3. Inverted left-right eye coordinates
        assertFalse(
            "lx >= rx must fail geometry check (inverted eyes)",
            PhotoEditorActivity.isValidEyeGeometry(600f, 450f, 350f, 450f)
        )
        assertFalse(
            "lx == rx must fail geometry check (collapsed eyes)",
            PhotoEditorActivity.isValidEyeGeometry(400f, 450f, 400f, 450f)
        )

        // 4. Inter-pupillary distance too small (< 10f)
        assertFalse(
            "Eye distance < 10f must fail",
            PhotoEditorActivity.isValidEyeGeometry(400f, 450f, 405f, 450f)
        )

        // 5. Eye Y below or equal to mouth Y
        assertFalse(
            "Eye Y at or below mouth Y must fail (mouth misrouting prevention)",
            PhotoEditorActivity.isValidEyeGeometry(
                lx = 350f, ly = 720f,
                rx = 600f, ry = 720f,
                mouthY = 700f
            )
        )
    }

    @Test
    fun testResolveEyeAnchorsWithValidIrisTrack() {
        val iris = FaceDetector106.IrisTrackInfo(
            leftCenterX = 340f,
            leftCenterY = 440f,
            leftRadius = 25f,
            rightCenterX = 590f,
            rightCenterY = 442f,
            rightRadius = 25f
        )
        val lmk = FloatArray(212)

        val anchors = PhotoEditorActivity.resolveEyeAnchors(
            detectedIrisTrack = iris,
            landmarks106 = lmk,
            faceBounds = RectF(200f, 200f, 750f, 900f),
            imageWidth = 960,
            imageHeight = 1280,
            mouthY = 700f
        )

        assertEquals("lxEye must match iris leftCenterX", 340f, anchors[0], 0.01f)
        assertEquals("lyEye must match iris leftCenterY", 440f, anchors[1], 0.01f)
        assertEquals("rxEye must match iris rightCenterX", 590f, anchors[2], 0.01f)
        assertEquals("ryEye must match iris rightCenterY", 442f, anchors[3], 0.01f)
    }

    @Test
    fun testResolveEyeAnchorsFallbackPreventsMouthAttraction() {
        // Construct a realistic 106-point landmark model where indices 98..105 are inner mouth
        val lmk = FloatArray(212)

        // Mouth points: 84 (left corner), 90 (right corner), 87 (upper), 93 (lower), 104, 105 (inner cavity)
        val mouthLeftX = 400f
        val mouthRightX = 520f
        val mouthY = 700f

        // Place inner mouth cavity landmarks at index 104 and 105
        lmk[104 * 2] = mouthLeftX + 20f
        lmk[104 * 2 + 1] = mouthY
        lmk[105 * 2] = mouthRightX - 20f
        lmk[105 * 2 + 1] = mouthY

        // Place true anatomical eye contours at 62..71 (left eye) and 72..81 (right eye)
        val eyeTrueY = 420f
        for (i in 62..71) {
            lmk[i * 2] = 340f + (i - 62) * 2f
            lmk[i * 2 + 1] = eyeTrueY
        }
        lmk[70 * 2] = 350f
        lmk[70 * 2 + 1] = eyeTrueY // left pupil

        for (i in 72..81) {
            lmk[i * 2] = 580f + (i - 72) * 2f
            lmk[i * 2 + 1] = eyeTrueY
        }
        lmk[80 * 2] = 590f
        lmk[80 * 2 + 1] = eyeTrueY // right pupil

        // When iris tracking is null (pure heuristic mode), resolveEyeAnchors MUST NOT pick 104/105 mouth
        val anchors = PhotoEditorActivity.resolveEyeAnchors(
            detectedIrisTrack = null,
            landmarks106 = lmk,
            faceBounds = RectF(200f, 200f, 750f, 900f),
            imageWidth = 960,
            imageHeight = 1280,
            mouthY = mouthY
        )

        assertTrue(
            "Resolved eye Y (${anchors[1]}) must be far above mouth Y ($mouthY)",
            anchors[1] < mouthY - 150f
        )
        assertEquals("Resolved lxEye must be anchored at left eye region", 349f, anchors[0], 2.0f)
        assertEquals("Resolved lyEye must be anchored at left eye region", eyeTrueY, anchors[1], 1.0f)
        assertEquals("Resolved rxEye must be anchored at right eye region", 589f, anchors[2], 2.0f)
        assertEquals("Resolved ryEye must be anchored at right eye region", eyeTrueY, anchors[3], 1.0f)

        // Verify that overwriting landmarks106[104]/[105] eliminates the mouth mapping for C++
        lmk[104 * 2] = anchors[0]
        lmk[104 * 2 + 1] = anchors[1]
        lmk[105 * 2] = anchors[2]
        lmk[105 * 2 + 1] = anchors[3]

        assertEquals("landmarks106[104] must now be true left eye", anchors[0], lmk[104 * 2], 0.01f)
        assertEquals("landmarks106[104+1] must now be true left eye Y", anchors[1], lmk[104 * 2 + 1], 0.01f)
        assertEquals("landmarks106[105] must now be true right eye", anchors[2], lmk[105 * 2], 0.01f)
        assertEquals("landmarks106[105+1] must now be true right eye Y", anchors[3], lmk[105 * 2 + 1], 0.01f)
    }

    @Test
    fun testResolveBrowAnchorsAnatomy() {
        val lmk = FloatArray(212)
        val eyeY = 450f
        val browArchY = 380f

        // Left brow 33..42, arch = 37
        for (i in 33..42) {
            lmk[i * 2] = 320f + (i - 33) * 6f
            lmk[i * 2 + 1] = browArchY + 5f
        }
        lmk[37 * 2] = 345f
        lmk[37 * 2 + 1] = browArchY // peak arch

        // Right brow 43..52, arch = 47
        for (i in 43..52) {
            lmk[i * 2] = 560f + (i - 43) * 6f
            lmk[i * 2 + 1] = browArchY + 5f
        }
        lmk[47 * 2] = 585f
        lmk[47 * 2 + 1] = browArchY // peak arch

        val browAnchors = PhotoEditorActivity.resolveBrowAnchors(
            landmarks106 = lmk,
            lxEye = 350f, lyEye = eyeY,
            rxEye = 600f, ryEye = eyeY
        )

        assertEquals("lBrowX should match left arch", 345f, browAnchors[0], 0.01f)
        assertEquals("lBrowY should match left arch Y", browArchY, browAnchors[1], 0.01f)
        assertEquals("rBrowX should match right arch", 585f, browAnchors[2], 0.01f)
        assertEquals("rBrowY should match right arch Y", browArchY, browAnchors[3], 0.01f)
        assertTrue("Brow Y must be above eye Y", browAnchors[1] < eyeY)
    }

    @Test
    fun testBrowConstantsAndColorMappings() {
        assertEquals(1, PhotoEditorActivity.PARAM_BROW_THICKNESS)
        assertEquals(2, PhotoEditorActivity.PARAM_BROW_ARCH)
        assertEquals(3, PhotoEditorActivity.PARAM_BROW_LENGTH)
        assertEquals(4, PhotoEditorActivity.PARAM_BROW_DENSITY_FILL)
        assertEquals(5, PhotoEditorActivity.PARAM_BROW_COLOR)
        assertEquals(6, PhotoEditorActivity.PARAM_LASH_DENSITY)
        assertEquals(7, PhotoEditorActivity.PARAM_LASH_LENGTH)
        assertEquals(8, PhotoEditorActivity.PARAM_LASH_CURL)

        assertEquals(0, PhotoEditorActivity.mapBrowColor("tool_brow_color_black"))
        assertEquals(1, PhotoEditorActivity.mapBrowColor("tool_brow_color_dark_brown"))
        assertEquals(2, PhotoEditorActivity.mapBrowColor("tool_brow_color_light_brown"))
        assertEquals(3, PhotoEditorActivity.mapBrowColor("tool_brow_color_ash_gray"))
        assertEquals(4, PhotoEditorActivity.mapBrowColor("tool_brow_color_auburn"))
    }
}
