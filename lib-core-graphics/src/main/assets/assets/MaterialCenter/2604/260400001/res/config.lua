local config = {}

-------------------- 可调整参数 --------------------

-- segment
config.segmentType = 2

-- shaders
config.vs = "shaders/Shader_Vertex.vs"
config.fs = "shaders/Shader_Mapping.fs"

-- default length
config.size = 13.0

-- default color
config.redColor = 1.0
config.greenColor = 1.0
config.blueColor = 1.0

return config
