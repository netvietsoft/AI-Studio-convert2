#!/usr/bin/env python3
"""
scripts/forensics/extract_shaders.py
Extract verbatim GLSL shader bodies and parameters from libMTFilterKernel.so and related libs.
"""
from pathlib import Path
from elftools.elf.elffile import ELFFile

def extract_shaders():
    path = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so")
    with open(path, "rb") as f:
        elf = ELFFile(f)
        rodata = elf.get_section_by_name(".rodata")
        r_data = rodata.data()
        r_addr = rodata["sh_addr"]
        
        # In Initlize at 0x1342dc, we saw:
        # 0x13437c: vertex shader
        # 0x134384: gray fragment shader
        # 0x1343b0: vertex shader
        # 0x1343b8: hair mask fragment shader
        # 0x1343dc: vertex shader
        # 0x1343e4: blur H fragment shader
        # 0x134408: vertex shader
        # 0x134410: blur V fragment shader
        # 0x134434: vertex shader
        # 0x13443c: soft hair fragment shader
        
        # Let's search strings around these RVAs
        frags = [
            ("Gray / Hair Init", b"uniform sampler2D inputImageTexture"),
            ("Soft Hair Kernel", b"const int KERNEL_SIZE = 10;"),
            ("Blur Weights", b"uniform highp float Weights[5];"),
            ("Hair Mask Tensor", b"shiftingSize")
        ]
        
        found_strings = set()
        for label, frag in frags:
            pos = 0
            while True:
                idx = r_data.find(frag, pos)
                if idx == -1:
                    break
                start = r_data.rfind(b"\x00", 0, idx)
                start = 0 if start == -1 else start + 1
                end = r_data.find(b"\x00", idx)
                end = len(r_data) if end == -1 else end
                raw = r_data[start:end]
                try:
                    s = raw.decode("utf-8")
                    va = r_addr + start
                    if va not in found_strings:
                        found_strings.add(va)
                        print(f"==================================================")
                        print(f"[{label}] VA: {hex(va)}, Length: {len(s)}")
                        print(f"==================================================")
                        print(s)
                        print("\n")
                except Exception as e:
                    pass
                pos = idx + len(frag)

if __name__ == "__main__":
    extract_shaders()
