import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");

        XmlQueryContext myContext = myManager.createQueryContext();
        myContext.setNamespace("people", "http://brians.org/people");
        myContext.setVariableValue("name", new XmlValue("Bob"));
        String myQuery = "collection('myContainer.dbxml')/people:person[name=$name]";

        XmlQueryExpression qe = myManager.prepare(myQuery, myContext);

        myContext.setVariableValue("name", new XmlValue("Bob"));
        XmlResults results = qe.execute(myContext);

        results.delete() 
        qe.delete(); 
        myContext.delete(); 
        myContainer.delete();
        myManager.delete();
    }
}

