-- @author: xyg2@meitu.com
------ ui

ui = {
    -- 有效力度 = 整体×0.5 + 左/右×0.5（可叠加）
    thighDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:整体", max = 1.0, min = -1, value = 0.0},
    thighLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:左腿", max = 1.0, min = -1, value = 0},
    thighRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:右腿", max = 1.0, min = -1, value = 0},
    order={"thighDeformIntensity","thighLeftDeformIntensity","thighRightDeformIntensity","compatible","region","antiShake","debug"},
    antiShake = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "防抖动",
        visible = false,
        order = {
            "renderMode",
            "offsetRTFixedSize",
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
            value = 1.00,
            ui_name = "显示方式",
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
        },
        filterType = { step = 1, ui_type = "slider", ui_name = "平滑类型:1-原本方式 2-一阶滤波 3-双指数平滑", max = 3, min = 1, value = 2 },
        temporalPosSmooth = { ui_type = "switch", value = true, ui_name = "时域平滑:前后帧变形混合" },
        smoothAlpha = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "平滑类型2:轮廓点一阶平滑", max = 1.0, min = 0.0, value = 0.2 },
        smoothBeta = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "平滑类型3:轮廓点双指数平滑", max = 1.0, min = 0.0, value = 0.1 },
        boxDeltaMeanRatio = { step = 0.001, precision = 4.0, ui_type = "slider", ui_name = "点抖动距离/视频宽的平均比例", max = 0.2, min = 0.0, value = 1.03 },
        boxDeltaMaxRatio = { step = 0.001, precision = 4.0, ui_type = "slider", ui_name = "点抖动距离/视频宽的最大比例", max = 0.3, min = 0.0, value = 1.06 },
        posSmoothAlpha = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "时域平滑：前后帧跟随平滑因子", max = 1.0, min = 0.0, value = 0.35 },
    },
    debug={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "显示",
        ui_fold = true,
        visible= false,
        order={"showLeftSlim","showRightSlim","showSkeleton","showContourLines","showMeshPoints"},
        showLeftSlim = { ui_type = "switch", value = false, ui_name = "左轮廓点" },
        showRightSlim = { ui_type = "switch", value = false, ui_name = "右轮廓点" },
        showSkeleton = { ui_type = "switch", value = false, ui_name = "骨骼点" },
        showContourLines = { ui_type = "switch", value = false, ui_name = "轮廓线" },
        showMeshPoints = { step = 1, ui_type = "slider", ui_name = "显示内部点", max = 7, min = 0, value = 0 }, 
    },
    region={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "范围控制",
        visible= false,
        order={"intentsityScale","midDownAdjust","showThighRegionBoxes","showInnerDeform","thighBoxOuterCoef","thighBoxInnerCoef","thighBoneAlongCoefUp","thighBoneAlongCoefDown"},
        intentsityScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "放大因子", max = 1.0, min = 0.0, value = 0.44},
        showThighRegionBoxes = { ui_type = "switch", value = false, ui_name = "显示大腿法向方框" },
        thighBoxOuterCoef = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "大腿外侧宽", max = 2.5, min = 0.5, value = 1.85 },
        thighBoxInnerCoef = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "大腿内侧宽", max = 1.5, min = 0.5, value = 0.7 },
        thighBoneAlongCoefUp = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "上基线上移", max = 1.0, min = 0.0, value = 0.52 },
        thighBoneAlongCoefDown = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "下基线下移", max = 1.5, min = 0.0, value = 0.5 },
        midDownAdjust = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "中下段调整因子", max = 2, min = 0.0, value = 1.28 },
    },
    compatible={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "兼容模式",
        visible = false,
        order={"showCompatibleBoxes","compatibleScale","fangkuangScale"},
        showCompatibleBoxes = { ui_type = "switch", value = true, ui_name = "兼容模式" },
        compatibleScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "兼容力度权重（两个腿都兼容才生效）", max = 1, min = 0.1, value =0.5 },
        fangkuangScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "方框大小系数（两个腿都兼容才生效）", max = 2, min = 0.5, value =1.5 },

    }
}


paramTable = {}
paramTable["default"] = {
    thighDeformIntensity = ui.thighDeformIntensity,
    thighLeftDeformIntensity = ui.thighLeftDeformIntensity,
    thighRightDeformIntensity = ui.thighRightDeformIntensity,
}

return {ui = ui, paramTable = paramTable}

--return ui
