-- @author: zzy6@meitu.com
------ ui
ui = {
	-- rate = { step = 1.00, ui_name_en = "Size", ui_name_tw = "变形程度", max = 100.00, min = -100.00, ui_name = "变形程度", ui_type = "slider", value = 0.00 },
	--blendshape_file = { ui_name_tw = "BLS文件", ui_type = "resourceComboBox", ui_name_en = "BLS File", filter = 2048.00, ui_name = "BLS文件", path = "ar3d/normal.bls", resourceType = 6.00, model_path = "ar3d/normal.bls" },
	TrapeziusGroupBox = {
		ui_type = "groupbox", ui_fold = true,ui_title = true,ui_name ="斜方肌力度",ui_name_en = "trapeziusDegree", ui_name_tw = "斜方肌力度",
		degree =  { step = 0.01,precision = 2.00, ui_name_en = "hunman1", ui_name_tw = "效果点位移缩放", max = 2.00, min = 0.01, ui_name = "效果点位移缩放", ui_type = "slider", value = 0.75 },
        human1 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman1", ui_name_tw = "第一个人", max = 200.00, min = -200.00, ui_name = "第一个人", ui_type = "slider", value = 0.0 },
		human2 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman2", ui_name_tw = "第二个人", max = 200.00, min = -200.00, ui_name = "第二个人", ui_type = "slider", value = 0.0 },
		human3 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman3", ui_name_tw = "第三个人", max = 200.00, min = -200.00, ui_name = "第三个人", ui_type = "slider", value = 0.0 },
		human4 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman4", ui_name_tw = "第四个人", max = 200.00, min = -200.00, ui_name = "第四个人", ui_type = "slider", value = 0.0 },
		human5 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman5", ui_name_tw = "第五个人", max = 200.00, min = -200.00, ui_name = "第五个人", ui_type = "slider", value = 0.0 },
		human6 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman6", ui_name_tw = "第六个人", max = 200.00, min = -200.00, ui_name = "第六个人", ui_type = "slider", value = 0.0 },
		human7 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman7", ui_name_tw = "第七个人", max = 200.00, min = -200.00, ui_name = "第七个人", ui_type = "slider", value = 0.0 },
		human8 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman8", ui_name_tw = "第八个人", max = 200.00, min = -200.00, ui_name = "第八个人", ui_type = "slider", value = 0.0 },
		human9 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman9", ui_name_tw = "第九个人", max = 200.00, min = -200.00, ui_name = "第九个人", ui_type = "slider", value = 0.0 },
		human10 =  { step = 0.01,precision = 2.00, ui_name_en = "hunman10", ui_name_tw = "第十个人", max = 200.00, min = -200.00, ui_name = "第十个人", ui_type = "slider", value = 0.0 },
		guassDegree = { step = 1.00, ui_name_en = "guassDegree", ui_name_tw = "平滑程度", max = 100.00, min = 0.00, ui_name = "平滑程度", ui_type = "slider", value = 100.00 },
		order = { "human1", "human2", "human3","human4","human5","human6", "human7", "human8","human9","human10","guassDegree"}
	},
	-- hipdegree = { step = 1.00, ui_name_en = "HipDegree", ui_name_tw = "翘臀力度", max = 200.00, min = -200.00, ui_name = "翘臀力度", ui_type = "slider", value = 80.00 },
	-- bellydegree = { step = 1.00, ui_name_en = "BellyDegree", ui_name_tw = "小腹力度", max = 200.00, min = -200.00, ui_name = "小腹力度", ui_type = "slider", value = 80.00 },
	-- backdegree = { step = 1.00, ui_name_en = "BackDegree", ui_name_tw = "驼背力度", max = 200.00, min = -200.00, ui_name = "驼背力度", ui_type = "slider", value = 80.00 },
	material_model = {
		ui_type = "combox",ui_name = "打印网格对应的模型文件",ui_name_en="Template file",ui_name_tw="範本文件",value=1,visible = true,
		items={
			{name="丰胸",name_en = "Template0", name_tw = "範本0"},
			{name="缩胸",name_en = "Template1", name_tw = "範本1"},
			{name="天鹅颈",name_en = "Template1", name_tw = "範本1"},
		}
	},
	edgeProtectionSize = { ui_type = "slider", ui_name = "边缘保护范围", value = 0, min = 0.0, max = 100.0, step = 1},
	faceProtect = { ui_type = "switch", value = true, ui_name_tw = "应用人脸保护", ui_name_en = "enable Face Mask Protect", ui_name = "应用人脸保护" },
	backgroundPainting = { ui_type = "switch", value = false, ui_name_tw = "应用背景填充", ui_name_en = "enable Mask", ui_name = "应用背景填充" },
	protectMask = { ui_type = "switch", value = false, ui_name_tw = "应用Mask保护", ui_name_en = "enable Mask Protect", ui_name = "应用Mask保护" },
	debugGrid = { ui_type = "switch", value = false, ui_name_tw = "打印网格", ui_name_en = "Debug", ui_name = "打印网格" },

	position1 = {
        ui_type = "groupbox", ui_fold = false,ui_title = true,ui_name ="缩放",ui_name_en = "Scale", ui_name_tw = "缩放",
        order = { "x", "y", "z" },
        x = { ui_type = "slider", ui_name = "X", value = 0, min = -100.0, max = 100.0, step = 1 },
        y = { ui_type = "slider", ui_name = "Y", value = 0, min = -100.0, max = 100.0, step = 1 },
		z = { ui_type = "slider", ui_name = "Z", value = 0, min = -100.0, max = 100.0, step = 1 },
    },
	position2 = {
        ui_type = "groupbox", ui_fold = false,ui_title = true,ui_name ="位移",ui_name_en = "Trance", ui_name_tw = "位移",
        order = { "x", "y", "z" },
        x = { ui_type = "slider", ui_name = "X", value = 0, min = -100.0, max = 100.0, step = 1 },
        y = { ui_type = "slider", ui_name = "Y", value = 0, min = -100.0, max = 100.0, step = 1 },
		z = { ui_type = "slider", ui_name = "Z", value = 0, min = -100.0, max = 100.0, step = 1 },
    },

	order = {"TrapeziusGroupBox","material_model","showMask","debugGrid","faceProtect","edgeProtectionSize","position1","position2"}
}


paramTable = {}
paramTable["default"] = {
    order = ui.order,
    material_model = ui.material_model,
    debugGrid = ui.debugGrid,

	TrapeziusGroupBox = ui.TrapeziusGroupBox,
	TrapeziusGroupBox_order = ui.TrapeziusGroupBox.order,
	TrapeziusGroupBox_human1 = ui.TrapeziusGroupBox.human1,
	TrapeziusGroupBox_human2 = ui.TrapeziusGroupBox.human2,
	TrapeziusGroupBox_human3 = ui.TrapeziusGroupBox.human3,
	TrapeziusGroupBox_human4 = ui.TrapeziusGroupBox.human4,
	TrapeziusGroupBox_human5 = ui.TrapeziusGroupBox.human5,
	TrapeziusGroupBox_human6 = ui.TrapeziusGroupBox.human6,
	TrapeziusGroupBox_human7 = ui.TrapeziusGroupBox.human7,
	TrapeziusGroupBox_human8 = ui.TrapeziusGroupBox.human8,
	TrapeziusGroupBox_human9 = ui.TrapeziusGroupBox.human9,
	TrapeziusGroupBox_human10 = ui.TrapeziusGroupBox.human10,
	TrapeziusGroupBox_guassDegree = ui.TrapeziusGroupBox.guassDegree,
}

return {ui = ui, paramTable = paramTable}