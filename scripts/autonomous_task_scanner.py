"""
CONVERT2 Autonomous Task Scanner
Authority: Chairman Tony
Mandate:
- Task Intake: F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\RULES\\TASK
- Task Report: F:\\CONVERT\\com.mt.mtxx.mtxx\\CONVERT2\\RULES\\REPORT
- Scanning cycle: 60s
"""

import os
import sys
import json
import zipfile
import re
import xml.etree.ElementTree as ET
from datetime import datetime, timezone, timedelta
from pathlib import Path

REPO_ROOT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2")
TASK_DIR = REPO_ROOT / "RULES" / "TASK"
REPORT_DIR = REPO_ROOT / "RULES" / "REPORT"
AI_REPORTS_DIR = REPO_ROOT / ".ai" / "reports"
STATE_FILE = REPO_ROOT / ".ai" / "state.json"
SCAN_LOG_FILE = REPO_ROOT / ".ai" / "task_scanner.log"

VN_TZ = timezone(timedelta(hours=7))

def get_docx_text(path):
    try:
        with zipfile.ZipFile(path) as z:
            xml_content = z.read("word/document.xml")
        tree = ET.fromstring(xml_content)
        namespaces = {"w": "http://schemas.openxmlformats.org/wordprocessingml/2006/main"}
        paragraphs = []
        for p in tree.iterfind(".//w:p", namespaces):
            texts = [node.text for node in p.iterfind(".//w:t", namespaces) if node.text]
            if texts:
                paragraphs.append("".join(texts))
        return "\n".join(paragraphs)
    except Exception:
        return ""

def extract_task_number(name):
    m = re.search(r"TASK_?(\d+)", name, re.IGNORECASE)
    if m:
        return int(m.group(1))
    return -1

def scan_for_active_task():
    now_str = datetime.now(VN_TZ).isoformat()
    if not STATE_FILE.exists():
        state = {}
    else:
        with open(STATE_FILE, "r", encoding="utf-8") as fp:
            state = json.load(fp)

    last_completed = state.get("last_completed_task_id", "")
    last_num = extract_task_number(last_completed)
    
    # Also find the highest completed task directory in RULES/REPORT
    highest_report_num = 60
    if REPORT_DIR.exists():
        for r_name in os.listdir(REPORT_DIR):
            n = extract_task_number(r_name)
            if n > highest_report_num:
                highest_report_num = n
    if last_num < highest_report_num:
        last_num = highest_report_num

    candidates = []
    for f in os.listdir(TASK_DIR):
        if (f.endswith(".docx") or f.endswith(".md")) and "TASK" in f.upper() and not f.startswith(("00","01","02","03","04","05","06","07","LEGACY")):
            p = TASK_DIR / f
            mtime = p.stat().st_mtime
            t_num = extract_task_number(f)

            if f.endswith(".docx"):
                text = get_docx_text(p)
            else:
                with open(p, "r", encoding="utf-8", errors="ignore") as fp:
                    text = fp.read()

            status = "UNKNOWN"
            priority = "NORMAL"
            for line in text.split("\n")[:20]:
                if "STATUS:" in line.upper():
                    status = line.split(":", 1)[1].strip().strip("*").strip()
                if "PRIORITY:" in line.upper():
                    priority = line.split(":", 1)[1].strip().strip("*").strip()

            candidates.append({
                "file": f,
                "path": str(p),
                "mtime": mtime,
                "task_num": t_num,
                "task_id": f.replace(".docx", "").replace(".md", ""),
                "status": status,
                "priority": priority
            })

    candidates.sort(key=lambda x: x["mtime"], reverse=True)

    # Check for NEW active tasks (task_num > last_num or newer modified time)
    new_active = []
    for c in candidates:
        if "ACTIVE" in c["status"].upper() and c["task_num"] > 0:
            # Check if already completed in lifecycle or earlier sequence
            is_completed = False
            task_key_3 = f"TASK_{c['task_num']:03d}_COMPLETED"
            task_key_2 = f"TASK_{c['task_num']}_COMPLETED"
            if task_key_3 in state.get("task_lifecycle", {}) or task_key_2 in state.get("task_lifecycle", {}):
                is_completed = True
            elif c["task_num"] <= last_num:
                is_completed = True

            # Check if this task already has a report in RULES/REPORT or .ai/reports
            report_dir = None
            for rdir in [REPORT_DIR, AI_REPORTS_DIR]:
                if rdir.exists():
                    for item in os.listdir(rdir):
                        if (f"TASK_{c['task_num']:03d}" in item.upper() or f"TASK_{c['task_num']}" in item.upper()):
                            report_dir = rdir / item
                            is_completed = True
                            break
                    if report_dir:
                        break
            
            if is_completed and report_dir and report_dir.exists():
                # Report already exists. Check if task file was updated AFTER the report was generated
                report_mtime = report_dir.stat().st_mtime
                if c["mtime"] > (report_mtime + 10): # 10s tolerance
                    # Task was revised after report was submitted
                    new_active.append(c)
            elif not is_completed and c["task_num"] > last_num:
                # Strictly new task
                new_active.append(c)

    log_entry = f"[{now_str}] Autonomous Scanner Check. Last completed task: TASK_{last_num:03d}.\n"
    if new_active:
        log_entry += f"  -> NEW ACTIVE TASK DETECTED: {new_active[0]['task_id']} (Priority: {new_active[0]['priority']})\n"
    else:
        log_entry += f"  -> IDLE_WAIT_FOR_TASK: All tasks up to TASK_{last_num:03d} are fully completed and packaged in RULES/REPORT.\n"

    SCAN_LOG_FILE.parent.mkdir(parents=True, exist_ok=True)
    with open(SCAN_LOG_FILE, "a", encoding="utf-8") as fp:
        fp.write(log_entry)

    print(log_entry.strip())
    return new_active

if __name__ == "__main__":
    scan_for_active_task()
