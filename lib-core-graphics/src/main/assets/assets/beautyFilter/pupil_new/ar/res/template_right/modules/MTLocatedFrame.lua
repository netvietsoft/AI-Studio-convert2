
----------------------------视频信息----------------------------------
MTLocatedFrame = {}
MTLocatedFrame.__index = MTLocatedFrame
-- 创建资源对象
function MTLocatedFrame.new()
    local o = {}
    setmetatable(o, MTLocatedFrame)
    return o
end
-- 初始化
-- @param enableBlend 是否开启混合(SRC_ALPHA,ONE_MINUS_SRC_ALPHA)
function MTLocatedFrame:initialize(enableBlend)
    self.material = Material.create("res/shaders/textured.vert", "res/shaders/textured.frag")
    self.mesh = Mesh.createQuadFullscreen()
	self.model = Model.create(self.mesh)
    self.model:setMaterial(self.material)
    self.transform = Matrix.new()
    if enableBlend ~= nil then
        self.material:getStateBlock():setBlend(true)
        self.material:getStateBlock():setBlendSrc(770)
        self.material:getStateBlock():setBlendDst(771)
    end

end


-- 计算矩形的外居中矩形
-- @param src 原始矩形
-- @param dst 目标矩形
-- @return 原始矩形外居中到目标矩形后的矩形
function MTLocatedFrame:calcOutsideRect(src,dst)
	local scaleWidth = dst[3]/src[3]
	local res_rect = {0,0,src[3]*scaleWidth,src[4]*scaleWidth}
	if(res_rect[4] < dst[4]) then
		local heightScale = dst[4]/res_rect[4]
		res_rect[3] = res_rect[3]*heightScale
		res_rect[4] = res_rect[4]*heightScale
	end
	res_rect[1] = (dst[3] - res_rect[3] )/2 + dst[1]
	res_rect[2] = (dst[4] - res_rect[4] )/2 + dst[2]
	return res_rect
end
-- 渲染纹理
-- @param sampler 纹理
-- @param orientation 设备方向
-- @param viewWidth 渲染目标宽
-- @param  viewHeight 渲染目标高
-- @param  flipY 是否要上下镜像
function MTLocatedFrame:render(sampler,orientation,viewWidth,viewHeight,flipY)
    local srcImageWidth = viewWidth
	local srcImageHeight = viewHeight
	--先把宽高调回原来的宽高
	if orientation == 1 then--home键在纹理上方
		srcImageWidth = viewWidth
		srcImageHeight = viewHeight
	elseif orientation == 2 then--home键在纹理下方
		srcImageWidth = viewWidth
		srcImageHeight = viewHeight
	elseif orientation == 3 then--home键在纹理左方
		srcImageWidth = viewHeight
		srcImageHeight = viewWidth
	elseif orientation == 4 then--home键在纹理右方
		srcImageWidth = viewHeight
		srcImageHeight = viewWidth
    end

    local txWidth = sampler:getTexture():getWidth()
    local txHeight = sampler:getTexture():getHeight()

    local rect_dst = {0,0,srcImageWidth,srcImageHeight}
	local rect_src = {0,0,txWidth,txHeight}
	local scale_dst_rect = self:calcOutsideRect(rect_src,rect_dst)
	local scalse_dst_mid = {scale_dst_rect[1] + scale_dst_rect[3]*0.5,scale_dst_rect[2] + scale_dst_rect[4]*0.5}

    local projMat = Matrix.new()
    Matrix.createOrthographicOffCenter(0,viewWidth,0,viewHeight,1.0,-1.0,projMat)
    self.transform:setIdentity()

	if orientation == 1 then--home键在纹理上方
		self.transform:translate(scalse_dst_mid[1],scalse_dst_mid[2],0.0)
		self.transform:rotateZ(180.0*0.0174533)
		self.transform:translate(-scalse_dst_mid[1],-scalse_dst_mid[2],0.0)
	elseif orientation == 2 then--home键在纹理下方
		
	elseif orientation == 3 then--home键在纹理左方
		self.transform:translate(viewWidth,0.0,0.0)
		self.transform:rotateZ(90.0*0.0174533)
	elseif orientation == 4 then--home键在纹理右方
		self.transform:translate(0.0,viewHeight,0.0)
		self.transform:rotateZ(-90.0*0.0174533)
    end
    
	projMat:multiply(self.transform)
	
	local mesh_vertex_texcoord_normal = {scale_dst_rect[1],scale_dst_rect[2],0,1,
	scale_dst_rect[1],scale_dst_rect[2]+scale_dst_rect[4],0,0,
	scale_dst_rect[1]+scale_dst_rect[3],scale_dst_rect[2],1,1,
    scale_dst_rect[1]+scale_dst_rect[3],scale_dst_rect[2]+scale_dst_rect[4],1,0}
    
    if flipY == true then
        mesh_vertex_texcoord_normal[4] = 1.0 - mesh_vertex_texcoord_normal[4]
        mesh_vertex_texcoord_normal[8] = 1.0 - mesh_vertex_texcoord_normal[8]
        mesh_vertex_texcoord_normal[12] = 1.0 - mesh_vertex_texcoord_normal[12]
        mesh_vertex_texcoord_normal[16] = 1.0 - mesh_vertex_texcoord_normal[16]
    end
	
	self.mesh:setVertexData(mesh_vertex_texcoord_normal)
	self.material:getParameter("u_diffuseTexture"):setSampler(sampler)
	self.material:getParameter("u_worldViewProjectionMatrix"):setMatrix(projMat)
	self.model:setMaterial(self.material)
    self.model:draw()
end
-- 获取渲染变换,可以获取变换矩阵然后去变换图片上对应的点
-- @return 变换矩阵
function MTLocatedFrame:getTransform()
    return self.transform
end
-- 释放资源
function MTLocatedFrame:release()
	self.material =  nil
	self.transform = nil
	self.mesh = nil
	self.model = nil
end

return MTLocatedFrame