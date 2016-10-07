import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");

        XmlQueryContext myContext = myManager.createQueryContext();
        String myQuery = "collection('myContainer.dbxml')/person[name='Jim']";

        XmlResults myResults = myManager.query(myQuery, myContext);
        XmlValue myValue = myResults.next();
        while (myValue != null) {
            XmlDocument myDocument = myValue.asDocument();
            String name = myDocument.getName();
            String content = myValue.asString();
            //System.out.print("Document " + name + ":\n");
            System.out.print(content);
            myValue = myResults.next();
        }

        myValue.delete(); 
        myResults.delete(); 
        myQuery.delete(); 
        myContext.delete(); 
        myContainer.delete(); 
        myManager.delete(); 
    }
}

