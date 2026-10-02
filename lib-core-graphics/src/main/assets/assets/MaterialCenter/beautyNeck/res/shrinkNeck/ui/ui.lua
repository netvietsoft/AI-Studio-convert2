-- @author: zzy6@meitu.com
------ ui
ui = {
	-- rate = { step = 1.00, ui_name_en = "Size", ui_name_tw = "变形程度", max = 100.00, min = -100.00, ui_name = "变形程度", ui_type = "slider", value = 0.00 },
	--blendshape_file = { ui_name_tw = "BLS文件", ui_type = "resourceComboBox", ui_name_en = "BLS File", filter = 2048.00, ui_name = "BLS文件", path = "ar3d/normal.bls", resourceType = 6.00, model_path = "ar3d/normal.bls" },
	isShrinkNeck = { ui_type = "switch", value = true, ui_name = "开启瘦脖子" },
    isNeckLength = { ui_type = "switch", value = true, ui_name = "开启脖子长度" },
	NeckThinning = { step = 0.01, precision = 2.00, ui_name_en = "NeckThinning", ui_name_tw = "瘦脖子力度", max = 1.00, min = -1.00, ui_name = "瘦脖子力度", ui_type = "slider", value = 0.0},
	NeckLengthening = { step = 0.01, precision = 2.00, ui_name_en = "NeckLengthening", ui_name_tw = "脖子长度力度", max = 1.00, min = -1.00, ui_name = "脖子长度力度", ui_type = "slider", value = 0.0},
	shoulderId = {step = 1.0,precision = 0.00,ui_type = "slider",ui_name = "shoulder ID",max = 5.0,min = 1.00,value = 1.00},
	isNeckLengthDebug = { ui_type = "switch", value = false, ui_name = "开启脖子长度Debug" },
	isShrinkNeckDebug = { ui_type = "switch", value = false, ui_name = "开启瘦脖子Debug" },
	order = { "isShrinkNeck","NeckThinning","isShrinkNeckDebug","isNeckLength", "NeckLengthening","isNeckLengthDebug"}
}


paramTable = {}
paramTable["default"] = {
    order = ui.order,
    shrinkNeckIntensity = ui.NeckThinning,
	neckLengthIntensity = ui.NeckLengthening,
	neckLengthDebug = ui.isNeckLengthDebug
}

return {ui = ui, paramTable = paramTable}