"""Publish only CEO assignment and host-mitigation records, never worker code."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha, iso

C = Controller(ROOT)
WT = Path("F:/CONVERT_WORKTREES/ceo-so45-20261008")
BRANCH = "ceo/so45-v4-orchestration-20261008"
RELS = [
    "RULES/TASK/TASK_069_SO45_VERIFIER_MINIMAL_REPAIR_ACTIVE.md",
    ".ai/ceo/config.json",
    ".ai/ceo/SO45_TO_V4_PLAN.md",
    ".ai/ceo/receipts/SO45_RECOVERY_DISPOSITION_AFTER_TASK067.json",
    ".ai/ceo/receipts/TASK_069_DISPATCH.json",
    ".ai/ceo/receipts/BASH_POPUP_RALPH_HOOK_FIX_20261008.json",
    "RULES/REPORT/CEO_SO45_ORCHESTRATION/BASH_POPUP_20261008/01_BASH_POPUP_REVIEW.md",
    ".ai/ceo/reviews/publish_task069_admin.py",
]


def git(*args):
    return subprocess.check_output(
        ["git", "-C", str(WT), *args],
        creationflags=subprocess.CREATE_NO_WINDOW,
    )


with C.transaction() as (registry, state):
    C.authorized(C.ceo_lease(registry), WT / "publication-scope")
    task = C.tasks()["TASK_069"]
    assert task["revision"] == 1 and task["status"] == "ACTIVE"
    assert task["dependencies"] == [{"task_id": "TASK_067", "revision": 3}]
    claim = state["claims"]["TASK_069:r1"]
    assert claim["dispatch_binding_verified"] and claim["fencing_token"] == 1018
    upstream = state["tasks"]["TASK_067"]
    assert upstream["verdict"]["disposition"] == "ACCEPTED"
    assert upstream["verdict"]["fingerprint"] == upstream["fingerprint"]
    hashes = {rel: file_sha(ROOT / rel) for rel in RELS}
    assert hashes[RELS[0]] == claim["task_sha"]
    private = json.loads((ROOT / ".ai/ceo/receipts/TASK_069_DISPATCH_PRIVATE.json").read_text())
    nonce = private["dispatch_token"].encode()
    for rel in RELS:
        assert "DISPATCH_PRIVATE" not in rel and nonce not in (ROOT / rel).read_bytes()

assert git("branch", "--show-current").decode().strip() == BRANCH
assert set(git("diff", "--cached", "--name-only").decode().splitlines()) <= set(RELS)
for rel in RELS:
    assert file_sha(ROOT / rel) == hashes[rel]
    target = WT / rel
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(ROOT / rel, target)
git("-c", "core.autocrlf=false", "add", "--", *RELS)
changed = git("diff", "--cached", "--name-only").decode().splitlines()
assert set(changed) <= set(RELS)
if changed:
    git("-c", "core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol", "diff", "--cached", "--check", "--", *changed)
    git("commit", "-m", "docs(ceo): dispatch bounded SO45 verifier repair and record Bash mitigation")
commit = git("rev-parse", "HEAD").decode().strip()
for rel, sha in hashes.items():
    assert hashlib.sha256(git("show", commit + ":" + rel)).hexdigest() == sha
with C.transaction() as (registry, state):
    C.ceo_lease(registry)
    assert C.tasks()["TASK_069"]["revision"] == 1
    assert file_sha(ROOT / RELS[0]) == hashes[RELS[0]]
git("push", "origin", BRANCH)
remote = git("ls-remote", "origin", "refs/heads/" + BRANCH).decode().split()[0]
assert remote == commit
with C.transaction() as (registry, state):
    data = {
        "schema_version": "2.1.2",
        "task_id": "TASK_069",
        "revision": 1,
        "commit": commit,
        "remote_verified": remote,
        "curated_files": hashes,
        "observed_at": iso(C.clock()),
        "meaning": "CEO assignment and host mitigation records only; worker implementation is not reviewed or accepted",
        "worker_implementation_accepted": False,
        "baseline_or_v4_authorized": False,
    }
    C.replace_json(ROOT / ".ai/ceo/receipts/TASK_069_ADMIN_PUBLICATION.json", data, registry)
    state["last_target_commit_sha"] = commit
    C.event(state, "CEO_ASSIGNMENT_PUBLICATION_VERIFIED", "TASK_069", revision=1, commit=commit, scoped_blob_hashes=len(hashes), implementation_accepted=False)
print(json.dumps({k: v for k, v in data.items() if k != "curated_files"}))
