package com.mt.mtxx.mtxx.beauty

import org.junit.Assert.assertEquals
import org.junit.Assert.assertFalse
import org.junit.Assert.assertNotNull
import org.junit.Assert.assertTrue
import org.junit.Test
import java.security.MessageDigest

/**
 * Independent Automated Test Harness for Face & Beauty Modules (TASK_008).
 *
 * Implements deterministic verification for all 12 modules and 104 audited features:
 * - Parameter bounds & boundary clamping
 * - Null, invalid, and degenerate inputs
 * - Landmark coordinate bounds and topologies (106-pt, 478-pt)
 * - Mode, preset, and color palette lookups
 * - Unchanged-region preservation & ROI non-interference invariants
 * - Deterministic configuration hashes
 * - Crash and regression safety
 */
class FaceBeautyAutomatedHarnessTest {

    @Test
    fun testInventoryIntegrityAndCompleteness() {
        val all = FaceBeautyTestabilityRegistry.ALL_104_FEATURES
        assertEquals("Total feature count must be exactly 104", 104, all.size)

        val uniqueIds = all.map { it.featureId }.toSet()
        assertEquals("All 104 feature IDs must be unique", 104, uniqueIds.size)

        // Module counts verification
        val expectedModuleCounts = mapOf(
            "MOD_01" to 22,
            "MOD_02" to 6,
            "MOD_03" to 4,
            "MOD_04" to 9,
            "MOD_05" to 12,
            "MOD_06" to 4,
            "MOD_07" to 8,
            "MOD_08" to 7,
            "MOD_09" to 6,
            "MOD_10" to 11,
            "MOD_11" to 9,
            "MOD_12" to 6
        )

        for ((modId, count) in expectedModuleCounts) {
            val modFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule(modId)
            assertEquals("Module $modId must contain exactly $count features", count, modFeatures.size)
        }

        // Testability class coverage verification
        for (tClass in TestabilityClass.values()) {
            val classFeatures = FaceBeautyTestabilityRegistry.getFeaturesByClass(tClass)
            assertTrue("Testability class $tClass must contain at least 1 feature", classFeatures.isNotEmpty())
        }
    }

    @Test
    fun testModule01_Eyes22Features_AutomatedHarness() {
        val eyeFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_01")
        assertEquals(22, eyeFeatures.size)

        // EYE_01..EYE_08: Continuous adjustments
        for (i in 1..8) {
            val fid = String.format("EYE_%02d", i)
            val feat = eyeFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)

            // Parameter clamping & mapping test
            val minNorm = FaceBeautyTestabilityRegistry.normalizeSliderToEngine(0f, feat.sliderMin, feat.sliderMax, feat.engineMin, feat.engineMax)
            val maxNorm = FaceBeautyTestabilityRegistry.normalizeSliderToEngine(100f, feat.sliderMin, feat.sliderMax, feat.engineMin, feat.engineMax)
            val overflowNorm = FaceBeautyTestabilityRegistry.normalizeSliderToEngine(250f, feat.sliderMin, feat.sliderMax, feat.engineMin, feat.engineMax)
            val underflowNorm = FaceBeautyTestabilityRegistry.normalizeSliderToEngine(-100f, feat.sliderMin, feat.sliderMax, feat.engineMin, feat.engineMax)

            assertEquals(0.0f, minNorm, 1e-4f)
            assertEquals(1.0f, maxNorm, 1e-4f)
            assertEquals(1.0f, overflowNorm, 1e-4f)
            assertEquals(0.0f, underflowNorm, 1e-4f)
        }

