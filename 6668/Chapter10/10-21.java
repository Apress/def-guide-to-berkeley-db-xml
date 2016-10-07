import com.sleepycat.dbxml.*;
import java.io.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();

        XmlDocument myDocument = myContainer.getDocument("114.xml");

        XmlValue metaValue = new XmlValue();

        myDocument.getMetaData("http://brians.org/metadata", "createdOn", metaValue);
        System.out.print("114.xml created on " + metaValue.asString() + "\n");

        myContainer.delete();
        myManager.delete();
    }
}

