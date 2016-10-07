#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    std::string myQuery = "collection()/person[name='Bob']";
    XmlResults results = myManager.query(myQuery, myContext);
    printf("%i results from query.\n", results.size());
    XmlValue value;
    while (results.next(value)) {
        XmlDocument myDoc = value.asDocument();
        std::string docContent = value.asString();
        std::string docName = myDoc.getName();
        std::cout << "Document " << docName << ":" << std::endl;
        std::cout << docContent << std::endl;
    }
}

