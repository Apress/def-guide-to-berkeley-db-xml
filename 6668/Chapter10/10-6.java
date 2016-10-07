import com.sleepycat.dbxml.*;
import com.sleepycat.db.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        // Create an XmlManager
	XmlManager myManager = new XmlManager();
        myManager.renameContainer("test.dbxml", "newtest.dbxml");
        myManager.removeContainer("newtest.dbxml");
        myManager.delete();
    }
}

