use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();

my $newcontent = "<person><name>Bob</name></person>";

my $document = $container->getDocument("file14");
$document->setContent("<person><name>Bob2</name></person>");
$container->updateDocument($document, $ucontext);

