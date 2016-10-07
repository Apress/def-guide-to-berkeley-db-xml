#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlUpdateContext myContext = myManager.createUpdateContext();
    std::string docContent = "<person><name>Bob</name></person>";
    myContainer.putDocument("", docContent,			// The document's content as string
                                          myContext,			// The update context 
                                          DBXML_GEN_NAME);	// Autogenerate document name
}

