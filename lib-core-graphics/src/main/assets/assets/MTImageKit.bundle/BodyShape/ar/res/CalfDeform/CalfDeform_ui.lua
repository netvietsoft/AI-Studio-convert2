-- @author: czh@meitu.com
-- Lua ui
-- @ui
------ ui

ui = {
    -- 整体力度作为两腿共同基础值；左/右力度作为各自增量，最终力度 clamp(-2, 2)。
    calfDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:整体(小腿)", max = 1.0, min = -1, value = 0.0},
    calfLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:左小腿", max = 1.0, min = -1, value = 0},
    calfRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:右小腿", max = 1.0, min = -1, value = 0},
    order={"calfDeformIntensity","calfLeftDeformIntensity","calfRightDeformIntensity"},
    antiShake = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "防抖动",
        visible = false,
        order = {
            "renderMode",
            "offsetRTFixedSize",
            "showOffsetMemStatus",
            "filterType",
            "smoothAlpha",
            "smoothBeta",
            "boxDeltaMeanRatio",
            "boxDeltaMaxRatio",
            "temporalPosSmooth",
            "posSmoothAlpha",
        },
        renderMode = {
            ui_type = "combox",
            value = 2.00,
            ui_name = "显示方式",
            visible = false,
            items = {
                { name = "原本网格" },
                { name = "OffsetMap" },
            },
        },
        offsetRTFixedSize = {
            step = 128,
            precision = 0,
            ui_type = "slider",
            ui_name = "位移图RT边长(0=半分辨率)",
            max = 2048.0,
            min = 0.0,
            value = 512.0,
            visible = false,
        },
        showOffsetMemStatus = { ui_type = "switch", value = false, ui_name = "屏幕显示内存优化HUD", visible = false },
        filterType = { step = 1, ui_type = "slider", ui_name = "平滑类型:1-原本方式 2-一阶滤波 3-双指数平滑", max = 3, min = 1, value = 2, visible = false },
        temporalPosSmooth = { ui_type = "switch", value = false, ui_name = "时域平滑:前后帧变形混合", visible = false },
        smoothAlpha = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "平滑类型2:轮廓点一阶平滑", max = 1.0, min = 0.0, value = 0.2, visible = false },
        smoothBeta = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "平滑类型3:轮廓点双指数平滑", max = 1.0, min = 0.0, value = 0.1, visible = false },
        boxDeltaMeanRatio = { step = 0.001, precision = 4.0, ui_type = "slider", ui_name = "点抖动距离/视频宽的平均比例", max = 0.2, min = 0.0, value = 0.03, visible = false },
        boxDeltaMaxRatio = { step = 0.001, precision = 4.0, ui_type = "slider", ui_name = "点抖动距离/视频宽的最大比例", max = 0.3, min = 0.0, value = 0.06, visible = false },
        posSmoothAlpha = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "时域平滑：前后帧跟随平滑因子", max = 1.0, min = 0.0, value = 0.35, visible = false },
    },
    debug={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "显示",
        ui_fold = true,
        visible = false,
        order={"enableDebugDraw","showSlimPoints","showRawDetectedPoints","showCorrectedPoints","showSkeleton","showContourLines","showCalfRegionBoxes","showCalfStartKeyPoints","showCalfSliceExposure","showLegOwnershipPoints","enableBluePointSmoothing","showMeshPoints","showRawMeshPoints","showDeformedMeshPoints","showMeshDisplacement","showRawDeformedMeshPoints","showRawMeshDisplacement"},
        enableDebugDraw = { ui_type = "switch", value = false, ui_name = "启用调试绘制" },
        showSlimPoints = { ui_type = "switch", value = false, ui_name = "轮廓点" },
        showRawDetectedPoints = { ui_type = "switch", value = false, ui_name = "显示修正前8点" },
        showCorrectedPoints = { ui_type = "switch", value = false, ui_name = "显示修正后8点" },
        showSkeleton = { ui_type = "switch", value = false, ui_name = "骨骼线" },
        showContourLines = { ui_type = "switch", value = false, ui_name = "轮廓线" },
        showCalfRegionBoxes = { ui_type = "switch", value = false, ui_name = "显示小腿法向方框" },
        showCalfStartKeyPoints = { ui_type = "switch", value = false, ui_name = "显示起点关键点(mid1/a)" },
        showCalfSliceExposure = { ui_type = "switch", value = false, ui_name = "显示切片接触/外露" },
        showLegOwnershipPoints = { ui_type = "switch", value = false, ui_name = "显示左右腿归属点" },
        enableBluePointSmoothing = { ui_type = "switch", value = true, ui_name = "启用蓝点平滑" },
        showMeshPoints = { step = 1, ui_type = "slider", ui_name = "显示内部点", max = 7, min = 0, value = 0 }, 
        showRawMeshPoints = { ui_type = "switch", value = false, ui_name = "显示原始网格点" },
        showDeformedMeshPoints = { ui_type = "switch", value = false, ui_name = "显示变形后网格点" },
        showMeshDisplacement = { ui_type = "switch", value = false, ui_name = "显示控制点位移" },
        showRawDeformedMeshPoints = { ui_type = "switch", value = false, ui_name = "显示当前帧未平滑的变形后网格点" },
        showRawMeshDisplacement = { ui_type = "switch", value = false, ui_name = "关闭时域平滑后显示位移" },
    },
    region={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "范围控制",
        visible= false,
        order={"trackingMode","enablePointCorrection","pointCorrectionStrength","intentsityScale","shrinkIntensityScale","midDownAdjust","calfStartOffset","calfBoneAlongCoefUp","crossKneeProtect","crossLegEnhance","crossLegExposureMin","crossLegKneeProtectScale","crossLegOwnershipMin","calfBoxOuterCoef","calfBoxInnerCoef","calfBoneAlongCoefDown"},
        trackingMode = {
            ui_type = "combox",
            value = 1.00,
            ui_name = "8点修正模式",
            items = {
                { name = "照片模式(不依赖上一帧)" },
                { name = "视频模式(参考上一帧)" },
            },
        },
        enablePointCorrection = { ui_type = "switch", value = true, ui_name = "启用8点修正" },
        pointCorrectionStrength = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "8点修正强度", max = 1.0, min = 0.0, value = 1 },
        intentsityScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "放大因子(力度<0)", max = 1.0, min = 0.0, value = 0.32},
        shrinkIntensityScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "缩小因子(力度>0)", max = 1.0, min = 0.0, value = 0.38},
        calfStartOffset = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "小腿起点下移(膝下起点)", max = 0.4, min = 0.0, value = 0.02 },
        calfBoneAlongCoefUp = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "上端延长(膝端基于起点再往上)", max = 1.0, min = 0.0, value = 0.17 },
        crossKneeProtect = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "对侧膝盖保护", max = 1.0, min = 0.0, value = 1.0 },
        crossLegEnhance = { ui_type = "switch", value = true, ui_name = "交叉腿增强" },
        crossLegExposureMin = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "交叉腿接触区保底", max = 1.0, min = 0.0, value = 0.70 },
        crossLegKneeProtectScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "交叉腿膝盖保护保留", max = 1.0, min = 0.0, value = 0.30 },
        crossLegOwnershipMin = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "交叉腿归属权重保底", max = 1.0, min = 0.0, value = 0.82 },
        calfBoxOuterCoef = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "小腿外侧宽", max = 2.5, min = 0.5, value = 2.5 },
        calfBoxInnerCoef = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "小腿内侧宽", max = 1.5, min = 0.5, value = 1.00 },
        calfBoneAlongCoefDown = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "下端延长(踝端基于终点再往下)", max = 1.5, min = 0.0, value = 0.51 },
        midDownAdjust = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "中下段调整因子", max = 2, min = 0.0, value = 0.3 },
    },
    compatible={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "兼容模式",
        visible = false,
        order={"showCompatibleBoxes","compatibleScale","fangkuangScale"},
        showCompatibleBoxes = { ui_type = "switch", value = true, ui_name = "兼容模式" },
        compatibleScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "兼容力度权重（两个腿都兼容才生效）", max = 1, min = 0.1, value =0.55 },
        fangkuangScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "方框大小系数（两个腿都兼容才生效）", max = 2, min = 0.5, value =1 },

    }
}


paramTable = {}
paramTable["default"] = {
    calfDeformIntensity = ui.calfDeformIntensity,
    calfLeftDeformIntensity = ui.calfLeftDeformIntensity,
    calfRightDeformIntensity = ui.calfRightDeformIntensity,
}

return ui, paramTable
