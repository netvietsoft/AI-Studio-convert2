# TASK_038 — Dynamic RegisterNatives Recovery

## 1. Executive Summary
- **Total Recovered RegisterNatives Tables:** 54 tables
- **Total Dynamic Native Methods Recovered:** 3,033 methods
- **Direct JNI Exports:** 2,647 methods
- **Total Native Bridge Surface:** 5,680 methods

---

## 2. Table-by-Table Recovery Catalog

| Library | Table RVA | Method Count | Matched Java Class | Match Confidence | Key Methods |
|---|---|---|---|---|---|
| `libARKernelInterface.so` | `0x010cc0b0` | 804 | `com.meitu.mtlab.arkernelinterface.core.*JNI` | HIGH_CONFIDENCE | `nativeCreateInstance`, `nativeSetFaceData`, `nativeRender` |
| `libARKernelInterface.so` | `0x010d56b0` | 1 | `com.meitu.flymedia.glx.graphics.freetype.GLXBitmap` | 100.0% | `nativeInitBitmapDC` |
| `libCtaApiLib.so` | `0x00088010` | 11 | `cn.com.chinatelecom.account.api.Helper` | 100.0% | `cepahsul`, `dnauhs` |
| `libKKMusicFX.so` | `0x0007f8d0` | 10 | `com.meitu.media.mfx.MFXManager` | 100.0% | `analyzeAudio`, `processAudio` |
| `libKKMusicFX.so` | `0x00080050` | 1 | `com.rmsl.juce.Java` | 100.0% | `initialiseJUCE` |
| `libLayerFlow.so` | `0x00531048` | 30 | `com.layer.flow.datas.LFAigcCacheData` | 85.7% | `nCreate`, `nDestroy`, `nSetCache` |
| `libLayerFlow.so` | `0x00531808` | 13 | `com.layer.flow.datas.LFAutoBeautyData` | 100.0% | `nCreate`, `nSetBeautyLevel` |
| `libLayerFlow.so` | `0x005319d0` | 31 | `com.layer.flow.datas.LFAutoBrushData` | 100.0% | `nCreate`, `nSetBrushRadius` |
| `libLayerFlow.so` | `0x00531d48` | 141 | `com.layer.flow.datas.LFBodyShapeData` | 92.4% | `nCreate`, `nSetSlimDegree` |
| `libLayerFlow.so` | `0x00532c30` | 122 | `com.layer.flow.datas.LFDermabrasionData` | 94.1% | `nDestroy`, `nSetSmoothLevel` |
| `libLayerFlow.so` | `0x005337e0` | 104 | `com.layer.flow.datas.LFEffectEyeData` | 87.7% | `nDestroy`, `nSetEyeEnlarge` |
| `libLayerFlow.so` | `0x005341f0` | 129 | `com.layer.flow.datas.LFEffectOneClickBeautyData` | 57.3% | `nDestroy`, `nApplyOneClick` |
| `libLayerFlow.so` | `0x00534e98` | 105 | `com.layer.flow.datas.LFEffectWakeSkinData` | 59.8% | `nCreate`, `nSetSkinTone` |
| `libLayerFlow.so` | `0x005358a0` | 200 | `com.layer.flow.datas.LFEnhanceData` | 85.8% | `nCreate`, `nSetContrast` |
| `libLayerFlow.so` | `0x00537030` | 63 | `com.layer.flow.datas.LFFaceFullData` | 93.3% | `nCreate`, `nSetFaceMorph` |
| `libLayerFlow.so` | `0x00537648` | 53 | `com.layer.flow.datas.LFFaceRemoldData` | 100.0% | `nDestroy`, `nSetJawMorph` |
| `libLayerFlow.so` | `0x00537b70` | 69 | `com.layer.flow.datas.LFFixTeethData` | 88.5% | `nCreate`, `nSetTeethWhite` |
| `libLayerFlow.so` | `0x00538308` | 97 | `com.layer.flow.datas.LFMakeUpData` | 52.6% | `nCreate`, `nSetBlushAlpha` |
| `libLayerFlow.so` | `0x00538eb0` | 163 | `com.layer.flow.datas.LFSkinWhitenData` | 62.7% | `nDestroy`, `nSetWhitenDegree` |
| `libLayerFlow.so` | `0x00539e28` | 67 | `com.layer.flow.datas.LFStickerData` | 81.5% | `nDestroy`, `nSetStickerFBO` |
| `libLayerFlow.so` | `0x0053a570` | 210 | `com.layer.flow.datas.LFTextData` | 98.0% | `nCreate`, `nSetTextTexture` |
| `libLayerFlow.so` | `0x0053bdb8` | 4 | `com.layer.flow.formula.LFBlockingWait` | 100.0% | `nGenerateBlockingIdByType8` |
| `libLayerFlow.so` | `0x0053be38` | 18 | `com.layer.flow.formula.LFFormulaShop` | 100.0% | `nCreate`, `nApplyFormula` |
| `libLayerFlow.so` | `0x0053c218` | 100 | `com.layer.flow.layer.LFBaseLayer` | 100.0% | `nClearPendingExceptions`, `nRender` |
| `libLayerFlow.so` | `0x0053fc70` | 47 | `com.layer.flow.plugin.LFAutoMagicPenResourceData` | 53.7% | `nCreate`, `nSetStroke` |
| `libLayerFlow.so` | `0x00540198` | 41 | `com.layer.flow.plugin.LFFormulaRenderPlugin` | 89.7% | `nCreate`, `nRenderFormula` |
| `libLayerFlow.so` | `0x00541d48` | 2 | `com.layer.flow.datas.LFAigcCacheData` | 100.0% | `nCreate`, `nGetCache` |
| `libLayerFlow.so` | `0x00541e38` | 26 | `com.layer.flow.plugin.LFNetHeader` | 100.0% | `nCreate`, `nSetHeader` |
| `libLayerFlow.so` | `0x00542138` | 18 | `com.layer.flow.plugin.LFStickerLocateStatus` | 100.0% | `nCreate`, `nGetStatus` |
| `libLayerFlow.so` | `0x00545dd0` | 4 | `com.layer.flow.plugin.LFPrepareManagerPlugin` | 100.0% | `nCreate`, `nPrepare` |
| `libLayerFlow.so` | `0x005461d8` | 31 | `com.layer.flow.plugin.LFMaterialDownloadPlugin` | 91.3% | `nCreate`, `nDownload` |
| `libLayerFlow.so` | `0x005466b0` | 3 | `com.layer.flow.plugin.LFOutputImagePlugin` | 100.0% | `nCreate`, `nOutput` |
| `libLayerFlow.so` | `0x005467c8` | 4 | `com.layer.flow.plugin.LFResourceDownloaderPlugin` | 100.0% | `nCreate`, `nStart` |
| `libLayerFlow.so` | `0x00546a08` | 4 | `com.layer.flow.plugin.LFSetLayerPlugin` | 100.0% | `nCreate`, `nSetLayer` |
| `libLayerFlow.so` | `0x00546ab8` | 3 | `com.layer.flow.plugin.LFSmartActionsPlugin` | 100.0% | `nCreate`, `nExecute` |
| `libLayerFlow.so` | `0x00548390` | 5 | `com.layer.flow.vision.LFVisionDetectService` | 100.0% | `nativeCreate`, `nativeDetect` |
| `libMTFilterKernel.so` | `0x001ca2d8` | 25 | `com.meitu.core.MTFilterKernelFaceData` | 100.0% | `nativeCreate`, `nativeGetLandmark`, `nativeSetFaceRect` |
| `libMTFilterKernel.so` | `0x001ca530` | 17 | `com.meitu.core.MTFilterKernelRender` | 100.0% | `nCreate`, `nInit`, `nRenderToOutTexture`, `nSetBodyTexture` |
| `libMTLReportTool.so` | `0x00019568` | 10 | `com.meitu.mtlab.MTLReportTool.MTLReportToolInterface` | 100.0% | `nativeCreateInstance`, `nativeReport` |
| `libPVGCodec.so` | `0x00139fe8` | 25 | `com.meitu.media.PVGCodec.AudioDecoder` | 61.5% | `native_setup`, `native_decode` |
| `libPVGCodec.so` | `0x0013a290` | 4 | `com.meitu.media.PVGCodec.GifMetaData` | 100.0% | `native_setup`, `native_getFrames` |
| `libPVGCodec.so` | `0x0013a338` | 9 | `com.meitu.media.PVGCodec.IProcessor` | 100.0% | `setLogLevel`, `processFrame` |
| `libPVGCodec.so` | `0x0013a4d8` | 90 | `com.meitu.media.PVGCodec.VideoDecoder` | 91.2% | `native_setup`, `native_render` |
| `libPVGLive.so` | `0x0009a938` | 36 | `com.meitu.mtlab.PVGLive.PVGLiveInterface` | 86.1% | `nativeSetLogLevel`, `nativeStartLive` |
| `libPVGVideoCodec.so` | `0x001181d8` | 1 | `kotlinx.coroutines.media.decoder.AndroidDecoder` | 100.0% | `callNativeOpaque` |
| `libPVGVideoCodec.so` | `0x001187f8` | 2 | `kotlinx.coroutines.media.decoder.FlyMediaReader` | 100.0% | `native_SurfaceTextureCallback` |
| `libaicodec.so` | `0x001feb88` | 2 | `com.meitu.media.aicodec.AICodec` | 100.0% | `getVersion`, `initAICodec` |
| `libaicodec.so` | `0x001febd0` | 26 | `kotlinx.coroutines.media.decoder.FlyMediaReader` | 100.0% | `native_open`, `native_seek` |
| `libaicodec.so` | `0x001fee58` | 1 | `kotlinx.coroutines.media.decoder.FlyMediaReader` | 100.0% | `native_getVideoFrame` |
| `libaicodec.so` | `0x001ff0c8` | 18 | `kotlinx.coroutines.media.encoder.FlyMediaRecorder` | 62.5% | `native_init`, `native_record` |
| `libaidetectionplugin.so` | `0x00081dc8` | 5 | `kotlinx.coroutines.aidetectionplugin.MTAIDetectionPluginConfig` | 100.0% | `nativeSetAILogLevel`, `nativeInit` |
| `libarkernel3.so` | `0x010f9230` | 1 | `com.meitu.flymedia.glx.graphics.freetype.GLXBitmap` | 100.0% | `nativeInitBitmapDC` |
| `libbytehook.so` | `0x000117a8` | 10 | `com.bytedance.android.bytehook.ByteHook` | 100.0% | `nativeGetVersion`, `nativeInit` |
| `libfntvcrash.so` | `0x00015600` | 7 | `com.meitu.crash.CrashHandler` | 85.7% | `nativeInit`, `nativeDump` |
| `libglide-webp.so` | `0x00068000` | 10 | `com.bumptech.glide.integration.webp.WebpImage` | 62.5% | `nativeCreateFromDirectByteBuffer` |

