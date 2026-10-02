cmake_minimum_required(VERSION 3.22.1)

project("meitu_reborn_native")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(include/media/video)
include_directories(include/vision/tracking)
include_directories(include/beauty)
include_directories(include/ai)

# Bat co toi uu hoa toc do cao va da luong OpenMP
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp -fvisibility=default -ffast-math")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -fopenmp -fvisibility=default -ffast-math")

# Setup Tencent NCNN static library
set(ncnn_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ncnn/ncnn-20260526-android/${ANDROID_ABI}/lib/cmake/ncnn")
find_package(ncnn REQUIRED)

add_library(
    meitu_reborn_native
    SHARED
    src/face_mesh_3d.cpp
    src/eye_retouch_engine.cpp
    src/nose_mouth_engine.cpp
    src/skin_makeup_engine.cpp
    src/body_hair_engine.cpp
    src/advanced_tone_engine.cpp
    src/face_reshape_3dmm.cpp
    src/face_relight.cpp
    src/face_tracking.cpp
    src/hair_daub.cpp
    src/liquify_warp.cpp
    src/color_lut.cpp
    src/portrait_matting.cpp
    src/teeth_ear_engine.cpp
    src/camera_shutter_pipeline.cpp
    src/yuv_converter.cpp
    src/ncnn_face_engine.cpp
    src/dense_facemesh_478.cpp
    src/face_retouch_detail.cpp
    src/adaptive_temporal_stabilizer.cpp
    src/landmark_fusion.cpp
    src/hair_matting_engine.cpp
    src/hair_strand_dye.cpp
    src/hair_engine.cpp
    src/hair/hair_orientation_engine.cpp
    src/hair/hair_texture_engine.cpp
    src/hair/hair_appearance_engine.cpp
    src/hair/hair_dye_material_engine.cpp
    src/hair/hair_anisotropic_specular_engine.cpp
    src/hair/hair_gpu_backend.cpp
    src/hair/hair_color_pipeline.cpp
    src/beard_dye_engine.cpp
    src/id_photo_collage_engine.cpp
    src/head_semantic_model.cpp
    src/head_skull_engine.cpp
    src/neck_clavicle_engine.cpp
    src/eyebrow_lash_engine.cpp
    src/eyelash_engine.cpp
    src/philtrum_engine.cpp
    src/clavicle_shoulder_engine.cpp
    src/accessory_occlusion_engine.cpp
    src/surface_normal_engine.cpp
    src/scalp_reconstruction_engine.cpp
    src/inference_backend_interface.cpp
    src/beauty_parameter_controller.cpp
    src/background_protection_engine.cpp
    src/body_contour_engine.cpp
    src/long_legs_body_slim_engine.cpp
    src/body_limb_hand_engine.cpp
    src/clothing_aware_engine.cpp
    src/dense_body_mesh.cpp
    src/deformation_constraint_solver.cpp
    src/body_semantic_model.cpp
    src/body_beauty_engine.cpp
    src/full_human_beauty_controller.cpp
    src/ai/bisenet_face_parser.cpp
    src/media/video/native_video_decoder.cpp
    src/media/video/video_frame_pool.cpp
    src/media/video/video_timeline_compositor.cpp
    src/vision/tracking/optical_flow_tracker.cpp
    src/jni_bridge.cpp
)

find_library(log-lib log)
find_library(jnigraphics-lib jnigraphics)
find_library(android-lib android)
find_library(mediandk-lib mediandk)

target_link_libraries(
    meitu_reborn_native
    ncnn
    ${log-lib}
    ${jnigraphics-lib}
    ${android-lib}
    ${mediandk-lib}
    m
    -fopenmp
    -static-openmp
)
