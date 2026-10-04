import os
import re
import urllib.request

html_path = r"C:\Users\PC.DESKTOP-81LIH38\.gemini\antigravity-cli\brain\75c01faf-d2b3-4e3f-92c3-d78a32e6483c\.system_generated\steps\135\content.md"
with open(html_path, "r", encoding="utf-8") as f:
    text = f.read()

imgs = re.findall(r'<img[^>]+src=["\']([^"\']+)["\']', text)
print(f"Found {len(imgs)} images")
os.makedirs("scratch/owner_evidence", exist_ok=True)
for i, url in enumerate(imgs):
    print(f"Image {i}: {url[:80]}...")
    out_file = f"scratch/owner_evidence/owner_evidence_{i}.png"
    try:
        urllib.request.urlretrieve(url, out_file)
        print(f"Saved to {out_file}, size={os.path.getsize(out_file)} bytes")
    except Exception as e:
        print(f"Failed to download {i}: {e}")
