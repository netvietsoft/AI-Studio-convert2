-- @author: tmw1

------ ui
ui = {}

ui_1 = {
    brushType = {
        ui_type = "combox",
        ui_name = "笔刷类型",
        value = 1.00,
        items = {
            { name = "橡皮擦" },
            { name = "直发笔刷" },
            { name = "卷发笔刷" },
        }
    },
    scaleUI = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "界面缩放倍数", max = 50.0, min = 1.0, value = 1.0 },
    size = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "笔画大小", max = 90.0, min = 3.0, value = 30.0 },
    rotAngle = { step = 1.0, precision = 0.00, ui_type = "slider", ui_name = "旋转角度(°)", max = 360.0, min = 0.00, value = 0.0 },
    tailDuration = { step = 10.0, precision = 0.00, ui_type = "slider", ui_name = "拖尾时长(ms)", max = 200.0, min = 0.00, value = 0.0 },
    tailMinLength = { step = 1.0, precision = 0.00, ui_type = "slider", ui_name = "拖尾最小长度(%)", max = 1000.0, min = 0.00, value = 0.0 },
    curlHairSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "卷发生成设置",
        ui_fold = false,
        visible = false,
        genCurlHair = { ui_type = "switch", value = true, ui_name = "生成卷发笔刷" },
        amplitude = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "幅度", max = 1.0, min = 0.01, value = 0.5 },
        initialPhase = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "初相(起始)", max = 1.0, min = 0.00, value = 0.00 },
        lineMaxWidth = { step = 1, precision = 0.00, ui_type = "slider", ui_name = "线条宽度", max = 90, min = 3.00, value = 30 },
        relativeDistance = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "前后笔相对距离", max = 2.0, min = 0.01, value = 1.00 },
        frequency = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "频率", max = 2.0, min = 0.5, value = 1.00 },
        blendWidthRatio = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "边缘模糊比例", max = 1.0, min = 0.0, value = 0.5 },
        order = { "genCurlHair", "amplitude", "initialPhase", "lineMaxWidth", "relativeDistance", "frequency", "blendWidthRatio" }
    },
    brushImage = {
        ui_type = "combox",
        ui_name = "笔刷图片",
        value = 7.00,
        items = {
            { name = "brush1" },
            { name = "brush2" },
            { name = "brush3" },
            { name = "brush4" },
            { name = "brush5" },
            { name = "brush6" },
            { name = "brush7" },
            { name = "brush8" },
            { name = "brush9" },
        }
    },
    color = { ui_type = "color", ui_name="画笔颜色", ui_format = "r&g&b&a", r = 252, g = 151, b= 224, a = 125 },
    interSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "插值点设置",
        ui_fold = false,
        lineInter = { ui_type = "switch", value = true, ui_name = "笔刷间距大时，启用线性插值" },
        lineInterDistance = { step = 0.1, precision = 3.00, ui_type = "slider", ui_name = "相对插值距离", max = 1.0, min = 0.001, value = 0.1 },
        minGap = { step = 0.001, precision = 3.00, ui_type = "slider", ui_name = "控制点最小距离", max = 0.1, min = 0.001, value = 0.022 },
        interMinGap = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "插值点最小距离", max = 0.01, min = 0.0001, value = 0.001 },
        intervalUnit = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "素材之间最小距离", max = 0.01, min = 0.0001, value = 0.001 },
        minInterPixelSize = { step = 0.1, precision = 2.00, ui_type = "slider", ui_name = "最小插值距离（像素点个数）", max = 5.0, min = 0.01, value = 1 },
        order = { "lineInter", "lineInterDistance", "minGap", "interMinGap", "intervalUnit", "minInterPixelSize" }
    },
    others = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "其他设置",
        ui_fold = false,
        rotWithDirection = { ui_type = "switch", value = false, ui_name = "笔刷方向跟随轨迹方向" },
        enableMSAA = { ui_type = "switch", value = false, ui_name = "开启MSAA", visible = false },
        enableConnectingCurvature = { ui_type = "switch", value = false, ui_name = "开启衔接圆弧" },
        connectingCurvature = { step = 1, precision = 3.00, ui_type = "slider", ui_name = "衔接曲率", max = 10, min = 1, value = 0 },
        order = { "rotWithDirection", "enableMSAA",  "enableConnectingCurvature", "connectingCurvature" }
    },
    logLevel = {
        ui_type = "combox",
        ui_name = "日志等级",
        value = 3.00,
        items = {
            { name = "fatal" },
            { name = "error" },
            { name = "waring" },
            { name = "info" },
            { name = "debug" },
        }
    },
    order = { "brushType", "scaleUI", "size", "rotAngle", "tailDuration", "tailMinLength", "brushImage", "color", "interSetting", "others", "logLevel"  }
}

