#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myQueryContext = myManager.createQueryContext();
    XmlIndexLookup myLookup = myManager.createIndexLookup(myContainer, "", "age", 
        "node-element-equality-decimal",
        XmlValue(XmlValue::DECIMAL, "16"), 
    XmlIndexLookup::GTE);
    myLookup.setHighBound(XmlValue(XmlValue::DECIMAL, "35"), XmlIndexLookup::LT);
    XmlResults myResults = myLookup.execute(myQueryContext, DBXML_REVERSE_ORDER);
    XmlDocument myDoc;
    while (myResults.next(myDoc)) {
        std::string dummyString;
        std::cout << myDoc.getName() << ": " << myDoc.getContent(dummyString) << std::endl;
    }
}

