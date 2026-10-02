-- @author: zzy6@meitu.com
------ ui
ui = {
	-- rate = { step = 1.00, ui_name_en = "Size", ui_name_tw = "变形程度", max = 100.00, min = -100.00, ui_name = "变形程度", ui_type = "slider", value = 0.00 },
	--blendshape_file = { ui_name_tw = "BLS文件", ui_type = "resourceComboBox", ui_name_en = "BLS File", filter = 2048.00, ui_name = "BLS文件", path = "ar3d/normal.bls", resourceType = 6.00, model_path = "ar3d/normal.bls" },
	hipGroupBox = {
		ui_type = "groupbox", ui_fold = true,ui_title = true,ui_name ="翘臀力度",ui_name_en = "hipDegree", ui_name_tw = "翘臀力度",
        human1 =  { step = 1.00, ui_name_en = "hunman1", ui_name_tw = "第一个人", max = 200.00, min = -200.00, ui_name = "第一个人", ui_type = "slider", value = 0.00 },
		human2 =  { step = 1.00, ui_name_en = "hunman2", ui_name_tw = "第二个人", max = 200.00, min = -200.00, ui_name = "第二个人", ui_type = "slider", value = 0.00 },
		human3 =  { step = 1.00, ui_name_en = "hunman3", ui_name_tw = "第三个人", max = 200.00, min = -200.00, ui_name = "第三个人", ui_type = "slider", value = 0.00 },
		human4 =  { step = 1.00, ui_name_en = "hunman4", ui_name_tw = "第四个人", max = 200.00, min = -200.00, ui_name = "第四个人", ui_type = "slider", value = 0.00 },
		human5 =  { step = 1.00, ui_name_en = "hunman5", ui_name_tw = "第五个人", max = 200.00, min = -200.00, ui_name = "第五个人", ui_type = "slider", value = 0.00 },
		human6 =  { step = 1.00, ui_name_en = "hunman6", ui_name_tw = "第六个人", max = 200.00, min = -200.00, ui_name = "第六个人", ui_type = "slider", value = 0.00 },
		human7 =  { step = 1.00, ui_name_en = "hunman7", ui_name_tw = "第七个人", max = 200.00, min = -200.00, ui_name = "第七个人", ui_type = "slider", value = 0.00 },
		human8 =  { step = 1.00, ui_name_en = "hunman8", ui_name_tw = "第八个人", max = 200.00, min = -200.00, ui_name = "第八个人", ui_type = "slider", value = 0.00 },
		human9 =  { step = 1.00, ui_name_en = "hunman9", ui_name_tw = "第九个人", max = 200.00, min = -200.00, ui_name = "第九个人", ui_type = "slider", value = 0.00 },
		human10 =  { step = 1.00, ui_name_en = "hunman10", ui_name_tw = "第十个人", max = 200.00, min = -200.00, ui_name = "第十个人", ui_type = "slider", value = 0.00 },
		guassDegree = { step = 1.00, ui_name_en = "guassDegree", ui_name_tw = "平滑程度", max = 100.00, min = 0.00, ui_name = "平滑程度", ui_type = "slider", value = 73.00 },
		order = { "human1", "human2", "human3","human4","human5","human6", "human7", "human8","human9","human10","guassDegree" }
	},
	bellyGroupBox = {
		ui_type = "groupbox", ui_fold = true,ui_title = true,ui_name ="小腹力度",ui_name_en = "bellyDegree", ui_name_tw = "小腹力度",
        human1 =  { step = 1.00, ui_name_en = "hunman1", ui_name_tw = "第一个人", max = 200.00, min = -200.00, ui_name = "第一个人", ui_type = "slider", value = 0.00 },
		human2 =  { step = 1.00, ui_name_en = "hunman2", ui_name_tw = "第二个人", max = 200.00, min = -200.00, ui_name = "第二个人", ui_type = "slider", value = 0.00 },
		human3 =  { step = 1.00, ui_name_en = "hunman3", ui_name_tw = "第三个人", max = 200.00, min = -200.00, ui_name = "第三个人", ui_type = "slider", value = 0.00 },
		human4 =  { step = 1.00, ui_name_en = "hunman4", ui_name_tw = "第四个人", max = 200.00, min = -200.00, ui_name = "第四个人", ui_type = "slider", value = 0.00 },
		human5 =  { step = 1.00, ui_name_en = "hunman5", ui_name_tw = "第五个人", max = 200.00, min = -200.00, ui_name = "第五个人", ui_type = "slider", value = 0.00 },
		human6 =  { step = 1.00, ui_name_en = "hunman6", ui_name_tw = "第六个人", max = 200.00, min = -200.00, ui_name = "第六个人", ui_type = "slider", value = 0.00 },
		human7 =  { step = 1.00, ui_name_en = "hunman7", ui_name_tw = "第七个人", max = 200.00, min = -200.00, ui_name = "第七个人", ui_type = "slider", value = 0.00 },
		human8 =  { step = 1.00, ui_name_en = "hunman8", ui_name_tw = "第八个人", max = 200.00, min = -200.00, ui_name = "第八个人", ui_type = "slider", value = 0.00 },
		human9 =  { step = 1.00, ui_name_en = "hunman9", ui_name_tw = "第九个人", max = 200.00, min = -200.00, ui_name = "第九个人", ui_type = "slider", value = 0.00 },
		human10 =  { step = 1.00, ui_name_en = "hunman10", ui_name_tw = "第十个人", max = 200.00, min = -200.00, ui_name = "第十个人", ui_type = "slider", value = 0.00 },
		guassDegree = { step = 1.00, ui_name_en = "guassDegree", ui_name_tw = "平滑程度", max = 100.00, min = 0.00, ui_name = "平滑程度", ui_type = "slider", value = 85.00 },
		order = { "human1", "human2", "human3","human4","human5","human6", "human7", "human8","human9","human10","guassDegree" }
	},
	backGroupBox = {
		ui_type = "groupbox", ui_fold = true,ui_title = true,ui_name ="驼背力度",ui_name_en = "backDegree", ui_name_tw = "驼背力度",
        human1 =  { step = 1.00, ui_name_en = "hunman1", ui_name_tw = "第一个人", max = 200.00, min = -200.00, ui_name = "第一个人", ui_type = "slider", value = 0.00 },
		human2 =  { step = 1.00, ui_name_en = "hunman2", ui_name_tw = "第二个人", max = 200.00, min = -200.00, ui_name = "第二个人", ui_type = "slider", value = 0.00 },
		human3 =  { step = 1.00, ui_name_en = "hunman3", ui_name_tw = "第三个人", max = 200.00, min = -200.00, ui_name = "第三个人", ui_type = "slider", value = 0.00 },
		human4 =  { step = 1.00, ui_name_en = "hunman4", ui_name_tw = "第四个人", max = 200.00, min = -200.00, ui_name = "第四个人", ui_type = "slider", value = 0.00 },
		human5 =  { step = 1.00, ui_name_en = "hunman5", ui_name_tw = "第五个人", max = 200.00, min = -200.00, ui_name = "第五个人", ui_type = "slider", value = 0.00 },
		human6 =  { step = 1.00, ui_name_en = "hunman6", ui_name_tw = "第六个人", max = 200.00, min = -200.00, ui_name = "第六个人", ui_type = "slider", value = 0.00 },
		human7 =  { step = 1.00, ui_name_en = "hunman7", ui_name_tw = "第七个人", max = 200.00, min = -200.00, ui_name = "第七个人", ui_type = "slider", value = 0.00 },
		human8 =  { step = 1.00, ui_name_en = "hunman8", ui_name_tw = "第八个人", max = 200.00, min = -200.00, ui_name = "第八个人", ui_type = "slider", value = 0.00 },
		human9 =  { step = 1.00, ui_name_en = "hunman9", ui_name_tw = "第九个人", max = 200.00, min = -200.00, ui_name = "第九个人", ui_type = "slider", value = 0.00 },
		human10 =  { step = 1.00, ui_name_en = "hunman10", ui_name_tw = "第十个人", max = 200.00, min = -200.00, ui_name = "第十个人", ui_type = "slider", value = 0.00 },
		guassDegree = { step = 1.00, ui_name_en = "guassDegree", ui_name_tw = "平滑程度", max = 100.00, min = 0.00, ui_name = "平滑程度", ui_type = "slider", value = 85.00 },
		order = { "human1", "human2", "human3","human4","human5","human6", "human7", "human8","human9","human10","guassDegree"}
	},

	-- hipdegree = { step = 1.00, ui_name_en = "HipDegree", ui_name_tw = "翘臀力度", max = 200.00, min = -200.00, ui_name = "翘臀力度", ui_type = "slider", value = 80.00 },
	-- bellydegree = { step = 1.00, ui_name_en = "BellyDegree", ui_name_tw = "小腹力度", max = 200.00, min = -200.00, ui_name = "小腹力度", ui_type = "slider", value = 80.00 },
	-- backdegree = { step = 1.00, ui_name_en = "BackDegree", ui_name_tw = "驼背力度", max = 200.00, min = -200.00, ui_name = "驼背力度", ui_type = "slider", value = 80.00 },
	material_model = {
		ui_type = "combox",ui_name = "打印网格对应的模型文件",ui_name_en="Template file",ui_name_tw="範本文件",value=1,visible = true,
		items={
			{name="翘臀",name_en = "Template0", name_tw = "範本0"},
			{name="小腹",name_en = "Template1", name_tw = "範本1"},
			{name="驼背",name_en = "Template2", name_tw = "範本2"},
		}
	},
	backgroundPainting = { ui_type = "switch", value = false, ui_name_tw = "应用背景填充", ui_name_en = "enable Mask", ui_name = "应用背景填充" },
	debugGrid = { ui_type = "switch", value = false, ui_name_tw = "打印网格", ui_name_en = "Debug", ui_name = "打印网格" },
	order = {"hipGroupBox","bellyGroupBox","backGroupBox","material_model","showMask","debugGrid"}
}


