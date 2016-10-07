from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")

uri = "http://brians.org/metadata"
metaname = "createdOn"

document = mycontainer.getDocument("1")
metavalue = XmlValue()
metavalue2 = XmlValue()
metavalue2 = document.getMetaData(uri, metaname, metavalue)
print "114.xml, created on ", metavalue.asString(), "\n"
print "114.xml, created on ", metavalue2.asString(), "\n"

del mycontainer

