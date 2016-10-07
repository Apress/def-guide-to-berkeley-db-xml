import com.sleepycat.dbxml.XmlContainer;
import com.sleepycat.dbxml.XmlManager;
import com.sleepycat.dbxml.XmlManagerConfig;
import com.sleepycat.db.Environment;
import com.sleepycat.db.EnvironmentConfig;
import java.io.File;

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
        myManager.delete();
    }
}

