use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
my $ucontext = $mgr->createUpdateContext();

my $modify = $mgr->createModify();
my $queryexp = $mgr->prepare("/person/name", $qcontext);

$modify->addAppendStep($queryexp, XmlModify::Attribute, "type", "given");

my $document = $container->getDocument("file14");
my $doc_value = new XmlValue($document);

$modify->execute($doc_value, $qcontext, $ucontext);

