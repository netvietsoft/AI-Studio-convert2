# 05 — Module `features.filters` (Pass 0: Kế hoạch convert 100% Meitu)

> Nguồn dữ kiện: `02_class_inventory.json` (55,781 class độc quyền), `04_kotlin_structure.json`, `03_jni_bridge.json`.
> Quyết định 2026-09-24 (Chủ tịch): **ĐƯỢC PHÉP CONVERT** mã decompile cho dự án Meitu — xem mục "QUYẾT ĐỊNH" ở `README.md`.

## 1. Tổng quan Module Filters & MTFilter Core

- Tổng số Class có chuỗi `filter` trong đường dẫn: **1460**
- Trong đó **cần convert: 1460** · **bỏ qua (do annotation processor sinh ra): 0**
- Thư viện C++ Native đảm nhiệm lõi: `libMTFilterKernel.so` (1.77 MB) & `libLayerFlow.so` (5.29 MB)
- Tài nguyên hỗ trợ: **127 3D LUT tables** (`.cube`, `.png`) và **2,031 Shaders** GPU

## 2. Danh sách CẦN CONVERT (thân hàm sẽ được chuyển sang Kotlin, giữ nguyên hành vi 100%)

| # | Class dịch ngược | Byte | dex | Kotlin gốc (nếu map được) |
|---|---|---|---|---|
| 1 | `com/layer/flow/datas/LFFilterData.java` | 6053 | classes13.dex | LFFilterData.kt |
| 2 | `com/layerflow/mtik/filter/SmartOptimizeType.java` | 13512 | classes13.dex | SmartOptimizeType.kt |
| 3 | `com/layerflow/scenemodule/effect/SceneEffectManager$processCurrentFilters$1.java` | 1127 | classes13.dex | SceneEffectManager.kt |
| 4 | `com/layerflow/smartmodule/effect/EffectManager$consolidateInFilter$2.java` | 4052 | classes13.dex | EffectManager.kt |
| 5 | `com/layerflow/smartmodule_common/effect/effect/SceneEffectOperator$precheckAiCloudFilterBlocked$1.java` | 1324 | classes2.dex | SceneEffectOperator.kt |
| 6 | `com/layerflow/smartmodule_common/effect/effect/SceneEffectOperator$precheckAiCloudFilterBlocked$2.java` | 2024 | classes2.dex | SceneEffectOperator.kt |
| 7 | `com/layerflow/smartmodule_common/effect/effect/SceneEffectOperator$precheckAiCloudFilterBlocked$animal$1.java` | 1901 | classes2.dex | SceneEffectOperator.kt |
| 8 | `com/layerflow/smartmodule_common/effect/effect/SceneEffectOperator$precheckAiCloudFilterBlocked$animal$2.java` | 1901 | classes2.dex | SceneEffectOperator.kt |
| 9 | `com/layerflow/smartmodule_common/effect/effect/aigc/SceneFilterAigcHandler$executeHostAigcRequest$1.java` | 1090 | classes2.dex | SceneFilterAigcHandler.kt |
| 10 | `com/layerflow/smartmodule_common/effect/effect/aigc/SceneFilterAigcHandler$executeHostAigcRequest$result$2.java` | 4279 | classes2.dex | SceneFilterAigcHandler.kt |
| 11 | `com/layerflow/smartmodule_common/effect/effect/aigc/SceneFilterAigcHandler$loadFilterMaterial$1.java` | 1076 | classes2.dex | SceneFilterAigcHandler.kt |
| 12 | `com/layerflow/smartmodule_common/effect/subfeature/SceneEmbellishHost$rebuildFilterChain$2.java` | 1833 | classes2.dex | SceneEmbellishHost.kt |
| 13 | `com/layerflow/smartv2/effect/EffectManagerV2$consolidateInFilter$2.java` | 6033 | classes13.dex | EffectManagerV2.kt |
| 14 | `com/layerflow/submodule/autoEmbellish/AutoEmbellishController$presetFilterFromFormulaModel$1.java` | 4020 | classes13.dex | AutoEmbellishController.kt |
| 15 | `com/meitu/aiphoto/widget/layerimage/RealtimeFilterImageView.java` | 12114 | classes14.dex | RealtimeFilterImageView.kt |
| 16 | `com/meitu/album/album3/XXAlbumController$pushFunctionFilterView$1.java` | 2467 | classes14.dex | XXAlbumController.kt |
| 17 | `com/meitu/album/album3/utils/XXAlbumMediaFilterHelper$asyncMediaFileCheck$1$1$1.java` | 2959 | classes14.dex | XXAlbumMediaFilterHelper.kt |
| 18 | `com/meitu/album/album3/utils/XXAlbumMediaFilterHelper$asyncMediaFileCheck$1.java` | 10209 | classes14.dex | XXAlbumMediaFilterHelper.kt |
| 19 | `com/meitu/album/album3/utils/XXAlbumMediaFilterHelper.java` | 6387 | classes14.dex | XXAlbumMediaFilterHelper.kt |
| 20 | `com/meitu/album2/multiPic/BlurFilterParams.java` | 2499 | classes14.dex | BlurFilterParams.kt |
| 21 | `com/meitu/album2/picker/FilterBean.java` | 1738 | classes14.dex | FilterBean.kt |
| 22 | `com/meitu/app/init/firstActivity/EnvCollectorJob$collectInfo$1$invokeSuspend$$inlined$filter$1$2.java` | 5110 | classes14.dex | EnvCollectorJob.kt |
| 23 | `com/meitu/app/init/firstActivity/EnvCollectorJob$collectInfo$1$invokeSuspend$$inlined$filter$2$2.java` | 5519 | classes14.dex | EnvCollectorJob.kt |
| 24 | `com/meitu/app/meitucamera/CameraFilterFragment$applyMaterial$1.java` | 2211 | classes14.dex | CameraFilterFragment.kt |
| 25 | `com/meitu/app/meitucamera/CameraFilterFragment$baseFilterMaterialListener$1$shouldInterceptMaterialClick$1.java` | 2395 | classes14.dex | CameraFilterFragment.kt |
| 26 | `com/meitu/app/meitucamera/CameraFilterFragment$handleAigcFilterBeforeSwitchToVideo$1.java` | 2659 | classes14.dex | CameraFilterFragment.kt |
| 27 | `com/meitu/app/meitucamera/CameraFilterFragment$initSearchView$1.java` | 1498 | classes14.dex | CameraFilterFragment.kt |
| 28 | `com/meitu/app/meitucamera/CameraFilterFragment$modifyDownloadedMaterial$1.java` | 7242 | classes14.dex | CameraFilterFragment.kt |
| 29 | `com/meitu/app/meitucamera/CameraFilterFragment$onCacheDataLoaded$3.java` | 5345 | classes14.dex | CameraFilterFragment.kt |
| 30 | `com/meitu/app/meitucamera/CameraFilterFragment$parentOnHiddenChanged$2.java` | 2929 | classes14.dex | CameraFilterFragment.kt |
| 31 | `com/meitu/app/meitucamera/CameraFilterFragment$pickMaterials$1$_filter$1.java` | 966 | classes14.dex | CameraFilterFragment.kt |
| 32 | `com/meitu/app/meitucamera/CameraFilterFragment$pickMaterials$1.java` | 11874 | classes14.dex | CameraFilterFragment.kt |
| 33 | `com/meitu/app/meitucamera/CameraFilterFragment$switchToDefaultNonAigcFilter$1.java` | 1222 | classes14.dex | CameraFilterFragment.kt |
| 34 | `com/meitu/app/meitucamera/CameraFilterFragment$switchToDefaultNonAigcFilter$2$appliedDefault$configReady$1.java` | 2627 | classes14.dex | CameraFilterFragment.kt |
| 35 | `com/meitu/app/meitucamera/CameraFilterFragment.java` | 64179 | classes14.dex | CameraFilterFragment.kt |
| 36 | `com/meitu/app/meitucamera/aigc/CameraFilterAigcPolicy$Decision.java` | 4107 | classes14.dex | CameraFilterAigcPolicy.kt |
| 37 | `com/meitu/app/meitucamera/aigc/CameraFilterAigcPolicy$Fallback.java` | 2419 | classes14.dex | CameraFilterAigcPolicy.kt |
| 38 | `com/meitu/app/meitucamera/aigc/CameraFilterAigcPolicy$Interaction.java` | 2685 | classes14.dex | CameraFilterAigcPolicy.kt |
| 39 | `com/meitu/app/meitucamera/aigc/CameraFilterAigcPolicy$Prompt.java` | 2449 | classes14.dex | CameraFilterAigcPolicy.kt |
| 40 | `com/meitu/app/meitucamera/aigc/CameraFilterAigcPolicy$Source.java` | 2305 | classes14.dex | CameraFilterAigcPolicy.kt |
| 41 | `com/meitu/app/meitucamera/controller/camera/AppleModelFilterController$deleteOldFilter$1.java` | 2309 | classes14.dex | AppleModelFilterController.kt |
| 42 | `com/meitu/app/meitucamera/controller/camera/AppleModelFilterController$startDownload$1$onChanged$1.java` | 4359 | classes14.dex | AppleModelFilterController.kt |
| 43 | `com/meitu/app/meitucamera/controller/camera/AppleModelFilterController.java` | 3672 | classes14.dex | AppleModelFilterController.kt |
| 44 | `com/meitu/app/meitucamera/controller/postprocess/picture/AIGCImageTasksController$createCloudFilterRequest$1.java` | 1214 | classes14.dex | AIGCImageTasksController.kt |
| 45 | `com/meitu/app/meitucamera/debug/magicroom/CameraMagicRoomMaterialReplayApplier$applyFilter$1.java` | 1287 | classes14.dex | CameraMagicRoomMaterialReplayApplier.kt |
| 46 | `com/meitu/app/meitucamera/debug/magicroom/CameraMagicRoomMaterialReplayApplier$queryRestoredFilterMaterial$1.java` | 1274 | classes14.dex | CameraMagicRoomMaterialReplayApplier.kt |
| 47 | `com/meitu/app/meitucamera/pipe/EffectPipeline$asyncApplyFilter$1.java` | 3920 | classes14.dex | EffectPipeline.kt |
| 48 | `com/meitu/bean/AiFilterApplyResult.java` | 5584 | classes14.dex | AiFilterApplyResult.kt |
| 49 | `com/meitu/bean/AiFilterCompareEntity.java` | 12123 | classes14.dex | AiFilterCompareEntity.kt |
| 50 | `com/meitu/business/ads/core/utils/AppInstallFilter.java` | 4262 | classes14.dex | AppInstallFilter.kt |
| 51 | `com/meitu/community/message/widget/OrderFilterView.java` | 9098 | classes14.dex | OrderFilterView.kt |
| 52 | `com/meitu/community/ui/publish/PublishFilterFragment$dealDataInitStatus$1$realList$1.java` | 3776 | classes14.dex | PublishFilterFragment.kt |
| 53 | `com/meitu/community/ui/publish/PublishFilterFragment$dealDataInitStatus$1.java` | 2785 | classes14.dex | PublishFilterFragment.kt |
| 54 | `com/meitu/community/ui/publish/PublishFilterFragment$initViewModel$1$1.java` | 1675 | classes14.dex | PublishFilterFragment.kt |
| 55 | `com/meitu/community/ui/publish/PublishFilterFragment.java` | 7832 | classes14.dex | PublishFilterFragment.kt |
| 56 | `com/meitu/core/MTFilterKernelConfigJNI.java` | 4168 | classes15.dex | MTFilterKernelConfigJNI.kt |
| 57 | `com/meitu/core/MTFilterKernelFaceData.java` | 8614 | classes15.dex | MTFilterKernelFaceData.kt |
| 58 | `com/meitu/core/MTFilterKernelRender.java` | 8110 | classes15.dex | MTFilterKernelRender.kt |
| 59 | `com/meitu/core/mtfilterkernel/BuildConfig.java` | 356 | classes15.dex | BuildConfig.kt |
| 60 | `com/meitu/core/mtfilterkernel/R.java` | 328 | classes15.dex | R.kt |
| 61 | `com/meitu/core/mtfilterkernel_resource_myxj/BuildConfig.java` | 384 | classes15.dex | BuildConfig.kt |
| 62 | `com/meitu/core/mtfilterkernel_resource_myxj/R.java` | 194 | classes15.dex | R.kt |
| 63 | `com/meitu/idphoto/agent/event/EventCenterKt$observe$$inlined$filterIsInstance$1$1.java` | 730 | classes15.dex | EventCenterKt.kt |
| 64 | `com/meitu/idphoto/agent/event/EventCenterKt$observe$$inlined$filterIsInstance$1$2$1.java` | 816 | classes15.dex | EventCenterKt.kt |
| 65 | `com/meitu/idphoto/agent/event/EventSystem$observe$$inlined$filterIsInstance$1$1.java` | 726 | classes15.dex | EventSystem.kt |
| 66 | `com/meitu/idphoto/agent/event/EventSystem$observe$$inlined$filterIsInstance$1$2$1.java` | 812 | classes15.dex | EventSystem.kt |
| 67 | `com/meitu/idphoto/page/edit/fragment/body/BodyNeckController$addBodyFilter$2.java` | 3580 | classes15.dex | BodyNeckController.kt |
| 68 | `com/meitu/idphoto/page/edit/fragment/body/BodyNeckController$removeBodyFilter$1.java` | 2522 | classes15.dex | BodyNeckController.kt |
| 69 | `com/meitu/idphoto/page/edit/fragment/tab/beauty/light/SmartLightFragment$initFilter$1.java` | 1076 | classes15.dex | SmartLightFragment.kt |
| 70 | `com/meitu/idphoto/page/edit/fragment/tab/combine/OneKeyStyleViewController$removeFilter$1.java` | 3388 | classes15.dex | OneKeyStyleViewController.kt |
| 71 | `com/meitu/idphoto/page/smear/controller/SmearController$mtikManagerListener$1$onStickerFilterSmearEvent$1.java` | 2636 | classes15.dex | SmearController.kt |
| 72 | `com/meitu/idphoto/page/smear/controller/SmearController$mtikManagerListener$1$onStickerFilterSmearEvent$2.java` | 2377 | classes15.dex | SmearController.kt |
| 73 | `com/meitu/idphoto/page/smear/controller/SmearController$mtikManagerListener$1$onStickerFilterSmearEvent$3.java` | 1972 | classes15.dex | SmearController.kt |
| 74 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForBatch$1.java` | 1323 | classes15.dex | ImageBaseTool.kt |
| 75 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForCooper$1.java` | 1333 | classes15.dex | ImageBaseTool.kt |
| 76 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForFreeNodeSteps$1.java` | 1495 | classes15.dex | ImageBaseTool.kt |
| 77 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForFreeNodeSteps$5.java` | 3559 | classes15.dex | ImageBaseTool.kt |
| 78 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForFreeNodeSteps$oldFilters$1.java` | 2330 | classes15.dex | ImageBaseTool.kt |
| 79 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForPuzzle$1.java` | 1351 | classes15.dex | ImageBaseTool.kt |
| 80 | `com/meitu/image_process/ImageBaseTool$rebuildFilterChainForSubModule$1.java` | 1539 | classes15.dex | ImageBaseTool.kt |
| ... | *(và 1380 class nghiệp vụ filter khác được định nghĩa đầy đủ trong `02_class_inventory.json`)* | | | |

## 3. BỎ QUA — Do Dagger / DataBinding / Synthetic Compiler sinh ra (không convert, để build sinh lại)

| # | Class | Ghi chú |
|---|---|---|

## 4. Phụ thuộc Native C++ & Assets Lõi của Module Filters

- Thư viện `.so` trong `extracted_native_libs/lib/arm64-v8a/`:
  - `libMTFilterKernel.so` (1.77 MB): Nhân áp dụng ma trận 3D LUT, Gaussian Blur, Bilateral Filter.
  - `libLayerFlow.so` (5.29 MB): Quản lý hòa trộn đa lớp màu (Overlay, SoftLight, Screen, Multiply).
  - `libc++_shared.so` (1.23 MB): Runtime C++ LLVM.
- Shaders trong `extracted_assets/`:
  - `assets/MTFilterCore.bundle/`: Hàng trăm shader `.fs` và `.vs` lọc màu.
  - `assets/colortoning/eva_a.bin`: Mô hình nơ-ron cân bằng màu da tự nhiên.
