import sys, json, math, copy, hashlib, datetime, unittest
from pathlib import Path
sys.path.insert(0,str(Path('.ai/ceo').resolve()))
import controller
from test_controller import ControllerTests
candidate_sha=controller.file_sha(Path('.ai/ceo/controller.py'))
print('CANDIDATE_SHA256',candidate_sha,flush=True)
results=[]
def run(name,fn):
    t=ControllerTests('test_claim_idempotency_and_same_owner_renewal_keep_fence')
    t.setUp()
    try:
        detail=fn(t)
        results.append({'case':name,'result':'PASS','detail':detail})
        print(json.dumps(results[-1],ensure_ascii=False),flush=True)
    finally:
        t.doCleanups()

def boundaries(t):
    t.task(max_minutes=30)
    start=t.now
    first=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert first['status']=='CLAIMED',first
    assert first['expiry']==start+1800,first
    acquired=t.controller.read_json(t.controller.registry)['active_locks'][-1]['acquired_at']
    fence=first['fencing_token']
    t.now=start+1000
    renewal=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert renewal['status']=='CLAIMED',renewal
    assert renewal['expiry']==start+1800,renewal
    assert renewal['fencing_token']==fence
    assert t.controller.read_json(t.controller.registry)['active_locks'][-1]['acquired_at']==acquired
    t.now=start+1800-0.000001
    near=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert near['status']=='CLAIMED' and near['expiry']==start+1800,near
    for offset in [1800,1801]:
        t.now=start+offset
        before=controller.file_sha(t.controller.registry)
        result=t.controller.claim('TASK_063','lead',t.standard_sha)
        assert result['reason']=='TASK_TIME_BUDGET_EXHAUSTED',result
        assert controller.file_sha(t.controller.registry)==before
    return {'first_clock':start,'deadline':first['expiry'],'renewed_at':start+1000,'preserved_acquired_at':acquired,'fence':fence,'exact_and_past_boundary':'BLOCKED'}
run('budget_and_original_clock_full_api',boundaries)

for name,val in [('zero',0),('negative',-1),('bool',True),('nan',float('nan')),('positive_inf',float('inf')),('negative_inf',float('-inf')),('string','30'),('list',[30]),('dict',{'n':30})]:
    def invalid(t,v=val):
        t.task(max_minutes=v)
        before=controller.file_sha(t.controller.registry)
        result=t.controller.claim('TASK_063','lead',t.standard_sha)
        assert result['reason']=='INVALID_TASK_TIME_BUDGET',result
        assert controller.file_sha(t.controller.registry)==before
        return result['reason']
    run('invalid_'+name,invalid)

def missing(t):
    t.task(max_minutes=30)
    first=t.controller.claim('TASK_063','lead',t.standard_sha)
    reg=t.controller.read_json(t.controller.registry)
    reg['active_locks']=[l for l in reg['active_locks'] if l.get('lease_id')!=first['lease_id']]
    t.json('.ai/locks.json',reg)
    t.now+=1801
    before=controller.file_sha(t.controller.registry)
    result=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert result['reason']=='WORKER_LEASE_MISSING_REQUIRES_CEO_HANDOFF',result
    assert controller.file_sha(t.controller.registry)==before
    assert not any(l.get('lease_id')==first['lease_id'] for l in t.controller.read_json(t.controller.registry)['active_locks'])
    return {'reason':result['reason'],'past_original_deadline':True,'old_fence_reused':False}
run('missing_registry_lease_never_resets_clock_or_fence',missing)

def revoked_claim(t):
    t.task(max_minutes=30)
    first=t.controller.claim('TASK_063','lead',t.standard_sha)
    state=t.controller.read_json(t.controller.state_path)
    state['claims']['TASK_063:r1'].update(status='REVOKED',expiry=0)
    t.json('.ai/ceo/state.json',state)
    before=controller.file_sha(t.controller.registry)
    result=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert result['reason']=='REVOKED_CLAIM_REQUIRES_CEO_HANDOFF',result
    assert controller.file_sha(t.controller.registry)==before
    return result['reason']
run('revoked_claim_cannot_reactivate',revoked_claim)

def revoked_lease(t):
    t.task(max_minutes=30)
    t.controller.claim('TASK_063','lead',t.standard_sha)
    reg=t.controller.read_json(t.controller.registry)
    reg['active_locks'][-1]['status']='REVOKED'
    t.json('.ai/locks.json',reg)
    before=controller.file_sha(t.controller.registry)
    result=t.controller.claim('TASK_063','lead',t.standard_sha)
    assert result['reason']=='REVOKED_LEASE_REQUIRES_CEO_HANDOFF',result
    assert controller.file_sha(t.controller.registry)==before
    return result['reason']
run('revoked_registry_lease_cannot_reactivate',revoked_lease)

def accepted(t):
    t.config['task_ids']+=['TASK_067','TASK_068']
    t.json('.ai/ceo/config.json',t.config)
    t.controller=controller.Controller(t.root,clock=lambda:t.now)
    out={}
    for task,revision in [('TASK_067',3),('TASK_068',2)]:
        t.task(task_id=task,revision=revision,max_minutes=30)
        t.report(task_id=task,revision=revision)
        verdict=t.accept(task)
        out[task]=verdict
    t.now+=1801
    tasks=t.controller.tasks()
    state=t.controller.read_json(t.controller.state_path)
    for task,revision in [('TASK_067',3),('TASK_068',2)]:
        assert t.controller.accepted(task,state,tasks,revision)
        result=t.controller.claim(task,'lead',t.standard_sha)
        assert result['reason']=='TASK_ALREADY_CEO_ACCEPTED',result
    return {'TASK_067_R3':'accepted_gate_preserved','TASK_068_R2':'accepted_gate_preserved','late_reclaim':'BLOCKED'}
run('accepted_067_068_gates_unaffected',accepted)

def scan_noauto(t):
    t.task(max_minutes=30)
    first=t.controller.claim('TASK_063','lead',t.standard_sha)
    t.now+=1801
    scan=t.controller.scan()
    state=t.controller.read_json(t.controller.state_path)
    reg=t.controller.read_json(t.controller.registry)
    task=t.controller.tasks()['TASK_063']
    lease=[l for l in reg['active_locks'] if l.get('lease_id')==first['lease_id']][0]
    assert task['status']=='ACTIVE'
    assert lease['status']=='ACTIVE' and not t.controller.lease_live(lease)
    assert not any(e.get('kind')=='TASK_TIME_BUDGET_EXHAUSTED' for e in scan['events'])
    return {'auto_block_metadata':False,'auto_revoke_lease_status':False,'lease_live':False,'meaning':'scan alone does not close exhausted task'}
run('honest_scanner_enforcement_limitation',scan_noauto)
print('TEST_RUN_COMPLETE',json.dumps({'candidate_sha256':candidate_sha,'cases':len(results),'all_pass':True,'isolated_fixture_only':True,'no_live_claim_registry_or_state_write':True}),flush=True)
