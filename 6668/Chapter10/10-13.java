import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlQueryContext myContext = myManager.createQueryContext();

        XmlQueryExpression mySubquery = myManager.prepare("/person/phone", myContext);
        XmlResults myResults = myManager.query("collection('myContainer.dbxml')/person[name='Jim']", myContext);
        XmlValue myValue = myResults.next();
        while (myValue != null) {
            XmlResults subResults = mySubquery.execute(myValue, myContext);
            XmlValue subValue = subResults.next();
            while (subValue != null) {
                XmlDocument myDocument = subValue.asDocument();
                String name = myDocument.getName();
                String content = subValue.asString();
                System.out.print("Document " + name + ":\n");
                System.out.print(content);
                subValue = subResults.next();
            }
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

