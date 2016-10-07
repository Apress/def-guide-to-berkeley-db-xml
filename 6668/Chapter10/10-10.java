import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main() throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");

        XmlQueryContext myContext = myManager.createQueryContext();
        String myQuery = "collection('myContainer.dbxml')/person[name='Jim']";

        XmlResults myResults = myManager.query(myQuery, myContext);

        myResults.delete();
        myContext.delete();
        myContainer.delete();
        myManager.delete();
    }
}

