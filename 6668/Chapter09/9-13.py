from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
ucontext = mymgr.createUpdateContext()

results = mymgr.query("collection('test.dbxml')/person[name='Bob']", qcontext)
for result in results:
    document = result.asDocument()
    print "Deleting document: ", document.getName(), "\n"
    mycontainer.deleteDocument(document, ucontext)

del mycontainer

