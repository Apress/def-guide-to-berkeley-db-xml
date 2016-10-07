from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()
myquery = r"collection('test.dbxml')/people:person[name=$name]"

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()

qcontext.setNamespace("people", "http://brians.org/people")
qcontext.setVariableValue("name", XmlValue("Bob"))

queryexp = mymgr.prepare(myquery, qcontext)
results = queryexp.execute(qcontext)
qcontext.setVariableValue("name", XmlValue("Bob"))
results = queryexp.execute(qcontext)

del mycontainer

