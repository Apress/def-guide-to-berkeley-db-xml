import com.sleepycat.dbxml.*;
import java.io.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("myContainer.dbxml");
        XmlUpdateContext uContext = myManager.createUpdateContext();

        XmlDocument myDocument = myContainer.getDocument("114.xml");
        myDocument.setMetaData("http://brians.org/metadata", "createdOn",
                new XmlValue(XmlValue.DATE_TIME, "2006-02-05T05:23:14"));

        myContainer.updateDocument(myDocument, uContext);
        myContainer.delete();
        myManager.delete();
    }
}

