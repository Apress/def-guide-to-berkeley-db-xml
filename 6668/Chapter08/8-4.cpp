#include "DbXml.hpp"

using namespace DbXml;
u_int32_t env_flags = DB_CREATE |	// Create if environment doesn't exist
                      DB_INIT_LOCK |	// Initialize the locking subsystem
                      DB_INIT_LOG |		// Initialize the logging subsystem
                      DB_INIT_MPOOL |	// Initialize the cache
                      DB_INIT_TXN;		// Initialize transactions for this environment
std::string envPath("/myEnv");

int main(void)
{
    DbEnv *myEnv = new DbEnv(0);
    try {
        myEnv->open(envPath.c_str(), env_flags, 0);
    } catch(DbException &e) {
        std::cerr << "Error opening database environment: "
                  << envPath << std::endl;
        std::cerr << e.what() << std::endl;
    } catch(std::exception &e) {
        std::cerr << "Error opening database environment: "
                  << envPath << std::endl;
        std::cerr << e.what() << std::endl;
    }
} 

