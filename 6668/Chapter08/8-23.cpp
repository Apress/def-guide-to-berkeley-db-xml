#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlQueryContext myQueryContext = myManager.createQueryContext();

    XmlIndexLookup myLookup = myManager.createIndexLookup(myContainer, "", "name", 
        "node-element-equality-string");
    XmlResults myResults = myLookup.execute(myQueryContext);
    XmlDocument myDoc;
    while (myResults.next(myDoc)) {
        std::string dummyString;
        std::cout << myDoc.getName() << ": " << myDoc.getContent(dummyString) << std::endl;
    }
}  

