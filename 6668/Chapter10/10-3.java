import com.sleepycat.dbxml.*;
import com.sleepycat.db.*;
import java.io.*;

class myDbXml {
    public static void main(String args[]) throws Throwable
    {
        File myDir = new File("myEnv/");

        // Open environment
        EnvironmentConfig myEnvConf = new EnvironmentConfig();
        myEnvConf.setErrorStream(System.err);
        Environment myEnv = new Environment(myDir, myEnvConf);

        // Create an XmlManager
        XmlManagerConfig myManagerConf = new XmlManagerConfig();
	XmlManager myManager = new XmlManager(myEnv, myManagerConf);
        myManager.setLogLevel(XmlManager.LEVEL_ALL, true);
        myManager.setLogCategory(XmlManager.CATEGORY_ALL, true);
    }
}

