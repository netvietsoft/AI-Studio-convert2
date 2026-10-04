#!/usr/bin/env python3
"""
TASK_040 Full Discovery & Forensic Classification Script
Target: F:\CONVERT root tree
"""

import os
import sys
import json
import csv
import hashlib
import time
import subprocess
from pathlib import Path
from collections import defaultdict, Counter
import re

ROOT = Path(r"F:\CONVERT")
REPO_ROOT = Path(r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2")
CONVERT2_LOCAL = REPO_ROOT

print(f"Starting TASK_040 discovery script on root: {ROOT}")

# Let's inspect git repos in F:\CONVERT
def check_git_repo(path: Path):
    git_dir = path / ".git"
    if not git_dir.exists():
        return False, None, None, None
    try:
        # Get HEAD commit
        p_head = subprocess.run(["git", "rev-parse", "HEAD"], cwd=str(path), capture_output=True, text=True, timeout=5)
        head = p_head.stdout.strip() if p_head.returncode == 0 else None
        
        # Get branch
        p_branch = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], cwd=str(path), capture_output=True, text=True, timeout=5)
        branch = p_branch.stdout.strip() if p_branch.returncode == 0 else None

        # Get remote
        p_remote = subprocess.run(["git", "remote", "-v"], cwd=str(path), capture_output=True, text=True, timeout=5)
        remote = p_remote.stdout.strip().splitlines()[0] if p_remote.returncode == 0 and p_remote.stdout.strip() else None

        return True, head, branch, remote
    except Exception as e:
        return True, f"ERROR: {e}", None, None

# Test git check
for d in [ROOT / "com.mt.mtxx.mtxx" / "CONVERT", ROOT / "com.mt.mtxx.mtxx" / "CONVERT2", ROOT / "com.lightricks.facetune.free" / "CONVERT"]:
    if d.exists():
        is_git, head, branch, remote = check_git_repo(d)
        print(f"Git check for {d}: is_git={is_git}, branch={branch}, head={head[:8] if head else None}, remote={remote}")
