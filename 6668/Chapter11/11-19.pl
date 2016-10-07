use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();

my $uri = "http://brians.org/metadata/";
my $metaname = "createdOn";
my $metavalue = new XmlValue();

my $document = $container->getDocument("file14");
$document->getMetaData($uri, $metaname, $metavalue);
print "file14, created on " . $metavalue->asString() . "\n";


