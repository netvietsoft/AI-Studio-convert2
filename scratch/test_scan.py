#!/usr/bin/env python3
import os
import sys
import json
import csv
import hashlib
import time
from pathlib import Path

ROOT = Path(r"F:\CONVERT")
REPO_ROOT = Path(r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2")
CONVERT2_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")

print(f"Scanning root: {ROOT}")
if not ROOT.exists():
    print("ERROR: ROOT does not exist!")
    sys.exit(1)

# List direct children
direct_children = list(ROOT.iterdir())
print(f"Direct children count: {len(direct_children)}")
for child in direct_children:
    print(f" - {child.name} ({'DIR' if child.is_dir() else 'FILE'})")

