
----------------------------视频信息----------------------------------
MTVideo = { _decoder = nil, _sampler = nil, _totalTime = 0.0, _currentTime = 0.0, _totalFrame = 0, _unitTime = 41.67,_width = 0,_height = 0}
MTVideo.__index = MTVideo
-- 创建资源对象
function MTVideo.new()
    local o = {}
    setmetatable(o, MTVideo)
    return o
end

--[[
    创建解码器
    @param path 文件路径
    @param videotype 视频类型
    ///< 正常的视频素材
    VIDEO_NORMAL = 0,
    ///< 上下分屏的视频素材 上半部分表示RGB 下半部分表示Alpha
    VIDEO_SPLIT_MASK = 1,
    ///< 拼接好的序列帧 全部加载
    VIDEO_FRAME_ANIMATION = 2,
    ///< 拆开的序列帧 全部加载
    VIDEO_FRAME_ANIMATION_THREADING = 3,
    ///< 拆开的序列帧 缓存池方式
    VIDEO_FRAME_ANIMATION_THREADING_CACHE = 4,
    ///< 使用虚拟内存缓存 拆开的序列帧
    VIDEO_FRAME_ANIMATION_SUPER_FILE = 5,
    ///< 使用虚拟内存缓存 拼接好的序列帧
    VIDEO_FRAME_ANIMATION_SUPER_FILE_2 = 6,
    ///< Dragon bones动画
    VIDEO_FRAME_ANIMATION_DRAGON_BONES = 7
    @param info VideoType对应的视频信息，见VideoType
    @param infoNum #info
    @param fps 视频帧率
    @param isShare 是否共享
    @param isLoop 是否循环解码
    @param isUseSelfFPS 是否使用内部FPS计时
    @return 图片解码器
]]
function MTVideo:initialize(videoType, path, info, fps)
    self._decoder = MVideoDecoder.new(path, videoType, info, #info, fps, false, true, false)
    local width = self._decoder:GetWidth()
    local height = self._decoder:GetHeight()
    local texture = Texture.create(Texture.RGBA8888, width, height, {}, false, Texture.TEXTURE_2D)
    self._sampler = Texture.Sampler.create(texture)
    texture = nil
	self._sampler:setWrapMode(Texture.CLAMP, Texture.CLAMP, Texture.CLAMP)
	self._width = width
	self._height = height
    self._totalTime = self._decoder:GetVideoTotalTime()
    self._totalFrame = fps * self._totalTime / 1000
    self._unitTime = 1000 / fps
end
-- 对动画资源进行偏移按ms
-- @param delta 单位ms
function MTVideo:offset(delta)
    self._currentTime = (self._currentTime + delta) % self._totalTime
    self._decoder:LoadToSampler(self._currentTime, self._sampler)
end
-- 对动画资源进行偏移按帧
--@param frameIndex 单位帧
function MTVideo:offset2(frameIndex)
    frameIndex = frameIndex % self._totalFrame
    self._decoder:LoadToSampler(frameIndex * self._unitTime, self._sampler)
    --LOGD("get "..frameIndex.." frame, "..frameIndex * self._unitTime.." ms")
end
-- 获取当前动画的sampler
-- @return gameplay::Texture::Sampler
function MTVideo:getSampler()
    return self._sampler
end
-- 释放资源
function MTVideo:release()
    self._decoder = nil
    self._sampler = nil
end

return MTVideo