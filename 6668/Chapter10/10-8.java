import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlQueryContext myContext = myManager.createQueryContext();
        myContext.setDefaultCollection("myCollection");
        String myQuery = "collection('myContainer.dbxml')/Synset[Word='wisdom']";
        XmlQueryExpression qe = myManager.prepare(myQuery, myContext);
        XmlResults results = qe.execute(myContext);

        results.delete();
        qe.delete();
        myContext.delete();
        myContainer.delete();
        myManager.delete();
    }
}