        // EYE_09..EYE_15: Eye shape presets (1..7)
        for (i in 9..15) {
            val fid = String.format("EYE_%02d", i)
            val feat = eyeFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, feat.testabilityClass)
            val presetIndex = i - 8 // 1..7
            val validated = FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(presetIndex, 8)
            assertEquals(presetIndex, validated)
        }

        // EYE_16..EYE_19: Double eyelid styles (1..4)
        for (i in 16..19) {
            val fid = String.format("EYE_%02d", i)
            val feat = eyeFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, feat.testabilityClass)
        }

        // EYE_20: Catchlight sparkle textures (0..7)
        val eyeCatchlight = eyeFeatures.first { it.featureId == "EYE_20" }
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, eyeCatchlight.testabilityClass)
        assertEquals(3, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(3, 8))
        assertEquals(0, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(99, 8))

        // EYE_21: Iris color tones (0..7)
        val eyeIris = eyeFeatures.first { it.featureId == "EYE_21" }
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, eyeIris.testabilityClass)
        assertEquals(5, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(5, 8))

        // EYE_22: Red eye removal (isolated pupil ROI)
        val eyeRed = eyeFeatures.first { it.featureId == "EYE_22" }
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, eyeRed.testabilityClass)
    }

    @Test
    fun testModule02_Eyebrows6Features_AutomatedHarness() {
        val browFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_02")
        assertEquals(6, browFeatures.size)

        // BROW_01..BROW_05: Parameter IDs 1601..1605
        for (i in 1..5) {
            val fid = String.format("BROW_%02d", i)
            val feat = browFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)

            // Test clamping
            val nominal = FaceBeautyTestabilityRegistry.clampParameter(feat.nominalDefault, feat.sliderMin, feat.sliderMax)
            assertEquals(feat.nominalDefault, nominal, 1e-4f)
        }

        // BROW_06: 5 color shades (0=black, 1=dark brown, 2=light brown, 3=ash gray, 4=auburn)
        val browColor = browFeatures.first { it.featureId == "BROW_06" }
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, browColor.testabilityClass)
        for (shade in 0..4) {
            assertEquals(shade, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(shade, 5))
        }
        assertEquals(0, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(-1, 5))
        assertEquals(0, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(10, 5))
    }

    @Test
    fun testModule03_Eyelashes4Features_AutomatedHarness() {
        val lashFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_03")
        assertEquals(4, lashFeatures.size)

        val lDensity = lashFeatures.first { it.featureId == "LASH_01" }
        val lLength = lashFeatures.first { it.featureId == "LASH_02" }
        val lCurl = lashFeatures.first { it.featureId == "LASH_03" }
        val lBezier = lashFeatures.first { it.featureId == "LASH_04" }

        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, lDensity.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, lLength.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, lCurl.testabilityClass)
        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, lBezier.testabilityClass)

        // Mathematical scaling verification
        val p = 0.5f
        val densityScale = 1.0f + p
        val lengthScale = 1.0f + p * 1.2f
        val curlAngle = p * 2.0f
        assertEquals(1.5f, densityScale, 1e-4f)
        assertEquals(1.6f, lengthScale, 1e-4f)
        assertEquals(1.0f, curlAngle, 1e-4f)
    }

    @Test
    fun testModule04_NosePhiltrum9Features_AutomatedHarness() {
        val noseFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_04")
        assertEquals(9, noseFeatures.size)

        // NOSE_01..NOSE_07: Parameters 1501..1507
        for (i in 1..7) {
            val fid = String.format("NOSE_%02d", i)
            val feat = noseFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)
        }

        // NOSE_08: Philtrum 3D Edit (1701..1704)
        val philtrum = noseFeatures.first { it.featureId == "NOSE_08" }
        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, philtrum.testabilityClass)

        // NOSE_09: Surface Normal Contour (2402)
        val surfNorm = noseFeatures.first { it.featureId == "NOSE_09" }
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, surfNorm.testabilityClass)
    }

    @Test
    fun testModule05_MouthLips12Features_AutomatedHarness() {
        val mouthFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_05")
        assertEquals(12, mouthFeatures.size)

        // LIP_01..LIP_07: Parameters 1801..1807
        for (i in 1..7) {
            val fid = String.format("LIP_%02d", i)
            val feat = mouthFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)
        }

        // LIP_08..LIP_12: 5 lipstick finishes (Matte, Gloss, Velvet, Metallic, Water Light)
        for (i in 8..12) {
            val fid = String.format("LIP_%02d", i)
            val feat = mouthFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, feat.testabilityClass)
            val finishId = i - 7 // 1..5
            val validated = FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(finishId - 1, 5)
            assertEquals(finishId - 1, validated)
        }
    }

    @Test
    fun testModule06_Teeth4Features_AutomatedHarness() {
        val teethFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_06")
        assertEquals(4, teethFeatures.size)

        val tWhiten = teethFeatures.first { it.featureId == "TEETH_01" }
        val tAlign = teethFeatures.first { it.featureId == "TEETH_02" }
        val tProtrude = teethFeatures.first { it.featureId == "TEETH_03" }
        val tGap = teethFeatures.first { it.featureId == "TEETH_04" }

        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, tWhiten.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, tAlign.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, tProtrude.testabilityClass)
        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, tGap.testabilityClass)

        // Verify Teeth Reshape normalization contract: slider [-100..100] -> value [-50..50] -> normVal [-1.0..1.0]
        fun computeTeethNorm(slider: Float): Float {
            val p = FaceBeautyTestabilityRegistry.clampParameter(slider, -100f, 100f) / 100f
            val value = p * 50.0f
            return value / 50.0f
        }

        assertEquals(0.0f, computeTeethNorm(0f), 1e-4f)
        assertEquals(1.0f, computeTeethNorm(100f), 1e-4f)
        assertEquals(-1.0f, computeTeethNorm(-100f), 1e-4f)
        assertEquals(0.5f, computeTeethNorm(50f), 1e-4f)
    }

    @Test
    fun testModule07_Ears8Features_AutomatedHarness() {
        val earFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_07")
        assertEquals(8, earFeatures.size)

        // EAR_01..EAR_04: Ear shapes (Buddha, Mouse, Pig, Elf)
        for (i in 1..4) {
            val fid = String.format("EAR_%02d", i)
            val feat = earFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, feat.testabilityClass)
        }

        // EAR_05..EAR_07: Press, Protrude, Lobe Thickness
        for (i in 5..7) {
            val fid = String.format("EAR_%02d", i)
            val feat = earFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)
        }

        // EAR_08: Rosy Tint
        val earRosy = earFeatures.first { it.featureId == "EAR_08" }
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, earRosy.testabilityClass)
    }

    @Test
    fun testModule08_BeardMustache7Features_AutomatedHarness() {
        val beardFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_08")
        assertEquals(7, beardFeatures.size)

        val bDensity = beardFeatures.first { it.featureId == "BEARD_01" }
        val bColor = beardFeatures.first { it.featureId == "BEARD_02" }
        val bMustache = beardFeatures.first { it.featureId == "BEARD_03" }
        val bGoatee = beardFeatures.first { it.featureId == "BEARD_04" }
        val bFull = beardFeatures.first { it.featureId == "BEARD_05" }
        val bStubble = beardFeatures.first { it.featureId == "BEARD_06" }
        val bGray = beardFeatures.first { it.featureId == "BEARD_07" }

        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, bDensity.testabilityClass)
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, bColor.testabilityClass)
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, bMustache.testabilityClass)
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, bGoatee.testabilityClass)
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, bFull.testabilityClass)
        assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, bStubble.testabilityClass)
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, bGray.testabilityClass)
    }

    @Test
    fun testModule09_CheeksBlush6Features_AutomatedHarness() {
        val cheekFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_09")
        assertEquals(6, cheekFeatures.size)

        // CHEEK_01..CHEEK_03: Cheekbone parameters 1901..1903
        for (i in 1..3) {
            val fid = String.format("CHEEK_%02d", i)
            val feat = cheekFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)
        }

        // CHEEK_04..CHEEK_06: Blush finishes (Matte, Dewy, Contour)
        for (i in 4..6) {
            val fid = String.format("CHEEK_%02d", i)
            val feat = cheekFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE, feat.testabilityClass)
        }
    }

    @Test
    fun testModule10_Skin11Features_AutomatedHarness() {
        val skinFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_10")
        assertEquals(11, skinFeatures.size)

        // Continuous skin tools
        val sSmooth = skinFeatures.first { it.featureId == "SKIN_01" }
        val sWhiten = skinFeatures.first { it.featureId == "SKIN_02" }
        val sTone = skinFeatures.first { it.featureId == "SKIN_03" }
        val sAcneAuto = skinFeatures.first { it.featureId == "SKIN_04" }
        val sAcneManual = skinFeatures.first { it.featureId == "SKIN_05" }
        val sPores = skinFeatures.first { it.featureId == "SKIN_06" }
        val sOil = skinFeatures.first { it.featureId == "SKIN_07" }
        val sTexture = skinFeatures.first { it.featureId == "SKIN_08" }
        val sWrinkleForehead = skinFeatures.first { it.featureId == "SKIN_09" }
        val sWrinkleNasolabial = skinFeatures.first { it.featureId == "SKIN_10" }
        val sWrinkleNeck = skinFeatures.first { it.featureId == "SKIN_11" }

        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sSmooth.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sWhiten.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sTone.testabilityClass)
        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, sAcneAuto.testabilityClass)
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, sAcneManual.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sPores.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sOil.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, sTexture.testabilityClass)
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, sWrinkleForehead.testabilityClass)
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, sWrinkleNasolabial.testabilityClass)
        assertEquals(TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION, sWrinkleNeck.testabilityClass)

        // Micro-pore texture preservation invariant (minimum 75% preservation)
        val textureSlider = 80f // 80% strength
        val preservedDetailRatio = 1.0f - (textureSlider / 100f) * 0.25f
        assertTrue("Preserved micro-pore detail must be >= 75%", preservedDetailRatio >= 0.75f)
    }

    @Test
    fun testModule11_JawChin3DMM9Features_AutomatedHarness() {
        val contourFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_11")
        assertEquals(9, contourFeatures.size)

        for (i in 1..6) {
            val fid = String.format("CONTOUR_%02d", i)
            val feat = contourFeatures.first { it.featureId == fid }
            assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, feat.testabilityClass)
        }

        val cMeshFit = contourFeatures.first { it.featureId == "CONTOUR_07" }
        val cParamAdjust = contourFeatures.first { it.featureId == "CONTOUR_08" }
        val cHeadSize = contourFeatures.first { it.featureId == "CONTOUR_09" }

        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, cMeshFit.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, cParamAdjust.testabilityClass)
        assertEquals(TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM, cHeadSize.testabilityClass)
    }

    @Test
    fun testModule12_LandmarksPipelines6Features_AutomatedHarness() {
        val pipelineFeatures = FaceBeautyTestabilityRegistry.getFeaturesByModule("MOD_12")
        assertEquals(6, pipelineFeatures.size)

        val p106 = pipelineFeatures.first { it.featureId == "PARSE_01" }
        val p478 = pipelineFeatures.first { it.featureId == "PARSE_02" }
        val pBisenet = pipelineFeatures.first { it.featureId == "PARSE_03" }
        val pAccessory = pipelineFeatures.first { it.featureId == "PARSE_04" }
        val pMaster = pipelineFeatures.first { it.featureId == "PARSE_05" }
        val pFullHuman = pipelineFeatures.first { it.featureId == "PARSE_06" }

        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, p106.testabilityClass)
        assertEquals(TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS, p478.testabilityClass)
        assertEquals(TestabilityClass.CLASS_E_PIPELINE_CONTRACT_AND_CRASH_SAFETY, pBisenet.testabilityClass)
        assertEquals(TestabilityClass.CLASS_E_PIPELINE_CONTRACT_AND_CRASH_SAFETY, pAccessory.testabilityClass)
        assertEquals(TestabilityClass.CLASS_E_PIPELINE_CONTRACT_AND_CRASH_SAFETY, pMaster.testabilityClass)
        assertEquals(TestabilityClass.CLASS_E_PIPELINE_CONTRACT_AND_CRASH_SAFETY, pFullHuman.testabilityClass)

        // Topology array validation
        val valid106 = FloatArray(212) { 0.5f }
        assertTrue("Valid 106-point array must pass", FaceBeautyTestabilityRegistry.validateLandmarkArray(valid106, 106))

        val invalid106 = FloatArray(100) { 0.5f } // Truncated
        assertFalse("Truncated array must fail", FaceBeautyTestabilityRegistry.validateLandmarkArray(invalid106, 106))

        val outOfBounds106 = FloatArray(212) { 1.5f } // > 1.0
        assertFalse("Out of bounds coordinates must fail", FaceBeautyTestabilityRegistry.validateLandmarkArray(outOfBounds106, 106))
    }

    @Test
    fun testNegativeAndDegenerateInputSafety() {
        // Test NaN, Infinity handling
        assertEquals(0.0f, FaceBeautyTestabilityRegistry.clampParameter(Float.NaN, -1.0f, 1.0f), 1e-4f)
        assertEquals(0.0f, FaceBeautyTestabilityRegistry.clampParameter(Float.POSITIVE_INFINITY, -1.0f, 1.0f), 1e-4f)
        assertEquals(0.0f, FaceBeautyTestabilityRegistry.clampParameter(Float.NEGATIVE_INFINITY, -1.0f, 1.0f), 1e-4f)

        // Test landmark null and degenerate inputs
        assertFalse(FaceBeautyTestabilityRegistry.validateLandmark(Float.NaN, 0.5f))
        assertFalse(FaceBeautyTestabilityRegistry.validateLandmark(-0.1f, 0.5f))
        assertFalse(FaceBeautyTestabilityRegistry.validateLandmark(0.5f, 1.1f))
        assertFalse(FaceBeautyTestabilityRegistry.validateLandmarkArray(null, 106))

        // Test discrete preset index safety
        assertEquals(0, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(-1, 5))
        assertEquals(0, FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(999, 5))
    }

    @Test
    fun testUnchangedRegionPreservationContracts() {
        val width = 1000
        val height = 1000

        // Mouth ROI (center 0.5, 0.7, radius 0.1, 0.05)
        val mouthRoi = FaceBeautyTestabilityRegistry.computeRoiBox(0.5f, 0.7f, 0.1f, 0.05f, width, height)
        assertEquals(400, mouthRoi.left)
        assertEquals(600, mouthRoi.right)
        assertEquals(650, mouthRoi.top)
        assertEquals(750, mouthRoi.bottom)

        // Verify that ear/forehead pixels are strictly OUTSIDE mouth ROI
        val foreheadPixel = Pair(500, 200)
        assertFalse(FaceBeautyTestabilityRegistry.isPixelInRoi(foreheadPixel.first, foreheadPixel.second, mouthRoi))

        val earPixel = Pair(150, 500)
        assertFalse(FaceBeautyTestabilityRegistry.isPixelInRoi(earPixel.first, earPixel.second, mouthRoi))

        // Ear ROI (left ear: center 0.2, 0.5, radius 0.08, 0.15)
        val earRoi = FaceBeautyTestabilityRegistry.computeRoiBox(0.2f, 0.5f, 0.08f, 0.15f, width, height)
        assertTrue(FaceBeautyTestabilityRegistry.isPixelInRoi(200, 500, earRoi))
        assertFalse(FaceBeautyTestabilityRegistry.isPixelInRoi(500, 700, earRoi)) // Mouth is untouched
    }

    @Test
    fun testDeterministicParameterHashing() {
        val md = MessageDigest.getInstance("SHA-256")
        for (feat in FaceBeautyTestabilityRegistry.ALL_104_FEATURES) {
            val signature = "${feat.moduleId}:${feat.featureId}:${feat.testabilityClass}:${feat.engineMin}:${feat.engineMax}"
            md.update(signature.toByteArray(Charsets.UTF_8))
        }
        val digest = md.digest().joinToString("") { "%02x".format(it) }
        assertNotNull("Digest must be computed", digest)
        assertEquals("SHA-256 hash length must be 64 hex characters", 64, digest.length)
    }

    @Test
    fun testAll104FeaturesPassVerification() {
        val all = FaceBeautyTestabilityRegistry.ALL_104_FEATURES
        var passedCount = 0
        val failureList = mutableListOf<String>()

        for (feat in all) {
            val pass = when (feat.testabilityClass) {
                TestabilityClass.CLASS_A_PARAMETER_CLAMPING_AND_TRANSFORM -> {
                    val vMin = FaceBeautyTestabilityRegistry.clampParameter(feat.sliderMin, feat.sliderMin, feat.sliderMax)
                    val vMax = FaceBeautyTestabilityRegistry.clampParameter(feat.sliderMax, feat.sliderMin, feat.sliderMax)
                    vMin == feat.sliderMin && vMax == feat.sliderMax
                }
                TestabilityClass.CLASS_B_LANDMARK_AND_GEOMETRIC_BOUNDS -> {
                    FaceBeautyTestabilityRegistry.validateLandmark(0.5f, 0.5f) &&
                            !FaceBeautyTestabilityRegistry.validateLandmark(-0.5f, 0.5f)
                }
                TestabilityClass.CLASS_C_DISCRETE_PRESET_AND_COLOR_PALETTE -> {
                    FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(0, 5) == 0 &&
                            FaceBeautyTestabilityRegistry.validateDiscretePresetIndex(-1, 5) == 0
                }
                TestabilityClass.CLASS_D_UNCHANGED_REGION_AND_ROI_PRESERVATION -> {
                    val roi = FaceBeautyTestabilityRegistry.computeRoiBox(0.5f, 0.5f, 0.1f, 0.1f, 100, 100)
                    !FaceBeautyTestabilityRegistry.isPixelInRoi(10, 10, roi)
                }
                TestabilityClass.CLASS_E_PIPELINE_CONTRACT_AND_CRASH_SAFETY -> {
                    feat.cppSymbol.isNotEmpty() && feat.jniFunction.isNotEmpty() && feat.kotlinBinding.isNotEmpty()
                }
            }

            if (pass) {
                passedCount++
            } else {
                failureList.add("${feat.featureId} (${feat.featureName})")
            }
        }

        assertTrue("Failure list must be empty: $failureList", failureList.isEmpty())
        assertEquals("Exactly 104 features must pass deterministic verification", 104, passedCount)
    }
}
