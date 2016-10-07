import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();

        myContainer.addIndex("", "person", "node-element-equality-string", uContext);

        myContainer.delete();
        myManager.delete();
    }
}

