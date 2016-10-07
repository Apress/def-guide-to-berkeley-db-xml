import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();
        
        XmlDocument myDocument = myContainer.getDocument("12.xml");
        myDocument.setContent("<person><name>Bob</name></person>");
        myContainer.updateDocument(myDocument, uContext);

        myContainer.delete();
        myManager.delete();
    }
}

