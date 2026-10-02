local config = {}

-------------------- 可调整参数 --------------------

-- segment
config.segmentType = 2

-- pen
config.penPng = "png/pen.png"

-- shaders
config.vs = "shaders/Stroke_Line.vs"
config.fs = "shaders/Stroke_Line.fs"

-- default length
config.size = 13.0

-- default color
config.redColor = 0.89
config.greenColor = 0.47
config.blueColor = 0.39

-- blend
config.isBlend = 1

return config
