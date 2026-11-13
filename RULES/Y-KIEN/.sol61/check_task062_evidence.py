"""Independent read-only TASK062 fixture/math/integrity checks; never runs AGY code."""
import datetime as dt
import csv
import hashlib
import json
import math
from pathlib import Path
import re
import zipfile

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_062_REPORT"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def pixels(path, mode="RGB"):
    with Image.open(path) as img:
        return np.array(img.convert(mode))


def softlight(a, b):
    return np.where(b <= .5, 2*a*b + a*a*(1-2*b),
                    2*a*(1-b) + np.sqrt(np.maximum(0, a))*(2*b-1))


def main():
    standard = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
    result = {"at": dt.datetime.now(dt.timezone.utc).isoformat(),
              "command": "python -X utf8 -B RULES/Y-KIEN/.sol61/check_task062_evidence.py",
              "checker_sha256": sha(Path(__file__)),
              "standard": {"path": str(standard), "sha256": sha(standard)},
              "limits": "Host fixture/math/integrity only; no product execution, ground truth, device, build or acceptance."}
    manifest = []
    for line in (REPORT / "04_RAW_EVIDENCE_MANIFEST.sha256").read_text(encoding="utf-8-sig").splitlines():
        expected, relative = line.split(None, 1)
        path = ROOT / relative.strip()
        measured = sha(path) if path.is_file() else "MISSING"
        manifest.append({"path": relative, "expected": expected, "measured": measured, "match": expected == measured})
    result["manifest"] = manifest
    visual = REPORT / "VISUAL_EVIDENCE"
    with zipfile.ZipFile(REPORT / "TASK_062_DEMO.zip") as z:
        result["zip"] = {"crc_bad_member": z.testzip(), "entries": len(z.infolist()),
                         "members_match_visual_files": all(hashlib.sha256(z.read(n)).hexdigest() == sha(visual / n)
                                                          for n in z.namelist())}
    cases = []
    for label, key, dye, bleach in [("A", "owner_fail_A_curly", [.95, .45, .65], .65),
                                   ("B", "owner_fail_B_orig", [.95, .88, .65], .75)]:
        original = pixels(visual / (key + "_01_original.png"))
        raw = pixels(visual / (key + "_02_raw_mask.png"), "L")
        clamped = pixels(visual / (key + "_03_clamped_mask.png"), "L")
        after = pixels(visual / (key + "_04_recolored_softlight.png"))
        arr = original.astype(np.float32) / 255
        y = .299*arr[:,:,0] + .587*arr[:,:,1] + .114*arr[:,:,2]
        cr = (arr[:,:,0]-y)*.713 + .5
        cb = (arr[:,:,2]-y)*.564 + .5
        skin = (cr >= .52) & (cr <= .72) & (cb >= .33) & (cb <= .53) & (arr[:,:,0] > arr[:,:,2])
        exclusion = skin.copy()
        exclusion[int(original.shape[0]*.85):] = True
        alpha = raw.astype(np.float32) / 255
        alpha[exclusion] = 0
        base = arr*(1-bleach) + y[:,:,None]*bleach
        dyed = np.clip(softlight(base, np.array(dye, dtype=np.float32)), 0, 1)
        recreated = np.clip((arr*(1-alpha[:,:,None]) + dyed*alpha[:,:,None])*255, 0, 255).astype(np.uint8)
        positive_before, positive_after = int(np.count_nonzero(raw)), int(np.count_nonzero(clamped))
        case = {"case": label, "size_wh": [original.shape[1], original.shape[0]],
                "original_pixels_match_task061_fixture": np.array_equal(original, pixels(ROOT / f"RULES/REPORT/TASK_061_REPORT/07_REFERENCE_IMPL/owner_fail_{label}_input.png")),
                "raw_pixels_match_task061_fixture": np.array_equal(raw, pixels(ROOT / f"RULES/REPORT/TASK_061_REPORT/07_REFERENCE_IMPL/owner_fail_{label}_mask.png", "L")),
                "clamped_pixels_match_host_recreation": np.array_equal(clamped, (alpha*255).astype(np.uint8)),
                "after_pixels_match_host_recreation": np.array_equal(after, recreated),
                "max_rgb_delta_on_self_defined_skin": int(np.abs(after.astype(int)-original.astype(int))[skin].max()),
                "fixture_positive_pixel_retention_pct": 100*positive_after/positive_before,
                "fixture_mask_mass_retention_pct": 100*float(clamped.sum())/float(raw.sum()),
                "not_ground_truth_accuracy_or_strand_score": True}
        if label == "B":
            case["background_samples_xy"] = [{"xy": [x, yy], "original": original[yy,x].tolist(),
                                               "after": after[yy,x].tolist(), "raw_mask": int(raw[yy,x]),
                                               "clamped_mask": int(clamped[yy,x])}
                                              for x, yy in [(384,80),(100,300)]]
        cases.append(case)
    result["visual_fixtures"] = cases
    source = ROOT / "lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp"
    text = source.read_text(encoding="utf-8")
    v3 = text.split("bool HairPipelineV2::executePipelineV3_Rebuild(",1)[1].split("// Full Pipeline Dispatcher",1)[0]
    result["source_sha256"] = sha(source)
    result["v3_specularParams_occurrences_including_signature"] = v3.count("specularParams")
    result["math_samples"] = {"softlight_neutral_grid_max_error": float(np.max(np.abs(softlight(np.linspace(0,1,256),.5)-np.linspace(0,1,256)))),
                             "uniform_gray_bleach0_and1_same_output_A01_B08": [float(softlight(.1,.8)),float(softlight(.1,.8))],
                             "black_base_with_B08": float(softlight(0,.8)),
                             "deployed_mask_shader_excl096_hair09": min(.9,1-.96),
                             "cpp_strict_mask_excl096_hair09": 0}
    # Isolated gate predicate, not a reproduced device leak or full pipeline.
    r,g,b,x,yy,min_fy,cx,cy,fw,fh,forehead,chin = 180,130,110,100,99,100,100,150,100,100,100,200
    luminance = .299*r+.587*g+.114*b
    cr = (r-luminance)*.713+128
    cb = (b-luminance)*.564+128
    skin = r > 45 and g > 28 and b > 15 and ((130 <= cr <= 175 and 77 <= cb <= 130 and r > b)
                                         or (r > g and g >= b and r-g >= 5 and r-b >= 10))
    old_oval = ((x-cx)/(fw*.68+1))**2 + ((yy-cy)/(fh*.72+1))**2 <= 1 and forehead-.1*fh <= yy <= chin+.1*fh
    result["isolated_skin_gate_counterexample"] = {"rgb": [r,g,b], "xy": [x,yy], "isSkin": skin,
                                                  "old_oval_protects": bool(old_oval and skin),
                                                  "new_skin_predicate_protects": bool(skin and (yy > min_fy or abs(x-cx) > fw*.90)),
                                                  "label": 17, "hair_probability": .9,
                                                  "limit": "Predicate only; no full-pipeline or device leak claimed."}
    # Independently sample native-function coverage identities in unchanged
    # TASK061 evidence. Body availability/identity is not hair arithmetic proof.
    coverage = ROOT / "RULES/REPORT/TASK_061_REPORT/05_DECOMPILE_COVERAGE.csv"
    with coverage.open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    population = [row for row in rows if row["UsedInSpec"] == "YES" and "Ghidra" in row["Decompiled"]]
    count = math.ceil(len(population)*.10)
    selected = sorted(population, key=lambda row: hashlib.sha256((row["Target"]+row["Address"]).encode()).hexdigest())[:count]
    maps = {}
    for library in {row["Target"] for row in selected}:
        raw_path = ROOT / f".ai/reconstruction/evidence/TASK_061/ghidra_decompiled/{library}_decompiled.txt"
        raw_text = raw_path.read_text(encoding="utf-8", errors="replace")
        raw_sha = sha(raw_path)
        headers = list(re.finditer(r"^FUNCTION: (.*)\nADDRESS:\s*(0x[0-9a-fA-F]+)\nSIZE:\s*(\d+) bytes", raw_text, re.M))
        table = {}
        for index, match in enumerate(headers):
            end = headers[index+1].start() if index+1 < len(headers) else len(raw_text)
            section = raw_text[match.start():end]
            body = section.partition("DECOMPILED C BODY:")[2].split("="*80)[0].strip()
            table[int(match.group(2),16)] = {"raw_path": raw_path.relative_to(ROOT).as_posix(),
                                            "raw_sha256": raw_sha, "header_line": raw_text.count("\n",0,match.start())+1,
                                            "raw_function_name": match.group(1), "raw_size": int(match.group(3)),
                                            "body_present": bool(body), "body_chars": len(body),
                                            "failure_marker": "decompilation failed" in body.casefold()}
        maps[library] = table
    samples = []
    for row in selected:
        raw = maps[row["Target"]].get(int(row["Address"],16))
        samples.append({"target": row["Target"], "address": row["Address"],
                        "coverage_function_name": row["FunctionName"], "claimed_has_arithmetic": row["HasArithmetic"],
                        "raw": raw, "size_matches": bool(raw and raw["raw_size"] == int(row["SizeBytes"]))})
    result["task061_coverage_identity_sample"] = {"population": len(population), "sample_count": count,
                                                 "selection": "Lowest SHA256(Target+Address), fixed independent sample",
                                                 "scope": "Address/size/body availability only; HasArithmetic and algorithm/quality remain unproven by this check.",
                                                 "samples": samples}
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
