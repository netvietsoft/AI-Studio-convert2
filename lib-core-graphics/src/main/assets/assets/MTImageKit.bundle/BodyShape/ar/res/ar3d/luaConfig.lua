
---------------------------------------------------------
local config =
{
    ---驼背
    obj = {
        ---翘臀
        {
            sceneFile = "hip.bls",
            ignoreNode = "SMPL_mesh_male_SMPL_shapes_male",
            sceneNodes = {
                base_simple4_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#offsetmap_C",
                },
            },
            sceneDebugNodes = {
                base_simple4_SMPL_mesh_male_SMPL_shapes_male = {
                    material = "all.material#debug",
                },
            },
        },
        ---小腹
        {
            sceneFile = "belly.bls",
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
         ---驼背
        {
            sceneFile = "back.bls",
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
