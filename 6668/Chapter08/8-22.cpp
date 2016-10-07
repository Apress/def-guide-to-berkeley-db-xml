#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    XmlIndexSpecification myIndexSpec = myContainer.getIndexSpecification();
    myIndexSpec.deleteIndex("", "person", "node-element-equality-string");
    myIndexSpec.addIndex("", "name", "node-element-equality-string");
    myContainer.setIndexSpecification(myIndexSpec, myUpdateContext);
}

