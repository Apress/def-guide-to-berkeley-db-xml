from bsddb3.db import *
from dbxml import *

mymgr = XmlManager()

mycontainer = mymgr.openContainer("test.dbxml")
ucontext = mymgr.createUpdateContext()

uri = "http://brians.org/metadata"
metaname = "createdOn"
metavalue = XmlValue(XmlValue.DATE_TIME, "2006-02-05T05:23:14")

document = mycontainer.getDocument("114.xml")
document.setMetaData(uri, metaname, metavalue)
mycontainer.updateDocument(document, ucontext, DBXML_LAZY_DOCS)

del mycontainer

