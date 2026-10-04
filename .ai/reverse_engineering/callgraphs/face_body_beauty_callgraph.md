# Face & Body Beauty Call Graph
1. `PhotoEditorActivity.applyTool(toolId)`
2. `BeautyEngineJNI.nativeDetectFaceLandmarks()` -> `ARKernel_DetectFaceLandmarks106(0x00048120)`
3. `BeautyEngineJNI.nativeApplyFaceReshape()` -> `ARKernel_DeformFaceMesh(0x0004a300)`
4. `BodyBeautyJNI.nativeDetectBodySkeleton()` -> `ARKernel_DetectBodyKeypoints24(0x00051200)`
5. `BodyBeautyJNI.nativeApplyBodyWarp()` -> `LayerFlow_MovingLeastSquaresWarp(0x00028700)`
