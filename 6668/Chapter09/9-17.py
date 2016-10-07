from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()

indexlookup = mymgr.createIndexLookup(mycontainer, "", "name", "node-element-equality-string")
results = indexlookup.execute(qcontext)

for result in results:
    document = result.asDocument()
    print document.getName(), ": ", document.getContent()

del mycontainer