paramTable = {}
paramTable["default"] = {
    order = ui.order,
    material_model = ui.material_model,
    hipdegree = ui.hipdegree,
	bellydegree = ui.bellydegree,
	backdegree = ui.backdegree,
    backgroundPainting = ui.backgroundPainting,
    debugGrid = ui.debugGrid,

	hipGroupBox = ui.hipGroupBox,
	hipGroupBox_order = ui.hipGroupBox.order,
	hipGroupBox_human1 = ui.hipGroupBox.human1,
	hipGroupBox_human2 = ui.hipGroupBox.human2,
	hipGroupBox_human3 = ui.hipGroupBox.human3,
	hipGroupBox_human4 = ui.hipGroupBox.human4,
	hipGroupBox_human5 = ui.hipGroupBox.human5,
	hipGroupBox_human6 = ui.hipGroupBox.human6,
	hipGroupBox_human7 = ui.hipGroupBox.human7,
	hipGroupBox_human8 = ui.hipGroupBox.human8,
	hipGroupBox_human9 = ui.hipGroupBox.human9,
	hipGroupBox_human10 = ui.hipGroupBox.human10,
	hipGroupBox_guassDegree = ui.hipGroupBox.guassDegree,

	bellyGroupBox = ui.bellyGroupBox,
	bellyGroupBox_order = ui.bellyGroupBox.order,
	bellyGroupBox_human1 = ui.bellyGroupBox.human1,
	bellyGroupBox_human2 = ui.bellyGroupBox.human2,
	bellyGroupBox_human3 = ui.bellyGroupBox.human3,
	bellyGroupBox_human4 = ui.bellyGroupBox.human4,
	bellyGroupBox_human5 = ui.bellyGroupBox.human5,
	bellyGroupBox_human6 = ui.bellyGroupBox.human6,
	bellyGroupBox_human7 = ui.bellyGroupBox.human7,
	bellyGroupBox_human8 = ui.bellyGroupBox.human8,
	bellyGroupBox_human9 = ui.bellyGroupBox.human9,
	bellyGroupBox_human10 = ui.bellyGroupBox.human10,
	bellyGroupBox_guassDegree = ui.bellyGroupBox.guassDegree,

	backGroupBox = ui.backGroupBox,
	backGroupBox_order = ui.backGroupBox.order,
	backGroupBox_human1 = ui.backGroupBox.human1,
	backGroupBox_human2 = ui.backGroupBox.human2,
	backGroupBox_human3 = ui.backGroupBox.human3,
	backGroupBox_human4 = ui.backGroupBox.human4,
	backGroupBox_human5 = ui.backGroupBox.human5,
	backGroupBox_human6 = ui.backGroupBox.human6,
	backGroupBox_human7 = ui.backGroupBox.human7,
	backGroupBox_human8 = ui.backGroupBox.human8,
	backGroupBox_human9 = ui.backGroupBox.human9,
	backGroupBox_human10 = ui.backGroupBox.human10,
	backGroupBox_guassDegree = ui.backGroupBox.guassDegree,
}

return {ui = ui, paramTable = paramTable}