#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    // Create an XmlManager
    XmlManager myManager;
    try {
        // Open a container
        XmlContainer myContainer = 
            myManager.openContainer("container.dbxml");
    } catch (XmlException &xe) {
        printf ("%s\n", xe.what());
    } catch (std::exception &e) {
        // Other error handling goes here
    }
}

