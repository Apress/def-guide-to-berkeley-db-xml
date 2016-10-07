from bsddb3.db import * 
from dbxml import * 

environment = DBEnv() 
environment.open("myEnv", 
    DB_CREATE|DB_INIT_LOCK|DB_INIT_LOG|DB_INIT_MPOOL|DB_INIT_TXN, 0) 
mymgr = XmlManager(environment, 0) 
uc = mymgr.createUpdateContext() 
container = mymgr.createContainer("test.dbxml", DBXML_TRANSACTIONAL) 
txn = mymgr.createTransaction() 
container.putDocument(txn, "doc12", "<person>Bill</person>", uc) 
txn.commit() 

