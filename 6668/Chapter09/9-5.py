from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
xmlucontext = mymgr.createUpdateContext()

xmlinput = mymgr.createLocalFileInputStream("file14.xml")

mycontainer.putDocument("file14", xmlinput, xmlucontext)

del mycontainer

