from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
ucontext = mymgr.createUpdateContext()

indexspec = mycontainer.getIndexSpecification()
indexspec.deleteIndex("", "person", "node-element-equality-string")
indexspec.addIndex("", "person", "node-attribute-equality-string")
mycontainer.setIndexSpecification(indexspec, ucontext)

del mycontainer

