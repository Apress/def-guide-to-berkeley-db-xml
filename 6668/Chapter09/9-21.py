from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
ucontext = mymgr.createUpdateContext()

mymodify = mymgr.createModify()
queryexp = mymgr.prepare("/person/name", qcontext)
mymodify.addAppendStep(queryexp, XmlModify.Attribute, "type", "given")

results = mymgr.query("collection('test.dbxml')/person[name='Bill']", qcontext)
mymodify.execute(results, qcontext, ucontext)

del mycontainer

