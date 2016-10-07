#include "DbXml.hpp" 
using namespace DbXml; 
int main(void) 
{ 
  u_int32_t env_flags = DB_CREATE    | // Create environment if it doesn't exist 
                        DB_INIT_LOCK | // Initialize locking 
                        DB_INIT_LOG  | // Initialize logging 
                        DB_INIT_MPOOL| // Initialize the cache 
                        DB_INIT_TXN;   // Initialize transactions 
  DbEnv myEnv(0); 
  myEnv.open("/path/to/environment", env_flags, 0); 
  XmlManager myManager = new XmlManager(myEnv, DBXML_ADOPT_DBENV); 
  XmlContainer myContainer = myManager.openContainer("myContainer.dbxml",
      DB_CREATE | DBXML_TRANSACTIONAL); 
} 

