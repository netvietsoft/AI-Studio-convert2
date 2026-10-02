
MTFrameBuffer = { _id = nil, _width = 0, _height = 0 }
MTFrameBuffer.__index = MTFrameBuffer
-- 创建FrameBuffer对象
function MTFrameBuffer.new()
	local o = {}
	setmetatable(o, MTFrameBuffer)
	return o
end
-- 更新Framebuffer尺寸
-- @param name 用作Gameplay 资源池的标识符,如果已经创建过会直接返回
-- @param width 新资源的宽
-- @param height 新资源的高
function MTFrameBuffer:resize(name, width, height)
	if self._width ~= width or self._height ~= height then
		--LOGD("MTFrameBuffer:resize " .. self._width .. " " .. self._height .. " " .. width .. " " .. height)
		self._id = FrameBuffer.create(name, width, height, Texture.RGBA)
		self._id:bind()
		local game = Game.getInstance()
		game:clear(Game.CLEAR_COLOR, 0, 0, 0, 1, 1.0, 0)
		self._width = width
		self._height = height
	end
end
-- 获取Framebuffer 绑定的Texture
-- @return gameplay::Texture  其采样方式默认为 _wrapS(Texture::CLAMP), _wrapT(Texture::CLAMP), _wrapR(Texture::CLAMP)
function MTFrameBuffer:getSampler()
	local sampler = Texture.Sampler.create(self._id:getRenderTarget():getTexture())
	return sampler
end
-- 绑定Framebuffer到上下文
function MTFrameBuffer:bind()
	self._id:bind()
end
-- 资源释放
function MTFrameBuffer:release()
	self._id = nil
end

return MTFrameBuffer