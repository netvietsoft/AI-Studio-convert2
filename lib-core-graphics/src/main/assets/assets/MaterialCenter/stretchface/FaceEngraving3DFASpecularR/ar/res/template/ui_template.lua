ui = {
    order = { "info", "cameraSettings", "lightSettings", "modelSettings", "showDebugView", "pbrSettings", "blendSettings", "printInfo" },
    info = {
        ui_type = "groupbox", ui_name = "info", ui_title = true, ui_fold = false,
        order = {}
    },
    cameraSettings = {
        ui_type = "groupbox", ui_name = "camera", ui_title = true, ui_fold = false, visible = false,
        order = { "x", "y", "z", "yaw", "pitch", "roll" },
        x = { ui_type = "slider", ui_name = "x", value = 0.0, min = -250, max = 250, precision = 2, step = 0.1 },
        y = { ui_type = "slider", ui_name = "y", value = 0.0, min = -250, max = 250, precision = 2, step = 0.1 },
        z = { ui_type = "slider", ui_name = "z", value = -49, min = -250, max = 250, precision = 2, step = 0.1 },
        yaw = { ui_type = "slider", ui_name = "yaw", value = 0.0, min = -180, max = 180, precision = 2, step = 0.1 },
        pitch = { ui_type = "slider", ui_name = "pitch", value = 0.0, min = -180, max = 180, precision = 2, step = 0.1 },
        roll = { ui_type = "slider", ui_name = "roll", value = 0.0, min = -180, max = 180, precision = 2, step = 0.1 },
    },
    lightSettings = {
        ui_type = "groupbox", ui_name = "light", ui_title = true, ui_fold = false,
        order = { "x", "y", "z" },
        x = { ui_type = "slider", ui_name = "x", value = 0.0, min = -250, max = 250, precision = 2, step = 0.1 },
        y = { ui_type = "slider", ui_name = "y", value = 0.0, min = -250, max = 250, precision = 2, step = 0.1 },
        z = { ui_type = "slider", ui_name = "z", value = 0.0, min = -250, max = 250, precision = 2, step = 0.1 }
    },
    modelSettings = {
        ui_type = "groupbox", ui_name = "model", ui_title = true, ui_fold = false, visible = false,
        order = { "x", "y", "z", "sx", "sy", "sz" },
        x = { ui_type = "slider", ui_name = "x", value = 0.0, min = -2, max = 2, precision = 2, step = 0.1 },
        y = { ui_type = "slider", ui_name = "y", value = 0.0, min = -2, max = 2, precision = 2, step = 0.1 },
        z = { ui_type = "slider", ui_name = "z", value = -52, min = -250, max = 250, precision = 2, step = 0.1 },
        sx = { ui_type = "slider", ui_name = "sx", value = 0.3, min = -250, max = 250, precision = 2, step = 0.1 },
        sy = { ui_type = "slider", ui_name = "sy", value = 0.3, min = -250, max = 250, precision = 2, step = 0.1 },
        sz = { ui_type = "slider", ui_name = "sz", value = 0.3, min = -250, max = 250, precision = 2, step = 0.1 }
    },
    pbrSettings = {
        ui_type = "groupbox", ui_name = "pbr", ui_title = true, ui_fold = false,
        order = { "u_roughness", "u_metallic", "u_normalDetail", "u_diffuseCol" },
        u_roughness = { ui_type = "slider", ui_name = "roughness", value = 0.50, min = 0.0, max = 1.0, precision = 2, step = 0.1 },
        u_metallic = { ui_type = "slider", ui_name = "metallic", value = 0.0, min = 0.0, max = 1.0, precision = 2, step = 0.1 },
        u_normalDetail = { ui_type = "slider", ui_name = "normalDetail", value = 1.0, min = 0.0, max = 1.0, precision = 2, step = 0.1 },
        u_diffuseCol = { ui_type = "color", ui_format = "r&g&b", ui_name = "diffuse", r = 255, g = 255, b = 255 },
    },
    blendSettings = {
        ui_type = "groupbox", ui_name = "blend", ui_title = true, ui_fold = false,
        order = { "u_strong" },
        u_strong = { ui_type = "slider", ui_name = "strong", value = 1.0, min = 0.0, max = 2.0, precision = 1, step = 0.1 },
    },
    showDebugView = {
        ui_type = "switch", ui_name = "DEBUG", value = false,
    },
    printInfo = {
        ui_type = "switch", ui_name = "print", value = false, visible = false
    }
}

return ui