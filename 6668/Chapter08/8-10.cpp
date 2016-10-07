#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    std::string docFilename = "file176.xml"; // the filename

    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");

    // The update context is needed to add the document.
    XmlUpdateContext theContext = myManager.createUpdateContext();

    // Create the file input stream
    XmlInputStream *myStream = myManager.createLocalFileInputStream(docFilename);

    // Put the document in the container
    myContainer.putDocument(docFilename, myStream, theContext, 0);

    return(0);
}

