local config = {}

config.segmentType = 22

config.bodyParams = {}

config.bodyParams["autoCutout"] = {
    gaussianKernel = 1.0, 
    startEdge = 0.5, 
    endEdge = 0.8
}

config.bodyParams["manualCutout"] = {
    gaussianKernel = 1.0, 
    startEdge = 0.5, 
    endEdge = 0.8
}

config.bodyParams["instanceCutout"] = {
    gaussianKernel = 1.7,
    startEdge = 0.45,
    endEdge = 0.7
}

return config