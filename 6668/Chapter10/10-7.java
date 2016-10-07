import com.sleepycat.dbxml.*;
import java.io.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        XmlManager myManager = new XmlManager();
        XmlContainer myContainer = myManager.openContainer("container.bdbxml");

        // The update context is needed to add the document.
        XmlUpdateContext theContext = myManager.createUpdateContext();

        // Create the file input stream
        XmlInputStream myStream = myManager.createLocalFileInputStream("./file176.xml");

        // Put the document in the container
        myContainer.putDocument("176", myStream, theContext);
        myContainer.delete();
        myManager.delete();
    }
}

