from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
qcontext = mymgr.createQueryContext()
ucontext = mymgr.createUpdateContext()

document = mycontainer.getDocument("1")
document.setContent("<person><name>Bob</name></person>")
mycontainer.updateDocument(document, ucontext)

del mycontainer

