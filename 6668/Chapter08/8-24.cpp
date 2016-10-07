#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;

    std::string URI = "http://dbxmlExamples/metadata";
    std::string metadataName = "createdOn";
    XmlValue metadataValue(XmlValue::DATE_TIME, "2006-02-05T05:23:14");

    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    XmlDocument myDoc = myContainer.getDocument("dbxml_11");
    myDoc.setMetaData(URI, metadataName, metadataValue);
    myContainer.updateDocument(myDoc, myUpdateContext);
}

