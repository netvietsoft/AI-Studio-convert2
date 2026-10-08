"""Persist the observed tool excerpt and actual R2 dispatch; never expose challenge."""
import json,pathlib,sys
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller,iso
root=pathlib.Path(__file__).resolve().parents[3]
c=Controller(root)
evidence={'source':'Paseo get_agent_activity(ace29908-a2b0-4777-a070-6bd100509738,limit100)',
    'actor_id':'ace29908-a2b0-4777-a070-6bd100509738','update_count':88,
    'observed_command_excerpt':'python -X utf8 -B .ai/ceo/controller.py claim --task-id TASK_067 --agent-id 7de71900-89f8-4633-97a9-3efaf42ea6b8 --standard-sha 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f',
    'limits':'Curated activity exposes command text but not its precise execution timestamp/stdout. Registry claim occurred05:20:09Z. Actual new worker BOOT response says no claim/writes.',
    'observed_at':iso(c.clock()),'control_regressions':{'offline_tests':29,'exit_code':0,'duration_seconds':5.673,
        'real_missing_binding_result':'BLOCKED/CEO_DISPATCH_BINDING_REQUIRED','research_or_product_PASS':False}}
dispatch=json.loads((root/'.ai/ceo/receipts/TASK_067_R2_DISPATCH.json').read_text())
with c.transaction() as(registry,state):
    c.replace_json(root/'.ai/ceo/receipts/TASK_067_WRONG_ACTOR_ACTIVITY.json',evidence,registry)
    dest=root/'RULES/REPORT/CEO_SO45_ORCHESTRATION/TASK_067_R2_ACTUAL_DISPATCH.md'
    c.authorized(c.ceo_lease(registry),dest)
    dest.write_text('# TASK067 R2 actual dispatch\n\n'+json.dumps(dispatch,ensure_ascii=False,indent=2)+'\n\nWorker engine Codex/gpt-6.1-sol; actual native session mapped through Paseo status. Exact task ACTIVE revision2, task SHA9e1b65478a0bf9dfb1e30ab6feaa76bbe5e8a8a51c6b25559487cff697b9bd28. Prompt delivered while idle; API returned success/running. This proves dispatch, not claim/completion. Mandatory full-rule reread and bounded report/script/evidence scopes included. Invalid1012 revoked; new valid claim must have verified dispatch binding and a new fence.\n\n29/29 offline control tests pass; actual missing-binding claim rejected. No diagnostic attempt-budget increase, baseline acceptance, product PASS or V4 opening. TASK063 remains BLOCKED. Existing minute scanner continues; no duplicate heartbeat.\n',encoding='utf-8')
    c.event(state,'CEO_MATERIAL_PROGRESS_NOTIFIED','TASK_067',revision=2,milestone='Actual idle recipient mapped and dispatched; untrusted1012 revoked;29 control tests pass')
print('Public dispatch and actor incident receipts saved without nonce')
