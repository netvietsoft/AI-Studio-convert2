-- author:mtxx_liyl 20190909

function LOGD( info )
	if info ~= nil then
		print("mtxx base: " .. info)
	end
end

---------------------------filter gl---------------------------------
MTMixFilter = { _mesh = nil, _material = nil, _model = nil }

function MTMixFilter:new()
	local o = {}
	setmetatable(o, self)
	self.__index = self
	return o
end

-- 一个纹理坐标
function MTMixFilter:initialize(vs, fs, define)
    --local matrix = Matrix.new()
    --Matrix.createScale(1, -1, 1, matrix)

    self._mesh = Mesh.createMesh(VertexFormat.new({ VertexFormat.Element.new(VertexFormat.POSITION, 2),
                                                    VertexFormat.Element.new(VertexFormat.TEXCOORD0, 2)}, 2), 4)
    self._mesh:setPrimitiveType(Mesh.TRIANGLE_STRIP)
    self._model = Model.create(self._mesh)
    self._material = self._model:setMaterial(vs, fs, define)
    --self._material:getParameter("u_projectionMatrix"):setMatrix(matrix)
    --matrix = nil
end

-- 两个纹理坐标
function MTMixFilter:initialize2(vs, fs, define)
	local matrix = Matrix.new()
	--Matrix.createScale(1, -1, 1, matrix)

	self._mesh = Mesh.createMesh(VertexFormat.new({ VertexFormat.Element.new(VertexFormat.POSITION, 2),
													VertexFormat.Element.new(VertexFormat.TEXCOORD0, 2),
													VertexFormat.Element.new(VertexFormat.TEXCOORD1, 2)}, 3), 4)
	self._mesh:setPrimitiveType(Mesh.TRIANGLE_STRIP)
	self._model = Model.create(self._mesh)
	self._material = self._model:setMaterial(vs, fs, define)
	self._material:getParameter("u_projectionMatrix"):setMatrix(matrix)
	matrix = nil
end

-- 三个纹理坐标
function MTMixFilter:initialize3(vs, fs, define)
	local matrix = Matrix.new()
	--Matrix.createScale(1, -1, 1, matrix)

	self._mesh = Mesh.createMesh(VertexFormat.new({ VertexFormat.Element.new(VertexFormat.POSITION, 2),
													VertexFormat.Element.new(VertexFormat.TEXCOORD0, 2),
													VertexFormat.Element.new(VertexFormat.TEXCOORD1, 2),
													VertexFormat.Element.new(VertexFormat.TEXCOORD2, 2)}, 4), 4)
	self._mesh:setPrimitiveType(Mesh.TRIANGLE_STRIP)
	self._model = Model.create(self._mesh)
	self._material = self._model:setMaterial(vs, fs, define)
	self._material:getParameter("u_projectionMatrix"):setMatrix(matrix)
	matrix = nil
end

-- 开启叠加模式
function MTMixFilter:enableBlend()
	self._material:getStateBlock():setBlend(true)
	self._material:getStateBlock():setBlendSrc(RenderState.BLEND_SRC_ALPHA)
	self._material:getStateBlock():setBlendDst(RenderState.BLEND_ONE_MINUS_SRC_ALPHA)
end

function MTMixFilter:setSampler(uniformName, sampler)
	self._material:getParameter(uniformName):setSampler(sampler)
end

function MTMixFilter:setFloatParam(uniformName, param)
	self._material:getParameter(uniformName):setFloat(param)
end

function MTMixFilter:setVec3Param(uniformName, param)
	self._material:getParameter(uniformName):setVector3(param)
end

function MTMixFilter:setVertexData(data)
	self._mesh:setVertexData(data)
end

function MTMixFilter:setVertexDataWithMaterial(positive)
	local left = 0.0
    local right = 1.0
    local top = 0.0
    local bottom = 1.0
	local VertexData = {}
	if positive == nil or positive ~= 1 then
		VertexData = {
			-1, 1, left, top, left, top,
			1, 1, right, top, right, top,
			-1, -1, left, bottom, left, bottom,
			1, -1, right, bottom, right, bottom
		}
	else
		VertexData = {
			-1, 1, left, top, left, bottom,
			1, 1, right, top, right, bottom,
			-1, -1, left, bottom, left, top,
			1, -1, right, bottom, right, top
		}
	end
	self._mesh:setVertexData(VertexData)
	VertexData = nil
end

function MTMixFilter:setVertexDataWithSource(positive)
	local left = 0.0
    local right = 1.0
    local top = 0.0
    local bottom = 1.0
	local VertexData = {}
	if positive == nil or positive ~= 1 then
		VertexData = {
			-1, 1, left, top,
			1, 1, right, top,
			-1, -1, left, bottom,
			1, -1, right, bottom
		}
	else
		VertexData = {
			-1, 1, left, bottom,
			1, 1, right, bottom,
			-1, -1, left, top,
			1, -1, right, top
		}
	end
	self._mesh:setVertexData(VertexData)
	VertexData = nil
end

