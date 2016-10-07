#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    myContext.setDefaultCollection("myCollection");
    std::string myQuery = "collection()/Synset[Word='wisdom']";
    XmlQueryExpression qe = myManager.prepare(myQuery, myContext);
    XmlResults results = qe.execute(myContext);
}

