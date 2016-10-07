#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    XmlDocument myDoc = myContainer.getDocument("114.xml");
    myDoc.setContent("<person><name>Charles</name></person>");
    myContainer.updateDocument(myDoc, myUpdateContext); 
}

