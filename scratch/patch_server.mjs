import fs from 'node:fs';

const filePath = 'backend/server.mjs';
let content = fs.readFileSync(filePath, 'utf8');

const target = '  // --- ROOT & ADMIN CMS SPA ROUTING';

const addition = `  // --- MATERIAL REPOSITORY API & STATIC ASSETS (202 MB Mitu Materials) ---
  if (pathname.startsWith('/material/') || pathname.startsWith('/materials/')) {
    const relPath = pathname.replace(/^\\/materials?\\//, '');
    const cleanRel = decodeURIComponent(relPath).replace(/\\.\\./g, '');
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

  // --- ROOT & ADMIN CMS SPA ROUTING`;

if (content.includes(target)) {
  content = content.replace(target, addition);
  fs.writeFileSync(filePath, content, 'utf8');
  console.log('✅ Successfully patched backend/server.mjs');
} else {
  console.log('❌ Target not found in backend/server.mjs');
}
