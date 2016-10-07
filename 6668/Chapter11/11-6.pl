use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $query = "collection()/person[name='Bob']";

my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
$qcontext->setDefaultCollection("test.dbxml");

my $query_exp = $mgr->prepare($query, $qcontext);
my $results = $query_exp->execute($qcontext);

