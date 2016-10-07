use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
my $ucontext = $mgr->createUpdateContext();

my $modify = $mgr->createModify();
my $queryexp = $mgr->prepare("/person/name", $qcontext);

$modify->addAppendStep($queryexp, XmlModify::Attribute, "type", "given");

my $results = $mgr->query("collection('test.dbxml')/person[name='Bill']", $qcontext);
$modify->execute($results, $qcontext, $ucontext);

