# TASK_038 — RegisterNatives Dynamic Registration Recovery

- **Total RegisterNatives Tables Recovered:** 102
- **Total Dynamically Registered Methods:** 1628

---

## Library: `libaicodec.so`
- **Target Class:** `%s/MTMV_AICodec: [%s(%d)]:> register_com_meitu_media_aicodec_AICodec failed
`
- **Registration Call RVA:** `0x105cf4`
- **JNINativeMethod Table RVA:** `0x1feb88`
- **Registered Method Count:** `2`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `getVersion` | `()Lcom/meitu/media/aicodec/AICodec$Version;` | `0x105e44` |
| 1 | `getVersionString` | `()Ljava/lang/String;` | `0x106008` |

---

## Library: `libaicodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0x106424`
- **JNINativeMethod Table RVA:** `0x1febb8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `callNativeOpaque` | `(Ljava/lang/String;Ljava/lang/String;Landroid/media/MediaFormat;)V` | `0x0` |

---

## Library: `libaicodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0x106a8c`
- **JNINativeMethod Table RVA:** `0x1febd0`
- **Registered Method Count:** `32`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_open` | `(JLjava/lang/String;)J` | `0x106d8c` |
| 1 | `native_start` | `(J)Z` | `0x106f1c` |
| 2 | `native_stop` | `(J)V` | `0x106fd0` |
| 3 | `native_pause` | `(J)V` | `0x107068` |
| 4 | `native_resume` | `(J)V` | `0x107100` |
| 5 | `native_close` | `(J)V` | `0x107198` |
| 6 | `native_hasAudio` | `(J)Z` | `0x10725c` |
| 7 | `native_hasVideo` | `(J)Z` | `0x107304` |
| 8 | `native_getDuration` | `(J)D` | `0x1073ac` |
| 9 | `native_getVideoDuration` | `(J)D` | `0x10745c` |
| 10 | `native_getAudioDuration` | `(J)D` | `0x10750c` |
| 11 | `native_getVideoWidth` | `(J)I` | `0x1075bc` |
| 12 | `native_getVideoHeight` | `(J)I` | `0x107664` |
| 13 | `native_getFps` | `(J)F` | `0x10770c` |
| 14 | `native_getRotation` | `(J)I` | `0x1077bc` |
| 15 | `native_getVideoCodec` | `(J)Ljava/lang/String;` | `0x107878` |
| 16 | `native_getVideoBitrate` | `(J)J` | `0x107960` |
| 17 | `native_getFramesNumber` | `(J)I` | `0x107a08` |
| 18 | `native_getAudioCodec` | `(J)Ljava/lang/String;` | `0x107ab0` |
| 19 | `native_getAudioBitrate` | `(J)J` | `0x107b98` |
| 20 | `native_getAudioSampleRate` | `(J)J` | `0x107c40` |
| 21 | `native_getSizePerSample` | `(J)J` | `0x107ce8` |
| 22 | `native_setEnableAudio` | `(JZ)V` | `0x107d9c` |
| 23 | `native_setEnableVideo` | `(JZ)V` | `0x107e40` |
| 24 | `native_setStartTime` | `(JJ)V` | `0x107ee4` |
| 25 | `native_setDuration` | `(JJ)J` | `0x107f80` |
| 26 | `native_registerEGLContext` | `(J)Z` | `0x0` |
| 27 | `native_getVideoFrame` | `(JJ[Ljava/nio/ByteBuffer;[I[J[I[Z)I` | `0x108040` |
| 28 | `native_setAudioOutParameter` | `(JII)I` | `0x0` |
| 29 | `native_getAudioFrame` | `(J[Ljava/nio/ByteBuffer;[Z)I` | `0x0` |
| 30 | `setEnableAdditionCodec` | `(I)V` | `0x0` |
| 31 | `setCodecRate` | `(I)V` | `0x0` |

---

## Library: `libaicodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0x106ad4`
- **JNINativeMethod Table RVA:** `0x1feed0`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_SurfaceTextureCallback` | `(J)V` | `0x0` |

---

## Library: `libaicodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0x106b1c`
- **JNINativeMethod Table RVA:** `0x1feee8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_ImageReaderCB` | `(J)V` | `0x0` |

---

## Library: `libaicodec.so`
- **Target Class:** `@`
- **Registration Call RVA:** `0x116bc0`
- **JNINativeMethod Table RVA:** `0x1ff0c8`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_init` | `()J` | `0x116d18` |
| 1 | `native_finalize` | `(J)V` | `0x116d58` |
| 2 | `native_setAudioInParam` | `(JIII)I` | `0x116d88` |
| 3 | `native_setAudioOutParam` | `(JIII)I` | `0x116e50` |
| 4 | `native_setVideoInParam` | `(JII)I` | `0x116f18` |
| 5 | `native_setVideoOutParam` | `(JIIIIII)I` | `0x116fe0` |
| 6 | `native_setVideoOutCodec` | `(JI)I` | `0x117340` |
| 7 | `native_setVideoOutProfile` | `(JI)I` | `0x117400` |

---