---

## 3. Deep Analysis of `libMTFilterKernel.so` Dynamic Tables

`libMTFilterKernel.so` dynamically registers two critical classes via `registerFaceDataMethods` and `registerMTFilterKernelRenderMethods`:

### Table 1: `com/meitu/core/MTFilterKernelFaceData` (25 Methods, RVA 0x001ca2d8)
1. `nativeCreate ()J -> 0x000be458`
2. `finalizer (J)V -> 0x000be468`
3. `nativeGetFaceCount (J)I -> 0x000be478`
4. `nativeGetFaceRect (JI)[F -> 0x000be4c0`
5. `nativeGetLandmark (JII)[F -> 0x000be590`
6. `nativeGetDetectWidth (J)I -> 0x000bea90`
7. `nativeGetDetectHeight (J)I -> 0x000beadc`
8. `nativeGetRace (JI)I -> 0x000beb28`
9. `nativeGetGender (JI)I -> 0x000beba8`
10. `nativeGetAge (JI)I -> 0x000bec28`
11. `nativeSetFaceCount (JI)V -> 0x000beca8`
12. `nativeSetDetectSize (JII)V -> 0x000bece8`
13. `nativeSetFaceRect (JI[F)V -> 0x000bed30`
14. `nativeSetLandmark (JII[F)Z -> 0x000bedf4`
15. `nativeSetLandmarkVisible (JII[F)Z -> 0x000bf2ec`
16. `nativeSetRace (JII)V -> 0x000bf80c`
17. `nativeSetGender (JII)V -> 0x000bf884`
18. `nativeSetAge (JII)V -> 0x000bf8fc`
19. `nativeGetFaceID (JI)I -> 0x000bf974`
20. `nativeSetFaceID (JII)V -> 0x000bf9e4`
21. `nativeSetHasGlasses (JII)V -> 0x000bfa58`
22. `nativeClear (J)V -> 0x000bfacc`
23. `nativeSetPitchAngle (JIF)V -> 0x000bfb18`
24. `nativeSetYawAngle (JIF)V -> 0x000bfb90`
25. `nativeSetRollAngle (JIF)V -> 0x000bfc08`

