# 03_REMEDIATION_RECOMMENDATION.md — Concrete Repair Specifications
**Task ID:** `TASK_067` (Revision 1)  
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Scope:** Remediation proposals for any future baseline task authorized by CEO disposition. Not applied to TASK_063.  

---

## 1. Unified Container Classifier Remediation

### Proposed Python Diff:
```python
def classify_zip_entry(container_bytes: bytes, header_offset: int, disk_bytes: bytes, container_total_len: int) -> dict:
    if header_offset + 30 > len(container_bytes):
        return {"status": "CORRUPTED_HEADER", "valid": False}
    
    sig, ver, flags, method, mtime, mdate, crc, comp, decl, nlen, elen = struct.unpack_from(
        "<IHHHHHIIIHH", container_bytes, header_offset
    )
    if sig != 0x04034B50:
        return {"status": "CORRUPTED_HEADER", "valid": False}
    
    # 1. Gate on unsupported flags (e.g. bit 3 data descriptor)
    if flags != 0:
        return {"status": "UNSUPPORTED_FLAGS", "valid": False}
    
    # 2. Gate on compression method (must be STORED = 0)
    if method != 0 or comp != decl:
        return {"status": "UNSUPPORTED_COMPRESSION", "valid": False}
    
    data_offset = header_offset + 30 + nlen + elen
    available = min(decl, len(container_bytes) - data_offset)
    payload = container_bytes[data_offset:data_offset + available]
    is_complete = (data_offset + decl <= len(container_bytes))
    
    # 3. Gate complete entries on declared size, CRC32, and exact on-disk byte equality
    if is_complete:
        calc_crc = zlib.crc32(payload) & 0xffffffff
        if calc_crc != crc:
            return {"status": "CORRUPTED_CRC", "valid": False}
        if payload != disk_bytes:
            return {"status": "PAYLOAD_MISMATCH", "valid": False}
        return {"status": "EXACT_PAYLOAD_MATCH", "valid": True}
    
    # 4. Gate truncated entries on prefix match against container EOF
    else:
        if data_offset + available != container_total_len:
            return {"status": "TRUNCATION_NOT_AT_EOF", "valid": False}
        if disk_bytes[:available] != payload:
            return {"status": "PAYLOAD_MISMATCH", "valid": False}
        # Explicitly do NOT claim a complete CRC match on truncated file
        return {"status": "PARTIAL_CONTAINER_TRUNCATED", "valid": True}
```

---

## 2. Objdump Parser & Regex Remediation

### Proposed Regex Fix:
```python
# Replace line 143:
# OLD: INS_RE = re.compile(r"^[ ]*[0-9a-f]+:\s+[0-9a-f]{8}\s+([a-z0-9.]+)", re.IGNORECASE)
# NEW:
INS_RE = re.compile(r"^\s*[0-9a-f]+:\s+([a-z][a-z0-9.]*)\b", re.IGNORECASE)
LABEL_RE = re.compile(r"^[0-9a-f]+\s+<([^>]+)>:\s*$", re.IGNORECASE)
HEADER_RE = re.compile(r"(file format|Disassembly of section)", re.IGNORECASE)
```

### Proposed Sample Line Accounting:
Instead of assuming that all non-blank lines are instructions, categorize every line:
```python
lines = raw_sample_text.splitlines()
instructions = []
labels = []
headers = []
for line in lines:
    if not line.strip(): continue
    if m := INS_RE.match(line):
        instructions.append(m.group(1).lower())
    elif m := LABEL_RE.match(line):
        labels.append(m.group(1))
    elif HEADER_RE.search(line):
        headers.append(line)
```

---

## 3. Durable Command Receipt Serialization

### Proposed JSON Receipt Schema Implementation:
When running tools (`objdump`, `readelf`, `ghidra`), serialize complete records to disk:
```python
receipt = {
    "command": cmd_args,
    "started_at": start_iso,
    "ended_at": end_iso,
    "duration_ms": duration,
    "exit_code": proc.returncode,
    "tool_path": str(tool_path),
    "tool_sha256": file_sha256(tool_path),
    "input_path": str(input_path),
    "input_sha256": file_sha256(input_path),
    "stdout_full_sha256": hashlib.sha256(proc.stdout).hexdigest(),
    "stdout_full_bytes": len(proc.stdout),
    "stderr_sha256": hashlib.sha256(proc.stderr).hexdigest(),
    "retained_path": str(retained_file_path),
    "retained_bytes": len(retained_content),
    "retained_sha256": hashlib.sha256(retained_content).hexdigest(),
    "retention_policy": "HEAD_1500_LINES"
}
```

---

## 4. Provenance & Attribution Corrections
1. **Shader Quoting:** Quote the literal GLSL function `float SoftLight_Fcn(float A, float B)` and its exact lines from the decoded APK. If providing an algebraic simplification (`2.0 * a * b`), label it explicitly as `Algebraic Simplification / Pedagogical Formulation`, not `Verbatim Shader Formulation`.
2. **Model Path:** Change the NE model path in asset inventories to `assets/vlaimodel/libmtskinphone/Models/NE.manis`.
3. **Symbol Counts:** Distinguish total defined symbols (303) from defined symbols containing keyword `Manis` (288).
4. **Tool Version:** Parse `Ghidra/application.properties` dynamically rather than hardcoding version strings.
