from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()
myquery = r"collection()/person[name='Bob']"

mycontainer = mymgr.openContainer("test.dbxml")
xmlqcontext = mymgr.createQueryContext()

xmlqcontext.setDefaultCollection("test.dbxml")
queryexp = mymgr.prepare(myquery, xmlqcontext)
results = queryexp.execute(xmlqcontext)

del mycontainer

