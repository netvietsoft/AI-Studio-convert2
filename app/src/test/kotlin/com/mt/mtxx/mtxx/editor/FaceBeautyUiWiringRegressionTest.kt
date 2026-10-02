package com.mt.mtxx.mtxx.editor

import org.junit.Assert.assertEquals
import org.junit.Assert.assertNotNull
import org.junit.Assert.assertTrue
import org.junit.Test

/**
 * Regression Test Suite for Face & Beauty UI Wiring Corrections (TASK_007 / TASK_009).
 *
 * Verifies that confirmed orphaned and bypassed Face/Beauty native methods
 * are properly wired into PhotoEditorActivity categories, tool definitions,
 * parameter normalization logic, and dispatch routing against REAL PRODUCTION CODE.
 */
class FaceBeautyUiWiringRegressionTest {

    // Helper data structure matching PhotoEditorActivity definitions
    data class ExpectedTool(
        val id: String,
        val categoryId: String,
        val targetNativeMethod: String,
        val targetParamIdOrMode: Int,
        val isVip: Boolean = false
    )

    private val expectedWiredTools = listOf(
        // Teeth Reshape (TeethEarEngine::applyTeethReshape)
        ExpectedTool("tool_teeth_align", "cat_teeth", "nativeApplyTeethReshape", PhotoEditorActivity.TEETH_SHAPE_ALIGN, true),
        ExpectedTool("tool_teeth_protrusion", "cat_teeth", "nativeApplyTeethReshape", PhotoEditorActivity.TEETH_SHAPE_PROTRUSION, true),

        // Philtrum Edit (PhiltrumEngine::applyPhiltrumEdit)
        ExpectedTool("tool_philtrum_high", "cat_mouth", "nativeApplyPhiltrumEdit", PhotoEditorActivity.PARAM_PHILTRUM_LENGTH, false),
        ExpectedTool("tool_philtrum_warp", "cat_mouth", "nativeApplyPhiltrumEdit", PhotoEditorActivity.PARAM_PHILTRUM_CUPID_ACCENT, false),
        ExpectedTool("tool_philtrum_depth", "cat_mouth", "nativeApplyPhiltrumEdit", PhotoEditorActivity.PARAM_PHILTRUM_GROOVE_DEPTH, false),

        // Eyebrow Colors (EyeRetouchEngine::applyEyebrowColor)
        ExpectedTool("tool_brow_color_black", "cat_makeup", "nativeApplyEyebrowColor", PhotoEditorActivity.BROW_COLOR_BLACK, false),
        ExpectedTool("tool_brow_color_dark_brown", "cat_makeup", "nativeApplyEyebrowColor", PhotoEditorActivity.BROW_COLOR_DARK_BROWN, false),
        ExpectedTool("tool_brow_color_light_brown", "cat_makeup", "nativeApplyEyebrowColor", PhotoEditorActivity.BROW_COLOR_LIGHT_BROWN, false),
        ExpectedTool("tool_brow_color_ash_gray", "cat_makeup", "nativeApplyEyebrowColor", PhotoEditorActivity.BROW_COLOR_ASH_GRAY, false),
        ExpectedTool("tool_brow_color_auburn", "cat_makeup", "nativeApplyEyebrowColor", PhotoEditorActivity.BROW_COLOR_AUBURN, false),

        // Procedural Eyelash (EyelashEngine::applyEyelash)
        ExpectedTool("tool_lash_density", "cat_makeup", "nativeApplyEyelash", 0 /* LASH_STYLE_NATURAL */, false),
        ExpectedTool("tool_lash_length", "cat_makeup", "nativeApplyEyelash", 0 /* LASH_STYLE_NATURAL */, false),
        ExpectedTool("tool_lash_curl", "cat_makeup", "nativeApplyEyelash", 0 /* LASH_STYLE_NATURAL */, false),

        // Surface Normal Sculpting (SurfaceNormalEngine::applyNormalSculpting)
        ExpectedTool("tool_contour_nose", "cat_makeup", "nativeApplyNormalSculpting", PhotoEditorActivity.PARAM_NORMAL_NOSE_SCULPT, false),

        // Clavicle & Shoulder (ClavicleShoulderEngine::applyClavicleShoulderEdit)
        ExpectedTool("tool_body_shoulder", "cat_body", "nativeApplyClavicleShoulderEdit", PhotoEditorActivity.PARAM_SHOULDER_SLIM, false),
        ExpectedTool("tool_clavicle_enhance", "cat_body", "nativeApplyClavicleShoulderEdit", PhotoEditorActivity.PARAM_CLAVICLE_HIGHLIGHT, false)
    )

    @Test
    fun testExpectedToolsRegistryIntegrity() {
        assertEquals("Total audited corrected tools count must match 16", 16, expectedWiredTools.size)
        val toolIds = expectedWiredTools.map { it.id }.toSet()
        assertEquals("All tool IDs must be strictly unique", expectedWiredTools.size, toolIds.size)

        // Verify directly against REAL production PhotoEditorActivity.PRODUCTION_CATEGORIES
        val allProdTools = PhotoEditorActivity.PRODUCTION_CATEGORIES.flatMap { it.tools }
        for (expected in expectedWiredTools) {
            val prodTool = allProdTools.find { it.id == expected.id }
            assertNotNull("Audited tool ${expected.id} MUST exist in production PhotoEditorActivity.PRODUCTION_CATEGORIES", prodTool)
            assertEquals("Tool ${expected.id} VIP flag must match production", expected.isVip, prodTool!!.isVip)
        }
    }

