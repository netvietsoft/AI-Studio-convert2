-- author: xyg2@meitu.com

local function makeHumanSlider(name)
    return { step = 1.00, precision = 2.00, ui_type = "slider", ui_name = name, max = 200.0, min = -200.0, value = 0.0 }
end

ui = {
    order = {
        "upperDeformIntensity", "upperLeftDeformIntensity", "upperRightDeformIntensity",
        "thighDeformIntensity", "thighLeftDeformIntensity", "thighRightDeformIntensity",
        "calfDeformIntensity", "calfLeftDeformIntensity", "calfRightDeformIntensity",
        "hipGroupBox_human1", "bellyGroupBox_human1", "backGroupBox_human1", "TrapeziusGroupBox_human1",
        "switch", "feather", "mix", "rgba"
    },
    switch = { ui_type = "switch", value = false, ui_name = "启用背景分割" },
    feather = { ui_type = "slider", ui_name = "羽化", value = 0.15, min = 0.0, max = 2.0, step = 0.01, precision = 2 },
    mix = { ui_type = "switch", value = false, ui_name = "纯色背景填充(仅用查看扣像结果)" },
    rgba = { ui_type = "color", ui_name = "填充背景颜色", ui_format = "r&g&b&a", r = 255, g = 0, b = 0, a = 255 },

    upperDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦大臂力度", max = 1.0, min = -1, value = 0 },
    upperLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦左大臂力度", max = 1.0, min = -1, value = 0 },
    upperRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦右大臂力度", max = 1.0, min = -1, value = 0 },
    thighDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦大腿力度", max = 1.0, min = -1, value = 0 },
    thighLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦左大腿力度", max = 1.0, min = -1, value = 0 },
    thighRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦右大腿力度", max = 1.0, min = -1, value = 0 },
    calfDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦小腿力度", max = 1.0, min = -1, value = 0 },
    calfLeftDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦左小腿力度", max = 1.0, min = -1, value = 0 },
    calfRightDeformIntensity = { step = 0.01, precision = 3.00, ui_type = "slider", ui_name = "瘦右小腿力度", max = 1.0, min = -1, value = 0 },
}

for i = 1, 10 do
    ui["hipGroupBox_human" .. i] = makeHumanSlider("翘臀人像" .. i)
    ui["bellyGroupBox_human" .. i] = makeHumanSlider("瘦小腹人像" .. i)
    ui["backGroupBox_human" .. i] = makeHumanSlider("直背人像" .. i)
    ui["TrapeziusGroupBox_human" .. i] = makeHumanSlider("斜方肌人像" .. i)
end

paramTable = {}
paramTable["default"] = {
    switch = ui.switch,
    upperDeformIntensity = ui.upperDeformIntensity,
    upperLeftDeformIntensity = ui.upperLeftDeformIntensity,
    upperRightDeformIntensity = ui.upperRightDeformIntensity,
    thighDeformIntensity = ui.thighDeformIntensity,
    thighLeftDeformIntensity = ui.thighLeftDeformIntensity,
    thighRightDeformIntensity = ui.thighRightDeformIntensity,
    calfDeformIntensity = ui.calfDeformIntensity,
    calfLeftDeformIntensity = ui.calfLeftDeformIntensity,
    calfRightDeformIntensity = ui.calfRightDeformIntensity,
}

for i = 1, 10 do
    paramTable["default"]["hipGroupBox_human" .. i] = ui["hipGroupBox_human" .. i]
    paramTable["default"]["bellyGroupBox_human" .. i] = ui["bellyGroupBox_human" .. i]
    paramTable["default"]["backGroupBox_human" .. i] = ui["backGroupBox_human" .. i]
    paramTable["default"]["TrapeziusGroupBox_human" .. i] = ui["TrapeziusGroupBox_human" .. i]
end

return { ui = ui, paramTable = paramTable }