ui_2 = {
    brushType = {
        ui_type = "combox",
        ui_name = "笔刷类型",
        value = 2.00,
        items = {
            { name = "橡皮擦" },
            { name = "直发笔刷" },
            { name = "卷发笔刷" },
        }
    },
    scaleUI = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "界面缩放倍数", max = 50.0, min = 1.0, value = 1.0 },
    size = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "笔画大小", max = 90.0, min = 1.0, value = 30.0 },
    rotAngle = { step = 1.0, precision = 0.00, ui_type = "slider", ui_name = "旋转角度(°)", max = 360.0, min = 0.00, value = 0.0 },
    tailDuration = { step = 10.0, precision = 0.00, ui_type = "slider", ui_name = "拖尾时长(ms)", max = 200.0, min = 0.00, value = 50.0 },
    tailMinLength = { step = 1.0, precision = 0.00, ui_type = "slider", ui_name = "拖尾最小长度(%)", max = 1000.0, min = 0.00, value = 624.0 },
    curlHairSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "卷发生成设置",
        ui_fold = false,
        visible = false,
        genCurlHair = { ui_type = "switch", value = true, ui_name = "生成卷发笔刷" },
        amplitude = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "幅度", max = 1.0, min = 0.01, value = 0.5 },
        initialPhase = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "初相(起始)", max = 1.0, min = 0.00, value = 0.00 },
        lineMaxWidth = { step = 1, precision = 0.00, ui_type = "slider", ui_name = "线条宽度", max = 90, min = 3.00, value = 30 },
        relativeDistance = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "前后笔相对距离", max = 2.0, min = 0.01, value = 1.00 },
        frequency = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "频率", max = 2.0, min = 0.5, value = 1.00 },
        blendWidthRatio = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "边缘模糊比例", max = 1.0, min = 0.0, value = 0.5 },
        order = { "genCurlHair", "amplitude", "initialPhase", "lineMaxWidth", "relativeDistance", "frequency", "blendWidthRatio" }
    },
    brushImage = {
        ui_type = "combox",
        ui_name = "笔刷图片",
        value = 7.00,
        items = {
            { name = "brush1" },
            { name = "brush2" },
            { name = "brush3" },
            { name = "brush4" },
            { name = "brush5" },
            { name = "brush6" },
            { name = "brush7" },
            { name = "brush8" },
            { name = "brush9" },
        }
    },
    color = { ui_type = "color", ui_name="画笔颜色", ui_format = "r&g&b&a", r = 252, g = 151, b= 224, a = 125 },
    interSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "插值点设置",
        ui_fold = false,
        lineInter = { ui_type = "switch", value = true, ui_name = "笔刷间距大时，启用线性插值" },
        lineInterDistance = { step = 0.1, precision = 3.00, ui_type = "slider", ui_name = "相对插值距离", max = 1.0, min = 0.001, value = 0.1 },
        minGap = { step = 0.001, precision = 3.00, ui_type = "slider", ui_name = "控制点最小距离", max = 0.1, min = 0.001, value = 0.031 },
        interMinGap = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "插值点最小距离", max = 0.01, min = 0.0001, value = 0.002 },
        intervalUnit = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "素材之间最小距离", max = 0.01, min = 0.0001, value = 0.002 },
        minInterPixelSize = { step = 0.1, precision = 2.00, ui_type = "slider", ui_name = "最小插值距离（像素点个数）", max = 5.0, min = 0.01, value = 1 },
        order = { "lineInter", "lineInterDistance", "minGap", "interMinGap", "intervalUnit", "minInterPixelSize" }
    },
    others = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "其他设置",
        ui_fold = false,
        rotWithDirection = { ui_type = "switch", value = false, ui_name = "笔刷方向跟随轨迹方向" },
        enableMSAA = { ui_type = "switch", value = false, ui_name = "开启MSAA", visible = false },
        enableConnectingCurvature = { ui_type = "switch", value = true, ui_name = "开启衔接圆弧" },
        connectingCurvature = { step = 1, precision = 3.00, ui_type = "slider", ui_name = "衔接曲率", max = 10, min = 1, value = 7.158 },
        order = { "rotWithDirection", "enableMSAA",  "enableConnectingCurvature", "connectingCurvature" }
    },
    logLevel = {
        ui_type = "combox",
        ui_name = "日志等级",
        value = 3.00,
        items = {
            { name = "fatal" },
            { name = "error" },
            { name = "waring" },
            { name = "info" },
            { name = "debug" },
        }
    },
    order = { "brushType", "scaleUI", "size", "rotAngle", "tailDuration", "tailMinLength", "brushImage", "color", "interSetting", "others", "logLevel"  }
}

