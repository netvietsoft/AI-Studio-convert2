ui = {
    order = { "size", "faceid" },
    size = { precision = 2.00, max = 1.0, min = 0.0, value = 0.0, ui_name = "大小:", step = 0.01, ui_type = "slider" },
    faceid = { precision = 0.00, max = 14.0, min = 0.0, value = 0.0, ui_name = "人脸ID:", step = 1.0, ui_type = "slider" }
}
 
paramTable = {}
paramTable["default"] = {
    lefteyesize = ui.size,
    leftfaceid = ui.faceid,
}

return {ui = ui, paramTable = paramTable}