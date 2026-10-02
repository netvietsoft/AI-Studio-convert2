// CÂY PHÂN CẤP CHỨC NĂNG CHỈNH SỬA ẢNH (EDITPHOTO) CHUẨN 100% NGUYÊN BẢN MEITU
// Gồm 4 cấp: Cấp 0 (Module Cha), Cấp 1 (Menu Con), Cấp 2 (Menu Cháu), Cấp 3 (Menu Chắt/Chút)

export const EDITPHOTO_HIERARCHY = {
  id: "module_editphoto_root",
  name: "Chỉnh Sửa Ảnh Toàn Năng (Edit Photo Core)",
  nameEn: "Photo Editor Main Engine",
  level: "cha",
  totalFeatures: 158,
  vipCount: 62,
  freeCount: 96,
  jniModulesLinked: 45,
  categories: [
    {
      id: "cat_basic_edit",
      name: "1. Chỉnh Sửa Cơ Bản & Khung Hình (Basic Edit & Canvas)",
      nameEn: "Basic Adjustments & Geometry",
      icon: "📐",
      level: "con",
      subGroups: [
        {
          id: "sub_crop_geometry",
          name: "Cắt, Xoay & Phối Cảnh (Crop & Geometry)",
          nameEn: "Crop, Rotation & Perspective",
          level: "chau",
          tools: [
            {
              id: "tool_crop_ratios",
              name: "Cắt Tỷ Lệ Đa Dạng (1:1, 4:3, 16:9, 9:16, 3:2, 2:3, Tự Do)",
              nameEn: "Aspect Ratio Crop Matrix",
              level: "chat",
              controlType: "Preset Selector & Drag Handles",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeCropCanvas(handle, x, y, w, h, ratio)",
              description: "Cắt ảnh theo chuẩn tỷ lệ khung hình Instagram, TikTok, Facebook hoặc tỷ lệ tự do."
            },
            {
              id: "tool_rotate_flip",
              name: "Xoay Góc Tự Do & Lật Gương (Rotate 360° & Flip H/V)",
              nameEn: "Free Rotation & Mirror Flip",
              level: "chat",
              controlType: "Angle Slider (-180° đến +180°) & Flip Buttons",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeRotateCanvas(handle, degree, flipX, flipY)",
              description: "Xoay ảnh mọi góc độ kèm lưới căn chỉnh chân trời tự động, lật đối xứng gương."
            },
            {
              id: "tool_perspective_correct",
              name: "Nắn Phối Cảnh & Căn Góc Nghiêng 3D (Perspective 3D)",
              nameEn: "Keystone & Perspective Correction",
              level: "chat",
              controlType: "4-Corner Pin Quad Mesh Slider",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeWarpPerspective(handle, float[] srcQuad, float[] dstQuad)",
              description: "Nắn chỉnh góc chụp nghiêng của tòa nhà, văn bản hoặc ảnh chụp bị méo góc."
            }
          ]
        },
        {
          id: "sub_light_color",
          name: "Ánh Sáng & Sắc Độ (Light & Color Adjustments)",
          nameEn: "Lighting, Exposure & Color Balance",
          level: "chau",
          tools: [
            {
              id: "tool_brightness_contrast",
              name: "Độ Sáng & Độ Tương Phản (Brightness & Contrast)",
              nameEn: "Brightness & Contrast Adjuster",
              level: "chat",
              controlType: "Bipolar Slider (-100 đến +100)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeSetBrightnessContrast(handle, float b, float c)",
              description: "Cân chỉnh cường độ chiếu sáng và tỷ lệ tương phản động trên toàn dải pixel."
            },
            {
              id: "tool_highlights_shadows",
              name: "Vùng Sáng & Vùng Tối (Highlights & Shadows Recovery)",
              nameEn: "HDR Highlights & Shadows Tuning",
              level: "chat",
              controlType: "Slider (0 đến 100)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeTuneHighlightsShadows(handle, float hi, float sh)",
              description: "Cứu chi tiết vùng cháy sáng hoặc kéo sáng vùng tối mà không làm bết màu."
            },
            {
              id: "tool_saturation_vibrance",
              name: "Độ Bão Hòa & Độ Tươi Màu (Saturation & Vibrance)",
              nameEn: "Color Saturation & Smart Vibrance",
              level: "chat",
              controlType: "Bipolar Slider (-100 đến +100)",
              isVip: false,
              nativeLib: "libPVGColorFunctions.so",
              jniMethod: "nativeAdjustColorSaturation(handle, float sat, float vib)",
              description: "Tăng độ rực rỡ của màu sắc, bảo vệ tông màu da người không bị cháy cam."
            },
            {
              id: "tool_color_temperature_tint",
              name: "Nhiệt Độ Màu & Tông Màu (Temperature & Tint WB)",
              nameEn: "White Balance & Kelvin Tint",
              level: "chat",
              controlType: "Dual Slider (Warm/Cold & Magenta/Green)",
              isVip: false,
              nativeLib: "libPVGColorFunctions.so",
              jniMethod: "nativeSetWhiteBalance(handle, float kelvin, float tint)",
              description: "Cân bằng trắng chuẩn xác, giả lập tông ấm hoàng hôn hoặc tông xanh lạnh điện ảnh."
            },
            {
              id: "tool_sharpness_clarity",
              name: "Độ Sắc Nét & Trong Trẻo (Sharpness & Clarity)",
              nameEn: "Unsharp Mask & Midtone Clarity",
              level: "chat",
              controlType: "Slider (0 đến 100)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyUnsharpMask(handle, float amount, float radius)",
              description: "Tăng cường độ nét ở các cạnh chi tiết và cải thiện độ sâu trường ảnh ở vùng trung sắc."
            },
            {
              id: "tool_film_grain",
              name: "Hạt Phim Cổ Điển (Film Grain Texture)",
              nameEn: "Analog Film Grain Simulation",
              level: "chat",
              controlType: "Dual Slider (Grain Size & Intensity)",
              isVip: true,
              nativeLib: "libfantasy.so",
              jniMethod: "nativeRenderFilmGrain(handle, float intensity, float size)",
              description: "Mô phỏng lớp nhiễu hạt bạc analog cổ điển từ cuộn film Kodak & Fujifilm 35mm."
            },
            {
              id: "tool_vignette",
              name: "Tối Góc Nghệ Thuật (Vignette Shading)",
              nameEn: "Lens Vignetting & Feather",
              level: "chat",
              controlType: "Dual Slider (Vignette Depth & Feather Radius)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyVignette(handle, float amount, float midpoint)",
              description: "Làm tối hoặc sáng nhẹ 4 góc ảnh, tạo điểm nhấn hút mắt vào trung tâm bức hình."
            }
          ]
        },
        {
          id: "sub_advanced_color",
          name: "Màu Sắc Nâng Cao (HSL & RGB Curves)",
          nameEn: "Selective HSL & Tone Curves",
          level: "chau",
          tools: [
            {
              id: "tool_hsl_8_channels",
              name: "Bộ Trộn Màu HSL 8 Kênh (Đỏ, Cam, Vàng, Lục, Lam, Chàm, Tím, Hồng)",
              nameEn: "8-Channel HSL Mixer (Hue, Saturation, Lightness)",
              level: "chat",
              controlType: "Color Dot Selector + 3 Sliders per Color",
              isVip: true,
              nativeLib: "libPVGColorFunctions.so",
              jniMethod: "nativeSetSelectiveHSL(handle, int channel, float h, float s, float l)",
              description: "Hiệu chỉnh độc lập sắc độ, độ rực và độ sáng của từng dải màu riêng biệt."
            },
            {
              id: "tool_rgb_curves",
              name: "Đường Cong Sắc Độ RGB Đa Điểm (RGB Tone Curves)",
              nameEn: "Multi-point RGB Tone Curves (Master, R, G, B)",
              level: "chat",
              controlType: "Interactive Spline Curve Canvas with Anchor Points",
              isVip: true,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyCurveSpline(handle, int channel, float[] points)",
              description: "Điều khiển đường cong độ sáng và cân bằng màu chuyên sâu chuẩn Adobe Lightroom."
            }
          ]
        },
        {
          id: "sub_lens_blur",
          name: "Làm Mờ & Chiều Sâu (Lens Blur & Tilt-Shift)",
          nameEn: "Depth of Field & Lens Bokeh",
          level: "chau",
          tools: [
            {
              id: "tool_gaussian_blur",
              name: "Làm Mờ Vùng Chọn Gaussian (Selective Gaussian Blur)",
              nameEn: "Custom Radius Gaussian Blur",
              level: "chat",
              controlType: "Radius Slider (0 - 50px) + Mask Brush",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyGaussianBlur(handle, float radius, int maskFbo)",
              description: "Làm mờ mịn màng hậu cảnh hoặc các vùng chi tiết cần giảm bớt sự chú ý."
            },
            {
              id: "tool_lens_bokeh",
              name: "Xóa Phông Hiệu Ứng Bokeh Ống Kính (Optical Bokeh FX)",
              nameEn: "Optical Aperture Bokeh (Heart, Star, Hexagon)",
              level: "chat",
              controlType: "Bokeh Shape Selector + Aperture Intensity Slider",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeRenderBokehBlur(handle, int shapeId, float aperture)",
              description: "Mô phỏng khẩu độ ống kính f/1.4 tạo các đốm sáng tròn, trái tim hoặc ngôi sao lung linh."
            },
            {
              id: "tool_tilt_shift",
              name: "Làm Mờ Mô Hình Thu Nhỏ (Radial & Linear Tilt-Shift)",
              nameEn: "Linear & Radial Tilt-Shift Miniature",
              level: "chat",
              controlType: "Interactive Pinch & Rotate Guide Lines",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyTiltShift(handle, int mode, float center, float width)",
              description: "Tạo hiệu ứng sa bàn đồ chơi thu nhỏ theo dải tuyến tính hoặc vòng tròn đồng tâm."
            }
          ]
        }
      ]
    },
    {
      id: "cat_portrait_beauty",
      name: "2. Làm Đẹp Chân Dung & Điêu Khắc (Portrait Retouch & Beauty)",
      nameEn: "Portrait Beauty & 3D Sculpting",
      icon: "💆‍♀️",
      level: "con",
      subGroups: [
        {
          id: "sub_skin_care",
          name: "Làn Da Hoàn Hảo (Skin Master & Tone)",
          nameEn: "Skin Softening & Complexion Tuning",
          level: "chau",
          tools: [
            {
              id: "tool_auto_beautify",
              name: "Làm Đẹp 1 Chạm Thông Minh (One-Tap Smart Beautify)",
              nameEn: "AI 1-Tap Facial Enhancement",
              level: "chat",
              controlType: "Intensity Slider (0 - 100%)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeAutoBeautify(handle, float level)",
              description: "AI tự động phân tích độ tuổi, giới tính và ánh sáng để tối ưu mịn da, sáng mắt chỉ với 1 chạm."
            },
            {
              id: "tool_skin_smooth_texture",
              name: "Làm Mịn Da Bảo Toàn Vân Da (Dual Bilateral Smooth)",
              nameEn: "Pore-Preserving Dual Bilateral Skin Smoothing",
              level: "chat",
              controlType: "Smooth Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeSkinSoften(handle, int level, boolean keepTexture)",
              description: "Làm mờ nếp nhăn và đốm nâu mà vẫn giữ nguyên kết cấu lỗ chân lông tự nhiên, không bị búp bê nhựa."
            },
            {
              id: "tool_skin_whitening_glow",
              name: "Làm Trắng Hồng Tự Nhiên (Natural Glow & Whitening)",
              nameEn: "Skin Radiance & Rosy Whitening",
              level: "chat",
              controlType: "White Level Slider (0 - 100)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeSkinWhitening(handle, int whiteLevel, int rosyLevel)",
              description: "Tăng sắc tố hồng hào và nâng tông da sáng khỏe, loại bỏ hoàn toàn hiện tượng da xỉn màu."
            },
            {
              id: "tool_skin_tone_changer",
              name: "Thay Đổi Tông Màu Da Đa Dạng (Skin Tone Palette)",
              nameEn: "Multi-Ethnic Skin Tone Palette (Porcelain, Tan, Golden)",
              level: "chat",
              controlType: "Swatch Palette (6 Shades) + Opacity Slider",
              isVip: true,
              nativeLib: "libPVGColorFunctions.so",
              jniMethod: "nativeApplySkinTone(handle, int toneIndex, float opacity)",
              description: "Chuyển đổi làn da sang tông trắng sứ Bắc Âu, nâu bánh mật thể thao hoặc rám nắng nhiệt đới."
            },
            {
              id: "tool_blemish_acne_remover",
              name: "Xóa Mụn, Tàn Nhang & Sẹo Rỗ (AI Blemish & Acne Eraser)",
              nameEn: "Intelligent Acne & Mole Spot Healer",
              level: "chat",
              controlType: "Auto AI Mode or Manual Spot Brush Size",
              isVip: false,
              nativeLib: "libaidetectionplugin.so",
              jniMethod: "nativeRemoveBlemishes(handle, float[] coords, int count)",
              description: "AI tự động phát hiện mụn trứng cá và xóa sạch tàn nhang trong tíc tắc."
            },
            {
              id: "tool_dark_circles_bags",
              name: "Xóa Quầng Thâm & Bọng Mắt (Dark Circles & Under-Eye Bags)",
              nameEn: "Under-Eye Dark Circles & Pockets Diminisher",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeClearDarkCircles(handle, float intensity)",
              description: "Xóa tan vết thâm quầng mệt mỏi và làm phẳng bọng mắt tức thì."
            },
            {
              id: "tool_matte_oil_control",
              name: "Khử Bóng Nhờn & Kiềm Dầu Vùng T-Zone (Matte Oil Control)",
              nameEn: "Facial Matte & Shine Removal",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeReduceSkinShine(handle, float matteLevel)",
              description: "Loại bỏ ánh bóng nhờn do dầu thừa hoặc đèn flash máy ảnh trên trán, mũi và cằm."
            }
          ]
        },
        {
          id: "sub_face_reshape_3d",
          name: "Điêu Khắc Khuôn Mặt 3D (3D Facial Reshaping)",
          nameEn: "106-Point Mesh Facial Reshaping",
          level: "chau",
          tools: [
            {
              id: "tool_slim_face",
              name: "Gọt Cằm V-Line & Thu Gọn Mặt (V-Line Jaw & Slim Face)",
              nameEn: "V-Line Jaw & Lower Face Slimming",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeSetSlimFace(handle, int intensity)",
              description: "Biến dạng lưới 106 điểm neo để thu gọn góc hàm vuông thành khuôn mặt V-Line thanh tú."
            },
            {
              id: "tool_chin_length",
              name: "Chiều Dài & Độ Nhọn Cằm (Chin Length & Pointiness)",
              nameEn: "Chin Extension, Shortening & Pointiness",
              level: "chat",
              controlType: "Bipolar Slider (-50 đến +50)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeAdjustChin(handle, float length, float tip)",
              description: "Kéo dài cằm ngắn hoặc thu ngắn cằm dài để đạt chuẩn tỷ lệ nhân trắc học hoàn hảo."
            },
            {
              id: "tool_cheekbones_reshape",
              name: "Hạ Xương Gò Má Cao (Cheekbones Reduction & Sculpting)",
              nameEn: "High Cheekbone Softener & Lifting",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeTuneCheekbones(handle, float reduction)",
              description: "Thu gọn gò má bướng bỉnh, giúp khuôn mặt mềm mại và nữ tính hơn khi nhìn góc nghiêng 45°."
            },
            {
              id: "tool_forehead_size",
              name: "Thu Nhỏ Trán & Căn Chỉnh Trán Cao (Forehead Resizing)",
              nameEn: "Forehead Height Adjustment",
              level: "chat",
              controlType: "Bipolar Slider (-50 đến +50)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeResizeForehead(handle, float ratio)",
              description: "Điều chỉnh chiều cao vùng trán, cân bằng tỷ lệ Thượng Đình - Trung Đình - Hạ Đình."
            },
            {
              id: "tool_golden_ratio_symmetry",
              name: "Cân Bằng Đối Xứng Khuôn Mặt (Facial Symmetry Auto-Align)",
              nameEn: "AI Facial Symmetry Alignment",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeCorrectFacialSymmetry(handle, float level)",
              description: "AI so sánh 2 nửa khuôn mặt và tự động cân chỉnh độ lệch lạc do thói quen nhai hoặc nằm nghiêng."
            }
          ]
        },
        {
          id: "sub_eye_features",
          name: "Đôi Mắt Rạng Rỡ (Eye Beautifier & Sparkle)",
          nameEn: "Eye Size, Distance & Sparkle Tuning",
          level: "chau",
          tools: [
            {
              id: "tool_eye_enlarging",
              name: "Mở To Mắt Tự Nhiên (Eye Enlarging & Pupil Boost)",
              nameEn: "Natural Eye Scaling & Pupil Boost",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeSetEyeSize(handle, int sizeLevel)",
              description: "Phóng to mắt tròn long lanh mà không làm biến dạng vùng da mí mắt xung quanh."
            },
            {
              id: "tool_eye_brighten",
              name: "Làm Sáng Tròng Mắt & Đốm Sáng Catchlight (Eye Brighten)",
              nameEn: "Sclera Whitening & Catchlight Injection",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeBrightenEyes(handle, float brightLevel)",
              description: "Khử tia máu đỏ ở lòng trắng mắt và bổ sung điểm phản xạ ánh sáng (catchlight) sống động."
            },
            {
              id: "tool_eye_distance_angle",
              name: "Khoảng Cách 2 Mắt & Góc Đuôi Mắt (Eye Distance & Tilt)",
              nameEn: "Interpupillary Distance & Canthal Tilt",
              level: "chat",
              controlType: "Dual Slider (Distance & Tilt Angle)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeAdjustEyeDistanceAndAngle(handle, float dist, float tilt)",
              description: "Kéo gần hoặc giãn xa khoảng cách giữa 2 khóe mắt, tạo dáng đuôi mắt cáo cá tính."
            }
          ]
        },
        {
          id: "sub_nose_mouth_teeth",
          name: "Mũi, Miệng & Răng (Nose, Lips & Teeth)",
          nameEn: "Nose Sculpt, Smile & Teeth Whitening",
          level: "chau",
          tools: [
            {
              id: "tool_nose_wings_slim",
              name: "Thu Nhỏ Cánh Mũi & Nâng Sống Mũi (Nose Slim & Bridge)",
              nameEn: "Nasal Alar Reduction & Bridge Elevation",
              level: "chat",
              controlType: "Dual Slider (Wings Slim & Bridge Height)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeTuneNose(handle, float alar, float bridge)",
              description: "Thu gọn 2 bên cánh mũi thon nhỏ và nâng cao sống mũi thẳng tắp thanh lịch."
            },
            {
              id: "tool_smile_enhancer",
              name: "Tạo Khóe Cười Rạng Rỡ (Smile Lift & Mouth Corner)",
              nameEn: "Mouth Corner Smile Lifting",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeLiftSmile(handle, float smileAmount)",
              description: "Uốn cong nhẹ 2 khóe môi hướng lên trên, tạo vẻ mặt tươi tắn nở nụ cười tự nhiên."
            },
            {
              id: "tool_lip_plumper",
              name: "Làm Dày Môi 3D & Tạo Rãnh Môi Gợi Cảm (Lip Plumper)",
              nameEn: "3D Lip Volume & Cupid's Bow Plumping",
              level: "chat",
              controlType: "Dual Slider (Upper Lip & Lower Lip)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativePlumpLips(handle, float upper, float lower)",
              description: "Tăng thể tích đôi môi căng mọng quyến rũ và định hình rãnh tim nhân trung sắc nét."
            },
            {
              id: "tool_teeth_whitening",
              name: "Làm Trắng Răng Tự Nhiên (Teeth Whitening)",
              nameEn: "Dental Whitening & Stain Removal",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeWhitenTeeth(handle, float level)",
              description: "Nhận diện cung hàm và tẩy sạch ố vàng trên men răng, mang lại nụ cười tỏa sáng tự tin."
            }
          ]
        },
        {
          id: "sub_body_resizing",
          name: "Vóc Dáng & Chiều Cao (Body Tuner & Lengthening)",
          nameEn: "Full Body Shaping & Leg Lengthening",
          level: "chau",
          tools: [
            {
              id: "tool_leg_lengthening",
              name: "Kéo Dài Chân Tỷ Lệ Vàng (Leg Lengthening & Height)",
              nameEn: "Intelligent Leg Extension",
              level: "chat",
              controlType: "Interactive Horizon Line Guide + Stretch Slider",
              isVip: true,
              nativeLib: "libARSPM.so",
              jniMethod: "nativeExtendLegs(handle, float startY, float factor)",
              description: "Kéo dài đôi chân chuẩn tỷ lệ siêu mẫu mà không làm méo mó các đường gạch hay vật thể nền."
            },
            {
              id: "tool_waist_slimming",
              name: "Thu Nhỏ Vòng Eo Con Kiến (Waist & Abdomen Slimming)",
              nameEn: "Waistline Contouring",
              level: "chat",
              controlType: "Slider (0 - 100) + Pin Handles",
              isVip: true,
              nativeLib: "libARSPM.so",
              jniMethod: "nativeSlimWaist(handle, float amount)",
              description: "Nhận diện đường cong cơ thể và bóp nhỏ eo đồng hồ cát gợi cảm."
            },
            {
              id: "tool_head_shrink",
              name: "Thu Nhỏ Tỷ Lệ Đầu So Với Cơ Thể (Head Size Optimizer)",
              nameEn: "Head to Body Proportion Tuner",
              level: "chat",
              controlType: "Slider (0 - 100)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeShrinkHead(handle, float ratio)",
              description: "Thu nhỏ kích thước đầu để tạo dáng người cao ráo chuẩn 8 - 9 đầu như người mẫu sàn diễn."
            }
          ]
        }
      ]
    },
    {
      id: "cat_virtual_makeup",
      name: "3. Trang Điểm Kỹ Thuật Số (Digital Virtual Makeup)",
      nameEn: "AR Digital Makeup Suite",
      icon: "💄",
      level: "con",
      subGroups: [
        {
          id: "sub_lipstick_suite",
          name: "Son Môi Cao Cấp (Lipstick Suite)",
          nameEn: "Lipstick Textures & Color Palette",
          level: "chau",
          tools: [
            {
              id: "tool_lip_textures",
              name: "5 Loại Chất Son (Matte Nhung, Glossy Bóng Mọng, Satin Mềm, Shimmer Kim Tuyến, Water Tint)",
              nameEn: "5 Lipstick Finishes & Shader Blends",
              level: "chat",
              controlType: "Finish Tab Selector",
              isVip: true,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeSetLipstickTexture(handle, int finishMode)",
              description: "Mô phỏng chân thực độ phản quang ánh sáng của các dòng son hi-end hàng đầu thế giới."
            },
            {
              id: "tool_lip_color_palette",
              name: "Bảng 60+ Màu Son (Đỏ Thuần, Cam Cháy, Hồng Đất, Nude Khói, Rượu Vang)",
              nameEn: "60+ Shade Chromatic Spectrum",
              level: "chat",
              controlType: "Color Swatch Grid + Hex Picker",
              isVip: false,
              nativeLib: "libPVGColorFunctions.so",
              jniMethod: "nativeSetLipColor(handle, String hex, float alpha)",
              description: "Đầy đủ các tông màu son thời thượng, hỗ trợ điều chỉnh độ đậm nhạt (Alpha 0-100%)."
            },
            {
              id: "tool_lip_ombre_gradient",
              name: "Đánh Son Lòng Môi Ombre 2 Màu (Two-Tone Ombre Lips)",
              nameEn: "Inner-to-Outer Gradient Ombre",
              level: "chat",
              controlType: "Dual Color Swatch Selector",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeSetTwoToneLips(handle, String innerHex, String outerHex)",
              description: "Phong cách đánh son lòng môi xí muội Hàn Quốc chuyển sắc từ đậm sang nhạt tự nhiên."
            }
          ]
        },
        {
          id: "sub_eye_makeup",
          name: "Trang Điểm Mắt & Kính Áp Tròng (Eye Makeup & Lenses)",
          nameEn: "Eyeshadow, Eyeliner, Lashes & Contact Lenses",
          level: "chau",
          tools: [
            {
              id: "tool_eyeshadow_palettes",
              name: "Phấn Mắt Đa Tầng (Eyeshadow Single, Duo & Glitter)",
              nameEn: "Multi-tone Shimmer & Matte Eyeshadow",
              level: "chat",
              controlType: "Palette Grid (24 Styles)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeApplyEyeshadow(handle, int styleId, float alpha)",
              description: "Phối màu phấn mắt khói, nhũ cam đào hoặc hồng đất với ánh kim tuyến phản xạ 3D."
            },
            {
              id: "tool_eyeliner_styles",
              name: "Kiểu Kẻ Mắt Đa Dạng (Cat-Eye, Puppy, Winged, Tightline)",
              nameEn: "Graphic & Classic Eyeliner Stencils",
              level: "chat",
              controlType: "Style Carousel (16 Stencils)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeApplyEyeliner(handle, int stencilId, String colorHex)",
              description: "Kẻ đuôi mắt sắc sảo từ tự nhiên thanh mảnh đến mắt mèo quyến rũ đậm cá tính."
            },
            {
              id: "tool_eyelashes_3d",
              name: "Lông Mi 3D Từng Sợi (Wispy, Doll Eyes, Volume Drama)",
              nameEn: "Volumetric 3D Eyelash Strands",
              level: "chat",
              controlType: "Lash Type Selector + Curl Slider",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeAttachLashes(handle, int lashId, float curl, float density)",
              description: "Gắn mi giả siêu thực với độ cong vút và từng sợi mi tơi đều theo góc nhìn 3 chiều."
            },
            {
              id: "tool_contact_lenses",
              name: "Kính Áp Tròng Đổi Màu Mắt (AR Iris Contact Lenses)",
              nameEn: "Cosmetic Colored Contact Lenses",
              level: "chat",
              controlType: "Pattern & Color Grid (Gray, Hazel, Blue, Amber)",
              isVip: true,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeApplyContactLens(handle, int lensTextureId, float opacity)",
              description: "Biến đổi màu tròng mắt với các họa tiết vân lens xám tây, nâu hổ phách hoặc xanh biếc."
            }
          ]
        },
        {
          id: "sub_blush_brows_hair",
          name: "Má Hồng, Lông Mày & Tóc (Blush, Brows & Hair)",
          nameEn: "Blush Contouring, Eyebrows & Hair Coloring",
          level: "chau",
          tools: [
            {
              id: "tool_blush_regions",
              name: "Phấn Má Theo Vùng (Gò Má Cao, Vắt Mũi Sun-Kissed, Dưới Mắt Igari)",
              nameEn: "Blush Placement Topography",
              level: "chat",
              controlType: "Region Selector + Color Swatch",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeSetBlush(handle, int regionId, String hex, float alpha)",
              description: "Đánh má hồng theo phong cách thiếu nữ Nhật Bản (Igari) hoặc má hồng rám nắng mùa hè."
            },
            {
              id: "tool_eyebrows_stencil",
              name: "Dáng Chân Mày Tự Nhiên (Ngang Hàn Quốc, Cong Tây, Lá Liễu)",
              nameEn: "Eyebrow Shape Stencils & Tinting",
              level: "chat",
              controlType: "Shape Selector + Shade Swatches (Black, Brown, Grey)",
              isVip: false,
              nativeLib: "libarkernel3.so",
              jniMethod: "nativeRenderBrows(handle, int browShapeId, String hex, float fill)",
              description: "Điền đầy các khoảng thưa của chân mày và chỉnh dáng cung mày chuẩn phong thủy."
            },
            {
              id: "tool_virtual_hair_dye",
              name: "Nhuộm Tóc Ảo Đa Sắc (Bạch Kim, Khói Rêu, Ombre, Highlight)",
              nameEn: "AI Hair Segmentation & Virtual Color Dye",
              level: "chat",
              controlType: "Color Swatch Grid + Multi-tone Mode",
              isVip: true,
              nativeLib: "libARSPM.so",
              jniMethod: "nativeDyeHair(handle, String primaryHex, String secondaryHex, float shine)",
              description: "AI phân đoạn từng lọn tóc và nhuộm màu tóc ảo tức thì với độ bóng mượt tự nhiên."
            }
          ]
        }
      ]
    },
    {
      id: "cat_filters_luts",
      name: "4. Bộ Lọc Màu Nghệ Thuật & 3D LUTs (Color Filters & LUTs)",
      nameEn: "Cinematic Color Grading & 3D LUTs",
      icon: "🎨",
      level: "con",
      subGroups: [
        {
          id: "sub_lut_categories",
          name: "127 Bảng Màu 3D LUTs Chuyên Nghiệp (127 Pro LUTs)",
          nameEn: "Color Grading Categories",
          level: "chau",
          tools: [
            {
              id: "tool_lut_portrait_glow",
              name: "Chân Dung Trong Trẻo (Portrait Natural Glow - 42 LUTs)",
              nameEn: "Portrait Skin Tone Presets",
              level: "chat",
              controlType: "Filter Carousel + Intensity Slider (0 - 100%)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyLutTexture(handle, String lutPath, float intensity)",
              description: "Tôn vinh làn da châu Á với tông trắng hồng mịn màng và ánh sáng tự nhiên."
            },
            {
              id: "tool_lut_retro_film",
              name: "Cổ Điển Film 35mm (Retro Vintage Film - 28 LUTs)",
              nameEn: "Vintage Analog Film Emulation",
              level: "chat",
              controlType: "Filter Carousel + Intensity Slider (0 - 100%)",
              isVip: true,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyLutTexture(handle, String lutPath, float intensity)",
              description: "Màu sắc hoài niệm thập niên 90 từ các cuộn phim Kodak Gold, Fuji Pro 400H."
            },
            {
              id: "tool_lut_cinematic_movie",
              name: "Điện Ảnh Hollywood & Hong Kong (Cinematic - 35 LUTs)",
              nameEn: "Hollywood Teal & Orange & Hong Kong Noir",
              level: "chat",
              controlType: "Filter Carousel + Intensity Slider (0 - 100%)",
              isVip: true,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyLutTexture(handle, String lutPath, float intensity)",
              description: "Tone màu Teal & Orange kinh điển và sắc màu điện ảnh Vương Gia Vệ lãng mạn."
            },
            {
              id: "tool_lut_scenery_food",
              name: "Ẩm Thực & Phong Cảnh HDR (Food & Landscape - 22 LUTs)",
              nameEn: "Vivid Scenery & Food Color Boost",
              level: "chat",
              controlType: "Filter Carousel + Intensity Slider (0 - 100%)",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeApplyLutTexture(handle, String lutPath, float intensity)",
              description: "Kích thích thị giác món ăn hấp dẫn và tôn sắc xanh thẳm của mây trời, biển biếc."
            }
          ]
        },
        {
          id: "sub_optical_effects",
          name: "Hiệu Ứng Quang Học & Bụi Phim (Film Optical FX)",
          nameEn: "Light Leaks, Dust & Prism Refraction",
          level: "chau",
          tools: [
            {
              id: "tool_light_leaks",
              name: "Lóa Sáng Hở Sáng Phim (Analog Light Leaks)",
              nameEn: "30+ Light Leak Overlays",
              level: "chat",
              controlType: "Overlay Selector + Blend Mode Toggle",
              isVip: true,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeApplyOverlayLayer(handle, int textureId, int blendMode, float alpha)",
              description: "Mô phỏng hiện tượng lọt sáng mép cuộn film tạo vệt cam đỏ nghệ thuật."
            },
            {
              id: "tool_dust_scratches",
              name: "Bụi Xước Cổ Điển (Vintage Dust & Scratches)",
              nameEn: "Film Scratches, Hair & Dust Particles",
              level: "chat",
              controlType: "Particle Texture Carousel",
              isVip: true,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeApplyOverlayLayer(handle, int textureId, 2, float alpha)",
              description: "Thêm các vệt xước xơ và hạt bụi thời gian lên bề mặt bức ảnh."
            }
          ]
        }
      ]
    },
    {
      id: "cat_ai_magic_tools",
      name: "5. Công Cụ Trí Tuệ Nhân Tạo (AI Magic & AIGC Engine)",
      nameEn: "AI Inpainting, Outpainting & Generation",
      icon: "🤖",
      level: "con",
      subGroups: [
        {
          id: "sub_ai_cleanup",
          name: "Xóa & Tách Nền Thông Minh (AI Cleanup & Matting)",
          nameEn: "Inpainting, Erasing & Auto Cutout",
          level: "chau",
          tools: [
            {
              id: "tool_ai_eraser_inpaint",
              name: "Xóa Vật Thể & Người Qua Đường (AI Eraser Inpainting)",
              nameEn: "Context-Aware Object & Passerby Eraser",
              level: "chat",
              controlType: "Brush Stroke & Lasso Selection",
              isVip: true,
              nativeLib: "libManis.so",
              jniMethod: "nativeRunInpaint(handle, byte[] maskData, int w, int h)",
              description: "Khoanh vùng người lạ hoặc rác thừa, AI tự động phân tích bối cảnh và bù đắp nền liền mạch."
            },
            {
              id: "tool_ai_human_cutout",
              name: "Tách Người 1 Chạm & Thay Đổi Hình Nền (AI Human Matting)",
              nameEn: "Sub-pixel Human Hair Cutout",
              level: "chat",
              controlType: "1-Tap Cutout + Background Preset Library",
              isVip: false,
              nativeLib: "libARSPM.so",
              jniMethod: "nativeSegmentHuman(handle, int inTexture, int outMaskTexture)",
              description: "Tách tóc và cơ thể người chính xác đến từng pixel con, ghép nền studio hoặc du lịch thế giới."
            }
          ]
        },
        {
          id: "sub_ai_generative",
          name: "Sáng Tạo Bằng Trí Tuệ Nhân Tạo (Generative AI & Enhancement)",
          nameEn: "Sky Swap, Expansion & Super Resolution",
          level: "chau",
          tools: [
            {
              id: "tool_ai_sky_replacement",
              name: "Thay Thế Bầu Trời Phép Màu (AI Sky Replacement)",
              nameEn: "Volumetric Sky Replacement & Relighting",
              level: "chat",
              controlType: "Sky Theme Carousel (Sunset, Galaxy, Aurora, Clouds)",
              isVip: true,
              nativeLib: "libManis.so",
              jniMethod: "nativeReplaceSky(handle, int skyIndex, float blendRatio)",
              description: "Biến bầu trời xám xịt thành hoàng hôn rực lửa hoặc dải ngân hà đầy sao lấp lánh."
            },
            {
              id: "tool_ai_outpainting_expand",
              name: "Mở Rộng Khung Hình AI (AI Outpainting & Canvas Expand)",
              nameEn: "Generative Outpainting & Edge Synthesis",
              level: "chat",
              controlType: "Canvas Drag Handles (Ratio Expand)",
              isVip: true,
              nativeLib: "libaicodec.so",
              jniMethod: "nativeRequestAIGCExpand(handle, float left, float top, float right, float bottom)",
              description: "AI tự động vẽ mở rộng ngoại cảnh xung quanh theo đúng phong cách và ánh sáng gốc."
            },
            {
              id: "tool_ai_super_resolution_4k",
              name: "Phục Hồi Nét Ảnh Cũ & Nâng Cấp 4K (AI Super Resolution)",
              nameEn: "4K Neural Upscaling & Detail Restorer",
              level: "chat",
              controlType: "1-Tap Enhance + Split Slider Comparison",
              isVip: true,
              nativeLib: "libManis.so",
              jniMethod: "nativeSuperResolution(handle, int scaleFactor)",
              description: "Tái tạo từng sợi tóc và con ngươi sắc nét từ ảnh mờ, ảnh chụp cũ thập niên trước."
            },
            {
              id: "tool_ai_cartoon_style",
              name: "Biến Ảnh Chân Dung Thành Anime / 3D Avatar (AI Cartoonify)",
              nameEn: "Anime, Claymation & 3D Pixar Avatar Styles",
              level: "chat",
              controlType: "Style Card Selector",
              isVip: true,
              nativeLib: "libfantasy.so",
              jniMethod: "nativeTransformArtisticStyle(handle, int styleId)",
              description: "Chuyển hóa ảnh người thật thành nhân vật hoạt hình Disney, Anime Nhật Bản hoặc tượng đất sét."
            }
          ]
        }
      ]
    },
    {
      id: "cat_stickers_text_decor",
      name: "6. Chữ Nghệ Thuật, Nhãn Dán & Bút Vẽ (Stickers, Text & Magic Brush)",
      nameEn: "Typography, Stickers & Doodle Brush",
      icon: "✨",
      level: "con",
      subGroups: [
        {
          id: "sub_text_typography",
          name: "Chữ Nghệ Thuật (Typography & 29 Custom Fonts)",
          nameEn: "Text Layouts & Font Styles",
          level: "chau",
          tools: [
            {
              id: "tool_text_font_library",
              name: "29 Phông Chữ Thiết Kế Độc Quyền (Sans, Serif, Handwriting, Calligraphy)",
              nameEn: "29 Proprietary TrueType Fonts",
              level: "chat",
              controlType: "Font Selector Ribbon + Text Editor Box",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeAddTextLayer(handle, String text, String fontPath, float size)",
              description: "Chèn phụ đề hoặc chữ ký nghệ thuật hỗ trợ đầy đủ bộ gõ tiếng Việt có dấu."
            },
            {
              id: "tool_text_styling_3d",
              name: "Kiểu Chữ 3D, Gradient & Đổ Bóng (3D Text, Stroke & Shadow)",
              nameEn: "3D Extrusion, Stroke & Gradient Fills",
              level: "chat",
              controlType: "Color Picker + Stroke Width Slider + Shadow Blur",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeSetTextStyle(handle, int layerId, String strokeHex, float strokeW)",
              description: "Tạo viền chữ nổi bật, bóng đổ mờ ảo và dải màu chuyển tiếp gradient phong cách poster."
            }
          ]
        },
        {
          id: "sub_stickers_doodle",
          name: "Nhãn Dán & Bút Vẽ Ma Thuật (Stickers & Magic Doodle)",
          nameEn: "Sticker Packs & Luminous Brushes",
          level: "chau",
          tools: [
            {
              id: "tool_stickers_packs",
              name: "Kho Hàng Ngàn Nhãn Dán Dễ Thương (Kawaii, Y2K, Phụ Kiện)",
              nameEn: "Sticker Packs & Dynamic Badges",
              level: "chat",
              controlType: "Sticker Category Browser + Transform Handles",
              isVip: false,
              nativeLib: "libglide-webp.so",
              jniMethod: "nativeAddSticker(handle, String stickerAssetPath, float x, float y)",
              description: "Chèn nơ, kính mát, mũ tai mèo và các biểu tượng cảm xúc độc đáo vào ảnh."
            },
            {
              id: "tool_magic_brush_glow",
              name: "Bút Vẽ Phát Sáng Neon & Sao Lấp Lánh (Magic Brush)",
              nameEn: "Neon Glow, Stardust & Heart Particle Brush",
              level: "chat",
              controlType: "Brush Particle Selector + Stroke Size Slider",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeDrawParticleStroke(handle, int particleType, float[] pathPoints)",
              description: "Vẽ các vệt sáng neon, bụi sao lung linh hoặc bong bóng xà phòng theo ngón tay di chuyển."
            },
            {
              id: "tool_mosaic_privacy",
              name: "Làm Mờ Mosaic & Che Bảo Mật (Pixelate & Pattern Mosaic)",
              nameEn: "Creative Pattern & Privacy Mosaic",
              level: "chat",
              controlType: "Brush Size Slider + Pattern Matrix",
              isVip: false,
              nativeLib: "libMTFilterKernel.so",
              jniMethod: "nativeDrawMosaic(handle, int patternId, float size, float[] points)",
              description: "Che biển số xe, thông tin nhạy cảm bằng họa tiết caro, hoa nhỏ hoặc hạt pixel."
            }
          ]
        }
      ]
    },
    {
      id: "cat_collage_frames",
      name: "7. Ghép Ảnh Đa Khung & Viền Ảnh (Collage Grid & Frame Layouts)",
      nameEn: "Multi-photo Collage, Scrapbook & Frames",
      icon: "🖼️",
      level: "con",
      subGroups: [
        {
          id: "sub_collage_layout",
          name: "Bố Cục Ghép Ảnh (Collage Grids)",
          nameEn: "Grid, Freeform & Filmstrip Collage",
          level: "chau",
          tools: [
            {
              id: "tool_grid_collage_2_to_9",
              name: "Ghép Lưới Từ 2 Đến 9 Ảnh (Smart Grid Layouts)",
              nameEn: "Dynamic Smart Grids (2-9 Photos)",
              level: "chat",
              controlType: "Grid Template Carousel + Border Margin Slider",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeCreateCollage(handle, int templateId, int[] textureIds)",
              description: "Tự động phân bố các bức ảnh vào bố cục lưới hiện đại, điều chỉnh khoảng cách viền."
            },
            {
              id: "tool_scrapbook_freeform",
              name: "Ghép Ảnh Tự Do Kiểu Cuốn Sổ Tay (Scrapbook Freeform)",
              nameEn: "Freeform Scrapbook Pinboard",
              level: "chat",
              controlType: "Free Drag, Rotate, Scale & Layer Stacking",
              isVip: true,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeAddScrapbookItem(handle, int textureId, float x, float y, float rot)",
              description: "Xếp lớp các bức ảnh ngẫu hứng với hiệu ứng băng keo dán giấy và góc xoay tự do."
            },
            {
              id: "tool_vertical_filmstrip",
              name: "Ghép Dọc Dạng Thước Phim Kỷ Niệm (Vertical Filmstrip)",
              nameEn: "Vertical Story & Filmstrip Roll",
              level: "chat",
              controlType: "Filmstrip Template Selector",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeGenerateFilmstrip(handle, int[] textures, int borderStyle)",
              description: "Nối liền các bức ảnh thành dải dài theo chiều dọc phù hợp đăng tải Story, Facebook và Pinterest."
            }
          ]
        },
        {
          id: "sub_frames_borders",
          name: "Khung Viền & Họa Tiết Nền (Frames & Canvas Background)",
          nameEn: "Polaroid Frames, Museum Borders & Wallpapers",
          level: "chau",
          tools: [
            {
              id: "tool_polaroid_frame",
              name: "Khung Ảnh Polaroid & Máy In Lấy Liền (Polaroid Borders)",
              nameEn: "Authentic Instant Polaroid Borders",
              level: "chat",
              controlType: "Frame Selector + Bottom Margin Note Editor",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeApplyFrame(handle, String frameAssetPath)",
              description: "Đóng khung ảnh giấy trắng polaroid cổ điển kèm khoảng trống viết chữ tay phía dưới."
            },
            {
              id: "tool_canvas_background_patterns",
              name: "Màu Nền & Họa Tiết Trang Trí (Canvas Gradient & Pattern)",
              nameEn: "Canvas Fill, Gradient & Pattern Wallpaper",
              level: "chat",
              controlType: "Color Swatch / Gradient / Pattern Selector",
              isVip: false,
              nativeLib: "libLayerFlow.so",
              jniMethod: "nativeSetCanvasBackground(handle, int type, String colorOrPattern)",
              description: "Mở rộng nền viền với màu pastel nhẹ nhàng hoặc họa tiết hoa nhí xinh xắn."
            }
          ]
        }
      ]
    }
  ]
};