## Library: `libaicodec.so`
- **Target Class:** `%s/MTMV_AICodec: [%s(%d)]:> native handle is null
`
- **Registration Call RVA:** `0x117500`
- **JNINativeMethod Table RVA:** `0x1ff188`
- **Registered Method Count:** `10`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_init` | `(Ljava/lang/String;J)J` | `0x117658` |
| 1 | `native_finalize` | `(J)V` | `0x117894` |
| 2 | `native_setEnableHardwareMode` | `(JZ)I` | `0x1178c4` |
| 3 | `native_registerEGLContext` | `(J)I` | `0x117974` |
| 4 | `native_start` | `(J)I` | `0x117acc` |
| 5 | `native_recordAudio` | `(JLjava/nio/ByteBuffer;)I` | `0x117b88` |
| 6 | `native_setEnableAsyncSendVideo` | `(JZ)I` | `0x117d00` |
| 7 | `native_recordVideo` | `(JIJLcom/meitu/media/encoder/FlyMediaRecorder$InputDataReleaseListener;)I` | `0x117db0` |
| 8 | `native_close` | `(J)I` | `0x118210` |
| 9 | `setCodecRate` | `(I)V` | `0x1182dc` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelAIKitInterfaceJNI`
- **Registration Call RVA:** `0x55e03c`
- **JNINativeMethod Table RVA:** `0x10cc0b0`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x55defc` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x55df2c` |
| 2 | `nativeReset` | `(J)V` | `0x55df44` |
| 3 | `nativeSetData` | `(JLjava/lang/String;)V` | `0x55df5c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelAnimalInterfaceJNI`
- **Registration Call RVA:** `0x55f240`
- **JNINativeMethod Table RVA:** `0x10cc1b8`
- **Registered Method Count:** `15`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x55e538` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x55ede8` |
| 2 | `nativeReset` | `(J)V` | `0x55ee00` |
| 3 | `nativeSetAnimalCount` | `(JI)V` | `0x55ee18` |
| 4 | `nativeGetAnimalCount` | `(J)I` | `0x55ee24` |
| 5 | `nativeSetAnimalID` | `(JII)V` | `0x55ee38` |
| 6 | `nativeGetAnimalID` | `(JI)I` | `0x55ee5c` |
| 7 | `nativeSetAnimalRect` | `(JIFFFF)V` | `0x55ee90` |
| 8 | `nativeGetAnimalRect` | `(JI)[F` | `0x55eeb8` |
| 9 | `nativeSetLandmark2D` | `(JI[F)V` | `0x55ef8c` |
| 10 | `nativeGetLandmark2D` | `(JI)[F` | `0x55f0b0` |
| 11 | `nativeSetAnimalLabel` | `(JII)V` | `0x55f148` |
| 12 | `nativeGetAnimalLabel` | `(JI)I` | `0x55f16c` |
| 13 | `nativeSetScore` | `(JIF)V` | `0x55f1a8` |
| 14 | `nativeGetScore` | `(JI)F` | `0x55f1cc` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelAugmentedRealityDataInterfaceJNI`
- **Registration Call RVA:** `0x560848`
- **JNINativeMethod Table RVA:** `0x10cc320`
- **Registered Method Count:** `18`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x55f7a4` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x55fe50` |
| 2 | `nativeReset` | `(J)V` | `0x55fe68` |
| 3 | `nativeSetDataSourceType` | `(JI)V` | `0x55fe80` |
| 4 | `nativeGetDataSourceType` | `(J)I` | `0x55fe8c` |
| 5 | `nativeSetIsFrontCamera` | `(JZ)V` | `0x55fea0` |
| 6 | `nativeGetIsFrontCamera` | `(J)Z` | `0x55feb4` |
| 7 | `nativeSetDeviceOrientationType` | `(JI)V` | `0x55fec8` |
| 8 | `nativeGetDeviceOrientationType` | `(J)I` | `0x55fed4` |
| 9 | `nativeSetGyroscopeQuaternionData` | `(JFFFF)V` | `0x55fee8` |
| 10 | `nativeSetAugmentedRealityMatrix` | `(J[F[F)V` | `0x55ff00` |
| 11 | `nativeSetLightEstimate` | `(J[FF)V` | `0x55ffc8` |
| 12 | `nativeSetARPlaneCount` | `(JI)V` | `0x560044` |
| 13 | `nativeSetARPlaneInfo` | `(JIII[F[F[F)V` | `0x560368` |
| 14 | `nativeSetInstantPlacementInfo` | `(J[FI[FI)V` | `0x560068` |
| 15 | `nativeSetFaceMeshCount` | `(JI)V` | `0x56048c` |
| 16 | `nativeSetFaceMeshTransformInfo` | `(JI[F[F)V` | `0x5604c0` |
| 17 | `nativeSetFaceMeshData` | `(JILjava/nio/FloatBuffer;Ljava/nio/FloatBuffer;Ljava/nio/FloatBuffer;Ljava/nio/ShortBuffer;)V` | `0x5605a0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `arkernel`
- **Registration Call RVA:** `0x562a28`
- **JNINativeMethod Table RVA:** `0x10cc4d0`
- **Registered Method Count:** `19`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x560dfc` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x561590` |
| 2 | `nativeReset` | `(J)V` | `0x5615a8` |
| 3 | `nativeSetBodyCount` | `(JI)V` | `0x5615c0` |
| 4 | `nativeGetBodyCount` | `(J)I` | `0x561628` |
| 5 | `nativeSetBodyRect` | `(JIFFFF)V` | `0x56163c` |
| 6 | `nativeGetBodyRect` | `(JI)[F` | `0x561664` |
| 7 | `nativeSetBodyData` | `(JI[F[FI)V` | `0x561738` |
| 8 | `nativeGetBodyPoints` | `(JI)[F` | `0x5619a8` |
| 9 | `nativeGetBodyScores` | `(JI)[F` | `0x561ac0` |
| 10 | `nativeSetContourData` | `(JI[F[FI)V` | `0x561be4` |
| 11 | `nativeGetContourPoints` | `(JI)[F` | `0x561e54` |
| 12 | `nativeGetContourScores` | `(JI)[F` | `0x561f6c` |
| 13 | `nativeSetNeckData` | `(JI[F[FI)V` | `0x562090` |
| 14 | `nativeGetNeckPoints` | `(JI)[F` | `0x562300` |
| 15 | `nativeGetNeckScores` | `(JI)[F` | `0x562418` |
| 16 | `nativeSetBreastData` | `(JI[F[FI)V` | `0x56253c` |
| 17 | `nativeGetBreastPoints` | `(JI)[F` | `0x5627ac` |
| 18 | `nativeGetBreastScores` | `(JI)[F` | `0x5628c4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelBodySlim3DDataInterfaceJNI`
- **Registration Call RVA:** `0x563988`
- **JNINativeMethod Table RVA:** `0x10cc698`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x562e64` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5632ac` |
| 2 | `nativeReset` | `(J)V` | `0x5632c4` |
| 3 | `nativeSetWidthAndHeight` | `(JII)V` | `0x5632dc` |
| 4 | `nativeSetBodySlim3DCount` | `(JII)V` | `0x5632e8` |
| 5 | `nativeSetBodySlim3DData` | `(JII[F[F[F[F)V` | `0x56339c` |
| 6 | `nativeSetBodySlim3DSparseDataCount` | `(JI)V` | `0x563664` |
| 7 | `nativeSetBodySlim3DSparseData` | `(JIII[F[F[F[F)V` | `0x563700` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelErrorDataInterfaceJNI`
- **Registration Call RVA:** `0x565abc`
- **JNINativeMethod Table RVA:** `0x10cc758`
- **Registered Method Count:** `7`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeDestroyInstance` | `(J)V` | `0x565968` |
| 1 | `nativeReset` | `(J)V` | `0x565994` |
| 2 | `nativeGetErrorCount` | `(J)I` | `0x565980` |
| 3 | `nativeGetErrorLabel` | `(JI)I` | `0x5659ac` |
| 4 | `nativeGetErrorCode` | `(JI)I` | `0x5659d4` |
| 5 | `nativeGetErrorParam` | `(JI)Ljava/lang/String;` | `0x5659fc` |
| 6 | `nativeGetErrorInfo` | `(JI)Ljava/lang/String;` | `0x565a3c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelFace2DReconstructorInterfaceJNI`
- **Registration Call RVA:** `0x56633c`
- **JNINativeMethod Table RVA:** `0x10cc800`
- **Registered Method Count:** `20`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x565adc` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5660a8` |
| 2 | `nativeReset` | `(J)V` | `0x5660c0` |
| 3 | `nativeSetFace2DReconstructorType` | `(JI)V` | `0x5660d8` |
| 4 | `nativeGetFace2DReconstructorType` | `(J)I` | `0x5660e4` |
| 5 | `nativeSetFaceCount` | `(JI)V` | `0x5660f8` |
| 6 | `nativeGetFaceCount` | `(J)I` | `0x566104` |
| 7 | `nativeSetFaceID` | `(JII)V` | `0x566118` |
| 8 | `nativeSetReconstructVertexs` | `(JIJ)V` | `0x56612c` |
| 9 | `nativeSetReconstructVertexsBuffer` | `(JILjava/nio/ByteBuffer;)V` | `0x566140` |
| 10 | `nativeSetReconstructTextureCoordinates` | `(JIJ)V` | `0x566188` |
| 11 | `nativeSetReconstructTextureCoordinatesBuffer` | `(JILjava/nio/ByteBuffer;)V` | `0x56619c` |
| 12 | `nativeSetReconstructStandTextureCoordinates` | `(JIJ)V` | `0x5661e4` |
| 13 | `nativeSetReconstructStandTextureCoordinatesBuffer` | `(JILjava/nio/ByteBuffer;)V` | `0x5661f8` |
| 14 | `nativeSetVertexNum` | `(JII)V` | `0x566240` |
| 15 | `nativeGetVertexNum` | `(JI)I` | `0x566254` |
| 16 | `nativeSetReconstructTriangleIndex` | `(JIJ)V` | `0x566270` |
| 17 | `nativeSetReconstructTriangleIndexBuffer` | `(JILjava/nio/ByteBuffer;)V` | `0x566284` |
| 18 | `nativeSetTriangleNum` | `(JII)V` | `0x5662cc` |
| 19 | `nativeGetTriangleNum` | `(JI)I` | `0x5662e0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelFace3DReconstructorInterfaceJNI`
- **Registration Call RVA:** `0x567728`
- **JNINativeMethod Table RVA:** `0x10cc9e0`
- **Registered Method Count:** `26`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x566744` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5674d4` |
| 2 | `nativeReset` | `(J)V` | `0x5674ec` |
| 3 | `nativeSetIsWithoutCache` | `(JZ)V` | `0x567504` |
| 4 | `nativeGetIsWithoutCache` | `(J)Z` | `0x567518` |
| 5 | `nativeSetFaceCount` | `(JI)V` | `0x56752c` |
| 6 | `nativeGetFaceCount` | `(J)I` | `0x567538` |
| 7 | `nativeSetMeshTriangleNum` | `(JII)V` | `0x56754c` |
| 8 | `nativeGetMeshTriangleNum` | `(JI)I` | `0x567560` |
| 9 | `nativeSetMeshTriangleNumWithoutLips` | `(JII)V` | `0x56757c` |
| 10 | `nativeGetMeshTriangleNumWithoutLips` | `(JI)I` | `0x567590` |
| 11 | `nativeSetMeshVertexNum` | `(JII)V` | `0x5675ac` |
| 12 | `nativeGetMeshVertexNum` | `(JI)I` | `0x5675c0` |
| 13 | `nativeSetReconstructVertexs` | `(JIJ)V` | `0x5675dc` |
| 14 | `nativeSetTextureCoordinatesV1` | `(JIJ)V` | `0x5675f0` |
| 15 | `nativeSetTextureCoordinatesV2` | `(JIJ)V` | `0x567604` |
| 16 | `nativeSetTriangleIndex` | `(JIJ)V` | `0x567618` |
| 17 | `nativeSetVertexNormals` | `(JIJ)V` | `0x567668` |
| 18 | `nativeSetCameraParam` | `(JIJ)V` | `0x56767c` |
| 19 | `nativeSetMatToNDC` | `(JIJ)V` | `0x567690` |
| 20 | `nativeSetFaceID` | `(JII)V` | `0x5676b8` |
| 21 | `nativeSetMatToImage` | `(JIJ)V` | `0x5676a4` |
| 22 | `nativeSetHasFace3DReconstructorData` | `(JIZ)V` | `0x5676cc` |
| 23 | `nativeSet3DIndex` | `(JIJ)V` | `0x56762c` |
| 24 | `nativeSet2DIndex` | `(JIJ)V` | `0x567640` |
| 25 | `nativeSetLandmark` | `(JII)V` | `0x567654` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `arkernel`
- **Registration Call RVA:** `0x5695ec`
- **JNINativeMethod Table RVA:** `0x10ccc50`
- **Registered Method Count:** `12`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x56822c` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x568be8` |
| 2 | `nativeReset` | `(J)V` | `0x568c00` |
| 3 | `nativeSetIsWithoutCache` | `(JZ)V` | `0x568c18` |
| 4 | `nativeGetIsWithoutCache` | `(J)Z` | `0x568c2c` |
| 5 | `nativeSetFaceCount` | `(JI)V` | `0x568c40` |
| 6 | `nativeGetFaceCount` | `(J)I` | `0x568c4c` |
| 7 | `nativeSetFaceID` | `(JII)V` | `0x568c60` |
| 8 | `nativeSetHasFaceDL3DReconstructorData` | `(JIZ)V` | `0x568c74` |
| 9 | `nativeSetMeshDataWithCopy` | `(JII[F[F[F[FI[S)V` | `0x568c90` |
| 10 | `nativeSetMatrixDataWithCopy` | `(JI[F[F[F[F[F)V` | `0x569000` |
| 11 | `nativeSetExpressionWithCopy` | `(JI[F[F[I[F)V` | `0x5692a8` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelFaceInterfaceJNI`
- **Registration Call RVA:** `0x56ca6c`
- **JNINativeMethod Table RVA:** `0x10ccd70`
- **Registered Method Count:** `58`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x5699e4` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x569f90` |
| 2 | `nativeReset` | `(J)V` | `0x569fa8` |
| 3 | `nativeSetFaceCount` | `(JI)V` | `0x569fc0` |
| 4 | `nativeGetFaceCount` | `(J)I` | `0x569fcc` |
| 5 | `nativeSetFaceID` | `(JII)V` | `0x569fe0` |
| 6 | `nativeGetFaceID` | `(JI)I` | `0x56a004` |
| 7 | `nativeSetFaceFR` | `(JIJ)V` | `0x56a038` |
| 8 | `nativeGetFaceFR` | `(JI)J` | `0x56a05c` |
| 9 | `nativeSetFaceRect` | `(JIFFFF)V` | `0x56a090` |
| 10 | `nativeGetFaceRect` | `(JI)[F` | `0x56a0b8` |
| 11 | `nativeSetPointCount2D` | `(JII)V` | `0x56a4ec` |
| 12 | `nativeGetPointCount2D` | `(JI)I` | `0x56a508` |
| 13 | `nativeSetFacialLandmark2D` | `(JI[F)V` | `0x56a528` |
| 14 | `nativeGetFacialLandmark2D` | `(JI)[F` | `0x56a66c` |
| 15 | `nativeSetFacialLandmark2DVisible` | `(JI[F)V` | `0x56a700` |
| 16 | `nativeGetFacialLandmark2DVisible` | `(JI)[F` | `0x56a844` |
| 17 | `nativeSetGender` | `(JII)V` | `0x56a8d0` |
| 18 | `nativeGetGender` | `(JI)I` | `0x56a908` |
| 19 | `nativeSetRace` | `(JII)V` | `0x56a948` |
| 20 | `nativeGetRace` | `(JI)I` | `0x56a974` |
| 21 | `nativeSetSkin` | `(JII)V` | `0x56a9b0` |
| 22 | `nativeGetSkin` | `(JI)I` | `0x56a9ec` |
| 23 | `nativeSetAge` | `(JII)V` | `0x56aa28` |
| 24 | `nativeGetAge` | `(JI)I` | `0x56aa4c` |
| 25 | `nativeSetChildAgeType` | `(JII)V` | `0x56aa80` |
| 26 | `nativeGetChildAgeType` | `(JI)I` | `0x56aab4` |
| 27 | `nativeSetPosEstimate` | `(JIFFFFFF)V` | `0x56aaf8` |
| 28 | `nativeGetPosEstimate` | `(JI)[F` | `0x56ab40` |
| 29 | `nativeSetNeckRect` | `(JIFFFF)V` | `0x56ac28` |
| 30 | `nativeGetNeckRect` | `(JI)[F` | `0x56ac50` |
| 31 | `nativeSetNeckPoints` | `(JI[F)V` | `0x56ad24` |
| 32 | `nativeGetNeckPoints` | `(JI)[F` | `0x56ae68` |
| 33 | `nativeSetHeadPoints` | `(JI[F)V` | `0x56af00` |
| 34 | `nativeGetHeadPoints` | `(JI)[F` | `0x56b024` |
| 35 | `nativeSetFacialInterPoint` | `(JI[F)V` | `0x56b0bc` |
| 36 | `nativeGetFacialInterPoint` | `(JI)[F` | `0x56b1e4` |
| 37 | `nativeSetLeftEarPointCount2D` | `(JII)V` | `0x56a18c` |
| 38 | `nativeGetLeftEarPointCount2D` | `(JI)I` | `0x56a1a8` |
| 39 | `nativeSetLeftEarLandmark2D` | `(JI[F)V` | `0x56a1c8` |
| 40 | `nativeGetLeftEarLandmark2D` | `(JI)[F` | `0x56a298` |
| 41 | `nativeSetRightEarPointCount2D` | `(JII)V` | `0x56a340` |
| 42 | `nativeGetRightEarPointCount2D` | `(JI)I` | `0x56a35c` |
| 43 | `nativeSetRightEarLandmark2D` | `(JI[F)V` | `0x56a37c` |
| 44 | `nativeGetRightEarLandmark2D` | `(JI)[F` | `0x56a44c` |
| 45 | `nativeSetFaceEmotionFactor` | `(JI[F)V` | `0x56b27c` |
| 46 | `nativeGetFaceEmotionFactor` | `(JI)[F` | `0x56b398` |
| 47 | `nativeSetEyeLid` | `(JIII)V` | `0x56b430` |
| 48 | `nativeSetSegmentMouthMaskInfo` | `(JILjava/nio/ByteBuffer;II[FIII)V` | `0x56b458` |
| 49 | `nativeSetSegmentFaceMaskInfo` | `(JILjava/nio/ByteBuffer;II[FIII)V` | `0x56b830` |
| 50 | `nativeSetPostureInfo` | `(JI[F[F[F[F[F[F[F)V` | `0x56c3f4` |
| 51 | `nativeSetMeshInfo` | `(JIIJJJJJIJ)V` | `0x56c660` |
| 52 | `nativeSetExpressionInfo` | `(JIIJIJ)V` | `0x56c6bc` |
| 53 | `nativeSetMeshInfoByteBuffer` | `(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V` | `0x56c6f4` |
| 54 | `nativeSetExpressionInfoByteBuffer` | `(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V` | `0x56c8f8` |
| 55 | `nativeSetLeftEyeMask` | `(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;IIII)V` | `0x56bc08` |
| 56 | `nativeSetRightEyeMask` | `(JILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;IIII)V` | `0x56bf50` |
| 57 | `nativeSetFaceHairMask` | `(JILjava/nio/ByteBuffer;II)V` | `0x56c298` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelFoodInterfaceJNI`
- **Registration Call RVA:** `0x56da8c`
- **JNINativeMethod Table RVA:** `0x10cd2e0`
- **Registered Method Count:** `15`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x56d49c` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x56d7a0` |
| 2 | `nativeReset` | `(J)V` | `0x56d7b8` |
| 3 | `nativeSetFoodCount` | `(JI)V` | `0x56d7d0` |
| 4 | `nativeGetFoodCount` | `(J)I` | `0x56d7dc` |
| 5 | `nativeSetFoodID` | `(JII)V` | `0x56d7f0` |
| 6 | `nativeGetFoodID` | `(JI)I` | `0x56d814` |
| 7 | `nativeSetFoodRect` | `(JIFFFF)V` | `0x56d848` |
| 8 | `nativeGetFoodRect` | `(JI)[F` | `0x56d870` |
| 9 | `nativeSetFoodScore` | `(JIF)V` | `0x56d944` |
| 10 | `nativeGetFoodScore` | `(JI)F` | `0x56d968` |
| 11 | `nativeSetFoodLabel` | `(JII)V` | `0x56d99c` |
| 12 | `nativeGetFoodLabel` | `(JI)I` | `0x56d9c0` |
| 13 | `nativeSetFoodLabelScore` | `(JIF)V` | `0x56d9f4` |
| 14 | `nativeGetFoodLabelScore` | `(JI)F` | `0x56da18` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelGlobalInterfaceJNI`
- **Registration Call RVA:** `0x570e7c`
- **JNINativeMethod Table RVA:** `0x10cd448`
- **Registered Method Count:** `16`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetApplicationContext` | `(Landroid/content/Context;)V` | `0x56dcac` |
| 1 | `nativeSetInternalLogLevel` | `(I)V` | `0x56e084` |
| 2 | `nativeSetLogCallback` | `(Lcom/meitu/mtlab/arkernelinterface/callback/ARKernelLogCallback;)V` | `0x56e104` |
| 3 | `nativeSetDirectory` | `(Ljava/lang/String;I)V` | `0x56e37c` |
| 4 | `nativeStartSoundService` | `()Z` | `0x56e4a4` |
| 5 | `nativePauseSoundService` | `(Z)V` | `0x56e51c` |
| 6 | `nativeStopSoundService` | `()V` | `0x56e5a8` |
| 7 | `nativeIsStopedSoundService` | `()Z` | `0x56e610` |
| 8 | `nativeStartGlobalGLThread` | `()V` | `0x56e680` |
| 9 | `nativeStopGlobalGLThread` | `()V` | `0x56e6e8` |
| 10 | `nativeGetCurrentVersion` | `()Ljava/lang/String;` | `0x56e750` |
| 11 | `nativeGetTagVersion` | `()Ljava/lang/String;` | `0x56e780` |
| 12 | `nativeRegisterFont` | `(Ljava/lang/String;Ljava/lang/String;)V` | `0x56e7b0` |
| 13 | `nativeParseTextPlist` | `(Ljava/lang/String;Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextConfig;)Z` | `0x56eae8` |
| 14 | `nativeParseAnimationPlist` | `(Ljava/lang/String;Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelAnimationConfig;)Z` | `0x56fd08` |
| 15 | `nativeParseWarpPlist` | `(Ljava/lang/String;Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelWarpConfig;)Z` | `0x5706f8` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelGroupDataInterfaceJNI`
- **Registration Call RVA:** `0x5717dc`
- **JNINativeMethod Table RVA:** `0x10cd5c8`
- **Registered Method Count:** `18`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x5712c4` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5712cc` |
| 2 | `nativeControlResetState` | `(J)V` | `0x5712d0` |
| 3 | `nativeResetState` | `(J)V` | `0x5712e0` |
| 4 | `nativeGetPartControl` | `(J)[J` | `0x5712f0` |
| 5 | `nativeGetPlistData` | `(J)[J` | `0x571418` |
| 6 | `nativePrepare` | `(J)Z` | `0x571540` |
| 7 | `nativeRelease` | `(J)V` | `0x571568` |
| 8 | `nativeIsPrepare` | `(J)Z` | `0x571578` |
| 9 | `nativeIsApply` | `(J)Z` | `0x5715a0` |
| 10 | `nativeSetApply` | `(JZ)V` | `0x5715c8` |
| 11 | `nativeHasBGM` | `(J)Z` | `0x5715e4` |
| 12 | `nativePlayBGM` | `(J)V` | `0x57160c` |
| 13 | `nativePauseBGM` | `(J)V` | `0x57161c` |
| 14 | `nativeReplayBGM` | `(J)V` | `0x57162c` |
| 15 | `nativeStopBGM` | `(J)V` | `0x57163c` |
| 16 | `nativeGetIsNeedDataRequireType` | `(JI)Z` | `0x57164c` |
| 17 | `nativeGetIsSupportMultiplyInstance` | `(J)Z` | `0x571774` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelHandInterfaceJNI`
- **Registration Call RVA:** `0x572bc8`
- **JNINativeMethod Table RVA:** `0x10cd778`
- **Registered Method Count:** `25`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x571810` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5724b4` |
| 2 | `nativeReset` | `(J)V` | `0x5724cc` |
| 3 | `nativeSetHandCount` | `(JI)V` | `0x5724e4` |
| 4 | `nativeGetHandCount` | `(J)I` | `0x5724f0` |
| 5 | `nativeSetHandID` | `(JII)V` | `0x572504` |
| 6 | `nativeGetHandID` | `(JI)I` | `0x572528` |
| 7 | `nativeSetHandRect` | `(JIFFFF)V` | `0x57255c` |
| 8 | `nativeGetHandRect` | `(JI)[F` | `0x572584` |
| 9 | `nativeSetHandPoint` | `(JIFF)V` | `0x572658` |
| 10 | `nativeGetHandPoint` | `(JI)[F` | `0x57267c` |
| 11 | `nativeSetHandKeyPoints` | `(JI[F)V` | `0x572740` |
| 12 | `nativeGetHandKeyPoints` | `(JI)[F` | `0x572818` |
| 13 | `nativeSetHandScore` | `(JIF)V` | `0x5728b0` |
| 14 | `nativeGetHandScore` | `(JI)F` | `0x5728d4` |
| 15 | `nativeSetHandGesture` | `(JII)V` | `0x572908` |
| 16 | `nativeGetHandGesture` | `(JI)I` | `0x572934` |
| 17 | `nativeSetHandGestureScore` | `(JIF)V` | `0x572968` |
| 18 | `nativeGetHandGestureScore` | `(JI)F` | `0x57298c` |
| 19 | `nativeSetNailCount` | `(JI)V` | `0x5729c0` |
| 20 | `nativeSetNailID` | `(JII)V` | `0x5729cc` |
| 21 | `nativeSetNailScore` | `(JIF)V` | `0x5729f0` |
| 22 | `nativeSetNailRect` | `(JIFFFF)V` | `0x572a14` |
| 23 | `nativeSetNailKeyPoints` | `(JI[F)V` | `0x572a44` |
| 24 | `nativeSetNailMaskInfo` | `(JILjava/nio/ByteBuffer;II)V` | `0x572b1c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelHuman3DDataInterfaceJNI`
- **Registration Call RVA:** `0x5738a4`
- **JNINativeMethod Table RVA:** `0x10cd9d0`
- **Registered Method Count:** `9`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57330c` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x573534` |
| 2 | `nativeReset` | `(J)V` | `0x57354c` |
| 3 | `nativeSetWidthAndHeight` | `(JFF)V` | `0x573564` |
| 4 | `nativeSetHumanBodyCount` | `(JI)V` | `0x573570` |
| 5 | `nativeSetHumanBodyInfo` | `(JIJ[F[F)V` | `0x573580` |
| 6 | `nativeSetHumanBodyJointInfo` | `(JII[F)V` | `0x573694` |
| 7 | `nativeSetShapeBlendShape` | `(JI[F)V` | `0x573740` |
| 8 | `nativeSetPoseBlendShape` | `(JI[F)V` | `0x5737d4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelImageDataInterfaceJNI`
- **Registration Call RVA:** `0x57447c`
- **JNINativeMethod Table RVA:** `0x10cdaa8`
- **Registered Method Count:** `13`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x5738e0` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x573cac` |
| 2 | `nativeReset` | `(J)V` | `0x573cc4` |
| 3 | `nativeSetImageValidRect` | `(JIIIII)V` | `0x573cdc` |
| 4 | `nativeGetImageValidRect` | `(JI)[F` | `0x573cf4` |
| 5 | `nativeSetImageDataUserDefineFlag` | `(JII)V` | `0x573d98` |
| 6 | `nativeGetImageDataUserDefineFlag` | `(JI)I` | `0x573dac` |
| 7 | `nativePushSourceGrayImageData` | `(J[BIIII)I` | `0x573dc8` |
| 8 | `nativePushSourceGrayImageDataWithByteBuffer` | `(JLjava/nio/ByteBuffer;IIII)I` | `0x573ec0` |
| 9 | `nativePushImageData` | `(JII[BIIII)I` | `0x573f84` |
| 10 | `nativePushImageDataWithByteBuffer` | `(JIILjava/nio/ByteBuffer;IIII)I` | `0x574078` |
| 11 | `nativePushYUVImageData` | `(JII[B[B[BIIIIII)I` | `0x57413c` |
| 12 | `nativePushYUVImageDataWithByteBuffer` | `(JIILjava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;IIIIII)I` | `0x5742f4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelInterfaceJNI`
- **Registration Call RVA:** `0x5789a8`
- **JNINativeMethod Table RVA:** `0x10cdbe0`
- **Registered Method Count:** `46`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57707c` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5770bc` |
| 2 | `nativeSetCallbackObject` | `(JLcom/meitu/mtlab/arkernelinterface/callback/ARKernelCallback;)V` | `0x5770ec` |
| 3 | `nativeClearCallbackObject` | `(J)V` | `0x577154` |
| 4 | `nativeSetCallbackPartCallbackObject` | `(JLcom/meitu/mtlab/arkernelinterface/callback/ARKernelCallbackPartCallback;)V` | `0x577164` |
| 5 | `nativeClearCallbackPartCallbackObject` | `(J)V` | `0x5771cc` |
| 6 | `nativeOnTouchBegin` | `(JFFI)V` | `0x5771dc` |
| 7 | `nativeOnTouchMove` | `(JFFI)V` | `0x5771f0` |
| 8 | `nativeOnTouchEnd` | `(JFFI)V` | `0x577204` |
| 9 | `nativeInitialize` | `(JJLjava/lang/String;)V` | `0x577218` |
| 10 | `nativeInitializeWithNoOpenGLContext` | `(J)V` | `0x5772bc` |
| 11 | `nativeLoadPublicParamConfiguration` | `(JLjava/lang/String;)Z` | `0x5772d8` |
| 12 | `nativeRelease` | `(J)V` | `0x5773a8` |
| 13 | `nativeUpdateCacheData` | `(J)V` | `0x5773b8` |
| 14 | `nativeGetResult` | `(J)I` | `0x5773c8` |
| 15 | `nativeOnDrawFrame` | `(JIIIIII)Z` | `0x5773f0` |
| 16 | `nativeVoidOperation` | `(JI)V` | `0x577434` |
| 17 | `nativePostMessage` | `(JLjava/lang/String;Ljava/lang/String;)V` | `0x577448` |
| 18 | `nativeNeedDataRequireType` | `(JI)Z` | `0x57770c` |
| 19 | `nativeGetOption` | `(JI)Z` | `0x577738` |
| 20 | `nativeSetOption` | `(JIZ)V` | `0x577764` |
| 21 | `nativeQueryDict` | `(JI)[Ljava/lang/Object;` | `0x577784` |
| 22 | `nativeQueryBool` | `(JI)Z` | `0x577af8` |
| 23 | `nativeSetNativeData` | `(JJ)V` | `0x577b24` |
| 24 | `nativeSetNativeRuntimeModifyFaceData` | `(JJ)V` | `0x577b38` |
| 25 | `nativeGetNativeRuntimeModifyFaceData` | `(J)J` | `0x577b4c` |
| 26 | `nativeGetMemoryUsage` | `(J)J` | `0x577b70` |
| 27 | `nativeGetTotalFaceState` | `(J)I` | `0x577b84` |
| 28 | `nativeGetErrorCache` | `(J)J` | `0x577b98` |
| 29 | `nativeSetMusicVolume` | `(JF)V` | `0x577bbc` |
| 30 | `nativeSetAllPartsAlpha` | `(JF)V` | `0x577bcc` |
| 31 | `nativeParserConfigWithJSONBuffer` | `(JLjava/lang/String;)[J` | `0x577bdc` |
| 32 | `nativeGenConfigJSONBuffer` | `(J)Ljava/lang/String;` | `0x577df0` |
| 33 | `nativeParserMVCommonStickerConfigStruct` | `(JJ)J` | `0x578008` |
| 34 | `nativeParserConfiguration` | `(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;I)J` | `0x578030` |
| 35 | `nativeParserMakeupPartColorConfiguration` | `(JLjava/lang/String;)J` | `0x5781cc` |
| 36 | `nativeDeleteConfiguration` | `(JJ)V` | `0x578348` |
| 37 | `nativeSetAllGroupOrder` | `(J[Ljava/lang/String;)V` | `0x57839c` |
| 38 | `nativeParserGroupConfiguration` | `(JJ)J` | `0x578634` |
| 39 | `nativeDeleteGroupConfiguration` | `(JJ)V` | `0x578668` |
| 40 | `nativeUnloadPart` | `(J)Z` | `0x5786bc` |
| 41 | `nativeReloadPartDefault` | `(J)Z` | `0x5786e4` |
| 42 | `nativeReloadPartControl` | `(J)Z` | `0x57870c` |
| 43 | `nativeGetLoadedPartControl` | `(J)[J` | `0x578734` |
| 44 | `nativeGetFaceliftOffsetPoint` | `(J[F[FII)V` | `0x57885c` |
| 45 | `nativeGetDumpInfo` | `(J)Ljava/lang/String;` | `0x577ee8` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelMVCommonStickerConfigStructJNI`
- **Registration Call RVA:** `0x578eb8`
- **JNINativeMethod Table RVA:** `0x10ce030`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x578c60` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x578c84` |
| 2 | `nativeSetImageData` | `(J[BII)V` | `0x578cb8` |
| 3 | `nativeSetImageDataWithByteBuffer` | `(JLjava/nio/ByteBuffer;II)V` | `0x578d38` |
| 4 | `nativeSetImagePath` | `(JLjava/lang/String;)V` | `0x578d80` |
| 5 | `nativeSetDefaultSize` | `(JII)V` | `0x578e6c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelPartControlInterfaceJNI`
- **Registration Call RVA:** `0x579eb4`
- **JNINativeMethod Table RVA:** `0x10ce0c0`
- **Registered Method Count:** `37`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x578ed8` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x578ee0` |
| 2 | `nativeGetPartTag` | `(J)J` | `0x578ee4` |
| 3 | `nativePrepare` | `(J)Z` | `0x578ef8` |
| 4 | `nativeRelease` | `(J)V` | `0x578f28` |
| 5 | `nativeGetPartTypeToString` | `(J)Ljava/lang/String;` | `0x578f40` |
| 6 | `nativeGetPartType` | `(J)I` | `0x579020` |
| 7 | `nativeGetPartID` | `(J)I` | `0x579034` |
| 8 | `nativeGetPartLayer` | `(J)I` | `0x579048` |
| 9 | `nativeGetPartControlLayer` | `(J)I` | `0x57905c` |
| 10 | `nativeSetPartControlLayer` | `(JI)V` | `0x579070` |
| 11 | `nativeGetPartControlVisible` | `(J)Z` | `0x579084` |
| 12 | `nativeSetPartControlVisible` | `(JZ)V` | `0x5790ac` |
| 13 | `nativePartControlResetState` | `(J)V` | `0x5790c8` |
| 14 | `nativeResetState` | `(J)V` | `0x5790d8` |
| 15 | `nativeGetParamControl` | `(J)[J` | `0x5790e8` |
| 16 | `nativeIsApply` | `(J)Z` | `0x579210` |
| 17 | `nativeSetApply` | `(JZ)V` | `0x579238` |
| 18 | `nativeGetCustomName` | `(J)Ljava/lang/String;` | `0x579254` |
| 19 | `nativeGetGenderType` | `(J)I` | `0x579334` |
| 20 | `nativeSetGenderType` | `(JI)V` | `0x579398` |
| 21 | `nativeGetFaceIDs` | `(J)[I` | `0x5793ac` |
| 22 | `nativeSetFaceIDs` | `(J[I)V` | `0x579578` |
| 23 | `nativeSetFaceIDAlpha` | `(JIF)V` | `0x579878` |
| 24 | `nativeGetFaceIDAlpha` | `(JI)F` | `0x57988c` |
| 25 | `nativeSetFaceIDsAlpha` | `(JIIF)V` | `0x5798a4` |
| 26 | `nativeGetFaceIDsAlpha` | `(JII)F` | `0x5798c4` |
| 27 | `nativeClearFaceIDAlpha` | `(J)V` | `0x5798e8` |
| 28 | `nativeGetCustomParamMap` | `(J)[Ljava/lang/Object;` | `0x579900` |
| 29 | `nativeInsertCustomParam` | `(JLjava/lang/String;Ljava/lang/String;)V` | `0x579bd8` |
| 30 | `nativeGetParamTableType` | `(J)I` | `0x579da8` |
| 31 | `nativeGetParamTableDict` | `(J)J` | `0x579dbc` |
| 32 | `nativeSupportsEyePartEffectAlpha` | `(J)Z` | `0x579de0` |
| 33 | `nativeGetEyePartAlphaSide` | `(J)I` | `0x579e08` |
| 34 | `nativeSetEyePartAlphaSide` | `(JI)V` | `0x579e1c` |
| 35 | `nativeGetEyePartEffectAlpha` | `(JI)F` | `0x579e30` |
| 36 | `nativeSetEyePartEffectAlpha` | `(JIF)Z` | `0x579e48` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelPlistDataInterfaceJNI`
- **Registration Call RVA:** `0x57b124`
- **JNINativeMethod Table RVA:** `0x10ce438`
- **Registered Method Count:** `36`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x579ee8` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x579ef0` |
| 2 | `nativeGetPlistTag` | `(J)J` | `0x579ef4` |
| 3 | `nativeControlResetState` | `(J)V` | `0x579f08` |
| 4 | `nativeResetState` | `(J)V` | `0x579f18` |
| 5 | `nativeGetPartControl` | `(J)[J` | `0x57a104` |
| 6 | `nativeGetAiConfigList` | `(J)[Ljava/lang/String;` | `0x579f28` |
| 7 | `nativePrepare` | `(J)Z` | `0x57a22c` |
| 8 | `nativeRelease` | `(J)V` | `0x57a254` |
| 9 | `nativeIsPrepare` | `(J)Z` | `0x57a264` |
| 10 | `nativeIsApply` | `(J)Z` | `0x57a28c` |
| 11 | `nativeSetApply` | `(JZ)V` | `0x57a2b4` |
| 12 | `nativeHasBGM` | `(J)Z` | `0x57a2d0` |
| 13 | `nativePlayBGM` | `(J)V` | `0x57a2f8` |
| 14 | `nativePauseBGM` | `(J)V` | `0x57a308` |
| 15 | `nativeReplayBGM` | `(J)V` | `0x57a318` |
| 16 | `nativeStopBGM` | `(J)V` | `0x57a328` |
| 17 | `nativeSeekBGM` | `(JF)V` | `0x57a338` |
| 18 | `nativeGetBGMPosition` | `(J)F` | `0x57a348` |
| 19 | `nativeSetBGMPath` | `(JLjava/lang/String;)V` | `0x57a35c` |
| 20 | `nativeGetBGMPath` | `(J)Ljava/lang/String;` | `0x57a448` |
| 21 | `nativeGetConfigBGMPath` | `(J)Ljava/lang/String;` | `0x57a750` |
| 22 | `nativeSetLayer` | `(JI)V` | `0x57a8ec` |
| 23 | `nativeGetLayer` | `(J)I` | `0x57a900` |
| 24 | `nativeIsSpecialFacelift` | `(J)Z` | `0x57a914` |
| 25 | `nativeIsSpecialMakeup` | `(J)Z` | `0x57a93c` |
| 26 | `nativeGetDefaultAlpha` | `(J)I` | `0x57a964` |
| 27 | `nativeIsParseSuccess` | `(J)Z` | `0x57a978` |
| 28 | `nativeGetErrorCode` | `(J)I` | `0x57a9c4` |
| 29 | `nativeGetCustomParamMap` | `(J)[Ljava/lang/Object;` | `0x57ab00` |
| 30 | `nativeInsertCustomParam` | `(JLjava/lang/String;Ljava/lang/String;)V` | `0x57add8` |
| 31 | `nativeGetIsNeedDataRequireType` | `(JI)Z` | `0x57a9d8` |
| 32 | `nativeGetIsSupportMultiplyInstance` | `(J)Z` | `0x57afa8` |
| 33 | `nativeGetPlistDataJSONBuffer` | `(J)Ljava/lang/String;` | `0x57afd0` |
| 34 | `nativeGetMemoryUsage` | `(J)J` | `0x57b0d0` |
| 35 | `nativeGetDumpInfo` | `(J)Ljava/lang/String;` | `0x57a5e4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelPointerDataInterfaceJNI`
- **Registration Call RVA:** `0x57b3e8`
- **JNINativeMethod Table RVA:** `0x10ce798`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57b144` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57b1d8` |
| 2 | `nativeReset` | `(J)V` | `0x57b1f0` |
| 3 | `nativePushPointerData` | `(JLjava/lang/String;Ljava/lang/String;JII)I` | `0x57b208` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelPreviewDataInterfaceJNI`
- **Registration Call RVA:** `0x57b77c`
- **JNINativeMethod Table RVA:** `0x10ce7f8`
- **Registered Method Count:** `15`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57b490` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57b50c` |
| 2 | `nativeReset` | `(J)V` | `0x57b524` |
| 3 | `nativeSetPreviewSize` | `(JII)V` | `0x57b53c` |
| 4 | `nativeGetPreviewSize` | `(J)[F` | `0x57b550` |
| 5 | `nativeSetPreviewResolution` | `(JII)V` | `0x57b5ec` |
| 6 | `nativeGetPreviewResolution` | `(J)[F` | `0x57b600` |
| 7 | `nativeSetIsCaptureFrame` | `(JZ)V` | `0x57b69c` |
| 8 | `nativeGetIsCaptureFrame` | `(J)Z` | `0x57b6b0` |
| 9 | `nativeSetIsContinuousInputStream` | `(JZ)V` | `0x57b6c4` |
| 10 | `nativeGetIsContinuousInputStream` | `(J)Z` | `0x57b6d8` |
| 11 | `nativeSetIsIdenticalInputStream` | `(JZ)V` | `0x57b6ec` |
| 12 | `nativeGetIsIdenticalInputStream` | `(J)Z` | `0x57b700` |
| 13 | `nativeSetIsFirstFrame` | `(JZ)V` | `0x57b714` |
| 14 | `nativeGetIsFirstFrame` | `(J)Z` | `0x57b728` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelShoulderInterfaceJNI`
- **Registration Call RVA:** `0x57c6fc`
- **JNINativeMethod Table RVA:** `0x10ce960`
- **Registered Method Count:** `17`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57b808` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57c07c` |
| 2 | `nativeReset` | `(J)V` | `0x57c094` |
| 3 | `nativeSetShoulderCount` | `(JI)V` | `0x57c120` |
| 4 | `nativeGetShoulderCount` | `(J)I` | `0x57c12c` |
| 5 | `nativeSetShoulderID` | `(JII)V` | `0x57c140` |
| 6 | `nativeGetShoulderID` | `(JI)I` | `0x57c164` |
| 7 | `nativeSetShoulderRect` | `(JIFFFF)V` | `0x57c198` |
| 8 | `nativeGetShoulderRect` | `(JI)[F` | `0x57c1c0` |
| 9 | `nativeSetShoulderRectScore` | `(JIF)V` | `0x57c280` |
| 10 | `nativeSetShoulderPointThreshold` | `(JIF)V` | `0x57c2d8` |
| 11 | `nativeGetShoulderRectScore` | `(JI)F` | `0x57c2a4` |
| 12 | `nativeGetShoulderPointThreshold` | `(JI)F` | `0x57c2f4` |
| 13 | `nativeSetLandmark2D` | `(JI[F)V` | `0x57c328` |
| 14 | `nativeGetLandmark2D` | `(JI)[F` | `0x57c458` |
| 15 | `nativeSetScores` | `(JI[F)V` | `0x57c504` |
| 16 | `nativeGetScores` | `(JI)[F` | `0x57c628` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelTextureDataInterfaceJNI`
- **Registration Call RVA:** `0x57d0c0`
- **JNINativeMethod Table RVA:** `0x10ceaf8`
- **Registered Method Count:** `13`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57cce8` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57ce08` |
| 2 | `nativeReset` | `(J)V` | `0x57ce20` |
| 3 | `nativeSetTextureValidRect` | `(JIIIII)V` | `0x57ce38` |
| 4 | `nativeGetTextureValidRect` | `(JI)[F` | `0x57ce50` |
| 5 | `nativeSetAffineTransformMatrix` | `(JI[F)V` | `0x57cef4` |
| 6 | `nativePushTextureData` | `(JIIII)I` | `0x57cf74` |
| 7 | `nativeGetTextureType` | `(JI)I` | `0x57cfe0` |
| 8 | `nativeGetTextureID` | `(JI)I` | `0x57cffc` |
| 9 | `nativeGetTextureWidth` | `(JI)I` | `0x57d018` |
| 10 | `nativeGetTextureHeight` | `(JI)I` | `0x57d034` |
| 11 | `nativeSetTextureUserDefineFlag` | `(JII)V` | `0x57d050` |
| 12 | `nativeGetTextureUserDefineFlag` | `(JI)I` | `0x57d064` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ARKernelTimeLineDataInterfaceJNI`
- **Registration Call RVA:** `0x57d288`
- **JNINativeMethod Table RVA:** `0x10cec30`
- **Registered Method Count:** `7`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57d1a8` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57d1d4` |
| 2 | `nativeReset` | `(J)V` | `0x57d1ec` |
| 3 | `nativeSetTimeLineType` | `(JI)V` | `0x57d204` |
| 4 | `nativeGetTimeLineType` | `(J)I` | `0x57d210` |
| 5 | `nativeSetInterval` | `(JI)V` | `0x57d224` |
| 6 | `nativeGetInterval` | `(J)I` | `0x57d234` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/interaction/ARKernelCanvasPropertyJNI`
- **Registration Call RVA:** `0x57da20`
- **JNINativeMethod Table RVA:** `0x10cecd8`
- **Registered Method Count:** `57`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x57d2c4` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x57d3d8` |
| 2 | `nativeReset` | `(J)V` | `0x57d3e8` |
| 3 | `nativeSetCanvasSize` | `(JII)V` | `0x57d4f8` |
| 4 | `nativeGetCanvasSize` | `(J)[I` | `0x57d50c` |
| 5 | `nativeSetCanvasDirectionType` | `(JI)V` | `0x57d5a4` |
| 6 | `nativeGetCanvasDirectionType` | `(J)I` | `0x57d5b0` |
| 7 | `nativeSetClickEventTimeValue` | `(JJ)V` | `0x57d5c4` |
| 8 | `nativeGetClickEventTimeValue` | `(J)J` | `0x57d5d0` |
| 9 | `nativeSetClickEventDistanceValue` | `(JI)V` | `0x57d5e4` |
| 10 | `nativeGetClickEventDistanceValue` | `(J)I` | `0x57d5f0` |
| 11 | `nativeSetLayerVertexMarkRadius` | `(JI)V` | `0x57d604` |
| 12 | `nativeGetLayerVertexMarkRadius` | `(J)I` | `0x57d610` |
| 13 | `nativeSetLayerMinValue` | `(JI)V` | `0x57d624` |
| 14 | `nativeGetLayerMinValue` | `(J)I` | `0x57d630` |
| 15 | `nativeSetLayerMaxValue` | `(JI)V` | `0x57d644` |
| 16 | `nativeGetLayerMaxValue` | `(J)I` | `0x57d650` |
| 17 | `nativeSetLayerOutlineBorderMinValue` | `(JI)V` | `0x57d664` |
| 18 | `nativeGetLayerOutlineBorderMinValue` | `(J)I` | `0x57d670` |
| 19 | `nativeSetLayerOutlineBorderMarginLeft` | `(JI)V` | `0x57d684` |
| 20 | `nativeGetLayerOutlineBorderMarginLeft` | `(J)I` | `0x57d690` |
| 21 | `nativeSetLayerOutlineBorderMarginRight` | `(JI)V` | `0x57d6a4` |
| 22 | `nativeGetLayerOutlineBorderMarginRight` | `(J)I` | `0x57d6b0` |
| 23 | `nativeSetLayerOutlineBorderMarginTop` | `(JI)V` | `0x57d6c4` |
| 24 | `nativeGetLayerOutlineBorderMarginTop` | `(J)I` | `0x57d6d0` |
| 25 | `nativeSetLayerOutlineBorderMarginBottom` | `(JI)V` | `0x57d6e4` |
| 26 | `nativeGetLayerOutlineBorderMarginBottom` | `(J)I` | `0x57d6f0` |
| 27 | `nativeSetLayerLimitArea` | `(JZ)V` | `0x57d704` |
| 28 | `nativeGetLayerLimitArea` | `(J)Z` | `0x57d718` |
| 29 | `nativeSetLayerMarginMinValue` | `(JI)V` | `0x57d72c` |
| 30 | `nativeGetLayerMarginMinValue` | `(J)I` | `0x57d738` |
| 31 | `nativeSetLayerMarginLimitOnlyMove` | `(JZ)V` | `0x57d74c` |
| 32 | `nativeGetLayerMarginLimitOnlyMove` | `(J)Z` | `0x57d760` |
| 33 | `nativeSetLayerDoubleTouchRotateValue` | `(JI)V` | `0x57d774` |
| 34 | `nativeGetLayerDoubleTouchRotateValue` | `(J)I` | `0x57d780` |
| 35 | `nativeSetEnableMoveAdsorb` | `(JZ)V` | `0x57d794` |
| 36 | `nativeGetEnableMoveAdsorb` | `(J)Z` | `0x57d7a8` |
| 37 | `nativeSetLayerMoveAdsorbIValue` | `(JI)V` | `0x57d7bc` |
| 38 | `nativeGetLayerMoveAdsorbIValue` | `(J)I` | `0x57d7c8` |
| 39 | `nativeSetLayerMoveAdsorbOValue` | `(JI)V` | `0x57d7dc` |
| 40 | `nativeGetLayerMoveAdsorbOValue` | `(J)I` | `0x57d7e8` |
| 41 | `nativeSetLayerAdsorbDatumLineCount` | `(JI)V` | `0x57d7fc` |
| 42 | `nativeGetLayerAdsorbDatumLineCount` | `(J)I` | `0x57d808` |
| 43 | `nativeSetLayerAdsorbDatumLines` | `(JIII)V` | `0x57d81c` |
| 44 | `nativeGetLayerAdsorbDatumLines` | `(JI)[I` | `0x57d840` |
| 45 | `nativeSetLayerEnableRotateAdsorb` | `(JZ)V` | `0x57d8f0` |
| 46 | `nativeGetLayerEnableRotateAdsorb` | `(J)Z` | `0x57d904` |
| 47 | `nativeSetLayerRotateAdsorbIValue` | `(JI)V` | `0x57d918` |
| 48 | `nativeGetLayerRotateAdsorbIValue` | `(J)I` | `0x57d924` |
| 49 | `nativeSetLayerRotateAdsorbOValue` | `(JI)V` | `0x57d938` |
| 50 | `nativeGetLayerRotateAdsorbOValue` | `(J)I` | `0x57d944` |
| 51 | `nativeSetLayerAdsorbDatumAngleCount` | `(JI)V` | `0x57d958` |
| 52 | `nativeGetLayerAdsorbDatumAngleCount` | `(J)I` | `0x57d964` |
| 53 | `nativeSetLayerAdsorbDatumAngles` | `(JII)V` | `0x57d978` |
| 54 | `nativeGetLayerAdsorbDatumAngles` | `(JI)I` | `0x57d994` |
| 55 | `nativeSetLayerEnableDoubleTouchTranslate` | `(JZ)V` | `0x57d9b8` |
| 56 | `nativeGetLayerEnableDoubleTouchTranslate` | `(J)Z` | `0x57d9cc` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerAnimationInteraction`
- **Registration Call RVA:** `0x581edc`
- **JNINativeMethod Table RVA:** `0x10cf230`
- **Registered Method Count:** `19`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeValid` | `(J)Z` | `0x581668` |
| 1 | `nativeSetConfigPath` | `(JLjava/lang/String;)V` | `0x5816a4` |
| 2 | `nativeGetConfigPath` | `(J)Ljava/lang/String;` | `0x581784` |
| 3 | `nativeSetTotalTime` | `(JF)V` | `0x581864` |
| 4 | `nativeGetTotalTime` | `(J)F` | `0x5818d8` |
| 5 | `nativeSetOnceTime` | `(JF)V` | `0x581904` |
| 6 | `nativeGetOnceTime` | `(J)F` | `0x581978` |
| 7 | `nativeSetSpeed` | `(JF)V` | `0x5819a4` |
| 8 | `nativeGetSpeed` | `(J)F` | `0x581a18` |
| 9 | `nativeSetBeginTimestamp` | `(JF)V` | `0x581a44` |
| 10 | `nativeGetBeginTimestamp` | `(J)F` | `0x581ab8` |
| 11 | `nativeSetEndTimestamp` | `(JF)V` | `0x581ae4` |
| 12 | `nativeGetEndTimestamp` | `(J)F` | `0x581b58` |
| 13 | `nativeSetJsonPath` | `(JLjava/lang/String;)V` | `0x581b84` |
| 14 | `nativeGetJsonPath` | `(J)Ljava/lang/String;` | `0x581c64` |
| 15 | `nativeSetRepeatCount` | `(JI)V` | `0x581d44` |
| 16 | `nativeGetRepeatCount` | `(J)I` | `0x581db8` |
| 17 | `nativeSetShowStaticFrame` | `(JZ)V` | `0x581de4` |
| 18 | `nativeGetShowStaticFrame` | `(J)Z` | `0x581e60` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerInteraction`
- **Registration Call RVA:** `0x583af4`
- **JNINativeMethod Table RVA:** `0x10cf3f8`
- **Registered Method Count:** `56`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetTag` | `(J)J` | `0x581f54` |
| 1 | `nativeSetOriginalSize` | `(JII)V` | `0x581f80` |
| 2 | `nativeGetOriginalSize` | `(J)[I` | `0x581ffc` |
| 3 | `nativeGetFinalSize` | `(J)[I` | `0x5820c0` |
| 4 | `nativeGetDefaultSize` | `(J)[I` | `0x582184` |
| 5 | `nativeSetTimestamp` | `(JJ)V` | `0x582248` |
| 6 | `nativeGetTimestamp` | `(J)J` | `0x5822bc` |
| 7 | `nativeSetTrans` | `(JII)V` | `0x5822e8` |
| 8 | `nativeGetTrans` | `(J)[I` | `0x582364` |
| 9 | `nativeSetScale` | `(JF)V` | `0x582428` |
| 10 | `nativeGetScale` | `(J)F` | `0x58249c` |
| 11 | `nativeSetRotate` | `(JF)V` | `0x5824c8` |
| 12 | `nativeGetRotate` | `(J)F` | `0x58253c` |
| 13 | `nativeSetMirror` | `(JZ)V` | `0x582568` |
| 14 | `nativeGetMirror` | `(J)Z` | `0x5825e4` |
| 15 | `nativeSetVisibility` | `(JZ)V` | `0x582620` |
| 16 | `nativeGetVisibility` | `(J)Z` | `0x58269c` |
| 17 | `nativeSetAreaLimit` | `(JZ)V` | `0x5826d8` |
| 18 | `nativeGetAreaLimit` | `(J)Z` | `0x582754` |
| 19 | `nativeSetAlpha` | `(JF)V` | `0x582790` |
| 20 | `nativeGetAlpha` | `(J)F` | `0x582804` |
| 21 | `nativeSetGlobalColor` | `(JFFF)V` | `0x582830` |
| 22 | `nativeGetGlobalColor` | `(J)[F` | `0x5828a8` |
| 23 | `nativeSetEnableGlobalColor` | `(JZ)V` | `0x58296c` |
| 24 | `nativeGetEnableGlobalColor` | `(J)Z` | `0x5829e8` |
| 25 | `nativeGetBlendMode` | `(J)I` | `0x582a24` |
| 26 | `nativeSetBlendMode` | `(JI)V` | `0x582a50` |
| 27 | `nativeGetBorderVertexPosition` | `(JI)[F` | `0x582ac4` |
| 28 | `nativeGetBorderPadding` | `(JI)F` | `0x582b88` |
| 29 | `nativeAppendAnimation` | `(J)J` | `0x582c04` |
| 30 | `nativeSubtractAnimation` | `(JJ)V` | `0x582c24` |
| 31 | `nativeAnimationList` | `(J)[J` | `0x582c84` |
| 32 | `nativeGetAnimation` | `(JJ)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerAnimationInteraction;` | `0x582d98` |
| 33 | `nativeGetTextFuncStructVector` | `(J)[Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction;` | `0x582e14` |
| 34 | `nativeSetEnableFlip` | `(JZ)V` | `0x582f28` |
| 35 | `nativeGetEnableFlip` | `(J)Z` | `0x582f90` |
| 36 | `nativeSetIsCurrentRenderThumbnail` | `(JZ)V` | `0x582fd4` |
| 37 | `nativeGetIsCurrentRenderThumbnail` | `(J)Z` | `0x583050` |
| 38 | `nativeGetCurrentFinalTrans` | `(J)[I` | `0x58308c` |
| 39 | `nativeGetTouchTransScale` | `(J)F` | `0x583150` |
| 40 | `nativeSetScaleXY` | `(J[F)V` | `0x58317c` |
| 41 | `nativeGetScaleXY` | `(J)[F` | `0x583210` |
| 42 | `nativeSetScissorRect` | `(J[I)V` | `0x5832cc` |
| 43 | `nativeGetScissorRect` | `(J)[I` | `0x583360` |
| 44 | `nativeSetLocalLayerOutlineBorderMinValue` | `(JI)V` | `0x583428` |
| 45 | `nativeSetLocalLayerOutlineBorderMarginLeft` | `(JI)V` | `0x58349c` |
| 46 | `nativeSetLocalLayerOutlineBorderMarginRight` | `(JI)V` | `0x583510` |
| 47 | `nativeSetLocalLayerOutlineBorderMarginTop` | `(JI)V` | `0x583584` |
| 48 | `nativeSetLocalLayerOutlineBorderMarginBottom` | `(JI)V` | `0x5835f8` |
| 49 | `nativeSetEnableSelected` | `(JZ)V` | `0x58366c` |
| 50 | `nativeGetEnableSelected` | `(J)Z` | `0x5836e8` |
| 51 | `nativeGetLockScreen` | `(J)Z` | `0x583724` |
| 52 | `nativeGetDesignedDraggable` | `(J)Z` | `0x583760` |
| 53 | `nativeGetTextInTimestamp` | `(J)F` | `0x58379c` |
| 54 | `nativeGetWatermarConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerInteraction$ARKernelWatermarkConfig;` | `0x5837c8` |
| 55 | `nativeSetWatermarConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerInteraction$ARKernelWatermarkConfig;)V` | `0x583850` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/interaction/ARKernelPublicInteractionService`
- **Registration Call RVA:** `0x585668`
- **JNINativeMethod Table RVA:** `0x10cf938`
- **Registered Method Count:** `23`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x585294` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x5852d4` |
| 2 | `nativeResizeCanvas` | `(JJ)V` | `0x585304` |
| 3 | `nativeRegisterVertexEventMark` | `(J[I)V` | `0x585318` |
| 4 | `nativeTouchBegin` | `(JFFI)V` | `0x5853b0` |
| 5 | `nativeTouchMove` | `(JFFI)V` | `0x5853c4` |
| 6 | `nativeTouchEnd` | `(JFFI)V` | `0x5853d8` |
| 7 | `nativeDispatch` | `(J)V` | `0x5853ec` |
| 8 | `nativeSortLayer` | `(J)V` | `0x5853fc` |
| 9 | `nativeSetInteractionCallbackFunctionStruct` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelInteractionCallback;)V` | `0x58540c` |
| 10 | `nativeFindLayer` | `(JJ)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelLayerInteraction;` | `0x585474` |
| 11 | `nativeGetSelectedLayer` | `(J)J` | `0x5854b0` |
| 12 | `nativeSetSelectedLayer` | `(JJ)V` | `0x5854c4` |
| 13 | `nativeGetLayerVisibility` | `(JJ)Z` | `0x5854d8` |
| 14 | `nativeSetLayerVisibility` | `(JJZ)V` | `0x585504` |
| 15 | `nativeGetLayerAreaLimit` | `(JJ)Z` | `0x585524` |
| 16 | `nativeSetLayerAreaLimit` | `(JJZ)V` | `0x585550` |
| 17 | `nativeGetLayerAlpha` | `(JJ)F` | `0x585570` |
| 18 | `nativeSetLayerAlpha` | `(JJF)V` | `0x585588` |
| 19 | `nativeGetEnablePickup` | `(JJ)Z` | `0x58559c` |
| 20 | `nativeSetEnablePickup` | `(JJZ)V` | `0x5855c8` |
| 21 | `nativeSetEnableDeselect` | `(JZ)V` | `0x5855e8` |
| 22 | `nativeGetEnableDeselect` | `(J)Z` | `0x585600` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction`
- **Registration Call RVA:** `0x589968`
- **JNINativeMethod Table RVA:** `0x10cfb60`
- **Registered Method Count:** `59`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeTextEnum` | `(J)I` | `0x585688` |
| 1 | `nativeGetInputFlag` | `(J)Ljava/lang/String;` | `0x5856b4` |
| 2 | `nativeTextRect` | `(J)[I` | `0x585794` |
| 3 | `nativeGetText` | `(J)[I` | `0x58585c` |
| 4 | `nativeSetText` | `(J[I)V` | `0x585fa4` |
| 5 | `nativeGetMissGlyphText` | `(J)[I` | `0x585c00` |
| 6 | `nativeGetFontLibrary` | `(J)Ljava/lang/String;` | `0x586224` |
| 7 | `nativeSetFontLibrary` | `(JLjava/lang/String;)V` | `0x5863c8` |
| 8 | `nativeGetFontSize` | `(J)F` | `0x5864d4` |
| 9 | `nativeSetFontSize` | `(JF)V` | `0x586500` |
| 10 | `nativeGetColorORGBA` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelColorORGBA;` | `0x586574` |
| 11 | `nativeSetColorORGBA` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelColorORGBA;)V` | `0x5865fc` |
| 12 | `nativeGetIsStaticShow` | `(J)Z` | `0x586800` |
| 13 | `nativeSetIsStaticShow` | `(JZ)V` | `0x58683c` |
| 14 | `nativeGetStrokeConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextStrokeConfig;` | `0x5868b8` |
| 15 | `nativeSetStrokeConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextStrokeConfig;)V` | `0x586940` |
| 16 | `nativeGetShadowConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextShadowConfig;` | `0x586c28` |
| 17 | `nativeSetShadowConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextShadowConfig;)V` | `0x586cb0` |
| 18 | `nativeGetGlowConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGlowConfig;` | `0x58701c` |
| 19 | `nativeSetGlowConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGlowConfig;)V` | `0x5870a4` |
| 20 | `nativeGetBackgroundColorConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextBackgroundColorConfig;` | `0x587418` |
| 21 | `nativeSetBackgroundColorConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextBackgroundColorConfig;)V` | `0x5874a0` |
| 22 | `nativeGetIsBold` | `(J)Z` | `0x58827c` |
| 23 | `nativeSetIsBold` | `(JZ)V` | `0x5882b8` |
| 24 | `nativeGetIsItalic` | `(J)Z` | `0x588334` |
| 25 | `nativeSetIsItalic` | `(JZ)V` | `0x588370` |
| 26 | `nativeGetIsUnderline` | `(J)Z` | `0x5883ec` |
| 27 | `nativeSetIsUnderline` | `(JZ)V` | `0x588428` |
| 28 | `nativeGetIsStrikeThrough` | `(J)Z` | `0x5884a4` |
| 29 | `nativeSetIsStrikeThrough` | `(JZ)V` | `0x5884e0` |
| 30 | `nativeGetJustify` | `(J)I` | `0x58855c` |
| 31 | `nativeSetJustify` | `(JI)V` | `0x588588` |
| 32 | `nativeGetHorizontal` | `(J)Z` | `0x5885fc` |
| 33 | `nativeSetHorizontal` | `(JZ)V` | `0x588638` |
| 34 | `nativeGetLeftToRight` | `(J)Z` | `0x5886b4` |
| 35 | `nativeSetLeftToRight` | `(JZ)V` | `0x5886f0` |
| 36 | `nativeGetWrap` | `(J)Z` | `0x58876c` |
| 37 | `nativeSetWrap` | `(JZ)V` | `0x5887a8` |
| 38 | `nativeGetShrink` | `(J)Z` | `0x588824` |
| 39 | `nativeSetShrink` | `(JZ)V` | `0x588860` |
| 40 | `nativeGetSpacing` | `(J)F` | `0x5888dc` |
| 41 | `nativeSetSpacing` | `(JF)V` | `0x588908` |
| 42 | `nativeGetLineSpacing` | `(J)F` | `0x58897c` |
| 43 | `nativeSetLineSpacing` | `(JF)V` | `0x5889a8` |
| 44 | `nativeGetSubLayerVertex` | `(JI)[F` | `0x588a1c` |
| 45 | `nativeGetTextLayout` | `(J)I` | `0x588ae0` |
| 46 | `nativeSetTextLayout` | `(JI)V` | `0x588b0c` |
| 47 | `nativeGetTextEditableConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextEditableConfig;` | `0x588b80` |
| 48 | `nativeSetTextEditableConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextEditableConfig;)V` | `0x588c10` |
| 49 | `nativeGetGradientConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGradientConfig;` | `0x587a28` |
| 50 | `nativeSetGradientConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextGradientConfig;)V` | `0x587b40` |
| 51 | `nativeGetSequenceStyle` | `(J)I` | `0x588e88` |
| 52 | `nativeSetSequenceStyle` | `(JI)V` | `0x588eb4` |
| 53 | `nativeGetIsVisible` | `(J)Z` | `0x588f28` |
| 54 | `nativeSetIsVisible` | `(JZ)V` | `0x588f64` |
| 55 | `nativeGetTextPathConfig` | `(J)Lcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextPathConfig;` | `0x588fe0` |
| 56 | `nativeSetTextPathConfig` | `(JLcom/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextPathConfig;)V` | `0x5890b0` |
| 57 | `nativeGetTextPathConfigPath` | `(J)Ljava/lang/String;` | `0x589768` |
| 58 | `nativeSetTextPathConfigPath` | `(JLjava/lang/String;)V` | `0x589848` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamBaseJNI`
- **Registration Call RVA:** `0x58a224`
- **JNINativeMethod Table RVA:** `0x10d00e8`
- **Registered Method Count:** `7`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeDispatch` | `(J)V` | `0x589e2c` |
| 1 | `nativeGetParamType` | `(J)I` | `0x589e3c` |
| 2 | `nativeGetParamFlag` | `(J)I` | `0x589e50` |
| 3 | `nativeGetChineseName` | `(J)Ljava/lang/String;` | `0x589e64` |
| 4 | `nativeGetEnglishName` | `(J)Ljava/lang/String;` | `0x589f44` |
| 5 | `nativeGetTraditionalName` | `(J)Ljava/lang/String;` | `0x58a024` |
| 6 | `nativeGetKey` | `(J)Ljava/lang/String;` | `0x58a104` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamColorJNI`
- **Registration Call RVA:** `0x58a4e8`
- **JNINativeMethod Table RVA:** `0x10d0190`
- **Registered Method Count:** `12`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetCurrentColorInfo` | `(JFFF)V` | `0x58a244` |
| 1 | `nativeSetCurrentColorAlpha` | `(JF)V` | `0x58a254` |
| 2 | `nativeSetCurrentColorOpacity` | `(JF)V` | `0x58a264` |
| 3 | `nativeGetCurrentColor` | `(JI)[F` | `0x58a274` |
| 4 | `nativeGetColorType` | `(J)I` | `0x58a348` |
| 5 | `nativeGetCurrentAlpha` | `(J)F` | `0x58a35c` |
| 6 | `nativeGetCurrentOpacity` | `(J)F` | `0x58a370` |
| 7 | `nativeGetDefaultColor` | `(JI)[F` | `0x58a384` |
| 8 | `nativeGetDefaultAlpha` | `(J)F` | `0x58a458` |
| 9 | `nativeGetDefaultOpacity` | `(J)F` | `0x58a46c` |
| 10 | `nativeGetMaxHValue` | `(J)F` | `0x58a480` |
| 11 | `nativeGetMinHValue` | `(J)F` | `0x58a494` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamPositionJNI`
- **Registration Call RVA:** `0x58a654`
- **JNINativeMethod Table RVA:** `0x10d02b0`
- **Registered Method Count:** `14`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetCurrentValueXY` | `(JFF)V` | `0x58a508` |
| 1 | `nativeSetCurrentValueXYZ` | `(JFFF)V` | `0x58a518` |
| 2 | `nativeSetCurrentValueXYZW` | `(JFFFF)V` | `0x58a528` |
| 3 | `nativeGetPositionType` | `(J)I` | `0x58a538` |
| 4 | `nativeGetCurrentX` | `(J)F` | `0x58a54c` |
| 5 | `nativeGetCurrentY` | `(J)F` | `0x58a560` |
| 6 | `nativeGetCurrentZ` | `(J)F` | `0x58a574` |
| 7 | `nativeGetCurrentW` | `(J)F` | `0x58a588` |
| 8 | `nativeGetDefaultX` | `(J)F` | `0x58a59c` |
| 9 | `nativeGetDefaultY` | `(J)F` | `0x58a5b0` |
| 10 | `nativeGetDefaultZ` | `(J)F` | `0x58a5c4` |
| 11 | `nativeGetDefaultW` | `(J)F` | `0x58a5d8` |
| 12 | `nativeGetMaxValue` | `(J)F` | `0x58a5ec` |
| 13 | `nativeGetMinValue` | `(J)F` | `0x58a600` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamSliderJNI`
- **Registration Call RVA:** `0x58a714`
- **JNINativeMethod Table RVA:** `0x10d0400`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetCurrentValue` | `(JF)V` | `0x58a674` |
| 1 | `nativeGetCurrentValue` | `(J)F` | `0x58a684` |
| 2 | `nativeGetDefaultValue` | `(J)F` | `0x58a698` |
| 3 | `nativeGetMaxValue` | `(J)F` | `0x58a6ac` |
| 4 | `nativeGetMinValue` | `(J)F` | `0x58a6c0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamStringJNI`
- **Registration Call RVA:** `0x58aa80`
- **JNINativeMethod Table RVA:** `0x10d0478`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetCurrentValue` | `(JLjava/lang/String;)V` | `0x58a734` |
| 1 | `nativeGetCurrentValue` | `(J)Ljava/lang/String;` | `0x58a7d0` |
| 2 | `nativeGetDefaultValue` | `(J)Ljava/lang/String;` | `0x58a908` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamSwitchJNI`
- **Registration Call RVA:** `0x58ab4c`
- **JNINativeMethod Table RVA:** `0x10d04c0`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetCurrentValue` | `(JZ)V` | `0x58aaa0` |
| 1 | `nativeGetCurrentValue` | `(J)Z` | `0x58aabc` |
| 2 | `nativeGetDefaultValue` | `(J)Z` | `0x58aae4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamTableDictJNI`
- **Registration Call RVA:** `0x58abd4`
- **JNINativeMethod Table RVA:** `0x10d0508`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetTable` | `(JI)J` | `0x58ab6c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/Param/ARKernelParamTableJNI`
- **Registration Call RVA:** `0x58ac70`
- **JNINativeMethod Table RVA:** `0x10d0520`
- **Registered Method Count:** `2`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetParam` | `(JI)J` | `0x58abf4` |
| 1 | `nativeGetParamCount` | `(J)I` | `0x58ac1c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamCheckControlJNI`
- **Registration Call RVA:** `0x58ad54`
- **JNINativeMethod Table RVA:** `0x10d0550`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetDefaultValue` | `(J)Z` | `0x58ac90` |
| 1 | `nativeGetCurrentValue` | `(J)Z` | `0x58acc0` |
| 2 | `nativeSetCurrentValue` | `(JZ)V` | `0x58acf0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamColorControlJNI`
- **Registration Call RVA:** `0x58b194`
- **JNINativeMethod Table RVA:** `0x10d0598`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetDefaultRGBAValue` | `(J)[F` | `0x58ad74` |
| 1 | `nativeGetCurrentRGBAValue` | `(J)[F` | `0x58ae60` |
| 2 | `nativeSetCurrentRGBAValue` | `(J[F)V` | `0x58af4c` |
| 3 | `nativeGetDefaultOpacityValue` | `(J)F` | `0x58b104` |
| 4 | `nativeGetCurrentOpacityValue` | `(J)F` | `0x58b120` |
| 5 | `nativeSetCurrentOpacityValue` | `(JF)V` | `0x58b13c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamControlJNI`
- **Registration Call RVA:** `0x58b414`
- **JNINativeMethod Table RVA:** `0x10d0628`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetParamType` | `(J)I` | `0x58b1b4` |
| 1 | `nativeGetParamFlag` | `(J)I` | `0x58b1d0` |
| 2 | `nativeGetChineseTips` | `(J)Ljava/lang/String;` | `0x58b1ec` |
| 3 | `nativeGetEnglishTips` | `(J)Ljava/lang/String;` | `0x58b2d4` |
| 4 | `nativeDispatch` | `(J)V` | `0x58b3bc` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamSliderControlJNI`
- **Registration Call RVA:** `0x58b634`
- **JNINativeMethod Table RVA:** `0x10d06a0`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetMinValue` | `(J)F` | `0x58b434` |
| 1 | `nativeGetMaxValue` | `(J)F` | `0x58b450` |
| 2 | `nativeGetDefaultValue` | `(J)F` | `0x58b46c` |
| 3 | `nativeGetCurrentValue` | `(J)F` | `0x58b488` |
| 4 | `nativeGetSliderKey` | `(J)Ljava/lang/String;` | `0x58b4a4` |
| 5 | `nativeGetEnable` | `(J)Z` | `0x58b58c` |
| 6 | `nativeSetCurrentValue` | `(JF)V` | `0x58b5bc` |
| 7 | `nativeSetEnable` | `(JZ)V` | `0x58b5d4` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamStringControlJNI`
- **Registration Call RVA:** `0x58b9f0`
- **JNINativeMethod Table RVA:** `0x10d0760`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetDefaultValue` | `(J)Ljava/lang/String;` | `0x58b654` |
| 1 | `nativeGetCurrentValue` | `(J)Ljava/lang/String;` | `0x58b73c` |
| 2 | `nativeGetStringKey` | `(J)Ljava/lang/String;` | `0x58b824` |
| 3 | `nativeSetCurrentValue` | `(JLjava/lang/String;)V` | `0x58b90c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParamControl/ARKernelParamValueControlJNI`
- **Registration Call RVA:** `0x58ba8c`
- **JNINativeMethod Table RVA:** `0x10d07c0`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetDefaultValue` | `(J)I` | `0x58ba10` |
| 1 | `nativeGetCurrentValue` | `(J)I` | `0x58ba24` |
| 2 | `nativeSetCurrentValue` | `(JI)V` | `0x58ba38` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/ParseData/ARKernelGroupDataJNI`
- **Registration Call RVA:** `0x58bebc`
- **JNINativeMethod Table RVA:** `0x10d0808`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `()J` | `0x58baac` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x58bad4` |
| 2 | `nativeSetGroupName` | `(JLjava/lang/String;)V` | `0x58bc20` |
| 3 | `nativeSetGroupAlpha` | `(JF)V` | `0x58bc94` |
| 4 | `nativePushOnePlistUnit` | `(JLjava/lang/String;Ljava/lang/String;)V` | `0x58bca0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `arkernel`
- **Registration Call RVA:** `0x58c86c`
- **JNINativeMethod Table RVA:** `0x10d0880`
- **Registered Method Count:** `9`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x58c1f0` |
| 1 | `nFinalizer` | `(J)V` | `0x58c240` |
| 2 | `nSetMakeupColorAlpha` | `(JI)V` | `0x58c2d8` |
| 3 | `nGetMakeupColorAlpha` | `(J)I` | `0x58c35c` |
| 4 | `nSetMakeupColorRGBA` | `(J[F)V` | `0x58c3e0` |
| 5 | `nGetMakeupColorRGBA` | `(J)[F` | `0x58c538` |
| 6 | `nSetMakeupColorOpacity` | `(JF)V` | `0x58c698` |
| 7 | `nGetMakeupColorOpacity` | `(J)F` | `0x58c724` |
| 8 | `nHaveColor` | `(J)Z` | `0x58c7a8` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/PartControl/ARKernelHairDaubControlInterfaceJNI`
- **Registration Call RVA:** `0x58d238`
- **JNINativeMethod Table RVA:** `0x10d0958`
- **Registered Method Count:** `9`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetDaubModel` | `(JI)V` | `0x58c88c` |
| 1 | `nativeSetBrushSize` | `(JI)V` | `0x58c950` |
| 2 | `nativeSetHairMakingupInfo` | `(JJ)V` | `0x58ccac` |
| 3 | `nativeSetScale` | `(JF)V` | `0x58ca14` |
| 4 | `nativeSetTranslate` | `(JII)V` | `0x58caec` |
| 5 | `nativeAddTranslate` | `(JII)V` | `0x58cbcc` |
| 6 | `nativeDisplay` | `(JIIIII)V` | `0x58cd74` |
| 7 | `nativeSaveHairMask` | `(JLjava/lang/String;)V` | `0x58ce80` |
| 8 | `nativeLoadHairMask` | `(JLjava/lang/String;)V` | `0x58d03c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `arkernel`
- **Registration Call RVA:** `0x58d9a0`
- **JNINativeMethod Table RVA:** `0x10d0a30`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetTransformationPoint` | `(J[FI)V` | `0x58d258` |
| 1 | `nativeGetEnableOption` | `(J)I` | `0x58d35c` |
| 2 | `nativeSetEnableOption` | `(JI)V` | `0x58d410` |
| 3 | `nativeSetManualLongLegParam` | `(JFF)V` | `0x58d4d4` |
| 4 | `nativeSetManualLongLegEnable` | `(JZ)V` | `0x58d5b4` |
| 5 | `nativeSetSlimHeadParam` | `(JFFF)V` | `0x58d67c` |
| 6 | `nativeSetManualSlimming3Param` | `(JFFFFF)V` | `0x58d778` |
| 7 | `nativeSetManualSlimming3Enable` | `(JZ)V` | `0x58d898` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/core/PartControl/ARKernelStaticPartControlInterfaceJNI`
- **Registration Call RVA:** `0x58e2d0`
- **JNINativeMethod Table RVA:** `0x10d0af0`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeGetMUType` | `(J)I` | `0x58d9c0` |
| 1 | `nativeGetHairMidPoints` | `(J)[F` | `0x58da5c` |
| 2 | `nativeSetHairMidPoints` | `(J[F)Z` | `0x58dbbc` |
| 3 | `nativeGetEyeShadowType` | `(J)I` | `0x58de34` |
| 4 | `nativeGetIsGlobalFilter` | `(J)Z` | `0x58dee8` |
| 5 | `nativeGetRectangle` | `(J)[F` | `0x58dfb4` |
| 6 | `nativeGetOperation` | `(J)I` | `0x58e078` |
| 7 | `nativeGetPath` | `(J)Ljava/lang/String;` | `0x58e12c` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/utils/ARKernelFacePickUpJNI`
- **Registration Call RVA:** `0x58e448`
- **JNINativeMethod Table RVA:** `0x10d0bb0`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeProcessDirectionByTouch` | `(IFFIIF[F)[F` | `0x58e2f0` |

---

## Library: `libARKernelInterface.so`
- **Target Class:** `com/meitu/mtlab/arkernelinterface/utils/ARKernelUnicodeConvertJNI`
- **Registration Call RVA:** `0x58ed58`
- **JNINativeMethod Table RVA:** `0x10d0bc8`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeUTF8ToUTF32` | `(Ljava/lang/String;)[I` | `0x58e468` |
| 1 | `nativeUTF8ToUTF32Byte` | `([B)[I` | `0x58e70c` |
| 2 | `nativeUTF32ToUTF8` | `([I)Ljava/lang/String;` | `0x58ead0` |

---

## Library: `libCtaApiLib.so`
- **Target Class:** `cn/com/chinatelecom/account/api/Helper`
- **Registration Call RVA:** `0x13724`
- **JNINativeMethod Table RVA:** `0x88010`
- **Registered Method Count:** `11`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `cepahsul` | `(Z)Ljava/lang/String;` | `0x13788` |
| 1 | `dnepah` | `(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;JZZLjava/lang/String;)Ljava/lang/String;` | `0x13a50` |
| 2 | `dnprecobjs` | `(Landroid/content/Context;JLjava/lang/String;)Ljava/lang/String;` | `0x16734` |
| 3 | `dnprecohdjs` | `()Ljava/lang/String;` | `0x18518` |
| 4 | `guulam` | `(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;` | `0x188e0` |
| 5 | `dnepmret` | `([BLjava/lang/String;)[B` | `0x19218` |
| 6 | `dneulret` | `([B)[B` | `0x18ce0` |
| 7 | `eneulret` | `(Ljava/lang/String;)Ljava/lang/String;` | `0x18edc` |
| 8 | `sgwret` | `(Ljava/lang/String;)Ljava/lang/String;` | `0x19540` |
| 9 | `gscret` | `(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;` | `0x1979c` |
| 10 | `testEncrypt` | `(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;` | `0x19e80` |

---

## Library: `libfntvcrash.so`
- **Target Class:** `cn/fly/tools/xcrash/NativeHandler`
- **Registration Call RVA:** `0x92fc`
- **JNINativeMethod Table RVA:** `0x15600`
- **Registered Method Count:** `7`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeInit` | `(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZZ)I` | `0x936c` |
| 1 | `nativeNotifyJavaCrashed` | `()V` | `0x9ed8` |
| 2 | `fC` | `(Ljava/lang/String;)Ljava/lang/Class;` | `0xb160` |
| 3 | `inv0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;` | `0xb260` |
| 4 | `set0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/Object;)V` | `0xbe88` |
| 5 | `get0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;)Ljava/lang/Object;` | `0xc204` |
| 6 | `nrInit` | `()Z` | `0xc5b8` |

---

## Library: `libglide-webp.so`
- **Target Class:** `com/bumptech/glide/integration/webp/WebpImage`
- **Registration Call RVA:** `0x14650`
- **JNINativeMethod Table RVA:** `0x68000`
- **Registered Method Count:** `238`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateFromDirectByteBuffer` | `(Ljava/nio/ByteBuffer;)Lcom/bumptech/glide/integration/webp/WebpImage;` | `0x13058` |
| 1 | `nativeGetFrame` | `(I)Lcom/bumptech/glide/integration/webp/WebpFrame;` | `0x131b0` |
| 2 | `nativeGetSizeInBytes` | `()I` | `0x13484` |
| 3 | `nativeDispose` | `()V` | `0x13588` |
| 4 | `nativeFinalize` | `()V` | `0x13694` |
| 5 | `nativeRenderFrame` | `(IILandroid/graphics/Bitmap;)V` | `0x13698` |
| 6 | `nativeDispose` | `()V` | `0x13c28` |
| 7 | `nativeFinalize` | `()V` | `0x13d70` |
| 8 | `nativeDecodeStream` | `(Ljava/io/InputStream;Landroid/graphics/BitmapFactory$Options;F[B)Landroid/graphics/Bitmap;` | `0x14a0c` |
| 9 | `nativeDecodeByteArray` | `([BIILandroid/graphics/BitmapFactory$Options;F[B)Landroid/graphics/Bitmap;` | `0x14aa0` |
| 10 | `` | `` | `0x68100` |
| 11 | `` | `` | `0x68118` |
| 12 | ` ` | `(` | `0x68130` |
| 13 | `8` | `@` | `0x68148` |
| 14 | `` | `O{` | `0x381a0` |
| 15 | `O{` | `{C` | `0x382ec` |
| 16 | `O{` | `{` | `0x54f19` |
| 17 | `` | `` | `0x0` |
| 18 | `` | `` | `0x0` |
| 19 | `` | `` | `0x0` |
| 20 | `` | `` | `0x0` |
| 21 | `` | `` | `0x0` |
| 22 | `` | `` | `0x0` |
| 23 | `` | `` | `0x0` |
| 24 | `` | `` | `0x0` |
| 25 | `` | `` | `0x0` |
| 26 | `` | `` | `0x0` |
| 27 | `` | `` | `0x0` |
| 28 | `` | `` | `0x0` |
| 29 | `` | `` | `0x0` |
| 30 | `` | `` | `0x0` |
| 31 | `` | `` | `0x0` |
| 32 | `` | `` | `0x0` |
| 33 | `` | `` | `0x0` |
| 34 | `` | `` | `0x0` |
| 35 | `` | `` | `0x0` |
| 36 | `` | `` | `0x0` |
| 37 | `` | `` | `0x0` |
| 38 | `` | `` | `0x0` |
| 39 | `` | `` | `0x0` |
| 40 | `` | `` | `0x0` |
| 41 | `` | `` | `0x0` |
| 42 | `` | `` | `0x0` |
| 43 | `` | `` | `0x0` |
| 44 | `` | `` | `0x0` |
| 45 | `` | `` | `0x0` |
| 46 | `` | `` | `0x0` |
| 47 | `` | `` | `0x0` |
| 48 | `` | `` | `0x0` |
| 49 | `` | `` | `0x0` |
| 50 | `` | `` | `0x0` |
| 51 | `` | `` | `0x0` |
| 52 | `` | `` | `0x0` |
| 53 | `` | `` | `0x0` |
| 54 | `` | `` | `0x0` |
| 55 | `` | `` | `0x0` |
| 56 | `` | `` | `0x0` |
| 57 | `` | `` | `0x0` |
| 58 | `` | `` | `0x0` |
| 59 | `` | `` | `0x0` |
| 60 | `` | `` | `0x0` |
| 61 | `` | `` | `0x0` |
| 62 | `` | `` | `0x0` |
| 63 | `` | `` | `0x0` |
| 64 | `` | `` | `0x0` |
| 65 | `` | `` | `0x0` |
| 66 | `` | `` | `0x0` |
| 67 | `` | `` | `0x0` |
| 68 | `` | `` | `0x0` |
| 69 | `` | `` | `0x0` |
| 70 | `` | `` | `0x0` |
| 71 | `` | `` | `0x0` |
| 72 | `` | `` | `0x0` |
| 73 | `` | `` | `0x0` |
| 74 | `` | `` | `0x0` |
| 75 | `` | `` | `0x0` |
| 76 | `` | `` | `0x0` |
| 77 | `` | `` | `0x0` |
| 78 | `` | `` | `0x0` |
| 79 | `` | `` | `0x0` |
| 80 | `` | `` | `0x0` |
| 81 | `` | `` | `0x0` |
| 82 | `` | `` | `0x0` |
| 83 | `` | `` | `0x0` |
| 84 | `` | `` | `0x0` |
| 85 | `` | `` | `0x0` |
| 86 | `` | `` | `0x0` |
| 87 | `` | `` | `0x0` |
| 88 | `` | `` | `0x0` |
| 89 | `` | `` | `0x0` |
| 90 | `` | `` | `0x0` |
| 91 | `` | `` | `0x0` |
| 92 | `` | `` | `0x0` |
| 93 | `` | `` | `0x0` |
| 94 | `` | `` | `0x0` |
| 95 | `` | `` | `0x0` |
| 96 | `` | `` | `0x0` |
| 97 | `` | `` | `0x0` |
| 98 | `` | `` | `0x0` |
| 99 | `` | `` | `0x0` |
| 100 | `` | `` | `0x0` |
| 101 | `` | `` | `0x0` |
| 102 | `` | `` | `0x0` |
| 103 | `` | `` | `0x0` |
| 104 | `` | `` | `0x0` |
| 105 | `` | `` | `0x0` |
| 106 | `` | `` | `0x0` |
| 107 | `` | `` | `0x0` |
| 108 | `` | `` | `0x0` |
| 109 | `` | `` | `0x0` |
| 110 | `` | `` | `0x0` |
| 111 | `` | `` | `0x0` |
| 112 | `` | `` | `0x0` |
| 113 | `` | `` | `0x0` |
| 114 | `` | `` | `0x0` |
| 115 | `` | `` | `0x0` |
| 116 | `` | `` | `0x0` |
| 117 | `` | `` | `0x0` |
| 118 | `` | `` | `0x0` |
| 119 | `` | `` | `0x0` |
| 120 | `` | `` | `0x0` |
| 121 | `` | `` | `0x0` |
| 122 | `` | `` | `0x0` |
| 123 | `` | `` | `0x0` |
| 124 | `` | `` | `0x0` |
| 125 | `` | `` | `0x0` |
| 126 | `` | `` | `0x0` |
| 127 | `` | `` | `0x0` |
| 128 | `` | `` | `0x0` |
| 129 | `` | `` | `0x0` |
| 130 | `` | `` | `0x0` |
| 131 | `` | `` | `0x0` |
| 132 | `` | `` | `0x0` |
| 133 | `` | `` | `0x0` |
| 134 | `` | `` | `0x0` |
| 135 | `` | `` | `0x0` |
| 136 | `` | `` | `0x0` |
| 137 | `` | `` | `0x0` |
| 138 | `` | `` | `0x0` |
| 139 | `` | `` | `0x0` |
| 140 | `` | `` | `0x0` |
| 141 | `` | `` | `0x0` |
| 142 | `` | `` | `0x0` |
| 143 | `` | `` | `0x0` |
| 144 | `` | `` | `0x0` |
| 145 | `` | `` | `0x0` |
| 146 | `` | `` | `0x0` |
| 147 | `` | `` | `0x0` |
| 148 | `` | `` | `0x0` |
| 149 | `` | `` | `0x0` |
| 150 | `` | `` | `0x0` |
| 151 | `` | `` | `0x0` |
| 152 | `` | `` | `0x0` |
| 153 | `` | `` | `0x0` |
| 154 | `` | `` | `0x0` |
| 155 | `` | `` | `0x0` |
| 156 | `` | `` | `0x0` |
| 157 | `` | `` | `0x0` |
| 158 | `` | `` | `0x0` |
| 159 | `` | `` | `0x0` |
| 160 | `` | `` | `0x0` |
| 161 | `` | `` | `0x0` |
| 162 | `` | `` | `0x0` |
| 163 | `` | `` | `0x0` |
| 164 | `` | `` | `0x0` |
| 165 | `` | `` | `0x0` |
| 166 | `` | `` | `0x0` |
| 167 | `` | `` | `0x0` |
| 168 | `` | `` | `0x0` |
| 169 | `` | `` | `0x0` |
| 170 | `` | `` | `0x0` |
| 171 | `` | `` | `0x0` |
| 172 | `` | `` | `0x0` |
| 173 | `` | `` | `0x0` |
| 174 | `` | `` | `0x0` |
| 175 | `` | `` | `0x0` |
| 176 | `` | `` | `0x0` |
| 177 | `` | `` | `0x0` |
| 178 | `` | `` | `0x0` |
| 179 | `` | `` | `0x0` |
| 180 | `` | `` | `0x0` |
| 181 | `` | `` | `0x0` |
| 182 | `` | `` | `0x0` |
| 183 | `` | `` | `0x0` |
| 184 | `` | `` | `0x0` |
| 185 | `` | `` | `0x0` |
| 186 | `` | `` | `0x0` |
| 187 | `` | `` | `0x0` |
| 188 | `` | `` | `0x0` |
| 189 | `` | `` | `0x0` |
| 190 | `` | `` | `0x0` |
| 191 | `` | `` | `0x0` |
| 192 | `` | `` | `0x0` |
| 193 | `` | `` | `0x0` |
| 194 | `` | `` | `0x0` |
| 195 | `` | `` | `0x0` |
| 196 | `` | `` | `0x0` |
| 197 | `` | `` | `0x0` |
| 198 | `` | `` | `0x0` |
| 199 | `` | `` | `0x0` |
| 200 | `` | `` | `0x0` |
| 201 | `` | `` | `0x0` |
| 202 | `` | `` | `0x0` |
| 203 | `` | `` | `0x0` |
| 204 | `` | `` | `0x0` |
| 205 | `` | `` | `0x0` |
| 206 | `` | `` | `0x0` |
| 207 | `` | `` | `0x0` |
| 208 | `` | `` | `0x0` |
| 209 | `` | `` | `0x0` |
| 210 | `` | `` | `0x0` |
| 211 | `` | `` | `0x0` |
| 212 | `` | `` | `0x0` |
| 213 | `` | `` | `0x0` |
| 214 | `` | `` | `0x0` |
| 215 | `` | `` | `0x0` |
| 216 | `` | `` | `0x0` |
| 217 | `` | `` | `0x0` |
| 218 | `` | `` | `0x0` |
| 219 | `` | `` | `0x0` |
| 220 | `` | `` | `0x0` |
| 221 | `` | `` | `0x0` |
| 222 | `` | `` | `0x0` |
| 223 | `` | `` | `0x0` |
| 224 | `` | `` | `0x0` |
| 225 | `` | `` | `0x0` |
| 226 | `` | `` | `0x0` |
| 227 | `` | `` | `0x0` |
| 228 | `` | `` | `0x0` |
| 229 | `` | `` | `0x0` |
| 230 | `` | `` | `0x0` |
| 231 | `` | `` | `0x0` |
| 232 | `` | `` | `0x0` |
| 233 | `` | `` | `0x0` |
| 234 | `` | `` | `0x0` |
| 235 | `` | `` | `0x0` |
| 236 | `` | `` | `0x0` |
| 237 | `` | `` | `0x0` |

---

## Library: `libglide-webp.so`
- **Target Class:** `com/bumptech/glide/integration/webp/WebpFrame`
- **Registration Call RVA:** `0x146e0`
- **JNINativeMethod Table RVA:** `0x52397`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `` | `0x0` |
| 1 | `` | `` | `0x0` |
| 2 | `` | `` | `0x0` |
| 3 | `` | `` | `0x0` |
| 4 | `` | `` | `0x0` |

---

## Library: `libKKMusicFX.so`
- **Target Class:** `MTMVCore`
- **Registration Call RVA:** `0x446cc`
- **JNINativeMethod Table RVA:** `0x7f8d0`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `analyzeAudio` | `(Ljava/lang/String;)Lcom/meitu/media/mfx/MFXManager$AudioSourceInfo;` | `0x4473c` |

---

## Library: `libKKMusicFX.so`
- **Target Class:** `com/meitu/media/mfx/EqualizerFX`
- **Registration Call RVA:** `0x44a98`
- **JNINativeMethod Table RVA:** `0x7f8e8`
- **Registered Method Count:** `2`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `_initNative` | `()J` | `0x44b08` |
| 1 | `_setChainSettings` | `(JLcom/meitu/media/mfx/EqualizerFX$ChainSettings;)V` | `0x44b48` |

---

## Library: `libKKMusicFX.so`
- **Target Class:** `com/meitu/media/mfx/KKLoudMeter`
- **Registration Call RVA:** `0x450a8`
- **JNINativeMethod Table RVA:** `0x7f918`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreate` | `(Ljava/lang/String;)J` | `0x45118` |
| 1 | `nativeRelease` | `()V` | `0x451b4` |
| 2 | `setTimeRange` | `(JJ)V` | `0x45220` |
| 3 | `calculateAndWaitLUFS` | `()F` | `0x4525c` |

---

## Library: `libKKMusicFX.so`
- **Target Class:** `com/meitu/media/mfx/MFXFormula`
- **Registration Call RVA:** `0x452c0`
- **JNINativeMethod Table RVA:** `0x7f978`
- **Registered Method Count:** `3`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `_toFormula` | `(J)Ljava/lang/String;` | `0x45330` |
| 1 | `_fromFormula` | `(Ljava/lang/String;)J` | `0x454b8` |
| 2 | `_adjustStrength` | `(Ljava/lang/String;JI)I` | `0x455f4` |

---

## Library: `liblabdeviceinfo.so`
- **Target Class:** `com/meitu/labdeviceinfo/LabDeviceModel`
- **Registration Call RVA:** `0x83a0`
- **JNINativeMethod Table RVA:** `0x21988`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateDeviceModel` | `()Lcom/meitu/labdeviceinfo/LabDeviceModel;` | `0x0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAiModelInfo`
- **Registration Call RVA:** `0x2b8b24`
- **JNINativeMethod Table RVA:** `0x531040`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `nCreate` | `0x1d8879` |
| 1 | `{` | `nDestroy` | `0x1e29a1` |
| 2 | `` | `getKey` | `0x1e7e9b` |
| 3 | `	{O` | `setKey` | `0x1e6a3a` |
| 4 | `{O` | `getModuleDirPath` | `0x1e7e9b` |
| 5 | `A`` | `setModuleDirPath` | `0x1e6a3a` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAigcCacheData`
- **Registration Call RVA:** `0x2bbd5c`
- **JNINativeMethod Table RVA:** `0x5310d8`
- **Registered Method Count:** `24`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2b8d20` |
| 1 | `nDestroy` | `(J)V` | `0x2b8db4` |
| 2 | `nGetOpenEyeMode` | `(J)I` | `0x2b8fac` |
| 3 | `nSetOpenEyeMode` | `(JI)V` | `0x2b8fc0` |
| 4 | `nGetFaceReshapeAigcCache` | `(J)Ljava/util/Map;` | `0x2b8fcc` |
| 5 | `nSetFaceReshapeAigcCache` | `(JLjava/util/Map;)V` | `0x2b9670` |
| 6 | `nGetGazeCorrectAigcCache` | `(J)Ljava/util/Map;` | `0x2b9d04` |
| 7 | `nSetGazeCorrectAigcCache` | `(JLjava/util/Map;)V` | `0x2ba344` |
| 8 | `nGetBody3DEffectAigcCache` | `(J)Ljava/util/Map;` | `0x2ba680` |
| 9 | `nSetBody3DEffectAigcCache` | `(JLjava/util/Map;)V` | `0x2bacb8` |
| 10 | `nGetStraightLegsAigcCache` | `(J)J` | `0x2bb0dc` |
| 11 | `nSetStraightLegsAigcCache` | `(JJ)V` | `0x2bb2c0` |
| 12 | `nGetThinBellyAigcCache` | `(J)J` | `0x2bb38c` |
| 13 | `nSetThinBellyAigcCache` | `(JJ)V` | `0x2bb440` |
| 14 | `nGetOneKeyBodyAigcCache` | `(J)J` | `0x2bb554` |
| 15 | `nSetOneKeyBodyAigcCache` | `(JJ)V` | `0x2bb608` |
| 16 | `nSaveSmileImage` | `(JLjava/lang/String;)Z` | `0x2bb71c` |
| 17 | `nLoadSmileImage` | `(JLjava/lang/String;)Z` | `0x2bb7dc` |
| 18 | `nSaveSmileFixImage` | `(JLjava/lang/String;)Z` | `0x2bb89c` |
| 19 | `nLoadSmileFixImage` | `(JLjava/lang/String;)Z` | `0x2bb95c` |
| 20 | `nSaveMakeupRepairAigcResult` | `(JLjava/lang/String;)Z` | `0x2bba1c` |
| 21 | `nLoadMakeupRepairAigcResult` | `(JLjava/lang/String;)Z` | `0x2bbadc` |
| 22 | `nSaveFleckFlawAigcResult` | `(JLjava/lang/String;)Z` | `0x2bbb9c` |
| 23 | `nLoadFleckFlawAigcResult` | `(JLjava/lang/String;)Z` | `0x2bbc5c` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoDermabrasionData$AutoDermabrasionModular`
- **Registration Call RVA:** `0x2c1e08`
- **JNINativeMethod Table RVA:** `0x531da8`
- **Registered Method Count:** `7`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroy` | `(J)V` | `0x2c1c40` |
| 1 | `nGetModular` | `(J)Ljava/lang/String;` | `0x2c1c7c` |
| 2 | `nSetModular` | `(JLjava/lang/String;)V` | `0x2c1c84` |
| 3 | `nIsEnable` | `(J)Z` | `0x2c1d04` |
| 4 | `nSetEnable` | `(JZ)V` | `0x2c1d0c` |
| 5 | `nGetInfoPointer` | `(J)J` | `0x2c1d1c` |
| 6 | `nSetInfo` | `(JJ)V` | `0x2c1d50` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoDermabrasionData$AutoDermabrasionModular`
- **Registration Call RVA:** `0x2c1e48`
- **JNINativeMethod Table RVA:** `0x531e50`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2c1d64` |
| 1 | `nDestroy` | `(J)V` | `0x2c1d88` |
| 2 | `nGetFaceLevel` | `(J)I` | `0x2c1d98` |
| 3 | `nSetFaceLevel` | `(JI)V` | `0x2c1da0` |
| 4 | `nGetBodyLevel` | `(J)I` | `0x2c1da8` |
| 5 | `nSetBodyLevel` | `(JI)V` | `0x2c1db0` |
| 6 | `nGetSmoothType` | `(J)I` | `0x2c1db8` |
| 7 | `nSetSmoothType` | `(JI)V` | `0x2c1dc0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoSlimData$AutoSlimModular`
- **Registration Call RVA:** `0x2c2348`
- **JNINativeMethod Table RVA:** `0x531f10`
- **Registered Method Count:** `10`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroy` | `(J)V` | `0x2c1e70` |
| 1 | `nGetModular` | `(J)Ljava/lang/String;` | `0x2c1eb4` |
| 2 | `nSetModular` | `(JLjava/lang/String;)V` | `0x2c1ebc` |
| 3 | `nIsEnable` | `(J)Z` | `0x2c1f3c` |
| 4 | `nSetEnable` | `(JZ)V` | `0x2c1f44` |
| 5 | `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2c1f54` |
| 6 | `nGetFaceDataByFaceId` | `(JI)J` | `0x2c2028` |
| 7 | `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2c20a4` |
| 8 | `nPutFaceDataByFaceId` | `(JIJ)V` | `0x2c2168` |
| 9 | `nClearFaceData` | `(J)V` | `0x2c2240` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoSlimData$AutoSlimModular`
- **Registration Call RVA:** `0x2c2388`
- **JNINativeMethod Table RVA:** `0x532000`
- **Registered Method Count:** `14`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2c2270` |
| 1 | `nDestroy` | `(J)V` | `0x2c2290` |
| 2 | `nGetFace` | `(J)I` | `0x2c22a0` |
| 3 | `nSetFace` | `(JI)V` | `0x2c22a8` |
| 4 | `nGetLeg` | `(J)I` | `0x2c22b0` |
| 5 | `nSetLeg` | `(JI)V` | `0x2c22b8` |
| 6 | `nGetWaist` | `(J)I` | `0x2c22c0` |
| 7 | `nSetWaist` | `(JI)V` | `0x2c22c8` |
| 8 | `nGetArm` | `(J)I` | `0x2c22d0` |
| 9 | `nSetArm` | `(JI)V` | `0x2c22d8` |
| 10 | `nGetNeckThin` | `(J)I` | `0x2c22e0` |
| 11 | `nSetNeckThin` | `(JI)V` | `0x2c22e8` |
| 12 | `nIsOneKey` | `(J)Z` | `0x2c22f0` |
| 13 | `nSetOneKey` | `(JZ)V` | `0x2c22f8` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoWrinkleCleanData$AutoWrinkleCleanModular`
- **Registration Call RVA:** `0x2c2c98`
- **JNINativeMethod Table RVA:** `0x532150`
- **Registered Method Count:** `10`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroy` | `(J)V` | `0x2c27c0` |
| 1 | `nGetModular` | `(J)Ljava/lang/String;` | `0x2c2804` |
| 2 | `nSetModular` | `(JLjava/lang/String;)V` | `0x2c280c` |
| 3 | `nIsEnable` | `(J)Z` | `0x2c288c` |
| 4 | `nSetEnable` | `(JZ)V` | `0x2c2894` |
| 5 | `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2c28a4` |
| 6 | `nGetFaceDataByFaceId` | `(JI)J` | `0x2c2978` |
| 7 | `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2c29f4` |
| 8 | `nPutFaceDataByFaceId` | `(JIJ)V` | `0x2c2ab8` |
| 9 | `nClearFaceData` | `(J)V` | `0x2c2b90` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFAutoWrinkleCleanData$AutoWrinkleCleanModular`
- **Registration Call RVA:** `0x2c2cd8`
- **JNINativeMethod Table RVA:** `0x532240`
- **Registered Method Count:** `14`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2c2bc0` |
| 1 | `nDestroy` | `(J)V` | `0x2c2be0` |
| 2 | `nGetForeheadLevel` | `(J)I` | `0x2c2bf0` |
| 3 | `nSetForeheadLevel` | `(JI)V` | `0x2c2bf8` |
| 4 | `nGetNeckLevel` | `(J)I` | `0x2c2c00` |
| 5 | `nSetNeckLevel` | `(JI)V` | `0x2c2c08` |
| 6 | `nGetEyeLevel` | `(J)I` | `0x2c2c10` |
| 7 | `nSetEyeLevel` | `(JI)V` | `0x2c2c18` |
| 8 | `nGetNasoLevel` | `(J)I` | `0x2c2c20` |
| 9 | `nSetNasoLevel` | `(JI)V` | `0x2c2c28` |
| 10 | `nGetLipLevel` | `(J)I` | `0x2c2c30` |
| 11 | `nSetLipLevel` | `(JI)V` | `0x2c2c38` |
| 12 | `nIsOneKey` | `(J)Z` | `0x2c2c40` |
| 13 | `nSetOneKey` | `(JZ)V` | `0x2c2c48` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFBody3DEffectRequestResult`
- **Registration Call RVA:** `0x2c53ac`
- **JNINativeMethod Table RVA:** `0x532930`
- **Registered Method Count:** `14`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2c3afc` |
| 1 | `nDestroy` | `(J)V` | `0x2c3b90` |
| 2 | `nGetIntrinsicMatrix` | `(J)Ljava/util/Map;` | `0x2c3c24` |
| 3 | `nSetIntrinsicMatrix` | `(JLjava/util/Map;)V` | `0x2c3d9c` |
| 4 | `nGetExtrinsicMatrix` | `(J)Ljava/util/Map;` | `0x2c4358` |
| 5 | `nSetExtrinsicMatrix` | `(JLjava/util/Map;)V` | `0x2c44d0` |
| 6 | `nGetVertices` | `(J)Ljava/util/Map;` | `0x2c457c` |
| 7 | `nSetVertices` | `(JLjava/util/Map;)V` | `0x2c46f4` |
| 8 | `nGetDirection` | `(J)Ljava/util/Map;` | `0x2c47a0` |
| 9 | `nSetDirection` | `(JLjava/util/Map;)V` | `0x2c4918` |
| 10 | `nGetBodyRect` | `(J)Ljava/util/Map;` | `0x2c49c4` |
| 11 | `nSetBodyRect` | `(JLjava/util/Map;)V` | `0x2c4b3c` |
| 12 | `nGetBody2dKpts` | `(J)Ljava/util/Map;` | `0x2c4d8c` |
| 13 | `nSetBody2dKpts` | `(JLjava/util/Map;)V` | `0x2c4f04` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFEffectOneClickBeautyData$LFOneClickBeautyResult`
- **Registration Call RVA:** `0x2d1ae8`
- **JNINativeMethod Table RVA:** `0x1ec8fc`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `` | `0x0` |
| 1 | `` | `` | `0x0` |
| 2 | `` | `` | `0x0` |
| 3 | `` | `` | `0x0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFFaceRemoldData$FaceRemoldModular`
- **Registration Call RVA:** `0x2e0818`
- **JNINativeMethod Table RVA:** `0x537648`
- **Registered Method Count:** `10`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroy` | `(J)V` | `0x2de620` |
| 1 | `nGetModular` | `(J)Ljava/lang/String;` | `0x2de698` |
| 2 | `nSetModular` | `(JLjava/lang/String;)V` | `0x2de6b8` |
| 3 | `nIsEnable` | `(J)Z` | `0x2de738` |
| 4 | `nSetEnable` | `(JZ)V` | `0x2de740` |
| 5 | `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2de750` |
| 6 | `nGetFaceDataByFaceId` | `(JI)J` | `0x2de810` |
| 7 | `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2dea7c` |
| 8 | `nPutFaceDataByFaceId` | `(JIJ)V` | `0x2dead8` |
| 9 | `nClearFaceData` | `(J)V` | `0x2dec4c` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFFaceRemoldData$FaceRemoldModular`
- **Registration Call RVA:** `0x2e0858`
- **JNINativeMethod Table RVA:** `0x537738`
- **Registered Method Count:** `12`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2dec7c` |
| 1 | `nDestroy` | `(J)V` | `0x2decf4` |
| 2 | `nGetFeatureParamDictListSize` | `(J)I` | `0x2ded98` |
| 3 | `nGetFeatureParamDictListKeys` | `(JI)[Ljava/lang/String;` | `0x2dedb4` |
| 4 | `nGetFeatureParamDictListValue` | `(JILjava/lang/String;)[Ljava/lang/Integer;` | `0x2def04` |
| 5 | `nSetFeatureParamDictListValueForIndex` | `(JILjava/lang/String;[Ljava/lang/Integer;)V` | `0x2df1c0` |
| 6 | `nGetMaterialModelList` | `(J)[J` | `0x2df654` |
| 7 | `nSetMaterialModelList` | `(J[J)V` | `0x2df740` |
| 8 | `nGetSmartMaterialPointer` | `(J)J` | `0x2df840` |
| 9 | `nSetSmartMaterial` | `(JJ)V` | `0x2df878` |
| 10 | `nSetEnableBackground` | `(JZ)V` | `0x2df890` |
| 11 | `nGetEnableBackground` | `(J)Z` | `0x2df8a4` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFFaceRemoldData$FaceRemoldInfo`
- **Registration Call RVA:** `0x2e0898`
- **JNINativeMethod Table RVA:** `0x537858`
- **Registered Method Count:** `18`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2df8ac` |
| 1 | `nDestroy` | `(J)V` | `0x2df914` |
| 2 | `nGetEyesType` | `(J)I` | `0x2df960` |
| 3 | `nSetEyesType` | `(JI)V` | `0x2df968` |
| 4 | `nIsHasSmileEffect` | `(J)Z` | `0x2df970` |
| 5 | `nSetHasSmileEffect` | `(JZ)V` | `0x2df978` |
| 6 | `nGetIndex` | `(J)I` | `0x2df988` |
| 7 | `nSetIndex` | `(JI)V` | `0x2df990` |
| 8 | `nIsFixed` | `(J)Z` | `0x2df998` |
| 9 | `nSetFixed` | `(JZ)V` | `0x2df9a0` |
| 10 | `nIsVip` | `(J)Z` | `0x2df9b0` |
| 11 | `nSetVip` | `(JZ)V` | `0x2df9b8` |
| 12 | `nGetAlpha` | `(J)F` | `0x2df9c8` |
| 13 | `nSetAlpha` | `(JF)V` | `0x2df9d0` |
| 14 | `nGetMaterialId` | `(J)J` | `0x2df9d8` |
| 15 | `nSetMaterialId` | `(JJ)V` | `0x2df9e0` |
| 16 | `nGetPreOperation` | `(J)I` | `0x2df9e8` |
| 17 | `nSetPreOperation` | `(JI)V` | `0x2df9f0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFFaceRemoldData$FaceRemoldMaterialParam`
- **Registration Call RVA:** `0x2e08d8`
- **JNINativeMethod Table RVA:** `0x537a08`
- **Registered Method Count:** `13`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroyResult` | `(J)V` | `0x2df9f8` |
| 1 | `nGetDurationByType` | `(JLjava/lang/String;)F` | `0x2dfb9c` |
| 2 | `nGetHasDoEffect` | `(J)Z` | `0x2dfdc0` |
| 3 | `nGetOpenEyeMode` | `(J)I` | `0x2dfdc8` |
| 4 | `nGetFaceResult` | `(J)Ljava/lang/Object;` | `0x2dfdd0` |
| 5 | `nGetBackgroundImage` | `(J)Landroid/graphics/Bitmap;` | `0x2dfea8` |
| 6 | `nGetBackgroundMaskImage` | `(J)Landroid/graphics/Bitmap;` | `0x2e0034` |
| 7 | `nGetSmileImage` | `(J)Landroid/graphics/Bitmap;` | `0x2e01c0` |
| 8 | `nGetSmileFixImage` | `(J)Landroid/graphics/Bitmap;` | `0x2e034c` |
| 9 | `nSaveBackground` | `(JLjava/lang/String;)Z` | `0x2e04d8` |
| 10 | `nSaveBackgroundMask` | `(JLjava/lang/String;)Z` | `0x2e0598` |
| 11 | `nSaveSmileImage` | `(JLjava/lang/String;)Z` | `0x2e0658` |
| 12 | `nSaveSmileFixImage` | `(JLjava/lang/String;)Z` | `0x2e0718` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFImageWithPath`
- **Registration Call RVA:** `0x2e66b8`
- **JNINativeMethod Table RVA:** `0x538308`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2e632c` |
| 1 | `nDestroy` | `(J)V` | `0x2e637c` |
| 2 | `nGetPath` | `(J)Ljava/lang/String;` | `0x2e6418` |
| 3 | `nSetPath` | `(JLjava/lang/String;)V` | `0x2e6450` |
| 4 | `nSaveImageTo` | `(JLjava/lang/String;)Z` | `0x2e64f8` |
| 5 | `nLoadImageFrom` | `(JLjava/lang/String;)Z` | `0x2e65b8` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFLiveStickerData$LFLiveStickerModular`
- **Registration Call RVA:** `0x2e6778`
- **JNINativeMethod Table RVA:** `0x1ec911`
- **Registered Method Count:** `33`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `` | `0x0` |
| 1 | `` | `` | `0x0` |
| 2 | `` | `` | `0x0` |
| 3 | `` | `` | `0x0` |
| 4 | `` | `` | `0x0` |
| 5 | `` | `` | `0x0` |
| 6 | `` | `` | `0x0` |
| 7 | `` | `` | `0x0` |
| 8 | `` | `` | `0x0` |
| 9 | `` | `` | `0x0` |
| 10 | `` | `` | `0x0` |
| 11 | `` | `` | `0x0` |
| 12 | `` | `` | `0x0` |
| 13 | `` | `` | `0x0` |
| 14 | `` | `` | `0x0` |
| 15 | `` | `` | `0x0` |
| 16 | `` | `` | `0x0` |
| 17 | `` | `` | `0x0` |
| 18 | `` | `` | `0x0` |
| 19 | `` | `` | `0x0` |
| 20 | `` | `` | `0x0` |
| 21 | `` | `` | `0x0` |
| 22 | `` | `` | `0x0` |
| 23 | `` | `` | `0x0` |
| 24 | `` | `` | `0x0` |
| 25 | `` | `` | `0x0` |
| 26 | `` | `` | `0x0` |
| 27 | `` | `` | `0x0` |
| 28 | `` | `` | `0x0` |
| 29 | `` | `` | `0x0` |
| 30 | `` | `` | `0x0` |
| 31 | `` | `` | `0x0` |
| 32 | `` | `` | `0x0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$LFSkinWhitenRuntimeData`
- **Registration Call RVA:** `0x2ef4f8`
- **JNINativeMethod Table RVA:** `0x539510`
- **Registered Method Count:** `4`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2edd48` |
| 1 | `nDestroy` | `(J)V` | `0x2edd64` |
| 2 | `nGetFleckFlowForceLocal` | `(J)Z` | `0x2edd74` |
| 3 | `nSetFleckFlowForceLocal` | `(JZ)V` | `0x2edd88` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$LFSkinWhitenRuntimeData`
- **Registration Call RVA:** `0x2ef538`
- **JNINativeMethod Table RVA:** `0x539570`
- **Registered Method Count:** `10`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroy` | `(J)V` | `0x2ee354` |
| 1 | `nGetModular` | `(J)Ljava/lang/String;` | `0x2edda0` |
| 2 | `nSetModular` | `(JLjava/lang/String;)V` | `0x2eddc0` |
| 3 | `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2ede40` |
| 4 | `nGetFaceDataByFaceId` | `(JI)J` | `0x2edf00` |
| 5 | `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2ee0fc` |
| 6 | `nPutFaceDataByFaceId` | `(JIJ)V` | `0x2ee158` |
| 7 | `nClearFaceData` | `(J)V` | `0x2ee30c` |
| 8 | `nIsEnable` | `(J)Z` | `0x2ee33c` |
| 9 | `nSetEnable` | `(JZ)V` | `0x2ee344` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$SkinWhitenModular`
- **Registration Call RVA:** `0x2ef578`
- **JNINativeMethod Table RVA:** `0x539660`
- **Registered Method Count:** `30`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2ee3cc` |
| 1 | `nDestroy` | `(J)V` | `0x2eea38` |
| 2 | `nGetDegree` | `(J)I` | `0x2ee47c` |
| 3 | `nSetDegree` | `(JI)V` | `0x2ee484` |
| 4 | `nGetEven` | `(J)I` | `0x2ee48c` |
| 5 | `nSetEven` | `(JI)V` | `0x2ee494` |
| 6 | `nGetMaterialPointer` | `(J)J` | `0x2ee49c` |
| 7 | `nSetMaterial` | `(JJ)V` | `0x2ee4c8` |
| 8 | `nGetTemperature` | `(J)I` | `0x2ee4dc` |
| 9 | `nSetTemperature` | `(JI)V` | `0x2ee4e4` |
| 10 | `nIsToneUniform` | `(J)Z` | `0x2ee4ec` |
| 11 | `nSetToneUniform` | `(JZ)V` | `0x2ee4f4` |
| 12 | `nGetUniform` | `(J)I` | `0x2ee504` |
| 13 | `nSetUniform` | `(JI)V` | `0x2ee50c` |
| 14 | `nGetUniformType` | `(J)I` | `0x2ee514` |
| 15 | `nSetUniformType` | `(JI)V` | `0x2ee51c` |
| 16 | `nGetAutoCustomColor` | `(J)Ljava/lang/String;` | `0x2ee524` |
| 17 | `nSetAutoCustomColor` | `(JLjava/lang/String;)V` | `0x2ee544` |
| 18 | `nGetWakeSkinPointer` | `(J)J` | `0x2ee5c4` |
| 19 | `nSetWakeSkin` | `(JJ)V` | `0x2ee608` |
| 20 | `nGetBodyEffectSteps` | `(J)[I` | `0x2ee62c` |
| 21 | `nSetBodyEffectSteps` | `(J[I)V` | `0x2ee6ac` |
| 22 | `nIsFleckFlaw` | `(J)Z` | `0x2ee960` |
| 23 | `nSetFleckFlaw` | `(JZ)V` | `0x2ee968` |
| 24 | `nGetCustomWhitenMaterialId` | `(J)J` | `0x2ee978` |
| 25 | `nSetCustomWhitenMaterialId` | `(JJ)V` | `0x2ee980` |
| 26 | `nGetCustomWhitenMaterialType` | `(J)I` | `0x2ee988` |
| 27 | `nSetCustomWhitenMaterialType` | `(JI)V` | `0x2ee990` |
| 28 | `nGetBodySkinCustomColor` | `(J)Ljava/lang/String;` | `0x2ee998` |
| 29 | `nSetBodySkinCustomColor` | `(JLjava/lang/String;)V` | `0x2ee9b8` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$SkinWhitenInfo`
- **Registration Call RVA:** `0x2ef5b8`
- **JNINativeMethod Table RVA:** `0x539930`
- **Registered Method Count:** `32`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2eeab4` |
| 1 | `nDestroy` | `(J)V` | `0x2eed28` |
| 2 | `nGetSkinType` | `(J)I` | `0x2eeb28` |
| 3 | `nSetSkinType` | `(JI)V` | `0x2eeb30` |
| 4 | `nGetConcealer` | `(J)I` | `0x2eeb38` |
| 5 | `nSetConcealer` | `(JI)V` | `0x2eeb40` |
| 6 | `nGetClarity` | `(J)I` | `0x2eeb48` |
| 7 | `nSetClarity` | `(JI)V` | `0x2eeb50` |
| 8 | `nGetLight` | `(J)I` | `0x2eeb58` |
| 9 | `nSetLight` | `(JI)V` | `0x2eeb60` |
| 10 | `nGetMatte` | `(J)I` | `0x2eeb68` |
| 11 | `nSetMatte` | `(JI)V` | `0x2eeb70` |
| 12 | `nGetHightLight` | `(J)I` | `0x2eeb78` |
| 13 | `nSetHightLight` | `(JI)V` | `0x2eeb80` |
| 14 | `nGetSkinBeauty` | `(J)I` | `0x2eeb88` |
| 15 | `nSetSkinBeauty` | `(JI)V` | `0x2eeb90` |
| 16 | `nGetSurface` | `(J)I` | `0x2eeb98` |
| 17 | `nSetSurface` | `(JI)V` | `0x2eeba0` |
| 18 | `nGetSkinColor` | `(J)I` | `0x2eeba8` |
| 19 | `nSetSkinColor` | `(JI)V` | `0x2eebb0` |
| 20 | `nGetSmooth` | `(J)I` | `0x2eebb8` |
| 21 | `nSetSmooth` | `(JI)V` | `0x2eebc0` |
| 22 | `nGetTexture` | `(J)I` | `0x2eebc8` |
| 23 | `nSetTexture` | `(JI)V` | `0x2eebd0` |
| 24 | `nGetBodyDodgeBurnAlpha` | `(J)I` | `0x2eebd8` |
| 25 | `nSetBodyDodgeBurnAlpha` | `(JI)V` | `0x2eebe0` |
| 26 | `nIsBodyConcealer` | `(J)Z` | `0x2eebe8` |
| 27 | `nSetBodyConcealer` | `(JZ)V` | `0x2eebf0` |
| 28 | `nGetMaterialType` | `(J)I` | `0x2eebfc` |
| 29 | `nSetMaterialType` | `(JI)V` | `0x2eec04` |
| 30 | `nGetBeautyGlowPointer` | `(J)J` | `0x2eec0c` |
| 31 | `nSetBeautyGlow` | `(JJ)V` | `0x2eec50` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$SkinWhitenWakeSkinParam`
- **Registration Call RVA:** `0x2ef5f8`
- **JNINativeMethod Table RVA:** `0x539c30`
- **Registered Method Count:** `8`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2eec8c` |
| 1 | `nDestroy` | `(J)V` | `0x2eecac` |
| 2 | `nGetFaceGlowAlpha` | `(J)D` | `0x2eecf8` |
| 3 | `nSetFaceGlowAlpha` | `(JD)V` | `0x2eed00` |
| 4 | `nGetBodyGlowAlpha` | `(J)D` | `0x2eed08` |
| 5 | `nSetBodyGlowAlpha` | `(JD)V` | `0x2eed10` |
| 6 | `nGetMaterialId` | `(J)J` | `0x2eed18` |
| 7 | `nSetMaterialId` | `(JJ)V` | `0x2eed20` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$SkinWhitenBeautyGlowParams`
- **Registration Call RVA:** `0x2ef638`
- **JNINativeMethod Table RVA:** `0x539cf0`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2eed74` |
| 1 | `nDestroy` | `(J)V` | `0x2eede4` |
| 2 | `nGetMaterialId` | `(J)J` | `0x2eedbc` |
| 3 | `nSetMaterialId` | `(JJ)V` | `0x2eedc4` |
| 4 | `nIsVip` | `(J)Z` | `0x2eedcc` |
| 5 | `nSetVip` | `(JZ)V` | `0x2eedd4` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFSkinWhitenData$SkinWhitenMaterialParam`
- **Registration Call RVA:** `0x2ef678`
- **JNINativeMethod Table RVA:** `0x539d80`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nDestroyResult` | `(J)V` | `0x2eee30` |
| 1 | `nGetDurationByType` | `(JLjava/lang/String;)F` | `0x2eeef8` |
| 2 | `nGetHasDoEffect` | `(J)Z` | `0x2ef130` |
| 3 | `nGetFaceResult` | `(J)Ljava/lang/Object;` | `0x2ef138` |
| 4 | `nGetBodyEffectCacheImageMap` | `(J)Ljava/util/Map;` | `0x2ef210` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `com/layer/flow/datas/LFStraightLegsAIGCRequestResult`
- **Registration Call RVA:** `0x2f20e8`
- **JNINativeMethod Table RVA:** `0x53a570`
- **Registered Method Count:** `6`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0x2f12e8` |
| 1 | `nDestroy` | `(J)V` | `0x2f1338` |
| 2 | `nGetImageList` | `(J)[J` | `0x2f1408` |
| 3 | `nSetImageList` | `(J[J)V` | `0x2f1934` |
| 4 | `nGetBboxLoc` | `(J)[I` | `0x2f1cd4` |
| 5 | `nSetBboxLoc` | `(J[I)V` | `0x2f1d60` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `mtik_`
- **Registration Call RVA:** `0x2f23cc`
- **JNINativeMethod Table RVA:** `0x1ec8fc`
- **Registered Method Count:** `84`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `` | `0x0` |
| 1 | `` | `` | `0x0` |
| 2 | `` | `` | `0x0` |
| 3 | `` | `` | `0x0` |
| 4 | `` | `` | `0x0` |
| 5 | `` | `` | `0x0` |
| 6 | `` | `` | `0x0` |
| 7 | `` | `` | `0x0` |
| 8 | `` | `` | `0x0` |
| 9 | `` | `` | `0x0` |
| 10 | `` | `` | `0x0` |
| 11 | `` | `` | `0x0` |
| 12 | `` | `` | `0x0` |
| 13 | `` | `` | `0x0` |
| 14 | `` | `` | `0x0` |
| 15 | `` | `` | `0x0` |
| 16 | `` | `` | `0x0` |
| 17 | `` | `` | `0x0` |
| 18 | `` | `` | `0x0` |
| 19 | `` | `` | `0x0` |
| 20 | `` | `` | `0x0` |
| 21 | `` | `` | `0x0` |
| 22 | `` | `` | `0x0` |
| 23 | `` | `` | `0x0` |
| 24 | `` | `` | `0x0` |
| 25 | `` | `` | `0x0` |
| 26 | `` | `` | `0x0` |
| 27 | `` | `` | `0x0` |
| 28 | `` | `` | `0x0` |
| 29 | `` | `` | `0x0` |
| 30 | `` | `` | `0x0` |
| 31 | `` | `` | `0x0` |
| 32 | `` | `` | `0x0` |
| 33 | `` | `` | `0x0` |
| 34 | `` | `` | `0x0` |
| 35 | `` | `` | `0x0` |
| 36 | `` | `` | `0x0` |
| 37 | `` | `` | `0x0` |
| 38 | `` | `` | `0x0` |
| 39 | `` | `` | `0x0` |
| 40 | `` | `` | `0x0` |
| 41 | `` | `` | `0x0` |
| 42 | `` | `` | `0x0` |
| 43 | `` | `` | `0x0` |
| 44 | `` | `` | `0x0` |
| 45 | `` | `` | `0x0` |
| 46 | `` | `` | `0x0` |
| 47 | `` | `` | `0x0` |
| 48 | `` | `` | `0x0` |
| 49 | `` | `` | `0x0` |
| 50 | `` | `` | `0x0` |
| 51 | `` | `` | `0x0` |
| 52 | `` | `` | `0x0` |
| 53 | `` | `` | `0x0` |
| 54 | `` | `` | `0x0` |
| 55 | `` | `` | `0x0` |
| 56 | `` | `` | `0x0` |
| 57 | `` | `` | `0x0` |
| 58 | `` | `` | `0x0` |
| 59 | `` | `` | `0x0` |
| 60 | `` | `` | `0x0` |
| 61 | `` | `` | `0x0` |
| 62 | `` | `` | `0x0` |
| 63 | `` | `` | `0x0` |
| 64 | `` | `` | `0x0` |
| 65 | `` | `` | `0x0` |
| 66 | `` | `` | `0x0` |
| 67 | `` | `` | `0x0` |
| 68 | `` | `` | `0x0` |
| 69 | `` | `` | `0x0` |
| 70 | `` | `` | `0x0` |
| 71 | `` | `` | `0x0` |
| 72 | `` | `` | `0x0` |
| 73 | `` | `` | `0x0` |
| 74 | `` | `` | `0x0` |
| 75 | `` | `` | `0x0` |
| 76 | `` | `` | `0x0` |
| 77 | `` | `` | `0x0` |
| 78 | `` | `` | `0x0` |
| 79 | `` | `` | `0x0` |
| 80 | `` | `` | `0x0` |
| 81 | `` | `` | `0x0` |
| 82 | `` | `` | `0x0` |
| 83 | `` | `` | `0x0` |

---

## Library: `libLayerFlow.so`
- **Target Class:** `mtik_`
- **Registration Call RVA:** `0x2f2450`
- **JNINativeMethod Table RVA:** `0x1ec8fc`
- **Registered Method Count:** `33`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `` | `` | `0x0` |
| 1 | `` | `` | `0x0` |
| 2 | `` | `` | `0x0` |
| 3 | `` | `` | `0x0` |
| 4 | `` | `` | `0x0` |
| 5 | `` | `` | `0x0` |
| 6 | `` | `` | `0x0` |
| 7 | `` | `` | `0x0` |
| 8 | `` | `` | `0x0` |
| 9 | `` | `` | `0x0` |
| 10 | `` | `` | `0x0` |
| 11 | `` | `` | `0x0` |
| 12 | `` | `` | `0x0` |
| 13 | `` | `` | `0x0` |
| 14 | `` | `` | `0x0` |
| 15 | `` | `` | `0x0` |
| 16 | `` | `` | `0x0` |
| 17 | `` | `` | `0x0` |
| 18 | `` | `` | `0x0` |
| 19 | `` | `` | `0x0` |
| 20 | `` | `` | `0x0` |
| 21 | `` | `` | `0x0` |
| 22 | `` | `` | `0x0` |
| 23 | `` | `` | `0x0` |
| 24 | `` | `` | `0x0` |
| 25 | `` | `` | `0x0` |
| 26 | `` | `` | `0x0` |
| 27 | `` | `` | `0x0` |
| 28 | `` | `` | `0x0` |
| 29 | `` | `` | `0x0` |
| 30 | `` | `` | `0x0` |
| 31 | `` | `` | `0x0` |
| 32 | `` | `` | `0x0` |

---

## Library: `libMTFilterKernel.so`
- **Target Class:** `com/meitu/core/MTFilterKernelFaceData`
- **Registration Call RVA:** `0xbe430`
- **JNINativeMethod Table RVA:** `0x1ca2d8`
- **Registered Method Count:** `25`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreate` | `()J` | `0xbe458` |
| 1 | `finalizer` | `(J)V` | `0xbe468` |
| 2 | `nativeGetFaceCount` | `(J)I` | `0xbe478` |
| 3 | `nativeGetFaceRect` | `(JI)[F` | `0xbe4c0` |
| 4 | `nativeGetLandmark` | `(JII)[F` | `0xbe590` |
| 5 | `nativeGetDetectWidth` | `(J)I` | `0xbea90` |
| 6 | `nativeGetDetectHeight` | `(J)I` | `0xbeadc` |
| 7 | `nativeGetRace` | `(JI)I` | `0xbeb28` |
| 8 | `nativeGetGender` | `(JI)I` | `0xbeba8` |
| 9 | `nativeGetAge` | `(JI)I` | `0xbec28` |
| 10 | `nativeSetFaceCount` | `(JI)V` | `0xbeca8` |
| 11 | `nativeSetDetectSize` | `(JII)V` | `0xbece8` |
| 12 | `nativeSetFaceRect` | `(JI[F)V` | `0xbed30` |
| 13 | `nativeSetLandmark` | `(JII[F)Z` | `0xbedf4` |
| 14 | `nativeSetLandmarkVisible` | `(JII[F)Z` | `0xbf2ec` |
| 15 | `nativeSetRace` | `(JII)V` | `0xbf80c` |
| 16 | `nativeSetGender` | `(JII)V` | `0xbf884` |
| 17 | `nativeSetAge` | `(JII)V` | `0xbf8fc` |
| 18 | `nativeGetFaceID` | `(JI)I` | `0xbf974` |
| 19 | `nativeSetFaceID` | `(JII)V` | `0xbf9e4` |
| 20 | `nativeSetHasGlasses` | `(JII)V` | `0xbfa58` |
| 21 | `nativeClear` | `(J)V` | `0xbfacc` |
| 22 | `nativeSetPitchAngle` | `(JIF)V` | `0xbfb18` |
| 23 | `nativeSetYawAngle` | `(JIF)V` | `0xbfb90` |
| 24 | `nativeSetRollAngle` | `(JIF)V` | `0xbfc08` |

---

## Library: `libMTFilterKernel.so`
- **Target Class:** `com/meitu/core/MTFilterKernelRender`
- **Registration Call RVA:** `0xbfcc0`
- **JNINativeMethod Table RVA:** `0x1ca530`
- **Registered Method Count:** `17`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nCreate` | `()J` | `0xbfce8` |
| 1 | `nFinalizer` | `(J)V` | `0xbfd28` |
| 2 | `nInit` | `(J)V` | `0xbfd40` |
| 3 | `nRelease` | `(J)V` | `0xbfd98` |
| 4 | `nLoadFilterConfig` | `(JLjava/lang/String;)Z` | `0xbfdf0` |
| 5 | `nRenderToOutTexture` | `(JIIIIII)I` | `0xbfee4` |
| 6 | `nSetDeviceOrientation` | `(JI)V` | `0xbff14` |
| 7 | `nSetFrameType` | `(JI)V` | `0xbff7c` |
| 8 | `nSetMTFilterKernelListener` | `(JLcom/meitu/core/MTFilterKernelRender$MTFilterKernelListener;)V` | `0xbff90` |
| 9 | `nActiveEffect` | `(J)V` | `0xbfff8` |
| 10 | `nSetFilterKernelSpliceData` | `(JLcom/meitu/core/MTFilterKernelRender$FilterKernelSpliceData;)V` | `0xc0008` |
| 11 | `nSetSpliceFilterStatus` | `(JZ)V` | `0xc01bc` |
| 12 | `nSetFilterKernelConfig` | `(JLcom/meitu/core/MTFilterKernelRender$FilterKernelConfig;)V` | `0xc01d4` |
| 13 | `nGetIsNeedBodySegment` | `(J)Z` | `0xc0668` |
| 14 | `nSetBodyTexture` | `(JIII)V` | `0xc0690` |
| 15 | `nSetBodySegmentDataWithBytebuffer` | `(JLjava/nio/ByteBuffer;IIII)V` | `0xc06cc` |
| 16 | `nSetFaceData` | `(JJ)V` | `0xc0774` |

---

## Library: `libMTGif.so`
- **Target Class:** `com/meitu/core/mtgif/MTGif`
- **Registration Call RVA:** `0xe2b4`
- **JNINativeMethod Table RVA:** `0x1bce8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeconvertVideo2Gif` | `(Ljava/lang/String;Ljava/lang/String;IIIF)Z` | `0x0` |

---

## Library: `libMTGif.so`
- **Target Class:** `com/meitu/core/mtgif/MTGif`
- **Registration Call RVA:** `0xe308`
- **JNINativeMethod Table RVA:** `0x1bce8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeconvertVideo2Gif` | `(Ljava/lang/String;Ljava/lang/String;IIIF)Z` | `0x0` |

---

## Library: `libPVGLive.so`
- **Target Class:** `com/meitu/mtlab/PVGLive/PVGGlobal`
- **Registration Call RVA:** `0x8a3a0`
- **JNINativeMethod Table RVA:** `0x9a938`
- **Registered Method Count:** `5`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeSetLogLevel` | `(I)I` | `0x8a3c0` |
| 1 | `nativeSetDebug` | `(Z)I` | `0x8a3c8` |
| 2 | `nativeIsDebug` | `()Z` | `0x8a3d8` |
| 3 | `nativeSetAndroidContext` | `(Landroid/content/Context;)I` | `0x8a3f0` |
| 4 | `nativeGetAndroidContext` | `()Landroid/content/Context;` | `0x8a414` |

---

## Library: `libPVGLive.so`
- **Target Class:** `com/meitu/mtlab/PVGLive/PVGLiveInterface`
- **Registration Call RVA:** `0x8a4ac`
- **JNINativeMethod Table RVA:** `0x9a9b0`
- **Registered Method Count:** `31`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `nativeCreateInstance` | `(I)J` | `0x8a4cc` |
| 1 | `nativeDestroyInstance` | `(J)V` | `0x8a4d4` |
| 2 | `nativeVersion` | `()Ljava/lang/String;` | `0x8a4e4` |
| 3 | `nativeOpenFile` | `(JLjava/lang/String;I)I` | `0x8a520` |
| 4 | `nativeClose` | `(J)V` | `0x8a650` |
| 5 | `nativeIsMotionPhoto` | `(J)Z` | `0x8a668` |
| 6 | `nativeVendor` | `(J)I` | `0x8a698` |
| 7 | `nativeExtractImageToFile` | `(JLjava/lang/String;)I` | `0x8a6b4` |
| 8 | `nativeExtractVideoToFile` | `(JLjava/lang/String;)I` | `0x8a7b4` |
| 9 | `nativeSetVendor` | `(JI)I` | `0x8a8b4` |
| 10 | `nativeSetImageFile` | `(JLjava/lang/String;)I` | `0x8a8d4` |
| 11 | `nativeSetVideoFile` | `(JLjava/lang/String;)I` | `0x8a9dc` |
| 12 | `nativeSetMetadataInt64` | `(JLjava/lang/String;J)I` | `0x8aae4` |
| 13 | `nativeSetMetadataInt` | `(JLjava/lang/String;I)I` | `0x8abe8` |
| 14 | `nativeSetMetadataFloat` | `(JLjava/lang/String;F)I` | `0x8acf0` |
| 15 | `nativeSetMetadataDouble` | `(JLjava/lang/String;D)I` | `0x8ae00` |
| 16 | `nativeSetMetadataString` | `(JLjava/lang/String;Ljava/lang/String;)I` | `0x8af10` |
| 17 | `nativeEncodeToFile` | `(JLjava/lang/String;)I` | `0x8b078` |
| 18 | `nativeEncodeDualOutput` | `(JLjava/lang/String;Ljava/lang/String;)I` | `0x8b178` |
| 19 | `nativeMetadataType` | `(JLjava/lang/String;)I` | `0x8b2ec` |
| 20 | `nativeMetadataInt` | `(JLjava/lang/String;)I` | `0x8b3e0` |
| 21 | `nativeMetadataInt64` | `(JLjava/lang/String;)J` | `0x8b4d4` |
| 22 | `nativeMetadataFloat` | `(JLjava/lang/String;)F` | `0x8b5c8` |
| 23 | `nativeMetadataDouble` | `(JLjava/lang/String;)D` | `0x8b6b8` |
| 24 | `nativeMetadataString` | `(JLjava/lang/String;)Ljava/lang/String;` | `0x8b7a8` |
| 25 | `nativeMetadataCount` | `(J)J` | `0x8b8b8` |
| 26 | `nativeMetadataKeyAt` | `(JJ)Ljava/lang/String;` | `0x8b8d4` |
| 27 | `nativeIsMotionPhotoFile` | `(Ljava/lang/String;I)Z` | `0x8b930` |
| 28 | `nativeDetectVendorFile` | `(Ljava/lang/String;I)I` | `0x8ba28` |
| 29 | `nativeQuickProbeMotionPhotoFile` | `(Ljava/lang/String;I)I` | `0x8bb20` |
| 30 | `nativeStripLiveVideoMetadataFile` | `(Ljava/lang/String;Ljava/lang/String;I)I` | `0x8bc18` |

---

## Library: `libPVGVideoCodec.so`
- **Target Class:** `%s/PVGVideoAVICodec: [%s(%d)]:> register_aicodec_native_methods failed
`
- **Registration Call RVA:** `0x9815c`
- **JNINativeMethod Table RVA:** `0x1181d8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `callNativeOpaque` | `(Ljava/lang/String;Ljava/lang/String;Landroid/media/MediaFormat;)V` | `0x9810c` |

---

## Library: `libPVGVideoCodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0xa3dac`
- **JNINativeMethod Table RVA:** `0x1187f8`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_SurfaceTextureCallback` | `(J)V` | `0xa3ce8` |

---

## Library: `libPVGVideoCodec.so`
- **Target Class:** `RecoveredFromContext`
- **Registration Call RVA:** `0xa3df8`
- **JNINativeMethod Table RVA:** `0x118810`
- **Registered Method Count:** `1`

| Index | Java Method Name | JVM Signature | Native Target RVA |
| :--- | :--- | :--- | :--- |
| 0 | `native_ImageReaderCB` | `(J)V` | `0xa3c84` |

---

