from bsddb3.db import *
from dbxml import *

myenv = DBEnv()
myenv.open("myenv/", DB_CREATE|DB_INIT_LOCK|DB_INIT_LOG|DB_INIT_MPOOL|DB_INIT_TXN, 0)
mgr = XmlManager(myenv, 0)


