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
config.size = 10.0

-- default color
config.redColor = 0.0
config.greenColor = 0.0
config.blueColor = 0.0

-- blend
config.isBlend = 1

return config