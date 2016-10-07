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
    XmlDocument myDoc = myContainer.getDocument("dbxml_11");
    XmlValue docValue(myDoc);
    myModify.execute(docValue, myQueryContext, myUpdateContext);
}

