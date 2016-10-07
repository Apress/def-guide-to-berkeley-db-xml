import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlQueryContext qContext = myManager.createQueryContext();
        XmlIndexLookup myLookup = myManager.createIndexLookup(myContainer, "", "name", "node-element-equality-stirng");

        XmlResults myResults = myLookup.execute(qContext);
        XmlValue myValue = myResults.next();
        while (myValue != null) {
            XmlDocument myDocument = myValue.asDocument();
            String name = myDocument.getName();
            System.out.print("Index touches " + name + "\n");
            myValue = myResults.next();
        }
        myContainer.delete();
        myManager.delete();
    }
}

