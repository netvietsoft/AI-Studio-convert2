"""Diagnostic reproduction and parser analysis for retained objdump disassembly samples (Investigation 2).

Demonstrates the regex failure in R3 scripts where --no-show-raw-insn suppressed instruction bytes,
causing 44 intact libraries to report zero instructions. Recounts 5 existing 1500-line raw samples,
categorizes line types, extracts literal representative lines, and defines a durable command receipt schema.
"""

import hashlib
import json
import re
from pathlib import Path
from typing import Dict, Any, List


ARITH_MNEMONICS = {
    "fadd", "fsub", "fmul", "fdiv", "fmla", "fmls", "fneg", "fabs",
    "fsqrt", "fcvtzs", "fcvtzu", "scvtf", "ucvtf", "fmax", "fmin",
    "madd", "msub", "sdiv", "udiv"
}

# R3 Buggy Regex: required 8-hex raw instruction bytes
R3_BUGGY_INS_RE = re.compile(r"^[ ]*[0-9a-f]+:\s+[0-9a-f]{8}\s+([a-z0-9.]+)", re.IGNORECASE)

# Corrected Regex: handles --no-show-raw-insn format (address: \s+ mnemonic)
CORRECTED_INS_RE = re.compile(r"^\s*[0-9a-f]+:\s+([a-z][a-z0-9.]*)\b", re.IGNORECASE)

# Regex for function / section labels: e.g. "00000000000ce7a0 <.text>:"
LABEL_RE = re.compile(r"^[0-9a-f]+\s+<([^>]+)>:\s*$", re.IGNORECASE)

# Header patterns
HEADER_RE = re.compile(r"(file format|Disassembly of section)", re.IGNORECASE)


def analyze_sample_file(path: Path) -> Dict[str, Any]:
    """Analyzes a single 1500-line objdump sample file."""
    text = path.read_text(encoding="utf-8-sig")
    lines = text.splitlines()

    r3_matches = []
    corrected_matches = []
    labels = []
    headers = []
    blank_lines = []
    unknown_lines = []

    for idx, line in enumerate(lines, start=1):
        if not line.strip():
            blank_lines.append((idx, line))
            continue

        if m := R3_BUGGY_INS_RE.match(line):
            r3_matches.append((idx, line, m.group(1).lower()))

        if m := CORRECTED_INS_RE.match(line):
            mnemonic = m.group(1).lower()
            is_arith = mnemonic in ARITH_MNEMONICS
            corrected_matches.append({
                "line_no": idx,
                "raw": line,
                "mnemonic": mnemonic,
                "is_arithmetic": is_arith,
            })
        elif m := LABEL_RE.match(line):
            labels.append((idx, line, m.group(1)))
        elif HEADER_RE.search(line):
            headers.append((idx, line))
        else:
            unknown_lines.append((idx, line))

    arith_instructions = [m for m in corrected_matches if m["is_arithmetic"]]

    return {
        "file_name": path.name,
        "total_lines": len(lines),
        "sha256": hashlib.sha256(text.encode("utf-8")).hexdigest(),
        "r3_regex_matched_count": len(r3_matches),
        "corrected_regex_instruction_count": len(corrected_matches),
        "corrected_arithmetic_count": len(arith_instructions),
        "labels_count": len(labels),
        "headers_count": len(headers),
        "blank_lines_count": len(blank_lines),
        "unknown_lines_count": len(unknown_lines),
        "representative_lines": {
            "r3_failing_instruction_lines": [
                {"line_no": m["line_no"], "raw": m["raw"], "parsed_mnemonic": m["mnemonic"]}
                for m in corrected_matches[:5]
            ],
            "arithmetic_instruction_lines": [
                {"line_no": m["line_no"], "raw": m["raw"], "parsed_mnemonic": m["mnemonic"]}
                for m in arith_instructions[:5]
            ],
            "label_lines": [
                {"line_no": l[0], "raw": l[1], "symbol": l[2]}
                for l in labels[:3]
            ],
            "header_lines": [
                {"line_no": h[0], "raw": h[1]}
                for h in headers[:3]
            ],
        },
    }


def get_command_receipt_schema() -> Dict[str, Any]:
    """Returns the proposed durable machine-readable command receipt schema."""
    return {
        "$schema": "https://json-schema.org/draft/2020-12/schema",
        "title": "DurableCommandExecutionReceipt",
        "description": "Standardized schema for recording binary tool execution, full outputs, and retained samples",
        "type": "object",
        "required": [
            "command",
            "working_directory",
            "started_at",
            "ended_at",
            "duration_ms",
            "exit_code",
            "tool_metadata",
            "input_files",
            "stdout_provenance",
            "stderr_provenance",
        ],
        "properties": {
            "command": {
                "type": "array",
                "items": {"type": "string"},
                "description": "Exact argument array passed to subprocess",
            },
            "working_directory": {"type": "string"},
            "started_at": {"type": "string", "format": "date-time"},
            "ended_at": {"type": "string", "format": "date-time"},
            "duration_ms": {"type": "number"},
            "exit_code": {"type": "integer"},
            "tool_metadata": {
                "type": "object",
                "required": ["path", "sha256", "version"],
                "properties": {
                    "path": {"type": "string"},
                    "sha256": {"type": "string"},
                    "version": {"type": "string"},
                },
            },
            "input_files": {
                "type": "array",
                "items": {
                    "type": "object",
                    "required": ["path", "sha256", "bytes"],
                    "properties": {
                        "path": {"type": "string"},
                        "sha256": {"type": "string"},
                        "bytes": {"type": "integer"},
                    },
                },
            },
            "stdout_provenance": {
                "type": "object",
                "required": [
                    "full_bytes",
                    "full_sha256",
                    "retained_path",
                    "retained_bytes",
                    "retained_sha256",
                    "retention_policy",
                ],
                "properties": {
                    "full_bytes": {"type": "integer"},
                    "full_sha256": {"type": "string"},
                    "retained_path": {"type": "string"},
                    "retained_bytes": {"type": "integer"},
                    "retained_sha256": {"type": "string"},
                    "retention_policy": {
                        "type": "string",
                        "enum": ["FULL", "HEAD_1500_LINES", "TAIL", "SAMPLED"],
                    },
                },
            },
            "stderr_provenance": {
                "type": "object",
                "required": ["retained_path", "bytes", "sha256"],
                "properties": {
                    "retained_path": {"type": "string"},
                    "bytes": {"type": "integer"},
                    "sha256": {"type": "string"},
                },
            },
        },
    }
