#include "DbXml.hpp"

using namespace DbXml;
int main(void) {
    XmlManager myManager;
    XmlContainer myContainer = myManager.openContainer("container.bdbxml");
    XmlQueryContext myContext = myManager.createQueryContext();
    XmlUpdateContext myUpdateContext = myManager.createUpdateContext();
    XmlResults results = myManager.query("collection('container.bdbxml')/person[name='Bob']", myContext);
    printf("Deleting %i documents matching query.\n", results.size());
    XmlDocument docToDelete;
    while (results.next(docToDelete)) {
        myContainer.deleteDocument(docToDelete, myUpdateContext);      
    }
}

