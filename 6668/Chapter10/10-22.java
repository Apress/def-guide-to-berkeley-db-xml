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
        XmlDocument myDocument = myContainer.getDocument("114.xml");
        XmlValue docValue = new XmlValue(myDocument);
        myModify.execute(docValue, qContext, uContext);

        myContainer.delete();
        myManager.delete();
    }
}

