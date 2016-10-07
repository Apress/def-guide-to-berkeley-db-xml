#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    myContainer.addIndex("", "person", "node-element-equality-string", myUpdateContext);
}

