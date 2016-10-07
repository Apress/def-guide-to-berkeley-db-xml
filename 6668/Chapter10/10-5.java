import com.sleepycat.dbxml.*;
import com.sleepycat.db.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        // Create an XmlManager
        XmlManagerConfig myManagerConf = new XmlManagerConfig();
	XmlManager myManager = new XmlManager(myManagerConf);
        
        XmlContainerConfig myContainerConf = new XmlContainerConfig();
        myContainerConf.setAllowValidation(true);
        myContainerConf.setNodeContainer(true);

        XmlContainer myContainer = myManager.createContainer( "myContainer.bdbxml", myContainerConf );

        myContainer.delete();
        myManager.delete();
    }
}

