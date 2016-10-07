import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();
        XmlQueryContext qContext = myManager.createQueryContext();
        
        String content = "<person><name>Bob</name></person>";
        myContainer.putDocument("", content, theContext, docConfig);

        myContainer.delete();
        myManager.delete();
    }
}

