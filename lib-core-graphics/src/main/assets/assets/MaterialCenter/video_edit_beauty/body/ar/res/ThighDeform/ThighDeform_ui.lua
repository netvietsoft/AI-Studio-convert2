-- @author: xyg2@meitu.com
------ ui

ui = {
    -- 有效力度 = 整体×0.5 + 左/右×0.5（可叠加）
    thighDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:整体", max = 1.0, min = -1, value = 0.0},
    thighLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:左腿", max = 1.0, min = -1, value = 0},
    thighRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "力度:右腿", max = 1.0, min = -1, value = 0},
    order={"thighDeformIntensity","thighLeftDeformIntensity","thighRightDeformIntensity","showThighRegionBoxes","regionVideo","antiShake","debug"},
    showThighRegionBoxes = { ui_type = "switch", value = false, ui_name = "显示大腿法向方框" },
    antiShake = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "防抖动",
        visible = false,
        order = {
            "offsetRTFixedSize",
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
    },
    debug={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "显示",
        ui_fold = true,
        visible= false,
        order={"showLeftSlim","showRightSlim","showLeftAlgoBox","showRightAlgoBox","showSkeleton","showContourLines","showMeshPoints"},
        showLeftSlim = { ui_type = "switch", value = false, ui_name = "左轮廓点" },
        showRightSlim = { ui_type = "switch", value = false, ui_name = "右轮廓点" },
        showLeftAlgoBox = { ui_type = "switch", value = false, ui_name = "左重建轮廓" },
        showRightAlgoBox = { ui_type = "switch", value = false, ui_name = "右重建轮廓" },
        showSkeleton = { ui_type = "switch", value = false, ui_name = "骨骼点" },
        showContourLines = { ui_type = "switch", value = false, ui_name = "轮廓线" },
        showMeshPoints = { step = 1, ui_type = "slider", ui_name = "显示内部点", max = 7, min = 0, value = 0 }, 
    },
    regionVideo={
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "范围控制",
        visible= true,
        order={"intensityScale","midDownAdjust","thighBoxWidth","thighBoneAlongCoefUp","thighBoneAlongCoefDown","smoothAlpha"},
        intensityScale = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "放大因子", max = 1.0, min = 0.0, value = 0.44},
        smoothAlpha = { step = 0.01, precision = 3.0, ui_type = "slider", ui_name = "骨骼平滑因子", max = 1.0, min = 0.0, value = 0.6 },
        thighBoxWidth = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "宽度", max = 2.5, min = 0.5, value = 1.5 },
        thighBoneAlongCoefUp = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "上基线上移", max = 1.0, min = 0.0, value = 0.45 },
        thighBoneAlongCoefDown = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "下基线下移", max = 1.5, min = 0.0, value = 0.25 },
        midDownAdjust = { step = 0.01, precision = 2.0, ui_type = "slider", ui_name = "中下段调整因子", max = 2, min = 0.0, value = 1.28 },
    },
}


paramTable = {}
paramTable["MVAR"] = {
    thighDeformIntensity = ui.thighDeformIntensity,
    thighLeftDeformIntensity = ui.thighLeftDeformIntensity,
    thighRightDeformIntensity = ui.thighRightDeformIntensity,
}

return {ui = ui, paramTable = paramTable}

--return ui
