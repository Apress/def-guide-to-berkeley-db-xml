#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
     u_int32_t env_flags = DB_CREATE |	// Create environment if it doesn't exist
                          DB_INIT_LOCK |	// Initialize locking
                          DB_INIT_LOG |	// Initialize logging
                          DB_INIT_MPOOL |	// Initialize the cache
                          DB_INIT_TXN;	// Initialize transactions
    XmlManager *myManager = NULL;
    XmlTransaction myTxn;
    try {
        DbEnv *myEnv = new DbEnv(0);
        myEnv->open("/myEnv", env_flags, 0);
        myManager = new XmlManager(myEnv, DBXML_ADOPT_DBENV);
        myTxn = myManager->createTransaction();
        XmlContainer myContainer = myManager->openContainer("myContainer.dbxml", DB_CREATE | DBXML_TRANSACTIONAL);
        
        XmlUpdateContext myUpdateContext = myManager->createUpdateContext();
        XmlInputStream *theStream = myManager->createLocalFileInputStream("myfile12.xml");
        myContainer.putDocument(myTxn,		// the transaction object
                                             "myfile12",	// the document's name
                                              theStream,	// the document
                                              myUpdateContext,	// The update context 
                                              0);		// Put flags.
        myTxn.commit();
    } catch(XmlException &error) {
        std::cerr << "Error in transaction: "
                  << error.what() << "\n"
                  << "Aborting." << std::endl;
        myTxn.abort();
    } 
}

