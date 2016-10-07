from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()
myquery = r"collection('test.dbxml')/person[name='Jim']"

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
qcontext.setEvaluationType(XmlQueryContext.Lazy)

results = mymgr.query(myquery, qcontext)

del mycontainer

