#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    std::string myQuery = "collection()/person[name='Bob']";
    XmlResults results = myManager.query(myQuery, myContext);
}

