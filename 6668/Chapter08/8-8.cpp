#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("/path/to/myContainer.bdbxml");
    return(0);
    // Container will be closed at the end of main()
}

