"""Release accepted worker leases without changing their immutable reports."""
import datetime as dt, importlib.util, json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
spec=importlib.util.spec_from_file_location('controller',ROOT/'.ai/ceo/controller.py')
m=importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
c=m.Controller(ROOT)
ids=('TASK_244',)
with m.guard(c.home/'control.guard'),m.guard(ROOT/'.ai/locks.registry.guard'):
    registry=c.read_json(c.registry); c.ceo_lease(registry)
    state=c.read_json(c.state_path)
    for tid in ids:
        x=state['tasks'][tid]
        assert x['verdict']['disposition']=='ACCEPTED',(tid,x.get('verdict'))
        key=f'{tid}:r1'; claim=state['claims'][key]
        assert claim['lease_id']==f'LEASE-CEO-WORKER-{tid}-R1'
        lock=next(z for z in registry['active_locks'] if z['lease_id']==claim['lease_id'])
        assert lock['status'] in ('ACTIVE','RELEASED') and lock['fencing_token']==claim['fencing_token']
    now=dt.datetime.now(dt.timezone.utc).isoformat()
    newr=json.loads(json.dumps(registry)); news=json.loads(json.dumps(state))
    for tid in ids:
        lock=next(z for z in newr['active_locks'] if z['lease_id']==f'LEASE-CEO-WORKER-{tid}-R1')
        if lock['status']=='ACTIVE':
            lock.update(status='RELEASED',expiry=now,released_at=now,release_reason=f'{tid} R1 independently ACCEPTED; worker finished')
        del news['claims'][f'{tid}:r1']
    newr['revision']+=1; newr['updated_at']=now
    news['revision']+=1; news['updated_at']=now
    if newr!=registry:
        c.replace_json(c.registry,newr,registry)
    c.replace_json(c.state_path,news,newr if newr!=registry else registry)
print('released',*ids)




