#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    // Create an XmlManager
    XmlManager myManager;
    // Set the errors stream to standard out
    myManager.getDbEnv()->set_error_stream(&std::cerr);
    try {
        XmlContainer myContainer = myManager.openContainer("container.dbxml");
        DbXml::setLogLevel(DbXml::LEVEL_ALL, true);
        DbXml::setLogCategory(DbXml::CATEGORY_ALL, true); 
    } catch (XmlException &xe) {
        // Error handling goes here
    }
}

