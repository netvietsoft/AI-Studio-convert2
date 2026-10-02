# TASK_015: FOCUSED REGRESSION TEST RESULTS

**Authority:** Chủ tịch Tony (Chairman)  
**Protocol:** CONVERT2_COMMAND_V2  
**Test Suite:** `com.mt.mtxx.mtxx.editor.EyeBrowLandmarkCorrectionRegressionTest`  
**Execution Command:** `./gradlew.bat :app:testDebugUnitTest --no-daemon`  
**Result:** **BUILD SUCCESSFUL — 7/7 TESTS PASSED (0 Failures, 0 Skipped)**

---

## 1. Test Suite Overview

A dedicated regression test suite was constructed at `app/src/test/kotlin/com/mt/mtxx/mtxx/editor/EyeBrowLandmarkCorrectionRegressionTest.kt` to rigorously guard against:
1. Acceptance of lower-face / oral landmarks as eye centers.
2. Inter-ocular distance abnormalities.
3. Inverted eyebrow-to-eye vertical relationships ($Y_{\text{brow}} \ge Y_{\text{eye}}$).
4. Feature catalog omission for MOD_01 (Eyes: 22 features) and MOD_02 (Eyebrows: 6 features).

---

## 2. Test Execution Details

| Test Case Name | Target Behavior | Result | Duration |
| :--- | :--- | :--- | :--- |
| `testResolveAnatomicalEyes_withValidIrisTrack_usesIrisDirectly` | Iris tracker outputs within upper face bounds are adopted directly. | **PASS** | 32 ms |
| `testResolveAnatomicalEyes_whenLandmarks104_105AreInMouth_rejectsMouthAndUsesContourAverage` | Inverted/mouth landmarks at $Y=780$ are rejected; contour average ($Y \approx 495$) is selected. | **PASS** | 14 ms |
| `testResolveAnatomicalEyes_whenAllLandmarksCorrupted_fallsBackToCanonicalGeometricBounds` | When all coordinates violate bounds, falls back to canonical $(0.35W, 0.42H)$ and $(0.65W, 0.42H)$. | **PASS** | 8 ms |
| `testResolveEyebrowAnchors_withValidBrows_acceptsBrowPoints` | Eyebrow landmarks at $Y \approx 420$ (above eye line $Y \approx 495$) are accepted. | **PASS** | 10 ms |
| `testResolveEyebrowAnchors_whenBrowBelowEyeLine_rejectsAndComputesAnatomicalOffsets` | Eyebrows placed below eye line are rejected and corrected via anatomical vector offset. | **PASS** | 9 ms |
| `testEyeContourEyelidPoints_averageWithinEyeRegion` | Eyelid contours 35..42 and 89..96 produce accurate eye centers within tolerance. | **PASS** | 8 ms |
| `testFeatureSuiteItems_eyeAndBrowCoverage` | Full suite coverage verified: 22 eye tools and 6 eyebrow tools present with valid IDs. | **PASS** | 10 ms |

**Total Suite Duration:** 91 ms  
**Aggregate Gradle Task Status:** `BUILD SUCCESSFUL in 1m 2s (120 actionable tasks: 5 executed, 115 up-to-date)`

---

## 3. Verifiable Test Log Excerpt

```
> Task :app:compileDebugKotlin UP-TO-DATE
> Task :app:compileDebugJavaWithJavac NO-SOURCE
> Task :app:processDebugJavaRes UP-TO-DATE
> Task :app:bundleDebugClassesToCompileJar UP-TO-DATE
> Task :app:bundleDebugClassesToRuntimeJar UP-TO-DATE
> Task :app:compileDebugUnitTestKotlin
> Task :app:compileDebugUnitTestJavaWithJavac NO-SOURCE
> Task :app:processDebugUnitTestJavaRes UP-TO-DATE
> Task :app:testDebugUnitTest

EyeBrowLandmarkCorrectionRegressionTest > testResolveAnatomicalEyes_withValidIrisTrack_usesIrisDirectly PASSED
EyeBrowLandmarkCorrectionRegressionTest > testResolveAnatomicalEyes_whenLandmarks104_105AreInMouth_rejectsMouthAndUsesContourAverage PASSED
EyeBrowLandmarkCorrectionRegressionTest > testResolveAnatomicalEyes_whenAllLandmarksCorrupted_fallsBackToCanonicalGeometricBounds PASSED
EyeBrowLandmarkCorrectionRegressionTest > testResolveEyebrowAnchors_withValidBrows_acceptsBrowPoints PASSED
EyeBrowLandmarkCorrectionRegressionTest > testResolveEyebrowAnchors_whenBrowBelowEyeLine_rejectsAndComputesAnatomicalOffsets PASSED
EyeBrowLandmarkCorrectionRegressionTest > testEyeContourEyelidPoints_averageWithinEyeRegion PASSED
EyeBrowLandmarkCorrectionRegressionTest > testFeatureSuiteItems_eyeAndBrowCoverage PASSED

BUILD SUCCESSFUL in 1m 2s
120 actionable tasks: 5 executed, 115 up-to-date
```
