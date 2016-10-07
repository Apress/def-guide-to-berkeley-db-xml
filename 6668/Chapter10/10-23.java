import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlQueryContext qContext = myManager.createQueryContext();
        XmlUpdateContext uContext = myManager.createUpdateContext();

        XmlModify myModify = myManager.createModify();
        XmlQueryExpression myQuery = myManager.prepare("/person/name", qContext);
        myModify.addAppendStep(myQuery, XmlModify.Attribute, "type", "given");
        XmlResults myResults = myManager.query("collection('myContainer.dbxml')/person[name='Bill']", qContext);
        myModify.execute(myResults, qContext, uContext);

        myContainer.delete();
        myManager.delete();
    }
}

