from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
ucontext = mymgr.createUpdateContext()

content = r"<person><name>Bob</name></person>"
mycontainer.putDocument("1", content, ucontext)

del mycontainer

