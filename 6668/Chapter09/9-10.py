from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()
myquery = r"collection('test.dbxml')/person[name='Fred']"

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
qcontext.setEvaluationType(XmlQueryContext.Lazy)

results = mymgr.query(myquery, qcontext)
for value in results:
    document = value.asDocument()
    name     = document.getName()
    content  = value.asString()
    print name, ": ", content

del mycontainer

