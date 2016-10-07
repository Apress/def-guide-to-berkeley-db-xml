use Sleepycat::DbXml 'simple'; 
use strict; 

my $mgr = new XmlManager(); 
my $container = $mgr->openContainer("test.dbxml"); 
my $ucontext = $mgr->createUpdateContext(); 
my $uri = "http://brians.org/metadata/"; 
my $metaname = "createdOn"; 
my $metavalue = new XmlValue(XmlValue::DATE_TIME, "2006-02-05T05:23:14");
my $document = $container->getDocument("file14.xml"); 
$document->setMetaData($uri, $metaname, $metavalue); 
$container->updateDocument($document, $ucontext); 