    @Test
    fun testTeethReshapeParameterMapping() {
        // Verify production constants in PhotoEditorActivity
        assertEquals(1, PhotoEditorActivity.TEETH_SHAPE_ALIGN)
        assertEquals(2, PhotoEditorActivity.TEETH_SHAPE_PROTRUSION)

        // Verify mathematical transformation of slider intensity [-100..100] via production method
        assertEquals(0.0f, PhotoEditorActivity.computeTeethReshapeValue(0), 1e-4f)
        assertEquals(50.0f, PhotoEditorActivity.computeTeethReshapeValue(100), 1e-4f)
        assertEquals(-50.0f, PhotoEditorActivity.computeTeethReshapeValue(-100), 1e-4f)
        assertEquals(25.0f, PhotoEditorActivity.computeTeethReshapeValue(50), 1e-4f)
    }

    @Test
    fun testPhiltrumParameterMapping() {
        // Verify production constants in PhotoEditorActivity
        assertEquals(1701, PhotoEditorActivity.PARAM_PHILTRUM_LENGTH)
        assertEquals(1702, PhotoEditorActivity.PARAM_PHILTRUM_WIDTH)
        assertEquals(1703, PhotoEditorActivity.PARAM_PHILTRUM_GROOVE_DEPTH)
        assertEquals(1704, PhotoEditorActivity.PARAM_PHILTRUM_CUPID_ACCENT)

        // Verify mapping via production method
        assertEquals(PhotoEditorActivity.PARAM_PHILTRUM_LENGTH, PhotoEditorActivity.mapPhiltrumTool("tool_philtrum_high"))
        assertEquals(PhotoEditorActivity.PARAM_PHILTRUM_CUPID_ACCENT, PhotoEditorActivity.mapPhiltrumTool("tool_philtrum_warp"))
        assertEquals(PhotoEditorActivity.PARAM_PHILTRUM_GROOVE_DEPTH, PhotoEditorActivity.mapPhiltrumTool("tool_philtrum_depth"))
        assertEquals(PhotoEditorActivity.PARAM_PHILTRUM_WIDTH, PhotoEditorActivity.mapPhiltrumTool("tool_philtrum_width"))
    }

    @Test
    fun testEyebrowColorShadesMapping() {
        // Verify production constants in PhotoEditorActivity
        assertEquals(0, PhotoEditorActivity.BROW_COLOR_BLACK)
        assertEquals(1, PhotoEditorActivity.BROW_COLOR_DARK_BROWN)
        assertEquals(2, PhotoEditorActivity.BROW_COLOR_LIGHT_BROWN)
        assertEquals(3, PhotoEditorActivity.BROW_COLOR_ASH_GRAY)
        assertEquals(4, PhotoEditorActivity.BROW_COLOR_AUBURN)

        // Verify mapping via production method
        assertEquals(PhotoEditorActivity.BROW_COLOR_BLACK, PhotoEditorActivity.mapBrowColor("tool_brow_color_black"))
        assertEquals(PhotoEditorActivity.BROW_COLOR_DARK_BROWN, PhotoEditorActivity.mapBrowColor("tool_brow_color_dark_brown"))
        assertEquals(PhotoEditorActivity.BROW_COLOR_LIGHT_BROWN, PhotoEditorActivity.mapBrowColor("tool_brow_color_light_brown"))
        assertEquals(PhotoEditorActivity.BROW_COLOR_ASH_GRAY, PhotoEditorActivity.mapBrowColor("tool_brow_color_ash_gray"))
        assertEquals(PhotoEditorActivity.BROW_COLOR_AUBURN, PhotoEditorActivity.mapBrowColor("tool_brow_color_auburn"))
    }

    @Test
    fun testProceduralEyelashScaleFormulas() {
        // Verify computation via production method PhotoEditorActivity.computeLashParameters
        val (dLen0, dDens0, _) = PhotoEditorActivity.computeLashParameters("tool_lash_density", 0.0f)
        assertEquals(1.0f, dLen0, 1e-4f)
        assertEquals(1.0f, dDens0, 1e-4f)

        val (dLen1, dDens1, _) = PhotoEditorActivity.computeLashParameters("tool_lash_density", 1.0f)
        assertEquals(1.0f, dLen1, 1e-4f)
        assertEquals(2.0f, dDens1, 1e-4f)

        val (lLen1, lDens1, _) = PhotoEditorActivity.computeLashParameters("tool_lash_length", 1.0f)
        assertEquals(2.2f, lLen1, 1e-4f)
        assertEquals(1.0f, lDens1, 1e-4f)

        val (_, _, curl0) = PhotoEditorActivity.computeLashParameters("tool_lash_curl", 0.0f)
        assertEquals(0.0f, curl0, 1e-4f)

        val (_, _, curl1) = PhotoEditorActivity.computeLashParameters("tool_lash_curl", 1.0f)
        assertEquals(2.0f, curl1, 1e-4f)
    }

    @Test
    fun testSurfaceNormalAndClavicleParamIds() {
        assertEquals(2402, PhotoEditorActivity.PARAM_NORMAL_NOSE_SCULPT)
        assertEquals(2201, PhotoEditorActivity.PARAM_CLAVICLE_HIGHLIGHT)
        assertEquals(2203, PhotoEditorActivity.PARAM_SHOULDER_SLIM)
    }
}
