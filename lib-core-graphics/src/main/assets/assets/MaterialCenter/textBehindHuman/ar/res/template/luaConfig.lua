
---------------------------------------------------------
-- enum SegmentMaskType {
--     SegmentMask_Invalid = -1,		// 无效
--     SegmentMask_BodyReverse = 0,	// 身体以外的部分.
--     SegmentMask_Body = 1,			// 身体以内的部分.
--     SegmentMask_Source = 2,			// 外部设置身体分割.
--     SegmentMask_FaceReverse = 3,	// 脸部以外的部分(暂时弃用).
--     SegmentMask_Face = 4,			// 脸部以内的部分(暂时弃用).
--     SegmentMask_Sky = 5,			// 天空以内的部分.
--     SegmentMask_SkyReverse = 6,		// 天空以外的部分.
--     SegmentMask_Hair = 7,			// 头发以内的部分.
--     SegmentMask_HairReverse = 8,	// 头发以外的部分.
--     SegmentMask_Eraser = 9,         // 外部设置头发分割
--     SegmentMask_Head = 10,			// 头部以内的部分
--     SegmentMask_HeadReverse = 11,	// 头部以外的部分
--     SegmentMask_Skin = 12,          // 皮肤分割以内
--     SegmentMask_SkinReverse = 13,   // 皮肤分割以外
--     SegmentMask_Cloth = 14,			// 衣服分割以内
--     SegmentMask_ClothReverse = 15,	// 衣服分割以外
--     SegmentMaskSize					// 数量
-- };

local config = {}

config.segmentType = 2
config.debug = false

--返回配置
return config
