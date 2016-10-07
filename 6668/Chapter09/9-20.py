from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
ucontext = mymgr.createUpdateContext()

mymodify = mymgr.createModify()
queryexp = mymgr.prepare("/person/name", qcontext)
mymodify.addAppendStep(queryexp, XmlModify.Attribute, "type", "given")

document = mycontainer.getDocument("1")
docvalue = XmlValue(document)
mymodify.execute(docvalue, qcontext, ucontext)

del mycontainer

