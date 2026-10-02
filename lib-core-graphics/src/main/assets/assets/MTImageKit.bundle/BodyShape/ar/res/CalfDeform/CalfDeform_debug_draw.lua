-- CalfDeform debug drawing (loaded via importMainEnv from CalfDeform.lua)
-- Shares main module _ENV: ui, _left, _right, _luaWorld, _vertices, subtractVectors, etc.

local function magnitude(v)
	return math.sqrt(v.x * v.x + v.y * v.y)
end

local function setupDebugLineMaterial(batch, color)
	batch:getMaterial():getParameter("u_width"):setFloat(_luaWorld.width)
	batch:getMaterial():getParameter("u_height"):setFloat(_luaWorld.height)
	batch:getMaterial():getParameter("u_color"):setVector3(color)
end

local function drawMeshBatch(batch, flatCoords, primitiveCount)
	if not batch or not flatCoords or #flatCoords == 0 or primitiveCount <= 0 then
		return
	end
	batch:start()
	batch:add(flatCoords, primitiveCount)
	batch:finish()
	batch:draw()
end

local function drawBoxContourLines(part, color)
	if not part.boxPoints then
		return
	end
	local lines = {}
	addLines(part.boxPoints, lines, 1, 2)
	addLines(part.boxPoints, lines, 2, 3)
	addLines(part.boxPoints, lines, 3, 4)
	addLines(part.boxPoints, lines, 4, 5)
	addLines(part.boxPoints, lines, 5, 6)
	addLines(part.boxPoints, lines, 6, 1)
	DrawLines(lines, color)
end

local function drawPartDebugPoints(part, boxColor, jointColor)
	if part.boxPoints then
		DrawPoint(part.boxPoints, boxColor)
	end
	if part.jointPoints then
		DrawPoint(part.jointPoints, jointColor)
	end
end

local function drawPointDebugOverlay(boxPoints, jointPoints, boxColor, jointColor)
	if boxPoints and #boxPoints > 0 then
		DrawPoint(boxPoints, boxColor)
	end
	if jointPoints and #jointPoints > 0 then
		DrawPoint(jointPoints, jointColor)
		local lines = {}
		addLines(jointPoints, lines, 1, 2)
		DrawLines(lines, jointColor)
	end
end

local function drawRawAndCorrectedInputPoints()
	if ui.debug.showRawDetectedPoints and ui.debug.showRawDetectedPoints.value then
		drawPointDebugOverlay(_debugRawLeftBoxPoints, _debugRawLeftJointPoints, Vector3.new(1.0, 0.55, 0.15), Vector3.new(1.0, 0.9, 0.2))
		drawPointDebugOverlay(_debugRawRightBoxPoints, _debugRawRightJointPoints, Vector3.new(0.15, 0.75, 1.0), Vector3.new(0.45, 0.95, 1.0))
	end
	if ui.debug.showCorrectedPoints and ui.debug.showCorrectedPoints.value then
		drawPointDebugOverlay(_debugCorrectedLeftBoxPoints, _debugCorrectedLeftJointPoints, Vector3.new(1.0, 0.0, 0.25), Vector3.new(1.0, 0.35, 0.65))
		drawPointDebugOverlay(_debugCorrectedRightBoxPoints, _debugCorrectedRightJointPoints, Vector3.new(0.1, 0.95, 0.2), Vector3.new(0.0, 0.85, 0.55))
	end
end

local function drawDisabledLegMarkers()
	if _left.isAble == false and _left.boxPoints then
		DrawPoint(_left.boxPoints, Vector3.new(1.0, 0.0, 1.0))
	end
	if _right.isAble == false and _right.boxPoints then
		DrawPoint(_right.boxPoints, Vector3.new(0.0, 1.0, 1.0))
	end
end

