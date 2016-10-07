use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();
my $xmlinput = $mgr->createLocalFileInputStream("file14.xml");
$container->putDocument("file14", $xmlinput, $ucontext);

