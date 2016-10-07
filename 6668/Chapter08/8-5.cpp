#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    u_int32_t env_flags = DB_CREATE |		// Create environment if it doesn't exist
                          DB_INIT_LOCK |		// Initialize locking
                          DB_INIT_LOG |		// Initialize logging
                          DB_INIT_MPOOL |		// Initialize the cache
                          DB_INIT_TXN;		// Initialize transactions

    std::string envPath("/myEnv");
    DbEnv *myEnv = new DbEnv(0);
    XmlManager *myManager = NULL;

    try {
        myEnv->open(envPath.c_str(), env_flags, 0);
        myManager = new XmlManager(myEnv, DBXML_ADOPT_DBENV);
    } catch(DbException &e) {
        std::cerr << "Error opening database environment: "
                  << envPath << std::endl;
        std::cerr << e.what() << std::endl;
    } catch (XmlException &xe) {
        std::cerr << "Error opening database environment: "
                  << envPath 
                  << " or opening XmlManager." << std::endl;
        std::cerr << xe.what() << std::endl;
    } 

    try {
        if (myManager != NULL) {
            delete myManager;
        }
    } catch(DbException &e) {
        std::cerr << "Error closing database environment: "
                << envPath << std::endl;
        std::cerr << e.what() << std::endl;
    } catch(XmlException &xe) {
        std::cerr << "Error closing database environment: "
                << envPath << std::endl;
        std::cerr << xe.what() << std::endl;
    }
}

