import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlQueryContext qContext = myManager.createQueryContext();
        XmlUpdateContext uContext = myManager.createUpdateContext();

        String myQuery = "collection('myContainer.dbxml')/person[name='Steve']";

        XmlResults myResults = myManager.query(myQuery, qContext);
        XmlValue myValue = myResults.next();
        while (myValue != null) {
            XmlDocument myDocument = myValue.asDocument();
            String name = myDocument.getName();
            System.out.print("Deleting " + name + "\n");
            myContainer.deleteDocument(myDocument, uContext);
            myValue = myResults.next();
        }
        myContainer.delete();
        myManager.delete();
    }
}

