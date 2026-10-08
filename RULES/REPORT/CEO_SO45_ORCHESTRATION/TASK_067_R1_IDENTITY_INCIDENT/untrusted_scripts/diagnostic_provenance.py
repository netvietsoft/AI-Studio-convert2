"""Diagnostic reproduction and provenance verification (Investigation 3).

Analyzes:
1. Original APK C2 literal SoftLight_Fcn vs R3 invented blendColor block.
2. Verified rational arithmetic counterexample (69/512 vs 5/32, delta 11/512).
3. Ground-truth NE.manis APK path/hash vs reported non-existent path.
4. libManis.so 288 Manis keyword hits vs 303 total defined symbols.
5. Ghidra application.properties parsed metadata vs R3 hardcoded string.
6. Native Paseo scheduler receipts and execution states.
"""

import hashlib
import json
import pathlib
import re
import zipfile
from fractions import Fraction as F
from typing import Dict, Any, List


def analyze_softlight_shader(apk_path: pathlib.Path) -> Dict[str, Any]:
    """Extracts and analyzes MTFilter_PsSoftLightr.fs from original APK."""
    entry_path = "assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs"
    key = bytes.fromhex("7c34b93a")

    with zipfile.ZipFile(apk_path) as z:
        raw_bytes = z.read(entry_path)

    decoded_bytes = bytes(b ^ key[i % 4] for i, b in enumerate(raw_bytes))
    decoded_text = decoded_bytes.decode("utf-8", errors="replace")
    decoded_lines = decoded_text.splitlines()

    # Lines 13-26 verbatim in actual shader
    verbatim_actual_lines = decoded_lines[12:26]  # 0-indexed: lines 13-26
    verbatim_actual_text = "\n".join(verbatim_actual_lines)

    # R3 invented block (from scripts/task063_r3/generate_deliverables_r3.py:802-815)
    r3_claimed_text = """highp float blendColor(highp float a, highp float b)
{
    highp float c = 0.0;
    if (b <= 0.5)
    {
        c = 2.0 * a * b + a * a * (1.0 - 2.0 * b);
    }
    else
    {
        c = 2.0 * a * (1.0 - b) + sqrt(a) * (2.0 * b - 1.0);
    }
    return c;
}"""

    # Rational math check
    A = F(1, 16)
    B = F(3, 4)
    # W3C SoftLight
    D = ((16 * A - 12) * A + 4) * A  # D(1/16) = 53/256
    w3c = A + (2 * B - 1) * (D - A)   # 69/512
    # Meitu Shader
    shader = 2 * A * (1 - B) + F(1, 4) * (2 * B - 1)  # 5/32
    diff = shader - w3c  # 11/512

    return {
        "apk_path": str(apk_path),
        "entry_path": entry_path,
        "raw_bytes_len": len(raw_bytes),
        "raw_sha256": hashlib.sha256(raw_bytes).hexdigest(),
        "xor_key_hex": key.hex(),
        "decoded_bytes_len": len(decoded_bytes),
        "decoded_sha256": hashlib.sha256(decoded_bytes).hexdigest(),
        "actual_function_name": "SoftLight_Fcn",
        "r3_claimed_function_name": "blendColor",
        "actual_lines_13_26": verbatim_actual_lines,
        "r3_claimed_block": r3_claimed_text,
        "discrepancies": [
            "Function name altered: SoftLight_Fcn -> blendColor",
            "Parameter types altered: float -> highp float",
            "Parameter names altered: A, B -> a, b",
            "Variable types altered: float C -> highp float c",
            "Branch 1 expression rewritten: A * B / 0.5 -> 2.0 * a * b",
            "Branch 2 expression rewritten: A * (1.0 - B) / 0.5 -> 2.0 * a * (1.0 - b)",
            "R3 falsely labeled rewritten/invented block as 'Verbatim Shader Formulation (lines 13-26)'",
        ],
        "rational_math": {
            "test_inputs": {"A": str(A), "B": str(B)},
            "w3c_D_A": str(D),
            "w3c_softlight": str(w3c),
            "w3c_decimal": float(w3c),
            "meitu_shader": str(shader),
            "meitu_decimal": float(shader),
            "exact_difference": str(diff),
            "difference_decimal": float(diff),
            "w3c_equivalence_disproven": diff != 0,
        },
    }


def analyze_model_asset_paths(apk_path: pathlib.Path) -> Dict[str, Any]:
    """Verifies actual model paths in APK vs reported paths."""
    with zipfile.ZipFile(apk_path) as z:
        names = z.namelist()

        # Check actual NE.manis
        actual_ne_path = "assets/vlaimodel/libmtskinphone/Models/NE.manis"
        actual_exists = actual_ne_path in names
        actual_bytes = z.read(actual_ne_path) if actual_exists else b""

        # Check false reported path
        false_ne_path = "assets/vlaimodel/libmtface/models/NE.manis"
        false_exists = false_ne_path in names

        # Find all mtface parsing models
        mtface_models = [
            {"entry": n, "bytes": len(z.read(n)), "sha256": hashlib.sha256(z.read(n)).hexdigest()}
            for n in names if "mtface_parsing" in n
        ]

    return {
        "actual_ne_path": actual_ne_path,
        "actual_ne_exists_in_apk": actual_exists,
        "actual_ne_bytes": len(actual_bytes),
        "actual_ne_sha256": hashlib.sha256(actual_bytes).hexdigest() if actual_exists else "",
        "false_reported_ne_path": false_ne_path,
        "false_reported_ne_exists_in_apk": false_exists,
        "mtface_parsing_models_found": mtface_models,
        "path_conclusion": (
            "NE.manis resides exclusively at assets/vlaimodel/libmtskinphone/Models/NE.manis. "
            "The path reported in R3 (assets/vlaimodel/libmtface/models/NE.manis) does not exist."
        ),
    }


