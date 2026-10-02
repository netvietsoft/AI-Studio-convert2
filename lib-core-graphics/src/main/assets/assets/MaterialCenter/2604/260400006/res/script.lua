-- author:mtxx_liyl 20190815

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
	_StrokeFilter:setVertexDataWithSource(1)

	-- stroke default param
	_size = _config.size
	_segmentType = _config.segmentType
	
	_config = nil
end

function resize(width, height)
	if _width == width and _height == height then
		return 
	end
	_width = width
	_height = height
end

function update(elapsedTime)
end

function render(doublebuffer)
	if _StrokeFilter == nil then
		LOGD('strokeFilter is nil')
		return
	end

	if _globalState:getSegmentMask(_segmentType) == nil then
		LOGD('stroke error: segment nil, type '.._segmentType)
		return
	end

    -- 设置程度
    _size = _globalState:getAlpha()

	-- 描边效果
	doublebuffer:BindFBOB()
	_StrokeFilter:setSampler("u_texture", doublebuffer:getGPSamplerA())
	_StrokeFilter:setSampler("u_mask", _globalState:getSegmentMask(_segmentType))
	_StrokeFilter:setFloatParam("size", _size)
	_StrokeFilter:setFloatParam("textureWidth", _width)
	_StrokeFilter:setFloatParam("textureHeight", _height)
	_StrokeFilter:draw()
	doublebuffer:SwapFBO()
end

function finalize()
	_StrokeFilter:release()
	_StrokeFilter = nil
	_color3 = nil
	
	_segmentType = nil
	_size = nil
	_width = nil
	_height = nil

	--gl filter
	collectgarbage("collect")
end
