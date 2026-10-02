// DỮ LIỆU CÂY PHÂN CẤP ĐẦY ĐỦ 100% CỦA TẤT CẢ CÁC MODULE MEITU REBORN (CONVERT2)
// Cung cấp cấu trúc Cha ➜ Con ➜ Cháu ➜ Chắt ➜ Chút (JNI Native C++ & .so)

export const ALL_MODULES_DATA = {
  // ==========================================
  // MODULE: VIDEO EDIT (BIÊN TẬP VIDEO ĐA TRACK)
  // ==========================================
  videoedit: {
    id: "module_videoedit_root",
    name: "Biên Tập Video Đa Năng (Video Editor Engine)",
    nameEn: "Multi-Track Video Editor Core",
    icon: "🎬",
    totalFeatures: 48,
    vipCount: 22,
    freeCount: 26,
    jniModulesLinked: 12,
    categories: [
      {
        id: "vcat_timeline_cuts",
        name: "1. Timeline & Cắt Ghép Đa Lớp (Timeline & Clip Trimming)",
        nameEn: "Timeline Multi-track & Splicing",
        icon: "✂️",
        subGroups: [
          {
            id: "vsub_clip_tools",
            name: "Công Cụ Cắt Tách Clip (Split, Trim & Reorder)",
            nameEn: "Clip Splitting & Sequencing",
            tools: [
              {
                id: "vtool_split_cut",
                name: "Cắt Tách Đoạn Video Chính Xác Theo Frame (Split at Playhead)",
                nameEn: "Frame-Accurate Video Splicing",
                controlType: "Playhead Tap Split Button",
                isVip: false,
                nativeLib: "libffmpeg.so",
                jniMethod: "nativeSplitVideoTrack(handle, long timestampMs)",
                description: "Cắt rời clip video tại vị trí đầu đọc với độ chính xác đến từng mili-giây."
              },
              {
                id: "vtool_speed_curve",
                name: "Đường Cong Tốc Độ Chuyển Động (Speed Curve Ramp 0.1x - 100x)",
                nameEn: "Variable Speed Ramp & Optical Flow",
                controlType: "Interactive Speed Bezier Curve Editor",
                isVip: true,
                nativeLib: "libffmpeg.so",
                jniMethod: "nativeApplySpeedRamp(handle, float[] curvePoints, boolean opticalFlow)",
                description: "Tăng giảm tốc độ mượt mà kiểu Fast-Slow-Fast, bù frame bằng luồng quang học Optical Flow."
              },
              {
                id: "vtool_reverse_playback",
                name: "Đảo Ngược Khung Hình Video (Video Reversal FX)",
                nameEn: "Bidirectional Reverse Rendering",
                controlType: "1-Tap Toggle Button",
                isVip: false,
                nativeLib: "libffavc.so",
                jniMethod: "nativeReverseVideo(handle, String inPath, String outPath)",
                description: "Tua ngược video tạo hiệu ứng ma thuật thời gian tua lại."
              },
              {
                id: "vtool_freeze_frame",
                name: "Đóng Băng Khung Hình Ấn Tượng (Freeze Frame 1 - 10s)",
                nameEn: "Snapshot Frame Freezing",
                controlType: "Duration Slider (1s - 10s)",
                isVip: true,
                nativeLib: "libVERenderer.so",
                jniMethod: "nativeInsertFreezeFrame(handle, long timestamp, float durationSec)",
                description: "Tạm dừng chuyển động video trong vài giây làm nổi bật khoảnh khắc đắt giá."
              }
            ]
          }
        ]
      },
      {
        id: "vcat_transitions_fx",
        name: "2. Chuyển Cảnh & Kỹ Xảo Điện Ảnh (Transitions & Cinematic FX)",
        nameEn: "Transitions & Visual Special Effects",
        icon: "⚡",
        subGroups: [
          {
            id: "vsub_transitions",
            name: "Hiệu Ứng Chuyển Cảnh Mượt Mà (Transitions Library)",
            nameEn: "3D, Glitch & Optical Transitions",
            tools: [
              {
                id: "vtool_transition_seamless",
                name: "Chuyển Cảnh Mượt Mà Không Vết Ghép (Zoom In/Out, Wipe, Dissolve)",
                nameEn: "Seamless Motion Transitions (60+ Presets)",
                controlType: "Transition Carousel + Duration Slider",
                isVip: false,
                nativeLib: "libVERenderer.so",
                jniMethod: "nativeSetTransition(handle, int clipIndex, int transId, float duration)",
                description: "Kết nối 2 clip mượt mà với hiệu ứng phóng to, quét ngang, tan biến tự nhiên."
              },
              {
                id: "vtool_glitch_3d_cube",
                name: "Kỹ Xảo 3D Lập Phương & Nhiễu Sóng Glitch (Glitch & 3D Cube)",
                nameEn: "Glitch RGB Split & 3D Cube Rotation",
                controlType: "3D Transition Selector",
                isVip: true,
                nativeLib: "libarkernel3.so",
                jniMethod: "nativeApply3DTransition(handle, int effectType, float progress)",
                description: "Hiệu ứng xoay khối lập phương 3 chiều và giật sóng nhiễu điện tử Cyberpunk."
              }
            ]
          }
        ]
      },
      {
        id: "vcat_audio_music",
        name: "3. Âm Thanh, Nhạc Nền & Lồng Tiếng (Audio & Voice Suite)",
        nameEn: "Audio Mixing, Sound FX & Voiceover",
        icon: "🎵",
        subGroups: [
          {
            id: "vsub_audio_tools",
            name: "Hòa Âm & Tách Lời Bài Hát (Audio Engine)",
            nameEn: "Audio Track Processing",
            tools: [
              {
                id: "vtool_audio_extract",
                name: "Trích Xuất Âm Thanh Từ Video Khác (Audio Extractor)",
                nameEn: "Video-to-Audio MP3/AAC Ripper",
                controlType: "Select Video File Button",
                isVip: false,
                nativeLib: "libffmpeg.so",
                jniMethod: "nativeExtractAudioTrack(String videoPath, String outAudioPath)",
                description: "Tách lấy đoạn nhạc hoặc lời thoại từ bất kỳ video nào trong thư viện máy."
              },
              {
                id: "vtool_vocal_remover_ai",
                name: "Tách Giọng Hát Khỏi Nhạc Nền Bằng AI (AI Vocal Remover / Karaoke)",
                nameEn: "Deep Learning Vocal & Instrumental Splitter",
                controlType: "Vocal / Instrumental Volume Sliders",
                isVip: true,
                nativeLib: "libmfxkit.so",
                jniMethod: "nativeSeparateVocals(handle, String audioPath, float vocalVol, float instVol)",
                description: "Tách giọng ca sĩ ra khỏi giai điệu để biến bài hát thành bản nhạc không lời Karaoke."
              },
              {
                id: "vtool_voice_changer_fx",
                name: "Biến Đổi Giọng Nói Vui Nhộn (Voice Changer FX - Chipmunk, Robot, Deep)",
                nameEn: "Pitch Shifting & Formant Voice Modulation",
                controlType: "Voice Profile Selector",
                isVip: false,
                nativeLib: "libKKMusicFX.so",
                jniMethod: "nativeApplyVoiceModulation(handle, int profileId, float pitchShift)",
                description: "Đổi giọng người lồng tiếng thành giọng sóc chuột, giọng quái vật hoặc robot tương lai."
              }
            ]
          }
        ]
      },
      {
        id: "vcat_video_ai_matting",
        name: "4. Tách Nền Video AI & Phụ Đề Tự Động (AI Matting & Auto Captions)",
        nameEn: "AI Video Matting & Speech-to-Text",
        icon: "🤖",
        subGroups: [
          {
            id: "vsub_video_ai",
            name: "Tách Nền & Nhận Diện Giọng Nói",
            nameEn: "Smart AI Video Processing",
            tools: [
              {
                id: "vtool_video_human_matting",
                name: "Tách Người Không Cần Phông Xanh (AI Video Background Remover)",
                nameEn: "Real-time Neural Video Human Matting",
                controlType: "1-Tap Cutout + Video Background Library",
                isVip: true,
                nativeLib: "libARSPM.so",
                jniMethod: "nativeSegmentVideoBody(handle, long frameHandle, int maskTex)",
                description: "Tách rời toàn bộ người quay trong video và thay đổi cảnh nền vũ trụ, bãi biển thời gian thực."
              },
              {
                id: "vtool_auto_subtitles_speech",
                name: "Tự Động Tạo Phụ Đề Tiếng Việt Bằng Giọng Nói (Auto Speech-to-Text)",
                nameEn: "Automatic Speech Recognition & Subtitle Sync",
                controlType: "Language Selector + Subtitle Style Ribbon",
                isVip: true,
                nativeLib: "libManis.so",
                jniMethod: "nativeGenerateSubtitles(handle, String audioTrack, String langCode)",
                description: "Lắng nghe lời thoại trong video và tự động gõ chữ phụ đề đồng bộ chuẩn từng mili-giây."
              },
              {
                id: "vtool_video_export_4k",
                name: "Xuất Video Độ Phân Giải 4K 60FPS (Ultra HD 4K Exporter)",
                nameEn: "Hardware Accelerated 4K/60fps H.265 Rendering",
                controlType: "Resolution (720p, 1080p, 2K, 4K) & FPS (24, 30, 60) Picker",
                isVip: true,
                nativeLib: "libffavc.so",
                jniMethod: "nativeRenderExport(handle, String outPath, int width, int height, int fps, int bitrate)",
                description: "Mã hóa video tốc độ cao qua phần cứng MediaCodec, bảo toàn sắc nét không vỡ hạt."
              }
            ]
          }
        ]
      }
    ]
  },

  // ==========================================
  // MODULE: CAMERA AR & CHỤP ẢNH CHÂN DUNG
  // ==========================================
  camera: {
    id: "module_camera_root",
    name: "Camera AR & Chụp Ảnh Chân Dung (Real-Time AR Camera)",
    nameEn: "AR Camera & Real-Time Beauty Engine",
    icon: "📸",
    totalFeatures: 36,
    vipCount: 16,
    freeCount: 20,
    jniModulesLinked: 8,
    categories: [
      {
        id: "ccat_realtime_beauty",
        name: "1. Làm Đẹp Thời Gian Thực Khi Quay / Chụp (Live Beauty Stream)",
        nameEn: "Live Viewport Real-Time Retouch",
        icon: "💆‍♀️",
        subGroups: [
          {
            id: "csub_live_retouch",
            name: "Mịn Da & Gọt Mặt Trực Tiếp Trên Khung Hình Camera",
            nameEn: "Real-time 106-Point Facial Warping",
            tools: [
              {
                id: "ctool_live_skin_smooth",
                name: "Mịn Da Trực Tiếp Khi Nhìn Màn Hình (Real-Time Live Smoothing)",
                nameEn: "Live GPU Fragment Skin Softening",
                controlType: "Slider (0 - 100%)",
                isVip: false,
                nativeLib: "libarkernel3_android.so",
                jniMethod: "nativeSetCameraBeautySmooth(handle, int smoothLevel)",
                description: "Làm mịn da trực tiếp với tốc độ 60 khung hình/giây ngay trên màn hình xem trước."
              },
              {
                id: "ctool_live_face_slim",
                name: "Gọt Cằm V-Line & To Mắt Thời Gian Thực (Live Slim & Eye Enlarge)",
                nameEn: "Live 3D Vertex Warping",
                controlType: "Dual Slider (Slim & Eye Size)",
                isVip: false,
                nativeLib: "libarkernel3.so",
                jniMethod: "nativeSetCameraBeautyShape(handle, int slim, int eye)",
                description: "Nhận diện khuôn mặt cử động và tự động bóp cằm thon gọn, mắt to tròn sống động."
              },
              {
                id: "ctool_live_makeup_filters",
                name: "Đánh Son & Má Hồng Trực Tiếp Bằng AR (Live AR Makeup Stencils)",
                nameEn: "Real-Time Augmented Makeup Projection",
                controlType: "Preset Carousel (30 Looks)",
                isVip: true,
                nativeLib: "libarkernel3.so",
                jniMethod: "nativeApplyLiveMakeupLook(handle, String makeupId)",
                description: "Người dùng không cần trang điểm ngoài đời, camera tự động tô son môi và kẻ mắt sắc nét."
              }
            ]
          }
        ]
      },
      {
        id: "ccat_ar_stickers",
        name: "2. Mặt Nạ AR & Hiệu Ứng 3D Tương Tác (3D AR Face Masks)",
        nameEn: "Interactive 3D AR Masks & Morphing",
        icon: "✨",
        subGroups: [
          {
            id: "csub_ar_masks",
            name: "Mặt Nạ 3D Bám Chuyển Động Khuôn Mặt (3D Face Tracking)",
            nameEn: "Rigid & Deformable 3D AR Assets",
            tools: [
              {
                id: "ctool_interactive_stickers",
                name: "Nhãn Dán Tương Tác Há Miệng / Chớp Mắt (Triggered AR Stickers)",
                nameEn: "Expression-Triggered AR Animations",
                controlType: "Mask Browser (100+ Packs)",
                isVip: false,
                nativeLib: "libMTARMPM.so",
                jniMethod: "nativeLoadARStickerPackage(handle, String zipPath)",
                description: "Khi người dùng há miệng sẽ phun cầu vồng, khi nháy mắt sẽ bắn tim lấp lánh."
              },
              {
                id: "ctool_virtual_accessories_3d",
                name: "Phụ Kiện Kính Mát & Mũ 3D Siêu Thực (3D Realistic Accessories)",
                nameEn: "PBR Lighting Augmented Accessories",
                controlType: "Accessory Carousel",
                isVip: true,
                nativeLib: "libarkernel3.so",
                jniMethod: "nativeRender3DAccessory(handle, int modelId, float lightYaw)",
                description: "Đeo thử kính râm hàng hiệu và vương miện lấp lánh ánh kim chuyển động theo đầu."
              }
            ]
          }
        ]
      },
      {
        id: "ccat_pro_controls",
        name: "3. Chế Độ Chụp Chuyên Nghiệp & Chụp Đêm (Pro Manual & Night HDR)",
        nameEn: "Pro Manual Controls & Low-light HDR",
        icon: "🌙",
        subGroups: [
          {
            id: "csub_pro_camera",
            name: "Điều Khiển Thủ Công ISO & Màn Trập",
            nameEn: "Manual Exposure Calibration",
            tools: [
              {
                id: "ctool_night_super_hdr",
                name: "Chụp Đêm Siêu Sáng Đa Khung Hình (Night Mode Multi-Frame HDR)",
                nameEn: "Computational Low-Light Night Fusion",
                controlType: "Night Mode Toggle + Auto Exposure Hold",
                isVip: true,
                nativeLib: "libPVGLive.so",
                jniMethod: "nativeCaptureNightHDR(handle, int frameCount, float evStep)",
                description: "Chụp liên tiếp 8 khung hình phơi sáng khác nhau và ghép lại cho bức ảnh đêm trong vắt không nhiễu."
              },
              {
                id: "ctool_pro_manual_iso_shutter",
                name: "Tùy Chỉnh ISO, Shutter Speed & Lấy Nét Thủ Công (Pro DSLR Controls)",
                nameEn: "Camera2 API Manual Calibration",
                controlType: "Rotary Dial Controls (ISO 50-6400, Shutter 1/8000s - 30s)",
                isVip: true,
                nativeLib: "liblabdeviceinfo.so",
                jniMethod: "nativeConfigureCameraSensor(int iso, long exposureTimeNs, float focusDist)",
                description: "Biến camera điện thoại thành máy ảnh DSLR chuyên nghiệp chụp phơi sáng dải ngân hà."
              }
            ]
          }
        ]
      }
    ]
  },

  // ==========================================
  // MODULE: ROBONEO (TRỢ LÝ AI AGENT ENGINE)
  // ==========================================
  roboneo: {
    id: "module_roboneo_root",
    name: "Trợ Lý AI RoboNeo (Agent Beauty Engine)",
    nameEn: "RoboNeo Conversational AI Agent Core",
    icon: "💬",
    totalFeatures: 24,
    vipCount: 14,
    freeCount: 10,
    jniModulesLinked: 6,
    categories: [
      {
        id: "rcat_agent_persona",
        name: "1. Persona & Đàm Thoại Đa Tác Tử (Agent Persona & LLM)",
        nameEn: "LLM System Persona & Multi-Agent Planner",
        icon: "🧠",
        subGroups: [
          {
            id: "rsub_persona_config",
            name: "Cấu Hình Trí Tuệ & Tính Cách AI",
            nameEn: "Prompt Engineering & Capabilities",
            tools: [
              {
                id: "rtool_voice_command_edit",
                name: "Chỉnh Sửa Ảnh Bằng Lệnh Giọng Nói / Chat Tự Nhiên (Voice Photo Editing)",
                nameEn: "Natural Language Photo Manipulation Tool Calling",
                controlType: "Microphone Voice Input & Chat Console",
                isVip: true,
                nativeLib: "libManis.so",
                jniMethod: "nativeParseBeautyIntent(String prompt, float[] outParams)",
                description: "Người dùng chỉ cần nói 'Làm cho mặt thon lại một chút và tô son đỏ tươi', AI tự động kích hoạt thanh trượt."
              },
              {
                id: "rtool_skin_ai_diagnostics",
                name: "Chẩn Đoán Sắc Tố Da & Đề Xuất Công Thức Makeup Riêng (Skin Diagnostics AI)",
                nameEn: "106-Point Landmark Pigment & Texture Analyzer",
                controlType: "1-Tap Scan Face Diagnostics Report",
                isVip: false,
                nativeLib: "libaidetectionplugin.so",
                jniMethod: "nativeAnalyzeSkinCondition(handle, byte[] faceBuffer)",
                description: "AI quét phát hiện vùng da dầu, da khô hoặc nếp nhăn và đưa ra lộ trình làm đẹp chuẩn xác nhất."
              }
            ]
          }
        ]
      }
    ]
  },

  // ==========================================
  // MODULE: VIP PLANS (DOANH THU & GÓI CƯỚC)
  // ==========================================
  vip_plans: {
    id: "module_vip_plans_root",
    name: "Quản Lý Gói Cước & Doanh Thu VIP (VIP Plans & Monetization)",
    nameEn: "Subscription Plans & In-App Purchases Engine",
    icon: "👑",
    totalFeatures: 18,
    vipCount: 18,
    freeCount: 0,
    jniModulesLinked: 4,
    categories: [
      {
        id: "vpcat_sku_management",
        name: "1. Bảng Giá SKU & Phân Hạng Gói Cước (SKU & Pricing Matrix)",
        nameEn: "Google Play & App Store Billing SKUs",
        icon: "💳",
        subGroups: [
          {
            id: "vpsub_plans",
            name: "Danh Sách Gói Thuê Bao",
            nameEn: "Active Commercial Plans",
            tools: [
              {
                id: "vptool_yearly_plan",
                name: "Gói Meitu VIP 1 Năm (Siêu Tiết Kiệm 50%) — SKU: meitu_vip_yearly",
                nameEn: "1-Year Auto-Renewable Subscription ($29.99/year)",
                controlType: "Price & Discount Matrix Editor",
                isVip: true,
                nativeLib: "libCtaApiLib.so",
                jniMethod: "nativeVerifyReceiptSignature(String receiptData)",
                description: "Gói thuê bao bán chạy nhất, mở khóa toàn bộ 62 tính năng VIP và 127 bộ lọc độc quyền."
              },
              {
                id: "vptool_monthly_plan",
                name: "Gói Meitu VIP 1 Tháng — SKU: meitu_vip_monthly",
                nameEn: "1-Month Flexible Subscription ($4.99/month)",
                controlType: "Price & Trial Days Editor",
                isVip: true,
                nativeLib: "libCtaApiLib.so",
                jniMethod: "nativeCheckVipSubscriptionStatus(String userId)",
                description: "Gói thuê bao linh hoạt theo tháng cho người dùng trải nghiệm ngắn hạn."
              },
              {
                id: "vptool_lifetime_license",
                name: "Gói Meitu VIP Trọn Đời — SKU: meitu_vip_lifetime",
                nameEn: "Lifetime Non-Consumable License ($99.99 once)",
                controlType: "Permanent Key Generator",
                isVip: true,
                nativeLib: "libCtaApiLib.so",
                jniMethod: "nativeBindPermanentDevice(String deviceFingerprint)",
                description: "Sở hữu vĩnh viễn không bao giờ hết hạn kèm đặc quyền trải nghiệm sớm tính năng mới."
              }
            ]
          }
        ]
      }
    ]
  },

  // ==========================================
  // MODULE: API VAULT (KHO CHÌA KHÓA BẢO MẬT)
  // ==========================================
  api_vault: {
    id: "module_api_vault_root",
    name: "Kho Chìa Khóa API Vault & Bảo Mật (API Secret Vault)",
    nameEn: "Third-Party Credentials & Security Matrix",
    icon: "🔑",
    totalFeatures: 12,
    vipCount: 6,
    freeCount: 6,
    jniModulesLinked: 4,
    categories: [
      {
        id: "avcat_ai_keys",
        name: "1. Chìa Khóa Dịch Vụ AI Bên Thứ Ba (GenAI API Credentials)",
        nameEn: "Cloud GenAI Partner Integrations",
        icon: "🛡️",
        subGroups: [
          {
            id: "avsub_credentials",
            name: "Danh Sách Khóa Tích Hợp",
            nameEn: "Secured Credential Stores",
            tools: [
              {
                id: "avtool_deepseek_key",
                name: "DeepSeek LLM API Key (Bộ Não Đàm Thoại Trợ Lý RoboNeo)",
                nameEn: "DeepSeek Reasoning API Gateway",
                controlType: "Encrypted Password Field + Test Ping",
                isVip: true,
                nativeLib: "libCtaApiLib.so",
                jniMethod: "nativeEncryptApiKey(String rawKey)",
                description: "Mã hóa AES-256 lưu trữ an toàn, cung cấp trí tuệ nhân tạo cho cuộc trò chuyện RoboNeo."
              },
              {
                id: "avtool_runway_kling_key",
                name: "Runway Gen-3 & Kling AI Video Keys (Biến Ảnh Thành Video Chuyển Động)",
                nameEn: "Motion Video Synthesis Gateways",
                controlType: "API Key Masked Box",
                isVip: true,
                nativeLib: "libCtaApiLib.so",
                jniMethod: "nativeDispatchVideoTask(String prompt, String imgUrl)",
                description: "Cổng kết nối tạo video nghệ thuật từ ảnh chân dung tĩnh chất lượng điện ảnh."
              }
            ]
          }
        ]
      }
    ]
  }
};