local function drawCalfStartKeyPoints()
	local items = {
		{ part = _left, lineColor = Vector3.new(1.0, 0.45, 0.2) },
		{ part = _right, lineColor = Vector3.new(0.2, 0.85, 0.4) },
	}
	for _, item in ipairs(items) do
		local rgn = item.part and item.part.calfRgn
		if rgn and rgn.valid then
			if rgn.rawMid1 and rgn.shiftedMid1 then
				DrawLines({ rgn.rawMid1, rgn.shiftedMid1 }, item.lineColor)
				DrawPoint({ rgn.rawMid1 }, Vector3.new(1.0, 1.0, 0.0))      -- 原始 mid1：黄
				DrawPoint({ rgn.shiftedMid1 }, Vector3.new(0.0, 1.0, 1.0))   -- 下移后的 mid1：青
			end
			if rgn.a then
				DrawPoint({ rgn.a }, Vector3.new(1.0, 0.0, 1.0))             -- 延长后的 a：紫
			end
			if rgn.shiftedMid1 and rgn.a then
				DrawLines({ rgn.shiftedMid1, rgn.a }, Vector3.new(1.0, 1.0, 1.0))
			end
		end
	end
end

local function drawLegOwnershipPoints()
	if _lastLeftOwnershipPoints and #_lastLeftOwnershipPoints > 0 then
		DrawPoint(_lastLeftOwnershipPoints, Vector3.new(1.0, 0.2, 0.2))
	end
	if _lastRightOwnershipPoints and #_lastRightOwnershipPoints > 0 then
		DrawPoint(_lastRightOwnershipPoints, Vector3.new(0.2, 1.0, 0.2))
	end
	if _lastSharedOwnershipPoints and #_lastSharedOwnershipPoints > 0 then
		DrawPoint(_lastSharedOwnershipPoints, Vector3.new(1.0, 1.0, 0.2))
	end
	if _lastCompressedOwnershipPoints and #_lastCompressedOwnershipPoints > 0 then
		DrawPoint(_lastCompressedOwnershipPoints, Vector3.new(0.2, 0.55, 1.0))
	end
end

local function drawCalfSliceExposure()
	local field = _lastCalfExposureField
	if not field then
		return
	end
	for _, slices in ipairs({ field.left, field.right }) do
		if slices then
			for i = 1, #slices do
				local s = slices[i]
				if s.side1 and s.side2 then
					local color = Vector3.new(0.2, 0.95, 0.95)
					if s.contactStrength > 0.66 then
						color = Vector3.new(1.0, 0.35, 0.15)
					elseif s.contactStrength > 0.2 then
						color = Vector3.new(1.0, 0.9, 0.2)
					end
					DrawLines({ s.side1.point, s.side2.point }, color)
				end
				if s.contactPoint then
					DrawPoint({ s.contactPoint }, Vector3.new(1.0, 0.35, 0.1))
				end
				if s.exposedPoint then
					DrawPoint({ s.exposedPoint }, Vector3.new(0.15, 1.0, 0.45))
				end
			end
		end
	end
	if _lastExposureMaskDebugPointsL and #_lastExposureMaskDebugPointsL > 0 then
		DrawPoint(_lastExposureMaskDebugPointsL, Vector3.new(1.0, 0.45, 0.1))
	end
	if _lastExposureMaskDebugPointsR and #_lastExposureMaskDebugPointsR > 0 then
		DrawPoint(_lastExposureMaskDebugPointsR, Vector3.new(0.1, 0.85, 1.0))
	end
end

