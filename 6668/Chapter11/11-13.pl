use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $ucontext = $mgr->createUpdateContext();
my $qcontext = $mgr->createQueryContext();

my $content = "<person><name>Bob</name></person>";
$container->putDocument("", $content, $ucontext, DbXml::DBXML_GEN_NAME);

my $results = $mgr->query("collection('test.dbxml')/person[name='Bob']", $qcontext);
my $value = new XmlValue();
my $phonevalue = new XmlValue();
while ($results->next($value)) {
    my $document = $value->asDocument();
    print "Deleting document: " . $document->getName() . "\n";
    $container->deleteDocument($document, $ucontext);
}

