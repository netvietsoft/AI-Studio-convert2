local config = {}

-------------------- 可调整参数 --------------------

-- segment
config.segmentType = 2

-- shaders
config.vs = "shaders/Shader_Vertex.vs"
config.fs = "shaders/Shader_Mapping.fs"

-- default length
config.size = 10.0

-- default color
config.redColor = 0.99
config.greenColor = 0.4
config.blueColor = 0.27

return config