local function drawMeshDisplacement(fromPoints, toPoints, color)
	if not fromPoints or not toPoints or #fromPoints == 0 or #fromPoints ~= #toPoints then
		return
	end
	local lines = {}
	for i = 1, #fromPoints do
		local p0 = fromPoints[i]
		local p1 = toPoints[i]
		if p0 and p1 then
			lines[#lines + 1] = { x = p0.x, y = p0.y }
			lines[#lines + 1] = { x = p1.x, y = p1.y }
		end
	end
	DrawLines(lines, color)
end


function DrawPoint(tablePoints,vec3)
	if not tablePoints or #tablePoints == 0 then
		return
	end
	local mypoints = {}
	for i = 1, #tablePoints do
		local p = tablePoints[i]
		mypoints[#mypoints+1]=p.x
		mypoints[#mypoints+1]=p.y
	end
	setupDebugLineMaterial(_luaWorld.lineMeshBatch, vec3)
	drawMeshBatch(_luaWorld.lineMeshBatch, mypoints, #mypoints / 2)
end
function addLines(points,lines,id1,id2)
	local p1=points[id1]
	local p2=points[id2]
	lines[#lines+1]={x=p1.x,y=p1.y}
	lines[#lines+1]={x=p2.x,y=p2.y}
end
function DrawLines(tablePoints,vec3)
	if not tablePoints or #tablePoints < 2 then
		return
	end
	local mypoints = {}
	for i = 1, #tablePoints,2 do
		local p1 = tablePoints[i]
		local p2 = tablePoints[i+1]
		if not p1 or not p2 then
			goto continue
		end
		mypoints[#mypoints+1]=p1.x
		mypoints[#mypoints+1]=p1.y
		mypoints[#mypoints+1]=p2.x
		mypoints[#mypoints+1]=p2.y
		::continue::
	end
	if #mypoints == 0 then
		return
	end
	setupDebugLineMaterial(_luaWorld.lineItems, vec3)
	drawMeshBatch(_luaWorld.lineItems, mypoints, #mypoints / 2)
end


local function drawLinesSlightThicker(tablePoints, color, offsetPx)
	if not tablePoints or #tablePoints < 2 then
		return
	end
	DrawLines(tablePoints, color)
	local delta = offsetPx or 0.8
	local plus = {}
	local minus = {}
	for i = 1, #tablePoints, 2 do
		local p1 = tablePoints[i]
		local p2 = tablePoints[i + 1]
		if not p1 or not p2 then
			goto continue
		end
		local dir = subtractVectors(p2, p1)
		local len = magnitude(dir)
		local nx, ny = 0.0, 0.0
		if len > 1e-5 then
			nx = -dir.y / len
			ny = dir.x / len
		end
		plus[#plus + 1] = { x = p1.x + nx * delta, y = p1.y + ny * delta }
		plus[#plus + 1] = { x = p2.x + nx * delta, y = p2.y + ny * delta }
		minus[#minus + 1] = { x = p1.x - nx * delta, y = p1.y - ny * delta }
		minus[#minus + 1] = { x = p2.x - nx * delta, y = p2.y - ny * delta }
		::continue::
	end
	if #plus > 0 then
		DrawLines(plus, color)
	end
	if #minus > 0 then
		DrawLines(minus, color)
	end
end

local function drawCalfRegionViz()
	if not (ui and ui.debug and ui.debug.showCalfRegionBoxes and ui.debug.showCalfRegionBoxes.value) then
		return
	end
	local rL = _left and _left.calfRgn
	local rR = _right and _right.calfRgn
	if not rL or not rL.valid or not rR or not rR.valid then
		return
	end
	for _, item in ipairs({
		{ r = rL, boneColor = Vector3.new(0.0, 1.0, 0.0) },
		{ r = rR, boneColor = Vector3.new(1.0, 0.0, 0.0) },
	}) do
		local r = item.r
		if r.wN and r.wN > 0 and r.n then
			local ox, oy = r.n.x * r.wN, r.n.y * r.wN
			local ap = { x = r.a.x + ox, y = r.a.y + oy }
			local bp = { x = r.b.x + ox, y = r.b.y + oy }
			drawLinesSlightThicker({ r.b, bp, bp, ap, ap, r.a }, Vector3.new(0.0, 0.85, 0.2), 0.9)
		end
		if r.wP and r.wP > 0 and r.n then
			local invN = { x = -r.n.x, y = -r.n.y }
			local ox, oy = invN.x * r.wP, invN.y * r.wP
			local ap = { x = r.a.x + ox, y = r.a.y + oy }
			local bp = { x = r.b.x + ox, y = r.b.y + oy }
			drawLinesSlightThicker({ r.b, bp, bp, ap, ap, r.a }, Vector3.new(1.0, 0.15, 0.15), 0.9)
		end
		drawLinesSlightThicker({ r.a, r.b }, item.boneColor, 0.9)
	end
end

local function isDebugDrawEnabled()
	return ui and ui.debug and ui.debug.enableDebugDraw and ui.debug.enableDebugDraw.value
end

local function runRender(newPoints)
	drawCalfRegionViz()
	if not isDebugDrawEnabled() then
		return
	end
	if ui.debug.showSkeleton.value then
		for _, part in ipairs({ _right, _left }) do
			if part.boxPoints and part.jointPoints then
				local lines = {}
				addLines(part.jointPoints, lines, 1, 2)
				DrawLines(lines, Vector3.new(1.0, 1.0, 1.0))
			end
		end
	end
	if ui.debug.showContourLines.value then
		drawBoxContourLines(_right, Vector3.new(0.0, 1.0, 0.0))
		drawBoxContourLines(_left, Vector3.new(1.0, 0.0, 0.0))
	end
	if ui.debug.showSlimPoints and ui.debug.showSlimPoints.value then
		drawPartDebugPoints(_right, Vector3.new(0.0, 1.0, 0.0), Vector3.new(1.0, 1.0, 1.0))
		drawPartDebugPoints(_left, Vector3.new(1.0, 0.0, 0.0), Vector3.new(1.0, 1.0, 1.0))
	end
	drawRawAndCorrectedInputPoints()
	if ui.debug.showCalfStartKeyPoints and ui.debug.showCalfStartKeyPoints.value then
		drawCalfStartKeyPoints()
	end
	if ui.debug.showCalfSliceExposure and ui.debug.showCalfSliceExposure.value then
		drawCalfSliceExposure()
	end
	if ui.debug.showLegOwnershipPoints and ui.debug.showLegOwnershipPoints.value then
		drawLegOwnershipPoints()
	end
	local svalue = ui.debug.showMeshPoints.value
	if svalue == 1 then
		DrawPoint(newPoints, Vector3.new(1.0, 0.0, 0.0))
	end
	if ui.debug.showRawMeshPoints and ui.debug.showRawMeshPoints.value then
		DrawPoint(_vertices, Vector3.new(0.0, 1.0, 0.0))
	end
	if ui.debug.showDeformedMeshPoints and ui.debug.showDeformedMeshPoints.value then
		DrawPoint(newPoints, Vector3.new(1.0, 0.0, 0.0))
	end
	if ui.debug.showMeshDisplacement and ui.debug.showMeshDisplacement.value then
		drawMeshDisplacement(_vertices, newPoints, Vector3.new(1.0, 1.0, 0.0))
	end
	if ui.debug.showRawDeformedMeshPoints and ui.debug.showRawDeformedMeshPoints.value then
		DrawPoint(_lastRawDeformedPoints, Vector3.new(0.2, 0.8, 1.0))
	end
	if ui.debug.showRawMeshDisplacement and ui.debug.showRawMeshDisplacement.value then
		drawMeshDisplacement(_vertices, _lastRawDeformedPoints, Vector3.new(0.2, 0.8, 1.0))
	end
	drawDisabledLegMarkers()
end

-- 5x7 点阵字，用于屏幕 HUD（无系统字体 API）
local HUD_GW, HUD_GH, HUD_ADV = 5, 7, 6
local HUD_FONT = {
	[" "] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	["-"] = {0x00,0x00,0x00,0x1F,0x00,0x00,0x00},
	[":"] = {0x00,0x04,0x00,0x00,0x04,0x00,0x00},
	["."] = {0x00,0x00,0x00,0x00,0x00,0x04,0x04},
	[">"] = {0x08,0x04,0x02,0x01,0x02,0x04,0x08},
	["~"] = {0x00,0x08,0x15,0x02,0x00,0x00,0x00},
	["0"] = {0x0E,0x11,0x13,0x15,0x19,0x11,0x0E},
	["1"] = {0x04,0x0C,0x04,0x04,0x04,0x04,0x0E},
	["2"] = {0x0E,0x11,0x01,0x06,0x08,0x10,0x1F},
	["3"] = {0x1F,0x02,0x04,0x02,0x01,0x11,0x0E},
	["4"] = {0x02,0x06,0x0A,0x12,0x1F,0x02,0x02},
	["5"] = {0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E},
	["6"] = {0x06,0x08,0x10,0x1E,0x11,0x11,0x0E},
	["7"] = {0x1F,0x01,0x02,0x04,0x08,0x08,0x08},
	["8"] = {0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E},
	["9"] = {0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C},
	["A"] = {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11},
	["B"] = {0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E},
	["C"] = {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E},
	["D"] = {0x1E,0x11,0x11,0x11,0x11,0x11,0x1E},
	["E"] = {0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F},
	["F"] = {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10},
	["G"] = {0x0E,0x11,0x10,0x17,0x11,0x11,0x0F},
	["H"] = {0x11,0x11,0x11,0x1F,0x11,0x11,0x11},
	["I"] = {0x0E,0x04,0x04,0x04,0x04,0x04,0x0E},
	["K"] = {0x11,0x12,0x14,0x18,0x14,0x12,0x11},
	["L"] = {0x10,0x10,0x10,0x10,0x10,0x10,0x1F},
	["M"] = {0x11,0x1B,0x15,0x11,0x11,0x11,0x11},
	["N"] = {0x11,0x19,0x15,0x13,0x11,0x11,0x11},
	["O"] = {0x0E,0x11,0x11,0x11,0x11,0x11,0x0E},
	["P"] = {0x1E,0x11,0x11,0x1E,0x10,0x10,0x10},
	["R"] = {0x1E,0x11,0x11,0x1E,0x14,0x12,0x11},
	["S"] = {0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E},
	["T"] = {0x1F,0x04,0x04,0x04,0x04,0x04,0x04},
	["U"] = {0x11,0x11,0x11,0x11,0x11,0x11,0x0E},
	["V"] = {0x11,0x11,0x11,0x11,0x0A,0x0A,0x04},
	["X"] = {0x11,0x11,0x0A,0x04,0x0A,0x11,0x11},
	["Y"] = {0x11,0x11,0x0A,0x04,0x04,0x04,0x04},
}

local function hudBitOn(bits, col)
	local shift = HUD_GW - 1 - col
	return math.floor(bits / (2 ^ shift)) % 2 == 1
end

local function collectHudTextPixels(out, x, y, text, scale)
	local cx = x
	for i = 1, #text do
		local ch = string.sub(text, i, i)
		if ch == string.lower(ch) and ch ~= string.upper(ch) then
			ch = string.upper(ch)
		end
		local glyph = HUD_FONT[ch] or HUD_FONT[" "]
		for row = 0, HUD_GH - 1 do
			local bits = glyph[row + 1] or 0
			for col = 0, HUD_GW - 1 do
				if hudBitOn(bits, col) then
					local px = cx + col * scale
					local py = y + row * scale
					for dy = 0, scale - 1 do
						for dx = 0, scale - 1 do
							out[#out + 1] = { x = px + dx, y = py + dy }
						end
					end
				end
			end
		end
		cx = cx + HUD_ADV * scale
	end
end

local function drawHudText(x, y, text, scale, color)
	if not text or text == "" then
		return
	end
	local pixels = {}
	collectHudTextPixels(pixels, x, y, text, scale)
	if #pixels > 0 then
		DrawPoint(pixels, color)
	end
end

local function drawHudRect(x, y, w, h, color)
	local lines = {
		{ x = x, y = y }, { x = x + w, y = y },
		{ x = x + w, y = y }, { x = x + w, y = y + h },
		{ x = x + w, y = y + h }, { x = x, y = y + h },
		{ x = x, y = y + h }, { x = x, y = y },
	}
	DrawLines(lines, color)
end

local function drawOffsetPreview(doublebuffer, x, y, size)
	if not _luaWorld or not _luaWorld.offsetSamplerA or not _luaWorld.debugBlitMaterial or not _luaWorld.offsetQuadModel then
		return
	end
	doublebuffer:BindFBOA()
	local game = Game.getInstance()
	local viewport = game:getViewport()
	local left = viewport:left()
	local top = viewport:top()
	local right = viewport:right()
	local bottom = viewport:bottom()
	game:setViewport(Rectangle.new(x, y, x + size, y + size))
	_luaWorld.debugBlitMaterial:getParameter("u_srcTexture"):setSampler(_luaWorld.offsetSamplerA)
	_luaWorld.offsetQuadModel:setMaterial(_luaWorld.debugBlitMaterial)
	_luaWorld.offsetQuadModel:draw()
	game:setViewport(Rectangle.new(left, top, right, bottom))
	drawHudRect(x - 1, y - 1, size + 2, size + 2, Vector3.new(1.0, 1.0, 1.0))
end

local function buildOffsetHudLines(path, w0, h0)
	local lines = {}
	if path == "offsetMap" then
		lines[1] = "PATH:OFFSETMAP"
	elseif path == "mesh" then
		lines[1] = "PATH:MESH"
	elseif path == "fallback" then
		lines[1] = "PATH:FALLBACK"
	elseif path == "skip_intensity" then
		lines[1] = "SKIP:INTENSITY0"
	elseif path == "skip_body" then
		lines[1] = "SKIP:NOBODY"
	else
		lines[1] = "PATH:IDLE"
	end
	local bw = _luaWorld and _luaWorld.offsetBufferWidth or 0
	local bh = _luaWorld and _luaWorld.offsetBufferHeight or 0
	if bw > 0 and bh > 0 then
		local memMb = bw * bh * 4 * 2 / (1024 * 1024)
		lines[2] = string.format("RT:%dx%d RGBA8", bw, bh)
		lines[3] = string.format("MEM:~%.1fMB", memMb)
	else
		lines[2] = "RT:NONE"
		lines[3] = "MEM:~0.0MB"
	end
	lines[4] = string.format("FULL:%dx%d", w0 or 0, h0 or 0)
	return lines
end

local function drawOffsetMemHud(doublebuffer, w0, h0)
	if not ui or not ui.antiShake or not ui.antiShake.showOffsetMemStatus or not ui.antiShake.showOffsetMemStatus.value then
		return
	end
	if not _luaWorld or not _luaWorld.lineMeshBatch then
		return
	end
	local diag = _luaWorld.offsetDiag or {}
	local path = diag.renderPath or "idle"
	local titleColor = Vector3.new(1.0, 1.0, 0.2)
	if path == "offsetMap" then
		titleColor = Vector3.new(0.2, 1.0, 0.35)
	elseif path == "mesh" then
		titleColor = Vector3.new(1.0, 0.85, 0.2)
	elseif path == "fallback" then
		titleColor = Vector3.new(1.0, 0.25, 0.25)
	elseif path == "skip_intensity" or path == "skip_body" then
		titleColor = Vector3.new(0.75, 0.75, 0.75)
	end
	local textColor = Vector3.new(0.95, 0.95, 0.95)
	local scale = math.max(2, math.floor((w0 or 720) / 360 + 0.5))
	local pad = 10
	local lineStep = (HUD_GH + 1) * scale
	local hudLines = buildOffsetHudLines(path, w0, h0)
	local panelW = 34 * scale
	local panelH = #hudLines * lineStep + pad * 2
	local baseX, baseY = pad, pad
	drawHudRect(baseX - 4, baseY - 4, panelW + 8, panelH + 8, Vector3.new(0.15, 0.85, 1.0))
	for i, line in ipairs(hudLines) do
		local color = (i == 1) and titleColor or textColor
		drawHudText(baseX, baseY + (i - 1) * lineStep, line, scale, color)
	end
	if path == "offsetMap" and _luaWorld.offsetSamplerA then
		local preview = math.min(180, math.max(96, math.floor((w0 or 720) * 0.18 + 0.5)))
		drawOffsetPreview(doublebuffer, baseX, baseY + panelH + 8, preview)
		drawHudText(baseX, baseY + panelH + preview + 14, "OFFSET RT PREVIEW", scale, Vector3.new(0.7, 0.9, 1.0))
	end
end

return {
	runRender = runRender,
	drawCalfRegionViz = drawCalfRegionViz,
	drawOffsetMemHud = drawOffsetMemHud,
}