def analyze_libmanis_symbols(readelf_path: pathlib.Path) -> Dict[str, Any]:
    """Analyzes readelf symbol table of libManis.so."""
    text = readelf_path.read_text(encoding="utf-8-sig")
    sym_re = re.compile(
        r"^\s*\d+:\s+([0-9a-f]+)\s+(\d+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(.*)$",
        re.IGNORECASE,
    )

    all_symbols = []
    for line in text.splitlines():
        if m := sym_re.match(line):
            value, size, st_type, bind, vis, ndx, name = m.groups()
            all_symbols.append({
                "value": value,
                "size": int(size),
                "type": st_type,
                "bind": bind,
                "vis": vis,
                "ndx": ndx,
                "name": name,
                "is_defined": (ndx != "UND" and int(value, 16) != 0),
                "mentions_manis": "manis" in name.lower(),
            })

    total_symbols = len(all_symbols)
    defined_symbols = [s for s in all_symbols if s["is_defined"]]
    manis_symbols = [s for s in all_symbols if s["mentions_manis"]]
    manis_defined = [s for s in defined_symbols if s["mentions_manis"]]
    manis_und = [s for s in manis_symbols if not s["is_defined"]]
    non_manis_defined = [s for s in defined_symbols if not s["mentions_manis"]]

    return {
        "readelf_file": str(readelf_path),
        "total_symbols_parsed": total_symbols,
        "total_defined_symbols_count": len(defined_symbols),
        "manis_keyword_all_count": len(manis_symbols),
        "manis_keyword_defined_count": len(manis_defined),
        "manis_keyword_import_count": len(manis_und),
        "non_manis_defined_count": len(non_manis_defined),
        "sample_non_manis_defined_symbols": [s["name"] for s in non_manis_defined[:5]],
        "r3_claim": "303 defined symbols mentioning Manis",
        "actual_ground_truth": (
            f"Exactly {len(manis_defined)} defined symbols mention Manis. "
            f"303 is the total defined symbol count (including {len(non_manis_defined)} "
            f"symbols that do not mention Manis)."
        ),
    }


def parse_ghidra_properties(props_path: pathlib.Path) -> Dict[str, Any]:
    """Parses Ghidra application.properties directly."""
    if not props_path.exists():
        return {"error": f"File not found: {props_path}"}

    props = {}
    for line in props_path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        if "=" in line:
            k, v = line.split("=", 1)
            props[k.strip()] = v.strip()

    version = props.get("application.version", "")
    release = props.get("application.release.name", "")
    build_date = props.get("application.build.date", "")
    rev = props.get("application.revision.ghidra", "")

    synthesized_version = f"{version}_{release} (Build: {build_date}, Rev: {rev})"

    return {
        "properties_path": str(props_path),
        "sha256": hashlib.sha256(props_path.read_bytes()).hexdigest(),
        "parsed_properties": {
            "application.name": props.get("application.name"),
            "application.version": version,
            "application.release.name": release,
            "application.build.date": build_date,
            "application.revision.ghidra": rev,
            "application.layout.version": props.get("application.layout.version"),
        },
        "synthesized_version_string": synthesized_version,
        "r3_hardcoded_literal": "12.1.4_PUBLIC (Build: 2026-Sep-21 1613 UTC, Rev: 8b6bbb857accdfa20dc5b2f5dea471178c2e9fbc)",
        "matches_parsed": (
            synthesized_version == "12.1.4_PUBLIC (Build: 2026-Sep-21 1613 UTC, Rev: 8b6bbb857accdfa20dc5b2f5dea471178c2e9fbc)"
        ),
    }


def analyze_native_schedules() -> List[Dict[str, Any]]:
    """Inspects native Paseo schedules from ~/.paseo/schedules/."""
    schedules_dir = pathlib.Path.home() / ".paseo/schedules"
    results = []
    if not schedules_dir.exists():
        return results

    for p in sorted(schedules_dir.glob("*.json")):
        try:
            data = json.loads(p.read_text(encoding="utf-8"))
            runs = data.get("runs", [])
            recent_runs = []
            for r in runs[-5:]:
                recent_runs.append({
                    "run_id": r.get("id"),
                    "scheduledFor": r.get("scheduledFor"),
                    "startedAt": r.get("startedAt"),
                    "endedAt": r.get("endedAt"),
                    "status": r.get("status"),
                    "error_summary": (r.get("error") or "")[:200] if r.get("error") else None,
                })
            results.append({
                "schedule_id": p.stem,
                "path": str(p),
                "sha256": hashlib.sha256(p.read_bytes()).hexdigest(),
                "status": data.get("status"),
                "target": data.get("target"),
                "cron": data.get("cron"),
                "recent_runs": recent_runs,
            })
        except Exception as exc:
            results.append({"schedule_id": p.stem, "error": str(exc)})

    return results