function MTMixFilter:setVertexDataWithDestination(positive, vertexInput)
	local left = 0.0
    local right = 1.0
    local top = 0.0
    local bottom = 1.0
    local VertexData = {}

	if positive == nil or positive ~= 1 then
		VertexData = {
			vertexInput[1], vertexInput[2], left, top,
			vertexInput[3], vertexInput[4], right, top,
			vertexInput[5], vertexInput[6], left, bottom,
			vertexInput[7], vertexInput[8], right, bottom
		}
	else
		VertexData = {
			vertexInput[1], vertexInput[2], left, bottom,
			vertexInput[3], vertexInput[4], right, bottom,
			vertexInput[5], vertexInput[6], left, top,
			vertexInput[7], vertexInput[8], right, top
		}
	end
	self._mesh:setVertexData(VertexData)

	VertexData = nil
end

function MTMixFilter:draw()
	self._model:draw()
end

function MTMixFilter:release()
	self._mesh = nil
	self._model = nil
	self._material = nil
end

----------------------------主流程----------------------------------

function initialize(resourcePath, globalState)
	LOGD(resourcePath)

	_globalState = globalState
	_resourcePath = resourcePath
	local _config = (load(FileSystem.readAll(resourcePath.."config.lua")))()

	-- stroke filter
	_StrokeFilter = MTMixFilter:new()
	_StrokeFilter:initialize(_resourcePath.._config.vs, _resourcePath.._config.fs)
	_StrokeFilter:enableBlend()
	_StrokeFilter:setVertexDataWithSource(1)

	--bg material
	_penSampler = Texture.Sampler.create(_resourcePath.._config.penPng)

	-- stroke default param
	_whScale = 1.0
	_size = _config.size
	local redColor = _config.redColor
	local greenColor = _config.greenColor
	local blueColor = _config.blueColor
	_color3 = Vector3.new(redColor, greenColor, blueColor)
	
	_config = nil
end

function resize(width, height)
	if _width == width and _height == height then
		return 
	end
	_width = width
	_height = height
	_whScale = 1.0 * _width / _height
end

function update(elapsedTime)
end

function render(doublebuffer)
	if _StrokeFilter == nil then
		LOGD('strokeFilter is nil')
		return
	end

	-- 获取边缘点数量
    _count = _globalState:getSegmentMaskDilateEdgePointCount()
    if _count == nil or _count <= 0 then
    	LOGD('stroke error: edge point count error')
		return
    end

    -- 设置颜色
    local color = _globalState:getColor()
    if color ~= nil then
    	_color3:set(color:x(), color:y(), color:z())
    	color = nil
    end

    -- 设置程度
    _size = _globalState:getAlpha()

    -- 设置基础宽高UV大小
    -- local uvW = _size / 20 / 50
    -- local uvH = _size / 20 / 50
    -- if _whScale >= 1.0 then 
    -- 	uvH = uvH * _whScale -- 宽比高大，就放大 uvH（根据宽高比）
    -- else
    -- 	uvW = uvW / _whScale -- 高比宽大，就放大宽 uvW
    -- end

    local uvH
    local uvW
    if _size < 1 then
		uvH = 0.008
	    uvW = uvH
    else
	    _whScale = (0.025 - 0.008) / (20 - 1)
		uvH = _whScale * (_size - 1) + 0.008
	    uvW = uvH
	end

	if _size == 0 then
		uvH = 0.0
	    uvW = 0.0
	end
	
    -- 计算疏密度
	local doDraw = true
	-- 虚线的取值范围
    local drawLength = uvW * uvW * 2.6 
    local noDrawLength = uvW * uvW * 1.6

	-- sync A 2 B
    --doublebuffer:SyncAToB()

	-- 描边效果
	doublebuffer:BindFBOB()
	_StrokeFilter:setSampler("u_mask", _penSampler)
	_StrokeFilter:setVec3Param("color", _color3)
	local lastPoint = _globalState:getSegmentMaskDilateEdgePoint(0)
	for i = 1, _count do
		local point = _globalState:getSegmentMaskDilateEdgePoint(i)
		if point ~= nil then
			-- 计算“当前点”和“上一个点”的距离
			local distance = (point:x() - lastPoint:x()) * (point:x() - lastPoint:x()) + (point:y() - lastPoint:y()) * (point:y() - lastPoint:y())
			if doDraw then
				-- 在虚线范围内
				if distance <= drawLength then
					-- -- 将坐标系原点从左上角移到图像中心 [0, 1] -> [-1, 1]
					local pointX = (point:x() - 0.5) * 2
					local pointY = (point:y() - 0.5) * 2
					if pointX > -1 or pointY > -1 then
						local vertex = {
						pointX - uvW, pointY + uvH, -- LT
						pointX + uvW, pointY + uvH, -- RT
						pointX - uvW, pointY - uvH, -- LB
						pointX + uvW, pointY - uvH, -- RB
						}
						_StrokeFilter:setVertexDataWithDestination(1, vertex)
						_StrokeFilter:draw() -- 画一个圆
						vertex = nil
					end
					pointX = nil
					pointY = nil
				else
					doDraw = false	-- 结束绘制
					lastPoint = point
				end
			else
				-- 进入虚线范围
				if distance > noDrawLength then
					doDraw = true -- 开始绘制
					lastPoint = point -- 更新“上一个点”
				end
			end
			distance = nil
		end
		point = nil
	end
	doublebuffer:SwapFBO()

	lastPoint = nil
	uvW = nil
	uvH = nil
end

function finalize()
	_StrokeFilter:release()
	_StrokeFilter = nil
	_color3 = nil
	_penSampler = nil
	
	_size = nil
	_width = nil
	_height = nil
	_whScale = nil

	_globalState = nil
	_resourcePath = nil

	--gl filter
	collectgarbage("collect")
end