### Table 2: `com/meitu/core/MTFilterKernelRender` (17 Methods, RVA 0x001ca530)
1. `nCreate ()J -> 0x000bfce8`
2. `nFinalizer (J)V -> 0x000bfd28`
3. `nInit (J)V -> 0x000bfd40`
4. `nRelease (J)V -> 0x000bfd98`
5. `nLoadFilterConfig (JLjava/lang/String;)Z -> 0x000bfdf0`
6. `nRenderToOutTexture (JIIIIII)I -> 0x000bfee4`
7. `nSetDeviceOrientation (JI)V -> 0x000bff14`
8. `nSetFrameType (JI)V -> 0x000bff7c`
9. `nSetMTFilterKernelListener (JLcom/meitu/core/MTFilterKernelRender$MTFilterKernelListener;)V -> 0x000bff90`
10. `nActiveEffect (J)V -> 0x000bfff8`
11. `nSetFilterKernelSpliceData (JLcom/meitu/core/MTFilterKernelRender$FilterKernelSpliceData;)V -> 0x000c0008`
12. `nSetSpliceFilterStatus (JZ)V -> 0x000c01bc`
13. `nSetFilterKernelConfig (JLcom/meitu/core/MTFilterKernelRender$FilterKernelConfig;)V -> 0x000c01d4`
14. `nGetIsNeedBodySegment (J)Z -> 0x000c0668`
15. `nSetBodyTexture (JIII)V -> 0x000c0690`
16. `nSetBodySegmentDataWithBytebuffer (JLjava/nio/ByteBuffer;IIII)V -> 0x000c06cc`
17. `nSetFaceData (JJ)V -> 0x000c0774`