ui_3 = {
    brushType = {
        ui_type = "combox",
        ui_name = "笔刷类型",
        value = 3.00,
        items = {
            { name = "橡皮擦" },
            { name = "直发笔刷" },
            { name = "卷发笔刷" },
        }
    },
    scaleUI = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "界面缩放倍数", max = 50.0, min = 1.0, value = 1.0 },
    size = { step = 1.0, precision = 1.00, ui_type = "slider", ui_name = "笔画大小", max = 500.0, min = 3.0, value = 200.0 },
    rotAngle = { step = 1.0, precision = 0.00, ui_type = "slider", ui_name = "旋转角度(°)", max = 360.0, min = 0.00, value = 0.0 },
    tailDuration = { step = 10.0, precision = 0.00, ui_type = "slider", visible = false, ui_name = "拖尾时长(ms)", max = 200.0, min = 0.00, value = 0.0 },
    tailMinLength = { step = 1.0, precision = 0.00, ui_type = "slider", visible = false, ui_name = "拖尾最小长度(%)", max = 1000.0, min = 0.00, value = 0.0 },
    curlHairSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "卷发生成设置",
        ui_fold = false,
        visible = true,
        genCurlHair = { ui_type = "switch", value = true, ui_name = "生成卷发笔刷" },
        amplitude = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "幅度", max = 1.0, min = 0.01, value = 0.2 },
        initialPhase = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "初相(起始)", max = 1.0, min = 0.00, value = 0.00 },
        lineMaxWidth = { step = 1, precision = 0.00, ui_type = "slider", ui_name = "线条宽度", max = 90, min = 3.00, value = 22 },
        relativeDistance = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "前后笔相对距离", max = 2.0, min = 0.01, value = 0.80 },
        frequency = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "频率", max = 2.0, min = 0.5, value = 1.20 },
        blendWidthRatio = { step = 0.01, precision = 2.00, ui_type = "slider", ui_name = "边缘模糊比例", max = 1.0, min = 0.0, value = 0.34 },
        order = { "genCurlHair", "amplitude", "initialPhase", "lineMaxWidth", "relativeDistance", "frequency", "blendWidthRatio" }
    },
    brushImage = {
        ui_type = "combox",
        ui_name = "笔刷图片",
        value = 8.00,
        items = {
            { name = "brush1" },
            { name = "brush2" },
            { name = "brush3" },
            { name = "brush4" },
            { name = "brush5" },
            { name = "brush6" },
            { name = "brush7" },
            { name = "brush8" },
            { name = "brush9" },
        }
    },
    color = { ui_type = "color", ui_name="画笔颜色", ui_format = "r&g&b&a", r = 252, g = 151, b= 224, a = 125 },
    interSetting = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "插值点设置",
        ui_fold = false,
        visible = false,
        lineInter = { ui_type = "switch", value = true, ui_name = "笔刷间距大时，启用线性插值" },
        lineInterDistance = { step = 0.1, precision = 3.00, ui_type = "slider", ui_name = "相对插值距离", max = 1.0, min = 0.001, value = 0.1 },
        minGap = { step = 0.001, precision = 3.00, ui_type = "slider", ui_name = "控制点最小距离", max = 0.1, min = 0.001, value = 0.031 },
        interMinGap = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "插值点最小距离", max = 0.01, min = 0.0001, value = 0.001 },
        intervalUnit = { step = 0.0001, precision = 4.00, ui_type = "slider", ui_name = "素材之间最小距离", max = 0.01, min = 0.0001, value = 0.001 },
        minInterPixelSize = { step = 1, precision = 0.00, ui_type = "slider", ui_name = "最小插值距离（像素点个数）", max = 10.0, min = 1, value = 1 },
        order = { "lineInter", "lineInterDistance", "minGap", "interMinGap", "intervalUnit", "minInterPixelSize" }
    },
    others = {
        ui_type = "groupbox",
        ui_title = true,
        ui_name = "其他设置",
        ui_fold = false,
        visible = false,
        rotWithDirection = { ui_type = "switch", value = false, ui_name = "笔刷方向跟随轨迹方向" },
        enableMSAA = { ui_type = "switch", value = false, ui_name = "开启MSAA", visible = false },
        enableConnectingCurvature = { ui_type = "switch", value = false, ui_name = "开启衔接圆弧" },
        connectingCurvature = { step = 1, precision = 3.00, ui_type = "slider", ui_name = "衔接曲率", max = 10, min = 1, value = 0 },
        order = { "rotWithDirection", "enableMSAA",  "enableConnectingCurvature", "connectingCurvature" }
    },
    logLevel = {
        ui_type = "combox",
        ui_name = "日志等级",
        value = 3.00,
        items = {
            { name = "fatal" },
            { name = "error" },
            { name = "waring" },
            { name = "info" },
            { name = "debug" },
        }
    },
    order = { "brushType", "scaleUI", "size", "rotAngle", "tailDuration", "tailMinLength", "curlHairSetting", "brushImage", "color", "interSetting", "others", "logLevel"  }
}


paramTable = {}
paramTable["default"] = {
    size = ui.size,
}

return {uiList = {ui_1, ui_2, ui_3}, paramTable = paramTable}