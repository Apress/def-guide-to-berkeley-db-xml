import com.sleepycat.dbxml.XmlContainer;
import com.sleepycat.dbxml.XmlException;
import com.sleepycat.dbxml.XmlManager;

class myDbXml {
public static void main(String args[]) throws Throwable
{
    // Create an XmlManager
    XmlManager myManager = null;
    try {
        // Open a container
        XmlContainer myContainer = 
            myManager.openContainer("container.dbxml");
    } catch (XmlException e) {
        System.out.print(e.what());
        // Error handling goes here
    } catch (Exception e) {
        // Error handling goes here
    }
}

}

