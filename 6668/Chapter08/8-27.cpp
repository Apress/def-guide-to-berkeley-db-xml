#include "DbXml.hpp"

using namespace DbXml;
int main(void)
{
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlQueryContext myQueryContext = myManager.createQueryContext();
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    XmlModify myModify = myManager.createModify();
    XmlQueryExpression myQuery = myManager.prepare("/person/name", myQueryContext);
    myModify.addAppendStep(myQuery, XmlModify::Attribute, "type", "given");
    XmlResults myResults = myManager.query("collection('container.bdbxml')/person/name", myQueryContext);
    myModify.execute(myResults, myQueryContext, myUpdateContext);
}

