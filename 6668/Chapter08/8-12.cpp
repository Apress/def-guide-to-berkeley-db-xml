#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("synsets.dbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    myContext.setNamespace("people", "http://brians.org/people");
    myContext.setVariableValue("name", "Bob");
    std::string myQuery = "collection('myCollection')/people:person[name=$name]";
    XmlQueryExpression qe = myManager.prepare(myQuery, myContext);
    XmlResults results = qe.execute(myContext);
    // Change the variable, and requery without recompiling query.
    myContext.setVariableValue("name", "Julie");
    results = qe.execute(myContext);
}

