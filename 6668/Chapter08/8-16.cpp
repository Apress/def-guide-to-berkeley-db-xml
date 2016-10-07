#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    XmlResults results = myManager.query("collection('myContainer.dbxml')/person[name='Bob']", myContext);
    printf("%i results from query.\n", results.size());
    XmlQueryExpression phoneQuery = 
        myManager.prepare("/person/phone/string()", myContext);
    XmlValue value;
    while (results.next(value)) {
        XmlQueryContext phoneContext = myManager.createQueryContext();
        XmlResults phoneResults = phoneQuery.execute(value, phoneContext);
        XmlDocument myDoc = value.asDocument();
        std::string docName = myDoc.getName();
        std::cout << "Document " << docName << ":" << std::endl;
        XmlValue phoneValue;
        while (phoneResults.next(phoneValue)) {
            std::cout << "  Phone: " << phoneValue.asString() << std::endl;
        }
    }
}

