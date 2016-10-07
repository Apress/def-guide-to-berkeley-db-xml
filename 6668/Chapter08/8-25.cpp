#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlDocument myDoc = myContainer.getDocument("dbxml_11"); 
    XmlValue metadataValue;
    myDoc.getMetaData("http://dbxmlExamples/metadata", "createdOn", metadataValue);
    std::cout << "Document 114.xml, created on " << metadataValue.asString() << std::endl;
}

