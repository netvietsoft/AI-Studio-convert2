
---------------------------------------------------------
local config =
{
    obj = {
         ---丰胸
        {
            sceneFile = "breast.bls",
            ignoreNode = "SMPL_mesh_male_SMPL_shapes_male",
            sceneNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#offsetmap_C",
                },
            },
            sceneDebugNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#debug",
                },
            },
        },
        ---缩胸
        {
            sceneFile = "breast.bls",
            ignoreNode = "SMPL_mesh_male_SMPL_shapes_male",
            sceneNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#offsetmap_C",
                },
            },
            sceneDebugNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#debug",
                },
            },
        },
        ---天鹅颈
        {
            sceneFile = "neck.bls",
            ignoreNode = "SMPL_mesh_male_SMPL_shapes_male",
            sceneNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#offsetmap_C",
                },
            },
            sceneDebugNodes = {
                base2_364_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#debug",
                },
            },
        },
    },
}

--返回配置
return config
