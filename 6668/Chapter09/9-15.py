from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
ucontext = mymgr.createUpdateContext()

mycontainer.addIndex("", "person", "node-element-equality-string", ucontext)

del mycontainer

