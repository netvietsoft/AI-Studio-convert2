
----------------------------基础3D渲染----------------------------------
-- 使用方式
-- 初始化:
-- _luaWorld.MT3DBaseRender = import("modules/MT3DBaseRender")
-- _luaWorld.MT3DBaseRender.setEnv(_ENV)
-- _luaWorld.baseHead = _luaWorld.MT3DBaseRender.new("BASE3D")
-- _luaWorld.baseHead:loadModel(_luaWorld.resourcePath.."model/head.obj")
-- _luaWorld.baseHead:setMaterial(_luaWorld.resourcePath.."all.material#head")
-- 更新和渲染:
-- _luaWorld.baseHead:updateFaces(faces,_width,_height)
-- _luaWorld.baseHead:draw()

MT3DBaseRender = { }
MT3DBaseRender.__index = MT3DBaseRender

MT3DBASE_MAX_SUPPORT_FACE = 5
_visitMT3DBaseRenderInstance = nil
MT3DBASE_MODE_BASE3D = "BASE3D"
MT3DBASE_MODE_DL3D = "DL3D"
-- 内部函数,用于遍历模型节点
function visitMT3DBaseRenderNode(node)
    local nodeId = node:getId()
	if nodeId == "RootNode" then
		return true
    end
	
	if node:getAnimation() ~= nil then
        local animation = node:getAnimation()
        _visitMT3DBaseRenderInstance._animations[nodeId] = animation
	end
    if node:getDrawable() ~= nil then
        local model = node:getDrawable():to("Model")
        _visitMT3DBaseRenderInstance._models[nodeId] = model
        _visitMT3DBaseRenderInstance._nodes[nodeId] = node
		--[[if model ~= nil and model:getSkin() ~= nil then
		end]]
    end
    
	return true
end

function visitMT3DBaseRenderNodeToDraw(node)
    if node:getDrawable() ~= nil then
        local model = node:getDrawable():to("Model")
        model:draw()
    end
    return true
end

-- ！！必须调用！！,用于把visit的函数放到主环境中
-- @param env 主lua脚本的_ENV
function MT3DBaseRender.setEnv(env)
    env["visitMT3DBaseRenderNode"] = visitMT3DBaseRenderNode
    env["visitMT3DBaseRenderNodeToDraw"] = visitMT3DBaseRenderNodeToDraw
end

-- 创建资源对象
-- @param mode "BASE3D"表示姿态预估下的3D,"DL3D"表示使用DL3D
-- @return 返回对象
function MT3DBaseRender.new(mode)
    local o = {}
    setmetatable(o, MT3DBaseRender)
    o._scene = nil
    o._mode = mode
    o._animations = {}
    o._models = {}
    o._nodes = {}
    o._faces = {}
    o._frsdl3d = {}
    o._width = 0
    o._height = 0
    o._file = ""
    o._clips = {}
    return o
end

-- 加载模型文件
-- @param path 模型路径 (.obj/.fbx)
-- @param flag 默认值 74 (aiProcess_JoinIdenticalVertices | aiProcess_Triangulate | aiProcess_GenSmoothNormals)
--              带切线 75 (aiProcess_JoinIdenticalVertices | aiProcess_Triangulate | aiProcess_GenSmoothNormals|aiProcess_CalcTangentSpace)
-- @param ignoreNode 需要忽略解析的节点
function MT3DBaseRender:loadModel(path,flag,ignoreNode)
    if flag == nil then
        flag = 74
    end
    if ignoreNode == nil then
        ignoreNode = ""
    end
    self._file = path:match("^.+/(.+)$")

    local decoder = AssimpSceneDecoder.new()
    decoder:readFile(path,flag)
    self._scene = decoder:loadScene(ignoreNode)
    if self._mode == MT3DBASE_MODE_BASE3D then
        local camera = Camera.createPerspective(45,1,1,10000)
        local cameraNode = self._scene:addNode("camera")
        cameraNode:setCamera(camera)
        cameraNode:setScaleZ(-1)
        self._scene:setActiveCamera(camera)
    elseif self._mode == MT3DBASE_MODE_DL3D then
        for i=1 ,MT3DBASE_MAX_SUPPORT_FACE do
            self._frsdl3d[i] =  GPFaceReconstructor.CreateWithType(6,true,true)
        end
        local camera = Camera.createPerspective(45,1,1,10000)
        local cameraNode = self._scene:addNode("camera")
        cameraNode:setCamera(camera)
        self._scene:setActiveCamera(camera)
    end
    
    _visitMT3DBaseRenderInstance = self
	self._scene:visit("visitMT3DBaseRenderNode")
end
-- 打印节点信息
function MT3DBaseRender:printSceneInfo()
    print(string.format("===%s:BASE3DINFO===",self._file))
    print("Animations: ")
    for k, v in pairs(self._animations) do
        print(string.format("%s: Duration: %d",k,v:getDuration()))
    end
    print("Drawables: ")
    for k, v in pairs(self._models) do
        print("key: ".. k)
    end
end
-- 设置模型材质
-- @param material 材质文件 or 材质对象
-- @param name 模型名称,为nil时设置所有模型为同一个材质
function MT3DBaseRender:setMaterial(material,name)
    if name == nil then
        for k, v in pairs(self._models) do 
            v:setMaterial(material)
        end
    else
        if self._models[name] == nil then
            print("error: model "..name.." not found")
        else
            self._models[name]:setMaterial(material)
        end
    end
