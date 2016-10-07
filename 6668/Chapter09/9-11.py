from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
qcontext.setEvaluationType(XmlQueryContext.Lazy)

results = mymgr.query("collection('test.dbxml')/person[name='Fred']", qcontext)
phonequery = mymgr.prepare("/person/phone", qcontext);

for value in results:
    phoneresults = phonequery.execute(value, qcontext)
    for phones in phoneresults:
        print "  phone: ", phoneresults.asString(), "\n"

del mycontainer

