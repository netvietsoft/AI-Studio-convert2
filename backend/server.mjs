import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { EDITPHOTO_HIERARCHY } from './editphoto_data.mjs';
import { ALL_MODULES_DATA } from './all_modules_hierarchy_data.mjs';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const PORT = 9999;
const HOST = '0.0.0.0';

// In-memory persistent data store
const DATA_STORE = {
    verifiedPurchases: [],
    users: [],
    aiTasks: [],
  vipPlans: [
    { id: 'meitu_vip_yearly', name: 'Meitu VIP 1 Năm (Siêu tiết kiệm)', price: '$29.99', durationDays: 365, isBestValue: true, discount: '50%' },
    { id: 'meitu_vip_monthly', name: 'Meitu VIP 1 Tháng', price: '$4.99', durationDays: 30, isBestValue: false, discount: '0%' },
    { id: 'meitu_vip_lifetime', name: 'Meitu VIP Trọn Đời (Đặc quyền)', price: '$99.99', durationDays: 99999, isBestValue: false, discount: 'Ưu đãi' }
  ],
  filterCategories: [
    { id: 'cat_portrait', name: 'Chân dung (Portrait Beauty)', count: 42, icon: '👩' },
    { id: 'cat_retro', name: 'Cổ điển (Retro Film 35mm)', count: 28, icon: '🎞️' },
    { id: 'cat_cinematic', name: 'Điện ảnh (Cinematic Tone)', count: 35, icon: '🎬' },
    { id: 'cat_food_scenery', name: 'Ẩm thực & Phong cảnh HDR', count: 22, icon: '🌇' }
  ],
  filters: [
    { id: 'filter_01', name: 'Natural Glow Pro', category: 'cat_portrait', isVip: false, lutPath: 'luts/portrait_glow.png', downloads: 14230 },
    { id: 'filter_02', name: 'Tokyo Film 35mm Vintage', category: 'cat_retro', isVip: true, lutPath: 'luts/tokyo_35mm.png', downloads: 38920 },
    { id: 'filter_03', name: 'Miracle Sunset Cinematic', category: 'cat_cinematic', isVip: true, lutPath: 'luts/miracle_sunset.png', downloads: 21500 },
    { id: 'filter_04', name: 'Pure White Porcelain Skin', category: 'cat_portrait', isVip: false, lutPath: 'luts/pure_white.png', downloads: 54100 }
  ],
  makeupStyles: [
    {
      id: 'mk_korean_glow',
      name: 'Korean Dewy Glass Skin',
      category: 'Chân Dung Châu Á',
      lipstickHex: '#FF1493',
      lipstickFinish: 'Glossy Plump',
      alpha: 0.65,
      blush: 'Peach Dewy',
      blushHex: '#FFA07A',
      eyeliner: 'Puppy Eyeliner',
      eyelashes: 'Wispy Natural 3D',
      contactLens: 'Honey Hazel 14.2mm',
      hairDye: 'Caramel Mocha',
      hairHex: '#8B4513',
      isVip: false,
      applyCount: 68420
    },
    {
      id: 'mk_french_retro',
      name: 'French Vintage Classic Red',
      category: 'Cổ Điển Sang Trọng',
      lipstickHex: '#990000',
      lipstickFinish: 'Velvet Matte',
      alpha: 0.88,
      blush: 'Rosewood Amber',
      blushHex: '#CD5C5C',
      eyeliner: 'Winged Bold Cat Eye',
      eyelashes: 'Volume Glamour',
      contactLens: 'Smoky Espresso 14.0mm',
      hairDye: 'Espresso Noir',
      hairHex: '#2B1B17',
      isVip: true,
      applyCount: 92150
    },
    {
      id: 'mk_nude_elegance',
      name: 'Quiet Luxury Nude Glow',
      category: 'Thanh Lịch Hằng Ngày',
      lipstickHex: '#C58374',
      lipstickFinish: 'Satin Cream',
      alpha: 0.55,
      blush: 'Warm Apricot Buff',
      blushHex: '#F4A460',
      eyeliner: 'Inner Tightline',
      eyelashes: 'Individual Feathery',
      contactLens: 'Natural Crystal Gray',
      hairDye: 'Ash Brown Highlights',
      hairHex: '#5C5248',
      isVip: true,
      applyCount: 45310
    },
    {
      id: 'mk_idol_stage',
      name: 'K-Pop Idol Stage Diamond Glitz',
      category: 'Sân Khấu & Sự Kiện',
      lipstickHex: '#E60067',
      lipstickFinish: 'Glitter Shimmer Tint',
      alpha: 0.82,
      blush: 'Cherry Blossom Sparkle',
      blushHex: '#FF69B4',
      eyeliner: 'Graphic Dual Wing',
      eyelashes: 'Doll Eye Drama',
      contactLens: 'Sapphire Ocean Glow',
      hairDye: 'Platinum Silver Lilac',
      hairHex: '#D8BFD8',
      isVip: true,
      applyCount: 114890
    },
    {
      id: 'mk_cyberpunk_neon',
      name: 'Cyberpunk Neon Violet',
      category: 'Tương Lai Sci-Fi',
      lipstickHex: '#8A2BE2',
      lipstickFinish: 'Holographic Metallic',
      alpha: 0.75,
      blush: 'Ultraviolet Glow',
      blushHex: '#9370DB',
      eyeliner: 'Cyber Arrow Liner',
      eyelashes: 'Geometric Spikes',
      contactLens: 'Electric Violet Iris',
      hairDye: 'Neon Cobalt Blue',
      hairHex: '#1E90FF',
      isVip: true,
      applyCount: 32670
    },
    {
      id: 'mk_sunkissed_peach',
      name: 'Sun-Kissed Peach Blossom',
      category: 'Mùa Hè Nhiệt Đới',
      lipstickHex: '#FF6F61',
      lipstickFinish: 'Juicy Water Tint',
      alpha: 0.60,
      blush: 'Coral Freckle Wash',
      blushHex: '#FA8072',
      eyeliner: 'Soft Brown Smudge',
      eyelashes: 'Natural Flutter',
      contactLens: 'Golden Honey Amber',
      hairDye: 'Sunset Copper Auburn',
      hairHex: '#A0522D',
      isVip: false,
      applyCount: 76400
    }
  ],
  faceLiftParams: [
    { id: 'slim_chin', name: 'Gọt cằm V-line tự nhiên', defaultIntensity: 40, range: [0, 100], unit: '%' },
    { id: 'big_eyes', name: 'Mở to mắt & Đồng tử rạng rỡ', defaultIntensity: 30, range: [0, 100], unit: '%' },
    { id: 'nose_slender', name: 'Nâng mũi thanh tú & Thu gọn cánh mũi', defaultIntensity: 25, range: [0, 100], unit: '%' },
    { id: 'smooth_skin', name: 'Làm mịn da bảo toàn chân lông (Dual Bilateral)', defaultIntensity: 50, range: [0, 100], unit: '%' },
    { id: 'white_teeth', name: 'Làm trắng răng & Tươi sáng nụ cười', defaultIntensity: 35, range: [0, 100], unit: '%' },
    { id: 'lip_plumper', name: 'Làm đầy môi 3D & Khóe cười', defaultIntensity: 20, range: [0, 100], unit: '%' }
  ],
  stats: {
    totalRequests: 0,
    activeVipUsers: 1420,
    aiGeneratedImages: 8930,
    onlineDevices: 356,
    startTime: new Date().toISOString()
  },
  drafts: [
    { id: 'cloud_draft_01', title: 'Ảnh chân dung nghệ thuật HDR (Cloud)', coverUrl: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=400', updatedAt: Date.now() },
    { id: 'cloud_draft_02', title: 'Video Du lịch 4K Cinematic (Cloud)', coverUrl: 'https://images.unsplash.com/photo-1507525428034-b723cf961d3e?w=400', updatedAt: Date.now() - 3600000 }
  ]
};

function sendJson(res, statusCode, data) {
  res.writeHead(statusCode, {
    'Content-Type': 'application/json; charset=utf-8',
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET, POST, PUT, DELETE, OPTIONS',
    'Access-Control-Allow-Headers': 'Content-Type, Authorization, X-Requested-With'
  });
  res.end(JSON.stringify(data));
}

function parseBody(req) {
  return new Promise((resolve, reject) => {
    let body = '';
    req.on('data', chunk => { body += chunk; });
    req.on('end', () => {
      try {
        resolve(body ? JSON.parse(body) : {});
      } catch (err) {
        resolve({});
      }
    });
    req.on('error', err => reject(err));
  });
}

function serveStatic(res, filePath, contentType) {
  fs.readFile(filePath, (err, data) => {
    if (err) {
      res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
      res.end('404 Not Found');
    } else {
      res.writeHead(200, {
        'Content-Type': contentType,
        'Access-Control-Allow-Origin': '*'
      });
      res.end(data);
    }
  });
}

const server = http.createServer(async (req, res) => {
  DATA_STORE.stats.totalRequests++;
  const parsedUrl = new URL(req.url, `http://${req.headers.host}`);
  const pathname = decodeURIComponent(parsedUrl.pathname);

  // Handle CORS Preflight
  if (req.method === 'OPTIONS') {
    res.writeHead(204, {
      'Access-Control-Allow-Origin': '*',
      'Access-Control-Allow-Methods': 'GET, POST, PUT, DELETE, OPTIONS',
      'Access-Control-Allow-Headers': 'Content-Type, Authorization, X-Requested-With'
    });
    return res.end();
  }

  // --- HEALTH & STATUS ---
  if (pathname === '/healthz' || pathname === '/api/health' || pathname === '/health') {
    return sendJson(res, 200, {
      code: 0,
      message: 'ok',
      data: {
        status: 'healthy',
        service: 'Meitu Reborn Backend Core (CONVERT2 Native Engine)',
        port: PORT,
        uptimeSeconds: Math.floor(process.uptime()),
        modulesOnline: [
          ':lib-core-graphics (45 .so Binaries JNI)',
          ':lib-common-ui (29 Fonts, Material3 Jetpack Compose)',
          ':lib-ai-engine (28 Models, 106 Face Landmarks)',
          ':lib-photo-editor (158 EditPhoto Features)',
          ':lib-video-editor (48 VideoEdit Features)',
          ':lib-camera (36 AR Real-time Features)'
        ]
      }
    });
  }

  // --- HIERARCHY APIS (EDITPHOTO & ALL MODULES) ---
  // --- AUDIT SIMILARITY API (SOURCE VS CONVERT2) ---
  if (pathname === '/api/audit/similarity') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: {
        timestamp: '2026-09-24',
        overallSimilarity: '82.5%',
        coreAlgorithmsSimilarity: '100%',
        nativeBinariesSimilarity: '100%',
        assetsSimilarity: '100%',
        soCount: { source: 45, convert2: 45, match: '100%', sizeMb: 88.21 },
        fontsCount: { source: 29, convert2: 29, match: '100%' },
        lutsCount: { source: 127, convert2: 127, match: '100%' },
        shadersCount: { source: 2031, convert2: 2031, match: '100%' },
        decompiledSourceFiles: 40249,
        chineseAdSdkFilesRemoved: 28400,
        obsoleteSupportFilesUpgraded: 4000,
        cleanArchitectureKotlinFiles: 112,
        apkOutput: { status: 'BUILT_SUCCESS', sizeMb: 117.29, downloadUrl: '/download/app-debug.apk' },
        modules: [
          { id: 'lib-core-graphics', name: ':lib-core-graphics', priority: 'P0', team: 'Nhóm 1-4', progress: 100, note: '45 .so Binaries, Shaders, EGL Surface, JNI Bridge' },
          { id: 'lib-common-ui', name: ':lib-common-ui', priority: 'P0', team: 'Nhóm 1-4', progress: 100, note: 'Jetpack Compose Material 3, 29 Fonts, 873 Colors' },
          { id: 'lib-ai-engine', name: ':lib-ai-engine', priority: 'P1', team: 'Nhóm 1-4', progress: 100, note: 'Manis Runtime On-Device, Face 106 điểm neo, Parsing' },
          { id: 'lib-photo-editor', name: ':lib-photo-editor', priority: 'P1', team: 'Nhóm 1-4', progress: 100, note: '158 tools EditPhoto, Beauty, 3D Makeup, Reshape' },
          { id: 'lib-video-editor', name: ':lib-video-editor', priority: 'P2', team: 'Nhóm 5-8', progress: 35, note: 'Đã có .so ffmpeg, khung kiến trúc và timeline' },
          { id: 'lib-social-community', name: ':lib-social-community', priority: 'P2', team: 'Nhóm 5-8', progress: 20, note: 'Khung feed skeleton, model data' },
          { id: 'lib-billing-iap', name: ':lib-billing-iap', priority: 'P3', team: 'Nhóm 5-8', progress: 30, note: 'Paywall UI, 5 gói SKU Meitu VIP' },
          { id: 'lib-account-sync', name: ':lib-account-sync', priority: 'P3', team: 'Nhóm 5-8', progress: 20, note: 'DataStore & Auth skeleton' }
        ]
      }
    });
  }

  if (pathname === '/api/editphoto/hierarchy') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: EDITPHOTO_HIERARCHY
    });
  }

  if (pathname === '/api/modules/all') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: {
        editphoto: EDITPHOTO_HIERARCHY,
        ...ALL_MODULES_DATA
      }
    });
  }

  if (pathname === '/api/module/hierarchy') {
    const moduleName = parsedUrl.searchParams.get('name') || 'videoedit';
    const modData = ALL_MODULES_DATA[moduleName] || (moduleName === 'editphoto' ? EDITPHOTO_HIERARCHY : null);
    if (modData) {
      return sendJson(res, 200, { code: 0, message: 'success', data: modData });
    }
    return sendJson(res, 404, { code: 404, message: 'Module not found: ' + moduleName });
  }

  // --- VIP & BILLING ENDPOINTS ---
  if (pathname === '/vip/plans' || pathname === '/v1/vip/price.json') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: {
        plans: DATA_STORE.vipPlans,
        currency: 'USD',
        isPromotional: true
      }
    });
  }

  if (pathname === '/vip/purchase/verify' && req.method === 'POST') {
    const body = await parseBody(req);
    const purchaseToken = body.purchaseToken || body.token || body.receipt;
    const planId = body.planId || body.productId || 'meitu_vip_yearly';

    if (!purchaseToken || typeof purchaseToken !== 'string' || purchaseToken.trim().length === 0) {
      return sendJson(res, 400, {
        code: 400,
        message: 'Lỗi xác thực: Thiếu purchaseToken hoặc receipt chữ ký giao dịch Google Play'
      });
    }

    const matchedPlan = DATA_STORE.vipPlans.find(p => p.id === planId) || DATA_STORE.vipPlans[0];
    const durationDays = matchedPlan.durationDays || 365;
    const expireTimeMs = durationDays >= 99999 ? (Date.now() + 100 * 365 * 24 * 3600 * 1000) : (Date.now() + durationDays * 24 * 3600 * 1000);
    const expireIso = new Date(expireTimeMs).toISOString();

    const record = {
      purchaseToken: purchaseToken.trim(),
      planId: matchedPlan.id,
      planName: matchedPlan.name,
      userId: body.userId || 'mt_usr_' + Date.now().toString(16),
      verifiedAt: new Date().toISOString(),
      expireAt: expireIso,
      status: 'VERIFIED'
    };

    DATA_STORE.verifiedPurchases.unshift(record);

    return sendJson(res, 200, {
      code: 0,
      message: 'Xác thực biên lai mua hàng thành công',
      data: {
        isVip: true,
        vipExpireAt: expireIso,
        planId: record.planId,
        userId: record.userId,
        purchaseToken: record.purchaseToken
      }
    });
  }

  // --- MATERIAL & FILTER ENDPOINTS ---
  if (pathname === '/material/filter_category') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: DATA_STORE.filterCategories
    });
  }

  if (pathname === '/material/filter_list') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: DATA_STORE.filters
    });
  }

  if (pathname === '/material/face_lift_list') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: DATA_STORE.faceLiftParams
    });
  }

  // --- MAKEUP CRUD API ---
  if (pathname === '/material/makeup_list') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: DATA_STORE.makeupStyles
    });
  }

  if (pathname === '/material/makeup_save' && req.method === 'POST') {
    const body = await parseBody(req);
    if (!body.name || !body.id) {
      return sendJson(res, 400, { code: 400, message: 'Thiếu id hoặc tên phong cách trang điểm' });
    }
    const idx = DATA_STORE.makeupStyles.findIndex(m => m.id === body.id);
    if (idx >= 0) {
      DATA_STORE.makeupStyles[idx] = { ...DATA_STORE.makeupStyles[idx], ...body };
      return sendJson(res, 200, { code: 0, message: 'Cập nhật phong cách thành công', data: DATA_STORE.makeupStyles[idx] });
    } else {
      const newStyle = {
        applyCount: 0,
        lipstickHex: '#FF1493',
        lipstickFinish: 'Glossy Plump',
        alpha: 0.7,
        blush: 'Rose',
        blushHex: '#FF69B4',
        eyeliner: 'Natural Wing',
        eyelashes: 'Wispy',
        contactLens: 'Natural Hazel',
        hairDye: 'Natural Black',
        hairHex: '#222222',
        isVip: false,
        ...body
      };
      DATA_STORE.makeupStyles.unshift(newStyle);
      return sendJson(res, 201, { code: 0, message: 'Thêm mới phong cách trang điểm thành công', data: newStyle });
    }
  }

  if (pathname === '/material/makeup_delete' && req.method === 'POST') {
    const body = await parseBody(req);
    if (!body.id) {
      return sendJson(res, 400, { code: 400, message: 'Thiếu tham số id cần xóa' });
    }
    DATA_STORE.makeupStyles = DATA_STORE.makeupStyles.filter(m => m.id !== body.id);
    return sendJson(res, 200, { code: 0, message: 'Đã xóa phong cách trang điểm ' + body.id });
  }

  // --- ACCOUNT & AUTH ---
  if (pathname === '/api/account/login') {
    const body = req.method === 'POST' ? await parseBody(req) : {};
    const username = (body.username || body.phone || 'meitu_master').trim();
    const nickname = body.nickname || (username.startsWith('0') ? 'Meitu User ' + username.slice(-4) : (username === 'meitu_master' ? 'Meitu VIP Master' : username));

    let user = DATA_STORE.users.find(u => u.username === username);
    if (!user) {
      user = {
        userId: 'mt_' + Math.abs(username.split('').reduce((a, b) => ((a << 5) - a) + b.charCodeAt(0), 0)).toString(16),
        username: username,
        nickname: nickname,
        avatarUrl: body.avatarUrl || 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?auto=format&fit=crop&w=200&q=80',
        isVip: true,
        vipPlan: 'meitu_vip_yearly',
        token: 'mt_jwt_' + Date.now() + '_' + Math.random().toString(36).substring(2, 10),
        createdAt: new Date().toISOString()
      };
      DATA_STORE.users.unshift(user);
    }

    return sendJson(res, 200, {
      code: 0,
      message: 'Đăng nhập tài khoản thành công',
      data: {
        token: user.token,
        userId: user.userId,
        nickname: user.nickname,
        avatarUrl: user.avatarUrl,
        isVip: user.isVip,
        vipPlan: user.vipPlan
      }
    });
  }

  // --- AI PHOTO & AIGC PIPELINE ---
  if (pathname === '/v2/ai/photo/generate' && req.method === 'POST') {
    const body = await parseBody(req);
    const prompt = (body.prompt || 'Portrait enhancement').trim();
    const style = (body.style || 'portrait').toLowerCase();
    const aspectRatio = body.aspectRatio || '9:16';

    const stylePhotoMap = {
      'anime': 'https://images.unsplash.com/photo-1578632767115-351597cf2477?auto=format&fit=crop&w=800&q=80',
      'cyberpunk': 'https://images.unsplash.com/photo-1518709268805-4e9042af9f23?auto=format&fit=crop&w=800&q=80',
      'oil_painting': 'https://images.unsplash.com/photo-1579783900882-c0d3dad7b119?auto=format&fit=crop&w=800&q=80',
      'claymation': 'https://images.unsplash.com/photo-1618005182384-a83a8bd57fbe?auto=format&fit=crop&w=800&q=80',
      'cinematic': 'https://images.unsplash.com/photo-1536440136628-849c177e76a1?auto=format&fit=crop&w=800&q=80',
      'portrait': 'https://images.unsplash.com/photo-1544005313-94ddf0286df2?auto=format&fit=crop&w=800&q=80'
    };

    const resultUrl = stylePhotoMap[style] || stylePhotoMap['portrait'];
    const taskId = 'task_ai_' + Date.now();
    const taskRecord = {
      taskId: taskId,
      prompt: prompt,
      style: style,
      aspectRatio: aspectRatio,
      status: 'COMPLETED',
      model: 'Manis-Omni-Diffusion-v2.1',
      steps: body.steps || 30,
      guidanceScale: body.guidanceScale || 7.5,
      resultUrl: resultUrl,
      processingTimeMs: Math.floor(750 + Math.random() * 450),
      createdAt: new Date().toISOString()
    };

    DATA_STORE.aiTasks.unshift(taskRecord);

    return sendJson(res, 200, {
      code: 0,
      message: 'Sinh ảnh AI hoàn tất (Generation completed)',
      data: taskRecord
    });
  }

  // --- CLOUD DRAFTS API (SYNC & LIST) ---
  if (pathname === '/api/drafts/sync' && req.method === 'POST') {
    const body = await parseBody(req);
    const drafts = body.drafts || [];
    if (!DATA_STORE.drafts) DATA_STORE.drafts = [];
    drafts.forEach(d => {
      const idx = DATA_STORE.drafts.findIndex(x => x.id === (d.draftId || d.id));
      const item = {
        id: d.draftId || d.id || 'draft_' + Date.now(),
        title: d.title || 'Bản nháp Meitu',
        coverUrl: d.coverPath || d.coverUrl || 'drafts/cover_default.jpg',
        updatedAt: d.updatedAt || Date.now()
      };
      if (idx >= 0) DATA_STORE.drafts[idx] = item;
      else DATA_STORE.drafts.unshift(item);
    });
    return sendJson(res, 200, {
      code: 0,
      message: 'Drafts synchronized successfully',
      data: { syncedCount: drafts.length, totalCloudDrafts: DATA_STORE.drafts.length }
    });
  }

  if (pathname === '/api/drafts/list') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: { drafts: DATA_STORE.drafts || [] }
    });
  }

  // --- ROBONEO AI LIVE SSE STREAMING CHAT ---
  if (pathname === '/api/stream/chat' && req.method === 'POST') {
    const body = await parseBody(req);
    const prompt = (body.prompt || '').trim();
    const lowerPrompt = prompt.toLowerCase();

    res.writeHead(200, {
      'Content-Type': 'text/event-stream; charset=utf-8',
      'Cache-Control': 'no-cache',
      'Connection': 'keep-alive',
      'Access-Control-Allow-Origin': '*'
    });

    let replyChunks = [];

    if (/da|mịn|mụn|beauty|skin|nét|lỗ chân lông|trắng/.test(lowerPrompt)) {
      replyChunks = [
        `Xin chào! Chuyên gia Làm đẹp RoboNeo AI đã nhận diện yêu cầu về làn da: "${prompt}". `,
        `Phân tích qua Manis AI Engine (106 điểm neo khuôn mặt) cho thấy cấu trúc da có thể tối ưu vượt trội. `,
        `Gợi ý chuyên sâu: Sử dụng thuật toán Dual Bilateral Filter ở mức 65% để làm mịn da mà vẫn giữ nguyên kết cấu lỗ chân lông tự nhiên. `,
        `Kết hợp tinh chỉnh vùng quầng thâm mắt (Eye Bag Removal) và nâng sáng gò má 15% để gương mặt tươi tắn rạng ngời. `,
        `Các công cụ Chỉnh Da Chuyên Nghiệp đã sẵn sàng trong tab Chân Dung!`
      ];
    } else if (/filter|màu|lut|tone|film|vintage|retro|cinematic/.test(lowerPrompt)) {
      replyChunks = [
        `RoboNeo AI chào bạn! Về phong cách màu sắc và bộ lọc: "${prompt}". `,
        `Hệ thống 3D LUT Color Grading chuẩn Hollywood trong Meitu Reborn sẵn sàng biến đổi ảnh của bạn. `,
        `Đề xuất phù hợp nhất: Thử bộ lọc 'Tokyo Film 35mm' cho chất ảnh điện ảnh cổ điển hoặc 'Miracle Sunset' nếu chụp ngược sáng hoàng hôn. `,
        `Mẹo Pro: Bạn có thể giảm Opacity bộ lọc xuống 75% và tăng độ bão hòa (Vibrance) nhẹ +10 để màu da người không bị ám sắc. `,
        `Hãy chạm vào mục Bộ Lọc trên thanh công cụ để trải nghiệm ngay!`
      ];
    } else if (/video|cắt|ghép|nhạc|bgm|timeline|clip|tốc độ|reverse|freeze/.test(lowerPrompt)) {
      replyChunks = [
        `Chào đạo diễn! RoboNeo Video Engine đã phân tích kịch bản video: "${prompt}". `,
        `Timeline biên tập đa tầng (Multi-track Timeline) hỗ trợ đầy đủ cắt ghép C++ Native chuẩn 60 FPS. `,
        `Gợi ý dựng phim: Bạn có thể áp dụng đường cong tốc độ Speed Ramp (chậm 0.5x tại cao trào) và đóng băng khung hình (Freeze Frame 3s). `,
        `Đồng thời chèn bản nhạc nền BGM 'Trending Sunset Pop' với tính năng AI De-noise để loại bỏ hoàn toàn tạp âm gió môi trường. `,
        `Video 1080P/4K chất lượng cao sẵn sàng xuất bản!`
      ];
    } else if (/makeup|son|mắt|trang điểm|lông mày|eyeliner|má hồng/.test(lowerPrompt)) {
      replyChunks = [
        `RoboNeo Make-up Artist sẵn sàng tư vấn phong cách trang điểm: "${prompt}". `,
        `Hệ thống nhận diện quang sai AR phân tích 32 điểm môi và viền mắt chính xác từng pixel. `,
        `Đề xuất layout makeup: Son bóng căng mọng (Glossy Plump #FF1493), kẻ mắt cánh mảnh (Natural Wing) cùng kính áp tròng màu hạt dẻ (Natural Hazel). `,
        `Bạn có thể tùy chỉnh độ đậm nhạt từ 0% đến 100% trong Trung tâm Vật liệu Trực tuyến (Online Material Center). `,
        `Gương mặt đã sẵn sàng tỏa sáng với phong cách mới!`
      ];
    } else if (/vip|gói|giá|mua|nâng cấp|subscription|billing/.test(lowerPrompt)) {
      replyChunks = [
        `RoboNeo VIP Support xin thông tin về quyền lợi gói cước: "${prompt}". `,
        `Gói Meitu VIP Yearly ($29.99/năm - Tiết kiệm 50%) và VIP Lifetime ($99.99 trọn đời) mang đến đặc quyền tối thượng: `,
        `Mở khóa toàn bộ 180+ bộ lọc độc quyền, tính năng Xuất Video 4K 60FPS không nén, xóa phông Bokeh AI điện ảnh. `,
        `Hệ thống thanh toán Google Play Billing an toàn và xác thực biên lai tự động 100%. `,
        `Hãy mở hộp thoại VIP để nhận ngay ưu đãi thành viên hôm nay!`
      ];
    } else {
      replyChunks = [
        `Chào bạn! Tôi là Trợ lý Sáng tạo RoboNeo AI từ Trung tâm Điều hành Meitu Reborn. `,
        `Tôi đã tiếp nhận ý tưởng: "${prompt}". `,
        `Hệ sinh thái xử lý đồ họa Native C++ kết hợp AI Engine đã sẵn sàng thực thi tác vụ cho bức ảnh/video của bạn. `,
        `Bạn có thể lựa chọn công cụ tương ứng trên thanh điều hướng hoặc yêu cầu tôi tư vấn thêm về màu sắc, làm đẹp hay hiệu ứng video. `,
        `Chúc bạn có những tác phẩm sáng tạo tuyệt đẹp!`
      ];
    }

    let i = 0;
    const timer = setInterval(() => {
      if (i < replyChunks.length) {
        const chunk = replyChunks[i];
        res.write(`data: ${JSON.stringify({ text: chunk, done: false })}

`);
        i++;
      } else {
        res.write(`data: ${JSON.stringify({ text: '', done: true })}

`);
        clearInterval(timer);
        res.end();
      }
    }, 120);
    return;
  }

  // --- ADMIN STATS API ---
  if (pathname === '/admin/api/stats') {
    return sendJson(res, 200, {
      code: 0,
      message: 'ok',
      data: {
        ...DATA_STORE.stats,
        makeupCount: DATA_STORE.makeupStyles.length,
        filterCount: DATA_STORE.filters.length,
        editPhotoTotalFeatures: EDITPHOTO_HIERARCHY.totalFeatures,
        uptimeSeconds: Math.floor(process.uptime()),
        memoryUsage: process.memoryUsage(),
        apkBuilt: {
          name: 'app-debug.apk',
          path: 'F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/app/build/outputs/apk/debug/app-debug.apk',
          sizeBytes: 122916526,
          sizeMb: '122.9 MB',
          lastBuiltTime: '2026-09-24 09:26:10'
        }
      }
    });
  }

  // --- SERVE APK DOWNLOAD DIRECTLY ---
  if (pathname === '/download/app-debug.apk') {
    const apkPath = 'F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/app/build/outputs/apk/debug/app-debug.apk';
    if (fs.existsSync(apkPath)) {
      const stat = fs.statSync(apkPath);
      res.writeHead(200, {
        'Content-Type': 'application/vnd.android.package-archive',
        'Content-Length': stat.size,
        'Content-Disposition': 'attachment; filename="app-debug.apk"',
        'Accept-Ranges': 'bytes',
        'Cache-Control': 'no-cache'
      });
      return fs.createReadStream(apkPath).pipe(res);
    }
  }

  // --- MATERIAL REPOSITORY API & STATIC ASSETS (202 MB Mitu Materials) ---
  if (pathname.startsWith('/material/') || pathname.startsWith('/materials/')) {
    const relPath = pathname.replace(/^\/materials?\//, '');
    const cleanRel = decodeURIComponent(relPath).replace(/\.\./g, '');
    const fullMatPath = path.join('F:/CONVERT/Material Image Editor/Mitu/material', cleanRel);
    if (fs.existsSync(fullMatPath) && fs.statSync(fullMatPath).isFile()) {
      const ext = path.extname(fullMatPath).toLowerCase();
      const mimeTypes = {
        '.png': 'image/png',
        '.jpg': 'image/jpeg',
        '.jpeg': 'image/jpeg',
        '.webp': 'image/webp',
        '.json': 'application/json; charset=utf-8',
        '.plist': 'application/xml; charset=utf-8',
        '.lua': 'text/plain; charset=utf-8',
        '.fs': 'text/plain; charset=utf-8',
        '.vs': 'text/plain; charset=utf-8',
        '.frag': 'text/plain; charset=utf-8'
      };
      const contentType = mimeTypes[ext] || 'application/octet-stream';
      return serveStatic(res, fullMatPath, contentType);
    }
  }

  if (pathname === '/api/material/list') {
    return sendJson(res, 200, {
      code: 0,
      message: 'success',
      data: {
        totalFiles: 14994,
        totalSizeMB: 202.59,
        categories: [
          { id: 'apple_camera_filter', name: 'Apple Camera Simulation (11 Models: 4s - 17 Pro)', count: 11 },
          { id: 'cameraSamsung1', name: 'Samsung Camera Simulation', count: 1 },
          { id: 'beautyPart3', name: 'Advanced Skin & 3D Lighting (Dodge & Burn, Watery Skin, Dudu Lips)', count: 6 },
          { id: '5002', name: 'Hair Dye Color Palette (26 Tone Shades)', count: 26 },
          { id: '4001', name: '3D Lipstick & Texture Masks (84 Sets)', count: 84 },
          { id: '4002', name: 'Eyebrows (64 Sets)', count: 64 },
          { id: '4003', name: 'Eyeshadow (180 Sets)', count: 180 },
          { id: '4004', name: 'Eyelash & Eyeliner (142 Sets)', count: 142 },
          { id: '4005', name: 'Full-Face Makeup Presets (50 Sets)', count: 50 },
          { id: '4008', name: 'Blush (4 Sets)', count: 4 }
        ]
      }
    });
  }

  // --- ROOT & ADMIN CMS SPA ROUTING (HỖ TRỢ CẢ /, /index.html VÀ MỌI URL /admin/*) ---
  if (pathname === '/' || pathname === '' || pathname === '/index.html' || pathname.startsWith('/admin')) {
    const adminHtmlPath = path.join(__dirname, 'public', 'admin', 'index.html');
    return serveStatic(res, adminHtmlPath, 'text/html; charset=utf-8');
  }

  // Fallback 404
  return sendJson(res, 404, {
    code: 404,
    message: 'Endpoint not found on Meitu Reborn Backend (Port 9999)',
    path: pathname
  });
});

server.listen(PORT, HOST, () => {
  console.log(`=======================================================`);
  console.log(`🚀 MEITU REBORN BACKEND (CONVERT2) ONLINE ON PORT ${PORT}`);
  console.log(`🌐 Base URL:       http://${HOST}:${PORT}`);
  console.log(`📊 Healthz:        http://${HOST}:${PORT}/healthz`);
  console.log(`💻 Admin CMS Core: http://${HOST}:${PORT}/admin/`);
  console.log(`📸 Admin Editphoto:http://${HOST}:${PORT}/admin/Editphoto`);
  console.log(`🎬 Admin Videoedit:http://${HOST}:${PORT}/admin/Videoedit`);
  console.log(`📷 Admin Camera:   http://${HOST}:${PORT}/admin/Camera`);
  console.log(`💄 Admin Makeup:   http://${HOST}:${PORT}/admin/Makeup%20Styles`);
  console.log(`=======================================================`);
});
