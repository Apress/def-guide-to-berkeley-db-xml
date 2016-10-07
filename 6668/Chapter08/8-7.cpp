#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;
    XmlContainer myContainer = myManager.createContainer(
        "/path/to/myContainer.bdbxml",
        DBXML_ALLOW_VALIDATION,
        XmlContainer::NodeContainer, 766 );
    return(0);
}

