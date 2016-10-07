#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    myContainer.addIndex("", "person",
        (XmlIndexSpecification::Type)
        (XmlIndexSpecification::PATH_NODE |
        XmlIndexSpecification::NODE_ELEMENT |
        XmlIndexSpecification::KEY_EQUALITY),
        XmlValue::STRING,
        myUpdateContext);
}

