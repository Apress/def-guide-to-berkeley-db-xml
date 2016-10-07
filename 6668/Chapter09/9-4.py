from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mymgr.renameContainer("test.dbxml", "newtest.dbxml")
mymgr.removeContainer("newtest.dbxml")

