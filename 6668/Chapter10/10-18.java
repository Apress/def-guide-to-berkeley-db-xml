import com.sleepycat.dbxml.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();

        XmlIndexSpecification myIndexSpec = myContainer.getIndexSpecification();
        myIndexSpec.deleteIndex("", "person", "node-element-equality-string");
        myIndexSpec.addIndex("", "person", "node-attribute-equality-string");
        myContainer.setIndexSpecification(myIndexSpec, uContext);

        myContainer.delete();
        myManager.delete();
    }
}