end
-- 创建动画片段
-- @param id 动画id 注意需要唯一
-- @param startT 开始时间,单位ms
-- @param endT 结束时间,单位ms
function MT3DBaseRender:createAnimationClip(id,startT,endT)
    for k, v in pairs(self._animations) do
        local clip = v:createClip(id,startT,endT)
        self._clips[#self._clips +1 ] = clip
    end
end
-- 设置动画循环次数
-- @param id 动画id 注意需要唯一,nil表示默认动画
-- @param repeatCount 循环次数,可浮点,0 表示无限循环
function MT3DBaseRender:setRepeatCount(id,repeatCount)
    for k, v in pairs(self._animations) do
        v:getClip(id):setRepeatCount(repeatCount)
    end
end

-- 播放动画片段
-- @param id 片段id,为null时播放默认动画
function MT3DBaseRender:play(id)
    for k, v in pairs(self._animations) do
        v:play(id)
    end
end
-- 停止播放动画片段
-- @param id 片段id,为null时播放默认动画
function MT3DBaseRender:stop(id)
    for k, v in pairs(self._animations) do
        v:stop(id)
    end
end
-- 暂停动画片段
-- @param id 片段id,为null时播放默认动画
function MT3DBaseRender:pause(id)
    for k, v in pairs(self._animations) do
        v:pause(id)
    end
end

-- 更新人脸
-- @param faces GPFace人脸!!数组!!,需要把所有人脸一起传入
-- @param width 当前屏幕宽度
-- @param height 当前屏幕高度
function MT3DBaseRender:updateFaces(faces,width,height)
    self._faces = {}
    local minFaceCnt = math.min(#faces,MT3DBASE_MAX_SUPPORT_FACE)
    for i = 1,minFaceCnt do
        self._faces[i] = faces[i]
    end
    self._width = width
    self._height = height
end
-- 渲染模型
-- @param name 模型名称,为nil时渲染所有节点
function MT3DBaseRender:draw(name)
    if name ~=nil and self._models[name] == nil then
        print("error: model "..name.." not found")
        return
    end
    if self._mode == MT3DBASE_MODE_BASE3D then
        for i = 1,#self._faces do
            local face = self._faces[i]
            local headPos = face:getPosEstimator()
            local t = Vector3.new()
            local r = Quaternion.new()
            local s = Vector3.new()
            headPos:decompose(s,r,t)

            local max = 0
            if self._width > self._height then
                max = self._width
            else
                max = self._height
            end

            local far = t:z() + 1500
            local near = t:z() - 1500
            if near < 1 then
                near = 1
            end

            local m00 = 2 * max / self._width
            local m11 = 2 * max / self._height
            local m22 = - (far + near) / (far - near)
            local m32 = -2 * far * near / (far - near)

            local proj = Matrix.new(m00,0,0,0,0,m11,0,0,0,0,m22,m32,0,0,-1,0)
            self._scene:getActiveCamera():setProjectionMatrix(proj)

            if name == nil then
                for k, v in pairs(self._models) do 
                    self._nodes[k]:setTranslation(t)
                    self._nodes[k]:setRotation(r)
                    self._nodes[k]:setScale(s)
                end
                --遍历场景进行渲染
                self._scene:visit("visitMT3DBaseRenderNodeToDraw")
            else
                self._nodes[name]:setTranslation(t)
                self._nodes[name]:setRotation(r)
                self._nodes[name]:setScale(s)
                self._models[name]:draw()
            end
        end
    elseif self._mode == MT3DBASE_MODE_DL3D then
        for i = 1,#self._faces do
            local face = self._faces[i]
            self._frsdl3d[i]:updateData(face:getFaceId(), 1)

            local mvpMatrix = self._frsdl3d[i]:getOrthoMVP()
            local eulerAngle = self._frsdl3d[i]:getRotation()
            local translate = self._frsdl3d[i]:getTranslate()
            local quaternion = Quaternion.new()
            Quaternion.createFromEuler(math.rad(eulerAngle:y()),math.rad(eulerAngle:x()),math.rad(eulerAngle:z()),quaternion)
            
            local transform = Transform.new()
            transform:setTranslation(translate)
            transform:setRotation(quaternion)
            local transformMatrix = transform:getMatrix()
            transformMatrix:invert()
            local projMat = Matrix.new()
            Matrix.multiply(mvpMatrix,transformMatrix,projMat)
            self._scene:getActiveCamera():setProjectionMatrix(projMat)
            if name == nil then
                for k, v in pairs(self._models) do
                    self._nodes[k]:setTranslation(translate)
                    self._nodes[k]:setRotation(quaternion)
                    v:draw()
                end
            else
                self._nodes[name]:setTranslation(translate)
                self._nodes[name]:setRotation(quaternion)
                self._models[name]:draw()
            end
        end
    end
end

-- 释放资源
function MT3DBaseRender:release()
    self._scene = nil
    self._animations = {}
    self._models = {}
    self._nodes = {}
    self._faces = {}
    self._clips = {}
end

return MT3DBaseRender